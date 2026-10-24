// Native 0x3ce40/0x3d220. Preserve inclusive indices and repeated identity reads.
#ifndef BOT3_POSITION_SELECTION_MQH
#define BOT3_POSITION_SELECTION_MQH
#include <bot-cua-toi-3/Bot3PositionClose.mqh>
void Bot3CloseFilteredPositions(const bool buy,const int &magic_base,const string &symbol,
                                ulong &last_ticket,Bot3PendingRequestState &state,
                                Bot3TradeSendOptions &options,const ulong &deviation,
                                const double &reference_a,const double &reference_b,
                                const double &threshold_a,const double &threshold_b)
{
   string position_symbol;
   int total=PositionsTotal();
   if(total<0) return;
   int seed=magic_base;
   long accepted[15];
   for(int i=0;i<15;i++)
   {
      uint low=(uint)seed+(uint)(i+1);
      accepted[i]=(long)(int)low;
   }
   for(int index=total;index>=0;index--)
   {
      last_ticket=PositionGetTicket(index);
      if(last_ticket==0) continue;
      bool matches=false;
      for(int i=0;i<15;i++)
      {
         if(PositionGetInteger(POSITION_MAGIC)==accepted[i]) { matches=true;break; }
      }
      if(!matches) continue;
      position_symbol=PositionGetString(POSITION_SYMBOL);
      if(position_symbol!=symbol) continue;
      if(PositionGetInteger(POSITION_TYPE)!=(buy ? (long)POSITION_TYPE_BUY : (long)POSITION_TYPE_SELL)) continue;
      PositionGetDouble(POSITION_VOLUME);
      Bot3TryClosePosition(state,options,deviation,reference_a,reference_b,threshold_a,threshold_b,last_ticket);
      for(int i=0;i<15;i++) { uint low=(uint)magic_base+(uint)(i+1);accepted[i]=(long)(int)low; }
   }
}
void Bot3CloseFilteredBuyPositions(const int &magic_base,const string &symbol,ulong &last_ticket,
                                   Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                   const ulong &deviation,const double &reference_a,const double &reference_b,
                                   const double &threshold_a,const double &threshold_b)
{
   Bot3CloseFilteredPositions(true,magic_base,symbol,last_ticket,state,options,deviation,reference_a,reference_b,threshold_a,threshold_b);
}
void Bot3CloseFilteredSellPositions(const int &magic_base,const string &symbol,ulong &last_ticket,
                                    Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                    const ulong &deviation,const double &reference_a,const double &reference_b,
                                    const double &threshold_a,const double &threshold_b)
{
   Bot3CloseFilteredPositions(false,magic_base,symbol,last_ticket,state,options,deviation,reference_a,reference_b,threshold_a,threshold_b);
}
#endif
