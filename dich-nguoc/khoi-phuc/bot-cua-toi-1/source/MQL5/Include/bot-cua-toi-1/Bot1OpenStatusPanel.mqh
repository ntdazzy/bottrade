#ifndef BOT1_OPEN_STATUS_PANEL_MQH
#define BOT1_OPEN_STATUS_PANEL_MQH
#include "Bot1NewsSelector.mqh"
#include "Bot1PriceLevels.mqh"

#ifndef BOT1_PANEL_TEXT_CASTS_MQH
#define BOT1_PANEL_TEXT_CASTS_MQH
string Bot1PanelDoubleText(const double value) { return (string)value; }
string Bot1PanelIntegerText(const int value) { return (string)value; }
string Bot1PanelTimeText(const datetime value) { return (string)value; }
#endif

void Bot1UpdateOpenStatusPanel(const uchar &show,const uchar &show_tester,const int &seed,const string &symbol,
                              const double &balance,const double &first_volume,const int &mode,const double &trade_risk,
                              const double &strategy_risk,const int &balance_step,const Bot1NewsEvents &events,
                              const Bot1NewsWindows &windows,Bot1NewsSelection &selection,ulong &last_ticket)
{
   if(show==0) return;
   const long tester=MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6);
   const uchar tester_flag=show_tester;
   if(tester==1 && tester_flag==0) return;
   const long tester_again=MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6);
   double open_pl=0.0;
   if(tester_again!=1 || tester_flag!=0)
   {
      const int total=PositionsTotal();
      if(total>0)
      {
         long accepted[8];
         for(int i=0;i<8;i++) accepted[i]=(long)(int)((uint)seed+(uint)(i+1));
         int index=0;
         do
         {
            last_ticket=PositionGetTicket(index);
            if(last_ticket!=0 && PositionGetString((ENUM_POSITION_PROPERTY_STRING)0)==symbol)
            {
               bool magic_match=false;
               for(int i=0;i<8;i++)
               {
                  if(PositionGetInteger((ENUM_POSITION_PROPERTY_INTEGER)12)==accepted[i])
                  { magic_match=true;break; }
               }
               if(magic_match && (PositionGetInteger((ENUM_POSITION_PROPERTY_INTEGER)2)==0 ||
                                  PositionGetInteger((ENUM_POSITION_PROPERTY_INTEGER)2)==1))
               {
                  PositionSelectByTicket(last_ticket);
                  const double first=PositionGetDouble((ENUM_POSITION_PROPERTY_DOUBLE)10);
                  const double second=PositionGetDouble((ENUM_POSITION_PROPERTY_DOUBLE)9);
                  SetUserError(4014);
                  const double part=(first+second)+0.0;
                  open_pl+=part;
               }
            }
            index++;
         } while(index<PositionsTotal());
      }
   }
   const string value=DoubleToString(open_pl,2);
   string index_text=IntegerToString(0,0,32);
   ObjectSetString(0,"lineopl"+index_text,(ENUM_OBJECT_PROPERTY_STRING)6,"Open P/L: "+value);
   const string balance_text=DoubleToString(balance,2);
   index_text=IntegerToString(0,0,32);
   ObjectSetString(0,"linea"+index_text,(ENUM_OBJECT_PROPERTY_STRING)6,"Account Balance: "+balance_text);
   Bot1UpdateNewsSelection(events,windows,selection);
   string news_text;
   if(selection.block_time!=0)
      news_text="Next News: "+selection.label+", "+Bot1PanelTimeText((datetime)selection.block_time);
   else news_text="no news coming up";
   index_text=IntegerToString(0,0,32);
   ObjectSetString(0,"linenfp"+index_text,(ENUM_OBJECT_PROPERTY_STRING)6,news_text);
   string strategy_text;
   if(mode==3)
      strategy_text="Using Max Risk Per Strategy: "+Bot1PanelDoubleText(strategy_risk)+"%";
   else if(mode==999)
      strategy_text="Using Max Risk Per Trade: "+Bot1PanelDoubleText(trade_risk)+"%";
   else if(mode==9999)
      strategy_text="Using Lots Per Balance, stepsize: "+Bot1PanelIntegerText(balance_step);
   else
      strategy_text="Using fixed lotsizee: "+DoubleToString(Bot1RoundPrice(first_volume,2),2)+"lots";
   ObjectSetString(0,"lines",(ENUM_OBJECT_PROPERTY_STRING)6,strategy_text);
}

#endif
