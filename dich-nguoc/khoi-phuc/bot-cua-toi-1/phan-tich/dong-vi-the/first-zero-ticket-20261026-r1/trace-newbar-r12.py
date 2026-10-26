"""Trace R12 definitions reaching the two new-bar parent calls in bot 1.

Read-only: this script only disassembles the captured original program bytes.
"""
import importlib.util
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
PRELUDE = ROOT / "bot-cua-toi-1" / "tests" / "check-management-prelude.py"
OUT = HERE / "newbar-r12-definitions.json"
BASE = 0x23E5AA10000
LO, HI = 0x18AA0, 0x1EF9C
TARGETS = {0x1A2CD: "buy", 0x1A2DB: "sell"}

# The repository's immutable local emulator bundle also supplies Capstone.
sys.path.insert(0, str(ROOT.parent / ".local" / "claude-recovery-20261023" / "python"))
import capstone


def load_prelude():
    spec = importlib.util.spec_from_file_location("first_zero_prelude", PRELUDE)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def canonical(md, register):
    name = md.reg_name(register)
    aliases = {"r12": "r12", "r12d": "r12", "r12w": "r12", "r12b": "r12"}
    return aliases.get(name, name)


def edges(instructions, index_by_address):
    out = {index: [] for index in range(len(instructions))}
    for index, ins in enumerate(instructions):
        destinations = []
        if ins.mnemonic.startswith("j"):
            if ins.operands and ins.operands[0].type == capstone.CS_OP_IMM:
                target = index_by_address.get(ins.operands[0].imm)
                if target is not None:
                    destinations.append(target)
            if ins.mnemonic != "jmp" and index + 1 < len(instructions):
                destinations.append(index + 1)
        elif not ins.mnemonic.startswith("ret") and index + 1 < len(instructions):
            destinations.append(index + 1)
        out[index] = destinations
    return out


def main():
    if OUT.exists():
        raise FileExistsError(OUT)
    prelude = load_prelude()
    original = prelude.Original()
    try:
        code = next(raw for region, raw in original.regions if region["base"] == BASE)
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
        md.detail = True
        ins = list(md.disasm(code[LO:HI], BASE + LO))
        index_by_address = {item.address: index for index, item in enumerate(ins)}
        forward = edges(ins, index_by_address)
        reverse = {index: [] for index in range(len(ins))}
        for source, destinations in forward.items():
            for destination in destinations:
                reverse[destination].append(source)
        rows = []
        for target, side in TARGETS.items():
            target_index = index_by_address[BASE + target]
            pending = list(reverse[target_index])
            visited = set()
            definitions = []
            entries = []
            while pending:
                index = pending.pop()
                if index in visited:
                    continue
                visited.add(index)
                item = ins[index]
                _, written = item.regs_access()
                if any(canonical(md, reg) == "r12" for reg in written):
                    definitions.append({"rva": hex(item.address - BASE), "mnemonic": item.mnemonic,
                                        "operands": item.op_str, "bytes": item.bytes.hex()})
                    continue
                if not reverse[index]:
                    entries.append(hex(item.address - BASE))
                    continue
                pending.extend(reverse[index])
            rows.append({"call_rva": hex(target), "side": side,
                         "definitions": sorted(definitions, key=lambda row: int(row["rva"], 16)),
                         "unresolved_function_entries": sorted(set(entries))})
        result = {"base": hex(BASE), "function": {"begin": hex(LO), "end": hex(HI)},
                  "targets": rows,
                  "nonvolatile_rule": "R12 is callee-saved across calls; calls do not define it in this trace.",
                  "original_bytes_modified": False}
        OUT.write_text(json.dumps(result, indent=2), encoding="utf-8")
        print(json.dumps(result, indent=2))
    finally:
        # The prelude oracle owns no close method; it only maps local emulator memory.
        pass


if __name__ == "__main__":
    main()
