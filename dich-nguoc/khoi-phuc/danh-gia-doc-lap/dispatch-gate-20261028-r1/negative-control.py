"""Reject two wrong gate branches in a disposable emulator copy; keep EX5 files intact."""
import argparse,importlib.util,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
s=importlib.util.spec_from_file_location('gate_negative',ROOT/'cong-cu/kiem-cong-dieu-phoi-bot-1-3.py');g=importlib.util.module_from_spec(s);s.loader.exec_module(g)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');a=p.parse_args();rows=g.cases();folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run
    tape=g.Reader((folder/'sdk-tape.bin').read_bytes());actual=g.Reader((folder/'mql5-results.bin').read_bytes());g.require(tape.take('3i')==actual.take('3i')==(g.MAGIC,1,len(rows)),'HEADER');records={}
    for row in rows:
        g.require(tape.take('i')[0]==actual.take('i')[0]==row['id'],'CASE');records[row['id']]=(tape.block(),actual.block())
    g.require(tape.pos==len(tape.raw) and actual.pos==len(actual.raw),'TRAILING')
    fresh=next(c for c in rows if c['tag']=='byte-flags-time-and-bar' and c['mode']==0 and c['m1']==1 and c['bars'][0]==101)
    even=next(c for c in rows if c['tag']=='byte-flags-time-and-bar' and c['mode']==0 and c['m1']==2 and c['bars'][0]==99)
    results=[]
    for name,row in [('new-bar-obeys-old-stop',fresh),('any-nonzero-m1-stops',even)]:
        o=g.Original(a.bot)
        if name=='new-bar-obeys-old-stop':
            rva=0x11070 if a.bot==1 else 0x18038;g.require(bytes(o.m.mem_read(o.base+rva,2))==b'\xeb\x0a','NEGATIVE_JUMP_BYTES');o.m.mem_write(o.base+rva,b'\xeb\x00')
        else:
            rva=0x11072 if a.bot==1 else 0x1803a;g.require(bytes(o.m.mem_read(o.base+rva,4))==b'\x40\xf6\xc7\x01','NEGATIVE_TEST_BYTES');o.m.mem_write(o.base+rva,b'\x40\x84\xff\x90')
        events,expected=records[row['id']];wrong=o.run(row,events)
        g.require(wrong[:-8]==expected[:-8] and expected[-8:]==bytes(8) and wrong[-8:]==struct.pack('<Q',1),'NEGATIVE_DID_NOT_ISOLATE_WRONG_STOP')
        results.append(dict(name=name,case=row['id'],rejected=True,expected_stop=False,wrong_stop=True,original_ex5_changed=False))
    result=dict(bot=a.bot,run=a.run,tape_sha256=g.sha(folder/'sdk-tape.bin'),tool_sha256=g.sha(Path(__file__)),gate_tool_sha256=g.sha(Path(g.__file__)),checks=results,whole_ea_complete=False)
    g.save(Path(__file__).parent/f'bot{a.bot}-negative.json',result);print(json.dumps(result))
if __name__=='__main__':main()
