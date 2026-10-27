#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3PendingResizeBalance.mqh"
input string CheckRun="";
input int OnlyCase=-1;
union BalanceBits { double value;ulong bits; };
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   { ushort c=StringGetCharacter(CheckRun,i);if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='-')) return 4; }
   string folder="bot3-resize-balance\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x52424731 || version!=1 || count<1 || count>20000 || OnlyCase>=count) { FileClose(source);return 7; }
   int result=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(result==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(result,magic);FileWriteInteger(result,1);FileWriteInteger(result,count);
   int written=0;
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(source),fatal=FileReadInteger(source);BalanceBits current,previous,percent;
      current.bits=(ulong)FileReadLong(source);previous.bits=(ulong)FileReadLong(source);percent.bits=(ulong)FileReadLong(source);
      if((OnlyCase<0 && fatal!=0) || (OnlyCase>=0 && OnlyCase!=row)) continue;
      if(OnlyCase>=0)
      {
         int before=FileOpen(folder+"before-fault.bin",FILE_WRITE|FILE_BIN);
         if(before==INVALID_HANDLE) { FileClose(source);FileClose(result);return 9; }
         FileWriteInteger(before,id);FileWriteLong(before,(long)previous.bits);FileClose(before);
         Print("RESIZE_BALANCE_CASE:",id);
      }
      bool changed=Bot3CheckResizeBalance(current.value,previous.value,percent.value);
      FileWriteInteger(result,id);FileWriteLong(result,(long)changed);FileWriteLong(result,(long)previous.bits);written++;
   }
   if(FileTell(source)!=FileSize(source)) { FileClose(source);FileClose(result);return 10; }
   FileClose(source);FileClose(result);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,0);FileWriteInteger(status,written);FileClose(status);return 0;
}
