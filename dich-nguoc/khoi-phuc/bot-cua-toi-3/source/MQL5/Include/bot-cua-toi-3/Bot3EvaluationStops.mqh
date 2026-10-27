// Initial SL/TP pass in the evaluator, before the later management loop.
#ifndef BOT3_EVALUATION_STOPS_MQH
#define BOT3_EVALUATION_STOPS_MQH
#include "Bot3PriceLevels.mqh"
#include "Bot3PositionModify.mqh"

struct Bot3EvaluationStopInputs
{
   uchar enabled;
   int magic;
   double stop_distance;
   double target_distance;
   double unit;
};

// Keep SUBSD NaN signs; a folded negation-plus-add changes the right operand.
double Bot3EvaluationDifference(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left-right;
}

int Bot3FillEvaluationStopsFields(const string &symbol,const uchar &enabled,const int &magic,
                                  const double &stop_distance,const double &target_distance,
                                  const double &unit,Bot3PendingRequestState &trade,
                                  Bot3TradeSendOptions &options)
{
   if(enabled==0) return 0;
   const int total=PositionsTotal();
   for(int index=total-1;index>=0;index--)
   {
      const ulong ticket=PositionGetTicket(index);
      if(ticket==0) continue;
      if(PositionGetInteger(POSITION_MAGIC)!=(long)magic) continue;
      if(PositionGetString(POSITION_SYMBOL)!=symbol) continue;
      double sl=PositionGetDouble(POSITION_SL);
      double tp=PositionGetDouble(POSITION_TP);
      if(sl!=0.0 && tp!=0.0) continue;
      const double open=PositionGetDouble(POSITION_PRICE_OPEN);
      const long type=PositionGetInteger(POSITION_TYPE);
      const uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      if(type!=POSITION_TYPE_BUY && type!=POSITION_TYPE_SELL) continue;
      if(sl==0.0)
      {
         if(type==POSITION_TYPE_BUY)
            sl=Bot3RoundPrice(Bot3EvaluationDifference(open,(stop_distance+0.0)*unit),digits);
         else
            sl=Bot3RoundPrice((stop_distance+0.0)*unit+open,digits);
      }
      if(tp==0.0 && target_distance>0.0)
      {
         if(type==POSITION_TYPE_BUY)
            tp=Bot3RoundPrice(open+target_distance*unit,digits);
         else
            tp=Bot3RoundPrice(Bot3EvaluationDifference(open,target_distance*unit),digits);
      }
      Bot3ModifyPosition(trade,options,ticket,sl,tp);
   }
   return total;
}

void Bot3FillEvaluationStops(const string &symbol,const Bot3EvaluationStopInputs &inputs,
                             Bot3PendingRequestState &trade,Bot3TradeSendOptions &options)
{
   Bot3FillEvaluationStopsFields(symbol,inputs.enabled,inputs.magic,inputs.stop_distance,
                                 inputs.target_distance,inputs.unit,trade,options);
}

#endif
