// Native 0x20bc0/0x47f10/0x482b0/0x484c0/0x48560. Component verification only.
#ifndef BOT3_VIRTUAL_STOPS_MQH
#define BOT3_VIRTUAL_STOPS_MQH
#include "Bot3PriceLevels.mqh"
#define BOT3_VIRTUAL_STOP_ROWS 500

struct Bot3VirtualStopState
{
   double rows[BOT3_VIRTUAL_STOP_ROWS][3];
   double take_rows[BOT3_VIRTUAL_STOP_ROWS][2];
   uchar guard;
   long reported_ticket;
   long reported_take_ticket;
};

void Bot3DropClosedVirtualStops(Bot3VirtualStopState &state,long &open_tickets[])
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
   for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
   {
      if(0.0<state.rows[row][0])
      {
         bool found=false;
         for(int index=0;index<count;index++)
            if(open_tickets[index]==(long)state.rows[row][0]) { found=true;break; }
         if(!found)
         {
            state.rows[row][2]=0.0;
            state.rows[row][1]=0.0;
            state.rows[row][0]=0.0;
         }
      }
      if(0.0<state.take_rows[row][0])
      {
         bool found=false;
         for(int index=0;index<count;index++)
            if(open_tickets[index]==(long)state.take_rows[row][0]) { found=true;break; }
         if(!found)
         {
            state.take_rows[row][0]=0.0;
            state.take_rows[row][1]=0.0;
         }
      }
   }
}

// Native 0x47f10.
double Bot3VirtualStopLevel(Bot3VirtualStopState &state,long &open_tickets[],
                            const string &symbol,const double &unit,const int side,
                            const double price,const double distance,const long ticket)
{
   if(state.guard==1)
      for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
         if(state.rows[row][0]==(double)ticket) return state.rows[row][1];

   double level=0.0;
   if(side==2)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      level=Bot3RoundPrice(distance*unit+price,digits);
   }
   else if(side==1)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      level=Bot3RoundPrice(price-distance*unit,digits);
   }
   if(state.guard==1)
      for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
      {
         if(state.rows[row][0]!=0.0) continue;
         state.rows[row][0]=(double)ticket;
         state.rows[row][1]=level;
         state.rows[row][2]=0.0;
         return level;
      }
   Bot3DropClosedVirtualStops(state,open_tickets);
   if(state.guard==1)
      for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
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
      int slots=state.guard==0 ? 0 : BOT3_VIRTUAL_STOP_ROWS;
      Print("Virtual SL table full (",slots," slots, ",positions,
            " open positions) - ticket ",ticket," will not trail.");
   }
   return level;
}

// Native 0x482b0. Ordered <= keeps NaN on the storage path.
double Bot3VirtualTakeLevel(Bot3VirtualStopState &state,long &open_tickets[],
                            const double level,const long ticket)
{
   if(state.guard==1)
      for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
         if(state.take_rows[row][0]==(double)ticket) return state.take_rows[row][1];
   if(level<=0.0) return 0.0;
   if(state.guard==1)
      for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
      {
         if(state.take_rows[row][0]!=0.0) continue;
         state.take_rows[row][0]=(double)ticket;
         state.take_rows[row][1]=level;
         return level;
      }
   Bot3DropClosedVirtualStops(state,open_tickets);
   if(state.guard==1)
      for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
      {
         if(state.take_rows[row][0]!=0.0) continue;
         state.take_rows[row][0]=(double)ticket;
         state.take_rows[row][1]=level;
         return level;
      }
   if(state.reported_take_ticket!=ticket)
   {
      state.reported_take_ticket=ticket;
      int positions=PositionsTotal();
      int slots=state.guard==0 ? 0 : BOT3_VIRTUAL_STOP_ROWS;
      Print("Virtual TP table full (",slots," slots, ",positions,
            " open positions) - ticket ",ticket," will not trail.");
   }
   return level;
}

// Native 0x484c0/0x48560. Not compiled; verification is pending.
bool Bot3VirtualStopDelayPassed(const Bot3VirtualStopState &state,
                                const int &delay_seconds,const long ticket)
{
   if(delay_seconds<=0 || state.guard!=1) return false;
   for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
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

void Bot3VirtualStopStamp(Bot3VirtualStopState &state,const long ticket)
{
   if(state.guard!=1) return;
   for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
   {
      if(state.rows[row][0]!=(double)ticket) continue;
      long now=(long)TimeCurrent();
      state.rows[row][2]=(double)now;
      return;
   }
}

#endif
