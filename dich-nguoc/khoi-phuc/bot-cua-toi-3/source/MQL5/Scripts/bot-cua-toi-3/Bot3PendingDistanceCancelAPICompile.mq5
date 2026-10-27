#property strict
#include "../../Include/bot-cua-toi-3/Bot3PendingDistanceCancel.mqh"
void OnStart()
{
   Bot3PendingRequestState state;Bot3TradeSendOptions options;ZeroMemory(state);ZeroMemory(options);
   string symbol="XAUUSD";int magic=42;double quote=100.,gap=1.;ulong ticket=0;
   Bot3CancelDistantPending(0,true,magic,symbol,quote,gap,ticket,state,options);
}
