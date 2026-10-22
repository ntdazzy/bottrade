#!/usr/bin/env python3
"""Create separately stored EX5 research copies; preserve author/copyright bytes."""
from pathlib import Path
import hashlib
import zipfile

ROOT = Path(__file__).resolve().parents[1]
TARGET = "http://localhost/demo"
URL_OFFSET = 0x1A8
SLOT_SIZE = 256
DEST_DIR = ROOT / "research-copies"
ZIP_FILE = ROOT / "dist" / "EX5-localhost-research.zip"

def slot_string(data):
    region = data[URL_OFFSET:URL_OFFSET + SLOT_SIZE]
    if len(region) != SLOT_SIZE:
        raise ValueError("EX5 header too short")
    chars = [int.from_bytes(region[i:i+2], "little") for i in range(0, SLOT_SIZE, 2)]
    if 0 not in chars:
        raise ValueError("unterminated URL slot")
    end = chars.index(0)
    if any(chars[end+1:]):
        raise ValueError("URL slot contains other data")
    return region[:2*end].decode("utf-16-le")

def patch(data):
    if data[:3] != b"EX5" or data[3] not in (2, 3):
        raise ValueError("unsupported EX5 header")
    old_url = slot_string(data)
    payload = TARGET.encode("utf-16-le") + bytes(2)
    new = bytearray(data)
    new[URL_OFFSET:URL_OFFSET+SLOT_SIZE] = payload.ljust(SLOT_SIZE, bytes(1))
    new = bytes(new)
    if (len(data) != len(new) or
        data[:URL_OFFSET] != new[:URL_OFFSET] or
        data[URL_OFFSET+SLOT_SIZE:] != new[URL_OFFSET+SLOT_SIZE:] or
        slot_string(new) != TARGET):
        raise ValueError("verification failed")
    return new, old_url

def main():
    paths = sorted(p for p in ROOT.rglob("*.ex5")
                   if ".git" not in p.parts
                   and "research-copies" not in p.parts
                   and "dist" not in p.parts)
    if len(paths) != 24:
        raise SystemExit(f"Expected 24 EX5 files, found {len(paths)}")
    prepared = []
    for path in paths:
        rel = path.relative_to(ROOT)
        src = path.read_bytes()
        try:
            changed, old = patch(src)
        except Exception as exc:
            raise SystemExit(f"ABORT (no files changed): {rel}: {exc}")
        if rel.name == "TwisterPro Scalper.ex5":
            output_rel = Path("twisterpro-scalper") / rel.name
        else:
            output_rel = rel
        prepared.append((output_rel, changed, src, old))
    for rel, changed, src, old in prepared:
        out = DEST_DIR / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(changed)
        if out.read_bytes() != changed:
            raise SystemExit(f"Write verification failed: {rel}")
        print(f"VERIFIED {rel} | bytes={len(src)} | old_url={old!r} | " +
              f"original_sha256={hashlib.sha256(src).hexdigest()} | " +
              f"copy_sha256={hashlib.sha256(changed).hexdigest()}")
    ZIP_FILE.parent.mkdir(exist_ok=True)
    with zipfile.ZipFile(ZIP_FILE, "w", compression=zipfile.ZIP_DEFLATED) as z:
        for rel, data, _, _ in prepared:
            z.writestr(str(rel).replace("\\", "/"), data)
    with zipfile.ZipFile(ZIP_FILE, "r") as z:
        assert len(z.namelist()) == len(prepared)
        assert z.testzip() is None
        for rel, data, _, _ in prepared:
            assert z.read(str(rel).replace("\\", "/")) == data
    print(f"SUCCESS: {len(prepared)} EX5 copies validated; ZIP={ZIP_FILE}")

if __name__ == "__main__":
    main()
