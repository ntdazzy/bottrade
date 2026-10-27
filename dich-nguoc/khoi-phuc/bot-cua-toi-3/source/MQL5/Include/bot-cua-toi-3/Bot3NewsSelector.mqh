// Native full news selector 7c30..7e18: timestamp, label, ordered live server reads.
#ifndef BOT3_NEWS_SELECTOR_MQH
#define BOT3_NEWS_SELECTOR_MQH
#include "Bot3NewsBlock.mqh"
struct Bot3NewsEvents { long nfp,interest,cpi; };
struct Bot3NewsWindows { uchar nfp_enabled,interest_enabled,cpi_enabled;int nfp_after,interest_after,cpi_after; };
struct Bot3NewsSelection { long block_time;string label; };
void Bot3UpdateNewsSelectionFields(const uchar &nfp_enabled,const long &nfp_time,const int &nfp_after,
                                   const uchar &interest_enabled,const long &interest_time,const int &interest_after,
                                   const uchar &cpi_enabled,const long &cpi_time,const int &cpi_after,
                                   Bot3NewsSelection &state)
{
   state.block_time=0;
   state.label="";
   if(nfp_enabled!=0 && nfp_time>0)
   {
      const long end=nfp_time+Bot3NewsMinutes32(nfp_after);
      if(end>(long)TimeTradeServer()) { state.block_time=nfp_time;state.label="NFP"; }
   }
   if(interest_enabled!=0 && interest_time>0)
   {
      const long end=interest_time+Bot3NewsMinutes32(interest_after);
      if(end>(long)TimeTradeServer())
         if(state.block_time==0 || interest_time<state.block_time)
         { state.block_time=interest_time;state.label="Interest rates"; }
   }
   if(cpi_enabled!=0 && cpi_time>0)
   {
      const long end=cpi_time+Bot3NewsMinutes32(cpi_after);
      if(end>(long)TimeTradeServer())
         if(state.block_time==0 || cpi_time<state.block_time)
         { state.block_time=cpi_time;state.label="CPI"; }
   }
}
void Bot3UpdateNewsSelection(const Bot3NewsEvents &events,const Bot3NewsWindows &settings,Bot3NewsSelection &state)
{
   Bot3UpdateNewsSelectionFields(settings.nfp_enabled,events.nfp,settings.nfp_after,
                                  settings.interest_enabled,events.interest,settings.interest_after,
                                  settings.cpi_enabled,events.cpi,settings.cpi_after,state);
}
#endif
