#ifndef BOT1_DISPATCH_TAIL_MQH
#define BOT1_DISPATCH_TAIL_MQH
#include "Bot1PanelCreation.mqh"
#include "Bot1ClosedStatusPanel.mqh"

void Bot1SetPanelCellText(const int index,const string &text)
{
   string name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetString(0,name,(ENUM_OBJECT_PROPERTY_STRING)6,text);
}

// Native dispatcher 0x16730..0x16da0. Shared arrays are also used by the strategy loop.
void Bot1FinishDispatch(const uchar &show,const uchar &show_tester,const int &seed,
                       const string &symbol,const double &balance,Bot1PanelCreationState &panel,
                       const Bot1NewsEvents &events,const Bot1NewsWindows &windows,
                       Bot1NewsSelection &selection,ulong &last_ticket,double &wins,double &losses,
                       long &previous_m5,int &balance_calls,double &cached_balance)
{
   Bot1UpdateOpenStatusPanel(show,show_tester,seed,symbol,balance,panel.lots[0],panel.mode,
      panel.trade_risk,panel.strategy_risk,panel.balance_step,events,windows,selection,last_ticket);
   const long observed=(long)iTime(NULL,PERIOD_M5,1);
   if(observed!=previous_m5)
   {
      previous_m5=(long)iTime(NULL,PERIOD_M5,1);
      if(show!=0 && (MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6)!=1 || show_tester!=0))
      {
         int cell=(int)panel.rows_ready*4;
         for(int row=0;row<8;row++,cell+=4)
         {
            string text="Strategy "+IntegerToString((long)(row+1),0,32);
            Bot1SetPanelCellText(cell,text);
            text=DoubleToString(Bot1RoundPrice(panel.closed[row],2),2);
            Bot1SetPanelCellText(cell+1,text);
            text=DoubleToString(Bot1RoundPrice(panel.per_trade[row],2),2);
            Bot1SetPanelCellText(cell+2,text);
            text=DoubleToString(Bot1RoundPrice(panel.lots[row],2),2);
            Bot1SetPanelCellText(cell+3,text);
         }
      }
      Bot1UpdateClosedStatusPanel(show,show_tester,seed,symbol,wins,losses);
   }
   balance_calls=(int)((uint)balance_calls+1);
   if(balance_calls>=2)
   {
      double observed_balance=AccountInfoDouble(ACCOUNT_BALANCE);
      balance_calls=0;
      cached_balance=observed_balance;
   }
}
#endif
