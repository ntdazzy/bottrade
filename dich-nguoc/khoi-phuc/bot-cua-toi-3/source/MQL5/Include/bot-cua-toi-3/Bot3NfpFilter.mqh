// Full evaluator NFP branch. Live fields stay shared across calendar and trade calls.
#ifndef BOT3_NFP_FILTER_MQH
#define BOT3_NFP_FILTER_MQH
#include "Bot3NfpCalendar.mqh"
#include "Bot3AmericanDST.mqh"
#include "Bot3NewsSelector.mqh"
#include "Bot3PendingDistanceCancel.mqh"
#include "Bot3PositionSelection.mqh"
struct Bot3NfpFilterSettings
{
   uchar enabled,use_calendar,throttle,delete_pending,close_positions;
   int before_minutes,after_minutes;
};
struct Bot3NfpFilterState
{
   uchar initialization_notice,notice,blocked;
   long last_query,utc_reference;
};
struct Bot3NfpExecution
{
   int strategy_magic,magic_base;
   string symbol;
   double reference_a,reference_b,threshold_a,gap;
   ulong last_ticket,deviation;
   Bot3PendingRequestState trade;
   Bot3TradeSendOptions options;
};
int Bot3NfpYear()
{
   MqlDateTime calendar;
   TimeCurrent(calendar);
   return calendar.year;
}
int Bot3NfpMonth()
{
   MqlDateTime calendar;
   TimeCurrent(calendar);
   return calendar.mon;
}
void Bot3NfpFilterActions(const Bot3NfpFilterSettings &settings,Bot3NfpFilterState &state,
                          Bot3NfpExecution &execution)
{
   if(settings.delete_pending!=0)
   {
      Bot3CancelDistantPending(1,true,execution.strategy_magic,execution.symbol,
                               execution.reference_b,execution.gap,execution.last_ticket,execution.trade,execution.options);
      Bot3CancelDistantPending(1,false,execution.strategy_magic,execution.symbol,
                               execution.reference_a,execution.gap,execution.last_ticket,execution.trade,execution.options);
   }
   if(settings.close_positions!=0)
   {
      Bot3CloseFilteredBuyPositions(execution.magic_base,execution.symbol,execution.last_ticket,execution.trade,
                                    execution.options,execution.deviation,execution.reference_a,execution.reference_b,
                                    execution.threshold_a,execution.gap);
      Bot3CloseFilteredSellPositions(execution.magic_base,execution.symbol,execution.last_ticket,execution.trade,
                                     execution.options,execution.deviation,execution.reference_a,execution.reference_b,
                                     execution.threshold_a,execution.gap);
   }
   if(state.blocked==0) Print("NFP!! deleting trades!!");
   state.blocked=1;
}
void Bot3ProcessNfpFilter(const Bot3NfpFilterSettings &settings,Bot3NfpFilterState &state,
                          Bot3NewsEvents &events,const MqlDateTime &cached_calendar,const long &history[],
                          Bot3NfpExecution &execution)
{
   state.initialization_notice=0;
   if(settings.enabled==0) return;
   if(settings.use_calendar!=0)
   {
      if(MQLInfoInteger(MQL_TESTER)!=1)
      {
         const long server=(long)TimeTradeServer();
         if(server>state.last_query+(settings.throttle!=0 ? 900 : 0))
         {
            events.nfp=Bot3FindNfpTime();
            state.last_query=(long)TimeTradeServer();
         }
         if(events.nfp>0 && (state.notice&1)!=0)
         {
            state.notice=0;
            const string date=TimeToString((datetime)events.nfp,3);
            Print("NFP filter: MQL5 Economic Calendar is available again, next release "+date);
         }
         uchar next_blocked=0;
         const long current=(long)TimeCurrent();
         if(current>=events.nfp-Bot3NewsMinutes32(settings.before_minutes))
         {
            const long second=(long)TimeCurrent();
            if(second<=events.nfp+Bot3NewsMinutes32(settings.after_minutes))
            {
               Bot3NfpFilterActions(settings,state,execution);
               next_blocked=1;
            }
         }
         state.blocked=next_blocked;
      }
      if(MQLInfoInteger(MQL_TESTER)!=1 && events.nfp!=0) return;
      if(MQLInfoInteger(MQL_TESTER)!=1 && state.notice==0)
      {
         state.notice=1;
         Print("NFP filter: the MQL5 Economic Calendar returned no release - using the EA's built-in dates instead. Protection is still active. If this persists, open Toolbox -> Calendar in the terminal so it can sync.");
      }
   }
   const long offset=Bot3AmericanDST() ? 0 : 3600;
   if(Bot3NfpYear()<=2026)
   {
      long selected=0;
      for(int i=0;i<300;i++)
      {
         MqlDateTime calendar;
         TimeToStruct((datetime)history[i],calendar);
         const int year=calendar.year;
         if(year!=Bot3NfpYear()) continue;
         TimeToStruct((datetime)history[i],calendar);
         const int month=calendar.mon;
         if(month!=Bot3NfpMonth()) continue;
         selected=history[i];
         const long server=(long)TimeTradeServer();
         events.nfp=((server+offset)+selected)-state.utc_reference;
         break;
      }
      const long shifted=selected+offset;
      if(state.utc_reference<shifted-Bot3NewsMinutes32(settings.before_minutes) ||
         state.utc_reference>shifted+Bot3NewsMinutes32(settings.after_minutes)) state.blocked=0;
      else Bot3NfpFilterActions(settings,state,execution);
      return;
   }
   if(cached_calendar.day>7 || cached_calendar.day_of_week!=5) return;
   const string year=IntegerToString((long)Bot3NfpYear(),0,' ');
   const string month=IntegerToString((long)Bot3NfpMonth(),0,' ');
   MqlDateTime calendar;
   TimeCurrent(calendar);
   const string day=IntegerToString((long)calendar.day,0,' ');
   const string date=year+month+day+" "+IntegerToString(1230,0,' ');
   const long time=(long)StringToTime(date);
   if(state.utc_reference<time-Bot3NewsMinutes32(settings.before_minutes) ||
      state.utc_reference>time+Bot3NewsMinutes32(settings.after_minutes)) state.blocked=0;
   else Bot3NfpFilterActions(settings,state,execution);
}
#endif
