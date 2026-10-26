"""Compare bot1 runtime profile loading with the captured native blocks.

prepare/original/mql5/compare RUN. The original mode invokes the existing
native-only profile probe; it does not use MQL5 output as an oracle.
"""
import argparse
import hashlib
import json
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

HOME = Path(__file__).resolve().parents[1]
ROOT = HOME.parent
MT = (ROOT.parent / ".local/mt5-bot1-thread-20261025").resolve()
SCRIPT = "Scripts/bot-cua-toi-1/Bot1RuntimeProfileCheck.mq5"
ANALYSIS = HOME / "phan-tich/chuong-trinh-chinh/profile-parameters-20261026-r1"
ANALYZER = ANALYSIS / "analyze-profile-parameters.py"
DATA = __import__("importlib.util").util.spec_from_file_location("b1_runtime_cases", HOME / "tests/runtime_profile_cases.py")
CASES = __import__("importlib.util").util.module_from_spec(DATA)
DATA.loader.exec_module(CASES)
MASK = (1 << 64) - 1
FIELDS = [
    ("reference", "d"),
    ("entry.confirmation_frame", "i"), ("entry.hour1_flag", "i"),
    ("entry.older_width", "i"), ("entry.recent_width", "i"),
    ("entry.last_shift", "i"), ("entry.gap_points", "d"),
    ("buy_offset", "d"), ("sell_offset", "d"), ("nearby_radius", "d"),
    ("expiration_hours", "i"), ("stop_distance", "d"),
    ("target_distance", "d"), ("trail_distance", "d"),
    ("trail_start", "d"), ("trail_limit", "d"), ("trail_step", "d"),
    ("aux_hour1", "i"), ("aux_scan50", "i"), ("aux_older", "i"),
    ("aux_recent", "i"), ("aux_offset", "d"),
]
NATIVE_PREFIX = "b1"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def require(ok, message):
    if not ok:
        raise ValueError(message)


def word(value, kind):
    if kind == "d":
        return struct.unpack("<Q", struct.pack("<d", value))[0]
    return int(value) & MASK


def native_for(row):
    name = f"{NATIVE_PREFIX}-native-profile-{row['id']:04d}"
    output = ANALYSIS / name
    require(not output.exists(), "NATIVE_RUN_EXISTS " + name)
    command = [
        sys.executable, "-I", "-B", "-X", "utf8", str(ANALYZER), name,
        "--amount=" + repr(row["randomization"]), "--seed", str(row["seed"]),
        "--hl", str(row["hl"]), "--adjustments",
        repr(row["price_delta"]), repr(row["stop_delta"]),
        repr(row["target_delta"]), repr(row["trail_delta"]),
    ]
    result = subprocess.run(command, cwd=ROOT.parent, capture_output=True, text=True)
    require(result.returncode == 0, "NATIVE_PROBE_FAILED " + name + " " + result.stderr[-500:])
    report = json.loads((output / "native-profiles.json").read_text(encoding="utf-8"))
    native = next(item for item in report["rows"] if item["index"] == row["index"])
    require(not native.get("unresolved_before_last_profile_write"), "NATIVE_UNRESOLVED_PROFILE " + str(native.get("unresolved_before_last_profile_write")))
    values = native["values"]
    raw_fields = native.get("raw_fields", {})
    words = [native["seed_after"]]
    for name, kind in FIELDS:
        require(name in values, "NATIVE_FIELD_MISSING " + name)
        if kind == "d" and name in raw_fields:
            words.append(int.from_bytes(bytes.fromhex(raw_fields[name]), "little"))
        else:
            words.append(word(values[name], kind))
    return CASES.RESULT.pack(row["id"], 0, 0, *words)


def identity():
    sources = [
        HOME / "source/MQL5" / SCRIPT,
        HOME / "source/MQL5/Include/bot-cua-toi-1/Bot1RuntimeProfile.mqh",
        HOME / "source/MQL5/Include/bot-cua-toi-1/Bot1BaseDistances.mqh",
        HOME / "source/MQL5/Include/bot-cua-toi-1/Bot1DistanceSettings.mqh",
        HOME / "source/MQL5/Include/bot-cua-toi-1/Bot1EntryProfiles.mqh",
    ]
    helpers = [Path(__file__), Path(CASES.__file__), ANALYZER]
    return {
        "analyzer_sha256": sha(ANALYZER),
        "sources_sha256": {str(path.relative_to(HOME / "source/MQL5")).replace("\\", "/"): sha(path) for path in sources},
        "helpers_sha256": {str(path.relative_to(ROOT)).replace("\\", "/"): sha(path) for path in helpers},
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode", choices=["prepare", "original", "mql5", "compare"])
    parser.add_argument("run")
    parser.add_argument("--build")
    args = parser.parse_args()
    require(re.fullmatch(r"[a-z0-9-]{1,50}", args.run), "BAD_RUN")
    folder = HOME / "bang-chung/kiem-quan-ly-vi-the" / args.run
    global NATIVE_PREFIX
    NATIVE_PREFIX = args.run
    rows = CASES.cases()
    current = identity()
    if args.mode == "prepare":
        folder.mkdir(parents=True, exist_ok=False)
        (folder / "cases.bin").write_bytes(CASES.encode(rows))
        (folder / "baseline.json").write_text(json.dumps(dict(**current, cases=len(rows)), indent=2), encoding="utf-8")
        print(json.dumps({"cases": len(rows)}))
        return
    baseline = json.loads((folder / "baseline.json").read_text(encoding="utf-8"))
    require(all(baseline[key] == value for key, value in current.items()), "IDENTITY_CHANGED")
    require((folder / "cases.bin").read_bytes() == CASES.encode(rows), "INPUTS_CHANGED")
    if args.mode == "original":
        result = bytearray(CASES.HEADER.pack(CASES.MAGIC, CASES.VERSION, len(rows)))
        for row in rows:
            result.extend(native_for(row))
        (folder / "original-results.bin").write_bytes(result)
        (folder / "original-run.json").write_text(json.dumps(dict(**current, cases=len(rows), result_sha256=sha(folder / "original-results.bin")), indent=2), encoding="utf-8")
        print(json.dumps({"cases": len(rows)}))
        return
    if args.mode == "mql5":
        require(args.build, "BUILD_REQUIRED")
        receipt = HOME / "bang-chung/bien-dich" / args.build / "bien-nhan.json"
        build = json.loads(receipt.read_text(encoding="utf-8-sig"))
        require(build["target"] == SCRIPT and build["errors"] == build["warnings"] == 0, "BUILD_NOT_CLEAN")
        files = MT / "MQL5/Files/bot1-runtime-profile" / args.run
        files.mkdir(parents=True, exist_ok=False)
        shutil.copyfile(folder / "cases.bin", files / "cases.bin")
        preset = MT / "MQL5/Presets" / ("b1-runtime-" + args.run + ".set")
        ini = MT / ("b1-runtime-" + args.run + ".ini")
        preset.write_text("CheckRun=" + args.run + "\n", encoding="utf-16")
        ini.write_text("[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1RuntimeProfileCheck\nScriptParameters=" + preset.name + "\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n", encoding="utf-16")
        proc = subprocess.Popen(f'"{MT / "terminal64.exe"}" /portable /config:"{ini}"', cwd=MT, creationflags=subprocess.CREATE_NO_WINDOW)
        code = proc.wait(timeout=120)
        require(code == 0 and (files / "script-status.bin").read_bytes() == struct.pack("<2i", 0, len(rows)), "MT5_FAILED")
        for name in ("mql5-results.bin", "script-status.bin"):
            shutil.copyfile(files / name, folder / name)
        (folder / "mql5-run.json").write_text(json.dumps(dict(**current, cases=len(rows), result_sha256=sha(folder / "mql5-results.bin"), build=args.build), indent=2), encoding="utf-8")
        print(json.dumps({"cases": len(rows), "exit_code": code}))
        return
    native = (folder / "original-results.bin").read_bytes()
    actual = (folder / "mql5-results.bin").read_bytes()
    require(native == actual, "RESULTS_DIFFER")
    report = {"cases": len(rows), "matched": len(rows), "failed": 0, "result_sha256": {"original": sha(folder / "original-results.bin"), "mql5": sha(folder / "mql5-results.bin")}, "whole_bot_complete": False, "whole_manager_complete": False, "full_ea": False, "native_scalar_profile_executed": True}
    (folder / "comparison.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report))


if __name__ == "__main__":
    main()
