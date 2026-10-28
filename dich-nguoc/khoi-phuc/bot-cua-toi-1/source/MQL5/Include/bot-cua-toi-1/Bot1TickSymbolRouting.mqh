#ifndef BOT1_TICK_SYMBOL_ROUTING_MQH
#define BOT1_TICK_SYMBOL_ROUTING_MQH

// Dispatcher 0x11f3f: copy the chart symbol before either the direct
// evaluation at 0x12004 or the configured strategy path at 0x12409.
bool Bot1PrepareTickSymbol(const string &chart_symbol,string &working_symbol)
{
   const int first=StringFind(chart_symbol,"XAUUSD");
   bool configured=false;
   if(chart_symbol!=NULL)
   {
      configured=first>=0 || StringFind(chart_symbol,"xauusd")>=0 ||
         StringFind(chart_symbol,"GOLD")>=0 || StringFind(chart_symbol,"gold")>=0 ||
         StringFind(chart_symbol,"Gold")>=0 || StringFind(chart_symbol,"XAU")>=0 ||
         StringFind(chart_symbol,"xau")>=0 || StringFind(chart_symbol,"XAG")>=0;
      if(!configured)
      {
         // Both searches execute before the native signed bitwise test.
         const int silver=StringFind(chart_symbol,"xag");
         const int future=StringFind(chart_symbol,"GC");
         configured=(silver&future)>=0;
         if(!configured) configured=StringFind(chart_symbol,"gc")>=0;
      }
   }
   working_symbol=chart_symbol;
   return configured;
}
#endif
