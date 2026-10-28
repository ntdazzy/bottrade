"""Trích riêng dữ liệu điều kiện tài khoản Bot 1 từ EX5 và bản chụp đã kiểm.

Không in tên, số đăng nhập hay chuỗi riêng. Dữ liệu đó chỉ được ghi vào .local.
Lệnh: python trich-dieu-kien-tai-khoan-bot-1.py NEW_RUN
"""
import argparse
import hashlib
import importlib.util
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
LOCAL = ROOT.parent / ".local"
BASE = 0x23E5AA10000
FUNCTION = (0x3D6C0, 0x457CB)
EXPECTED = {
    "ex5": "a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922",
    "code": "e099f124084093c3fdc8651d5f5326709b165248982e5d4eb7394afcbb8177a4",
    "function": "7723b57d62ea7b205f2e8086679e8a7d23774416ca98c9369be426fde0365ea5",
}
EX5 = LOCAL / "claude-recovery-20261023/mt5/MQL5/Experts/Market/Gold Trade Pro MT5.ex5"
CAPTURE = ROOT / "bot-cua-toi-1/bang-chung/captures/luot-20261023-r1"
C_FILE = ROOT / "bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c"
PRICE_TOOL = ROOT / "cong-cu/kiem-muc-gia-bot-1-3.py"
OUTPUT = LOCAL / "bot1-auth-original-data-20261028-r1/data.private.json"


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def fail(code):
    raise RuntimeError(code)


def source_function():
    source = C_FILE.read_text(encoding="utf-8", errors="strict")
    start = source.index("ulonglong FUN_23e5aa4d6c0")
    end = source.index("/* Address: 23e5aa557d0 */", start)
    return source[start:end], source.count("\n", 0, start) + 1, source.count("\n", 0, end) + 1


def read_literal(machine, rva):
    length = int.from_bytes(bytes(machine.mem_read(BASE + rva - 4, 4)), "little")
    if not 0 < length < 400:
        fail("INVALID_LITERAL_LENGTH")
    return bytes(machine.mem_read(BASE + rva, length * 2)).decode("utf-16le", errors="strict")


def pair_rows(machine, text):
    # Bốn cặp trước và bốn cặp trong nhánh AccountInfoInteger(32), theo đúng thứ tự mã máy.
    fixed = [
        (0x57C6C, 0x57C8C), (0x57FAC, 0x57FCC), (0x57FEC, 0x5800C), (0x5802C, 0x5804C),
        (0x5806C, 0x5808C), (0x580AC, 0x580CC), (0x580EC, 0x5810C), (0x5812C, 0x5814C),
    ]
    section = text[text.index("LAB_23e5aa4dd55:"):text.index("if (param_1 <")]
    calls = re.findall(r"FUN_23e5aa103c0\(uStack_5c,(?:literal_|&DAT_)23e5aa([0-9a-f]+)\)", section)
    if len(calls) != 436:
        fail("DIRECT_STRING_CALL_COUNT_" + str(len(calls)))
    direct = list(zip(calls[::2], calls[1::2]))
    result = []
    for index, (left, right) in enumerate(fixed):
        group = "first_4" if index < 4 else "account_info_integer_32_4"
        result.append({"group": group, "order": index, "left": read_literal(machine, left),
                       "right": read_literal(machine, right), "literal_rvas": [hex(left), hex(right)]})
    for index, (left, right) in enumerate(direct):
        # Nhãn C dùng địa chỉ tuyệt đối; trừ đúng 0x10000 để ra RVA của base chụp.
        a, b = int(left, 16) - 0x10000, int(right, 16) - 0x10000
        result.append({"group": "direct_218", "order": index, "left": read_literal(machine, a),
                       "right": read_literal(machine, b), "literal_rvas": [hex(a), hex(b)]})
    return result


def candidate_logins(text):
    tree = text[text.index("if (param_1 <"):]
    values = {int(value, 16) for value in re.findall(r"param_1\s*==\s*0x([0-9a-f]+)", tree)}
    values |= {int(value, 16) for value in re.findall(r"lVar19\s*=\s*0x([0-9a-f]+)", tree)}
    ranges = []
    for base, size in re.findall(r"param_1\s*-\s*0x([0-9a-f]+)U?\s*<\s*(0x[0-9a-f]+|\d+)", tree):
        base, size = int(base, 16), int(size, 0)
        ranges.append({"begin": hex(base), "length": size})
        values.update(range(base, base + size))
    return values, ranges


def load_runner():
    spec = importlib.util.spec_from_file_location("auth_native", PRICE_TOOL)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    runner = module.Original(1)
    if runner.base != BASE:
        fail("CAPTURE_BASE_DIFFERS")
    return runner


def login_runner(runner):
    machine, registers = runner.m, runner.x
    hooks = {0x7FF6846B7410: 10, 0x7FF6846E0FD0: 11, 0x7FF6846B73C0: 12}
    for page in {address & ~0xFFF for address in hooks}:
        if not any(lo <= page <= hi for lo, hi, _ in machine.mem_regions()):
            machine.mem_map(page, 0x1000)
    for address, kind in hooks.items():
        machine.mem_write(address, b"\xc3")
        runner.apis[address] = kind

    def api_call(mem, address, _size, _user):
        if runner.apis[address] == 10:
            mem.mem_write(BASE + 0x6A43C, struct.pack("<IQ", 0, 0))
        mem.reg_write(registers.UC_X86_REG_RAX, 0)

    for address in hooks:
        machine.hook_add(runner.uc.UC_HOOK_CODE, api_call, begin=address, end=address)

    def accepts(login):
        for region, raw in runner.regions:
            if region.get("kind") == "mutable_program_data":
                machine.mem_write(region["base"], raw)
        for name in ("RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15"):
            machine.reg_write(getattr(registers, "UC_X86_REG_" + name), 0)
        stack = 0x50020000 - 0x108
        machine.mem_write(stack, struct.pack("<Q", 0x60000000))
        machine.reg_write(registers.UC_X86_REG_RSP, stack)
        machine.reg_write(registers.UC_X86_REG_RCX, login)
        machine.emu_start(BASE + FUNCTION[0], 0x60000000, count=5_000_000)
        if machine.reg_read(registers.UC_X86_REG_RIP) != 0x60000000:
            fail("NATIVE_FUNCTION_DID_NOT_RETURN")
        return bool(machine.reg_read(registers.UC_X86_REG_RAX) & 0xFF)

    return accepts


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("run")
    args = parser.parse_args()
    if not re.fullmatch(r"[a-z0-9-]{1,64}",args.run):
        fail("BAD_RUN")
    target=LOCAL/args.run/"data.private.json"
    if target.exists():
        fail("OUTPUT_EXISTS")
    for path in (EX5, C_FILE, PRICE_TOOL, CAPTURE / "capture.json"):
        if not path.is_file():
            fail("MISSING_" + path.name)
    if digest(EX5) != EXPECTED["ex5"]:
        fail("ORIGINAL_EX5_SHA256_DIFFERS")
    capture = json.loads((CAPTURE / "capture.json").read_text(encoding="utf-8"))
    code_row = next((row for row in capture["regions"] if row.get("kind") == "executable" and row["base"] == BASE), None)
    if not code_row or code_row["sha256"] != EXPECTED["code"]:
        fail("CAPTURE_CODE_SHA256_DIFFERS")
    code = CAPTURE / code_row["file"]
    if digest(code) != EXPECTED["code"]:
        fail("CAPTURE_CODE_FILE_SHA256_DIFFERS")
    raw = code.read_bytes()[FUNCTION[0]:FUNCTION[1]]
    if hashlib.sha256(raw).hexdigest() != EXPECTED["function"]:
        fail("FUNCTION_SNAPSHOT_SHA256_DIFFERS")
    text, c_first, c_last = source_function()
    runner = load_runner()
    pairs = pair_rows(runner.m, text)
    candidates, ranges = candidate_logins(text)
    accepts = login_runner(runner)
    logins = sorted(login for login in candidates if accepts(login))
    if len(pairs) != 226:
        fail("TOTAL_PAIR_COUNT_" + str(len(pairs)))
    packed_logins = b"".join(struct.pack("<Q", login) for login in logins)
    report = {
        "private": True,
        "verification": "unverified_complete_login_set",
        "reason": "Native code was run for every C-derived candidate, but this tool does not prove that C parsing found every possible candidate.",
        "source": {
            "original_ex5_sha256": digest(EX5), "snapshot_code_sha256": digest(code),
            "function_rva": [hex(FUNCTION[0]), hex(FUNCTION[1])], "function_snapshot_sha256": hashlib.sha256(raw).hexdigest(),
            "c_file_sha256": digest(C_FILE), "c_lines": [c_first, c_last],
            "raw_instruction_ranges": {"mql_info_6": ["0x3d915", "0x3d92c"], "pair_checks": ["0x3d958", "0x407d1"], "login_tree": ["0x407d2", "0x457c6"]},
        },
        "pairs": pairs,
        "pair_counts": {"first_4": 4, "account_info_integer_32_4": 4, "direct_218": 218, "total": 226},
        "login_candidates_from_c": len(candidates), "login_range_forms_from_c": ranges,
        "logins": logins, "login_count": len(logins), "login_uint64le_sha256": hashlib.sha256(packed_logins).hexdigest(),
    }
    target.parent.mkdir(parents=True, exist_ok=True)
    with target.open('x',encoding='utf-8') as stream:
        json.dump(report,stream,ensure_ascii=False,indent=2)
    print(json.dumps({"output": str(target), "pair_count": len(pairs), "login_count": len(logins),
                      "login_uint64le_sha256": report["login_uint64le_sha256"], "verification": report["verification"]}))


if __name__ == "__main__":
    try:
        main()
    except Exception as error:
        print(str(error), file=sys.stderr)
        raise SystemExit(1)
