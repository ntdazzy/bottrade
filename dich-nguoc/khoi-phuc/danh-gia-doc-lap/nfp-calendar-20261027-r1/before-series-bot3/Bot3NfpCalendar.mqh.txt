// Calendar NFP lookup, native 6ad0..6f13.
#ifndef BOT3_NFP_CALENDAR_MQH
#define BOT3_NFP_CALENDAR_MQH
long Bot3FindNfpTime()
{
   const long now=(long)TimeTradeServer();
   MqlCalendarEvent events[];
   const int count=CalendarEventByCurrency("USD",events);
   long selected=0;
   if(count>0)
   {
      const long from=now-86400;
      const long to=now+5961600;
      ulong event_id=840030016;
      for(int i=0;i<count;i++)
         if(StringFind(events[i].name,"Nonfarm Payrolls")>=0)
         {
            event_id=events[i].id;
            if(event_id==0) event_id=840030016;
            break;
         }
      MqlCalendarValue values[];
      const int total=CalendarValueHistoryByEvent(event_id,values,(datetime)from,(datetime)to);
      for(int i=0;i<total;i++)
      {
         const long time=(long)values[i].time;
         if(time>from && (selected==0 || time<selected)) selected=time;
      }
   }
   return selected;
}
#endif
