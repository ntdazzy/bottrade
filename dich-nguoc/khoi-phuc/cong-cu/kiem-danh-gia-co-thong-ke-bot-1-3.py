"""Compare evaluator through closed-history text and hourly table cleanup.
prepare|mql5(--build)|original|compare BOT RUN. No original EX5 or live trading changes.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
parent=module('display_parent','cong-cu/kiem-danh-gia-lien-tuc-bot-1-3.py');active=parent.active;base=parent.base;pub=parent.pub;require=parent.require;sha=parent.sha;save=parent.save;Reader=parent.Reader;MAGIC=parent.MAGIC
cases=parent.cases;encode=parent.encode
SCOPE=dict(parent.SCOPE,final_display_excluded=False,native_closed_history_executed=True,native_hourly_results_cleanup_executed=True,whole_evaluator_complete=False)
def original(bot,casts):
    previous=parent.original(bot,casts);cfg=parent.CFG[bot];abort=0x1a63a if bot==1 else 0x22875
    class Display(previous.__class__):
        def __init__(self):
            super().__init__();self.display_entered=False;self.native_hist_selected=-1
            for api,offset in [(47,0x7d84f0),(48,0x7d8810),(49,0x7d8860),(50,0x7d8940),(51,0x7d89d0),(52,0x7d88b0)]:
                address=0x7ff683f20000+offset;self.sdk[address]=api
                if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
                self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
            self.display_calls=self.results_cleanup_calls=0
            for rva in ([0xffb0,0x32ce0] if bot==1 else [0x16e80,0x3e490]):self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+rva,end=self.base+rva)
        def state(self):
            return super().state()+struct.pack('<3Q',self.value(0x67900 if bot==1 else 0x74940,'Q'),self.value(0x67908 if bot==1 else 0x74948,'Q'),self.value(0x67448 if bot==1 else 0x74488,'i')&MASK)
        def visit(self,m,address,size,user):
            rva=address-self.base
            if rva==cfg['end']:self.display_entered=True;return
            if rva==abort:
                self.entry_decision=2 if self.saw_new_bar else 1 if self.display_entered else 0;self.terminal=rva;self.done=True;m.emu_stop();return
            if rva==(0xffb0 if bot==1 else 0x16e80):self.display_calls+=1
            if rva==(0x32ce0 if bot==1 else 0x3e490):self.results_cleanup_calls+=1
            result=super().visit(m,address,size,user)
            if rva==cfg['start']:
                for a,n in [(0x67900 if bot==1 else 0x74940,8),(0x67908 if bot==1 else 0x74948,8),(0x67448 if bot==1 else 0x74488,4)]:m.mem_write(self.base+a,bytes(n))
            return result
        def call(self,m,address,size,user):
            api=self.sdk.get(address)
            if api not in [47,48,49,50,51,52]:return super().call(m,address,size,user)
            x=self.x;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));rd=self.tape
            require(rd.block()==self.state(),'DISPLAY_STATE '+str((self.case['id'],api)));kind,a,b,c,d=rd.take('i4Q');texts=[rd.text() for _ in range(4)];payload=rd.block();error,=rd.take('I');require(kind==api and r('RCX')==self.nfp['ctx'] and payload==b'','DISPLAY_CONTEXT')
            if api==47:require((r('RDX'),r('R8'))==(a,b),'HISTORY_SELECT');m.reg_write(x.UC_X86_REG_RAX,c)
            elif api==48:m.reg_write(x.UC_X86_REG_RAX,a)
            elif api==49:require(r('RDX')&0xffffffff==a,'HISTORY_TICKET');m.reg_write(x.UC_X86_REG_RAX,b)
            else:
                require((r('RDX'),r('R8'))==(a,b),'HISTORY_PROPERTY')
                if api==50:m.reg_write(x.UC_X86_REG_RAX,c)
                elif api==51:m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(texts[0])))
                else:m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',c));m.reg_write(x.UC_X86_REG_XMM0,c)
            m.mem_write(self.base+self.nfp['error'],struct.pack('<I',error));self.api_count+=1
        def run(self,c,tape):self.display_entered=False;return super().run(c,tape)
    return Display()
def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationWithDisplayCheck.mq5';helpers=dict(parent.identity(bot)['helpers_sha256'])
    for p in [Path(__file__),ROOT/'cong-cu/tao-bo-kiem-danh-gia-co-thong-ke.py',ROOT/f'bot-cua-toi-{bot}/tests/check-position-management-flow.py']:helpers[p.relative_to(ROOT).as_posix()]=sha(p)
    return dict(original_ex5_sha256=base.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256=helpers)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases(a.bot);folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows,a.bot));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows,a.bot),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}EvaluationWithDisplayCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_CHANGED')
        files=mt/f'MQL5/Files/bot{a.bot}-evaluation-display'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('evaluation-'+a.run+'.set');ini=mt/('evaluation-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}EvaluationWithDisplayCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','sdk-tape.bin','script-status.bin','cast-values.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),casts_sha256=sha(folder/'cast-values.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tape=Reader((folder/'sdk-tape.bin').read_bytes());require(tape.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=original(a.bot,active.PARTS[a.bot].news.news.news.news.cast_values(folder/'cast-values.bin'));o.cast_calls=o.queue_clears=0;raw=bytearray(header);calls=0
        for c in rows:
            require(tape.take('i')[0]==c['id'],'TAPE_ID');state=o.run(c,tape.block());raw+=struct.pack('<2i',c['id'],len(state))+state;calls+=o.api_count
        require(tape.pos==len(tape.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        require(all(o.executed.get(k,0)>0 for k in ['evaluation','buy_manager','sell_manager','modify','close','send','table_cleanup']) and o.display_calls>0 and o.results_cleanup_calls>0,'UNEXECUTED_CHILD')
        save(folder/'decisions.json',o.terminals)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),casts_sha256=sha(folder/'cast-values.bin'),sdk_calls=calls,parent_instructions=len(o.covered),native_child_calls=o.executed,closed_display_calls=o.display_calls,hourly_results_cleanup_calls=o.results_cleanup_calls,**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls,children=o.executed)));return
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')) and r['sdk_tape_sha256']==sha(folder/'sdk-tape.bin') and r['casts_sha256']==sha(folder/'cast-values.bin'),'RUN_CHANGED')
    left,right=[(folder/(n+'-results.bin')).read_bytes() for n in ['original','mql5']];require(left==right,'RESULTS_DIFFER')
    save(folder/'comparison.json',dict(cases=len(rows),matched=len(rows),failed=0,**SCOPE,limits=['Native entry through management and all following active branches. Terminal replies and initial configuration supplied. Closed-history display and hourly cleanup included; initialization/lifecycle, all branch/error coverage, rendered UI and complete paired EA run remain excluded.']));print(json.dumps(dict(cases=len(rows),matched=len(rows),failed=0)))
if __name__=='__main__':main()
