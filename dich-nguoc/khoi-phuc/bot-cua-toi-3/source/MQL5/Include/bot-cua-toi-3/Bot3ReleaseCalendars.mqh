// Economic-calendar lookups following the original interest/CPI helpers.
#ifndef BOT3_RELEASE_CALENDARS_MQH
#define BOT3_RELEASE_CALENDARS_MQH
long Bot3FindInterestRateTime()
{
   const long now=(long)TimeTradeServer();
   MqlCalendarEvent events[];
   const int count=CalendarEventByCountry("US",events);
   if(count<=0) return 0;
   const long from=now-86400,to=now+5961600;
   ulong event_id=0x3212255e;
   for(int i=0;i<count;i++)
      if(StringFind(events[i].name,"Fed Interest Rate Decision")>=0)
      {
         event_id=events[i].id;
         if(event_id==0) event_id=0x3212255e;
         break;
      }
   MqlCalendarValue values[];
   const int total=CalendarValueHistoryByEvent(event_id,values,(datetime)from,(datetime)to);
   if(GetLastError()==5401)
   {
      Print("Calendar timeout error. Try shortening the date range.");
      return 0;
   }
   long selected=0;
   for(int i=0;i<total;i++)
   {
      const long time=(long)values[i].time;
      if(time>from && (selected==0 || time<selected)) selected=time;
   }
   return selected;
}
long Bot3FindCpiTime()
{
   const long now=(long)TimeTradeServer();
   MqlCalendarEvent events[];
   const int count=CalendarEventByCurrency("USD",events);
   if(count<=0) return 0;
   const long from=now-86400,to=now+5961600;
   ulong event_id=0x3211d735;
   for(int i=0;i<count;i++)
   {
      const string name=events[i].name;
      if((StringFind(name,"Consumer Price Index")>=0 || StringFind(name,"CPI ")>=0) &&
         (StringFind(name,"(YoY)")>=0 || StringFind(name,"ex Food")<0))
      {
         event_id=events[i].id;
         if(event_id==0) event_id=0x3211d735;
         break;
      }
   }
   MqlCalendarValue values[];
   const int total=CalendarValueHistoryByEvent(event_id,values,(datetime)from,(datetime)to);
   long selected=0;
   for(int i=0;i<total;i++)
   {
      const long time=(long)values[i].time;
      if(time>from && (selected==0 || time<selected)) selected=time;
   }
   return selected;
}
#endif
