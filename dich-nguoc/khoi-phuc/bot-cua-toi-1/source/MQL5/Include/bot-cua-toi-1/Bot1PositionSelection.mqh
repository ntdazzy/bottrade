// Native 0x2fa00/0x2fce0. Preserve inclusive indices and repeated identity reads.
#ifndef BOT1_POSITION_SELECTION_MQH
#define BOT1_POSITION_SELECTION_MQH
#include "Bot1PositionClose.mqh"
void Bot1CloseFilteredPositions(const bool buy,const int &magic_base,const string &symbol,
                                ulong &last_ticket,Bot1PendingRequestState &state,
                                Bot1TradeSendOptions &options,const ulong &deviation,
                                const double &reference_a,const double &reference_b,
                                const double &threshold_a,const double &threshold_b)
{
   string position_symbol;
   int total=PositionsTotal();
   if(total<0) return;
   int seed=magic_base;
   long accepted[8];
   for(int i=0;i<8;i++)
   {
      uint low=(uint)seed+(uint)(i+1);
      accepted[i]=(long)(int)low;
   }
   for(int index=total;index>=0;index--)
   {
      last_ticket=PositionGetTicket(index);
      if(last_ticket==0) continue;
      bool matches=false;
      for(int i=0;i<8;i++)
      {
         if(PositionGetInteger(POSITION_MAGIC)==accepted[i]) { matches=true;break; }
      }
      if(!matches) continue;
      position_symbol=PositionGetString(POSITION_SYMBOL);
      if(position_symbol!=symbol) continue;
      if(PositionGetInteger(POSITION_TYPE)!=(buy ? (long)POSITION_TYPE_BUY : (long)POSITION_TYPE_SELL)) continue;
      PositionGetDouble(POSITION_VOLUME);
      Bot1TryClosePosition(state,options,deviation,reference_a,reference_b,threshold_a,threshold_b,last_ticket);
   }
}
void Bot1CloseFilteredBuyPositions(const int &magic_base,const string &symbol,ulong &last_ticket,
                                   Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                   const ulong &deviation,const double &reference_a,const double &reference_b,
                                   const double &threshold_a,const double &threshold_b)
{
   Bot1CloseFilteredPositions(true,magic_base,symbol,last_ticket,state,options,deviation,reference_a,reference_b,threshold_a,threshold_b);
}
void Bot1CloseFilteredSellPositions(const int &magic_base,const string &symbol,ulong &last_ticket,
                                    Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                    const ulong &deviation,const double &reference_a,const double &reference_b,
                                    const double &threshold_a,const double &threshold_b)
{
   Bot1CloseFilteredPositions(false,magic_base,symbol,last_ticket,state,options,deviation,reference_a,reference_b,threshold_a,threshold_b);
}
#endif
