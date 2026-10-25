#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VirtualStops.mqh"
input string CheckRun="";
union StoreBits { double d;ulong u; };
Bot3VirtualStopState STable;
double SLevel=0,STake=0;
int SScenario=0,SGuard=0,SDigits[6],SCount=0,SFault=0;
ulong SHash=0;
ulong SBits(const double value) { StoreBits b;b.d=value;return b.u; }
double SNaN() { StoreBits b;b.u=(ulong)0x7ff8000000000000;return b.d; }
void SWord(ulong &hash,const ulong word)
{
   for(int i=0;i<8;i++) { hash^=(word>>(8*i))&255;hash*=(ulong)0x100000001b3; }
}
long SSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS || SCount>=6) { SFault=1;return 0; }
   int value=SDigits[SCount];SWord(SHash,3);SWord(SHash,(ulong)property);
   SWord(SHash,(ulong)(long)value);SWord(SHash,(ulong)SCount);SWord(SHash,0);SCount++;
   if(SCount==SScenario)
   {
      SLevel+=1.25;STake+=2.5;STable.guard=(uchar)((SGuard+1)%256);
   }
   return (long)value;
}
#define SymbolInfoInteger SSymbolInteger
#include "../../Include/bot-cua-toi-3/Bot3ManagementVirtualFinish.mqh"
#undef SymbolInfoInteger
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot3-management-virtual-store\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d565033 || version!=1 || count<1 || count>100000) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source),buy=FileReadInteger(source);SScenario=FileReadInteger(source);
      SGuard=FileReadInteger(source);int pattern=FileReadInteger(source);
      for(int k=0;k<6;k++) SDigits[k]=FileReadInteger(source);
      double initial_stop=FileReadDouble(source),initial_take=FileReadDouble(source);
      SLevel=FileReadDouble(source);STake=FileReadDouble(source);double key=FileReadDouble(source);
      if(id!=i || (buy!=0 && buy!=1) || pattern<0 || pattern>5) { SFault=9;break; }
      STable.guard=(uchar)SGuard;
      for(int row=0;row<500;row++)
      {
         STable.rows[row][0]=10000.0+row;STable.rows[row][1]=20000.0+row;STable.rows[row][2]=-30000.0-row;
         STable.take_rows[row][0]=40000.0+row;STable.take_rows[row][1]=50000.0+row;
      }
      if(pattern==0 || pattern==4 || pattern==5)
      {
         STable.rows[0][0]=key;STable.take_rows[0][0]=key;
      }
      if(pattern==1) { STable.rows[499][0]=key;STable.take_rows[499][0]=key; }
      if(pattern==2)
      {
         int indices[3]={1,17,499};
         for(int k=0;k<3;k++) { STable.rows[indices[k]][0]=key;STable.take_rows[indices[k]][0]=key; }
      }
      if(pattern==4) { STable.rows[0][0]=SNaN();STable.take_rows[0][0]=SNaN(); }
      if(pattern==5) { STable.rows[0][0]=0.0;STable.take_rows[0][0]=0.0; }
      SCount=0;SHash=(ulong)0xcbf29ce484222325;
      Bot3StoreVirtualLevels("CHECK",initial_stop,initial_take,SLevel,STake,key,STable);
      ulong table_hash=(ulong)0xcbf29ce484222325;
      for(int row=0;row<500;row++) for(int col=0;col<3;col++) SWord(table_hash,SBits(STable.rows[row][col]));
      for(int row=0;row<500;row++) for(int col=0;col<2;col++) SWord(table_hash,SBits(STable.take_rows[row][col]));
      FileWriteInteger(output,id);FileWriteInteger(output,(int)STable.guard);FileWriteInteger(output,SFault);
      FileWriteDouble(output,initial_stop);FileWriteDouble(output,initial_take);FileWriteDouble(output,SLevel);FileWriteDouble(output,STake);FileWriteDouble(output,key);
      FileWriteInteger(output,SCount);FileWriteLong(output,(long)SHash);FileWriteLong(output,(long)table_hash);
   }
   if(SFault==0 && FileTell(source)!=FileSize(source)) SFault=10;
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,SFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot3ManagementVirtualStoreCheck:",SFault,",",count);return SFault;
}
