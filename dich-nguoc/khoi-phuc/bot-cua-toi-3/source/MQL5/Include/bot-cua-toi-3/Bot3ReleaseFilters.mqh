// Interest/CPI evaluator branches share live calendar controls and trade context.
#ifndef BOT3_RELEASE_FILTERS_MQH
#define BOT3_RELEASE_FILTERS_MQH
#include "Bot3NfpFilter.mqh"
#include "Bot3ReleaseCalendars.mqh"
struct Bot3ReleaseFilterSettings
{
   uchar enabled,delete_pending,close_positions;
   int before_minutes,after_minutes;
};
struct Bot3ReleaseFilterState { uchar notice,blocked;long last_query; };
void Bot3ReleaseFilterActions(const bool interest,const Bot3ReleaseFilterSettings &settings,
                              Bot3ReleaseFilterState &state,Bot3NfpExecution &execution)
{
   if(settings.delete_pending!=0)
   {
      Bot3CancelDistantPending(1,true,execution.strategy_magic,execution.symbol,execution.tick.ask,
                               execution.gap,execution.last_ticket,execution.trade,execution.options);
      Bot3CancelDistantPending(1,false,execution.strategy_magic,execution.symbol,execution.tick.bid,
                               execution.gap,execution.last_ticket,execution.trade,execution.options);
   }
   if(settings.close_positions!=0)
   {
      Bot3CloseFilteredBuyPositions(execution.magic_base,execution.symbol,execution.last_ticket,execution.trade,
                                    execution.options,execution.deviation,execution.tick.bid,execution.tick.ask,
                                    execution.threshold_a,execution.gap);
      Bot3CloseFilteredSellPositions(execution.magic_base,execution.symbol,execution.last_ticket,execution.trade,
                                     execution.options,execution.deviation,execution.tick.bid,execution.tick.ask,
                                     execution.threshold_a,execution.gap);
   }
   if(state.blocked==0) Print(interest ? "Interest Rate decision!! deleting trades!!" : "CPI!! deleting trades!!");
   state.blocked=1;
}
void Bot3ProcessReleaseFilter(const bool interest,const uchar &use_calendar,const uchar &throttle,
                              const long &utc_reference,const Bot3ReleaseFilterSettings &settings,
                              Bot3ReleaseFilterState &state,long &event_time,const long &history[],
                              Bot3NfpExecution &execution)
{
   if(settings.enabled==0) return;
   if(use_calendar!=0 && MQLInfoInteger(MQL_TESTER)!=1)
   {
      const long server=(long)TimeTradeServer();
      if(server>state.last_query+(throttle!=0 ? 900 : 0))
      {
         event_time=interest ? Bot3FindInterestRateTime() : Bot3FindCpiTime();
         state.last_query=(long)TimeTradeServer();
      }
      if(event_time>0 && (state.notice&1)!=0)
      {
         state.notice=0;
         const string date=TimeToString((datetime)event_time,3);
         const string prefix=interest ? "Interest Rate filter: MQL5 Economic Calendar is available again, next release "
                                      : "CPI filter: MQL5 Economic Calendar is available again, next release ";
         Print(prefix+date);
      }
      if(event_time>0)
      {
         uchar blocked=0;
         const long current=(long)TimeCurrent();
         if(current>=event_time-Bot3NewsMinutes32(settings.before_minutes))
         {
            const long second=(long)TimeCurrent();
            if(second<=event_time+Bot3NewsMinutes32(settings.after_minutes))
            {
               Bot3ReleaseFilterActions(interest,settings,state,execution);
               blocked=1;
            }
         }
         state.blocked=blocked;
         return;
      }
      if(state.notice==0)
      {
         state.notice=1;
         if(interest) Print("Interest Rate filter: the MQL5 Economic Calendar returned no release - using the EA's built-in dates instead. Protection is still active. If this persists, open Toolbox -> Calendar in the terminal so it can sync.");
         else Print("CPI filter: the MQL5 Economic Calendar returned no release - using the EA's built-in dates instead. Protection is still active. If this persists, open Toolbox -> Calendar in the terminal so it can sync.");
      }
   }
   if(Bot3NfpYear()>2026) return;
   const long offset=Bot3AmericanDST() ? 0 : 3600;
   for(int i=0;i<300;i++)
   {
      MqlDateTime calendar;
      TimeToStruct((datetime)history[i],calendar);
      const int year=calendar.year;
      if(year!=Bot3NfpYear()) continue;
      TimeToStruct((datetime)history[i],calendar);
      const int month=calendar.mon;
      if(month!=Bot3NfpMonth()) continue;
      const long selected=history[i];
      if(selected<=0) break;
      const long server=(long)TimeTradeServer();
      const long shifted=selected+offset;
      event_time=(server+shifted)-utc_reference;
      if(utc_reference<shifted-Bot3NewsMinutes32(settings.before_minutes) ||
         utc_reference>shifted+Bot3NewsMinutes32(settings.after_minutes)) state.blocked=0;
      else Bot3ReleaseFilterActions(interest,settings,state,execution);
      return;
   }
   state.blocked=0;
}
#endif
