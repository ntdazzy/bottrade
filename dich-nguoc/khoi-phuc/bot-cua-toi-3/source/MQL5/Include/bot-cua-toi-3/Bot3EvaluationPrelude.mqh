// Evaluator prelude after the time/symbol head through the SymbolInfoTick and TimeCurrent calls.
#ifndef BOT3_EVALUATION_PRELUDE_MQH
#define BOT3_EVALUATION_PRELUDE_MQH
#include "Bot3EvaluationHead.mqh"

struct Bot3EvaluationPreludeState
{
   Bot3EvaluationHeadState head;
   uchar session_flag;
   MqlTick tick;
   double spread;
   MqlDateTime current_calendar;
};

void Bot3ReportSessions(const string symbol)
{
   Print("[SESSIONS] trade sessions reported for ",symbol,":");
   for(uint day=0;day<7;day++)
   {
      string line="   day "+IntegerToString((long)day,0,32)+":";
      datetime from=0,to=0;
      uint session=0;
      while(true)
      {
         if(!SymbolInfoSessionTrade(symbol,(ENUM_DAY_OF_WEEK)day,session,from,to))
         {
            if(session==0) line+=" none";
            break;
         }
         line+=" ["+TimeToString(from,TIME_MINUTES)+"-"+TimeToString(to,TIME_MINUTES)+"]";
         if(session==9) break;
         session++;
      }
      Print(line);
   }
}

uchar Bot3CheckSession(const string symbol,const MqlDateTime &calendar,
                       const datetime server_time)
{
   if(calendar.day_of_week==0 || calendar.day_of_week==6) return 1;

   datetime from=0,to=0;
   if(!SymbolInfoSessionTrade(symbol,(ENUM_DAY_OF_WEEK)calendar.day_of_week,0,from,to))
      return 0;

   const long now=(long)server_time%86400;
   uint session=0;
   while(true)
   {
      const long begin=(long)from%86400;
      bool inside=false;
      // The original tests the `to` value against 86401 and preserves an
      // unsigned adjustment for the unusual boundary values.
      if((long)to<86401)
      {
         long adjusted=(long)to;
         if((ulong)(to-86340)<(ulong)0xfffffffffffeaebd)
            adjusted=86400;
         if(adjusted>=begin)
            inside=(begin<=now && now<=adjusted);
         else
            inside=(now>=begin || now<=(long)to);
      }
      else
      {
         const long normalized_to=(long)((ulong)to%86400);
         inside=(now>=begin || now<=normalized_to);
      }
      if(inside) return 0;
      if(session==9) return 1;
      session++;
      if(!SymbolInfoSessionTrade(symbol,(ENUM_DAY_OF_WEEK)calendar.day_of_week,session,from,to))
         return 1;
   }
}

void Bot3PrepareEvaluation(const uint strategy_index,const uchar caller_flag,
                           Bot3EvaluationHeadInputs &inputs,
                           Bot3EvaluationPreludeState &state)
{
   const Bot3EvaluationHeadResult route=Bot3BeginEvaluation(strategy_index,caller_flag,inputs,state.head);
   if(route==BOT3_HEAD_NEXT_216E5)
   {
      inputs.native_1d6d08=1;
      Bot3ReportSessions(state.head.selected_symbol);
   }
   state.session_flag=Bot3CheckSession(state.head.selected_symbol,state.head.calendar,state.head.server_time);
   state.head.selected_symbol=NULL;
   if(!SymbolInfoTick(inputs.symbol,state.tick))
      Print("Tick not ok");
   state.spread=state.tick.ask-state.tick.bid;
   TimeCurrent(state.current_calendar);
}

#endif
