"""Compare new bot2 metadata function RVAs with the preserved 83-function map."""
from pathlib import Path
import argparse
import hashlib
import json

ROOT = Path(__file__).parent
NEW = ROOT.parent / "luot-20261026-data" / "metadata"
OLD = ROOT / "functions-83.json"

def main():
    ap=argparse.ArgumentParser(); ap.add_argument("--out",required=True); a=ap.parse_args()
    if Path(a.out).exists(): raise FileExistsError("OUTPUT_EXISTS "+a.out)
    imp=json.loads((NEW/"import.json").read_text(encoding="utf-8"))
    rows=[line.split("\t") for line in (NEW/"functions.tsv").read_text().splitlines() if line.strip()]
    old=json.loads(OLD.read_text(encoding="utf-8"))
    old_rvas={x["r"] for x in old["functions"]}
    new_rvas={hex(int(x[0],16)-int(imp["code_base"],16)) for x in rows}
    data={"bot":2,"capture":imp["capture"],"source_sha256":imp["engine"]["source_sha256"],"tester_sha256":imp["engine"]["tester_sha256"],"tester_pid":imp["engine"]["tester_pid"],"engine_base":imp["engine"]["engine_base"],"code_base":imp["code_base"],"code_sha256":imp["code_sha256"],"data_sha256":imp["data_sha256"],"function_count":len(rows),"native_labels":imp["native_labels"],"native_signatures":imp["native_signatures"],"strings":imp["strings"],"string_refs":imp["string_refs"],"old_function_count":len(old["functions"]),"rvas_added":sorted(new_rvas-old_rvas,key=lambda x:int(x,16)),"rvas_removed":sorted(old_rvas-new_rvas,key=lambda x:int(x,16)),"new_functions":[{"begin_rva":x[0],"end_rva":x[1]} for x in rows],"scope":"86 function-table ranges from the new capture; not a whole-EA completeness claim"}
    Path(a.out).write_text(json.dumps(data,ensure_ascii=False,indent=2)+"\n",encoding="utf-8",newline="\n")
if __name__=='__main__': main()
