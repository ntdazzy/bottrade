// Pure scalar runtime-profile check. It does not read market data or send orders.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1RuntimeProfile.mqh"
input string CheckRun="";

union Bot1RuntimeDoubleBits { double d;ulong u; };
ulong Bot1RuntimeBits(const double value)
{
   Bot1RuntimeDoubleBits bits;bits.d=value;return bits.u;
}

void Bot1RuntimeSetSentinels(Bot1DistanceInputs &inputs)
{
   inputs.reference=70001.25;inputs.use_variable=true;inputs.adjust_lots=true;inputs.max_spread=70002.25;
   inputs.feature_flag=1;inputs.freeze_buffer_flag=1;inputs.virtual_expiration=1;inputs.min_change=70003.25;
   inputs.entry.confirmation_frame=70011;inputs.entry.hour1_flag=70012;inputs.entry.older_width=70013;
   inputs.entry.recent_width=70014;inputs.entry.last_shift=70015;inputs.entry.gap_points=70016.25;
   inputs.buy_offset=70021.25;inputs.sell_offset=70022.25;inputs.nearby_radius=70023.25;
   inputs.expiration_hours=70024;inputs.stop_distance=70025.25;inputs.target_distance=70026.25;
   inputs.trail_distance=70027.25;inputs.trail_start=70028.25;inputs.trail_limit=70029.25;
   inputs.trail_step=70030.25;inputs.aux_hour1=1;inputs.aux_scan50=1;
   inputs.aux_older=70031;inputs.aux_recent=70032;inputs.aux_offset=70033.25;
}

int Bot1RuntimeUntouchedChanged(const Bot1DistanceInputs &before,const Bot1DistanceInputs &after)
{
   if(before.use_variable!=after.use_variable || before.adjust_lots!=after.adjust_lots || before.max_spread!=after.max_spread) return 1;
   if(before.feature_flag!=after.feature_flag || before.freeze_buffer_flag!=after.freeze_buffer_flag || before.virtual_expiration!=after.virtual_expiration || before.min_change!=after.min_change) return 1;
   return 0;
}

void Bot1RuntimeWriteWords(const int output,const Bot1DistanceInputs &inputs,
                           const Bot1ProfileRuntimeState &state,const int fault,
                           const int untouched)
{
   FileWriteInteger(output,fault);FileWriteInteger(output,untouched);
   FileWriteLong(output,(long)state.random_seed);
   FileWriteLong(output,(long)Bot1RuntimeBits(inputs.reference));
   FileWriteLong(output,(long)inputs.entry.confirmation_frame);FileWriteLong(output,(long)inputs.entry.hour1_flag);
   FileWriteLong(output,(long)inputs.entry.older_width);FileWriteLong(output,(long)inputs.entry.recent_width);
   FileWriteLong(output,(long)inputs.entry.last_shift);FileWriteLong(output,(long)Bot1RuntimeBits(inputs.entry.gap_points));
   FileWriteLong(output,(long)Bot1RuntimeBits(inputs.buy_offset));FileWriteLong(output,(long)Bot1RuntimeBits(inputs.sell_offset));
   FileWriteLong(output,(long)Bot1RuntimeBits(inputs.nearby_radius));FileWriteLong(output,(long)inputs.expiration_hours);
   FileWriteLong(output,(long)Bot1RuntimeBits(inputs.stop_distance));FileWriteLong(output,(long)Bot1RuntimeBits(inputs.target_distance));
   FileWriteLong(output,(long)Bot1RuntimeBits(inputs.trail_distance));FileWriteLong(output,(long)Bot1RuntimeBits(inputs.trail_start));
   FileWriteLong(output,(long)Bot1RuntimeBits(inputs.trail_limit));FileWriteLong(output,(long)Bot1RuntimeBits(inputs.trail_step));
   FileWriteLong(output,(long)inputs.aux_hour1);FileWriteLong(output,(long)inputs.aux_scan50);
   FileWriteLong(output,(long)inputs.aux_older);FileWriteLong(output,(long)inputs.aux_recent);
   FileWriteLong(output,(long)Bot1RuntimeBits(inputs.aux_offset));
}

int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot1-runtime-profile\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(input_file==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x52504631 || version!=1 || count<1 || count>10000) { FileClose(input_file);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(input_file);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   int failures=0;
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(input_file),index=FileReadInteger(input_file),hl=FileReadInteger(input_file);
      uint seed=(uint)FileReadInteger(input_file);
      Bot1ProfileAdjustments adjustments;
      adjustments.randomization=FileReadDouble(input_file);adjustments.price_delta=FileReadDouble(input_file);
      adjustments.stop_delta=FileReadDouble(input_file);adjustments.target_delta=FileReadDouble(input_file);
      adjustments.trail_delta=FileReadDouble(input_file);
      Bot1DistanceInputs before,inputs;ZeroMemory(before);Bot1RuntimeSetSentinels(before);inputs=before;
      Bot1ProfileRuntimeState state;ZeroMemory(state);state.random_seed=seed;
      Bot1LoadRuntimeProfile((uint)index,hl!=0,adjustments,inputs,state);
      int untouched=Bot1RuntimeUntouchedChanged(before,inputs);if(untouched!=0) failures++;
      FileWriteInteger(output,id);Bot1RuntimeWriteWords(output,inputs,state,0,untouched);
   }
   FileClose(input_file);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status!=INVALID_HANDLE) { FileWriteInteger(status,failures);FileWriteInteger(status,count);FileClose(status); }
   return failures==0 ? 0 : 1;
}
