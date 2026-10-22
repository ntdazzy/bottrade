#!/usr/bin/env python3
"""Prepare EX5 study copies with neutral *display* metadata; preserve provenance.

This does not transfer authorship, copyright or license, and does not unlock
demo features. It may invalidate EX5 checksums or runtime compatibility.
The original EX5 files outside research-copies are never modified.
"""
from pathlib import Path
import hashlib
import json
import zipfile

ROOT = Path(__file__).resolve().parents[1]
COPIES = ROOT / "research-copies"
ARCHIVE = ROOT / "dist" / "EX5-localhost-research-metadata.zip"
AUTHOR_LABEL = "Research Copy - See PROVENANCE.json"
URL_LABEL = "http://localhost/demo"
AUTHOR_OFFSET, URL_OFFSET, FIELD_SIZE = 0xA8, 0x1A8, 256

def sha(data):
    return hashlib.sha256(data).hexdigest()

def get_field(data, offset):
    raw = data[offset:offset+FIELD_SIZE]
    if len(raw) != FIELD_SIZE:
        raise ValueError("short metadata slot")
    codes = [int.from_bytes(raw[j:j+2], "little") for j in range(0, FIELD_SIZE, 2)]
    if 0 not in codes:
        raise ValueError("unterminated metadata slot")
    end = codes.index(0)
    if any(codes[end+1:]):
        raise ValueError("metadata slot has non-zero trailing data")
    return raw[:2*end].decode("utf-16-le")

def put_field(data, offset, value):
    encoded = value.encode("utf-16-le") + b"\x00\x00"
    if len(encoded) > FIELD_SIZE:
        raise ValueError("replacement longer than metadata slot")
    data[offset:offset+FIELD_SIZE] = encoded.ljust(FIELD_SIZE, b"\x00")

def transform(original):
    if original[:3] != b"EX5" or original[3] not in (2,3):
        raise ValueError("unexpected EX5 signature")
    orig_author = get_field(original, AUTHOR_OFFSET)
    orig_url = get_field(original, URL_OFFSET)
    patched = bytearray(original)
    put_field(patched, AUTHOR_OFFSET, AUTHOR_LABEL)
    put_field(patched, URL_OFFSET, URL_LABEL)
    out = bytes(patched)
    if (len(original) != len(out)
        or original[:AUTHOR_OFFSET] != out[:AUTHOR_OFFSET]
        or original[AUTHOR_OFFSET+FIELD_SIZE:URL_OFFSET] != out[AUTHOR_OFFSET+FIELD_SIZE:URL_OFFSET]
        or original[URL_OFFSET+FIELD_SIZE:] != out[URL_OFFSET+FIELD_SIZE:]
        or get_field(out, AUTHOR_OFFSET) != AUTHOR_LABEL
        or get_field(out, URL_OFFSET) != URL_LABEL):
        raise ValueError("unexpected binary differences")
    changed = sum(x!=y for x,y in zip(original, out))
    return out, orig_author, orig_url, changed

def main():
    originals = sorted(p for p in ROOT.rglob("*.ex5")
                       if ".git" not in p.parts
                       and "research-copies" not in p.parts
                       and "dist" not in p.parts)
    if len(originals) != 24:
        raise SystemExit(f"ABORT: expected 24 source EX5, found {len(originals)}")
    prepared = []
    audit = []
    for p in originals:
        relative = p.relative_to(ROOT)
        output_rel = (Path("twisterpro-scalper") / p.name
                      if p.name == "TwisterPro Scalper.ex5" else relative)
        original = p.read_bytes()
        try:
            output, old_author, old_url, changed_count = transform(original)
        except (ValueError, UnicodeError) as exc:
            raise SystemExit(f"ABORT before any changes: {relative}: {exc}")
        prepared.append((output_rel, output))
        audit.append({
            "original_path": relative.as_posix(),
            "research_copy": output_rel.as_posix(),
            "original_author_or_copyright": old_author,
            "original_url": old_url,
            "original_sha256": sha(original),
            "research_copy_sha256": sha(output),
            "size": len(output),
            "changed_bytes": changed_count
        })
    if len(set(p.as_posix() for p,_ in prepared)) != 24:
        raise SystemExit("ABORT: duplicate destination")
    provenance = {
        "purpose": "Research copies; neutral display metadata only.",
        "note": "Original authorship, copyright and licensing remain with their respective holders. No ownership, free-use rights, license bypass, behavioral equivalence or MT5 compatibility is claimed.",
        "replacement_author_field": AUTHOR_LABEL,
        "replacement_url_field": URL_LABEL,
        "files": audit
    }
    manifest = (json.dumps(provenance, ensure_ascii=False, indent=2)+"\n").encode("utf-8")
    for rel, blob in prepared:
        target = COPIES / rel
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(blob)
        if target.read_bytes() != blob:
            raise SystemExit(f"Verification failed after write: {rel}")
    (COPIES/"PROVENANCE.json").write_bytes(manifest)
    ARCHIVE.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(ARCHIVE, "w", compression=zipfile.ZIP_DEFLATED) as archive:
        for rel,blob in prepared:
            archive.writestr(rel.as_posix(),blob)
        archive.writestr("PROVENANCE.json",manifest)
    with zipfile.ZipFile(ARCHIVE, "r") as archive:
        if archive.testzip() is not None or len(archive.namelist()) != 25:
            raise SystemExit("ZIP CRC/count verification failed")
        for rel,blob in prepared:
            if archive.read(rel.as_posix()) != blob:
                raise SystemExit("ZIP contents mismatch")
        if archive.read("PROVENANCE.json") != manifest:
            raise SystemExit("ZIP manifest mismatch")
    for entry in audit:
        print(f"VERIFIED {entry['research_copy']} | size={entry['size']} | changed_bytes={entry['changed_bytes']} | original_sha256={entry['original_sha256']} | copy_sha256={entry['research_copy_sha256']}")
    print(f"SUCCESS: {len(prepared)} EX5 copies, 25 ZIP entries; archive={ARCHIVE}")

if __name__ == "__main__":
    main()
