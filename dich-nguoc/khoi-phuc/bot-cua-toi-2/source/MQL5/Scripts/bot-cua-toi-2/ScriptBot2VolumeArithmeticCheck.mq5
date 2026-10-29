#property strict
#include "../../Include/bot-cua-toi-2/Bot2VolumeArithmetic.mqh"
union DoubleBits { double value;ulong bits; };
ulong ValueBits(const double value) { DoubleBits b;b.value=value;return b.bits; }
input string CheckRun="";

int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot2-volume-arithmetic\\"+CheckRun+"\\";
   int in=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(in==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(in),version=FileReadInteger(in),count=FileReadInteger(in),width=FileReadInteger(in);
   if(magic!=0x564f4c32 || version!=1 || width!=9 || count<1) { FileClose(in);return 1; }
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(out==INVALID_HANDLE) { FileClose(in);return 1; }
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);FileWriteInteger(out,width);FileWriteInteger(out,0);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(in),index=FileReadInteger(in);
      Bot2VolumeArithmeticSettings r;Bot2VolumeArithmeticContext c;Bot2VolumeArithmeticState s;
      r.use_equity=(bool)FileReadInteger(in);r.only_up=(bool)FileReadInteger(in);
      r.manual_balance=FileReadDouble(in);r.start_lots=FileReadDouble(in);r.max_lots=FileReadDouble(in);r.lot_scale=FileReadDouble(in);
      r.manual_risk=FileReadDouble(in);r.strategy_risk=FileReadDouble(in);s.mode=(uint)FileReadInteger(in);
      s.highest_balance=FileReadDouble(in);s.volume=FileReadDouble(in);s.strategy_loss=FileReadDouble(in);s.balance_step=FileReadInteger(in);
      c.balance=FileReadDouble(in);c.equity=FileReadDouble(in);c.converted_balance=FileReadDouble(in);c.tick_value=FileReadDouble(in);
      c.minimum=FileReadDouble(in);c.maximum=FileReadDouble(in);c.step=FileReadDouble(in);c.stop_distance=FileReadDouble(in);c.multiplier=FileReadInteger(in);
      bool ok=Bot2PrepareVolumeArithmetic(r,c,s);
      if(!ok)
      {
         s.volume=0.0;s.effective_balance=0.0;s.highest_balance=0.0;s.mode=0;s.strategy_loss=0.0;s.balance_step=0;
      }
      FileWriteInteger(out,id);FileWriteInteger(out,ok?1:0);
      FileWriteLong(out,(long)ValueBits(s.volume));FileWriteLong(out,(long)ValueBits(s.effective_balance));FileWriteLong(out,(long)ValueBits(s.highest_balance));
      FileWriteLong(out,(long)s.mode);FileWriteLong(out,(long)ValueBits(s.strategy_loss));FileWriteLong(out,(long)s.balance_step);
      FileWriteLong(out,(long)s.warnings);FileWriteLong(out,(long)s.alerts);FileWriteLong(out,(long)s.peak_writes);
   }
   bool exact=FileTell(in)==FileSize(in);FileClose(in);FileClose(out);return exact?0:1;
}
