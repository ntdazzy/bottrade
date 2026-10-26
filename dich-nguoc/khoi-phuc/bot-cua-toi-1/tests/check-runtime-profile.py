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
NATIVE_REPORTS = {}
NATIVE_RECEIPTS = []
SCOPE = {"whole_bot_complete": False, "whole_manager_complete": False, "full_ea": False,
         "native_scalar_profile_executed": True, "original_ex5_changed": False}


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
    controls=[row[n] for n in ["randomization", "price_delta", "stop_delta", "target_delta", "trail_delta"]]
    key=(row["seed"],row["hl"],struct.pack("<5d",*controls))
    if key not in NATIVE_REPORTS:
        name=f"{NATIVE_PREFIX}-n{len(NATIVE_REPORTS):03d}"
        output=ANALYSIS/name
        require(not output.exists(), "NATIVE_RUN_EXISTS " + name)
        command=[sys.executable,"-I","-B","-X","utf8",str(ANALYZER),name,
                 "--amount="+repr(controls[0]),"--seed",str(row["seed"]),"--hl",str(row["hl"]),
                 "--adjustments",*[repr(v) for v in controls[1:]]]
        result=subprocess.run(command,cwd=ROOT.parent,capture_output=True,text=True)
        require(result.returncode==0,"NATIVE_PROBE_FAILED "+name+" "+result.stderr[-500:])
        report_path=output/"native-profiles.json"
        report=json.loads(report_path.read_text(encoding="utf-8"))
        require(report["installed_ex5_sha256"]=="a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922","ORIGINAL_EX5_DIFFERS")
        require(report["function_sha256"]=="f5edd0f5e9033ddddb289a3419406c06292ce22bff197bea6d10acea1756c721","ORIGINAL_FUNCTION_DIFFERS")
        require(report["tool_sha256"]==sha(ANALYZER),"NATIVE_PROBE_TOOL_CHANGED")
        NATIVE_REPORTS[key]=report
        NATIVE_RECEIPTS.append({"report":report_path.relative_to(ROOT).as_posix(),"sha256":sha(report_path)})
    report=NATIVE_REPORTS[key]
    native = next(item for item in report["rows"] if item["index"] == row["index"])
    require(native["required_field_count"]==22 and native["required_field_bytes_written"]==127,"PROFILE_WRITES_INCOMPLETE")
    require(native["stop_details"]["reason"]=="required_fields_complete" and not native["read_before_write_events"],"NATIVE_PROFILE_CONTEXT_UNPROVEN")
    require(not native.get("unresolved_before_last_profile_write"), "NATIVE_UNRESOLVED_PROFILE " + str(native.get("unresolved_before_last_profile_write")))
    values = native["values"]
    raw_fields = native["raw_fields"]
    words = [native["seed_after"]]
    for name, kind in FIELDS:
        require(name in values, "NATIVE_FIELD_MISSING " + name)
        if kind == "d":
            require(name in raw_fields,"NATIVE_BITS_MISSING "+name)
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
        HOME / "source/MQL5/Include/bot-cua-toi-1/Bot1Preparation.mqh",
    ]
    helpers = [Path(__file__), Path(CASES.__file__), ANALYZER,
               ROOT/'cong-cu/kiem-dieu-chinh-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',
               ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',
               ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py',
               HOME/'phan-tich/luot-20261023-data-v2/metadata/import.json',
               HOME/'phan-tich/luot-20261023-data-v2/kiem-tham-so-goc.json']
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
        require(not (folder/"original-results.bin").exists(),"RESULT_EXISTS")
        result = bytearray(CASES.HEADER.pack(CASES.MAGIC, CASES.VERSION, len(rows)))
        for row in rows:
            result.extend(native_for(row))
        (folder / "original-results.bin").write_bytes(result)
        (folder / "original-run.json").write_text(json.dumps(dict(**current, cases=len(rows), result_sha256=sha(folder / "original-results.bin"), native_reports=NATIVE_RECEIPTS, **SCOPE), indent=2), encoding="utf-8")
        print(json.dumps({"cases": len(rows)}))
        return
    if args.mode == "mql5":
        require(args.build, "BUILD_REQUIRED")
        receipt = HOME / "bang-chung/bien-dich" / args.build / "bien-nhan.json"
        build = json.loads(receipt.read_text(encoding="utf-8-sig"))
        require(build["target"] == SCRIPT and build["errors"] == build["warnings"] == 0, "BUILD_NOT_CLEAN")
        for name,digest in current['sources_sha256'].items():
            require(sha(MT/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_DIFFERS '+name)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5')
        require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files = MT / "MQL5/Files/bot1-runtime-profile" / args.run
        files.mkdir(parents=True, exist_ok=False)
        shutil.copyfile(folder / "cases.bin", files / "cases.bin")
        preset = MT / "MQL5/Presets" / ("b1-runtime-" + args.run + ".set")
        ini = MT / ("b1-runtime-" + args.run + ".ini")
        preset.write_text("CheckRun=" + args.run + "\n", encoding="utf-16")
        ini.write_text("[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1RuntimeProfileCheck\nScriptParameters=" + preset.name + "\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n", encoding="utf-16")
        proc = subprocess.Popen(f'"{MT / "terminal64.exe"}" /portable /config:"{ini}"', cwd=MT, creationflags=subprocess.CREATE_NO_WINDOW)
        try:code = proc.wait(timeout=120)
        except subprocess.TimeoutExpired:
            proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code == 0 and (files / "script-status.bin").read_bytes() == struct.pack("<2i", 0, len(rows)), "MT5_FAILED")
        for name in ("mql5-results.bin", "script-status.bin"):
            shutil.copyfile(files / name, folder / name)
        (folder / "mql5-run.json").write_text(json.dumps(dict(**current, cases=len(rows), result_sha256=sha(folder / "mql5-results.bin"), build=args.build, build_receipt_sha256=sha(receipt), **SCOPE), indent=2), encoding="utf-8")
        print(json.dumps({"cases": len(rows), "exit_code": code}))
        return
    native = (folder / "original-results.bin").read_bytes()
    actual = (folder / "mql5-results.bin").read_bytes()
    for name in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/name).read_text())
        require(all(record[k]==v for k,v in current.items()),'RUN_IDENTITY_DIFFERS')
        require(record['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RESULT_FILE_CHANGED')
    for item in json.loads((folder/'original-run.json').read_text())['native_reports']:
        require(sha(ROOT/item['report'])==item['sha256'],'NATIVE_REPORT_CHANGED')
    header=CASES.HEADER.pack(CASES.MAGIC,CASES.VERSION,len(rows))
    require(native[:12]==actual[:12]==header and len(native)==len(actual)==12+len(rows)*CASES.RESULT.size,'RESULT_SIZE_OR_HEADER_DIFFERS')
    require(native == actual, "RESULTS_DIFFER")
    report = {"cases": len(rows), "matched": len(rows), "failed": 0, "result_sha256": {"original": sha(folder / "original-results.bin"), "mql5": sha(folder / "mql5-results.bin")}, "whole_bot_complete": False, "whole_manager_complete": False, "full_ea": False, "native_scalar_profile_executed": True}
    (folder / "comparison.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report))


if __name__ == "__main__":
    main()
