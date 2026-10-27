#property strict
#include "../../Include/bot-cua-toi-3/Bot3PositionManagement.mqh"
void OnStart()
{
   Bot3PositionManagementSettings settings;Bot3PositionManagementState shared;
   Bot3PendingRequestState requests;Bot3TradeSendOptions options;
   ZeroMemory(settings);ZeroMemory(shared);ZeroMemory(requests);ZeroMemory(options);
   double step=0,cache[100][2],volumes[9],levels[100];MqlTick tick;ZeroMemory(tick);
   ArrayInitialize(cache,0.0);ArrayInitialize(volumes,0.0);ArrayInitialize(levels,0.0);
   uint index=0,errors=0;ulong last=0,deviation=0;
   Bot3ManagePositionsFields(false,settings,shared,levels,requests,options,deviation,step,cache,volumes,index,errors,last,tick,settings.symbol,settings.magic,settings.unit,settings.stop_distance,settings.take_distance,settings.gap,settings.freeze,settings.finish.high_low_enabled,settings.finish.step_reference);
}
