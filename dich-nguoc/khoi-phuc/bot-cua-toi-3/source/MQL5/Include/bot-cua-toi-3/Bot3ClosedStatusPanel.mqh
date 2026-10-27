#ifndef BOT3_CLOSED_STATUS_PANEL_MQH
#define BOT3_CLOSED_STATUS_PANEL_MQH
#include "Bot3PriceLevels.mqh"

void Bot3UpdateClosedStatusPanel(const uchar &show,const uchar &show_tester,const int &seed,const string &symbol,
                                 double &wins,double &losses)
{
   if(show==0) return;
   const long tester=MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6);
   if(tester==1 && show_tester==0) return;
   double total=0.0;
   double win_count=0.0;
   double loss_count=0.0;
   if(HistorySelect(0,2147483647))
   {
      const int total_deals=HistoryDealsTotal();
      if(total_deals-1>=0)
      {
         long accepted[15];
         for(int i=0;i<15;i++) accepted[i]=(long)(int)((uint)seed+(uint)(i+1));
         for(int index=total_deals-1;index>=0;index--)
         {
            const ulong ticket=HistoryDealGetTicket(index);
            bool magic_match=false;
            for(int i=0;i<15;i++)
            {
               if(HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)11)==accepted[i])
               { magic_match=true;break; }
            }
            if(magic_match && HistoryDealGetString(ticket,(ENUM_DEAL_PROPERTY_STRING)0)==symbol)
            {
               const double first=HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)9); total+=first;
               const double second=HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)7); total+=second;
               const double third=HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)8); total+=third;
               const double reread=HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)9);
               if(reread!=0.0)
               {
                  double delta=HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)9);
                  delta+=HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)7);
                  delta+=HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)8);
                  if(delta>0.0) win_count+=1.0;
                  if(delta<0.0) loss_count+=1.0;
               }
            }
         }
      }
   }
   losses=loss_count;
   wins=win_count;
   const string win_text=IntegerToString((int)wins,0,32);
   string text="Total profits/losses so far: "+win_text+"/";
   const string loss_text=IntegerToString((int)losses,0,32);
   text+=loss_text;
   string index_text=IntegerToString(0,0,32);
   ObjectSetString(0,"lineto"+index_text,(ENUM_OBJECT_PROPERTY_STRING)6,text);
   const string value=DoubleToString(Bot3RoundPrice(total,2),2);
   index_text=IntegerToString(0,0,32);
   ObjectSetString(0,"linetp"+index_text,(ENUM_OBJECT_PROPERTY_STRING)6,"Total P/L so far: "+value);
}

#endif
