// HEAD of native evaluator 0x20ef0..0x211ea.
// Only time/empty-symbol selection and the MQLInfoInteger(7) branch are here.
#ifndef BOT3_EVALUATION_HEAD_MQH
#define BOT3_EVALUATION_HEAD_MQH

enum Bot3EvaluationHeadResult
{
   BOT3_HEAD_NEXT_211EA = 0,
   BOT3_HEAD_NEXT_216E5 = 1
};

struct Bot3EvaluationHeadInputs
{
   string symbol;
   string native_1d6e28;
   uchar native_1d6d08;
};

struct Bot3EvaluationHeadState
{
   uint strategy_index;
   uchar caller_flag;
   datetime server_time;
   MqlDateTime calendar;
   string selected_symbol;
};

Bot3EvaluationHeadResult Bot3BeginEvaluation(const uint index,const uchar caller_flag,
                                             const Bot3EvaluationHeadInputs &inputs,
                                             Bot3EvaluationHeadState &state)
{
   state.strategy_index=index;
   state.caller_flag=caller_flag;
   state.server_time=TimeTradeServer();
   TimeToStruct(state.server_time,state.calendar);

   // Preserve the empty-string comparison; do not add a generic NULL fallback.
   if(inputs.symbol=="") state.selected_symbol=inputs.native_1d6e28;
   else state.selected_symbol=inputs.symbol;

   if(inputs.native_1d6d08==0 && MQLInfoInteger((ENUM_MQL_INFO_INTEGER)7)==0)
      return BOT3_HEAD_NEXT_216E5;
   return BOT3_HEAD_NEXT_211EA;
}

#endif
