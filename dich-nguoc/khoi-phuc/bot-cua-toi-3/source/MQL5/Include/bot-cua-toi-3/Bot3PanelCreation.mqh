#ifndef BOT3_PANEL_CREATION_MQH
#define BOT3_PANEL_CREATION_MQH
#include "Bot3PanelCell.mqh"
#include "Bot3OpenStatusPanel.mqh"
#include "Bot3PriceLevels.mqh"

struct Bot3PanelCreationState
{
   int font;
   double scale;
   uchar color_flag;
   uint mode;
   int frequency;
   double strategy_risk;
   double manual_lots;
   double allowed_dd;
   double cell_x;
   double cell_y;
   uchar cell_font_flag;
   uchar closed_star;
   uchar rows_ready;
   double closed[9];
   double per_trade[9];
   double lots[9];
};

void Bot3PanelFixedLabel(const string name,const long y,const string text,const long font,const uchar &color_flag)
{
   ObjectCreate(0,name,(ENUM_OBJECT)102,0,(datetime)0,0.0);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x402,0);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3f5,y);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3f4,11);
   ObjectSetString(0,name,(ENUM_OBJECT_PROPERTY_STRING)6,text);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0,color_flag!=0 ? 0x8b0000 : 0);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3ea,font);
}

string Bot3PanelStatusName(const string prefix)
{
   return prefix+IntegerToString(0,0,32);
}

void Bot3PanelStatusStart(const string prefix,const long y)
{
   string name=Bot3PanelStatusName(prefix);
   ObjectCreate(0,name,(ENUM_OBJECT)102,0,(datetime)0,0.0);
   name=Bot3PanelStatusName(prefix);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x402,0);
   name=Bot3PanelStatusName(prefix);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3f5,y);
   name=Bot3PanelStatusName(prefix);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3f4,11);
}

void Bot3PanelStatusFinish(const string prefix,const string text,const long font,const uchar &color_flag)
{
   string name=Bot3PanelStatusName(prefix);
   ObjectSetString(0,name,(ENUM_OBJECT_PROPERTY_STRING)6,text);
   const uchar flag=color_flag;
   name=Bot3PanelStatusName(prefix);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0,(flag&1)!=0 ? 0x8b0000 : 0);
   name=Bot3PanelStatusName(prefix);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3ea,font);
}

void Bot3PanelStyle(const string name,const long color_value,const long font,const string face)
{
   if(ObjectFind(0,name)==-1) return;
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0,color_value);
   ObjectSetInteger(0,name,(ENUM_OBJECT_PROPERTY_INTEGER)0x3ea,font);
   ObjectSetString(0,name,(ENUM_OBJECT_PROPERTY_STRING)0x3e9,face);
}

// Full native constructor: 0xef40..0x14f98. State fields remain live at each original read.
void Bot3CreateInfoPanel(Bot3PanelCreationState &p,const Bot3NewsEvents &events,
                         const Bot3NewsWindows &windows,Bot3NewsSelection &selection)
{
   const int font=p.font>0 ? p.font : 7;
   ObjectCreate(0,"infopanel_rectangle",(ENUM_OBJECT)110,0,(datetime)0,0.0);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x3f4,5);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x3f5,20);
   const double scale=p.scale;
   const double width=350.0*scale;
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x3fb,(long)width);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x3fc,(long)(width+0.0));
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x402,0);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0,0x3a2a1e);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x401,0x17110d);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)3,0);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x40b,0x3a2a1e);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x405,0);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)1,0);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)2,2);
   ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)10,0);
   Bot3PanelFixedLabel("line1",24,"The Gold Reaper V5.5",font,p.color_flag);
   Bot3PanelFixedLabel("linec",(long)(scale*20.0+20.0+4.0),"EA Developed by Wim Schrynemakers - 2024",font,p.color_flag);
   Bot3PanelFixedLabel("line2",(long)(32.0*scale+20.0+4.0),"------------------------------------------------------",font,p.color_flag);
   ObjectCreate(0,"lines",(ENUM_OBJECT)102,0,(datetime)0,0.0);
   ObjectSetInteger(0,"lines",(ENUM_OBJECT_PROPERTY_INTEGER)0x402,0);
   ObjectSetInteger(0,"lines",(ENUM_OBJECT_PROPERTY_INTEGER)0x3f5,(long)(44.0*scale+20.0+4.0));
   ObjectSetInteger(0,"lines",(ENUM_OBJECT_PROPERTY_INTEGER)0x3f4,11);
   string frequency_text;
   switch(p.frequency)
   {
      case 0: frequency_text="extreme conservative";break;
      case 1: frequency_text="conservative";break;
      case 2: frequency_text="moderate";break;
      case 3: frequency_text="intense";break;
      case 4: frequency_text="extreme";break;
      default: frequency_text="manual strategy selection";
   }
   ObjectSetString(0,"lines",(ENUM_OBJECT_PROPERTY_STRING)6,"Trade Frequency: "+frequency_text);
   ObjectSetInteger(0,"lines",(ENUM_OBJECT_PROPERTY_INTEGER)0,p.color_flag!=0 ? 0x8b0000 : 0);
   ObjectSetInteger(0,"lines",(ENUM_OBJECT_PROPERTY_INTEGER)0x3ea,font);
   const uint mode=p.mode;
   ObjectCreate(0,"linet",(ENUM_OBJECT)102,0,(datetime)0,0.0);
   ObjectSetInteger(0,"linet",(ENUM_OBJECT_PROPERTY_INTEGER)0x402,0);
   ObjectSetInteger(0,"linet",(ENUM_OBJECT_PROPERTY_INTEGER)0x3f5,(long)(60.0*scale+20.0+4.0));
   ObjectSetInteger(0,"linet",(ENUM_OBJECT_PROPERTY_INTEGER)0x3f4,11);
   string risk_text;
   if(mode==3) risk_text="Max risk per strategy: "+Bot3PanelDoubleText(p.strategy_risk)+"%";
   else if(mode==1234) risk_text="Max allowed DD: "+Bot3PanelDoubleText(p.allowed_dd)+"%";
   else risk_text="Manual lotsize: "+Bot3PanelDoubleText(p.manual_lots)+"lots";
   ObjectSetString(0,"linet",(ENUM_OBJECT_PROPERTY_STRING)6,risk_text);
   ObjectSetInteger(0,"linet",(ENUM_OBJECT_PROPERTY_INTEGER)0,p.color_flag!=0 ? 0x8b0000 : 0);
   ObjectSetInteger(0,"linet",(ENUM_OBJECT_PROPERTY_INTEGER)0x3ea,font);
   Bot3PanelStatusStart("lineopl",(long)(76.0*scale+20.0+4.0));
   Bot3PanelStatusFinish("lineopl","Open P/L: -",font,p.color_flag);
   Bot3PanelStatusStart("linea",(long)(92.0*scale+20.0+4.0));
   Bot3PanelStatusFinish("linea","Account Balance: -",font,p.color_flag);
   Bot3PanelStatusStart("linetp",(long)(108.0*scale+20.0+4.0));
   Bot3PanelStatusFinish("linetp","Total P/L so far: -",font,p.color_flag);
   Bot3PanelStatusStart("linenfp",(long)(124.0*scale+20.0+4.0));
   Bot3UpdateNewsSelection(events,windows,selection);
   string news_text;
   if(selection.block_time!=0)
      news_text="Next News: "+selection.label+", "+Bot3PanelTimeText((datetime)selection.block_time);
   else news_text="no news coming up";
   Bot3PanelStatusFinish("linenfp",news_text,font,p.color_flag);

   const int base_y=(int)(scale*160.0+20.0+4.0);
   string label="Strategy";
   Bot3CreatePanelCell(base_y,0,label,0,0,0xc4b741,p.cell_x,p.cell_y,p.cell_font_flag);
   label=p.closed_star==1 ? "Closed PL*" : "Closed PL";
   Bot3CreatePanelCell(base_y,1,label,0,1,0xc4b741,p.cell_x,p.cell_y,p.cell_font_flag);
   label="PL per trade";
   Bot3CreatePanelCell(base_y,2,label,0,2,0xc4b741,p.cell_x,p.cell_y,p.cell_font_flag);
   label="Lotsize";
   Bot3CreatePanelCell(base_y,3,label,0,3,0xc4b741,p.cell_x,p.cell_y,p.cell_font_flag);
   p.rows_ready=1;
   for(int i=0;i<9;i++)
   {
      const int index=4+4*i,row=i+1;
      label="Strategy "+IntegerToString((long)row,0,32);
      Bot3CreatePanelCell(base_y,index,label,row,0,0xb09a8b,p.cell_x,p.cell_y,p.cell_font_flag);
      label=DoubleToString(Bot3RoundPrice(p.closed[i],2),2);
      Bot3CreatePanelCell(base_y,index+1,label,row,1,0xb09a8b,p.cell_x,p.cell_y,p.cell_font_flag);
      label=DoubleToString(Bot3RoundPrice(p.per_trade[i],2),2);
      Bot3CreatePanelCell(base_y,index+2,label,row,2,0xb09a8b,p.cell_x,p.cell_y,p.cell_font_flag);
      label=DoubleToString(Bot3RoundPrice(p.lots[i],2),2);
      Bot3CreatePanelCell(base_y,index+3,label,row,3,0xb09a8b,p.cell_x,p.cell_y,p.cell_font_flag);
   }
   const long large_font=(long)(int)((uint)font+4);
   const long body_font=(long)(int)((uint)font+1);
   Bot3PanelStyle("line1",0xbd7d37,large_font,"Arial Bold");
   Bot3PanelStyle("linec",0xe8d6c8,body_font,"Arial");
   Bot3PanelStyle("lines",0xb09a8b,body_font,"Arial");
   Bot3PanelStyle("linet",0xb09a8b,body_font,"Arial");
   Bot3PanelStyle("lineopl0",0xbd7d37,body_font,"Arial");
   Bot3PanelStyle("linea0",0xb09a8b,body_font,"Arial");
   Bot3PanelStyle("lineto0",0xb09a8b,body_font,"Arial");
   Bot3PanelStyle("linetp0",0xbd7d37,body_font,"Arial");
   Bot3PanelStyle("linenfp0",0xb09a8b,body_font,"Arial");
   Bot3PanelStyle("linenextnews0",0xb09a8b,body_font,"Arial");
   string separator="";
   const int count=(int)(width/(double)(int)((uint)font+3));
   for(int i=0;i<count;i++) separator+="─";
   ObjectSetString(0,"line2",(ENUM_OBJECT_PROPERTY_STRING)6,separator);
   Bot3PanelStyle("line2",0x503a2a,body_font,"Arial");
}
#endif
