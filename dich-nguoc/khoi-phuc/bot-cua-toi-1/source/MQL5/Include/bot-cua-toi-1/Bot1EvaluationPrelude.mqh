// Bot 1 evaluator prelude through the tick and current-time calls.
#ifndef BOT1_EVALUATION_PRELUDE_MQH
#define BOT1_EVALUATION_PRELUDE_MQH

struct Bot1EvaluationPreludeInputs
{
   string symbol;
   string native_6a428;
   uchar native_6a3b4;
};
struct Bot1EvaluationPreludeState
{
   uint strategy_index;
   datetime server_time;
   MqlDateTime calendar;
   string selected_symbol;
   uchar session_flag;
   MqlTick tick;
   double spread;
   MqlDateTime current_calendar;
};

void Bot1ReportSessions(const string symbol)
{
   Print("[SESSIONS] trade sessions reported for ",symbol,":");
   for(uint day=0;day<7;day++)
   {
      string line="   day "+IntegerToString((long)day,0,32)+":";
      datetime from=0,to=0;uint session=0;
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

uchar Bot1CheckSession(const string symbol,const MqlDateTime &calendar,const datetime server_time)
{
   if(calendar.day_of_week==0 || calendar.day_of_week==6) return 1;
   datetime from=0,to=0;
   if(!SymbolInfoSessionTrade(symbol,(ENUM_DAY_OF_WEEK)calendar.day_of_week,0,from,to)) return 0;
   const long now=(long)server_time%86400;uint session=0;
   while(true)
   {
      const long begin=(long)from%86400;bool inside=false;
      if((long)to<86401)
      {
         long adjusted=(long)to;
         if((ulong)(to-86340)<(ulong)0xfffffffffffeaebd) adjusted=86400;
         if(adjusted>=begin) inside=(begin<=now && now<=adjusted);
         else inside=(now>=begin || now<=(long)to);
      }
      else
      {
         const long normalized_to=(long)((ulong)to%86400);
         inside=(now>=begin || now<=normalized_to);
      }
      if(inside) return 0;
      if(session==9) return 1;
      session++;
      if(!SymbolInfoSessionTrade(symbol,(ENUM_DAY_OF_WEEK)calendar.day_of_week,session,from,to)) return 1;
   }
}

void Bot1PrepareEvaluationFields(const uint strategy_index,Bot1EvaluationPreludeInputs &inputs,
                                  Bot1EvaluationPreludeState &state,const string &symbol,
                                  MqlTick &tick,double &spread,
                                  MqlDateTime &current_calendar,bool &reported_sessions)
{
   reported_sessions=false;
   state.strategy_index=strategy_index;
   state.server_time=TimeTradeServer();
   TimeToStruct(state.server_time,state.calendar);
   if(symbol=="") state.selected_symbol=inputs.native_6a428;
   else state.selected_symbol=symbol;
   if(inputs.native_6a3b4==0 && MQLInfoInteger((ENUM_MQL_INFO_INTEGER)7)==0)
   {
      inputs.native_6a3b4=1;
      Bot1ReportSessions(state.selected_symbol);
      reported_sessions=true;
   }
   state.session_flag=Bot1CheckSession(state.selected_symbol,state.calendar,state.server_time);
   state.selected_symbol=NULL;
   if(!SymbolInfoTick(symbol,tick)) Print("Tick not ok");
   spread=tick.ask-tick.bid;
   TimeCurrent(current_calendar);
}

void Bot1PrepareEvaluation(const uint strategy_index,Bot1EvaluationPreludeInputs &inputs,
                           Bot1EvaluationPreludeState &state)
{
   bool reported_sessions=false;
   Bot1PrepareEvaluationFields(strategy_index,inputs,state,inputs.symbol,state.tick,
                                state.spread,state.current_calendar,reported_sessions);
}

#endif
