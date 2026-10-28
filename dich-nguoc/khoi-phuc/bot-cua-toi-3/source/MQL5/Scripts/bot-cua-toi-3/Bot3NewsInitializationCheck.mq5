#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-3/Bot3NfpCalendar.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ReleaseCalendars.mqh"
datetime InitServer();
#define TimeTradeServer InitServer
#include "../../Include/bot-cua-toi-3/Bot3NewsSelector.mqh"
#undef TimeTradeServer
Bot3NewsWindows InitWindows;Bot3NewsEvents InitEvents;Bot3NewsSelection InitSelection;
long InitQuery,InitReplies[3],InitClocks[3];int InitCounts[7],InitOutput;
struct InitEffect { int api,n,field;long value;string label; };InitEffect InitEffects[];
void InitText(const string value)
{
   int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(InitOutput,n);if(n>0)FileWriteString(InitOutput,value,n);
}
string InitReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void InitState()
{
   FileWriteLong(InitOutput,(long)InitWindows.nfp_enabled);FileWriteLong(InitOutput,(long)InitWindows.interest_enabled);FileWriteLong(InitOutput,(long)InitWindows.cpi_enabled);
   FileWriteLong(InitOutput,(long)InitWindows.nfp_after);FileWriteLong(InitOutput,(long)InitWindows.interest_after);FileWriteLong(InitOutput,(long)InitWindows.cpi_after);
   FileWriteLong(InitOutput,InitEvents.nfp);FileWriteLong(InitOutput,InitEvents.interest);FileWriteLong(InitOutput,InitEvents.cpi);
   FileWriteLong(InitOutput,InitSelection.block_time);FileWriteLong(InitOutput,InitQuery);InitText(InitSelection.label);
}
void InitEffectNow(const int api,const int n)
{
   for(int i=0;i<ArraySize(InitEffects);i++)
   {
      if(InitEffects[i].api!=api || InitEffects[i].n!=n)continue;
      long v=InitEffects[i].value;
      switch(InitEffects[i].field)
      {
         case 0:InitWindows.nfp_enabled=(uchar)v;break;case 1:InitWindows.interest_enabled=(uchar)v;break;case 2:InitWindows.cpi_enabled=(uchar)v;break;
         case 3:InitWindows.nfp_after=(int)v;break;case 4:InitWindows.interest_after=(int)v;break;case 5:InitWindows.cpi_after=(int)v;break;
         case 6:InitEvents.nfp=v;break;case 7:InitEvents.interest=v;break;case 8:InitEvents.cpi=v;break;
         case 9:InitSelection.block_time=v;break;case 10:InitQuery=v;break;case 11:InitSelection.label=InitEffects[i].label;break;
      }
   }
}
void InitRecord(const int api,const long argument,const string value=NULL)
{
   InitState();FileWriteInteger(InitOutput,api);FileWriteLong(InitOutput,argument);InitText(value);int n=++InitCounts[api];InitEffectNow(api,n);
}
long InitNfp(){long reply=InitReplies[0];InitRecord(1,reply);return reply;}
long InitInterest(){long reply=InitReplies[1];InitRecord(2,reply);return reply;}
long InitCpi(){long reply=InitReplies[2];InitRecord(3,reply);return reply;}
datetime InitServer(){int n=InitCounts[6];long reply=InitClocks[n<3 ? n : 2];InitRecord(6,reply);return (datetime)reply;}
void InitPrint(const string value){InitRecord(5,0,value);}
string Bot3InitializationTimeText(const datetime value){string reply=(string)value;InitRecord(4,(long)value,reply);return reply;}
#define BOT3_INITIALIZATION_TIME_TEXT_MQH
#define Bot3FindNfpTime InitNfp
#define Bot3FindInterestRateTime InitInterest
#define Bot3FindCpiTime InitCpi
#define Print InitPrint
#include "../../Include/bot-cua-toi-3/Bot3NewsInitialization.mqh"
#undef Print
#undef Bot3FindNfpTime
#undef Bot3FindInterestRateTime
#undef Bot3FindCpiTime
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-news-initialization\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x494e5331 || version!=1 || count<1)return 3;
   InitOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(InitOutput==INVALID_HANDLE)return 4;
   FileWriteInteger(InitOutput,magic);FileWriteInteger(InitOutput,version);FileWriteInteger(InitOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);InitWindows.nfp_enabled=(uchar)FileReadLong(file);InitWindows.interest_enabled=(uchar)FileReadLong(file);InitWindows.cpi_enabled=(uchar)FileReadLong(file);
      InitWindows.nfp_after=(int)FileReadLong(file);InitWindows.interest_after=(int)FileReadLong(file);InitWindows.cpi_after=(int)FileReadLong(file);
      InitEvents.nfp=FileReadLong(file);InitEvents.interest=FileReadLong(file);InitEvents.cpi=FileReadLong(file);InitSelection.block_time=FileReadLong(file);InitQuery=FileReadLong(file);InitSelection.label=InitReadText(file);
      for(int i=0;i<3;i++)InitReplies[i]=FileReadLong(file);for(int i=0;i<3;i++)InitClocks[i]=FileReadLong(file);
      int effects=FileReadInteger(file);if(effects<0 || effects>128)return 5;ArrayResize(InitEffects,effects);
      for(int i=0;i<effects;i++){InitEffects[i].api=FileReadInteger(file);InitEffects[i].n=FileReadInteger(file);InitEffects[i].field=FileReadInteger(file);InitEffects[i].value=0;InitEffects[i].label=NULL;if(InitEffects[i].field==11)InitEffects[i].label=InitReadText(file);else InitEffects[i].value=FileReadLong(file);}
      ArrayInitialize(InitCounts,0);FileWriteInteger(InitOutput,id);ulong at=FileTell(InitOutput);FileWriteInteger(InitOutput,0);ulong begin=FileTell(InitOutput);
      Bot3InitializeNews(InitWindows,InitEvents,InitSelection,InitQuery);InitState();
      ulong end=FileTell(InitOutput);FileSeek(InitOutput,(long)at,SEEK_SET);FileWriteInteger(InitOutput,(int)(end-begin));FileSeek(InitOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 6;FileClose(file);FileClose(InitOutput);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
