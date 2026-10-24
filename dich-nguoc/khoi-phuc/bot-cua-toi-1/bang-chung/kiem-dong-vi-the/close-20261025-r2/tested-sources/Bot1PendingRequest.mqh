// Native 0x32dd0 up to the send boundary 0x3363d; this function never sends.
#ifndef BOT1_PENDING_REQUEST_MQH
#define BOT1_PENDING_REQUEST_MQH
#include "Bot1Filling.mqh"
struct Bot1PendingRequestState
{
   MqlTradeRequest request;
   MqlTradeResult result;
   MqlTradeCheckResult check;
   ulong magic;
   ENUM_ORDER_TYPE_FILLING preferred;
};
bool Bot1PreparePendingRequest(Bot1PendingRequestState &state,const int strategy_magic,
                              const uchar virtual_expiration,const string symbol,
                              const ENUM_ORDER_TYPE type,const double volume,const double price,
                              const double sl,const double tp,const string comment,const datetime expiration)
{
   state.magic=(ulong)(long)strategy_magic;
   if(IsStopped())
   {
      PrintFormat("%s: MQL5 program is stopped. Trading is disabled","CTrade::OrderOpen");
      state.result.retcode=10027;
      return false;
   }
   ZeroMemory(state.request);
   ZeroMemory(state.result);
   ZeroMemory(state.check);
   if(!Bot1CheckFilling(symbol,state.request,state.result,state.preferred)) return false;
   ENUM_ORDER_TYPE_TIME time_mode=virtual_expiration==0 ? ORDER_TIME_SPECIFIED : ORDER_TIME_GTC;
   if(virtual_expiration!=0 && expiration==0)
   {
      ulong flags=(ulong)SymbolInfoInteger(symbol,SYMBOL_EXPIRATION_MODE);
      if((flags&1)==0)
      {
         time_mode=ORDER_TIME_DAY;
         if((flags&2)==0)
         {
            Print("CTrade::OrderOpen",": Error: Unable to place order without explicitly specified expiration time");
            state.result.retcode=10022;
            state.result.comment="Invalid expiration type";
            return false;
         }
      }
   }
   state.request.action=TRADE_ACTION_PENDING;
   state.request.symbol=symbol;
   state.request.magic=state.magic;
   state.request.type=type;
   state.request.volume=volume;
   state.request.price=price;
   state.request.stoplimit=price;
   state.request.sl=sl;
   state.request.tp=tp;
   state.request.type_time=time_mode;
   state.request.expiration=expiration;
   string name=(symbol==NULL) ? _Symbol : symbol;
   long value=0;
   uint flags=0;
   if(SymbolInfoInteger(name,SYMBOL_ORDER_MODE,value)) flags=(uint)value;
   bool allowed=false;
   switch(type)
   {
      case ORDER_TYPE_BUY: case ORDER_TYPE_SELL: allowed=(flags&1)!=0;break;
      case ORDER_TYPE_BUY_LIMIT: case ORDER_TYPE_SELL_LIMIT: allowed=(flags&2)!=0;break;
      case ORDER_TYPE_BUY_STOP: case ORDER_TYPE_SELL_STOP: allowed=(flags&4)!=0;break;
      case ORDER_TYPE_BUY_STOP_LIMIT: case ORDER_TYPE_SELL_STOP_LIMIT: allowed=(flags&8)!=0;break;
   }
   if(!allowed)
   {
      state.result.retcode=10035;
      Print("CTrade::OrderTypeCheck: Invalid order type");
      return false;
   }
   if(state.request.sl!=0.0 || state.request.tp!=0.0)
   {
      if((flags&16)==0) state.request.sl=0.0;
      if((flags&32)==0) state.request.tp=0.0;
   }
   if(!Bot1CheckFilling(symbol,state.request,state.result,state.preferred))
   {
      state.result.retcode=10030;
      Print("CTrade::OrderOpen: Invalid filling type");
      return false;
   }
   if(!Bot1ExpirationAllowed(symbol,state.request.type_time))
   {
      state.result.retcode=10022;
      Print("CTrade::OrderOpen: Invalid expiration type");
      return false;
   }
   state.request.comment=comment;
   return true;
}
#endif
