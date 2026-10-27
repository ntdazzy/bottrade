#property strict
#include "../../Include/bot-cua-toi-1/Bot1Lifecycle.mqh"
input bool Extended=false;
input int IndicatorHandle=-1;
void OnStart() { int handle=IndicatorHandle; Bot1DeinitializePanel(Extended,handle); }
