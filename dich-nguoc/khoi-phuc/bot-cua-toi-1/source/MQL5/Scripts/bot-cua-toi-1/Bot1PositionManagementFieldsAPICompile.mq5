#property strict
#include "../../Include/bot-cua-toi-1/Bot1PositionManagement.mqh"
void OnStart()
{
   Bot1PositionManagementSettings settings;Bot1PositionManagementState shared;
   Bot1PendingRequestState requests;Bot1TradeSendOptions options;
   ZeroMemory(settings);ZeroMemory(shared);ZeroMemory(requests);ZeroMemory(options);
   double step=0,cache[100][2],volumes[8],levels[100];MqlTick tick;ZeroMemory(tick);
   ArrayInitialize(cache,0.0);ArrayInitialize(volumes,0.0);ArrayInitialize(levels,0.0);
   uint index=0,errors=0;ulong last=0,deviation=0;
   Bot1ManagePositionsFields(false,settings,shared,levels,requests,options,deviation,false,step,cache,volumes,index,errors,last,tick,settings.symbol,settings.magic,settings.unit,settings.stop_distance,settings.take_distance,settings.gap,settings.freeze,settings.finish.high_low_enabled,settings.finish.step_reference,settings.enabled,settings.emergency_offset);
}
