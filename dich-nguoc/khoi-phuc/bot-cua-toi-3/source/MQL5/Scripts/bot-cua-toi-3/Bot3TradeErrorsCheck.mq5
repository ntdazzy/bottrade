#property script_show_inputs
#include <bot-cua-toi-3/Bot3TradeErrors.mqh>
input string CheckRun="";
void WriteText(const int file,const string text)
{
   int n=StringLen(text);FileWriteInteger(file,n,INT_VALUE);
   if(n>0) FileWriteString(file,text,n);
}
void WriteHeader(const int file,const int count)
{
   FileWriteInteger(file,0x45525231,INT_VALUE);FileWriteInteger(file,1,INT_VALUE);FileWriteInteger(file,count,INT_VALUE);
}
int OnStart()
{
   int length=StringLen(CheckRun);
   if(length<1 || length>48) return 1;
   for(int k=0;k<length;k++)
   {
      ushort c=StringGetCharacter(CheckRun,k);
      if(!((c>=97 && c<=122) || (c>=48 && c<=57) || c==45)) return 2;
   }
   string folder="bot3-trade-errors\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN|FILE_UNICODE);
   if(input_file==INVALID_HANDLE) return 3;
   int magic=FileReadInteger(input_file,INT_VALUE),version=FileReadInteger(input_file,INT_VALUE),count=FileReadInteger(input_file,INT_VALUE);
   if(magic!=0x45525231 || version!=1 || count<1 || count>20000 || FileSize(input_file)!=(ulong)(12+16*count)) { FileClose(input_file);return 4; }
   int result_file=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   int cast_file=FileOpen(folder+"cast-values.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(result_file==INVALID_HANDLE || cast_file==INVALID_HANDLE)
   {
      FileClose(input_file);if(result_file!=INVALID_HANDLE) FileClose(result_file);if(cast_file!=INVALID_HANDLE) FileClose(cast_file);return 5;
   }
   WriteHeader(result_file,count);WriteHeader(cast_file,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input_file,INT_VALUE),code=FileReadInteger(input_file,INT_VALUE);
      uint counter=(uint)FileReadInteger(input_file,INT_VALUE);int old_kind=FileReadInteger(input_file,INT_VALUE);
      if(id!=i || old_kind<0 || old_kind>2) { FileClose(input_file);FileClose(result_file);FileClose(cast_file);return 6; }
      string text="";
      if(old_kind==1) text="old text";
      else if(old_kind==2) { string prior="";StringInit(prior,300,120);text="Vé cũ "+prior; }
      WriteText(cast_file,(string)code);
      text=Bot3TradeErrorText(code,counter);
      FileWriteInteger(result_file,id,INT_VALUE);FileWriteInteger(result_file,(int)counter,INT_VALUE);WriteText(result_file,text);
   }
   FileClose(input_file);FileClose(result_file);FileClose(cast_file);
   int status_file=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status_file==INVALID_HANDLE) return 7;
   FileWriteInteger(status_file,0,INT_VALUE);FileWriteInteger(status_file,count,INT_VALUE);FileClose(status_file);return 0;
}
