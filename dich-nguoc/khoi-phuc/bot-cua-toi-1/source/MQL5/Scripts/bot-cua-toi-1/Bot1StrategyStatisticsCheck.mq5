#property strict
input string CheckRun="";
union Number { double value;ulong word; };
ulong ReplyBits;int ReplyCount,Calls,CalledIndex;
#include "../../Include/bot-cua-toi-1/Bot1StrategyHistory.mqh"
double MockClosed(const uchar &show_tester,const string &symbol,const int &magic,const uint &current,
                  int &closed[],Bot1StrategyHistoryCache &cache)
{
   Calls++;CalledIndex=(int)current;closed[current]=ReplyCount;
   Number value;value.word=ReplyBits;return value.value;
}
#define Bot1StrategyClosedProfit MockClosed
#include "../../Include/bot-cua-toi-1/Bot1StrategyStatistics.mqh"
#undef Bot1StrategyClosedProfit
int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="bot1-strategy-statistics\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x53544132 || version!=1 || count<1)return 3;
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE)return 4;
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file),changed=FileReadInteger(file),caller=FileReadInteger(file),current=FileReadInteger(file);
      ReplyBits=(ulong)FileReadLong(file);int initial_count=FileReadInteger(file);ReplyCount=FileReadInteger(file);
      int closed[8];double total[8],average[8];
      for(int j=0;j<8;j++){closed[j]=10+j;total[j]=10.25+(double)j;average[j]=-300.5-(double)j;}
      closed[caller]=initial_count;Calls=0;CalledIndex=-1;
      uchar show=1;string symbol="XAUUSD";int owner=9001;uint current_index=(uint)current;
      Bot1StrategyHistoryCache cache;
      Bot1UpdateStrategyStatistics(changed!=0,(uint)caller,show,symbol,owner,current_index,closed,cache,total,average);
      FileWriteInteger(out,id);FileWriteInteger(out,Calls);FileWriteInteger(out,CalledIndex);
      for(int j=0;j<8;j++)FileWriteInteger(out,closed[j]);
      for(int j=0;j<8;j++){Number x;x.value=total[j];FileWriteLong(out,(long)x.word);}
      for(int j=0;j<8;j++){Number x;x.value=average[j];FileWriteLong(out,(long)x.word);}
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(out);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
