#!/usr/bin/env python3
"""EX5 research metadata patcher: only fixed UTF-16LE header slots are changed.

This changes presentation text, not licenses or runtime restrictions, and may
invalidate EX5 integrity checks. Originals remain on the repository main branch.
"""
from pathlib import Path
import hashlib
import json
import sys
import zipfile

ROOT = Path(__file__).resolve().parents[1]
AUTHOR_OFFSET, URL_OFFSET, SLOT_SIZE = 0xA8, 0x1A8, 256
RESEARCH_LABEL = "Local research copy - metadata redacted"
LOCAL_URL = "http://localhost/demo"
ARCHIVE = ROOT / "dist" / "EX5-research-localhost.zip"

def sha(b):
    return hashlib.sha256(b).hexdigest()

def read_slot(blob, offset):
    if len(blob) < offset + SLOT_SIZE:
        raise ValueError("header too small")
    chunk = blob[offset:offset + SLOT_SIZE]
    if not any(chunk):
        return ""
    vals = [int.from_bytes(chunk[i:i+2], "little") for i in range(0, SLOT_SIZE, 2)]
    if 0 not in vals:
        raise ValueError("unterminated header slot")
    end = vals.index(0)
    if any(vals[end+1:]):
        raise ValueError("nonempty data after UTF-16LE terminator")
    text = chunk[:end*2].decode("utf-16le")
    if any(ord(c) < 32 for c in text):
        raise ValueError("control chars in header slot")
    return text

def fill_slot(value):
    payload = value.encode("utf-16le") + b"\x00\x00"
    if len(payload) > SLOT_SIZE:
        raise ValueError("metadata too long")
    return payload.ljust(SLOT_SIZE, b"\x00")

def patch(data):
    if not data.startswith(b"EX5\x02"):
        raise ValueError("unexpected EX5 magic")
    before_author = read_slot(data, AUTHOR_OFFSET)
    before_url = read_slot(data, URL_OFFSET)
    author = RESEARCH_LABEL if before_author else ""
    url = LOCAL_URL if before_url else ""
    out = bytearray(data)
    out[AUTHOR_OFFSET:AUTHOR_OFFSET+SLOT_SIZE] = fill_slot(author)
    out[URL_OFFSET:URL_OFFSET+SLOT_SIZE] = fill_slot(url)
    result = bytes(out)
    if (len(data) != len(result)
        or result[:AUTHOR_OFFSET] != data[:AUTHOR_OFFSET]
        or result[AUTHOR_OFFSET+SLOT_SIZE:URL_OFFSET] != data[AUTHOR_OFFSET+SLOT_SIZE:URL_OFFSET]
        or result[URL_OFFSET+SLOT_SIZE:] != data[URL_OFFSET+SLOT_SIZE:]
        or read_slot(result, AUTHOR_OFFSET) != author
        or read_slot(result, URL_OFFSET) != url):
        raise ValueError("post-patch verification failed")
    return result, {"author_changed": before_author != author,
                    "url_changed": before_url != url,
                    "input_sha256": sha(data), "output_sha256": sha(result),
                    "bytes": len(data)}

def main():
    paths = sorted(p for p in ROOT.rglob("*.ex5")
                   if ".git" not in p.parts and "dist" not in p.parts)
    if len(paths) != 24:
        raise SystemExit(f"ABORT: Expected 24 EX5; found {len(paths)}")
    all_rows, errors = [], []
    for p in paths:
        rel = p.relative_to(ROOT).as_posix()
        try:
            altered, fields = patch(p.read_bytes())
            all_rows.append((p, rel, altered, fields))
        except (ValueError, UnicodeError) as e:
            errors.append({"path": rel, "error": str(e)})
    if errors:
        print(json.dumps({"status": "ABORTED", "errors": errors}, indent=2))
        raise SystemExit("ABORT: No files have been modified")
    for p, rel, data, fields in all_rows:
        p.write_bytes(data)
    ARCHIVE.parent.mkdir(exist_ok=True)
    with zipfile.ZipFile(ARCHIVE, "w", compression=zipfile.ZIP_DEFLATED) as z:
        for _, rel, data, _ in all_rows:
            z.writestr(rel, data)
    with zipfile.ZipFile(ARCHIVE) as z:
        assert z.testzip() is None
        for _, rel, data, _ in all_rows:
            assert z.read(rel) == data
    print("ARCHIVE", ARCHIVE)
    print(json.dumps({"status": "validated", "total": len(all_rows),
        "modified": sum(r["input_sha256"] != r["output_sha256"] for *_, r in all_rows),
        "author_fields_changed": sum(r["author_changed"] for *_, r in all_rows),
        "url_fields_changed": sum(r["url_changed"] for *_, r in all_rows),
        "files": [{"path": rel, **r} for _, rel, _, r in all_rows]}, indent=2))
    return 0

if __name__ == "__main__":
    sys.exit(main())
