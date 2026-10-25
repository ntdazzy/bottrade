"""Archive a bounded Claude batch, validating real model/effort from API journals.
Usage: thu-ket-qua-claude.py BATCH --runs RUN ... [--refused RUN ...]
--refused is a human-reviewed classification of a textual refusal, even is_error=false.
Pending jobs are recorded as pending; no result is treated as source verification.
"""
import argparse,datetime,hashlib,json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];WS=ROOT.parents[1]
JOURNALS=Path('C:/Users/NTD/.claude/projects/C--Users-NTD-Desktop-Bot-Market-Demo')
sha=lambda raw:hashlib.sha256(raw).hexdigest()
def require(value,message):
    if not value:raise ValueError(message)
def stamp(value):return datetime.datetime.fromisoformat(value.replace('Z','+00:00'))
def message(row):
    content=row.get('message',{}).get('content','')
    if isinstance(content,str):return content
    return '\n'.join(x.get('text','') for x in content if isinstance(x,dict) and x.get('type')=='text') if isinstance(content,list) else ''
def rows(raw):
    out=[]
    for line in raw.splitlines():
        try:out.append(json.loads(line))
        except json.JSONDecodeError:pass
    return out
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2);f.write('\n')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('batch');p.add_argument('--runs',nargs='+',required=True);p.add_argument('--refused',nargs='*',default=[]);a=p.parse_args()
    for name in [a.batch]+a.runs+a.refused:require(re.fullmatch('[a-z0-9-]{1,64}',name),'BAD_NAME')
    require(len(a.runs)==len(set(a.runs)) and set(a.refused)<=set(a.runs),'BAD_RUN_LIST')
    target=ROOT/'danh-gia-claude'/a.batch;require(not target.exists(),'BATCH_EXISTS')
    ledger=[];archives=[];now=datetime.datetime.now(datetime.timezone.utc).isoformat()
    for run in a.runs:
        matches=list((ROOT.parent/'.local').glob('claude-parallel-*/'+run+'/job.json'));require(len(matches)==1,'AMBIGUOUS_JOB '+run)
        jp=matches[0];folder=jp.parent;jb=jp.read_bytes();job=json.loads(jb.decode('utf-8-sig'));prompt=(folder/'prompt.txt').read_bytes()
        require(sha(prompt)==job['prompt_sha256'],'PROMPT_HASH_DIFFERS '+run)
        response_raw=(folder/'response.json').read_bytes();response=json.loads(response_raw.decode('utf-8-sig')) if response_raw else None
        if response:
            journal=JOURNALS/(response['session_id']+'.jsonl');raw=journal.read_bytes();records=rows(raw)
        else:
            hits=[]
            for journal in JOURNALS.glob('*.jsonl'):
                if journal.stat().st_mtime<stamp(job['started']).timestamp()-1200:continue
                raw=journal.read_bytes();records=rows(raw)
                if any(r.get('type')=='user' and message(r).strip()==prompt.decode('utf-8').strip() for r in records):hits.append((journal,raw,records))
            require(len(hits)==1,'AMBIGUOUS_SESSION '+run);journal,raw,records=hits[0]
        require(any(r.get('type')=='user' and message(r).strip()==prompt.decode('utf-8').strip() for r in records),'JOURNAL_PROMPT_DIFFERS '+run)
        requests=[]
        for row in records:
            if row.get('type')!='api-request' or not row.get('timestamp') or stamp(row['timestamp'])<stamp(job['started']):continue
            cfg=row['params'];requests.append(dict(timestamp=row['timestamp'],model=cfg.get('model'),effort=cfg.get('output_config',{}).get('effort')))
        require(requests and all(r['model']=='claude-opus-5-5' and r['effort']=='max' for r in requests),'ACTUAL_MODEL_EFFORT_DIFFERS '+run)
        output=(WS/job['output_directory']).resolve();require(output.is_relative_to(ROOT/'claude-thuc-hien'),'OUTPUT_OUTSIDE_SCOPE')
        files={str(f.relative_to(WS)).replace('\\','/'):sha(f.read_bytes()) for f in output.rglob('*') if f.is_file() and f.name!='TASK.md'}
        status='pending-final-response'
        if response:
            if response.get('is_error'):status='provider-blocked-or-error'
            elif run in a.refused:status='textual-refusal'
            elif files:status='delivered-unverified'
            else:status='no-deliverables-needs-classification'
        require(not(run in a.refused and response is None),'REFUSAL_WITHOUT_FINAL '+run)
        record=dict(run=run,session_id=journal.stem,started=job['started'],snapshot_utc=now,status=status,
         response_is_error=response.get('is_error') if response else None,terminal_reason=response.get('terminal_reason') if response else None,
         job_sha256=sha(jb),prompt_sha256=sha(prompt),response_sha256=sha(response_raw) if response else None,
         actual_requests=len(requests),requests=requests,ultracode_requested=job.get('ultracode_requested'),ultracode_runtime_confirmed=None,
         journal_prefix_bytes=len(raw),journal_prefix_sha256=sha(raw),files_sha256=files,source_validated=False,whole_bot_complete=False)
        ledger.append(record)
        if response:archives.append((run,record,jb,prompt,response_raw))
    target.mkdir(parents=True)
    for run,record,jb,prompt,response_raw in archives:
        folder=target/run;folder.mkdir()
        for name,raw in [('job.json',jb),('prompt.txt',prompt),('response.json',response_raw)]:
            with (folder/name).open('xb') as f:f.write(raw)
        save(folder/'receipt.json',record)
    save(target/'dispatch.json',dict(snapshot_utc=now,jobs=ledger,whole_bot_complete=False))
    print(json.dumps([dict(run=r['run'],status=r['status'],actual_requests=r['actual_requests'],files=len(r['files_sha256'])) for r in ledger]))
if __name__=='__main__':main()
