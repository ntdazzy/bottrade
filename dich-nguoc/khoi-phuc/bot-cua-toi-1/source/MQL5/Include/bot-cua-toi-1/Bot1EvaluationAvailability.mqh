#ifndef BOT1_EVALUATION_AVAILABILITY_MQH
#define BOT1_EVALUATION_AVAILABILITY_MQH
bool Bot1AllowsOrderEvaluation(const uchar &day_switch_filter,const MqlDateTime &calendar,uchar &notice)
{
   const long mode=MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6);
   if(mode==0 && MQLInfoInteger((ENUM_MQL_INFO_INTEGER)4)==0)
   {
      if(notice==0) Print("Market closed... waiting to continue");
      notice=1;
      return false;
   }
   if(day_switch_filter!=0 && calendar.hour==0 && calendar.min<=4)
   {
      if(notice==0)
      {
         const int pause_minutes=5;
         const string minutes=(string)pause_minutes;
         Print("DAYSWITCH -> Market might be closed... waiting "+minutes+" minutes before setting order..");
      }
      notice=1;
      return false;
   }
   return true;
}
#endif
