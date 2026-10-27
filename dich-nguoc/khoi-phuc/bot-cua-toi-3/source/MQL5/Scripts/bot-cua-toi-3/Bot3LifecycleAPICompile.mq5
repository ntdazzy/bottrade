#property strict
#include "../../Include/bot-cua-toi-3/Bot3Lifecycle.mqh"
input uchar Extended=0;
input int IndicatorHandle=-1;
void OnStart() { int handle=IndicatorHandle; Bot3DeinitializePanel(Extended,handle); }
