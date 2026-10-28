"""Verify the exact published gate, bridge and isolated handoff evidence."""
import argparse,hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path);a=p.parse_args();results={}
    originals={1:('820755052E4765D7D56E6DAAFBB28091','Gold Trade Pro MT5','a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922'),
               3:('D0E8209F77C8CF37AD8BF550E51FF075','The Gold Reaper MT5','ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83')}
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';terminal,name,digest=originals[bot]
        original=Path.home()/'AppData/Roaming/MetaQuotes/Terminal'/terminal/'MQL5/Experts/Market'/(name+'.ex5');require(sha(original)==digest,'ORIGINAL_EX5_CHANGED')
        output={}
        for label,count,fields,revision in [('init-sequence',1600,None,1),('prep-bridge-controls',432 if bot==1 else 2106,68 if bot==1 else 69,3)]:
            folder=home/'bang-chung/kiem-quan-ly-vi-the'/f'b{bot}-{label}-20261028-r{revision}';comparison=read(folder/'comparison.json');original_run=read(folder/'original-run.json');mql=read(folder/'mql5-run.json')
            require(comparison['cases']==comparison['matched']==count and comparison['failed']==0,'COMPARISON_FAILED '+label)
            require(not comparison['full_ea'] and not comparison['whole_bot_complete'],'SCOPE_INVALID')
            require(original_run['result_sha256']==mql['result_sha256']==sha(folder/'original-results.bin')==sha(folder/'mql5-results.bin'),'RESULT_BYTES_CHANGED '+label)
            for path,d in mql['sources_sha256'].items():require(sha(source/path)==d,'SOURCE_CHANGED '+path)
            receipt=home/'bang-chung/bien-dich'/mql['build']/'bien-nhan.json';build=read(receipt);binary=receipt.parent/Path(build['target']).with_suffix('.ex5').name
            require(sha(receipt)==mql['build_receipt_sha256'] and build['errors']==build['warnings']==0 and sha(binary)==build['binary_sha256'],'BUILD_CHANGED '+label)
            if fields is not None:require(comparison['fields']==fields,'FIELD_COUNT_CHANGED')
            output[label]=dict(cases=count,matched=comparison['matched'],fields=fields,result_sha256=original_run['result_sha256'])
        handoff=home/'bang-chung/kiem-quan-ly-vi-the'/f'b{bot}-shared-handoff-20261028-r3';report=read(handoff/'comparison.json')
        require(report['calls']==2 and report['failed']==0 and (handoff/'result.bin').read_bytes()==struct.pack('<2i',0,2),'HANDOFF_FAILED')
        for path,d in report['sources_sha256'].items():require(sha(source/path)==d,'HANDOFF_SOURCE_CHANGED '+path)
        receipt=home/'bang-chung/bien-dich'/report['build']/'bien-nhan.json';build=read(receipt);binary=receipt.parent/Path(build['target']).with_suffix('.ex5').name
        require(report['build_receipt_sha256']==sha(receipt) and build['errors']==build['warnings']==0 and sha(binary)==build['binary_sha256'],'HANDOFF_BUILD_CHANGED')
        negative=home/'bang-chung/kiem-quan-ly-vi-the'/f'b{bot}-shared-handoff-negative-20261028-r1';negative_report=read(negative/'comparison.json')
        require(negative_report['rejected'] and negative_report['wrong_state_bits']==238 and negative_report['calls']==2,'NEGATIVE_NOT_REJECTED')
        require(sha(negative/'result.bin')==negative_report['result_sha256'] and (negative/'result.bin').read_bytes()==struct.pack('<2i',238,2),'NEGATIVE_RESULT_CHANGED')
        negative_receipt=home/'bang-chung/bien-dich'/negative_report['build']/'bien-nhan.json';negative_build=read(negative_receipt);negative_binary=negative_receipt.parent/Path(negative_build['target']).with_suffix('.ex5').name
        require(sha(negative_receipt)==negative_report['build_receipt_sha256'] and negative_build['errors']==negative_build['warnings']==0 and sha(negative_binary)==negative_build['binary_sha256'],'NEGATIVE_BUILD_CHANGED')
        snapshot=ROOT/'danh-gia-doc-lap/bridge-source-20261028-r1'
        for ext in ['mqh','mq5']:
            filename=f'Bot{bot}SharedHandoffNegative'+('Check' if ext=='mq5' else '')+'.'+ext
            require(sha(snapshot/(filename+'.txt'))==negative_build['sources_sha256'][f'Scripts/bot-cua-toi-{bot}/'+filename],'NEGATIVE_SOURCE_CHANGED')
        all_receipt=home/'bang-chung/bien-dich'/f'b{bot}-all-headers-api-20261028-r17/bien-nhan.json';all_build=read(all_receipt);all_binary=all_receipt.parent/Path(all_build['target']).with_suffix('.ex5').name
        require(all_build['errors']==all_build['warnings']==0 and sha(all_binary)==all_build['binary_sha256'],'ALL_HEADERS_BUILD_CHANGED')
        for path,d in all_build['sources_sha256'].items():require(sha(source/path)==d,'ALL_HEADERS_SOURCE_CHANGED '+path)
        output['shared_handoff']=dict(calls=2,failed=0,evaluator_body_replaced=True,second_preparation_returns_early=True,previous_version_rejected=True)
        output['all_headers']=len(list((source/f'Include/bot-cua-toi-{bot}').glob('*.mqh')));output['original_sha256']=digest;results[str(bot)]=output
    result=dict(bots=results,whole_ea_complete=False,whole_dispatcher_complete=False,
       limits=['Authorization result supplied in initialization-sequence test; actual authorization body and alert are excluded.','Bridge comparison stops before evaluator; two strings use hashes.','Handoff test replaces evaluator and service replies; only one early-return scenario.','Full OnInit, OnTick, rendered interface, real account and paired EA comparison remain incomplete.'])
    if a.output:
        with a.output.open('x',encoding='utf-8',newline='\n') as f:json.dump(result,f,indent=2)
    print(json.dumps(result))
if __name__=='__main__':main()
