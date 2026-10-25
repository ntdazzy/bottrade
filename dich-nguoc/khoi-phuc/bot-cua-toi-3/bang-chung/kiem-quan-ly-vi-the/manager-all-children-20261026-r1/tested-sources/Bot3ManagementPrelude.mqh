// Reconstructed management-prefix functions; verification scope is recorded in evidence.
// Prelude of native 0x32f60 (buy 0x330f1..0x33b73) and 0x37590 (sell 0x3771e..0x38194).
// Not complete management functions: no outer loop, anchor or trailing branches here.
#ifndef BOT3_MANAGEMENT_PRELUDE_MQH
#define BOT3_MANAGEMENT_PRELUDE_MQH
#include "Bot3PriceLevels.mqh"
#include "Bot3PositionModify.mqh"
#include "Bot3PositionClose.mqh"

struct Bot3ManagedPosition
{
   double sl;
   double tp;
   double ticket_number;
   double open_price;
   string comment;
   double volume;
   long opened;
   long type;
   long magic;
   string symbol;
};

bool Bot3ReadManagementPosition(const int index,const bool buy,
                               const int &magic,const int &enabled,const string &symbol,
                               ulong &last_ticket,MqlTick &tick,Bot3ManagedPosition &position)
{
   last_ticket=PositionGetTicket(index);
   if(last_ticket==0) return false;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   position.sl=Bot3RoundPrice(PositionGetDouble(POSITION_SL),digits);
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   position.tp=Bot3RoundPrice(PositionGetDouble(POSITION_TP),digits);
   position.ticket_number=(double)(long)last_ticket;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   position.open_price=Bot3RoundPrice(PositionGetDouble(POSITION_PRICE_OPEN),digits);
   position.comment=PositionGetString(POSITION_COMMENT);
   position.volume=PositionGetDouble(POSITION_VOLUME);
   position.opened=PositionGetInteger(POSITION_TIME);
   position.type=PositionGetInteger(POSITION_TYPE);
   position.magic=PositionGetInteger(POSITION_MAGIC);
   position.symbol=PositionGetString(POSITION_SYMBOL);
   if(!SymbolInfoTick(symbol,tick)) Print("Tick not ok");
   if((int)position.type!=(buy ? 0 : 1)) return false;
   if(magic!=(int)position.magic || enabled!=1) return false;
   return position.symbol==symbol;
}

void Bot3FillManagementInitialLevels(const bool buy,const string &symbol,
                                    const double &unit,const double &stop_distance,
                                    const double &take_distance,Bot3ManagedPosition &position,
                                    Bot3PendingRequestState &state,Bot3TradeSendOptions &options)
{
   if(position.sl==0.0)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      double price=buy ? position.open_price-stop_distance*unit
                       : stop_distance*unit+position.open_price;
      position.sl=Bot3RoundPrice(price,digits);
      Bot3ModifyPosition(state,options,(ulong)(long)position.ticket_number,position.sl,position.tp);
   }
   if(position.tp==0.0)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      double price=buy ? take_distance*unit+position.open_price
                       : position.open_price-take_distance*unit;
      position.tp=Bot3RoundPrice(price,digits);
      Bot3ModifyPosition(state,options,(ulong)(long)position.ticket_number,position.sl,position.tp);
   }
}

// Groups 0/1/2: enabled bytes 0x6d29e/0x6d2a0/0x6d2a2, timeframe bytes 0x6d29d/0x6d29f/0x6d2a1;
// every group's first iTime uses shift byte 0x6d29c. The caller runs groups 0,1,2 in order.
ENUM_TIMEFRAMES Bot3ManagementCandleTimeframe(const uchar &setting,const int group)
{
   if(group==1) return (ENUM_TIMEFRAMES)(setting==0 ? 0 : 15);
   if(group==2) return (ENUM_TIMEFRAMES)(setting==0 ? 0 : 0x4001);
   return (ENUM_TIMEFRAMES)(int)setting;
}

void Bot3CloseManagementCandle(const bool buy,const string &symbol,const int group,
                              const uchar &enabled,const uchar &timeframe,const uchar &shift,
                              const Bot3ManagedPosition &position,const MqlTick &tick,
                              Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                              const ulong &deviation,const double &threshold_a,
                              const double &threshold_b)
{
   if(enabled!=1) return;
   long previous=(long)iTime(symbol,Bot3ManagementCandleTimeframe(timeframe,group),(int)shift);
   if(previous>position.opened) return;
   long current=(long)iTime(symbol,Bot3ManagementCandleTimeframe(timeframe,group),0);
   if(position.opened>=current) return;
   double close=iClose(symbol,Bot3ManagementCandleTimeframe(timeframe,group),1);
   double open=iOpen(symbol,Bot3ManagementCandleTimeframe(timeframe,group),1);
   if(!(buy ? close<open : open<close)) return;
   close=iClose(symbol,Bot3ManagementCandleTimeframe(timeframe,group),1);
   if(!(buy ? close<position.open_price : position.open_price<close)) return;
   Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,
                        (ulong)(long)position.ticket_number);
   Print("closing candle confirmation");
}
#endif
