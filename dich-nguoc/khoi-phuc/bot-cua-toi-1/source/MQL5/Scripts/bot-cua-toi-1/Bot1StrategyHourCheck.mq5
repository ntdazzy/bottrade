#property strict
datetime MockHour(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
#define iTime MockHour
#include "../../Include/bot-cua-toi-1/Bot1StrategyHour.mqh"
#undef iTime
input string CheckRun="";
string GateSymbol;long Hour,Replies[2],EffectValue,Trace[10];
int Calls,EffectCall,EffectField,Replacement;
string SymbolName(const int id)
{
   if(id==0)return "XAUUSD";
   if(id==1)return "Vàng.α";
   if(id==2)return "";
   return "GOLD.a";
}
ulong TextHash(const string value)
{
   ulong hash=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      ushort c=StringGetCharacter(value,i);
      hash^=(ulong)(c&255);hash*=(ulong)0x100000001b3;
      hash^=(ulong)(c>>8);hash*=(ulong)0x100000001b3;
   }
   return hash;
}
datetime MockHour(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   if(Calls>=2)return 0;
   const int at=5*Calls;const long reply=Replies[Calls];Calls++;
   Trace[at]=(long)frame;Trace[at+1]=(long)shift;Trace[at+2]=(long)TextHash(symbol);
   Trace[at+3]=Hour;Trace[at+4]=reply;
   if(EffectCall==Calls)
   {
      if(EffectField==1)Hour=EffectValue;
      if(EffectField==2)GateSymbol=SymbolName(Replacement);
   }
   return (datetime)reply;
}
int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="bot1-strategy-hour\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x48524731 || version!=1 || count<1)return 3;
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE)return 4;
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   for(int i=0;i<count;i++)
   {
      long id=FileReadLong(file);Hour=FileReadLong(file);Replies[0]=FileReadLong(file);Replies[1]=FileReadLong(file);
      EffectCall=(int)FileReadLong(file);EffectField=(int)FileReadLong(file);EffectValue=FileReadLong(file);
      GateSymbol=SymbolName((int)FileReadLong(file));Replacement=(int)FileReadLong(file);
      Calls=0;ArrayInitialize(Trace,0);
      bool changed=Bot1StrategyHourChanged(GateSymbol,Hour);
      FileWriteLong(out,id);FileWriteLong(out,(long)changed);FileWriteLong(out,Hour);
      FileWriteLong(out,Calls);FileWriteLong(out,(long)TextHash(GateSymbol));
      for(int j=0;j<10;j++)FileWriteLong(out,Trace[j]);
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(out);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
