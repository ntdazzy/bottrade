#property strict
// Arithmetic/state check only. No trading API is called.
#include "../../Include/bot-cua-toi-1/Bot1StrategySelection.mqh"
union DoubleBits { double value; ulong bits; };
ulong ValueBits(const double value) { DoubleBits v;v.value=value;return v.bits; }
input string CheckRun="";

int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot1-strategy-selection\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x53454c31 || version!=1 || count<1) { FileClose(h);return 1; }
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(out==INVALID_HANDLE) { FileClose(h);return 1; }
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(h);uint mask=(uint)FileReadInteger(h);
      Bot1StrategySelectionInput settings;
      settings.run_strategy_a=(mask&1)!=0;settings.run_strategy_b=(mask&2)!=0;
      settings.run_strategy_c=(mask&4)!=0;settings.run_strategy_d=(mask&8)!=0;
      settings.run_strategy_e=(mask&16)!=0;settings.run_strategy_f=(mask&32)!=0;
      settings.run_strategy_g=(mask&64)!=0;settings.run_strategy_h=(mask&128)!=0;
      Bot1StrategySelectionState state;Bot1SelectStrategies(settings,state);
      FileWriteInteger(out,id);FileWriteInteger(out,(int)state.enabled_mask);
   }
   bool exact=FileTell(h)==FileSize(h);FileClose(h);FileClose(out);
   return exact ? 0 : 1;
}
