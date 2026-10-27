#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1ManagementCallerContext.mqh"
input string CheckRun="";
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   { ushort c=StringGetCharacter(CheckRun,i);if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='-')) return 4; }
   string folder="bot1-first-zero-context\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x465a4331 || version!=1 || count<1 || count>20000) { FileClose(input_file);return 7; }
   int output_file=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output_file==INVALID_HANDLE) { FileClose(input_file);return 8; }
   FileWriteInteger(output_file,magic);FileWriteInteger(output_file,1);FileWriteInteger(output_file,count);FileWriteInteger(output_file,1);
   int fault=0;
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input_file),initial_levels=FileReadInteger(input_file),initial_count=FileReadInteger(input_file);
      int day=FileReadInteger(input_file),mode=FileReadInteger(input_file),sessions=FileReadInteger(input_file);
      int incoming=FileReadInteger(input_file),stack_shift=FileReadInteger(input_file);
      if(id!=i || mode<0 || mode>2 || sessions<0 || sessions>10 || (stack_shift%16)!=0) fault=9;
      bool value=Bot1BarFirstZeroTicketChanged((uchar)initial_levels,initial_count,day,mode==2,incoming!=0);
      FileWriteInteger(output_file,id);FileWriteLong(output_file,(long)value);
   }
   if(FileTell(input_file)!=FileSize(input_file)) fault=10;
   FileClose(input_file);FileClose(output_file);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,fault);FileWriteInteger(status,count);FileClose(status);return fault;
}
