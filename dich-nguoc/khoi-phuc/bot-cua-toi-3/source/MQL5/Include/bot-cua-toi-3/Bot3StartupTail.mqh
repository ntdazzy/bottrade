#ifndef BOT3_STARTUP_TAIL_MQH
#define BOT3_STARTUP_TAIL_MQH
#include "Bot3PanelCreation.mqh"
#include "Bot3ClosedStatusPanel.mqh"

struct Bot3StartupTailState
{
   string buy_first,buy_second,sell_first,sell_second;
   uchar flag_744a0;
};

// OnInit 0x574c..0x5f34. Keep the price-bar array separate from M1 bars.
int Bot3InitializeStartupTail(const string &order_comment,const string &symbol,
                              const uint &strategy_index,const double &start_lots,
                              const MqlDateTime &calendar,long &bar_times[],
                              const uchar &show_panel,const uchar &show_tester,
                              const uchar &history_window,const int &strategy_magic,
                              const int &magic_base,const double &effective_balance,
                              Bot3PanelCreationState &panel,const Bot3NewsEvents &events,
                              const Bot3NewsWindows &windows,Bot3NewsSelection &selection,
                              ulong &last_ticket,int &last_hour,double &wins,double &losses,
                              Bot3StartupTailState &state)
{
   state.flag_744a0=0;
   state.buy_first=order_comment+"B1";
   state.buy_second=order_comment+"B2";
   state.sell_first=order_comment+"S1";
   state.sell_second=order_comment+"S2";
   last_hour=calendar.hour;
   bar_times[0]=0;
   SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   if(panel.lots[strategy_index]<start_lots) panel.lots[strategy_index]=start_lots;
   if(show_panel!=0)
   {
      if(panel.closed_star==1 && HistorySelect((datetime)0,(datetime)0x7fffffff))
      {
         int index=HistoryDealsTotal();
         if(index-1>=0)
         {
            do
            {
               index--;
               const ulong ticket=HistoryDealGetTicket(index);
               const long time=HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)2);
               long boundary=(long)TimeCurrent();
               if(history_window!=0) boundary-=7776000;
               if(time<boundary) break;
               if(HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)11)==strategy_magic)
                  HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)5);
            } while(index>0);
         }
      }
      Bot3CreateInfoPanel(panel,events,windows,selection);
      Bot3UpdateOpenStatusPanel(show_panel,show_tester,magic_base,symbol,effective_balance,
                               panel.frequency,panel.mode,panel.manual_lots,panel.allowed_dd,
                               panel.strategy_risk,events,windows,selection,last_ticket);
      Bot3UpdateClosedStatusPanel(show_panel,show_tester,magic_base,symbol,wins,losses);
   }
   return 0;
}
#endif
