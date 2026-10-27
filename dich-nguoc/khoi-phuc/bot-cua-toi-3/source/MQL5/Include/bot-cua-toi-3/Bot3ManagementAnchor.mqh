// Scoped original segments: buy 0x33b73..0x33d76; sell 0x38194..0x3839c.
// These segments alone are not the complete position managers.
#ifndef BOT3_MANAGEMENT_ANCHOR_MQH
#define BOT3_MANAGEMENT_ANCHOR_MQH
#include "Bot3PriceLevels.mqh"

struct Bot3ManagementAnchorState
{
   double rows[100][2];
   double step_reference;
   long ticket;
   double level;
   bool gap_passed;
   double reference;
};

void Bot3PrepareManagementAnchorFields(Bot3ManagementAnchorState &state,
                                 const string &symbol,const double &unit,
                                 const double &step_setting,const double &limit,
                                 const uchar &use_anchor,const bool buy,
                                 const double ticket_number,const double opened,double &rows[][2],double &step_reference)
{
   step_reference=step_setting;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   state.ticket=(long)ticket_number;
   double key=(double)state.ticket;
   double level=0.0;
   for(int row=0;row<100;row++)
      if(rows[row][0]==key) { level=rows[row][1];break; }
   level=Bot3RoundPrice(level,digits);
   if(level!=0.0)
   {
      double adjustment=unit*(-0.0);
      level=level+adjustment;
   }
   else
   {
      level=opened;
      for(int row=0;row<100;row++)
      {
         if(rows[row][0]!=0.0) continue;
         rows[row][0]=key;
         rows[row][1]=opened;
         break;
      }
   }
   state.level=level;
   state.gap_passed=false;
   double threshold=buy ? 0.0-unit*0.0 : unit*0.0+0.0;
   if(threshold<level)
   {
      double difference=buy ? opened-level : level-opened;
      state.gap_passed=limit*unit<difference;
   }
   state.reference=opened;
   if(use_anchor!=0) state.reference=level;
}

void Bot3PrepareManagementAnchor(Bot3ManagementAnchorState &state,
                                 const string &symbol,const double &unit,
                                 const double &step_setting,const double &limit,
                                 const uchar &use_anchor,const bool buy,
                                 const double ticket_number,const double opened)
{
   Bot3PrepareManagementAnchorFields(state,symbol,unit,step_setting,limit,use_anchor,buy,ticket_number,opened,
                                      state.rows,state.step_reference);
}
#endif
