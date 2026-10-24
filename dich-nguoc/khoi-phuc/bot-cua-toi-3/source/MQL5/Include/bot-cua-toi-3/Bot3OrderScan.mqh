// Reconstructed from native 0x3e490,0x47330; OrdersTotal is intentional.
#ifndef BOT3_ORDER_SCAN_MQH
#define BOT3_ORDER_SCAN_MQH
void Bot3CleanPendingResults(double &results[][2],ulong &last_ticket)
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
bool Bot3AllowsPendingOrder()
{
   int limit=(int)AccountInfoInteger(ACCOUNT_LIMIT_ORDERS);
   if(limit==0) return true;
   return OrdersTotal()<limit;
}
#endif
