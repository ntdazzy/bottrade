"""Compare continuous bot 3 OnInit 0x458e..0x5f34 on shared state.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
The two entry-level and three panel children record arguments; no boundary reset.
"""
import importlib.util
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('post3_port',ROOT/'cong-cu/kiem-trang-thai-giao-dich-khoi-dong-bot-3.py');tr3=importlib.util.module_from_spec(s);s.loader.exec_module(tr3)
path=ROOT/'cong-cu/kiem-noi-khoi-dong-bot-1.py'
source=tr3.port(path.read_text(encoding='utf-8'))
source=source.replace('kiem-trang-thai-giao-dich-khoi-dong-bot-1.py','kiem-trang-thai-giao-dich-khoi-dong-bot-3.py').replace('kiem-duoi-khoi-dong-bot-1.py','kiem-duoi-khoi-dong-bot-3.py')
source=source.replace("tr=module('joined_trading','kiem-trang-thai-giao-dich-khoi-dong-bot-3.py')","tr=module('joined_trading','kiem-trang-thai-giao-dich-khoi-dong-bot-3.py').b")
source=source.replace("tail=module('joined_tail','kiem-duoi-khoi-dong-bot-3.py')","tail=module('joined_tail','kiem-duoi-khoi-dong-bot-3.py').b")
source=source.replace('0x62480','0x6d578').replace('0x8320','0xef40').replace('0xe1b0','0x14fa0').replace('0xffb0','0x16e80')
source=source.replace('original_hash(1)','original_hash(3)').replace('native_init_sha256=boot.INIT_SHA',"native_init_sha256=tr.identity()['native_init_sha256']")
source=source.replace('MinimumSpread,FridayClosed,','MinimumSpread,').replace('Volumes[8]','Volumes[9]').replace('TailBars[8]','TailBars[9]')
source=source.replace('for i in range(8):','for i in range(9):').replace("('P.strategy_index',7)","('P.strategy_index',8)").replace('for(int i=0;i<8;i++)Panel.lots[i]','for(int i=0;i<9;i++)Panel.lots[i]')
source=source.replace('for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word(Bits(Queue.orders[i][j]));','for(int i=0;i<500;i++)for(int j=0;j<2;j++)Word(Bits(Manager.table.take_rows[i][j]));for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word(Bits(Queue.orders[i][j]));')
source=source.replace('bytes(self.m.mem_read(self.base+0x6d680,12000))+','bytes(self.m.mem_read(self.base+0x6d680,12000))+bytes(self.m.mem_read(self.base+0x70560,8000))+')
source=source.replace('[(0x6d680,1500,.125),(0x724b0,300,.25)]','[(0x6d680,1500,.125),(0x70560,1000,.375),(0x724b0,300,.25)]')
source=source.replace('sp+0xe8','sp+0xf8').replace("[('RSP',sp),('RBP',self.base+0x1d6e48),('R12',self.print_api),('R14',0x7ff6846f1c40),('R15',self.base+0x5c0)]","[('RSP',sp),('RBP',0x7ff6846f1c40),('R12',self.print_api),('R13',0x7ff6846ef6c0),('R15',self.base+0x5c0)]")
old='''const int &seed,const string &symbol,const double &balance,const double &volume,
              const int &mode,const double &risk,const double &strategy_risk,const int &step,const Bot3NewsEvents &events,'''
new='''const int &seed,const string &symbol,const double &balance,const int &frequency,
              const uint &mode,const double &manual_lots,const double &allowed_dd,const double &strategy_risk,const Bot3NewsEvents &events,'''
tr3.require(source.count(old)==1,'JOINED_OPEN_SIGNATURE');source=source.replace(old,new)
source=source.replace("elif api==10:require(reg('RDX')==args[0]==6,'TAIL_INFO_ARGS');reply=args[1]","elif api==10:raise RuntimeError('UNEXPECTED_TESTER_GATE_IN_BOT3_TAIL')")
source=source.replace('table_cells=1800','table_cells=2800')
source=source.replace("'SHARED_FIELD_TYPE'","'SHARED_FIELD_TYPE '+str((n,hex(r),match,renamed(n),k))")
source=source.replace("if __name__=='__main__':main()",'')
exec(compile(source,__file__,'exec'),globals())
_identity=identity
def identity():
    current=_identity();current['helpers_sha256'][path.relative_to(ROOT).as_posix()]=sha(path);return current
SCOPE=dict(SCOPE,authorization_executed=False,authorization_entry_guarded=True,virtual_take_table_checked=True)
if __name__=='__main__':main()
