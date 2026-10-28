"""Prove the recorder rejects equality and summation-order errors; original files stay intact."""
import argparse,importlib.util,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
s=importlib.util.spec_from_file_location('daily_negative',ROOT/'cong-cu/kiem-lo-ngay-bot-1-3.py');d=importlib.util.module_from_spec(s);s.loader.exec_module(d)
class WrongSum(d.Original):
    def arithmetic_step(self,m,address,size,user):
        op,left,right,n=self.arithmetic[address];reg=lambda name:getattr(self.x,'UC_X86_REG_'+name)
        swap=self.daily['arithmetic'][1][0];accumulate=self.daily['arithmetic'][2][0]
        if address==self.base+swap:
            self.wrong_swap=struct.unpack('<Q',m.mem_read(m.reg_read(reg(right)),8))[0]
            m.reg_write(self.x.UC_X86_REG_RIP,address+n);return
        if address==self.base+accumulate:
            old=m.reg_read(reg(left));part=m.reg_read(reg(right))&d.MASK
            result=self.host.add(self.host.add(old&d.MASK,part),self.wrong_swap)
            m.reg_write(reg(left),(old&~d.MASK)|result);m.reg_write(self.x.UC_X86_REG_RIP,address+n);return
        return super().arithmetic_step(m,address,size,user)
def records(folder,rows):
    r=d.Reader((folder/'sdk-tape.bin').read_bytes());d.require(r.take('3i')==(d.MAGIC,1,len(rows)),'HEADER');out={}
    for row in rows:d.require(r.take('i')[0]==row['id'],'CASE_ID');out[row['id']]=r.block()
    d.require(r.pos==len(r.raw),'TAPE_TRAILING');return out
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');a=p.parse_args();rows=d.cases();folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;tapes=records(folder,rows);out=[]
    equal=next(c for c in rows if c['tag']=='strict-threshold-and-sign-not-absolute' and c['daily']['Equity'][-1]==d.bits(90.))
    rounded=next(c for c in rows if c['tag']=='rounding-order-changes-close-decision')
    for name,row,cls in [('threshold-equality-closes',equal,d.Original),('sum-plus-part-plus-swap',rounded,WrongSum)]:
        o=cls(a.bot)
        try:
            if name=='threshold-equality-closes':
                rva=0x11e76 if a.bot==1 else 0x19349;old=bytes(o.m.mem_read(o.base+rva,2));d.require(old==(b'\x76\x56' if a.bot==1 else b'\x0f\x86'),'NEGATIVE_BRANCH_BYTES')
                # Only the emulator's disposable copy is changed, after the complete original hash check.
                o.m.mem_write(o.base+rva+(a.bot==3),b'\x72' if a.bot==1 else b'\x82')
            try:o.run(row,tapes[row['id']])
            except (ValueError,struct.error) as e:
                rip=o.m.reg_read(o.x.UC_X86_REG_RIP);d.require(rip==0x7ff683f20000+0x7b49f0,'WRONG_NEGATIVE_FAILURE_LOCATION '+hex(rip))
                out.append(dict(name=name,case=row['id'],tag=row['tag'],rejected=True,extra_service='Print',failure_type=type(e).__name__,original_ex5_changed=False))
            else:raise ValueError('WRONG_VERSION_ACCEPTED '+name)
        finally:o.close()
    result=dict(bot=a.bot,run=a.run,tape_sha256=d.sha(folder/'sdk-tape.bin'),tool_sha256=d.sha(Path(__file__)),daily_tool_sha256=d.sha(Path(d.__file__)),checks=out,whole_ea_complete=False)
    d.save(Path(__file__).parent/f'bot{a.bot}-negative.json',result);print(json.dumps(result))
if __name__=='__main__':main()
