#property strict
#include "../../Include/bot-cua-toi-1/Bot1PendingDistanceCancel.mqh"
void OnStart()
{
   Bot1PendingRequestState state;Bot1TradeSendOptions options;ZeroMemory(state);ZeroMemory(options);
   string symbol="XAUUSD";int magic=42;double quote=100.,gap=1.;ulong ticket=0;
   Bot1CancelDistantPending(0,true,magic,symbol,quote,gap,ticket,state,options);
}
