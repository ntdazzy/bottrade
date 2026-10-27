#property strict
#include "../../Include/bot-cua-toi-3/Bot3PanelCell.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) return;
   string text="panel"; double scale_x=100.0,scale_y=20.0; uchar font_flag=1;
   Bot3CreatePanelCell(10,0,text,0,0,0xc4b741,scale_x,scale_y,font_flag);
}
