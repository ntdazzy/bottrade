// Native full news selector 7310..74f8: timestamp, label, ordered live server reads.
#ifndef BOT1_NEWS_SELECTOR_MQH
#define BOT1_NEWS_SELECTOR_MQH
#include "Bot1NewsBlock.mqh"
struct Bot1NewsEvents { long nfp,interest,cpi; };
struct Bot1NewsWindows { uchar nfp_enabled,interest_enabled,cpi_enabled;int nfp_after,interest_after,cpi_after; };
struct Bot1NewsSelection { long block_time;string label; };
void Bot1UpdateNewsSelectionFields(const uchar &nfp_enabled,const long &nfp_time,const int &nfp_after,
                                   const uchar &interest_enabled,const long &interest_time,const int &interest_after,
                                   const uchar &cpi_enabled,const long &cpi_time,const int &cpi_after,
                                   Bot1NewsSelection &state)
{
   state.block_time=0;
   state.label="";
   if(nfp_enabled!=0 && nfp_time>0)
   {
      const long end=nfp_time+Bot1NewsMinutes32(nfp_after);
      if(end>(long)TimeTradeServer()) { state.block_time=nfp_time;state.label="NFP"; }
   }
   if(interest_enabled!=0 && interest_time>0)
   {
      const long end=interest_time+Bot1NewsMinutes32(interest_after);
      if(end>(long)TimeTradeServer())
         if(state.block_time==0 || interest_time<state.block_time)
         { state.block_time=interest_time;state.label="Interest rates"; }
   }
   if(cpi_enabled!=0 && cpi_time>0)
   {
      const long end=cpi_time+Bot1NewsMinutes32(cpi_after);
      if(end>(long)TimeTradeServer())
         if(state.block_time==0 || cpi_time<state.block_time)
         { state.block_time=cpi_time;state.label="CPI"; }
   }
}
void Bot1UpdateNewsSelection(const Bot1NewsEvents &events,const Bot1NewsWindows &settings,Bot1NewsSelection &state)
{
   Bot1UpdateNewsSelectionFields(settings.nfp_enabled,events.nfp,settings.nfp_after,
                                  settings.interest_enabled,events.interest,settings.interest_after,
                                  settings.cpi_enabled,events.cpi,settings.cpi_after,state);
}
#endif
