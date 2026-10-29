#property strict
input string CheckRun="";
input int CheckCase=-1;
union DoubleBits { double value;ulong bits; };
ulong ValueBits(const double value) { DoubleBits b;b.value=value;return b.bits; }
double minimum_value,maximum_value,step_value,last_value;
int call_count=0,trace_file=INVALID_HANDLE,format_file=INVALID_HANDLE;
ulong call_hash=0;
bool api_error=false;
void Trace(const ulong api,const ulong property,const ulong value)
{
   ulong words[3];words[0]=api;words[1]=property;words[2]=value;
   for(int n=0;n<3;n++) for(int b=0;b<8;b++) { call_hash^=(words[n]>>(8*b))&0xff;call_hash*=(ulong)0x100000001b3; }
   if(trace_file!=INVALID_HANDLE) { for(int n=0;n<3;n++) FileWriteLong(trace_file,(long)words[n]); FileFlush(trace_file); }
   call_count++;
}
double MockSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="XAUUSD") api_error=true;
   if(property==SYMBOL_VOLUME_MIN) last_value=minimum_value;
   else if(property==SYMBOL_VOLUME_MAX) last_value=maximum_value;
   else if(property==SYMBOL_VOLUME_STEP) last_value=step_value;
   else { api_error=true;last_value=0.0; }
   Trace(1,(ulong)property,ValueBits(last_value));return last_value;
}
void MockPrint(const string message)
{
   string prefixes[3]={"Volume is less than the minimal allowed SYMBOL_VOLUME_MIN=",
                       "Volume is greater than the maximal allowed SYMBOL_VOLUME_MAX=",
                       "Volume is not a multiple of the minimal step SYMBOL_VOLUME_STEP="};
   int kind=0;
   for(int i=0;i<3;i++) if(message==prefixes[i]+(string)last_value) { kind=i+1;break; }
   if(kind==0) api_error=true;
   Trace(2,(ulong)kind,ValueBits(last_value));
}
#define SymbolInfoDouble MockSymbolDouble
#define Print MockPrint
#include "../../Include/bot-cua-toi-2/Bot2VolumeValidation.mqh"
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot2-volume-validation\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x56414c31 || version!=3 || count<1 || FileSize(h)!=(ulong)12+(ulong)count*36) { FileClose(h);return 1; }
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(out==INVALID_HANDLE) { FileClose(h);return 1; }
   format_file=FileOpen(folder+"formatted.txt",FILE_WRITE|FILE_TXT|FILE_ANSI);
   if(format_file==INVALID_HANDLE) { FileClose(h);FileClose(out);return 1; }
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   if(CheckCase>=0) trace_file=FileOpen(folder+"fault-trace.bin",FILE_WRITE|FILE_BIN);
   if(CheckCase>=0 && trace_file==INVALID_HANDLE) { FileClose(h);FileClose(out);return 1; }
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(h);double amount=FileReadDouble(h);minimum_value=FileReadDouble(h);maximum_value=FileReadDouble(h);step_value=FileReadDouble(h);
      FileWriteString(format_file,IntegerToString(id)+"|"+(string)minimum_value+"|"+(string)maximum_value+"|"+(string)step_value+"\r\n");
      if(CheckCase>=0 && id!=CheckCase) continue;
      call_count=0;call_hash=(ulong)0xcbf29ce484222325;api_error=false;
      FileWriteInteger(out,id);FileFlush(out);
      ResetLastError();
      bool accepted=Bot2ValidateVolume("XAUUSD",amount);
      uint last_error=GetLastError();
      FileWriteInteger(out,api_error ? -2 : (int)accepted);FileWriteInteger(out,call_count);FileWriteLong(out,(long)call_hash);FileWriteInteger(out,(int)last_error);
   }
   bool exact=FileTell(h)==FileSize(h);FileClose(h);FileClose(out);FileClose(format_file);if(trace_file!=INVALID_HANDLE) FileClose(trace_file);return exact ? 0 : 1;
}
