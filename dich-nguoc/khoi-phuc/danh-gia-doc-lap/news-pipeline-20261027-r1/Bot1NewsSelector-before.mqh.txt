// Native full news selector 7310..74f8: timestamp, label, ordered live server reads.
#ifndef BOT1_NEWS_SELECTOR_MQH
#define BOT1_NEWS_SELECTOR_MQH
#include "Bot1NewsBlock.mqh"
struct Bot1NewsEvents { long nfp,interest,cpi; };
struct Bot1NewsWindows { uchar nfp_enabled,interest_enabled,cpi_enabled;int nfp_after,interest_after,cpi_after; };
struct Bot1NewsSelection { long block_time;string label; };
void Bot1UpdateNewsSelection(const Bot1NewsEvents &events,const Bot1NewsWindows &settings,Bot1NewsSelection &state)
{
   state.block_time=0;
   state.label="";
   if(settings.nfp_enabled!=0 && events.nfp>0)
   {
      const long end=events.nfp+Bot1NewsMinutes32(settings.nfp_after);
      if(end>(long)TimeTradeServer()) { state.block_time=events.nfp;state.label="NFP"; }
   }
   if(settings.interest_enabled!=0 && events.interest>0)
   {
      const long end=events.interest+Bot1NewsMinutes32(settings.interest_after);
      if(end>(long)TimeTradeServer())
         if(state.block_time==0 || events.interest<state.block_time)
         { state.block_time=events.interest;state.label="Interest rates"; }
   }
   if(settings.cpi_enabled!=0 && events.cpi>0)
   {
      const long end=events.cpi+Bot1NewsMinutes32(settings.cpi_after);
      if(end>(long)TimeTradeServer())
         if(state.block_time==0 || events.cpi<state.block_time)
         { state.block_time=events.cpi;state.label="CPI"; }
   }
}
#endif
