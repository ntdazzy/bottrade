#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1TickSymbolRouting.mqh"
string ReadText(const int h){int n=FileReadInteger(h);return n<0 ? NULL : (n==0 ? "" : FileReadString(h,n));}
void Text(const int h,const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(h,n);if(n>0)FileWriteString(h,value,n);}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-tick-symbol\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x53594d31 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file);uint error=(uint)FileReadInteger(file);string chart_name=ReadText(file),working=ReadText(file);
      ResetLastError();if(error!=0)SetUserError((ushort)(error-65536));
      bool configured=Bot1PrepareTickSymbol(chart_name,working);uint final_error=GetLastError();
      FileWriteInteger(output,id);FileWriteInteger(output,(int)configured);FileWriteInteger(output,(int)final_error);Text(output,chart_name);Text(output,working);
   }
   if(FileTell(file)!=FileSize(file))return 5;FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
