// Verified scope must be read from management-prelude evidence, not this comment.
// Components of native 0x271f0/0x2abc0; these are not complete management functions.
#ifndef BOT1_MANAGEMENT_PRELUDE_MQH
#define BOT1_MANAGEMENT_PRELUDE_MQH
#include "Bot1PriceLevels.mqh"
#include "Bot1PositionModify.mqh"
#include "Bot1PositionClose.mqh"
#include "Bot1VirtualStops.mqh"

struct Bot1ManagedPosition
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

bool Bot1ReadManagementPosition(const int index,const bool buy,
                               const int &magic,const int &enabled,const string &symbol,
                               ulong &last_ticket,MqlTick &tick,Bot1ManagedPosition &position)
{
   last_ticket=PositionGetTicket(index);
   if(last_ticket==0) return false;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   position.sl=Bot1RoundPrice(PositionGetDouble(POSITION_SL),digits);
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   position.tp=Bot1RoundPrice(PositionGetDouble(POSITION_TP),digits);
   position.ticket_number=(double)(long)last_ticket;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   position.open_price=Bot1RoundPrice(PositionGetDouble(POSITION_PRICE_OPEN),digits);
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

void Bot1FillManagementInitialLevels(const bool buy,const string &symbol,
                                    const double &unit,const double &stop_distance,
                                    const double &take_distance,Bot1ManagedPosition &position,
                                    Bot1PendingRequestState &state,Bot1TradeSendOptions &options)
{
   if(position.sl==0.0)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      double price=buy ? position.open_price-stop_distance*unit
                       : stop_distance*unit+position.open_price;
      position.sl=Bot1RoundPrice(price,digits);
      Bot1ModifyPosition(state,options,(ulong)(long)position.ticket_number,position.sl,position.tp);
   }
   if(position.tp==0.0)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      double price=buy ? take_distance*unit+position.open_price
                       : position.open_price-take_distance*unit;
      position.tp=Bot1RoundPrice(price,digits);
      Bot1ModifyPosition(state,options,(ulong)(long)position.ticket_number,position.sl,position.tp);
   }
}

ENUM_TIMEFRAMES Bot1ManagementCandleTimeframe(const uchar &setting,const bool alternate)
{
   return (ENUM_TIMEFRAMES)(alternate ? (setting==0 ? 0 : 30) : (int)setting);
}

void Bot1CloseManagementCandle(const bool buy,const string &symbol,
                              const uchar &enabled,const uchar &timeframe,const bool alternate,
                              const Bot1ManagedPosition &position,
                              Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                              const ulong &deviation,const MqlTick &tick,
                              const double &threshold_a,const double &threshold_b)
{
   if(enabled!=1) return;
   long previous=(long)iTime(symbol,Bot1ManagementCandleTimeframe(timeframe,alternate),1);
   if(previous>position.opened) return;
   long current=(long)iTime(symbol,Bot1ManagementCandleTimeframe(timeframe,alternate),0);
   if(position.opened>=current) return;
   double close=iClose(symbol,Bot1ManagementCandleTimeframe(timeframe,alternate),1);
   double open=iOpen(symbol,Bot1ManagementCandleTimeframe(timeframe,alternate),1);
   if(!(buy ? close<open : open<close)) return;
   close=iClose(symbol,Bot1ManagementCandleTimeframe(timeframe,alternate),1);
   if(!(buy ? close<position.open_price : position.open_price<close)) return;
   Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,
                        (ulong)(long)position.ticket_number);
   Print("closing candle confirmation");
}

double Bot1ManagementCachedReference(const bool buy,const string &symbol,
                                     const double &ticket_number,const double &open_price,
                                     const double &unit,const double &step,
                                     const double &threshold,const uchar &use_cached,
                                     double &copied_step,double &cache[][2],
                                     bool &distance_passed,double &anchor)
{
   copied_step=step;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double ticket=(double)(long)ticket_number;
   double level=0.0;
   for(int row=0;row<100;row++)
      if(cache[row][0]==ticket) { level=cache[row][1];break; }
   level=Bot1RoundPrice(level,digits);
   if(level!=0.0) level=level+unit*(-0.0);
   else
   {
      for(int row=0;row<100;row++)
      {
         if(cache[row][0]!=0.0) continue;
         cache[row][0]=ticket;
         cache[row][1]=open_price;
         break;
      }
      level=open_price;
   }
   if(buy) distance_passed=(0.0-unit*0.0<level && threshold*unit<open_price-level);
   else distance_passed=(unit*0.0+0.0<level && threshold*unit<level-open_price);
   anchor=use_cached==0 ? open_price : level;
   return level;
}

bool Bot1StartVirtualManagement(const bool buy,const string &symbol,const double &unit,
                                const double &stop_distance,const int &delay_seconds,
                                Bot1ManagedPosition &position,MqlTick &tick,
                                Bot1VirtualStopState &table,long &open_tickets[],
                                double &initial_level,double &current_level,
                                Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                const ulong &deviation,const double &threshold_a,
                                const double &threshold_b)
{
   long ticket=(long)position.ticket_number;
   initial_level=Bot1VirtualStopLevel(table,open_tickets,symbol,unit,buy ? 1 : 2,
                                     position.open_price,stop_distance,ticket);
   current_level=initial_level;
   if(buy ? tick.bid<=initial_level : initial_level<=tick.ask)
   {
      SymbolInfoTick(symbol,tick);
      Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,
                           (ulong)ticket);
      return true;
   }
   if(Bot1VirtualStopDelayPassed(table,delay_seconds,ticket))
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      double candidate=Bot1RoundPrice(current_level,digits);
      double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
      if(buy ? position.sl+point<candidate : candidate<position.sl-point)
      {
         digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
         position.sl=Bot1RoundPrice(current_level,digits);
         Bot1ModifyPosition(state,options,(ulong)ticket,position.sl,position.tp);
         Bot1VirtualStopStamp(table,ticket);
      }
   }
   return false;
}

void Bot1AdvanceTimedVirtualStop(const bool buy,const string &symbol,const double &unit,
                                 const double &activation,const double &distance,
                                 const int &delay_seconds,const double &freeze_distance,
                                 const Bot1ManagedPosition &position,MqlTick &tick,
                                 double &current_level,bool &changed)
{
   if(!(0.0<activation)) return;
   long now=(long)TimeCurrent();
   if(now<position.opened+(long)delay_seconds) return;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double offset=distance*unit;
   if(buy)
   {
      if(!(level+point+offset<quote)) return;
      if(!(tick.bid<position.tp-freeze_distance)) return;
      changed=true;current_level=tick.bid-offset;
   }
   else
   {
      if(!(quote<(level-point)-offset)) return;
      if(!(freeze_distance+position.tp<tick.ask)) return;
      changed=true;current_level=offset+tick.ask;
   }
}

bool Bot1AdvanceDistanceVirtualStop(const bool buy,const string &symbol,const double &unit,
                                    const double &trail_distance,const double &trail_step,
                                    const double &trail_start,const double &trail_limit,
                                    const double anchor,const Bot1ManagedPosition &position,
                                    MqlTick &tick,const double &volumes[],const uint &strategy_index,
                                    double &current_level,bool &changed,
                                    Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                    const ulong &deviation,const double &threshold_a,
                                    const double &threshold_b)
{
   if(!(0.0<trail_distance)) return false;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double distance=(trail_step+trail_distance)*unit;
   if(buy)
   {
      if(!(level+point+distance<quote)) return false;
      if(!(trail_start*unit+anchor<tick.bid)) return false;
      if(!(current_level<trail_limit*unit+position.open_price)) return false;
      current_level=tick.bid-trail_distance*unit;
   }
   else
   {
      if(!(quote<(level-point)-distance)) return false;
      if(!(tick.ask<anchor-trail_start*unit)) return false;
      if(!(position.open_price-trail_limit*unit<current_level)) return false;
      current_level=trail_distance*unit+tick.ask;
   }
   double volume=Bot1RoundPrice(volumes[strategy_index]*0.0,2);
   changed=true;
   if(volume<position.volume)
   {
      double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
      if(minimum<=volume)
      {
         Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,
                              (ulong)(long)position.ticket_number);
         return true;
      }
   }
   return false;
}

void Bot1AdvanceSlippageVirtualStop(const bool buy,const string &symbol,const double &unit,
                                    const int &enabled,const bool distance_passed,
                                    const double reference,const double &trail_distance,
                                    const double &start_distance,const double &limit_distance,
                                    const double &freeze_distance,const Bot1ManagedPosition &position,
                                    MqlTick &tick,double &current_level,bool &changed)
{
   if(enabled!=1 || !distance_passed || !(0.0<trail_distance)) return;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(buy)
   {
      if(!(level+point+trail_distance*unit<quote)) return;
      if(!(reference+start_distance*unit<tick.bid)) return;
      if(!(tick.bid<position.tp-freeze_distance)) return;
      if(!(current_level<unit*limit_distance+position.open_price)) return;
      Print("Slippage control active");
      changed=true;current_level=tick.bid-trail_distance*unit;
   }
   else
   {
      if(!(quote<(level-point)-trail_distance*unit)) return;
      if(!(tick.ask<reference-start_distance*unit)) return;
      if(!(freeze_distance+position.tp<tick.ask)) return;
      if(!(position.open_price-unit*limit_distance<current_level)) return;
      Print("Slippage controle active");
      changed=true;current_level=trail_distance*unit+tick.ask;
   }
}
#endif
