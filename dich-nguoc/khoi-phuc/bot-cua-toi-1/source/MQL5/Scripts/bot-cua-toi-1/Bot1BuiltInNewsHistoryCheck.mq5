#property strict
input string CheckRun="";
uchar HistoryFlag0,HistoryFlag1;long HistoryNfp[300],HistoryInterest[300],HistoryCpi[300],HistoryReply;
int HistoryEffect,HistoryCalls,HistoryOutput;
void HistoryState()
{
   FileWriteLong(HistoryOutput,(long)HistoryFlag0);FileWriteLong(HistoryOutput,(long)HistoryFlag1);
   for(int i=0;i<300;i++)FileWriteLong(HistoryOutput,HistoryNfp[i]);
   for(int i=0;i<300;i++)FileWriteLong(HistoryOutput,HistoryInterest[i]);
   for(int i=0;i<300;i++)FileWriteLong(HistoryOutput,HistoryCpi[i]);
}
long HistoryInfo(const ENUM_MQL_INFO_INTEGER property)
{
   HistoryState();FileWriteInteger(HistoryOutput,(int)property);FileWriteLong(HistoryOutput,HistoryReply);HistoryCalls++;
   if(HistoryEffect==1)HistoryFlag0=7;else if(HistoryEffect==2)HistoryFlag1=255;
   else if(HistoryEffect==3)HistoryNfp[299]=-11;else if(HistoryEffect==4)HistoryInterest[250]=123456789;
   else if(HistoryEffect==5)HistoryCpi[299]=17;else if(HistoryEffect==6)HistoryNfp[0]=999;
   else if(HistoryEffect==7)HistoryInterest[0]=999;else if(HistoryEffect==8)HistoryCpi[0]=999;
   return HistoryReply;
}
#define MQLInfoInteger HistoryInfo
#include "../../Include/bot-cua-toi-1/Bot1BuiltInNewsHistory.mqh"
#undef MQLInfoInteger
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-builtin-news-history\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x49484331 || version!=1 || count<1)return 3;
   HistoryOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(HistoryOutput==INVALID_HANDLE)return 4;
   FileWriteInteger(HistoryOutput,magic);FileWriteInteger(HistoryOutput,version);FileWriteInteger(HistoryOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);HistoryFlag0=(uchar)FileReadInteger(file);HistoryFlag1=(uchar)FileReadInteger(file);HistoryReply=FileReadLong(file);HistoryEffect=FileReadInteger(file);
      for(int i=0;i<300;i++)HistoryNfp[i]=FileReadLong(file);for(int i=0;i<300;i++)HistoryInterest[i]=FileReadLong(file);for(int i=0;i<300;i++)HistoryCpi[i]=FileReadLong(file);
      HistoryCalls=0;FileWriteInteger(HistoryOutput,id);ulong at=FileTell(HistoryOutput);FileWriteInteger(HistoryOutput,0);ulong begin=FileTell(HistoryOutput);
      Bot1InitializeBuiltInNewsHistory(HistoryFlag0,HistoryFlag1,HistoryNfp,HistoryInterest,HistoryCpi);HistoryState();FileWriteInteger(HistoryOutput,HistoryCalls);
      ulong end=FileTell(HistoryOutput);FileSeek(HistoryOutput,(long)at,SEEK_SET);FileWriteInteger(HistoryOutput,(int)(end-begin));FileSeek(HistoryOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 5;FileClose(file);FileClose(HistoryOutput);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
