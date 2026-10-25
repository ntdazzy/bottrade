// Final virtual trailing blocks; not the complete management functions.
#ifndef BOT1_MANAGEMENT_VIRTUAL_FINISH_MQH
#define BOT1_MANAGEMENT_VIRTUAL_FINISH_MQH
#include "Bot1ManagementPrelude.mqh"

struct Bot1VirtualFinishSettings
{
   int high_low_enabled;       // 0x624e4
   uchar high_low_before_open; // low bit, 0x624d8
   uchar high_low_shift;       // 0x624ec
   double high_low_buy_shift;  // 0x50248, captured 10.0
   double high_low_sell_shift; // 0x50270, captured 10.0
   double lock_start;          // 0x624c8
   double lock_extra;          // 0x624d0
   int mode;                   // 0x6241c
   uchar step_enabled;         // 0x62508, exactly 1
   double step_reference;      // 0x62510, both signed zeros accepted
   int min_steps;              // 0x62518
   double step_distance;       // 0x62520
};

void Bot1AdvanceVirtualHighLow(const bool buy,const string &symbol,
                               const Bot1VirtualFinishSettings &settings,
                               const double &unit,const double &gap,const double &freeze,
                               const Bot1ManagedPosition &position,MqlTick &tick,
                               const double &levels[],const uint &strategy_index,
                               double &current_level,bool &changed)
{
   if(settings.high_low_enabled<=0) return;
   double price=current_level;
   double level=levels[strategy_index];
   double limit=buy ? price+gap : price-gap;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(buy ? limit+point<level : level<limit-point)) return;
   level=levels[strategy_index];
   if(!(buy ? level<position.open_price : position.open_price<level) &&
      (settings.high_low_before_open&1)!=0) return;
   double k=settings.high_low_shift==0 ? 0.0 :
            (buy ? settings.high_low_buy_shift : settings.high_low_sell_shift);
   double offset=k*unit;
   double quote=buy ? tick.bid : tick.ask;
   limit=buy ? (quote-offset)-gap : (offset+quote)+gap;
   point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(buy ? level<limit-point : limit+point<level)) return;
   if(!(buy ? tick.bid<position.tp-freeze : freeze+position.tp<tick.ask)) return;
   changed=true;
   current_level=levels[strategy_index];
}

void Bot1AdvanceVirtualBreakEvenCounter(const bool buy,const string &symbol,
                                         const Bot1VirtualFinishSettings &settings,
                                         const double &unit,const double &gap,const double &freeze,
                                         const double selected_anchor,const double cached_reference,
                                         const double &copied_step,const Bot1ManagedPosition &position,
                                         MqlTick &tick,double &current_level,bool &changed,int &counter)
{
   if(0.0<settings.lock_start && settings.mode==2)
   {
      double u=unit;
      double activation=settings.lock_start*u;
      double quote=buy ? tick.bid : tick.ask;
      double trigger=buy ? activation+position.open_price : position.open_price-activation;
      if(buy ? trigger<quote : quote<trigger)
      {
         double offset=u*settings.lock_extra;
         double candidate=buy ? offset+position.open_price : position.open_price-offset;
         double old=current_level;
         double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
         if(buy ? old+point<candidate : candidate<old-point)
         {
            double extra=settings.lock_extra;
            quote=buy ? tick.bid : tick.ask;
            offset=extra*unit;
            candidate=buy ? position.open_price+offset : position.open_price-offset;
            if((buy ? gap+candidate<quote : quote<candidate-gap) &&
               (buy ? quote<position.tp-freeze : freeze+position.tp<quote))
            {
               current_level=candidate;
               changed=true;
            }
         }
      }
   }
   if(changed) return;
   double quote=buy ? tick.bid : tick.ask;
   double old=current_level;
   if(settings.step_enabled!=1) return;
   double u=unit;
   double step=settings.step_distance*u;
   counter++;
   double candidate=buy ? step+old : old-step;
   if(!(buy ? gap+candidate<quote : quote<candidate-gap)) return;
   if(!(buy ? quote<position.tp-freeze : position.tp+freeze<quote)) return;
   if(settings.step_reference!=0.0)
   {
      double distance=u*copied_step;
      if(!(buy ? selected_anchor+distance<quote : quote<cached_reference-distance)) return;
   }
   if(counter<settings.min_steps) return;
   counter=0;
   current_level=candidate;
   changed=true;
}

void Bot1StoreVirtualStop(const string &symbol,const double initial_level,
                          const double &current_level,const double ticket_number,
                          Bot1VirtualStopState &table)
{
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double initial=Bot1RoundPrice(initial_level,digits);
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double current=Bot1RoundPrice(current_level,digits);
   if(initial==current) return;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   current=Bot1RoundPrice(current_level,digits);
   if(table.guard!=1) return;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
      if(table.rows[row][0]==ticket_number)
      {
         table.rows[row][1]=current;
         return;
      }
}
// The virtual-table path exits directly to aggregate/next-position, without a mode recheck.
bool Bot1FinishVirtualManagement(const bool buy,const string &symbol,
                                 const Bot1VirtualFinishSettings &settings,
                                 const double &unit,const double &gap,const double &freeze,
                                 const double selected_anchor,const double cached_reference,
                                 const double &copied_step,const Bot1ManagedPosition &position,
                                 MqlTick &tick,const double &levels[],const uint &strategy_index,
                                 double &current_level,bool &changed,int &counter,
                                 const double initial_level,const long ticket,Bot1VirtualStopState &table,
                                 Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                 const ulong &deviation)
{
   Bot1AdvanceVirtualHighLow(buy,symbol,settings,unit,gap,freeze,position,tick,
                             levels,strategy_index,current_level,changed);
   Bot1AdvanceVirtualBreakEvenCounter(buy,symbol,settings,unit,gap,freeze,
                                       selected_anchor,cached_reference,copied_step,
                                       position,tick,current_level,changed,counter);
   if(buy ? current_level>=tick.bid : tick.ask>=current_level)
   {
      SymbolInfoTick(symbol,tick);
      Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket);
      return true;
   }
   Bot1StoreVirtualStop(symbol,initial_level,current_level,(double)ticket,table);
   return false;
}
#endif
