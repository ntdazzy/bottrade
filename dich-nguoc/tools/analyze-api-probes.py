"""Identify calls in known-source probe functions; do not infer trading rules."""
from pathlib import Path
import json
import re
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project_paths import EVIDENCE, LIBS, read_manifest
ROOT = EVIDENCE
sys.path.insert(0, str(LIBS))
from capstone import Cs, CS_ARCH_X86, CS_MODE_64, CS_OP_IMM, CS_OP_REG


def canonical(name):
    aliases = {
        "eax": "rax", "ax": "rax", "al": "rax", "ah": "rax",
        "ebx": "rbx", "bx": "rbx", "bl": "rbx", "bh": "rbx",
        "ecx": "rcx", "cx": "rcx", "cl": "rcx", "ch": "rcx",
        "edx": "rdx", "dx": "rdx", "dl": "rdx", "dh": "rdx",
        "esi": "rsi", "si": "rsi", "sil": "rsi",
        "edi": "rdi", "di": "rdi", "dil": "rdi",
        "ebp": "rbp", "bp": "rbp", "bpl": "rbp",
        "esp": "rsp", "sp": "rsp", "spl": "rsp",
    }
    return aliases.get(name, re.sub(r"^(r(?:8|9|1[0-5]))[dwb]$", r"\1", name))


def trace_calls(engine, data, base, start, end, host_base, host_size):
    state, result, constants = {}, [], set()
    for ins in engine.disasm(data[start:end], base + start):
        constants.update(op.imm for op in ins.operands if op.type == CS_OP_IMM)
        if ins.mnemonic in ("call", "jmp") and ins.operands:
            op = ins.operands[0]
            target = op.imm if op.type == CS_OP_IMM else state.get(canonical(engine.reg_name(op.reg))) if op.type == CS_OP_REG else None
            if target and host_base <= target < host_base + host_size:
                result.append({
                    "site_rva": hex(ins.address - base), "target_rva": hex(target - host_base),
                    "rdx_constant": state.get("rdx"), "r8_constant": state.get("r8"),
                    "transfer": ins.mnemonic,
                })
        dest, rhs = None, None
        if ins.mnemonic in ("mov", "movabs") and len(ins.operands) == 2 and ins.operands[0].type == CS_OP_REG:
            dest = canonical(engine.reg_name(ins.operands[0].reg))
            source = ins.operands[1]
            rhs = source.imm if source.type == CS_OP_IMM else state.get(canonical(engine.reg_name(source.reg))) if source.type == CS_OP_REG else None
            if rhs is not None and ins.operands[0].size == 4:
                rhs &= 0xffffffff
        _, written = ins.regs_access()
        for register in written:
            state.pop(canonical(engine.reg_name(register)), None)
        if dest and rhs is not None:
            state[dest] = rhs
        if ins.mnemonic.startswith("j") or ins.mnemonic == "ret":
            state = {}
        elif ins.mnemonic == "call":
            state = {k: v for k, v in state.items() if k in ("rbx", "rbp", "rsi", "rdi", "r12", "r13", "r14", "r15")}
    return result, constants


def main():
    name = sys.argv[1]
    if not re.fullmatch(r"api_probe_v[0-9]+", name):
        raise ValueError("Expected a probe capture name")
    folder = ROOT / "captures" / name
    process = json.loads((ROOT / name.replace("_", "-") / "process.json").read_text(encoding="utf-8-sig"))
    capture = json.loads((folder / "capture.json").read_text())
    code = next(r for r in capture["regions"] if r["kind"] == "executable" and r["bytes"] >= 8192)
    region = next(r for r in capture["regions"] if r["kind"] == "mutable_program_data")
    blob, data = (folder / code["file"]).read_bytes(), (folder / region["file"]).read_bytes()
    data_rva = region["base"] - code["base"]
    runs = []
    for off in range(0, len(data) - 12, 4):
        begin, end, unwind = struct.unpack_from("<III", data, off)
        if not (0 <= begin < end <= code["bytes"] and data_rva <= unwind < data_rva + len(data) and data[unwind - data_rva] & 7 == 1):
            continue
        row = {"offset": off, "begin": begin, "end": end, "unwind": unwind}
        if runs and off == runs[-1][-1]["offset"] + 12 and begin >= runs[-1][-1]["end"]:
            runs[-1].append(row)
        else:
            runs.append([row])
    table = max(runs, key=len)
    references = {}
    for match in re.finditer(rb"(?:[\x20-\x7e]\x00){4,}", data):
        text = match.group().decode("utf-16le")
        if not text.startswith("EX5_API_PROBE:"):
            continue
        pointer, pos = struct.pack("<Q", region["base"] + match.start()), 0
        while (pos := data.find(pointer, pos)) >= 0:
            if pos >= 4 and struct.unpack_from("<I", data, pos - 4)[0] == 0:
                references[region["base"] + pos - 4] = text.split(":", 1)[1]
            pos += 1
    host_size = read_manifest()["engine_size"]
    host_base = int(process["EngineBase"], 16)
    engine = Cs(CS_ARCH_X86, CS_MODE_64)
    engine.detail = True
    functions, operations = [], {}
    for row in table:
        calls, constants = trace_calls(engine, blob, code["base"], row["begin"], row["end"], host_base, host_size)
        markers = sorted({references[c] for c in constants if c in references})
        functions.append({"rva": hex(row["begin"]), "end_rva": hex(row["end"]), "markers": markers, "calls": calls})
        if len(markers) == 1:
            for call in calls:
                if call["target_rva"] == "0x7b49f0" and call["rdx_constant"] is not None:
                    operation = call["rdx_constant"]
                    if operation != 2:
                        operations.setdefault(str(operation), []).append(markers[0])
    result = {
        "engine_sha256": process["EngineSHA256"], "engine_base": process["EngineBase"],
        "dispatcher_rva": "0x7b49f0", "print_marker_operation": 2,
        "observed_dispatch_operations": {key: sorted(set(value)) for key, value in operations.items()},
        "functions": functions, "runtime_function_table": table,
        "limit": "Call-site observations, not automatic proof that every helper is the named public API.",
    }
    output = folder / "probe-analysis.json"
    if output.exists():
        raise ValueError("Output already exists")
    output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "functions_with_one_marker": sum(len(f["markers"]) == 1 for f in functions),
        "dispatch_operations": result["observed_dispatch_operations"],
    }))


if __name__ == "__main__":
    main()
