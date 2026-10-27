#property strict
#include "../../Include/bot-cua-toi-3/Bot3Lifecycle.mqh"
input bool Extended=false;
input int IndicatorHandle=-1;
void OnStart() { int handle=IndicatorHandle; Bot3DeinitializePanel(Extended,handle); }
