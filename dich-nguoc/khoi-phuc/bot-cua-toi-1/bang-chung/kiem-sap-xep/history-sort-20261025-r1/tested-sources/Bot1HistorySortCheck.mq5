// Runs Bot1HistorySort on the cases written by kiem-sap-xep-bot-1-3.py.
// No expected values here: the tool compares both physical arrays with the original code run.
#property script_show_inputs
#include <bot-cua-toi-1/Bot1HistorySort.mqh>

input string CheckRun="";

#define SORT_CHECK_MAGIC        0x48535231
#define SORT_CHECK_VERSION      1
#define SORT_CHECK_MAX_ELEMENTS 4096

int Finish(const int code,const int processed)
{
   Print("Bot1HistorySortCheck:",code,",",processed);
   return code;
}
bool ValidRun(const string run)
{
   int length=StringLen(run);
   if(length<1 || length>40) return false;
   for(int i=0;i<length;i++)
   {
      ushort c=StringGetCharacter(run,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return false;
   }
   return true;
}
// A truncated record is rejected instead of being read as zeros.
bool Available(const int file,const long bytes)
{
   return (long)FileTell(file)+bytes<=(long)FileSize(file);
}
// Elements are loaded in memory order with the normal flag; the case flag is set afterwards.
template<typename T>
bool LoadPhysical(const int file,T &values[],const int size)
{
   ArrayFree(values);
   if(!ArraySetAsSeries(values,false) || ArrayResize(values,size)!=size) return false;
   for(int i=0;i<size;i++) values[i]=(T)FileReadLong(file);
   return true;
}
// Writes the flag left after the call and the size, then the elements in memory order.
template<typename T>
bool WritePhysical(const int file,T &values[])
{
   bool series=ArrayGetAsSeries(values);
   int size=ArraySize(values);
   FileWriteInteger(file,(int)series);
   FileWriteInteger(file,size);
   if(!ArraySetAsSeries(values,false)) return false;
   for(int i=0;i<size;i++) FileWriteLong(file,(long)values[i]);
   return ArraySetAsSeries(values,series);
}
int OnStart()
{
   if(!ValidRun(CheckRun)) return Finish(2,0);
   string folder="bot1-history-sort\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return Finish(3,0);
   int reader=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(reader==INVALID_HANDLE) return Finish(4,0);
   int magic=0,version=0,count=0;
   if(Available(reader,12))
   {
      magic=FileReadInteger(reader);version=FileReadInteger(reader);count=FileReadInteger(reader);
   }
   if(magic!=SORT_CHECK_MAGIC || version!=SORT_CHECK_VERSION || count<1) { FileClose(reader);return Finish(5,0); }
   int writer=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(writer==INVALID_HANDLE) { FileClose(reader);return Finish(6,0); }
   FileWriteInteger(writer,magic);FileWriteInteger(writer,version);FileWriteInteger(writer,count);
   ulong keys[];
   long values[];
   int code=0,processed=0;
   for(int index=0;index<count;index++)
   {
      if(!Available(reader,28)) { code=7;break; }
      int id=FileReadInteger(reader),left=FileReadInteger(reader),right=FileReadInteger(reader);
      int keys_series=FileReadInteger(reader),values_series=FileReadInteger(reader);
      int key_count=FileReadInteger(reader),value_count=FileReadInteger(reader);
      if(id!=index || keys_series<0 || keys_series>1 || values_series<0 || values_series>1 ||
         key_count<0 || key_count>SORT_CHECK_MAX_ELEMENTS || value_count<0 || value_count>SORT_CHECK_MAX_ELEMENTS ||
         !Available(reader,8*(long)(key_count+value_count))) { code=7;break; }
      if(!LoadPhysical(reader,keys,key_count) || !LoadPhysical(reader,values,value_count) ||
         !ArraySetAsSeries(keys,keys_series==1) || !ArraySetAsSeries(values,values_series==1)) { code=8;break; }
      Print("BOT1_HISTORY_SORT_CASE:",id);
      FileFlush(writer);
      Bot1HistorySort(keys,values,left,right);
      FileWriteInteger(writer,id);
      if(!WritePhysical(writer,keys) || !WritePhysical(writer,values)) { code=9;break; }
      processed++;
   }
   if(code==0 && FileTell(reader)!=FileSize(reader)) code=10;
   FileClose(reader);FileClose(writer);
   if(code!=0) return Finish(code,processed);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return Finish(11,processed);
   FileWriteInteger(status,0);FileWriteInteger(status,processed);FileClose(status);
   return Finish(0,processed);
}
