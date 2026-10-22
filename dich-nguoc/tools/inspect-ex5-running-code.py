"""Read executable private pages only from this task's isolated MT5 tester."""

import argparse
import ctypes as ct
from ctypes import wintypes as wt
import hashlib
import json
from pathlib import Path
import time
import sys
sys.path.insert(0, str(Path(__file__).resolve().parent))
from project_paths import EVIDENCE, TERMINAL


ROOT = EVIDENCE
EXPECTED = TERMINAL / "metatester64.exe"


class MemoryInfo(ct.Structure):
    _fields_ = [
        ("BaseAddress", ct.c_void_p),
        ("AllocationBase", ct.c_void_p),
        ("AllocationProtect", wt.DWORD),
        ("PartitionId", wt.WORD),
        ("RegionSize", ct.c_size_t),
        ("State", wt.DWORD),
        ("Protect", wt.DWORD),
        ("Type", wt.DWORD),
    ]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--pid", type=int, required=True)
    parser.add_argument("--out", type=Path, required=True)
    parser.add_argument("--min-code-bytes", type=int, default=0)
    parser.add_argument("--wait-seconds", type=float, default=0)
    parser.add_argument("--include-readonly", action="store_true")
    parser.add_argument("--include-program-data", action="store_true")
    parser.add_argument("--ready-byte-rva", type=lambda text: int(text, 0))
    parser.add_argument("--verify-input-strings", type=Path)
    args = parser.parse_args()
    if not 0 <= args.wait_seconds <= 30 or not 0 <= args.min_code_bytes <= 64 * 1024 * 1024:
        raise ValueError("INVALID_CAPTURE_LIMIT")
    if args.ready_byte_rva is not None and (not args.include_program_data or args.ready_byte_rva < 0):
        raise ValueError("READY_BYTE_REQUIRES_PROGRAM_DATA_AND_NONNEGATIVE_RVA")
    output = args.out.resolve()
    if not output.is_relative_to(ROOT.resolve() / "captures") or output.exists():
        raise ValueError("OUTPUT_MUST_BE_NEW_DIRECTORY_UNDER_OWNED_CAPTURES")
    string_checks = []
    if args.verify_input_strings:
        check_path = args.verify_input_strings.resolve()
        if not check_path.is_relative_to(ROOT.resolve()):
            raise ValueError("STRING_CHECKS_OUTSIDE_RESEARCH_ROOT")
        string_checks = json.loads(check_path.read_text(encoding="utf-8-sig"))
        if not args.include_program_data:
            raise ValueError("STRING_CHECKS_REQUIRE_PROGRAM_DATA")

    kernel = ct.WinDLL("kernel32", use_last_error=True)
    kernel.OpenProcess.argtypes = [wt.DWORD, wt.BOOL, wt.DWORD]
    kernel.OpenProcess.restype = wt.HANDLE
    kernel.CloseHandle.argtypes = [wt.HANDLE]
    kernel.QueryFullProcessImageNameW.argtypes = [wt.HANDLE, wt.DWORD, wt.LPWSTR, ct.POINTER(wt.DWORD)]
    kernel.VirtualQueryEx.argtypes = [wt.HANDLE, ct.c_void_p, ct.POINTER(MemoryInfo), ct.c_size_t]
    kernel.VirtualQueryEx.restype = ct.c_size_t
    kernel.ReadProcessMemory.argtypes = [wt.HANDLE, ct.c_void_p, ct.c_void_p, ct.c_size_t, ct.POINTER(ct.c_size_t)]
    handle = kernel.OpenProcess(0x0400 | 0x0010, False, args.pid)
    if not handle:
        raise ct.WinError(ct.get_last_error())
    try:
        name = ct.create_unicode_buffer(32768)
        length = wt.DWORD(len(name))
        if not kernel.QueryFullProcessImageNameW(handle, 0, name, ct.byref(length)):
            raise ct.WinError(ct.get_last_error())
        if Path(name.value).resolve() != EXPECTED.resolve():
            raise ValueError("PROCESS_IS_NOT_THIS_TASKS_ISOLATED_TESTER")
        deadline = time.monotonic() + args.wait_seconds
        while args.min_code_bytes:
            address, largest = 0, 0
            while address < 0x7FFFFFFFFFFF:
                info = MemoryInfo()
                if not kernel.VirtualQueryEx(handle, address, ct.byref(info), ct.sizeof(info)):
                    break
                following = (info.BaseAddress or 0) + info.RegionSize
                if following <= address:
                    raise ValueError("INVALID_MEMORY_REGION")
                address = following
                if info.State == 0x1000 and info.Type == 0x20000 and info.Protect == 0x20:
                    largest = max(largest, info.RegionSize)
            if largest >= args.min_code_bytes:
                break
            if time.monotonic() >= deadline:
                raise TimeoutError("NO_EXECUTABLE_PRIVATE_REGION_REACHED_REQUIRED_SIZE")
            time.sleep(0.05)
        output.mkdir(parents=True)
        result = {"pid": args.pid, "process": name.value, "regions": [], "errors": [], "bytes": 0}
        memory_layout = []
        address = 0
        while address < 0x7FFFFFFFFFFF:
            info = MemoryInfo()
            if not kernel.VirtualQueryEx(handle, address, ct.byref(info), ct.sizeof(info)):
                result["query_end"] = {"address": address, "windows_error": ct.get_last_error()}
                break
            base, size = info.BaseAddress or 0, info.RegionSize
            if size == 0 or base + size <= address:
                raise ValueError("INVALID_MEMORY_REGION")
            address = base + size
            if info.State != 0x1000 or info.Type != 0x20000:
                continue
            memory_layout.append({
                "base": base, "allocation_base": info.AllocationBase,
                "bytes": size, "protect": info.Protect,
            })
            if info.Protect & 0x100 or (info.Protect & 0xFF) not in (0x10, 0x20, 0x40, 0x80):
                continue
            if size > 64 * 1024 * 1024 or result["bytes"] + size > 256 * 1024 * 1024:
                result["errors"].append({"event": "size_limit", "address": base, "bytes": size})
                continue
            buffer = ct.create_string_buffer(size)
            received = ct.c_size_t()
            if not kernel.ReadProcessMemory(handle, base, buffer, size, ct.byref(received)):
                result["errors"].append({"event": "read_failed", "address": base, "windows_error": ct.get_last_error()})
                continue
            if received.value != size:
                result["errors"].append({"event": "short_read", "address": base, "expected": size, "received": received.value})
                continue
            data = buffer.raw
            filename = f"{base:016x}.bin"
            (output / filename).write_bytes(data)
            result["regions"].append({
                "base": base, "allocation_base": info.AllocationBase, "bytes": size,
                "protect": info.Protect, "file": filename, "kind": "executable",
                "sha256": hashlib.sha256(data).hexdigest(),
            })
            result["bytes"] += size
        code_allocations = {region["allocation_base"] for region in result["regions"]}
        result["allocation_layout"] = [region for region in memory_layout if region["allocation_base"] in code_allocations]
        if args.include_readonly:
            for region in result["allocation_layout"]:
                if region["protect"] != 0x02:
                    continue
                base, size = region["base"], region["bytes"]
                if size > 64 * 1024 * 1024 or result["bytes"] + size > 256 * 1024 * 1024:
                    result["errors"].append({"event": "readonly_size_limit", "address": base, "bytes": size})
                    continue
                buffer = ct.create_string_buffer(size)
                received = ct.c_size_t()
                if not kernel.ReadProcessMemory(handle, base, buffer, size, ct.byref(received)) or received.value != size:
                    result["errors"].append({"event": "readonly_read_failed", "address": base, "windows_error": ct.get_last_error()})
                    continue
                data = buffer.raw
                filename = f"{base:016x}-readonly.bin"
                (output / filename).write_bytes(data)
                result["regions"].append(dict(region, kind="readonly_data", file=filename, sha256=hashlib.sha256(data).hexdigest()))
                result["bytes"] += size
        if args.include_program_data:
            program_code = [r for r in result["regions"] if r["kind"] == "executable" and r["protect"] == 0x20 and r["bytes"] >= 8192]
            if len(program_code) != 1:
                raise ValueError("AMBIGUOUS_PROGRAM_ALLOCATION")
            allocation = program_code[0]["allocation_base"]
            if args.ready_byte_rva is not None:
                ready_address = program_code[0]["base"] + args.ready_byte_rva
                holder = next((r for r in result["allocation_layout"]
                    if r["allocation_base"] == allocation and r["protect"] == 0x04
                    and r["base"] <= ready_address < r["base"] + r["bytes"]), None)
                if holder is None:
                    raise ValueError("READY_BYTE_OUTSIDE_PROGRAM_DATA")
                ready_started = time.monotonic()
                while True:
                    buffer = ct.create_string_buffer(1)
                    received = ct.c_size_t()
                    if not kernel.ReadProcessMemory(handle, ready_address, buffer, 1, ct.byref(received)) or received.value != 1:
                        raise RuntimeError("READY_BYTE_READ_FAILED")
                    if buffer.raw == b"\x01":
                        break
                    if time.monotonic() - ready_started >= args.wait_seconds:
                        raise TimeoutError("PROGRAM_READY_BYTE_NOT_SET")
                    time.sleep(0.01)
                result["ready_byte"] = {
                    "rva": hex(args.ready_byte_rva), "value": 1,
                    "wait_seconds": round(time.monotonic() - ready_started, 3),
                }
            for region in result["allocation_layout"]:
                if region["allocation_base"] != allocation or region["protect"] != 0x04:
                    continue
                base, size = region["base"], region["bytes"]
                if size > 16 * 1024 * 1024:
                    result["errors"].append({"event": "program_data_size_limit", "address": base, "bytes": size})
                    continue
                buffer = ct.create_string_buffer(size)
                received = ct.c_size_t()
                if not kernel.ReadProcessMemory(handle, base, buffer, size, ct.byref(received)) or received.value != size:
                    result["errors"].append({"event": "program_data_read_failed", "address": base, "windows_error": ct.get_last_error()})
                    continue
                data = buffer.raw
                filename = f"{base:016x}-program-data.bin"
                (output / filename).write_bytes(data)
                result["regions"].append(dict(region, kind="mutable_program_data", file=filename, sha256=hashlib.sha256(data).hexdigest()))
                result["bytes"] += size
            if not any(r["kind"] == "mutable_program_data" for r in result["regions"]):
                result["errors"].append({"event": "program_data_not_captured"})
            result["input_string_checks"] = []
            for check in string_checks:
                address = program_code[0]["base"] + int(check["rva"], 0)
                holder = next((r for r in result["regions"] if r["kind"] == "mutable_program_data" and r["base"] <= address and address + 12 <= r["base"] + r["bytes"]), None)
                if holder is None:
                    raise ValueError("STRING_DESCRIPTOR_OUTSIDE_CAPTURED_PROGRAM_DATA")
                expected = check["expected"].encode("utf-16le")
                if len(expected) > 8192:
                    raise ValueError("EXPECTED_STRING_TOO_LONG")
                block = (output / holder["file"]).read_bytes()
                offset = address - holder["base"]
                pointer = int.from_bytes(block[offset + 4:offset + 12], "little")
                passed = not expected and pointer == 0
                error = 0
                if pointer >= 12:
                    buffer = ct.create_string_buffer(12 + len(expected) + 2)
                    received = ct.c_size_t()
                    ok = kernel.ReadProcessMemory(handle, pointer - 12, buffer, len(buffer), ct.byref(received))
                    error = ct.get_last_error() if not ok else 0
                    if ok and received.value == len(buffer):
                        units = int.from_bytes(buffer.raw[8:12], "little")
                        passed = units * 2 == len(expected) and buffer.raw[12:] == expected + b"\0\0"
                result["input_string_checks"].append({"name": check["name"], "rva": check["rva"], "matches_expected": passed, "windows_error": error})
                if not passed:
                    result["errors"].append({"event": "input_string_verification_failed", "name": check["name"], "windows_error": error})
        (output / "capture.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
        print(json.dumps({"pid": args.pid, "regions": len(result["regions"]), "bytes": result["bytes"], "errors": result["errors"], "out": str(output)}))
        if result["errors"] or max((r["bytes"] for r in result["regions"] if r["kind"] == "executable"), default=0) < args.min_code_bytes:
            raise SystemExit(2)
    finally:
        kernel.CloseHandle(handle)


if __name__ == "__main__":
    main()
