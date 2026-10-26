"""Inventory the new bot2 snapshot; read-only, native-range hashed and declaration-aware."""
from pathlib import Path
import argparse, hashlib, json, re

ROOT=Path(__file__).parent
META=ROOT/'luot-20261026-data-r2/metadata'
CAP=ROOT.parent/'bang-chung/captures/luot-20261026-r1'
BASE=0x253f2620000

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--out',required=True); a=ap.parse_args(); out=Path(a.out)
    if out.exists(): raise FileExistsError('OUTPUT_EXISTS '+str(out))
    imp=json.loads((META/'import.json').read_text(encoding='utf-8'))
    capture=json.loads((CAP/'capture.json').read_text(encoding='utf-8'))
    code=next(r for r in capture['regions'] if r.get('kind')=='executable' and r['base']==BASE)
    raw=(CAP/code['file']).read_bytes()
    if hashlib.sha256(raw).hexdigest()!=code['sha256'] or code['sha256']!=imp['code_sha256']: raise ValueError('CODE_HASH_MISMATCH')
    if capture['pid']!=imp['engine']['tester_pid']: raise ValueError('PID_MISMATCH')
    if imp['engine']['source_sha256']!='390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795': raise ValueError('SOURCE_SHA_MISMATCH')
    cpath=ROOT/'luot-20261026-data-r2/ma-trung-gian.c'; ctext=cpath.read_text(encoding='utf-8'); lines=ctext.splitlines(True)
    funcs=[]
    table=[]
    for line in (META/'functions.tsv').read_text().splitlines():
        b,e=line.split('\t')[:2]; table.append((int(b,16),int(e,16)))
    for i,(b,e) in enumerate(table,1):
        require_range=0<=b-BASE<e-BASE<=len(raw)
        if not require_range: raise ValueError('NATIVE_RANGE_OUTSIDE_CAPTURE')
        native_sha=hashlib.sha256(raw[b-BASE:e-BASE]).hexdigest()
        absolute=b; marker=f'/* Address: {absolute:x} */'; pos=ctext.find(marker)
        if pos<0:
            funcs.append({'index':i,'begin_rva':hex(b-BASE),'end_rva':hex(e-BASE),'absolute':hex(absolute),'native_body_sha256':native_sha,'status':'failed','failure_reason':'C address comment not found','c_line':None}); continue
        startline=ctext[:pos].count('\n')+1; nextpos=ctext.find('/* Address:',pos+len(marker)); body=ctext[pos:nextpos if nextpos>=0 else len(ctext)];
        declaration=next((x.strip() for x in body.splitlines() if re.search(r'\bFUN_[0-9a-f]+\s*\(',x)),None)
        if 'DECOMPILATION FAILED' in body:
            funcs.append({'index':i,'begin_rva':hex(b-BASE),'end_rva':hex(e-BASE),'absolute':hex(absolute),'native_body_sha256':native_sha,'status':'failed','failure_reason':'DECOMPILATION FAILED: Exception while decompiling; giữ nguyên, không tự điền','c_line':startline})
            continue
        code_body=body.split('{',1)[1] if '{' in body else ''
        internals=sorted(set(re.findall(r'\b(FUN_[0-9a-f]+)\s*\(',code_body)))
        named=sorted(set(re.findall(r'\b(MT5_[A-Za-z0-9_]+)\s*\(',code_body)))
        globals_=sorted(set(re.findall(r'(?:_DAT|DAT|uRam|iRam)_[0-9A-Fa-f]+',body)))
        gmap=[{'name':g,'absolute':hex(int(g.split('_')[-1],16)),'rva':hex(int(g.split('_')[-1],16)-BASE)} for g in globals_]
        funcs.append({'index':i,'begin_rva':hex(b-BASE),'end_rva':hex(e-BASE),'absolute':hex(absolute),'native_body_sha256':native_sha,'status':'done','c_line':startline,'declaration':declaration,'c_body_sha256_lf':hashlib.sha256(body.replace('\r\n','\n').encode()).hexdigest(),'direct_internal_calls':internals,'named_mt5_calls':named,'global_mentions':gmap})
    if len(funcs)!=86 or sum(x['status']=='done' for x in funcs)!=85 or sum(x['status']=='failed' for x in funcs)!=1: raise ValueError('ROW_STATUS_CHECK_FAILED')
    data={'tool_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),'native_range_hashes_computed':True,'declarations_excluded_from_call_scan':True,'bot':2,'snapshot':'luot-20261026-r1','source_sha256':imp['engine']['source_sha256'],'tester_sha256':imp['engine']['tester_sha256'],'tester_pid':imp['engine']['tester_pid'],'engine_base':imp['engine']['engine_base'],'code_base':hex(BASE),'code_sha256':imp['code_sha256'],'code_file_sha256':hashlib.sha256(raw).hexdigest(),'c_source_sha256_raw':hashlib.sha256(cpath.read_bytes()).hexdigest(),'function_count':86,'done_count':85,'failed_count':1,'functions':funcs,'scope':'86 metadata entries from one snapshot; not a whole-EA claim'}
    out.mkdir(parents=True,exist_ok=False); (out/'inventory-v2.json').write_text(json.dumps(data,ensure_ascii=False,indent=2)+'\n',encoding='utf-8',newline='\n')
    md=['# Inventory snapshot bot2 — luot-20261026-r1','',f"Nguồn EX5 SHA: `{data['source_sha256']}`; engine: `{data['tester_sha256']}`; code SHA: `{data['code_sha256']}`; 86 hàm, 85 hoàn tất, 1 lỗi.",'','| # | RVA | Trạng thái | Dòng C | Khai báo | Gọi nội bộ | SDK tên rõ |','|---:|---:|---|---:|---|---|---|']
    for f in funcs: md.append(f"| {f['index']} | `{f['begin_rva']}`..`{f['end_rva']}` | {f['status']} | {f.get('c_line','—')} | `{f.get('declaration','—')}` | `{', '.join(f.get('direct_internal_calls',[])) or '—'}` | `{', '.join(f.get('named_mt5_calls',[])) or 'chưa gắn'}` |")
    md += ['','','Phạm vi chỉ là 86 dải hàm của một snapshot; không kết luận toàn EA. Hàm lỗi giữ nguyên lý do, không tự điền.']
    (out/'inventory-v2.md').write_text('\n'.join(md)+'\n',encoding='utf-8',newline='\n')

if __name__=='__main__': main()
