// Pure component check with supplied prices. This script never sends orders.
#property script_show_inputs false
double check_prices[];
int check_digits,check_calls;
ulong check_hash;

void CheckTrace(const int api,const int first,const int second)
{
   ulong words[3]; words[0]=(ulong)api; words[1]=(ulong)(long)first; words[2]=(ulong)(long)second;
   for(int i=0;i<3;i++)
      for(int k=0;k<8;k++) { check_hash^=(words[i]>>(8*k))&0xff; check_hash*=(ulong)0x100000001b3; }
   check_calls++;
}
double CheckHigh(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   CheckTrace(1,shift,(int)timeframe);
   return shift>=0 && shift<ArraySize(check_prices) ? check_prices[shift] : 0.0;
}
double CheckLow(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   CheckTrace(2,shift,(int)timeframe);
   return shift>=0 && shift<ArraySize(check_prices) ? check_prices[shift] : 0.0;
}
long CheckInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   CheckTrace(3,(int)property,0);
   return check_digits;
}
#define iHigh CheckHigh
#define iLow CheckLow
#define SymbolInfoInteger CheckInteger
#include "../../Include/bot-cua-toi-1/Bot1PriceLevels.mqh"
#undef iHigh
#undef iLow
#undef SymbolInfoInteger

void OnStart()
{
   int handle_in=FileOpen("bot1-price-levels\\cases.bin",FILE_READ|FILE_BIN);
   if(handle_in==INVALID_HANDLE) { Print("Cannot read price-level cases: ",GetLastError()); return; }
   int magic=FileReadInteger(handle_in),version=FileReadInteger(handle_in),count=FileReadInteger(handle_in);
   if(magic!=0x50495631 || version!=1) { FileClose(handle_in); return; }
   int handle_out=FileOpen("bot1-price-levels\\mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(handle_out==INVALID_HANDLE) { FileClose(handle_in); return; }
   FileWriteInteger(handle_out,magic); FileWriteInteger(handle_out,version); FileWriteInteger(handle_out,count);
   for(int c=0;c<count;c++)
   {
      int id=FileReadInteger(handle_in),lower=FileReadInteger(handle_in),tf=FileReadInteger(handle_in);
      int older=FileReadInteger(handle_in),recent=FileReadInteger(handle_in),last=FileReadInteger(handle_in);
      check_digits=FileReadInteger(handle_in);
      int size=FileReadInteger(handle_in);
      double quote=FileReadDouble(handle_in),gap=FileReadDouble(handle_in);
      ArrayResize(check_prices,size);
      for(int i=0;i<size;i++) check_prices[i]=FileReadDouble(handle_in);
      check_calls=0; check_hash=(ulong)0xcbf29ce484222325;
      double value=lower ? Bot1LowerLevel("CHECK",(ENUM_TIMEFRAMES)tf,older,recent,last,quote,gap) :
                           Bot1UpperLevel("CHECK",(ENUM_TIMEFRAMES)tf,older,recent,last,quote,gap);
      FileWriteInteger(handle_out,id); FileWriteDouble(handle_out,value);
      FileWriteInteger(handle_out,check_calls); FileWriteLong(handle_out,(long)check_hash);
   }
   FileClose(handle_in); FileClose(handle_out);
   Print("Bot1PriceLevelsCheck: ",count," cases written");
}
