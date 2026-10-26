// Bot 1 management router: the caller's licence flag gate, then bar-change or per-tick
// management of buy and sell positions through Bot1ManagePositions.
#ifndef BOT1_MANAGEMENT_ROUTER_MQH
#define BOT1_MANAGEMENT_ROUTER_MQH
#include "Bot1PositionManagement.mqh"

// Counts the open positions of one direction whose magic and symbol match the settings.
// last_ticket keeps the last ticket read; no other state changes.
int Bot1CountManagementPositions(const bool buy,const string &symbol,
                                 const int &magic,ulong &last_ticket)
{
   string position_symbol;
   int count=0;
   int total=PositionsTotal();
   if(total<1) return 0;
   int index=0;
   do
   {
      last_ticket=PositionGetTicket(index);
      // A zero ticket skips the other reads of this position.
      if(last_ticket!=0)
      {
         // The 64-bit magic is compared with the sign-extended setting read after the call.
         const long position_magic=PositionGetInteger(POSITION_MAGIC);
         if(position_magic==(long)magic)
         {
            // Buy reads the type before the symbol; sell reads the symbol before the type.
            if(buy)
            {
               if(PositionGetInteger(POSITION_TYPE)==0)
               {
                  position_symbol=PositionGetString(POSITION_SYMBOL);
                  if(position_symbol==symbol) count++;
               }
            }
            else
            {
               position_symbol=PositionGetString(POSITION_SYMBOL);
               if(position_symbol==symbol && PositionGetInteger(POSITION_TYPE)==1) count++;
            }
         }
      }
      index++;
      // Read again after each position, including skipped ones.
      total=PositionsTotal();
   }
   while(index<total);
   return count;
}

// strategy_index is the caller's 0..7 snapshot and picks the slot in the 8-entry last_times;
// shared.strategy_index is not used for it. Returns true when the licence flag is 0 or a
// manager returned true, so the caller stops the rest of its pass; false lets it continue.
// bar_first_zero_ticket_changed has no default and is passed to both bar-change managers.
bool Bot1RoutePositionManagement(const uchar &license_valid,
                                 const uchar &tick_management,const uchar &bar_override,
                                 const int &timeframe,const uint strategy_index,
                                 long &last_times[],
                                 const Bot1PositionManagementSettings &settings,
                                 Bot1PositionManagementState &shared,
                                 const double &buy_levels[],const double &sell_levels[],
                                 Bot1PendingRequestState &requests,
                                 Bot1TradeSendOptions &options,const ulong &deviation,
                                 const bool bar_first_zero_ticket_changed)
{
   // The flag is owned by the caller and only read here.
   if(license_valid==0)
   {
      Print("Licence not valid!");
      return true;
   }
   // Evaluated left to right with early stop: PositionsTotal is called only when both flags
   // allow the per-tick branch.
   if(tick_management==0 || bar_override!=0 || PositionsTotal()<1)
   {
      const ENUM_TIMEFRAMES frame=(ENUM_TIMEFRAMES)timeframe;
      const long previous=last_times[strategy_index];
      const long observed=(long)iTime(settings.symbol,frame,1);
      if(observed==previous) return false;
      // symbol and timeframe are read again; the stored time comes from this second call.
      const long current=(long)iTime(settings.symbol,(ENUM_TIMEFRAMES)timeframe,1);
      last_times[strategy_index]=current;
      // Sell always runs after buy, even when buy returned true, with the state buy left behind.
      // Both receive the bar_first_zero_ticket_changed value of this router call.
      const bool buy_changed=Bot1ManagePositions(true,settings,shared,buy_levels,requests,options,
                                                 deviation,bar_first_zero_ticket_changed);
      const bool sell_changed=Bot1ManagePositions(false,settings,shared,sell_levels,requests,
                                                  options,deviation,bar_first_zero_ticket_changed);
      return buy_changed || sell_changed;
   }

   // Each count reads PositionsTotal itself. The sell count runs even when buy management
   // returned true and sees the positions and state buy management left behind.
   // Both per-tick managers take true for a zero ticket at index 0.
   const int buy_count=Bot1CountManagementPositions(true,settings.symbol,settings.magic,
                                                    shared.last_ticket);
   bool buy_changed=false;
   if(buy_count>0)
      buy_changed=Bot1ManagePositions(true,settings,shared,buy_levels,requests,options,
                                      deviation,true);
   const int sell_count=Bot1CountManagementPositions(false,settings.symbol,settings.magic,
                                                     shared.last_ticket);
   bool sell_changed=false;
   if(sell_count>0)
      sell_changed=Bot1ManagePositions(false,settings,shared,sell_levels,requests,options,
                                       deviation,true);
   return buy_changed || sell_changed;
}
#endif
