#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"
Bot1PanelCreationState P;Bot1NewsEvents Events;Bot1NewsWindows Windows;Bot1NewsSelection Selection;
union Number { double value;ulong word; };
double FromBits(const ulong word) { Number n;n.word=word;return n.value; }
void Text(const int file,const string value)
{ int n=StringLen(value);FileWriteInteger(file,n);if(n>0)FileWriteString(file,value,n); }
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-panel-visual\\"+CheckRun+"\\";
   string names[]={"infopanel_rectangle","line1","linec","line2","lines","linet","lineopl0","linea0","linetp0","linenfp0"};
   for(int i=0;i<ArraySize(names);i++)ObjectDelete(0,names[i]);
   ObjectsDeleteAll(0,"info_ea");
   P.font=7;
   P.scale=FromBits(4607182418800017408);
   P.color_flag=1;
   P.mode=-1;
   P.strategy_risk=FromBits(4613374868287651840);
   P.trade_risk=FromBits(4608308318706860032);
   P.balance_step=600;
   P.cell_x=FromBits(4635224363354816512);
   P.cell_y=FromBits(4624070917402656768);
   P.cell_font_flag=1;
   P.closed_star=1;
   P.rows_ready=0;
   P.closed[0]=FromBits(4607204936798154260);
   P.closed[1]=FromBits(4607204936798154260);
   P.closed[2]=FromBits(4607204936798154260);
   P.closed[3]=FromBits(4607204936798154260);
   P.closed[4]=FromBits(4607204936798154260);
   P.closed[5]=FromBits(4607204936798154260);
   P.closed[6]=FromBits(4607204936798154260);
   P.closed[7]=FromBits(4607204936798154260);
   P.per_trade[0]=FromBits(13830576973652930068);
   P.per_trade[1]=FromBits(13830576973652930068);
   P.per_trade[2]=FromBits(13830576973652930068);
   P.per_trade[3]=FromBits(13830576973652930068);
   P.per_trade[4]=FromBits(13830576973652930068);
   P.per_trade[5]=FromBits(13830576973652930068);
   P.per_trade[6]=FromBits(13830576973652930068);
   P.per_trade[7]=FromBits(13830576973652930068);
   P.lots[0]=FromBits(4593671619917905920);
   P.lots[1]=FromBits(4593671619917905920);
   P.lots[2]=FromBits(4593671619917905920);
   P.lots[3]=FromBits(4593671619917905920);
   P.lots[4]=FromBits(4593671619917905920);
   P.lots[5]=FromBits(4593671619917905920);
   P.lots[6]=FromBits(4593671619917905920);
   P.lots[7]=FromBits(4593671619917905920);
   Events.nfp=1767355500;
   Events.interest=1767355500;
   Events.cpi=1767355500;
   Windows.nfp_enabled=0;
   Windows.interest_enabled=0;
   Windows.cpi_enabled=0;
   Windows.nfp_after=10;
   Windows.interest_after=10;
   Windows.cpi_after=10;
   Selection.block_time=999;
   Selection.label="Previous";
   Bot1CreateInfoPanel(P,Events,Windows,Selection);ChartRedraw(0);
   int output=FileOpen(folder+"objects.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 2;
   int count=ObjectsTotal(0,-1,-1);FileWriteInteger(output,0x50564931);FileWriteInteger(output,1);FileWriteInteger(output,count);
   ENUM_OBJECT_PROPERTY_INTEGER properties[]={OBJPROP_TYPE,OBJPROP_XDISTANCE,OBJPROP_YDISTANCE,OBJPROP_XSIZE,OBJPROP_YSIZE,
      OBJPROP_FONTSIZE,OBJPROP_COLOR,OBJPROP_BGCOLOR,OBJPROP_BORDER_COLOR,OBJPROP_SELECTABLE,OBJPROP_HIDDEN};
   for(int i=0;i<count;i++)
   {
      string name=ObjectName(0,i,-1,-1);Text(output,name);
      for(int j=0;j<ArraySize(properties);j++)FileWriteLong(output,ObjectGetInteger(0,name,properties[j]));
      Text(output,ObjectGetString(0,name,OBJPROP_TEXT));Text(output,ObjectGetString(0,name,OBJPROP_FONT));
   }
   FileClose(output);
   ResetLastError();bool border_set=ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x40b,0x3a2a1e);
   int set_error=GetLastError();ResetLastError();long border=ObjectGetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x40b);
   int get_error=GetLastError();int probe=FileOpen(folder+"sdk-properties.bin",FILE_WRITE|FILE_BIN);if(probe==INVALID_HANDLE)return 5;
   FileWriteInteger(probe,0x50525031);FileWriteInteger(probe,border_set ? 1 : 0);FileWriteInteger(probe,set_error);
   FileWriteLong(probe,border);FileWriteInteger(probe,get_error);FileClose(probe);
   bool shot=ChartScreenShot(0,folder+"panel.png",1200,720,ALIGN_RIGHT);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 3;
   FileWriteInteger(status,shot ? 0 : 4);FileWriteInteger(status,count);FileWriteInteger(status,(int)P.rows_ready);FileClose(status);
   return shot ? 0 : 4;
}
