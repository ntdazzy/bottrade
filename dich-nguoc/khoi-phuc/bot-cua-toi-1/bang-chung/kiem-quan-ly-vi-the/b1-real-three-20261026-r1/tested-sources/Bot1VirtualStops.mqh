// Native 0x18790/0x3d200/0x3d5a0/0x3d640. Verification is pending.
#ifndef BOT1_VIRTUAL_STOPS_MQH
#define BOT1_VIRTUAL_STOPS_MQH
#include "Bot1PriceLevels.mqh"
#define BOT1_VIRTUAL_STOP_ROWS 500

struct Bot1VirtualStopState
{
   double rows[BOT1_VIRTUAL_STOP_ROWS][3];
   uchar guard;
   long reported_ticket;
};

void Bot1DropClosedVirtualStops(Bot1VirtualStopState &state,long &open_tickets[])
{
   if(ArraySize(open_tickets)<64) ArrayResize(open_tickets,64,0);
   int total=PositionsTotal();
   int count=0;
   for(int index=0;index<total;index++)
   {
      ulong ticket=PositionGetTicket(index);
      if(ticket==0) continue;
      if((ulong)PositionGetInteger(POSITION_TYPE)>=2) continue;
      if(ArraySize(open_tickets)<=count) ArrayResize(open_tickets,count+64,0);
      open_tickets[count]=(long)ticket;
      count++;
   }
   if(state.guard!=1) return;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
   {
      if(!(0.0<state.rows[row][0])) continue;
      bool found=false;
      for(int index=0;index<count;index++)
      {
         if(open_tickets[index]==(long)state.rows[row][0]) { found=true;break; }
      }
      if(found) continue;
      state.rows[row][2]=0.0;
      state.rows[row][1]=0.0;
      state.rows[row][0]=0.0;
   }
}

double Bot1VirtualStopLevel(Bot1VirtualStopState &state,long &open_tickets[],
                            const string &symbol,const double &unit,const int side,
                            const double price,const double distance,const long ticket)
{
   if(state.guard==1)
      for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
         if(state.rows[row][0]==(double)ticket) return state.rows[row][1];

   double level=0.0;
   if(side==2)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      level=Bot1RoundPrice(distance*unit+price,digits);
   }
   else if(side==1)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      level=Bot1RoundPrice(price-distance*unit,digits);
   }
   if(state.guard==1)
      for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
      {
         if(state.rows[row][0]!=0.0) continue;
         state.rows[row][0]=(double)ticket;
         state.rows[row][1]=level;
         state.rows[row][2]=0.0;
         return level;
      }
   Bot1DropClosedVirtualStops(state,open_tickets);
   if(state.guard==1)
      for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
      {
         if(state.rows[row][0]!=0.0) continue;
         state.rows[row][0]=(double)ticket;
         state.rows[row][1]=level;
         state.rows[row][2]=0.0;
         return level;
      }
   if(state.reported_ticket!=ticket)
   {
      state.reported_ticket=ticket;
      int positions=PositionsTotal();
      int slots=state.guard==0 ? 0 : BOT1_VIRTUAL_STOP_ROWS;
      Print("Virtual SL table full (",slots," slots, ",positions,
            " open positions) - ticket ",ticket," will not trail.");
   }
   return level;
}

bool Bot1VirtualStopDelayPassed(const Bot1VirtualStopState &state,
                               const int &delay_seconds,const long ticket)
{
   if(delay_seconds<=0 || state.guard!=1) return false;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
   {
      if(state.rows[row][0]!=(double)ticket) continue;
      long stamp=(long)state.rows[row][2];
      if(stamp==0) return true;
      long now=(long)TimeCurrent();
      long delay=(long)delay_seconds;
      long elapsed=now-stamp;
      return delay<=elapsed;
   }
   return false;
}

void Bot1VirtualStopStamp(Bot1VirtualStopState &state,const long ticket)
{
   if(state.guard!=1) return;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
   {
      if(state.rows[row][0]!=(double)ticket) continue;
      long now=(long)TimeCurrent();
      state.rows[row][2]=(double)now;
      return;
   }
}
#endif
