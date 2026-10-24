// Native 0x22c40/0x3d010. Reference names remain neutral until callers are traced.
#ifndef BOT1_POSITION_CLOSE_MQH
#define BOT1_POSITION_CLOSE_MQH
#include "Bot1TradeSend.mqh"
void Bot1ClosePosition(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                       const ulong &deviation,const ulong ticket)
{
   if(IsStopped())
   {
      PrintFormat("%s: MQL5 program is stopped. Trading is disabled","CTrade::PositionClose");
      state.result.retcode=10027;
      return;
   }
   if(!PositionSelectByTicket(ticket)) return;
   string symbol=PositionGetString(POSITION_SYMBOL);
   ZeroMemory(state.request);
   ZeroMemory(state.result);
   ZeroMemory(state.check);
   if(!Bot1CheckFilling(symbol,state.request,state.result,state.preferred)) return;
   bool buy=(uint)PositionGetInteger(POSITION_TYPE)==0;
   state.request.type=buy ? ORDER_TYPE_SELL : ORDER_TYPE_BUY;
   state.request.price=SymbolInfoDouble(symbol,buy ? SYMBOL_BID : SYMBOL_ASK);
   state.request.action=TRADE_ACTION_DEAL;
   state.request.position=ticket;
   state.request.symbol=symbol;
   state.request.volume=PositionGetDouble(POSITION_VOLUME);
   state.request.magic=state.magic;
   state.request.deviation=deviation;
   Bot1SendTrade(options,state.request,state.result);
}
void Bot1TryClosePosition(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                          const ulong &deviation,const double &reference_a,const double &reference_b,
                          const double &threshold_a,const double &threshold_b,const ulong ticket)
{
   if(!PositionSelectByTicket(ticket)) return;
   state.magic=(ulong)PositionGetInteger(POSITION_MAGIC);
   if(PositionGetInteger(POSITION_TYPE)==(long)POSITION_TYPE_BUY)
   {
      double reference=reference_a;
      double sl=PositionGetDouble(POSITION_SL);
      if(MathAbs(reference-sl)>threshold_a)
      {
         reference=reference_a;
         sl=PositionGetDouble(POSITION_SL);
         if(MathAbs(reference-sl)>threshold_b) Bot1ClosePosition(state,options,deviation,ticket);
      }
   }
   if(PositionGetInteger(POSITION_TYPE)==(long)POSITION_TYPE_SELL)
   {
      double reference=reference_b;
      double sl=PositionGetDouble(POSITION_SL);
      if(MathAbs(reference-sl)>threshold_a)
      {
         reference=reference_a;
         sl=PositionGetDouble(POSITION_SL);
         if(MathAbs(reference-sl)>threshold_b) Bot1ClosePosition(state,options,deviation,ticket);
      }
   }
}
#endif
