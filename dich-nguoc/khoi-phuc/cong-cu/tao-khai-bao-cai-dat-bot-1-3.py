"""Generate verified MQL5 input declarations and value-recording scripts."""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MENU = ROOT / "menu-bot-1-3" / "luot-20261023-r1" / "verified-menu.json"

def fail(message: str) -> None:
    raise ValueError(message)

def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()

def mql_string(value: str) -> str:
    if not isinstance(value, str):
        fail("STRING_VALUE_REQUIRED")
    return '"' + value.replace("\\", "\\\\").replace('"', '\\"').replace("\r", "\\r").replace("\n", "\\n") + '"'

def parse_value(setting: dict) -> tuple[str, str]:
    representation = setting.get("representation")
    value = setting.get("default")
    if representation == "bool":
        if value not in ("true", "false"):
            fail(f"BAD_BOOL:{setting['name']}")
        return "bool", value
    if representation == "double":
        try:
            float(value)
        except (TypeError, ValueError):
            fail(f"BAD_DOUBLE:{setting['name']}")
        return "double", str(value)
    if representation == "integer_or_enum":
        if not re.fullmatch(r"-?\d+", str(value)):
            fail(f"BAD_INTEGER:{setting['name']}")
        return "int", str(value)
    if representation == "string":
        return "string", mql_string(value)
    fail(f"UNKNOWN_REPRESENTATION:{setting.get('name')}:{representation}")

def validate(bot: dict, set_path: Path) -> tuple[list[dict], dict[str, list[tuple[int, str]]]]:
    settings = bot.get("settings")
    if not isinstance(settings, list) or not settings:
        fail("SETTINGS_MISSING")
    if len(settings) != bot.get("default_count") or len(settings) != (72 if bot["bot"] == 1 else 80):
        fail("INPUT_COUNT_MISMATCH")
    expected = list(range(1, len(settings) + 1))
    actual = [row.get("order") for row in settings]
    if actual != expected:
        fail(f"ORDER_NOT_CONTIGUOUS:{actual}")
    names = [row.get("name") for row in settings]
    if any(not isinstance(name, str) or not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name) for name in names):
        fail("BAD_INPUT_NAME")
    if len(set(names)) != len(names):
        fail("DUPLICATE_INPUT_NAME")
    expected_sha = bot.get("defaults_set_sha256")
    if expected_sha and sha256(set_path) != expected_sha:
        fail(f"DEFAULTS_SHA256_MISMATCH:{set_path.name}")
    menus: dict[str, list[tuple[int, str]]] = {}
    for menu in bot.get("menus", []):
        name = menu.get("name")
        if name in menus or name not in names:
            fail(f"MENU_INPUT_MISSING_OR_DUPLICATE:{name}")
        choices = []
        seen: set[int] = set()
        for choice in menu.get("choices", []):
            value = choice.get("value")
            label = choice.get("label")
            if not isinstance(value, int) or value in seen or not isinstance(label, str):
                fail(f"BAD_MENU_CHOICE:{name}")
            seen.add(value)
            choices.append((value, label))
        if not choices:
            fail(f"EMPTY_MENU:{name}")
        menus[name] = choices
    for row in settings:
        parse_value(row)
    return settings, menus

def enum_name(bot: int, input_name: str) -> str:
    return f"Bot{bot}{input_name}Value"

def render_header(bot: int, settings: list[dict], menus: dict[str, list[tuple[int, str]]]) -> str:
    lines = [f"#ifndef BOT{bot}_INPUTS_MQH", f"#define BOT{bot}_INPUTS_MQH", "// Generated from the verified MT5 input snapshot; behavior is not inferred here."]
    for setting in settings:
        name = setting["name"]
        if name not in menus:
            continue
        typ = enum_name(bot, name)
        lines.append(f"enum {typ}")
        lines.append("{")
        choices = menus[name]
        for index, (value, label) in enumerate(choices):
            comma = "," if index < len(choices) - 1 else ""
            comment = label.replace("\r", " ").replace("\n", " ")
            lines.append(f"   {typ}_{index} = {value}{comma} // {comment}")
        lines.append("};")
    for setting in settings:
        name = setting["name"]
        typ, literal = parse_value(setting)
        if name in menus:
            choices = menus[name]
            default = str(setting["default"])
            index = next(i for i, (value, _) in enumerate(choices) if str(value) == default)
            literal = f"{enum_name(bot, name)}_{index}"
            typ = enum_name(bot, name)
        label = setting.get("visible_label")
        comment = "" if label is None else " // " + str(label).replace("\r", " ").replace("\n", " ")
        lines.append(f"input {typ} {name} = {literal};{comment}")
    lines.extend(["#endif", ""])
    return "\n".join(lines)

def render_script(bot: int, count: int, settings: list[dict], menus: dict[str, list[tuple[int, str]]]) -> str:
    lines = ["#property strict", 'input string CheckRun="";', f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}Inputs.mqh"', ""]
    lines += ["int WriteText(const int handle,const string value)", "{", "   if(value==NULL) { FileWriteInteger(handle,-1); return 0; }", "   int length=StringLen(value); FileWriteInteger(handle,length);", "   if(length>0) FileWriteString(handle,value,length);", "   return length;", "}", "", "bool ValidRun(const string value)", "{", "   int length=StringLen(value);", "   if(length<1 || length>48) return false;", "   for(int i=0;i<length;i++)", "   {", "      ushort c=StringGetCharacter(value,i);", "      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return false;", "   }", "   return true;", "}", "", "int OnStart()", "{", '   if(!ValidRun(CheckRun)) { Print("INVALID_CHECK_RUN:",CheckRun,":",StringLen(CheckRun));return 1; }', f'   string folder="bot{bot}-inputs\\\\"+CheckRun+"\\\\";', "   int file=FileOpen(folder+\"values.bin\",FILE_WRITE|FILE_BIN);", "   if(file==INVALID_HANDLE) return 2;", "   FileWriteInteger(file,0x494e5031); FileWriteInteger(file,1); FileWriteInteger(file," + str(count) + ");"]
    for index, setting in enumerate(settings):
        name = setting["name"]
        typ, _ = parse_value(setting)
        lines.append(f"   WriteText(file,\"{name}\");")
        kind = 2 if name in menus or typ == "int" else (1 if typ == "bool" else (3 if typ == "double" else 4))
        lines.append(f"   FileWriteInteger(file,{kind});")
        if name in menus:
            lines.append(f"   FileWriteInteger(file,(int){name});")
        elif typ == "bool":
            lines.append(f"   FileWriteInteger(file,{name} ? 1 : 0);")
        elif typ == "int":
            lines.append(f"   FileWriteInteger(file,{name});")
        elif typ == "double":
            lines.append(f"   FileWriteDouble(file,{name});")
        else:
            lines.append(f"   WriteText(file,{name});")
    lines.extend(["   FileClose(file);", "   return 0;", "}", ""])
    return "\n".join(lines)

def load() -> list[tuple[int, list[dict], dict[str, list[tuple[int, str]]]]]:
    data = json.loads(MENU.read_text(encoding="utf-8"))
    result = []
    for bot in data.get("bots", []):
        bot_id = bot.get("bot")
        if bot_id not in (1, 3):
            fail(f"UNEXPECTED_BOT:{bot_id}")
        set_path = MENU.parent / f"bot{bot_id}-defaults.set"
        settings, menus = validate(bot, set_path)
        result.append((bot_id, settings, menus))
    if sorted(bot for bot, _, _ in result) != [1, 3]:
        fail("BOTS_INCOMPLETE")
    return result

def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    for bot, settings, menus in load():
        root = ROOT / f"bot-cua-toi-{bot}"
        header = root / f"source/MQL5/Include/bot-cua-toi-{bot}/Bot{bot}Inputs.mqh"
        script = root / f"source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}InputsCheck.mq5"
        expected_header = render_header(bot, settings, menus)
        expected_script = render_script(bot, len(settings), settings, menus)
        if args.check:
            if not header.exists() or header.read_text(encoding="utf-8") != expected_header:
                fail(f"GENERATED_HEADER_DIFF:{header}")
            if not script.exists() or script.read_text(encoding="utf-8") != expected_script:
                fail(f"GENERATED_SCRIPT_DIFF:{script}")
        else:
            header.write_text(expected_header, encoding="utf-8", newline="\n")
            script.write_text(expected_script, encoding="utf-8", newline="\n")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
