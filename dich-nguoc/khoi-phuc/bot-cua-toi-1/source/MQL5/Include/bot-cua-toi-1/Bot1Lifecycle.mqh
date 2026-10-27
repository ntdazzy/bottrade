#ifndef BOT1_LIFECYCLE_MQH
#define BOT1_LIFECYCLE_MQH

// Native deinitialization order from RVA 0x1f5e0.
void Bot1DeinitializePanel(const uchar &extended,int &indicator_handle)
{
   ObjectDelete(0,"line1");
   ObjectDelete(0,"linec");
   ObjectDelete(0,"line2");
   ObjectDelete(0,"lines");
   ObjectDelete(0,"lineTradeStart");
   ObjectDelete(0,"linenfp"+IntegerToString(0));
   for(int outer=0;outer<100;outer++)
   {
      ObjectDelete(0,"lineopl"+IntegerToString(outer));
      ObjectDelete(0,"linea"+IntegerToString(outer));
      ObjectDelete(0,"lineto"+IntegerToString(outer));
      ObjectDelete(0,"linetp"+IntegerToString(outer));
      ObjectDelete(0,"linetq"+IntegerToString(outer));
      for(int inner=0;inner<10;inner++)
         ObjectDelete(0,"tabel_info"+IntegerToString(outer*100+inner));
   }
   ObjectDelete(0,"infopanel_rectangle");
   for(int index=0;index<10;index++)
   {
      ObjectDelete(0,"tabel_heading"+IntegerToString(index));
      ObjectDelete(0,"tabel_totals"+IntegerToString(index));
   }
   if(extended==1)
      for(int index=0;index<300;index++)
      {
         ObjectDelete(0,"horizontalrect"+IntegerToString(index));
         ObjectDelete(0,"info_ea"+IntegerToString(index));
         if(extended!=1) break;
      }
   if(indicator_handle!=-1)
   {
      IndicatorRelease(indicator_handle);
      indicator_handle=-1;
   }
   ObjectsDeleteAll(0,-1,-1);
}
#endif
