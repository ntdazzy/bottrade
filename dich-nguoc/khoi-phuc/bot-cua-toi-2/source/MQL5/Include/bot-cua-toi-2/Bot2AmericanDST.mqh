// Native RVA 0x17440. Compares whole days, excluding both boundary days.
#ifndef BOT2_AMERICAN_DST_MQH
#define BOT2_AMERICAN_DST_MQH
bool Bot2AmericanDST()
{
   MqlDateTime dt;
   TimeToStruct(TimeCurrent(),dt);
   if(dt.year<1987)
   {
      Print("AmericanDST(): Invalid year.");
      return false;
   }
   int year=dt.year;
   double start_day=0.0,end_day=0.0;
   datetime start_base=0,end_base=0;
   if(year<2007)
   {
      start_day=MathMod(year*6-year/4+2,7.0)+1.0;
      end_day=31.0-MathMod(year*5/4+1,7.0);
      string start_text="",end_text="";
      StringConcatenate(start_text,year,".04.01");
      StringConcatenate(end_text,year,".10.01");
      start_base=StringToTime(start_text);
      end_base=StringToTime(end_text);
   }
   else
   {
      int cycle=year*5/4+1;
      start_day=14.0-MathMod(cycle,7.0);
      end_day=7.0-MathMod(cycle,7.0);
      string start_text="",end_text="";
      StringConcatenate(start_text,year,".03.01");
      StringConcatenate(end_text,year,".11.01");
      start_base=StringToTime(start_text);
      end_base=StringToTime(end_text);
   }
   TimeToStruct(TimeCurrent(),dt);
   int today=dt.day_of_year;
   TimeToStruct(start_base+7200+((int)start_day*86400-86400),dt);
   if(dt.day_of_year<today)
   {
      TimeToStruct(TimeCurrent(),dt);
      today=dt.day_of_year;
      TimeToStruct(end_base+7200+((int)end_day*86400-86400),dt);
      if(today<dt.day_of_year) return true;
   }
   return false;
}
#endif
