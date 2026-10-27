#property strict
input string CheckRun="";
datetime SelectorTime();
#define TimeTradeServer SelectorTime
#include "../../Include/bot-cua-toi-1/Bot1NewsSelector.mqh"
#undef TimeTradeServer
Bot1NewsEvents QueryEvents;Bot1NewsWindows QueryWindows;Bot1NewsSelection QuerySelection;
long QueryClocks[3];int ClockCalls,Mutation,EventFile;
void WriteText(const int file,const string value)
{
   if(value==NULL) { FileWriteInteger(file,-1);return; }
   int n=StringLen(value);FileWriteInteger(file,n);if(n>0) FileWriteString(file,value,n);
}
void WriteState(const int file)
{
   FileWriteLong(file,QuerySelection.block_time);WriteText(file,QuerySelection.label);
   FileWriteLong(file,QueryEvents.nfp);FileWriteLong(file,QueryEvents.interest);FileWriteLong(file,QueryEvents.cpi);
   FileWriteLong(file,(long)QueryWindows.nfp_enabled);FileWriteLong(file,(long)QueryWindows.interest_enabled);FileWriteLong(file,(long)QueryWindows.cpi_enabled);
   FileWriteLong(file,(long)QueryWindows.nfp_after);FileWriteLong(file,(long)QueryWindows.interest_after);FileWriteLong(file,(long)QueryWindows.cpi_after);
}
datetime SelectorTime()
{
   long reply=QueryClocks[MathMin(ClockCalls,2)];FileWriteLong(EventFile,reply);WriteState(EventFile);ClockCalls++;
   if(Mutation==1 && ClockCalls==1) QueryEvents.nfp=1700;
   else if(Mutation==2 && ClockCalls==2) QueryEvents.interest=50;
   else if(Mutation==3 && ClockCalls==2) QueryEvents.cpi=20;
   else if(Mutation==4 && ClockCalls==1) QueryWindows.interest_enabled=0;
   else if(Mutation==5 && ClockCalls==1) QueryWindows.interest_after=2147483647;
   else if(Mutation==6 && ClockCalls==2) { QuerySelection.block_time=5;QuerySelection.label="Changed"; }
   return (datetime)reply;
}
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot1-news-selector\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4e535331 || version!=1 || count<1) { FileClose(file);return 3; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),numeric=FileOpen(folder+"numeric-regression.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE || numeric==INVALID_HANDLE) { FileClose(file);return 4; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(file);QueryEvents.nfp=FileReadLong(file);QueryEvents.interest=FileReadLong(file);QueryEvents.cpi=FileReadLong(file);
      QueryWindows.nfp_enabled=(uchar)FileReadInteger(file);QueryWindows.interest_enabled=(uchar)FileReadInteger(file);QueryWindows.cpi_enabled=(uchar)FileReadInteger(file);
      QueryWindows.nfp_after=FileReadInteger(file);QueryWindows.interest_after=FileReadInteger(file);QueryWindows.cpi_after=FileReadInteger(file);
      for(int i=0;i<3;i++) QueryClocks[i]=FileReadLong(file);Mutation=FileReadInteger(file);ClockCalls=0;
      QuerySelection.block_time=999;QuerySelection.label="Previous";
      string name=folder+"events-"+IntegerToString(id)+".bin";EventFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(EventFile==INVALID_HANDLE) return 5;
      Bot1UpdateNewsSelection(QueryEvents,QueryWindows,QuerySelection);FileClose(EventFile);
      int events=FileOpen(name,FILE_READ|FILE_BIN);if(events==INVALID_HANDLE) return 6;
      int size=(int)FileSize(events);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(events,bytes,0,size);FileClose(events);
      FileWriteInteger(output,id);FileWriteInteger(output,size);if(size>0) FileWriteArray(output,bytes,0,size);WriteState(output);
      if(Mutation==0 && QueryClocks[0]==QueryClocks[1] && QueryClocks[1]==QueryClocks[2])
      {
         Bot1NewsBlockState old;
         Bot1SelectNewsBlock(QueryClocks[0],QueryWindows.nfp_enabled!=0,QueryEvents.nfp,QueryWindows.nfp_after,
                              QueryWindows.interest_enabled!=0,QueryEvents.interest,QueryWindows.interest_after,
                              QueryWindows.cpi_enabled!=0,QueryEvents.cpi,QueryWindows.cpi_after,old);
         FileWriteInteger(numeric,id);FileWriteLong(numeric,old.block_time);
      }
   }
   FileClose(file);FileClose(output);FileClose(numeric);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
