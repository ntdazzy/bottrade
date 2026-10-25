"""Check exact tested source/helper bytes in the staged index or a committed revision.
Run from the repository root. --ref HEAD checks the committed tree; default checks the index.
Reads only. Binaries/results remain local, not published.
"""
import argparse,hashlib,json,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def git(*args):return subprocess.check_output(['git',*args])
def sha(raw):return hashlib.sha256(raw).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--ref',default='');a=p.parse_args();count=0
    for bot,run in [(1,'b1-real-timed-20261025-r10'),(3,'real-take-20261025-r1')]:
        home=ROOT/('bot-cua-toi-'+str(bot));folder=home/'bang-chung/kiem-quan-ly-vi-the'/run
        record=json.loads((folder/'original-run.json').read_text())
        for key in ['sources_sha256','helpers_sha256']:
            for name,digest in record[key].items():
                path=home/'source/MQL5'/name if key=='sources_sha256' else ROOT/name
                relative=path.relative_to(Path.cwd()).as_posix()
                assert sha(path.read_bytes())==digest,'WORKSPACE_DIFFERS '+relative
                assert sha(git('show',a.ref+':'+relative))==digest,'GIT_BYTES_DIFFER '+relative
                count+=1
        assert sha((folder/'original-results.bin').read_bytes())==sha((folder/'mql5-results.bin').read_bytes())==record['result_sha256']
        report=json.loads((folder/'comparison.json').read_text())
        assert report['failed']==0 and report['matched']==report['cases']
        assert not report['whole_bot_complete'] and not report['whole_manager_complete']
    originals=[('820755052E4765D7D56E6DAAFBB28091','Gold Trade Pro MT5','a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922'),('D0E8209F77C8CF37AD8BF550E51FF075','The Gold Reaper MT5','ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83')]
    for terminal,name,digest in originals:
        path=Path.home()/'AppData/Roaming/MetaQuotes/Terminal'/terminal/'MQL5/Experts/Market'/(name+'.ex5')
        assert sha(path.read_bytes())==digest,'ORIGINAL_EX5_DIFFERS'
    manifest=Path(__file__).with_name('publication-paths.txt');paths=set(manifest.read_text().splitlines())
    args=['diff','--cached','--name-only','-z'] if not a.ref else ['diff-tree','--no-commit-id','--name-only','-r','-z',a.ref]
    actual=set(filter(None,git(*args).decode().split('\0')))
    assert actual==paths,'PUBLISHED_PATHS_DIFFER'
    assert not any(Path(n).suffix.lower() in ['.ex5','.exe','.dll','.bin','.log','.png','.pyc'] for n in actual)
    print(json.dumps(dict(source_and_helper_hashes=count,unchanged_originals=2,files=len(actual),ref=a.ref or 'index',whole_eas_complete=0)))
if __name__=='__main__':main()
