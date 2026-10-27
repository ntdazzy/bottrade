#ifndef BOT1_PANEL_CELL_MQH
#define BOT1_PANEL_CELL_MQH

void Bot1CreatePanelCell(const int base_y,const int index,const string &text,
                         const int row,const int column,uint color_value,
                         const double &scale_x,const double &scale_y,
                         const uchar &font_flag)
{
   string name="info_ea"+IntegerToString((long)index,0,32);
   ObjectCreate(0,name,(ENUM_OBJECT)107,0,(datetime)0,0.0);

   double x=scale_x;
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3f4,(long)(x*(double)column+11.0));
   double y=scale_y;
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3f5,(long)(y*(double)row+(double)base_y));

   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetString(0,name,(ENUM_OBJECT_PROPERTY_STRING)6,text);
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)3,0);
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0,(long)color_value);
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x401,0x17110d);
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x40b,0x3a2a1e);

   uchar flag=font_flag;
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3ea,(flag&1)!=0 ? 7 : 0);
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetString(0,name,(ENUM_OBJECT_PROPERTY_STRING)0x3e9,color_value==0xc4b741 ? "Arial Bold" : "Arial");
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x404,1);
   y=scale_y;
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3fc,(long)y);
   x=scale_x;
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3fb,(long)x);
   y=scale_y;
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3fc,(long)y);
   name="info_ea"+IntegerToString((long)index,0,32);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x40c,2);
}

#endif
