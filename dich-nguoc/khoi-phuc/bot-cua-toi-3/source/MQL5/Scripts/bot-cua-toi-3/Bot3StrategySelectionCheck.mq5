#property strict
// Arithmetic/state check only. No trading API is called.
#include "../../Include/bot-cua-toi-3/Bot3StrategySelection.mqh"
union DoubleBits { double value; ulong bits; };
ulong ValueBits(const double value) { DoubleBits v;v.value=value;return v.bits; }
input string CheckRun="";

int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-strategy-selection\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x53454c31 || version!=1 || count<1) { FileClose(h);return 1; }
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(out==INVALID_HANDLE) { FileClose(h);return 1; }
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(h);Bot3StrategySelectionInput settings;
      settings.trade_frequency=FileReadInteger(h);settings.risk=FileReadInteger(h);
      settings.max_allowed_dd=FileReadDouble(h);settings.converted_balance=FileReadDouble(h);
      settings.use_variable_values=FileReadInteger(h)!=0;settings.manual_menu_mask=(uint)FileReadInteger(h);
      settings.initial_enabled_mask=(uint)FileReadInteger(h);settings.initial_mode=FileReadInteger(h);
      settings.initial_divisor=FileReadDouble(h);settings.threshold_flags=(uint)FileReadInteger(h);
      Bot3StrategySelectionState state;Bot3SelectStrategies(settings,state);
      FileWriteInteger(out,id);FileWriteInteger(out,state.mode);
      FileWriteInteger(out,(int)state.enabled_mask);FileWriteLong(out,(long)ValueBits(state.divisor));
   }
   bool exact=FileTell(h)==FileSize(h);FileClose(h);FileClose(out);
   return exact ? 0 : 1;
}
