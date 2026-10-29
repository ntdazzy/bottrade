"""Read-only exact Git/source/evidence check for bot2 volume validation.

--run RUN --build BUILD --all-headers BUILD --manifest FILE [--ref HEAD]
Run from the workspace root after staging only the manifest's files.
"""
import argparse,hashlib,importlib.util,json,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];WORK=ROOT.parents[1];HOME=ROOT/'bot-cua-toi-2';SRC=HOME/'source/MQL5'
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
pub=module('volume2_publication','kiem-ban-git-quan-ly.py');require=pub.require
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--run',required=True);p.add_argument('--build',required=True);p.add_argument('--all-headers',required=True);p.add_argument('--manifest',type=Path,required=True);p.add_argument('--ref',default='');a=p.parse_args()
    require(Path.cwd().resolve()==WORK.resolve(),'RUN_FROM_WORKSPACE_ROOT')
    folder=HOME/'bang-chung/kiem-khoi-luong-hop-le'/a.run;baseline=read(folder/'baseline.json');count=0
    def exact(path,digest):
        nonlocal count
        rel=path.resolve().relative_to(WORK).as_posix();require(sha(path)==digest,'WORKSPACE_BYTES_DIFFER '+rel)
        require(hashlib.sha256(pub.git('show',a.ref+':'+rel)).hexdigest()==digest,'GIT_BYTES_DIFFER '+rel);count+=1
    paths={'source_mqh':SRC/'Include/bot-cua-toi-2/Bot2VolumeValidation.mqh',
           'source_mq5':SRC/'Scripts/bot-cua-toi-2/Bot2VolumeValidationCheck.mq5',
           'helper':ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-2.py',
           'native_loader':ROOT/'cong-cu/kiem-gio-mua-he-bot-2.py',
           'metadata':HOME/'phan-tich/luot-20261026-data-r2/metadata/import.json'}
    for name,path in paths.items():exact(path,baseline['identity'][name])
    result=subprocess.run([sys.executable,'-I','-B','-X','utf8',str(paths['helper']),'compare',a.run],cwd=WORK,capture_output=True,text=True,check=True)
    report=json.loads(result.stdout.strip());require(report['failed']==0 and report['matched']==report['cases'],'CASES_NOT_PASSING')
    for build in [a.build,a.all_headers]:
        receipt=HOME/'bang-chung/bien-dich'/build/'bien-nhan.json';data=read(receipt)
        require(data['errors']==data['warnings']==0,'BUILD_NOT_CLEAN')
        for path in pub.closure(SRC/data['target'],SRC):exact(path,data['sources_sha256'][path.relative_to(SRC).as_posix()])
        require(sha(receipt.parent/Path(data['target']).with_suffix('.ex5').name)==data['binary_sha256'],'ARCHIVED_BINARY_CHANGED')
    original=Path('C:/Users/NTD/Desktop/BotTradeEA/local/market-demos-20261020/dich-nguoc-luot2/terminal/MQL5/Experts/Market/Goldbot One MT5.ex5')
    require(sha(original)==baseline['original_ex5_sha256']=='390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795','ORIGINAL_EX5_CHANGED')
    wanted=set(a.manifest.read_text(encoding='utf-8').splitlines());args=['diff','--cached','--name-only','-z'] if not a.ref else ['diff-tree','--no-commit-id','--name-only','-r','-z',a.ref]
    actual=set(filter(None,pub.git(*args).decode().split('\0')));require(actual==wanted,'PUBLISHED_PATHS_DIFFER')
    require(not any(Path(n).suffix.lower() in ['.ex5','.exe','.dll','.bin','.log','.pyc'] for n in actual),'BINARY_OR_LOG_STAGED')
    print(json.dumps(dict(ref=a.ref or 'index',files=len(actual),exact_file_hashes=count,cases=report['cases'],fault_cases=report['fault_cases'],original_unchanged=True,whole_ea_complete=False)))
if __name__=='__main__':main()
