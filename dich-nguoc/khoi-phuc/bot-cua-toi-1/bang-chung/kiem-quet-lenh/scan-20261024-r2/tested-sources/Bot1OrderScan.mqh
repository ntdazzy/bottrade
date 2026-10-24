// Reconstructed from native 0x31f40,0x323e0,0x32ce0; preserve total..0.
#ifndef BOT1_ORDER_SCAN_MQH
#define BOT1_ORDER_SCAN_MQH
int Bot1CountPendingKind(const int &strategy_magic,const string &symbol,
                         ulong &last_ticket,const ENUM_ORDER_TYPE kind)
{
   string order_symbol;
   int count=0;
   for(int index=OrdersTotal();index>=0;index--)
   {
      last_ticket=OrderGetTicket(index);
      if(last_ticket==0) continue;
      long order_magic=OrderGetInteger(ORDER_MAGIC);
      if(order_magic!=(long)strategy_magic) continue;
      order_symbol=OrderGetString(ORDER_SYMBOL);
      if(order_symbol!=symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)==(long)kind) count++;
   }
   return count;
}
int Bot1CountBuyPending(const int &strategy_magic,const string &symbol,ulong &last_ticket)
{
   return Bot1CountPendingKind(strategy_magic,symbol,last_ticket,ORDER_TYPE_BUY_STOP);
}
int Bot1CountSellPending(const int &strategy_magic,const string &symbol,ulong &last_ticket)
{
   return Bot1CountPendingKind(strategy_magic,symbol,last_ticket,ORDER_TYPE_SELL_STOP);
}
void Bot1CleanPendingResults(double &results[][2],ulong &last_ticket)
{
   for(int row=0;row<100;row++)
   {
      long recorded=(long)results[row][0];
      bool found=false;
      for(int index=OrdersTotal();index>=0;index--)
      {
         last_ticket=PositionGetTicket(index);
         if(last_ticket!=0 && last_ticket==(ulong)recorded) found=true;
      }
      if(!found) { results[row][0]=0.0;results[row][1]=0.0; }
   }
}
#endif
