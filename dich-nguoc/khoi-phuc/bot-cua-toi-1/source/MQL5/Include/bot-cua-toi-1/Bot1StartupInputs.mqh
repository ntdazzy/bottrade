#ifndef BOT1_STARTUP_INPUTS_MQH
#define BOT1_STARTUP_INPUTS_MQH
#include "Bot1Preparation.mqh"

// Call when loading program state, before the first preparation.
// User inputs and the current symbol belong to their own bindings.
void Bot1InitializeStartupInputs(Bot1PreparationInputs &inputs)
{
   inputs.indicator_period=30;
   inputs.indicator_day=1;
   inputs.reference=0.0;
   inputs.feature_flag=1;
   inputs.freeze_buffer_flag=1;
   inputs.entry.confirmation_frame=0;
   inputs.entry.hour1_flag=1;
   inputs.entry.older_width=10;
   inputs.entry.recent_width=3;
   inputs.entry.last_shift=120;
   inputs.entry.gap_points=30.0;
   inputs.buy_offset=0.5;
   inputs.sell_offset=0.0;
   inputs.nearby_radius=1.0;
   inputs.expiration_hours=24;
   inputs.stop_distance=50.0;
   inputs.target_distance=100.0;
   inputs.trail_distance=10.0;
   inputs.trail_start=10.0;
   inputs.trail_limit=100.0;
   inputs.trail_step=0.40000000000000002;
   inputs.aux_hour1=0;
   inputs.aux_scan50=0;
   inputs.aux_older=0;
   inputs.aux_recent=0;
   inputs.aux_offset=0.0;
   inputs.min_change=1.0;
   inputs.native_62218=5000.0;
   inputs.native_62220=1;
   inputs.native_62228=40.0;
   inputs.native_62230=10.0;
   inputs.native_62238=30.0;
   inputs.native_62240=1;
   inputs.native_62268=1;
   inputs.native_622a8=1;
   inputs.native_622ec=1;
   inputs.native_622f0=1;
   inputs.native_62390=1.0;
   inputs.native_62398=1;
   inputs.native_623a8=5.0;
   inputs.native_623b0=99.0;
   inputs.comment="";
}
#endif
