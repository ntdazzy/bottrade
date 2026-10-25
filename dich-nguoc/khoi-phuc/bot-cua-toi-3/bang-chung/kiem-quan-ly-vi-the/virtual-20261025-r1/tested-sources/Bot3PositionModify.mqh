// Native 0x32a90: stop check, ticket selection, full reset, then SLTP send/messages.
#ifndef BOT3_POSITION_MODIFY_MQH
#define BOT3_POSITION_MODIFY_MQH
#include "Bot3TradeSend.mqh"
bool Bot3ModifyPosition(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                        const ulong ticket,const double sl,const double tp)
{
   if(IsStopped())
   {
      PrintFormat("%s: MQL5 program is stopped. Trading is disabled","CTrade::PositionModify");
      state.result.retcode=10027;
      return false;
   }
   if(!PositionSelectByTicket(ticket)) return false;
   ZeroMemory(state.request);
   ZeroMemory(state.result);
   ZeroMemory(state.check);
   state.request.action=TRADE_ACTION_SLTP;
   state.request.position=ticket;
   state.request.symbol=PositionGetString(POSITION_SYMBOL);
   state.request.magic=state.magic;
   state.request.sl=sl;
   state.request.tp=tp;
   return Bot3SendTrade(options,state.request,state.result);
}
#endif
