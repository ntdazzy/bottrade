#ifndef BOT3_STRATEGY_PRESENCE_MQH
#define BOT3_STRATEGY_PRESENCE_MQH

// Native dispatcher 0x1a68e..0x1a7c3. Retained flags require sixteen cells.
void Bot3CollectStrategyPresence(const int &base_magic,uchar &retained_flags[])
{
   for(int i=8;i<16;i++) retained_flags[i]=0;
   for(int i=0;i<8;i++) retained_flags[i]=0;
   const int positions=PositionsTotal();
   if((int)((uint)positions-(uint)1)>=0)
   {
      const long seed=(long)base_magic;
      int index=positions;
      do
      {
         index=(int)((uint)index-(uint)1);
         if(PositionGetTicket(index)!=0)
         {
            const long magic=PositionGetInteger((ENUM_POSITION_PROPERTY_INTEGER)12);
            const ulong offset=(ulong)magic-(ulong)seed;
            if(offset-(ulong)1<=(ulong)14) retained_flags[(int)offset]=1;
         }
      } while(index>0);
   }
   const int orders=OrdersTotal();
   if((int)((uint)orders-(uint)1)>=0)
   {
      const long seed=(long)base_magic;
      int index=orders;
      do
      {
         index=(int)((uint)index-(uint)1);
         if(OrderGetTicket(index)!=0)
         {
            const long magic=OrderGetInteger((ENUM_ORDER_PROPERTY_INTEGER)15);
            const ulong offset=(ulong)magic-(ulong)seed;
            if(offset-(ulong)1<=(ulong)14) retained_flags[(int)offset]=1;
         }
      } while(index>0);
   }
}

#endif
