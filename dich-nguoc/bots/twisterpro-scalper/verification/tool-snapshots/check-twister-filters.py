"""Check recovered filters against original instructions in an offline CPU emulator."""
import argparse
import hashlib
import json
from pathlib import Path
import random
import re
import struct
import sys

ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / "analysis-libs"))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_RAX, UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8, UC_X86_REG_RIP, UC_X86_REG_RSP

BASE = 0x25a0b0c0000
HOST_BID = 0x7ff6537a2890
HOST_VOLUME = 0x7ff6537b21d0
HOST_FREE_ARRAY = 0x7ff653789d20
CAPTURE = ROOT / "captures/twisterdata1_09"
CODE = CAPTURE / "0000025a0b0c0000.bin"
DATA = CAPTURE / "0000025a0b0db000-program-data.bin"
MODULE = ROOT / "reconstructed/TwisterFilters.mqh"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


class OriginalInstructions:
    def __init__(self):
        metadata = read_json(CAPTURE / "capture.json")
        for path in (CODE, DATA):
            expected = next(x["sha256"] for x in metadata["regions"] if x["file"] == path.name)
            if sha(path) != expected:
                raise ValueError("ORIGINAL_CAPTURE_CHANGED")
        self.m = Uc(UC_ARCH_X86, UC_MODE_64)
        self.m.mem_map(BASE, 0x30000)
        self.m.mem_write(BASE, CODE.read_bytes())
        self.original_data = DATA.read_bytes()
        self.m.mem_map(0x100000, 0x10000)
        self.m.mem_map(0x200000, 0x1000)
        self.m.mem_map(0x400000, 0x1000)
        self.m.mem_map(HOST_BID & ~0xfff, 0x1000)
        self.m.mem_write(HOST_BID, b"\xc3")
        self.m.hook_add(UC_HOOK_CODE, self.provide_bid, begin=HOST_BID, end=HOST_BID)
        for address in (HOST_VOLUME, HOST_FREE_ARRAY):
            self.m.mem_map(address & ~0xfff, 0x1000)
            self.m.mem_write(address, b"\xc3")
            self.m.hook_add(UC_HOOK_CODE, self.provide_volume, begin=address, end=address)
        self.context = self.m.context_save()

    def provide_bid(self, machine, address, size, user_data):
        # Only this observed host operation is supplied; all other external calls fail.
        if machine.reg_read(UC_X86_REG_R8) != 1 or machine.reg_read(UC_X86_REG_RDX) != BASE + 0x1c150:
            raise ValueError("UNEXPECTED_SYMBOLINFO_CALL")
        self.write(0x24e48, "d", self.bid)
        self.calls += 1

    def provide_volume(self, machine, address, size, user_data):
        if address == HOST_FREE_ARRAY:
            self.volume_frees += 1
            return
        stack = machine.reg_read(UC_X86_REG_RSP)
        start = struct.unpack("<i", machine.mem_read(stack + 0x28, 4))[0]
        count = struct.unpack("<i", machine.mem_read(stack + 0x30, 4))[0]
        array = struct.unpack("<Q", machine.mem_read(stack + 0x38, 8))[0]
        if machine.reg_read(UC_X86_REG_RDX) != 6 or start != 1 or count != 3:
            raise ValueError("UNEXPECTED_COPYVOLUME_CALL")
        flags = struct.unpack("<I", machine.mem_read(array, 4))[0]
        if not flags & 0x100000:
            raise ValueError("VOLUME_ARRAY_NOT_SERIES")
        machine.mem_write(array + 8, struct.pack("<Q", max(0, self.volume_case["copied"])))
        machine.mem_write(array + 0x1c, struct.pack("<Q", 0x400000))
        machine.mem_write(0x400000, struct.pack("<qqq", 999, self.volume_case["previous"], self.volume_case["current"]))
        machine.reg_write(UC_X86_REG_RAX, self.volume_case["copied"] & 0xffffffffffffffff)
        self.volume_calls += 1

    def write(self, rva, fmt, value):
        self.m.mem_write(BASE + rva, struct.pack("<" + fmt, value))

    def reset(self):
        self.m.context_restore(self.context)
        self.m.mem_write(BASE + 0x1b000, self.original_data)
        self.m.mem_write(0x10fff8, struct.pack("<Q", 0x200000))
        self.m.reg_write(UC_X86_REG_RSP, 0x10fff8)
        self.calls = 0
        self.volume_calls = 0
        self.volume_frees = 0

    def run(self, rva):
        self.m.emu_start(BASE + rva, 0x200000, timeout=1000000, count=10000)
        if self.m.reg_read(UC_X86_REG_RIP) != 0x200000:
            raise ValueError("ORIGINAL_FUNCTION_DID_NOT_RETURN")
        return self.m.reg_read(UC_X86_REG_RAX)

    def trend(self, case):
        self.reset()
        self.bid = case["bid"]
        for rva, key in ((0x223b4, "enabled"), (0x223b5, "both"), (0x223b6, "slope")):
            self.write(rva, "?", case[key])
        for i, (rva, values) in enumerate(zip((0x22430, 0x22470, 0x224b0, 0x224f0), case["arrays"])):
            self.write(rva, "I", 0x100000 if case["series"] else 0)
            self.write(rva + 8, "Q", len(values))
            pointer = 0x400000 + i * 0x100
            self.write(rva + 0x1c, "Q", pointer)
            physical = list(reversed(values)) if case["series"] else values
            if physical:
                self.m.mem_write(pointer, struct.pack("<" + "d" * len(physical), *physical))
        result = struct.unpack("<i", struct.pack("<I", self.run(0xc080) & 0xffffffff))[0]
        expected_calls = int(case["enabled"] and all(len(a) >= n for a, n in zip(case["arrays"], (3, 3, 2, 2))))
        if self.calls != expected_calls or result not in (-1, 0, 1):
            raise ValueError("UNEXPECTED_ORIGINAL_TREND_RESULT")
        return result

    def candle(self, case):
        self.reset()
        values = dict(zip((0x225e8, 0x225f0, 0x225f8, 0x22600, 0x22570, 0x22388, 0x22380, 0x22390), case["values"]))
        values[0x22608] = case["values"][1] - case["values"][2]
        values[0x22610] = abs(case["values"][3] - case["values"][0])
        for rva, value in values.items():
            self.write(rva, "d", value)
        self.m.reg_write(UC_X86_REG_RCX, int(case["buy"]))
        result = self.run(0xc690) & 0xff
        if self.calls or result not in (0, 1):
            raise ValueError("UNEXPECTED_ORIGINAL_CANDLE_RESULT")
        return result

    def volume(self, case):
        self.reset()
        self.volume_case = case
        self.write(0x223b7, "?", case["enabled"])
        self.write(0x223c0, "B", 1)
        self.write(0x223b8, "d", case["ratio"])
        result = self.run(0xc880) & 0xff
        if self.calls or self.volume_calls != int(case["enabled"]) or self.volume_frees != int(case["enabled"]) or result not in (0, 1):
            raise ValueError("UNEXPECTED_ORIGINAL_VOLUME_RESULT")
        return result


def prepare(run):
    directory = ROOT / "filter-check" / run
    directory.mkdir(parents=True)
    original = OriginalInstructions()
    rng = random.Random(20261021)
    trends, candles, volumes = [], [], []
    for i in range(320):
        arrays = [[rng.choice([98., 99., 100., 101., 102.]) for _ in range(n)] for n in (3, 3, 2, 2)]
        if i < 32:
            arrays[i % 4] = arrays[i % 4][:i % 3]
        case = {"arrays": arrays, "bid": rng.choice([99., 100., 101.]),
                "enabled": i % 17 != 0, "both": bool(i & 1), "slope": bool(i & 2), "series": bool(i & 4)}
        case["expected"] = original.trend(case)
        trends.append(case)
    for i in range(320):
        low = rng.choice([0., 100., 2000.])
        width = rng.choice([0., 0.00001, 0.0001, 0.123, 1., 10.])
        high = low + width
        open_price = low + rng.choice([0., 0.2, 0.5, 0.8, 1.]) * width
        close = low + rng.choice([0., 0.2, 0.5, 0.8, 1.]) * width
        case = {"buy": bool(i & 1), "values": [open_price, high, low, close, rng.choice([0.001, 0.01, 1.]),
                rng.choice([0., 123., 1230.]), rng.choice([0., 0.6, 1.]), rng.choice([0., 0.25, 2.1])]}
        case["expected"] = original.candle(case)
        candles.append(case)
    for i in range(160):
        previous = rng.choice([0, 1, 2, 3, 10, 100, 101, 10000000])
        ratio = rng.choice([0.62, 0.5, 1.0])
        current = max(0, int(previous * ratio) + rng.choice([-1, 0, 1]))
        case = {"enabled": i % 11 != 0, "copied": rng.choice([-1, 0, 1, 2, 3, 3, 3]),
                "current": current, "previous": previous, "ratio": ratio}
        case["expected"] = original.volume(case)
        volumes.append(case)
    code = ['#property strict', '#include "TwisterFilters.mqh"',
            '// Offline function comparison only; no order functions.', 'int OnInit() {',
            '   if(!MQLInfoInteger(MQL_TESTER)) return INIT_FAILED;', '   double a[],b[],c[],d[];']
    for index, case in enumerate(trends):
        for name, values in zip("abcd", case["arrays"]):
            code.append(f"   ArrayResize({name},{len(values)});")
            for i, value in enumerate(values):
                code.append(f"   {name}[{i}]={value!r};")
        flags = ",".join(str(case[x]).lower() for x in ("enabled", "both", "slope"))
        code.append(f'   PrintFormat("TWISTER_FILTER|trend|{index}|%d",TwisterRecoveredTrend({case["bid"]!r},a,b,c,d,{flags}));')
    for index, case in enumerate(candles):
        args = ",".join([str(case["buy"]).lower()] + [repr(x) for x in case["values"]])
        code.append(f'   PrintFormat("TWISTER_FILTER|candle|{index}|%d",TwisterRecoveredCandle({args}));')
    for index, case in enumerate(volumes):
        args = ",".join([str(case["enabled"]).lower(), str(case["copied"]), str(case["current"]), str(case["previous"]), repr(case["ratio"])])
        code.append(f'   PrintFormat("TWISTER_FILTER|volume|{index}|%d",TwisterRecoveredVolume({args}));')
    code += ['   Print("TWISTER_FILTER_DONE");', '   return INIT_SUCCEEDED;', '}', 'void OnTick() {}']
    source = directory / "TwisterFiltersCheck.mq5"
    source.write_text("\n".join(code) + "\n", encoding="utf-8")
    receipt = {"trend": trends, "candle": candles, "volume": volumes, "files": {str(p): sha(p) for p in (CODE, DATA, MODULE, source, Path(__file__))},
               "source": "Original captured x86-64 instructions; synthetic arrays/OHLC; SymbolInfoDouble(BID) supplied by test."}
    (directory / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"trend_cases": len(trends), "candle_cases": len(candles), "volume_cases": len(volumes), "source": str(source)}))


def compare(run):
    directory = ROOT / "filter-check" / run
    receipt = read_json(directory / "receipt.json")
    for path, digest in receipt["files"].items():
        if sha(Path(path)) != digest:
            raise ValueError("EVIDENCE_CHANGED:" + path)
    binary = ROOT / "terminal/MQL5/Experts/Market/TwisterFiltersCheck.ex5"
    build = read_json(binary.with_suffix(".build.json"))
    if sha(binary) != build["binary_sha256"]:
        raise ValueError("CHECKER_BINARY_CHANGED")
    for filename, digest in build["compiled_inputs"].items():
        if sha(Path(filename)) != digest:
            raise ValueError("COMPILED_INPUT_CHANGED")
        source = directory / Path(filename).name if Path(filename).suffix == ".mq5" else MODULE
        if Path(filename).read_text(encoding="utf-16") != source.read_text(encoding="utf-8"):
            raise ValueError("COMPILED_SOURCE_DIFFERS")
    log_path = ROOT / "market-logs" / (run + ".log")
    sections = re.split(r"(?m)^##### ", log_path.read_text(encoding="utf-8"))
    selected = [s for s in sections if re.match(r"[^\n]+ \(Agent-127\.0\.0\.1-[0-9]+\)", s) and "TWISTER_FILTER_DONE" in s]
    if len(selected) != 1 or selected[0].count("TWISTER_FILTER_DONE") != 1:
        raise ValueError("EXPECTED_ONE_COMPLETE_LOCAL_AGENT_LOG")
    actual = {}
    for kind, index, value in re.findall(r"TWISTER_FILTER\|(trend|candle|volume)\|(\d+)\|(-?\d+)", selected[0]):
        key = (kind, int(index))
        if key in actual:
            raise ValueError("DUPLICATE_RESULT")
        actual[key] = int(value)
    expected_count = sum(len(receipt[k]) for k in ("trend", "candle", "volume"))
    if len(actual) != expected_count:
        raise ValueError("RESULT_COUNT_DIFFERS")
    failures = []
    for kind in ("trend", "candle", "volume"):
        for index, case in enumerate(receipt[kind]):
            if actual[(kind, index)] != case["expected"]:
                failures.append({"kind": kind, "index": index, "original_instructions": case["expected"], "mql5": actual[(kind, index)]})
    result = {"comparisons": expected_count, "matched": expected_count-len(failures), "failures": failures,
              "receipt_sha256": sha(directory / "receipt.json"), "binary_sha256": sha(binary), "log_sha256": sha(log_path),
              "limit": "Three function bodies with supplied finite test data; not an original full-EA MT5 trading comparison."}
    with (directory / "comparison.json").open("x", encoding="utf-8") as stream:
        json.dump(result, stream, indent=2)
        stream.write("\n")
    print(json.dumps(result))
    if failures:
        raise SystemExit(1)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("action", choices=["prepare", "compare"])
    parser.add_argument("run")
    args = parser.parse_args()
    if not re.fullmatch(r"[a-z][a-z0-9_]{0,23}", args.run):
        raise ValueError("INVALID_RUN")
    (prepare if args.action == "prepare" else compare)(args.run)
