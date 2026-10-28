#ifndef BOT1_STARTUP_TAIL_MQH
#define BOT1_STARTUP_TAIL_MQH
#include "Bot1PanelCreation.mqh"
#include "Bot1ClosedStatusPanel.mqh"

struct Bot1StartupTailState
{
   string buy_first,buy_second,sell_first,sell_second;
};

// OnInit 0x4e77..0x5658. Panel lots are the shared native volume array.
int Bot1InitializeStartupTail(const string &order_comment,const string &symbol,
                              const uint &strategy_index,const double &start_lots,
                              const MqlDateTime &calendar,long &bar_times[],
                              const uchar &show_panel,const uchar &show_tester,
                              const uchar &history_window,const int &strategy_magic,
                              const int &magic_base,const double &effective_balance,
                              Bot1PanelCreationState &panel,const Bot1NewsEvents &events,
                              const Bot1NewsWindows &windows,Bot1NewsSelection &selection,
                              ulong &last_ticket,int &last_hour,double &wins,double &losses,
                              Bot1StartupTailState &state)
{
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
      if(panel.closed_star==1)
      {
         const int tester=MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6);
         if((tester!=1 || show_tester!=0) && HistorySelect((datetime)0,(datetime)0x7fffffff))
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
      }
      Bot1CreateInfoPanel(panel,events,windows,selection);
      Bot1UpdateOpenStatusPanel(show_panel,show_tester,magic_base,symbol,effective_balance,
                                 panel.lots[0],panel.mode,panel.trade_risk,panel.strategy_risk,
                                 panel.balance_step,events,windows,selection,last_ticket);
      Bot1UpdateClosedStatusPanel(show_panel,show_tester,magic_base,symbol,wins,losses);
   }
   return 0;
}
#endif
