"""Compare recovered MQL5 settings with initialized original EX5 snapshots."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

ROOT = Path(__file__).resolve().parent
SOURCE = ROOT.parent / "mt5-btc-recovery/TwisterPro Scalper.ex5"
SOURCE_SHA = "c705e2bbbb66d18e31e2a375625dfdef69243cb73e684af3a846d6ab33fabe73"
FORMATS = {"bool": "?", "int": "i", "long": "q", "ulong": "Q", "double": "d"}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def prepare(run):
    directory = ROOT / "settings-check" / run
    directory.mkdir()
    if sha(SOURCE) != SOURCE_SHA:
        raise ValueError("ORIGINAL_EX5_CHANGED")
    inputs_source = ROOT / "reconstructed/TwisterInputs.mqh"
    settings_source = ROOT / "reconstructed/TwisterSettings.mqh"
    fields = re.findall(r"^\s+(bool|int|long|ulong|double) v_([0-9a-f]+);",
                        settings_source.read_text(), re.M)
    if len(fields) != 40:
        raise ValueError("UNEXPECTED_SETTINGS_FIELD_COUNT")
    receipt = {"source_sha256": SOURCE_SHA, "files": {}, "cases": [], "fields": fields}
    for path in (inputs_source, settings_source, ROOT / "settings-check/cases.json"):
        receipt["files"][str(path)] = sha(path)
    code = [
        '#property strict', '#include "TwisterSettings.mqh"',
        '// Settings verifier only. It contains no trading implementation.',
        'void Emit(const string label,const TwisterRecoveredSettings &s) {',
    ]
    for kind, rva in fields:
        fmt = "%.17g" if kind == "double" else ("%I64d" if kind == "long" else "%I64u" if kind == "ulong" else "%d")
        code.append(f'   PrintFormat("TWISTER_SETTINGS|%s|{rva}|{fmt}",label,s.v_{rva});')
    code += ['}', 'int OnInit() {',
             '   if(!MQLInfoInteger(MQL_TESTER)) return INIT_FAILED;',
             '   TwisterRecoveredInputs p; TwisterRecoveredSettings s;']
    for case in read_json(ROOT / "settings-check/cases.json"):
        label = case["name"]
        if not re.fullmatch(r"[a-z0-9_]+", label):
            raise ValueError("INVALID_CASE_NAME")
        capture_dir = ROOT / "captures" / case["capture"]
        record_path = ROOT / (case["capture"] + "-result.json")
        record = read_json(record_path)
        if record["source_sha256"].lower() != SOURCE_SHA or record["capture_exit"] != 0 or record["cleanup_errors"]:
            raise ValueError("UNSUCCESSFUL_ORIGINAL_CAPTURE:" + label)
        job_path = ROOT / (case["capture"] + "-job.json")
        if read_json(job_path)[0].get("inputs", {}) != case["inputs"]:
            raise ValueError("CAPTURE_INPUTS_DIFFER:" + label)
        metadata_path = capture_dir / "capture.json"
        metadata = read_json(metadata_path)
        if metadata["errors"] or metadata.get("ready_byte", {}).get("rva") != "0x22590":
            raise ValueError("ORIGINAL_NOT_READY:" + label)
        code_regions = [x for x in metadata["regions"] if x["kind"] == "executable" and x["bytes"] == 110592]
        if len(code_regions) != 1:
            raise ValueError("UNEXPECTED_ORIGINAL_CODE_LAYOUT")
        data = next(x for x in metadata["regions"] if x["kind"] == "mutable_program_data")
        code_base = code_regions[0]["base"]
        blob = (capture_dir / data["file"]).read_bytes()
        for region in (code_regions[0], data):
            path = capture_dir / region["file"]
            if sha(path) != region["sha256"]:
                raise ValueError("CAPTURE_HASH_MISMATCH")
            receipt["files"][str(path)] = sha(path)
        for path in (record_path, job_path, metadata_path):
            receipt["files"][str(path)] = sha(path)

        def value(rva, kind):
            return struct.unpack_from("<" + FORMATS[kind], blob, code_base + rva - data["base"])[0]

        if not value(0x22590, "bool"):
            raise ValueError("CAPTURED_READY_FLAG_FALSE")
        point = value(0x22570, "double")
        if point <= 0:
            raise ValueError("INVALID_ORIGINAL_POINT")
        expected = {rva: value(int(rva, 16), kind) for kind, rva in fields}
        receipt["cases"].append(dict(case, point=point, expected=expected))
        code.append("   TwisterRecoveredDefaults(p);")
        for name, setting in case["inputs"].items():
            if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name) or not isinstance(setting, (float, int)) and setting not in ("true", "false"):
                raise ValueError("UNSUPPORTED_TEST_INPUT")
            code.append(f"   p.{name}={setting};")
        code += ["   TwisterRecoverSettings(p,true,s);",
                 f"   TwisterRecoverPriceDistances({point!r},s);",
                 f'   Emit("{label}",s);']
    code += ['   Print("TWISTER_SETTINGS_DONE");', '   return INIT_SUCCEEDED;', '}', 'void OnTick() {}']
    test_source = directory / "TwisterSettingsCheck.mq5"
    test_source.write_text("\n".join(code) + "\n", encoding="utf-8")
    receipt["files"][str(test_source)] = sha(test_source)
    receipt["run"] = run
    (directory / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"cases": len(receipt["cases"]), "fields": len(fields), "source": str(test_source)}))


def compare(run):
    directory = ROOT / "settings-check" / run
    receipt = read_json(directory / "receipt.json")
    if sha(SOURCE) != receipt["source_sha256"]:
        raise ValueError("ORIGINAL_CHANGED_SINCE_PREPARE")
    for filename, digest in receipt["files"].items():
        if sha(Path(filename)) != digest:
            raise ValueError("EVIDENCE_CHANGED:" + filename)
    binary = ROOT / "terminal/MQL5/Experts/Market/TwisterSettingsCheck.ex5"
    build_path = binary.with_suffix(".build.json")
    build = read_json(build_path)
    if sha(binary) != build["binary_sha256"]:
        raise ValueError("CHECKER_BINARY_CHANGED")
    for filename, digest in build["compiled_inputs"].items():
        if sha(Path(filename)) != digest:
            raise ValueError("COMPILED_INPUT_CHANGED")
        source = ROOT / "reconstructed" / Path(filename).name
        if Path(filename).suffix == ".mq5":
            source = directory / Path(filename).name
        if Path(filename).read_text(encoding="utf-16") != source.read_text(encoding="utf-8"):
            raise ValueError("COMPILED_SOURCE_DIFFERS")
    log_path = ROOT / "market-logs" / (run + ".log")
    combined_log = log_path.read_text(encoding="utf-8")
    sections = re.split(r"(?m)^##### ", combined_log)
    agent_sections = [s for s in sections if re.match(r"[^\n]+ \(Agent-127\.0\.0\.1-[0-9]+\)", s)
                      and "TWISTER_SETTINGS_DONE" in s]
    if len(agent_sections) != 1:
        raise ValueError("EXPECTED_ONE_LOCAL_AGENT_LOG")
    log = agent_sections[0]
    if log.count("TWISTER_SETTINGS_DONE") != 1:
        raise ValueError("CHECKER_DID_NOT_COMPLETE_ONCE")
    rows = re.findall(r"TWISTER_SETTINGS\|([a-z0-9_]+)\|([0-9a-f]+)\|([^\r\n]+)", log)
    actual = {}
    for label, rva, text in rows:
        key = (label, rva)
        if key in actual:
            raise ValueError("DUPLICATE_RESULT")
        actual[key] = text
    expected_count = len(receipt["cases"]) * len(receipt["fields"])
    if len(actual) != expected_count:
        raise ValueError("MISSING_OR_EXTRA_RESULTS")
    failures = []
    for case in receipt["cases"]:
        for kind, rva in receipt["fields"]:
            expected = case["expected"][rva]
            text = actual[(case["name"], rva)]
            observed = float(text) if kind == "double" else int(text)
            if struct.pack("<" + FORMATS[kind], observed) != struct.pack("<" + FORMATS[kind], expected):
                failures.append({"case": case["name"], "rva": rva, "original": expected, "mql5": observed})
    result = {"cases": len(receipt["cases"]), "comparisons": expected_count,
              "matched": expected_count - len(failures), "failures": failures,
              "source_sha256": SOURCE_SHA, "binary_sha256": sha(binary),
              "log_sha256": sha(log_path), "build_receipt_sha256": sha(build_path),
              "log_section": log.splitlines()[0],
              "limit": "Only initialized settings; not complete EA behavior or original internal names."}
    output = directory / "comparison.json"
    with output.open("x", encoding="utf-8") as stream:
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
