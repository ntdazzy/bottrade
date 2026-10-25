// Regression check: management callers must execute the real close guard.
// Terminal replies are supplied; IsStopped always prevents any trade send.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1PositionModify.mqh"
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
input string CheckRun="";
bool LinkBuy=true,LinkSelected=true;
long LinkType=0;
double LinkStopPrice=0.0;
int LinkSelects=0,LinkIntegers=0,LinkDoubles=0,LinkStopped=0,LinkFormats=0;
bool LinkSelect(const ulong ticket) { LinkSelects++;return ticket==7 && LinkSelected; }
long LinkInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   LinkIntegers++;
   return property==POSITION_MAGIC ? 747 : LinkType;
}
double LinkDouble(const ENUM_POSITION_PROPERTY_DOUBLE property) { LinkDoubles++;return LinkStopPrice; }
bool LinkIsStopped() { LinkStopped++;return true; }
void LinkFormat(const string format,const string name) { LinkFormats++; }
#define PositionSelectByTicket LinkSelect
#define PositionGetInteger LinkInteger
#define PositionGetDouble LinkDouble
#define IsStopped LinkIsStopped
#define PrintFormat LinkFormat
#include "../../Include/bot-cua-toi-1/Bot1PositionClose.mqh"
#undef PositionSelectByTicket
#undef PositionGetInteger
#undef PositionGetDouble
#undef IsStopped
#undef PrintFormat
datetime LinkTime(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   return (datetime)(shift==0 ? 1001 : 1000);
}
double LinkCandleClose(const string symbol,const ENUM_TIMEFRAMES frame,const int shift) { return LinkBuy ? 99.0 : 101.0; }
double LinkCandleOpen(const string symbol,const ENUM_TIMEFRAMES frame,const int shift) { return 100.0; }
double LinkLevel(Bot1VirtualStopState &table,long &tickets[],const string &symbol,const double &unit,
                 const int side,const double price,const double distance,const long ticket)
{
   return LinkBuy ? 120.0 : 80.0;
}
bool LinkTick(const string symbol,MqlTick &tick) { return false; }
double LinkSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property) { return 0.0; }
void LinkPrint(const string text) {}
#define iTime LinkTime
#define iClose LinkCandleClose
#define iOpen LinkCandleOpen
#define Bot1VirtualStopLevel LinkLevel
#define SymbolInfoTick LinkTick
#define SymbolInfoDouble LinkSymbolDouble
#define Print LinkPrint
#include "../../Include/bot-cua-toi-1/Bot1ManagementPrelude.mqh"
#undef iTime
#undef iClose
#undef iOpen
#undef Bot1VirtualStopLevel
#undef SymbolInfoTick
#undef SymbolInfoDouble
#undef Print

int OnStart()
{
   if(StringLen(CheckRun)==0 || StringFind(CheckRun,"..")>=0 ||
      StringFind(CheckRun,"/")>=0 || StringFind(CheckRun,"\\")>=0) return 1;
   string folder="bot1-management-close-link\\"+CheckRun+"\\";
   if(!FolderCreate("bot1-management-close-link") && GetLastError()!=0) ResetLastError();
   FolderCreate("bot1-management-close-link\\"+CheckRun);
   int output=FileOpen(folder+"results.tsv",FILE_WRITE|FILE_TXT|FILE_ANSI,0,CP_UTF8);
   if(output==INVALID_HANDLE) return 2;
   FileWriteString(output,"id\tpath\tbuy\tscenario\tselects\tintegers\tdoubles\tstopped\tformats\tmagic\tretcode\tpassed\n");
   int count=0,failed=0;
   for(int path=0;path<3;path++)
      for(int side=0;side<2;side++)
         for(int scenario=0;scenario<6;scenario++)
         {
            LinkBuy=side==0;LinkSelected=scenario!=0;
            LinkType=scenario==1 ? 2 : (LinkBuy ? 0 : 1);
            LinkSelects=LinkIntegers=LinkDoubles=LinkStopped=LinkFormats=0;
            MqlTick tick;ZeroMemory(tick);
            tick.bid=LinkBuy ? 110.0 : 90.0;tick.ask=tick.bid;
            LinkStopPrice=tick.bid-(scenario==3 || scenario==4 ? 2.0 : 0.0);
            double threshold_a=scenario==3 || scenario==4 ? 1.0 : 0.0;
            double threshold_b=scenario==3 ? 2.0 : 1.0;
            if(scenario==5) threshold_a=MathSqrt(-1.0);
            Bot1ManagedPosition position;ZeroMemory(position);
            position.ticket_number=7.0;position.open_price=100.0;
            position.volume=1.0;position.opened=1000;position.tp=200.0;
            Bot1PendingRequestState state;ZeroMemory(state);
            Bot1TradeSendOptions options;ZeroMemory(options);
            Bot1VirtualStopState table;ZeroMemory(table);
            long tickets[];double volumes[1];volumes[0]=1.0;
            double unit=1.0,initial=0.0,current=LinkBuy ? 95.0 : 105.0;
            bool changed=false;ulong deviation=0;
            uchar candle_enabled=1,timeframe=0;uint strategy_index=0;
            if(path==0)
               Bot1CloseManagementCandle(LinkBuy,"CHECK",candle_enabled,timeframe,false,position,state,options,
                                        deviation,tick,threshold_a,threshold_b);
            else if(path==1)
               Bot1StartVirtualManagement(LinkBuy,"CHECK",unit,10.0,0,position,tick,table,
                                          tickets,initial,current,state,options,deviation,
                                          threshold_a,threshold_b);
            else
               Bot1AdvanceDistanceVirtualStop(LinkBuy,"CHECK",unit,2.0,0.0,-5.0,20.0,100.0,
                                               position,tick,volumes,strategy_index,current,changed,state,
                                               options,deviation,threshold_a,threshold_b);
            int integers=scenario==0 ? 0 : 3;
            int doubles=scenario<2 ? 0 : (scenario==3 || scenario==4 ? 2 : 1);
            int stopped=scenario==4 ? 1 : 0;
            ulong magic=scenario==0 ? 0 : 747;
            uint retcode=scenario==4 ? 10027 : 0;
            bool passed=LinkSelects==1 && LinkIntegers==integers && LinkDoubles==doubles &&
                        LinkStopped==stopped && LinkFormats==stopped &&
                        state.magic==magic && state.result.retcode==retcode;
            if(!passed) failed++;
            FileWriteString(output,StringFormat("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%I64u\t%u\t%d\n",
                            count,path,(int)LinkBuy,scenario,LinkSelects,LinkIntegers,LinkDoubles,
                            LinkStopped,LinkFormats,state.magic,state.result.retcode,(int)passed));
            count++;
         }
   FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 3;
   FileWriteInteger(status,failed);FileWriteInteger(status,count);FileClose(status);
   Print("Bot1ManagementCloseLinkCheck:",failed,",",count);
   return failed;
}
