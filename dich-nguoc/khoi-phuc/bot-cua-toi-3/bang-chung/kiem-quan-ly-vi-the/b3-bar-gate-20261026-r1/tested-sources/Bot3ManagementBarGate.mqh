// Bot 3 bar gate in front of the position manager: buy and sell management run only when the
// time of bar 1 differs from the time stored for the strategy slot.
#ifndef BOT3_MANAGEMENT_BAR_GATE_MQH
#define BOT3_MANAGEMENT_BAR_GATE_MQH
#include "Bot3PositionManagement.mqh"

// strategy_index is the caller's 0..8 snapshot and picks the slot in the 9-entry last_times;
// shared.strategy_index is not used for it. Returns false when the bar time is unchanged,
// otherwise whether buy or sell management returned true.
bool Bot3ManageOnBarChange(const string &symbol,const int &timeframe,const uint strategy_index,
                           long &last_times[],const Bot3PositionManagementSettings &settings,
                           Bot3PositionManagementState &shared,const double &buy_levels[],
                           const double &sell_levels[],Bot3PendingRequestState &requests,
                           Bot3TradeSendOptions &options,const ulong &deviation)
{
   const ENUM_TIMEFRAMES frame=(ENUM_TIMEFRAMES)timeframe;
   const long previous=last_times[strategy_index];
   const long observed=(long)iTime(symbol,frame,1);
   if(previous==observed) return false;
   // timeframe is read again; the stored time comes from this second call, not from observed.
   const long current=(long)iTime(symbol,(ENUM_TIMEFRAMES)timeframe,1);
   last_times[strategy_index]=current;
   // Sell always runs after buy, even when buy returned true, with the state buy left behind.
   const bool buy_changed=Bot3ManagePositions(true,settings,shared,buy_levels,requests,options,
                                              deviation);
   const bool sell_changed=Bot3ManagePositions(false,settings,shared,sell_levels,requests,options,
                                               deviation);
   return buy_changed || sell_changed;
}
#endif
