#property strict
// Arithmetic check only. No trading API is called.
#include "../../Include/bot-cua-toi-1/Bot1Volume.mqh"
input string CheckRun="";
union DoubleBits { double value; ulong bits; };
ulong ValueBits(const double value) { DoubleBits v;v.value=value;return v.bits; }
int OnStart()
{
   if(CheckRun=="") { Print("CheckRun is required");return 1; }
   string folder="bot1-volume\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(h),version=FileReadInteger(h),bot=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x564f4c31 || version!=1 || bot!=1 || count<1 || FileSize(h)!=(ulong)16+(ulong)count*172)
   { FileClose(h);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(h);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);FileWriteInteger(output,9);
   int enums[]={ACCOUNT_BALANCE,ACCOUNT_EQUITY,SYMBOL_TRADE_TICK_VALUE,SYMBOL_VOLUME_MIN,SYMBOL_VOLUME_MAX,SYMBOL_VOLUME_STEP};
   for(int e=0;e<ArraySize(enums);e++) FileWriteInteger(output,enums[e]);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(h);
      Bot1VolumeSettings r;Bot1VolumeContext c;Bot1VolumeState s;
      r.use_equity=FileReadInteger(h)!=0;
      r.only_up=FileReadInteger(h)!=0;
      r.manual_balance=FileReadDouble(h);
      r.start_lots=FileReadDouble(h);
      r.max_lots=FileReadDouble(h);
      r.lot_scale=FileReadDouble(h);
      r.manual_risk=FileReadDouble(h);
      r.strategy_risk=FileReadDouble(h);
      s.mode=(uint)FileReadInteger(h);
      s.highest_balance=FileReadDouble(h);
      s.volume=FileReadDouble(h);
      s.strategy_loss=FileReadDouble(h);
      s.balance_step=FileReadInteger(h);
      c.balance=FileReadDouble(h);
      c.equity=FileReadDouble(h);
      c.converted_balance=FileReadDouble(h);
      c.converted_dd_balance=FileReadDouble(h);
      c.tick_value=FileReadDouble(h);
      c.minimum=FileReadDouble(h);
      c.maximum=FileReadDouble(h);
      c.step=FileReadDouble(h);
      c.stop_distance=FileReadDouble(h);
      c.multiplier=FileReadInteger(h);
      c.enabled_mask=(uint)FileReadInteger(h);
      bool ok=Bot1PrepareVolume(r,c,s);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)ok);
      FileWriteLong(output,ok ? (long)ValueBits(s.volume) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(s.effective_balance) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(s.highest_balance) : 0);
      FileWriteLong(output,ok ? (long)s.mode : 0);
      FileWriteLong(output,ok ? (long)ValueBits(s.strategy_loss) : 0);
      FileWriteLong(output,ok ? (long)s.balance_step : 0);
      FileWriteLong(output,ok ? (long)s.warnings : 0);
      FileWriteLong(output,ok ? (long)s.alerts : 0);
      FileWriteLong(output,ok ? (long)s.peak_writes : 0);
   }
   FileClose(h);FileClose(output);
   Print("Volume check: ",count," cases written");return 0;
}
