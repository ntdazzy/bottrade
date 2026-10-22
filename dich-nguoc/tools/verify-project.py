"""Verify the migration, preserved evidence, and original EA files without MT5."""
import hashlib
import argparse
import json
from pathlib import Path
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project_paths import PROJECT, WORK, EVIDENCE, evidence_path, read_manifest


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def check_file(relative, digest):
    path = (PROJECT / relative).resolve()
    if not path.is_relative_to(PROJECT) or not path.is_file():
        raise ValueError("MISSING_PROJECT_FILE: " + relative)
    if sha(path) != digest.lower():
        raise ValueError("FILE_DIFFERS_FROM_MIGRATION: " + relative)


def events(run):
    log_path = EVIDENCE / "market-logs" / (run + ".log")
    sections = re.split(r"(?m)^##### ", log_path.read_text(encoding="utf-8"))
    local = [s for s in sections if "(Agent-127.0.0.1-" in s.split("\n", 1)[0]]
    if len(local) != 1 or "thread finished" not in local[0]:
        raise ValueError("LOCAL_AGENT_RUN_NOT_COMPLETE: " + run)
    result = []
    for row in local[0].splitlines():
        cells = row.split("\t")
        if len(cells) >= 5 and re.match(r"2026\.\d\d\.\d\d ", cells[4]):
            result.append(cells[4])
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--evidence-only", action="store_true",
                        help="Check preserved evidence and originals; allow current source/tools/docs to evolve.")
    args = parser.parse_args()
    manifest = read_manifest()
    checked_migration_files = 0
    for item in manifest["files"]:
        if args.evidence_only and item["kind"] != "evidence":
            continue
        check_file(item["destination"], item.get("current_sha256", item["sha256"]))
        checked_migration_files += 1
    for item in manifest["destination_before"]:
        check_file(item["path"], item["sha256"])
    if not args.evidence_only:
        for item in manifest.get("generated_files", []):
            check_file(item["path"], item["sha256"])
    originals = json.loads((WORK / "catalog.json").read_text(encoding="utf-8"))
    for item in originals:
        check_file(item["source"], item["sha256"])
    build_count = 0
    for receipt in (EVIDENCE / "builds").glob("*/*.build.json"):
        data = json.loads(receipt.read_text(encoding="utf-8-sig"))
        binary = receipt.parent / (receipt.name.removesuffix(".build.json") + ".ex5")
        log = binary.with_suffix(".log")
        if sha(binary) != data["binary_sha256"] or sha(log) != data["log_sha256"]:
            raise ValueError("BUILD_ARTIFACT_CHANGED: " + receipt.name)
        for old_path, digest in data["compiled_inputs"].items():
            if sha(evidence_path(old_path)) != digest:
                raise ValueError("RECORDED_BUILD_INPUT_CHANGED: " + old_path)
        build_count += 1
    pairs = [("first_four_days", "tworig_m1_a", "twreco_m1_a_v1", 31)]
    for tag, count in (("ticks1", 533), ("ticks2", 169), ("delay", 183), ("broker1", 123)):
        pairs.append((tag, "tw_orig_" + tag + "_v2", "tw_reco_" + tag + "_v2", count))
    comparisons = []
    for label, original, recovered, count in pairs:
        original_events, recovered_events = events(original), events(recovered)
        if original_events != recovered_events or len(original_events) != count:
            raise ValueError("RECORDED_BEHAVIOR_DIFFERS: " + label)
        comparisons.append({"case": label, "matching_messages": count})
    print(json.dumps({"migration_files": len(manifest["files"]),
                      "checked_migration_files": checked_migration_files,
                      "scope": "preserved_evidence" if args.evidence_only else "migration_snapshot",
                      "existing_files_preserved": len(manifest["destination_before"]),
                      "original_ea_files": len(originals), "build_receipts": build_count,
                      "recorded_behavior": comparisons,
                      "status": "verified", "limit": "File preservation and recorded runs only; no fresh MT5 run or full EA equivalence claim."}, ensure_ascii=False))


if __name__ == "__main__":
    main()
