#!/usr/bin/env python3
"""Read-only static audit of EX5 files: no bypass/decompilation or code edits."""
import collections
import hashlib
import json
import math
import re
import subprocess
import sys
from pathlib import Path

root=Path(sys.argv[1]).resolve()
project=Path(__file__).resolve().parents[1]
reference=json.loads((project/"research-copies/PROVENANCE.json").read_text())
originals={r["original_path"]:r for r in reference["files"]}
baseline="ca36ad58a1aec605e3fcb6e9d729380c5cbb9ad4"
header_spans=((0xa8,0x1a8),(0x1a8,0x2a8))
printable={
  "ascii":re.compile(rb"[\x20-\x7e]{6,}"),
  "utf16le":re.compile(rb"(?:[\x20-\x7e]\x00){5,}"),
  "utf16be":re.compile(rb"(?:\x00[\x20-\x7e]){5,}")
}
topics=re.compile(r"(?i)(copyright|author|mql5|metatrader|mqlblue|profalgo|twister|license|licence|trial|demo|market|activation|activate|expiry|expire|https?://|www\.|mailto:|telegram|localhost|quantumlab|nicedata|weredeu|wim schrynemakers|arnold bobrinskii|vitalii kosov|sathit sukhirun|forexeasolutions)")
def sha(data):
 return hashlib.sha256(data).hexdigest()
def entropy(data):
 if not data:return 0
 c=collections.Counter(data); n=len(data)
 return round(-sum((v/n)*math.log2(v/n) for v in c.values()),4)
def readslot(d,off):
 b=d[off:off+256]
 try:return b.decode("utf-16-le").split("\x00",1)[0]
 except Exception:return "INVALID"
def inside_header(off):
 return any(s<=off<e for s,e in header_spans)
def origbytes(path):
 p=subprocess.run(["git","show",f"{baseline}:{path}"],cwd=root,capture_output=True)
 if p.returncode:return None,p.stderr.decode(errors="replace")
 return p.stdout,None
records=[]
paths=sorted(root.rglob("*.ex5"))
for file in paths:
 path=file.relative_to(root).as_posix()
 data=file.read_bytes()
 original,problem=origbytes(path)
 diffs=[]; out_of_header=0
 if original is not None and len(original)==len(data):
  changed=[i for i,(a,b) in enumerate(zip(original,data)) if a!=b]
  out_of_header=sum(not inside_header(i) for i in changed)
 else:changed=[]
 strings=[]; count=collections.Counter()
 for encoding,regex in printable.items():
  for m in regex.finditer(data):
   count[encoding]+=1
   v=m.group()
   try:
    t=(v.decode("ascii") if encoding=="ascii" else v.decode("utf-16-le" if encoding=="utf16le" else "utf-16-be"))
   except UnicodeDecodeError:continue
   if topics.search(t):
    strings.append({"offset":m.start(),"hex_offset":hex(m.start()),"encoding":encoding,
                    "in_header":inside_header(m.start()),"text":t[:280]})
 exact=[]
 ref=originals.get(path,{})
 for field in ("original_author_or_copyright","original_url"):
  value=ref.get(field) or ""
  if not value:continue
  for enc in ("ascii","utf-16-le","utf-16-be"):
   try:needle=value.encode(enc)
   except UnicodeEncodeError:continue
   offset=0; found=[]
   while 1:
    idx=data.find(needle,offset)
    if idx==-1 or len(found)>=15:break
    found.append(idx);offset=idx+1
   if found:exact.append({"field":field,"encoding":enc,"offsets":found})
 markers={name:data.count(bytes.fromhex(sig)) for name,sig in
    {"zip_pk0304":"504b0304","gzip_1f8b":"1f8b","zlib_789c":"789c","zlib_78da":"78da","pe_mz":"4d5a"}.items()}
 slices=[entropy(data[i:i+65536]) for i in range(0,len(data),65536)]
 records.append({
  "path":path,"size":len(data),"sha256":sha(data),"header_magic":data[:4].hex(),
  "header_author":readslot(data,0xa8),"header_url":readslot(data,0x1a8),
  "original_available":original is not None,
  "original_sha256":sha(original) if original is not None else None,
  "original_size":len(original) if original is not None else None,
  "changed_bytes_from_original":len(changed),
  "changed_outside_two_header_spans":out_of_header if original is not None and len(original)==len(data) else None,
  "string_totals":dict(count),
  "notable_strings":strings[:400],
  "notable_total":len(strings),
  "notable_outside_header":sum(not s["in_header"] for s in strings),
  "original_provenance_exact_occurrences":exact,
  "high_entropy_blocks_over_7_5":sum(e>7.5 for e in slices),
  "blocks_64k":len(slices),
  "entropy_min":min(slices) if slices else 0,
  "entropy_max":max(slices) if slices else 0,
  "embedded_markers":markers
 })
 print(f"AUDIT {path} | size={len(data)} | changed_outside_header={out_of_header} | matches={len(strings)} | original_strings={len(exact)}")
summary={
 "scanned_files":len(records),
 "files_with_extra_author_urls":sum(bool(r["original_provenance_exact_occurrences"]) for r in records),
 "files_with_notable_strings_outside_header":sum(r["notable_outside_header"]>0 for r in records),
 "files_changed_outside_header":sum(r["changed_outside_two_header_spans"] not in (None,0) for r in records),
 "expected_count":17,
 "limitations":["Static raw-byte scan only","No runtime MT5 testing","No decrypting or guaranteed unpacking of protected EX5",
                "Keyword scan can yield false positives; nonliteral/obfuscated references are not detectable"]
}
dest=project/"dist"/"ex5-deep-audit"
dest.mkdir(parents=True,exist_ok=True)
(dest/"audit.json").write_text(json.dumps({"summary":summary,"files":records},indent=2,ensure_ascii=False))
with (dest/"audit.md").open("w") as o:
 o.write("# EX5 static binary audit\n\n"+json.dumps(summary,indent=2)+"\n\n")
 for r in records:
  o.write(f"## {r['path']}\n\nSHA-256: \`{r['sha256']}\` | size={r['size']} | changed_from_original={r['changed_bytes_from_original']} | outside_header={r['changed_outside_two_header_spans']}\n\n")
  o.write("### Notable strings outside header\n\n")
  for s in r["notable_strings"]:
   if not s["in_header"]:o.write(f"- offset {s['hex_offset']} [{s['encoding']}]: {s['text'][:180]}\n")
  o.write("\n### Remaining exact origin references\n\n"+json.dumps(r["original_provenance_exact_occurrences"],ensure_ascii=False)+"\n\n")
print("SUMMARY "+json.dumps(summary))
if len(records)!=17:raise SystemExit("Unexpected EX5 count")
if summary["files_changed_outside_header"]:raise SystemExit("Changes outside header discovered")
