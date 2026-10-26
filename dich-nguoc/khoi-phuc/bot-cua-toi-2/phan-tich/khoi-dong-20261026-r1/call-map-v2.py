"""Read-only v2 call/field inventory; never overwrites output files."""
from pathlib import Path
import argparse
import hashlib
import json
import re

BASE = 0x24FC8630000
C_PATH = Path(__file__).parents[1] / "ban-ex5-06" / "ma-trung-gian.c"
ADDR_PATH = Path(__file__).parents[1] / "ban-ex5-06" / "diem-bat-dau-ham.txt"

def norm(value):
    return value.replace("\r\n", "\n").replace("\r", "\n")

def build():
    raw = C_PATH.read_text(encoding="utf-8")
    normalized = norm(raw)
    lines = normalized.splitlines(True)
    addresses = [int(x, 16) for x in re.findall(r"24fc[0-9a-f]+", ADDR_PATH.read_text())]
    prefixes = ("void ", "ulonglong ", "longlong ", "uint ", "int ", "bool ", "undefined", "double ", "char ", "short ", "float ")
    starts = []
    for address in addresses:
        name = "FUN_" + format(address, "x")
        line_no = next((i + 1 for i, line in enumerate(lines) if name in line and (line.lstrip().startswith(prefixes) or line.lstrip().startswith(name))), None)
        if line_no is None:
            raise ValueError("DECLARATION_NOT_FOUND " + name)
        starts.append((address, line_no, name))
    starts.sort()
    functions = []
    for index, (address, line_no, name) in enumerate(starts):
        end_line = starts[index + 1][1] - 1 if index + 1 < len(starts) else len(lines)
        body = "".join(lines[line_no - 1:end_line])
        declaration = body.split("{", 1)[0].strip().replace("\n", " ")
        internal = sorted(set(re.findall(r"\b(FUN_[0-9a-f]+)\s*\(", body)) - {name})
        indirect = sorted(set(re.findall(r"\(code \*\)(0x[0-9a-f]+)", body)))
        globals_ = sorted(set(re.findall(r"(?:_DAT|DAT|uRam|iRam)_[0-9A-Fa-f]+", body)))
        global_map = [{"name": g, "absolute": hex(int(g.split("_")[-1], 16)), "rva": hex(int(g.split("_")[-1], 16) - BASE)} for g in globals_]
        assignments = sorted(set(g for g in globals_ if re.search(re.escape(g) + r"\s*(?:=|\+=|-=|\+\+|--)", body)))
        named_sdk = sorted(set(re.findall(r"\bMT5_[A-Za-z0-9_]+", body)))
        functions.append({"index":index+1,"absolute":hex(address),"rva":hex(address-BASE),"declaration_line":line_no,"declaration":declaration,"body_sha256_lf":hashlib.sha256(body.encode()).hexdigest(),"direct_internal_calls":internal,"indirect_call_targets_raw":indirect,"global_mentions":global_map,"direct_assignment_candidates":assignments,"named_mt5_calls":named_sdk,"sdk_binding_status":"named MT5 call present" if named_sdk else "not named in C; raw target only"})
    if len(functions) != 83 or any(int(f["absolute"],16)-BASE != int(f["rva"],16) for f in functions):
        raise ValueError("FUNCTION_OR_RVA_CHECK_FAILED")
    return {"bot":2,"build":"installed_market_build","base":hex(BASE),"c_source":C_PATH.as_posix(),"c_sha256_raw":hashlib.sha256(raw.encode()).hexdigest(),"c_sha256_normalized_lf":hashlib.sha256(normalized.encode()).hexdigest(),"function_count":len(functions),"scope":"83 captured starts; not an EX5 completeness claim","functions":functions}

def main():
    ap=argparse.ArgumentParser(); ap.add_argument("--json",required=True); ap.add_argument("--md",required=True); args=ap.parse_args(); data=build()
    if Path(args.json).resolve()==Path(args.md).resolve(): raise ValueError("OUTPUT_PATHS_MUST_DIFFER")
    for target in (Path(args.json),Path(args.md)):
        if target.exists(): raise FileExistsError("OUTPUT_EXISTS "+str(target))
    Path(args.json).write_text(json.dumps(data,ensure_ascii=False,indent=2)+"\n",encoding="utf-8",newline="\n")
    rows=["# Bản đồ gọi hàm bot2 v2 (bản đã cài)","",f"Nguồn C SHA-256 raw: `{data['c_sha256_raw']}`; chuẩn LF: `{data['c_sha256_normalized_lf']}`; base: `{data['base']}`; số hàm: **{data['function_count']}**.","","Lời gọi nội bộ chỉ nhận diện tên FUN theo sau dấu mở ngoặc. Biến toàn cục chỉ là mentions; phép gán chỉ là ứng viên. Địa chỉ gián tiếp chưa tự gắn tên SDK.","","| # | RVA | Dòng | Gọi nội bộ trực tiếp | Gọi gián tiếp thô | Biến được nhắc | Ứng viên phép gán | SDK tên rõ |","|---:|---:|---:|---|---|---|---|---|"]
    for f in data["functions"]:
        rows.append(f"| {f['index']} | `{f['rva']}` | {f['declaration_line']} | `{', '.join(f['direct_internal_calls']) or '—'}` | `{', '.join(f['indirect_call_targets_raw']) or '—'}` | `{', '.join(g['name'] for g in f['global_mentions']) or '—'}` | `{', '.join(f['direct_assignment_candidates']) or '—'}` | `{', '.join(f['named_mt5_calls']) or 'chưa gắn'}` |")
    rows += ["","## Giới hạn","","Bản đồ chỉ khoanh vùng từ C trung gian của 83 hàm đã chụp; không chứng minh toàn bộ EX5, không đặt tên thuật toán và không thay cho kiểm MT5."]
    Path(args.md).write_text("\n".join(rows)+"\n",encoding="utf-8",newline="\n")

if __name__ == "__main__": main()
