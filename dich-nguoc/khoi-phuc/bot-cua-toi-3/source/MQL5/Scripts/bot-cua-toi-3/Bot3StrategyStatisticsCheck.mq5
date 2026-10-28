#property strict
input string CheckRun="";
union Number { double value;ulong word; };
ulong ReplyBits;int ReplyCount,Calls,CalledIndex;
#include "../../Include/bot-cua-toi-3/Bot3StrategyHistory.mqh"
double MockClosed(const uchar &show_tester,const string &symbol,const int &magic,const uint &current,
                  int &closed[],Bot3StrategyHistoryCache &cache)
{
   Calls++;CalledIndex=(int)current;closed[current]=ReplyCount;
   Number value;value.word=ReplyBits;return value.value;
}
#define Bot3StrategyClosedProfit MockClosed
#include "../../Include/bot-cua-toi-3/Bot3StrategyStatistics.mqh"
#undef Bot3StrategyClosedProfit
int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="bot3-strategy-statistics\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x53544132 || version!=1 || count<1)return 3;
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE)return 4;
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file),changed=FileReadInteger(file),caller=FileReadInteger(file),current=FileReadInteger(file);
      ReplyBits=(ulong)FileReadLong(file);int initial_count=FileReadInteger(file);ReplyCount=FileReadInteger(file);
      int closed[9];double total[9],average[9];
      for(int j=0;j<9;j++){closed[j]=10+j;total[j]=10.25+(double)j;average[j]=-300.5-(double)j;}
      closed[caller]=initial_count;Calls=0;CalledIndex=-1;
      uchar show=1;string symbol="XAUUSD";int owner=9001;uint current_index=(uint)current;
      Bot3StrategyHistoryCache cache;
      Bot3UpdateStrategyStatistics(changed!=0,(uint)caller,show,symbol,owner,current_index,closed,cache,total,average);
      FileWriteInteger(out,id);FileWriteInteger(out,Calls);FileWriteInteger(out,CalledIndex);
      for(int j=0;j<9;j++)FileWriteInteger(out,closed[j]);
      for(int j=0;j<9;j++){Number x;x.value=total[j];FileWriteLong(out,(long)x.word);}
      for(int j=0;j<9;j++){Number x;x.value=average[j];FileWriteLong(out,(long)x.word);}
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(out);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
