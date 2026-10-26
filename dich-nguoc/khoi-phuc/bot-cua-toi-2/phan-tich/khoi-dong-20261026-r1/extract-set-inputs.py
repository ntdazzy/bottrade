"""Read five bot2 .set files; emit only base key=value inputs."""
from pathlib import Path
import argparse
import hashlib
import json

SET_DIR = Path(__file__).parents[5] / "1-dang-tin-nhat" / "bot-cua-toi-2" / "bo-cai-tac-gia"
FILES = sorted(SET_DIR.glob("*.set"))

def read(path):
    rows = {}
    for line in path.read_text(encoding="utf-8-sig").splitlines():
        if "=" not in line or line.startswith(";"):
            continue
        key, value = line.split("=", 1)
        if key.endswith((",F", ",1", ",2", ",3")) or set(value) == {"-"}:
            continue
        rows[key] = value
    return rows

def main():
    ap = argparse.ArgumentParser(); ap.add_argument("--out", required=True); args = ap.parse_args()
    if Path(args.out).exists(): raise FileExistsError("OUTPUT_EXISTS " + args.out)
    parsed = {p.name: read(p) for p in FILES}
    keys = sorted(set().union(*(d for d in parsed.values())))
    data = {"files": [{"name": p.name, "bytes": p.stat().st_size, "sha256": hashlib.sha256(p.read_bytes()).hexdigest()} for p in FILES], "note": "Chỉ lấy dòng key=value cơ sở; hậu tố ,F/,1/,2/,3/ được giữ riêng và không coi là input khác.", "inputs": {key: {name: parsed[name].get(key) for name in parsed} for key in keys}}
    Path(args.out).write_text(json.dumps(data, ensure_ascii=False, indent=2) + "\n", encoding="utf-8", newline="\n")

if __name__ == "__main__": main()
