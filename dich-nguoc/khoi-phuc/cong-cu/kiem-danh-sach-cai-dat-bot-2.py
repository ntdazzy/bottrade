#!/usr/bin/env python3
"""Extract the bot2 input list from the luot-20261026-r1 report."""

from __future__ import annotations

import hashlib
import html
import json
import re
from pathlib import Path


EXPECTED_EX5_SHA256 = "390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795"


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def read_json(path: Path) -> dict:
    with path.open(encoding="utf-8") as handle:
        return json.load(handle)


def main() -> None:
    repo = Path(__file__).resolve().parents[3]
    evidence_dir = repo / "dich-nguoc/khoi-phuc/bot-cua-toi-2/bang-chung/luot-20261026-r1"
    html_path = evidence_dir / "b2-luot-20261026-r1.htm"
    run_path = evidence_dir / "capture-run.json"
    finalization_path = evidence_dir / "capture-finalization.json"
    capture_path = repo / "dich-nguoc/khoi-phuc/bot-cua-toi-2/bang-chung/captures/luot-20261026-r1/capture.json"
    ex5_path = Path(
        r"C:/Users/NTD/Desktop/BotTradeEA/local/market-demos-20261020/"
        r"dich-nguoc-luot2/terminal/MQL5/Experts/Market/Goldbot One MT5.ex5"
    )
    inventory_path = (
        repo
        / "dich-nguoc/khoi-phuc/bot-cua-toi-2/phan-tich/luot-20261026-data-r2/"
        / "inventory-v3/inventory-v3.json"
    )
    output_dir = repo / "dich-nguoc/khoi-phuc/danh-gia-doc-lap/inputs-bot2-20261029-r1"
    output_path = output_dir / "inputs.json"

    run = read_json(run_path)
    finalization = read_json(finalization_path)
    capture = read_json(capture_path)
    inventory = read_json(inventory_path)
    actual_ex5_sha = sha256(ex5_path)
    if actual_ex5_sha != EXPECTED_EX5_SHA256:
        raise SystemExit(f"EX5 SHA mismatch: {actual_ex5_sha}")
    if run["source_sha256"].lower() != EXPECTED_EX5_SHA256:
        raise SystemExit("capture-run source SHA does not match the required EX5 SHA")
    if finalization["test"]["expert_sha256"].lower() != EXPECTED_EX5_SHA256:
        raise SystemExit("capture-finalization expert SHA does not match the required EX5 SHA")

    run_inputs = run["job"]["inputs"]
    final_inputs = finalization["test"]["job"]["inputs"]
    if run_inputs != final_inputs:
        raise SystemExit("capture-run and capture-finalization job inputs differ")
    if set(run_inputs) != {"AutoGMT", "Broker_GMT_OFFSET_Winter", "Broker_GMT_OFFSET_Summer"}:
        raise SystemExit(f"unexpected job input names: {sorted(run_inputs)}")
    overridden = dict(run_inputs)

    executable_regions = [region for region in capture["regions"] if region.get("kind") == "executable"]
    if not executable_regions:
        raise SystemExit("capture has no executable region")
    captured_base = hex(executable_regions[0]["base"])
    metadata_base = inventory.get("code_base")
    if metadata_base is None or captured_base.lower() != metadata_base.lower():
        raise SystemExit(f"capture/metadata base mismatch: {captured_base} != {metadata_base}")
    html_sha = sha256(html_path)
    report_sha = finalization["test"].get("report_sha256")
    if report_sha is None or html_sha.lower() != report_sha.lower():
        raise SystemExit(f"report SHA mismatch: {html_sha} != {report_sha}")

    html_bytes = html_path.read_bytes()
    html_encoding = "utf-16" if html_bytes.startswith((b"\xff\xfe", b"\xfe\xff")) else "utf-8"
    source = html_bytes.decode(html_encoding)
    input_section = source.split("Inputs:</td>", 1)[1].split("Company:</td>", 1)[0]
    values = [
        html.unescape(match.group(1))
        for match in re.finditer(r"<b>(.*?)</b>", input_section, re.S)
        if "=" in match.group(1)
    ]
    if len(values) != 70:
        raise SystemExit(f"expected 70 report rows, found {len(values)}")

    rows = []
    for order, raw in enumerate(values, 1):
        name, value = raw.split("=", 1)
        is_title = name in {
            "lijntje",
            "BacktestSpeed_string",
            "spreadfilter",
            "NFP_FILTER",
            "IR_FILTER",
            "CPI_FILTER",
            "propfirmsettings",
            "LotSizeSettings",
        }
        rows.append(
            {
                "order": order,
                "kind": "menu_title" if is_title else "input",
                "name": name,
                "observed_value": value,
                "overridden_in_capture": (not is_title and name in overridden),
                "type": None,
                "default": None,
                "rva": None,
            }
        )

    actual_inputs = [row for row in rows if row["kind"] == "input"]
    titles = [row for row in rows if row["kind"] == "menu_title"]
    if len(titles) != 8 or len(actual_inputs) != 62:
        raise SystemExit(f"unexpected counts: titles={len(titles)}, inputs={len(actual_inputs)}")
    observed_overrides = {
        row["name"]: row["observed_value"]
        for row in actual_inputs
        if row["overridden_in_capture"]
    }
    if observed_overrides != overridden:
        raise SystemExit(f"override mismatch: {observed_overrides}")

    output_dir.mkdir(parents=True, exist_ok=True)
    evidence = {
        str(path.relative_to(repo)): sha256(path)
        for path in (html_path, run_path, finalization_path, inventory_path)
    }
    result = {
        "bot": 2,
        "snapshot": "luot-20261026-r1",
        "source_ex5": str(ex5_path),
        "source_ex5_sha256": actual_ex5_sha,
        "code_base": metadata_base,
        "counts": {"report_rows": len(rows), "menu_titles": len(titles), "inputs": len(actual_inputs)},
        "overrides": overridden,
        "evidence_sha256": evidence,
        "inputs": rows,
        "limitations": [
            "Kiểu khai báo, giá trị mặc định và RVA đều chưa có bằng chứng trực tiếp; giữ null.",
            "59 mục không bị truyền trong lượt chạy không được gọi là mặc định chắc chắn.",
            "inventory-v3 là bảng 86 dải hàm, không phải bảng ánh xạ đầu vào.",
        ],
    }
    serialized = json.dumps(result, ensure_ascii=False, indent=2) + "\n"
    if output_path.exists():
        existing = json.loads(output_path.read_text(encoding="utf-8"))
        if existing != result:
            raise SystemExit(f"existing JSON differs; refusing to overwrite: {output_path}")
        status = "already_verified"
    else:
        output_path.write_text(serialized, encoding="utf-8")
        status = "written"
    print(json.dumps({"status": status, "output": str(output_path), "report_rows": len(rows), "menu_titles": len(titles), "inputs": len(actual_inputs)}, ensure_ascii=False))


if __name__ == "__main__":
    main()
