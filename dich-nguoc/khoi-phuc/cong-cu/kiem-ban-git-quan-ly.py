"""Read-only publication check for exact management sources and scoped evidence.
From the workspace root: --manifest FILE --case-run BOT:RUN [--compile-only BOT:BUILD]
Default checks the staged index; --ref HEAD checks the committed tree.
"""
import argparse,hashlib,json,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];WORK=ROOT.parents[1]
def require(ok,message):
    if not ok:raise ValueError(message)
def sha(raw):return hashlib.sha256(raw).hexdigest()
def git(*args):return subprocess.check_output(['git',*args],cwd=WORK)
def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def pair(value):
    require(re.fullmatch('[13]:[a-z0-9-]{1,64}',value),'BAD_BOT_RUN')
    bot,name=value.split(':');return int(bot),name
def closure(path,base):
    seen=set();pending=[path.resolve()]
    while pending:
        current=pending.pop()
        if current in seen:continue
        require(current.is_relative_to(base.resolve()),'INCLUDE_OUTSIDE_SOURCE')
        require(current.is_file(),'SOURCE_MISSING '+str(current));seen.add(current)
        pending.extend((current.parent/n).resolve() for n in re.findall(r'^\s*#include\s+"([^"]+)"',current.read_text(encoding='utf-8-sig'),re.M))
    return seen
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--manifest',type=Path,required=True);p.add_argument('--case-run',action='append',default=[]);p.add_argument('--compile-only',action='append',default=[]);p.add_argument('--ref',default='');a=p.parse_args()
    require(Path.cwd().resolve()==WORK.resolve(),'RUN_FROM_WORKSPACE_ROOT')
    count=0
    def exact(path,digest):
        nonlocal count
        relative=path.resolve().relative_to(WORK).as_posix()
        require(sha(path.read_bytes())==digest,'WORKSPACE_BYTES_DIFFER '+relative)
        require(sha(git('show',a.ref+':'+relative))==digest,'GIT_BYTES_DIFFER '+relative);count+=1
    results=[]
    for value in a.case_run:
        bot,name=pair(value);home=ROOT/('bot-cua-toi-'+str(bot));folder=home/'bang-chung/kiem-quan-ly-vi-the'/name;run=read(folder/'original-run.json');actual=read(folder/'mql5-run.json');report=read(folder/'comparison.json')
        require(report['failed']==0 and report['matched']==report['cases'] and report['cases']>0,'CASES_NOT_PASSING')
        require(not report['whole_bot_complete'] and not report['whole_manager_complete'],'SCOPE_NOT_PARTIAL')
        for key in ['sources_sha256','helpers_sha256']:
            for n,digest in run[key].items():exact(home/'source/MQL5'/n if key=='sources_sha256' else ROOT/n,digest)
        require(sha((folder/'original-results.bin').read_bytes())==run['result_sha256']==actual['result_sha256']==sha((folder/'mql5-results.bin').read_bytes()),'LOCAL_RESULTS_DIFFER')
        results.append(dict(bot=bot,run=name,cases=report['cases']))
    for value in a.compile_only:
        bot,name=pair(value);home=ROOT/('bot-cua-toi-'+str(bot));receipt=home/'bang-chung/bien-dich'/name/'bien-nhan.json';build=read(receipt)
        require(type(build['errors']) is int and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        base=home/'source/MQL5'
        for path in closure(base/build['target'],base):exact(path,build['sources_sha256'][path.relative_to(base.resolve()).as_posix()])
        binary=receipt.parent/Path(build['target']).with_suffix('.ex5').name
        require(sha(binary.read_bytes())==build['binary_sha256'],'LOCAL_BINARY_DIFFERS')
    originals=[('820755052E4765D7D56E6DAAFBB28091','Gold Trade Pro MT5','a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922'),('D0E8209F77C8CF37AD8BF550E51FF075','The Gold Reaper MT5','ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83')]
    for terminal,name,digest in originals:require(sha((Path.home()/'AppData/Roaming/MetaQuotes/Terminal'/terminal/'MQL5/Experts/Market'/(name+'.ex5')).read_bytes())==digest,'ORIGINAL_EX5_DIFFERS')
    wanted=set(a.manifest.read_text(encoding='utf-8').splitlines());args=['diff','--cached','--name-only','-z'] if not a.ref else ['diff-tree','--no-commit-id','--name-only','-r','-z',a.ref];actual=set(filter(None,git(*args).decode().split('\0')))
    require(actual==wanted,'PUBLISHED_PATHS_DIFFER')
    require(not any(Path(n).suffix.lower() in ['.ex5','.exe','.dll','.bin','.log','.png','.pyc'] for n in actual),'BINARY_OR_TEMP_STAGED')
    print(json.dumps(dict(ref=a.ref or 'index',exact_file_hashes=count,files=len(actual),case_runs=results,compile_only=a.compile_only,unchanged_originals=2,whole_eas_complete=0)))
if __name__=='__main__':main()
