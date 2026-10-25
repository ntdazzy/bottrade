#property strict
#property script_show_inputs
// Execute only the cache component with supplied symbol digits, no trade calls.
#include "../../Include/bot-cua-toi-1/Bot1PositionModify.mqh"
#include "../../Include/bot-cua-toi-1/Bot1PositionClose.mqh"
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
input string CheckRun="";
int CacheDigits=0,CacheCalls=0,CacheFault=0;
long CacheSymbolDigits(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS) CacheFault=1;
   CacheCalls++;return (long)CacheDigits;
}
#define SymbolInfoInteger CacheSymbolDigits
#include "../../Include/bot-cua-toi-1/Bot1ManagementPrelude.mqh"
#undef SymbolInfoInteger
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 2;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 2;
   }
   string folder="bot1-management-cache\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 3;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 4;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d434131 || version!=1 || count<1 || count>100000) { FileClose(source);return 5; }
   int result=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(result==INVALID_HANDLE) { FileClose(source);return 6; }
   FileWriteInteger(result,magic);FileWriteInteger(result,version);FileWriteInteger(result,count);
   double cache[100][2];string symbol="CHECK";
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source),buy=FileReadInteger(source);CacheDigits=FileReadInteger(source);
      uchar use_cached=(uchar)FileReadInteger(source);
      double ticket=FileReadDouble(source),price=FileReadDouble(source),unit=FileReadDouble(source);
      double step=FileReadDouble(source),threshold=FileReadDouble(source),copied=FileReadDouble(source);
      if(id!=i || (buy!=0 && buy!=1)) { CacheFault=7;break; }
      for(int row=0;row<100;row++) for(int col=0;col<2;col++) cache[row][col]=FileReadDouble(source);
      bool distance=false;double anchor=0.0;CacheCalls=0;
      double value=Bot1ManagementCachedReference(buy!=0,symbol,ticket,price,unit,step,threshold,use_cached,copied,cache,distance,anchor);
      FileWriteInteger(result,id);FileWriteInteger(result,CacheCalls);
      FileWriteDouble(result,value);FileWriteDouble(result,anchor);FileWriteDouble(result,copied);
      FileWriteDouble(result,(double)(long)ticket);FileWriteInteger(result,(int)distance);
      for(int row=0;row<100;row++) for(int col=0;col<2;col++) FileWriteDouble(result,cache[row][col]);
   }
   if(FileTell(source)!=FileSize(source)) CacheFault=8;
   FileClose(source);FileClose(result);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,CacheFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot1ManagementCacheCheck:",CacheFault,",",count);return CacheFault;
}
