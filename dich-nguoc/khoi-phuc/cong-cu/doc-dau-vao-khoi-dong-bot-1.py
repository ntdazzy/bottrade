"""Read preparation inputs from a real bot-1 capture with all profiles disabled.

RUN names a completed chay-chup-bot-1-3.py --disable-strategies run.
This is a read-only observation after OnInit, not an observation of every
constructor output. The EX5, code anchors, input flags and capture hashes must match.
"""
import argparse,hashlib,importlib.util,json,re,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('startup_input_contract',ROOT/'cong-cu/kiem-nap-chien-luoc-bot-1-3.py')
setup=importlib.util.module_from_spec(spec);spec.loader.exec_module(setup)
require=setup.require
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('run');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN')
    home=ROOT/'bot-cua-toi-1';folder=home/'bang-chung'/a.run;capture=home/'bang-chung/captures'/a.run
    record=json.loads((folder/'capture-run.json').read_text());meta=json.loads((capture/'capture.json').read_text())
    require(record['strategy_profiles_disabled'] and record['capture_exit']==record['runner_exit']==0 and record['test_completed'],'RUN_NOT_COMPLETED')
    chain,full,data=setup.contract(1)
    require(record['source_sha256']==setup.identity(1,chain)['original_ex5_sha256'],'ORIGINAL_CHANGED')
    require(record['tester_pid']==meta['pid'] and not meta['errors'],'CAPTURE_IDENTITY_CHANGED')
    require(meta.get('ready_byte',{}).get('rva')=='0x67930' and meta['ready_byte']['value']==1,'INITIALIZATION_NOT_OBSERVED')
    inputs=record['job']['inputs'];require(all(inputs[f'RunStrategy{v}']=='false' for v in 'ABCDEFGH'),'PROFILE_INPUTS_ENABLED')
    regions=[]
    for r in meta['regions']:
        path=capture/r['file'];require(sha(path)==r['sha256'],'CAPTURE_BYTES_CHANGED');regions.append((r,path.read_bytes()))
    code=[r for r,_ in regions if r['kind']=='executable' and r['protect']==0x20 and r['bytes']>=8192]
    require(len(code)==1,'AMBIGUOUS_CODE');base=code[0]['base']
    def read_abs(address,size):
        for r,raw in regions:
            if r['base']<=address and address+size<=r['base']+len(raw):return raw[address-r['base']:address-r['base']+size]
        raise ValueError('VALUE_OUTSIDE_CAPTURE '+hex(address))
    def read(rva,size):return read_abs(base+rva,size)
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64
    md=Cs(CS_ARCH_X86,CS_MODE_64)
    anchors={0x7512:'rax, '+hex(base+0x621c4),0x751c:'rcx, '+hex(base+0x621c8)}
    for pc,operand in anchors.items():
        i=next(md.disasm(read(pc,15),base+pc));require(i.mnemonic=='movabs' and i.op_str==operand,'PREPARATION_LAYOUT_CHANGED')
    require(all(read(0x6a580+8*i,1)==b'\0' for i in range(8)),'PROFILE_FLAG_NOT_ZERO')
    require(struct.unpack('<I',read(0x678f4,4))[0]==0,'PREPARATION_INDEX_CHANGED')
    fields=[('indicator_period','i',0x621c4),('indicator_day','B',0x621c8)]+full.legacy.fields(full.legacy.INPUTS,1)+[(r[0],r[1],r[2]) for r in full.EXTRA]
    rows=[]
    for name,kind,rva in fields:
        raw=read(rva,struct.calcsize('<'+kind));value=struct.unpack('<'+kind,raw)[0]
        rows.append(dict(field=name,kind=kind,rva=hex(rva),value=value,raw_hex=raw.hex(),user_input=rva>=0x6a500))
    strings=[]
    for name,rva in [('preparation_comment',0x622d0),('symbol_suffix',0x62208),('working_symbol',0x67918)]:
        pointer=struct.unpack_from('<Q',read(rva,12),4)[0]
        try:
            if pointer==0:value=None
            else:
                length=struct.unpack('<I',read_abs(pointer-4,4))[0];require(length<10000,'STRING_TOO_LONG');value=read_abs(pointer,2*length).decode('utf-16-le')
            strings.append(dict(field=name,rva=hex(rva),observed=True,value=value))
        except ValueError:strings.append(dict(field=name,rva=hex(rva),observed=False,reason='The string heap bytes were not captured.'))
    report=dict(original_ex5_sha256=record['source_sha256'],capture_sha256=sha(capture/'capture.json'),run_record_sha256=sha(folder/'capture-run.json'),
                tester_sha256=record['tester_sha256'],code_base=hex(base),profile_flags_zero=8,preparation_index=0,fields=rows,strings=strings,
                full_ea=False,scope='Live preparation inputs after initialization with all eight profiles disabled; not raw constructor output defaults.')
    target=folder/'observed-preparation-inputs.json'
    with target.open('x',encoding='utf-8',newline='\n') as out:json.dump(report,out,ensure_ascii=False,indent=2)
    print(json.dumps(dict(fields=len(rows),internal_fields=sum(not r['user_input'] for r in rows),strings=strings,output=str(target)),ensure_ascii=False))
if __name__=='__main__':main()
