// Final virtual blocks only; runtime comparison is required before use in an EA.
#ifndef BOT3_MANAGEMENT_VIRTUAL_FINISH_MQH
#define BOT3_MANAGEMENT_VIRTUAL_FINISH_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3VirtualStops.mqh"

struct Bot3VirtualFinishSettings
{
   int high_low_enabled;
   uchar high_low_before_open;
   uchar high_low_shift;
   double high_low_buy_shift;
   double high_low_sell_shift;
   double lock_start;
   double lock_extra;
   int mode;
   uchar step_enabled;
   double step_reference;
   int min_steps;
   double step_distance;
};

void Bot3AdvanceVirtualHighLowFields(const bool buy,const string &symbol,
                               const Bot3VirtualFinishSettings &settings,const double &unit,
                               const double &gap,const double &freeze,
                               const Bot3ManagedPosition &position,MqlTick &tick,
                               const double &levels[],const uint &strategy_index,
                               double &current_level,bool &changed,
                               const int &high_low_enabled)
{
   if(high_low_enabled<=0) return;
   double level=current_level;
   double first=levels[strategy_index];
   double limit=buy ? level+gap : level-gap;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(buy ? limit+point<first : first<limit-point)) return;
   double second=levels[strategy_index];
   if(!(buy ? second<position.open_price : position.open_price<second)
      && (settings.high_low_before_open&1)!=0) return;
   double shift=settings.high_low_shift==0 ? 0.0
                : (buy ? settings.high_low_buy_shift : settings.high_low_sell_shift);
   double offset=shift*unit;
   double quote=buy ? tick.bid : tick.ask;
   limit=buy ? (quote-offset)-gap : (offset+quote)+gap;
   point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(buy ? second<limit-point : limit+point<second)) return;
   if(!(buy ? tick.bid<(position.tp-freeze) : (freeze+position.tp)<tick.ask)) return;
   changed=true;
   current_level=levels[strategy_index];
}

void Bot3AdvanceVirtualHighLow(const bool buy,const string &symbol,
                               const Bot3VirtualFinishSettings &settings,const double &unit,
                               const double &gap,const double &freeze,
                               const Bot3ManagedPosition &position,MqlTick &tick,
                               const double &levels[],const uint &strategy_index,
                               double &current_level,bool &changed)
{
   Bot3AdvanceVirtualHighLowFields(buy,symbol,settings,unit,gap,freeze,position,tick,
                                   levels,strategy_index,current_level,changed,
                                   settings.high_low_enabled);
}

void Bot3AdvanceVirtualBreakEvenCounterFields(const bool buy,const string &symbol,
                                        const Bot3VirtualFinishSettings &settings,const double &unit,
                                        const double &gap,const double &freeze,const double selected_anchor,
                                        const double &copied_step,const Bot3ManagedPosition &position,
                                        MqlTick &tick,double &current_level,bool &changed,int &counter,
                                        const double &step_reference)
{
   double open_price=position.open_price;
   double tp=position.tp;
   double start=settings.lock_start;
   if(0.0<start && settings.mode==2)
   {
      double u=unit;
      double quote=buy ? tick.bid : tick.ask;
      double activation=start*u;
      double trigger=buy ? activation+open_price : open_price-activation;
      if(buy ? trigger<quote : quote<trigger)
      {
         double offset=u*settings.lock_extra;
         double candidate=buy ? offset+open_price : open_price-offset;
         double old=current_level;
         double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
         if(buy ? old+point<candidate : candidate<old-point)
         {
            // lock_extra, tick and unit are read again after the API call.
            double extra=settings.lock_extra;
            quote=buy ? tick.bid : tick.ask;
            offset=extra*unit;
            candidate=buy ? open_price+offset : open_price-offset;
            if(buy ? (gap+candidate<quote && quote<tp-freeze)
                   : (quote<candidate-gap && freeze+tp<quote))
            {
               current_level=candidate;
               changed=true;
            }
         }
      }
   }
   // A true flag (this lock or an earlier block) skips the counter. Below it the flag is false,
   // so the native clears at 0x36b08/0x36f82 and 0x3acf0/0x3b175 leave it unchanged.
   if(changed) return;
   double quote=buy ? tick.bid : tick.ask;
   double old=current_level;
   if(settings.step_enabled!=1) return;
   uint wrapped=(uint)counter; // int32 increment wraps like native inc eax
   wrapped++;
   int steps=(int)wrapped;
   counter=steps;
   double u=unit;
   double step=settings.step_distance*u;
   double next=buy ? step+old : old-step;
   if(!(buy ? gap+next<quote : quote<next-gap)) return;
   if(!(buy ? quote<tp-freeze : freeze+tp<quote)) return;
   // +0 and -0 skip the anchor test; any other value, NaN included, requires it on both sides.
   if(step_reference!=0.0)
   {
      double distance=u*copied_step;
      if(!(buy ? selected_anchor+distance<quote : quote<selected_anchor-distance)) return;
   }
   if(steps<settings.min_steps) return;
   counter=0;
   current_level=next;
   changed=true;
}

void Bot3AdvanceVirtualBreakEvenCounter(const bool buy,const string &symbol,
                                        const Bot3VirtualFinishSettings &settings,const double &unit,
                                        const double &gap,const double &freeze,const double selected_anchor,
                                        const double &copied_step,const Bot3ManagedPosition &position,
                                        MqlTick &tick,double &current_level,bool &changed,int &counter)
{
   Bot3AdvanceVirtualBreakEvenCounterFields(buy,symbol,settings,unit,gap,freeze,selected_anchor,
                                            copied_step,position,tick,current_level,changed,counter,
                                            settings.step_reference);
}

// Buy 0x36b19..0x36f5f, sell 0x3ad01..0x3b14f; do not create new rows.
void Bot3StoreVirtualLevels(const string &symbol,const double initial_stop,
                            const double initial_take,const double &current_level,
                            const double &current_take,const double cached_ticket_number,
                            Bot3VirtualStopState &table)
{
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double previous=Bot3RoundPrice(initial_stop,digits);
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double current=Bot3RoundPrice(current_level,digits);
   if(previous!=current)
   {
      digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      current=Bot3RoundPrice(current_level,digits);
      if(table.guard==1)
         for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
            if(table.rows[row][0]==cached_ticket_number) { table.rows[row][1]=current;break; }
   }
   if(!(0.0<current_take)) return;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   previous=Bot3RoundPrice(initial_take,digits);
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   current=Bot3RoundPrice(current_take,digits);
   if(previous==current) return;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   current=Bot3RoundPrice(current_take,digits);
   if(table.guard==1)
      for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
         if(table.take_rows[row][0]==cached_ticket_number) { table.take_rows[row][1]=current;break; }
}
#endif
