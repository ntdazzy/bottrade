"""Paths for the standalone project and its immutable research receipts."""
import json
from pathlib import Path

WORK = Path(__file__).resolve().parents[1]
PROJECT = WORK.parent
BOT = WORK / "bots/twisterpro-scalper"
SOURCE_DIR = BOT / "source"
EVIDENCE = BOT / "verification"
ANALYSIS = BOT / "analysis"
TERMINAL = WORK / ".local/terminal"
LIBS = WORK / ".local/python"


def key(path):
    return str(path).replace("\\", "/").casefold()


def read_manifest():
    return json.loads((WORK / "docs/migration/manifest.json").read_text(encoding="utf-8"))


def recorded_path(path):
    """Keep new receipts portable; historical receipts remain byte-for-byte intact."""
    return Path(path).resolve().relative_to(PROJECT).as_posix()


def evidence_path(path):
    manifest = read_manifest()
    aliases = manifest["path_aliases"]
    destination = aliases.get(key(path))
    if destination:
        candidate = PROJECT / destination
    else:
        candidate = Path(path)
        if not candidate.is_absolute():
            candidate = PROJECT / candidate
    candidate = candidate.resolve()
    if not candidate.is_relative_to(PROJECT):
        raise ValueError("EVIDENCE_PATH_OUTSIDE_NEW_PROJECT: " + str(path))
    return candidate


def original_ex5(bot_id="twisterpro-scalper", index=None):
    catalog = json.loads((WORK / "catalog.json").read_text(encoding="utf-8"))
    entries = [x for x in catalog if x["bot_id"] == bot_id and (index is None or x["index"] == index)]
    if len(entries) != 1:
        raise ValueError("ORIGINAL_VARIANT_MUST_BE_EXPLICIT")
    return PROJECT / entries[0]["source"]


def check_binary(stem, run_directory):
    if (Path(run_directory) / "comparison.json").exists():
        return EVIDENCE / "builds" / stem / (stem + ".ex5")
    return TERMINAL / "MQL5/Experts/Market" / (stem + ".ex5")
