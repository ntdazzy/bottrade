#property strict
input string CheckRun="";
input int OnlyCase=-1;
long QueryNow;int EventReply,ValueReply,EventOutput;bool EventSeries,ValueSeries;
ulong EventIds[];string EventNames[];long ValueTimes[];
void WriteText(const int h,const string value)
{ int n=StringLen(value);FileWriteInteger(h,n);if(n>0) FileWriteString(h,value,n); }
string ReadText(const int h)
{ int n=FileReadInteger(h);if(n<0) return NULL;return n>0 ? FileReadString(h,n) : ""; }
void Record(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const string message="")
{
   FileWriteInteger(EventOutput,api);FileWriteLong(EventOutput,(long)a);FileWriteLong(EventOutput,(long)b);
   FileWriteLong(EventOutput,(long)c);FileWriteLong(EventOutput,(long)d);WriteText(EventOutput,message);FileFlush(EventOutput);
}
datetime CalendarServer()
{ Record(1,(ulong)QueryNow);return (datetime)QueryNow; }
int CalendarEvents(const string currency,MqlCalendarEvent &events[])
{
   Record(2,(ulong)(long)EventReply,(ulong)ArraySize(EventIds),0,0,currency);
   ArrayResize(events,ArraySize(EventIds));
   for(int i=0;i<ArraySize(events);i++) { ZeroMemory(events[i]);events[i].id=EventIds[i];events[i].name=EventNames[i]; }
   ArraySetAsSeries(events,EventSeries);
   return EventReply;
}
int CalendarValues(const ulong event_id,MqlCalendarValue &values[],const datetime from,const datetime to=0)
{
   Record(3,event_id,(ulong)from,(ulong)to,(ulong)(long)ValueReply);
   ArrayResize(values,ArraySize(ValueTimes));
   for(int i=0;i<ArraySize(values);i++) { ZeroMemory(values[i]);values[i].time=(datetime)ValueTimes[i]; }
   ArraySetAsSeries(values,ValueSeries);
   return ValueReply;
}
#define TimeTradeServer CalendarServer
#define CalendarEventByCurrency CalendarEvents
#define CalendarValueHistoryByEvent CalendarValues
#include "../../Include/bot-cua-toi-3/Bot3NfpCalendar.mqh"
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-nfp-calendar\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(h==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x4e465031 || version!=1 || count<1) { FileClose(h);return 3; }
   int normal=0;
   for(int row=0;row<count;row++)
   {
      FileReadInteger(h);int fatal=FileReadInteger(h);if(fatal==0) normal++;
      FileReadLong(h);for(int k=0;k<5;k++) FileReadInteger(h);int total=FileReadInteger(h);
      for(int i=0;i<total;i++) { FileReadLong(h);ReadText(h); }
      total=FileReadInteger(h);for(int i=0;i<total;i++) FileReadLong(h);
   }
   FileSeek(h,12,SEEK_SET);int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(h);return 4; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,normal);FileFlush(output);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(h),fatal=FileReadInteger(h);QueryNow=FileReadLong(h);int initial_error=FileReadInteger(h);
      EventReply=FileReadInteger(h);ValueReply=FileReadInteger(h);EventSeries=FileReadInteger(h)!=0;ValueSeries=FileReadInteger(h)!=0;int total=FileReadInteger(h);ArrayResize(EventIds,total);ArrayResize(EventNames,total);
      for(int i=0;i<total;i++) { EventIds[i]=(ulong)FileReadLong(h);EventNames[i]=ReadText(h); }
      total=FileReadInteger(h);ArrayResize(ValueTimes,total);for(int i=0;i<total;i++) ValueTimes[i]=FileReadLong(h);
      if(OnlyCase<0 ? fatal!=0 : id!=OnlyCase) continue;
      string name=folder+"events-"+IntegerToString(id)+".bin";
      EventOutput=FileOpen(name,FILE_WRITE|FILE_BIN);if(EventOutput==INVALID_HANDLE) { FileClose(h);FileClose(output);return 5; }
      Print("NFP_CALENDAR_CASE:",id);SetUserError((ushort)(initial_error-65536));
      long selected=Bot3FindNfpTime();int last_error=GetLastError();FileClose(EventOutput);
      int events=FileOpen(name,FILE_READ|FILE_BIN);if(events==INVALID_HANDLE) return 6;
      int size=(int)FileSize(events);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(events,bytes,0,size);FileClose(events);
      FileWriteInteger(output,id);FileWriteLong(output,selected);FileWriteInteger(output,last_error);FileWriteInteger(output,size);
      if(size>0) FileWriteArray(output,bytes,0,size);
   }
   FileClose(h);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 7;FileWriteInteger(status,0);FileWriteInteger(status,normal);FileClose(status);return 0;
}
