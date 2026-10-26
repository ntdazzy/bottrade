// Pure scalar runtime-profile check. It does not read market data or send orders.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3RuntimeProfile.mqh"
input string CheckRun="";

union Bot3RuntimeDoubleBits { double d;ulong u; };
ulong Bot3RuntimeBits(const double value)
{
   Bot3RuntimeDoubleBits bits;bits.d=value;return bits.u;
}

void Bot3RuntimeFail(int &fault,const int value)
{
   if(fault==0) fault=value;
}

void Bot3RuntimeSetSentinels(Bot3PreparationInputs &inputs)
{
   inputs.symbol="KEEP.symbol.💰";inputs.comment="KEEP.comment";
   inputs.indicator_timeframe=70001;inputs.indicator_period=70002;inputs.reference=70003.25;
   inputs.variable_distances=7;inputs.adjust_lots=8;
   inputs.entry.confirmation_frame=70011;inputs.entry.entry_frame=70012;
   inputs.entry.older_width=70013;inputs.entry.recent_width=70014;
   inputs.entry.last_shift=70015;inputs.entry.gap_points=70016.25;
   inputs.feature_flag=9;inputs.max_spread=70021.25;inputs.freeze_buffer_flag=10;
   inputs.native_6d250=70031.25;inputs.native_6d258=11;inputs.native_6d260=70032.25;
   inputs.native_6d268=70033.25;inputs.native_6d270=70034.25;inputs.native_6d278=12;
   inputs.native_1d6fa8=70035;inputs.native_1d6fc0=13;inputs.virtual_expiration=14;
   inputs.virtual_stops=15;inputs.native_1d6fe8=70036;inputs.native_1d7178=16;
   inputs.native_6d2a3=17;inputs.buy_offset=70041.25;inputs.sell_offset=70042.25;
   inputs.native_6d2e0=70043;inputs.native_6d2e4=70044;inputs.nearby_radius=70045.25;inputs.expiration_hours=70046;
   inputs.management_timeframe=70047;inputs.stop_distance=70048.25;
   inputs.target_distance=70048.25;inputs.trail_distance=70049.25;
   inputs.trail_start=70050.25;inputs.native_6d368=70051.25;
   inputs.native_6d370=70052.25;inputs.trail_limit=70053.25;
   inputs.trail_step=70054.25;inputs.trigger_distance=70055.25;
   inputs.locked_distance=70056.25;inputs.aux_hour1=18;inputs.aux_scan50=19;
   inputs.aux_older=70057;inputs.aux_recent=70058;inputs.aux_offset=70059.25;
   inputs.native_6d3f8=20;inputs.native_6d3f0=70060.25;inputs.min_change=70061.25;
   inputs.native_6d408=70062.25;inputs.native_1d7138=70063.25;
   inputs.native_6d410=70064.25;inputs.native_1d7130=70065;
   inputs.native_6d418=70066.25;inputs.native_6d420=21;
}

int Bot3RuntimeUntouchedChanged(const Bot3PreparationInputs &before,
                                const Bot3PreparationInputs &after)
{
   if(before.symbol!=after.symbol || before.comment!=after.comment) return 1;
   if(before.reference!=after.reference || before.variable_distances!=after.variable_distances || before.adjust_lots!=after.adjust_lots) return 1;
   if(before.feature_flag!=after.feature_flag || before.max_spread!=after.max_spread || before.freeze_buffer_flag!=after.freeze_buffer_flag) return 1;
   if(before.native_6d250!=after.native_6d250 || before.native_6d258!=after.native_6d258 || before.native_6d260!=after.native_6d260 || before.native_6d268!=after.native_6d268 || before.native_6d270!=after.native_6d270 || before.native_6d278!=after.native_6d278) return 1;
   if(before.native_1d6fa8!=after.native_1d6fa8 || before.native_1d6fc0!=after.native_1d6fc0 || before.virtual_expiration!=after.virtual_expiration || before.virtual_stops!=after.virtual_stops || before.native_1d6fe8!=after.native_1d6fe8 || before.native_1d7178!=after.native_1d7178 || before.native_6d2a3!=after.native_6d2a3) return 1;
   if(before.native_6d3f8!=after.native_6d3f8 || before.native_6d3f0!=after.native_6d3f0 || before.min_change!=after.min_change || before.native_6d408!=after.native_6d408 || before.native_1d7138!=after.native_1d7138 || before.native_6d410!=after.native_6d410 || before.native_1d7130!=after.native_1d7130 || before.native_6d418!=after.native_6d418 || before.native_6d420!=after.native_6d420) return 1;
   return 0;
}

void Bot3RuntimeWriteWords(const int output,const Bot3PreparationInputs &inputs,
                           const Bot3ProfileRuntimeState &state,const int fault,
                           const int untouched)
{
   FileWriteInteger(output,fault);FileWriteInteger(output,untouched);
   FileWriteLong(output,(long)state.random_seed);
   FileWriteLong(output,(long)state.native_6d324);FileWriteLong(output,(long)state.native_6d3c0);
   FileWriteLong(output,(long)inputs.entry.confirmation_frame);FileWriteLong(output,(long)inputs.entry.entry_frame);
   FileWriteLong(output,(long)inputs.entry.older_width);FileWriteLong(output,(long)inputs.entry.recent_width);
   FileWriteLong(output,(long)inputs.entry.last_shift);FileWriteLong(output,(long)Bot3RuntimeBits(inputs.entry.gap_points));
   FileWriteLong(output,(long)Bot3RuntimeBits(inputs.buy_offset));FileWriteLong(output,(long)Bot3RuntimeBits(inputs.sell_offset));
   FileWriteLong(output,(long)Bot3RuntimeBits(inputs.nearby_radius));FileWriteLong(output,(long)inputs.expiration_hours);
   FileWriteLong(output,(long)Bot3RuntimeBits(inputs.stop_distance));FileWriteLong(output,(long)Bot3RuntimeBits(inputs.target_distance));
   FileWriteLong(output,(long)Bot3RuntimeBits(inputs.trail_distance));FileWriteLong(output,(long)Bot3RuntimeBits(inputs.trail_start));
   FileWriteLong(output,(long)Bot3RuntimeBits(inputs.trail_limit));FileWriteLong(output,(long)Bot3RuntimeBits(inputs.trail_step));
   FileWriteLong(output,(long)Bot3RuntimeBits(inputs.native_6d368));FileWriteLong(output,(long)Bot3RuntimeBits(inputs.native_6d370));
   FileWriteLong(output,(long)Bot3RuntimeBits(inputs.trigger_distance));FileWriteLong(output,(long)Bot3RuntimeBits(inputs.locked_distance));
   FileWriteLong(output,(long)inputs.aux_hour1);FileWriteLong(output,(long)inputs.aux_scan50);
   FileWriteLong(output,(long)inputs.aux_older);FileWriteLong(output,(long)inputs.aux_recent);
   FileWriteLong(output,(long)Bot3RuntimeBits(inputs.aux_offset));FileWriteLong(output,(long)inputs.indicator_period);
   FileWriteLong(output,(long)inputs.indicator_timeframe);FileWriteLong(output,(long)inputs.native_6d2e0);
   FileWriteLong(output,(long)inputs.management_timeframe);FileWriteLong(output,(long)inputs.native_6d2e4);
}

int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-runtime-profile\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(input_file==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x52504633 || version!=1 || count<1 || count>10000) { FileClose(input_file);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(input_file);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   int failures=0;
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(input_file);int index=FileReadInteger(input_file);uint seed=(uint)FileReadInteger(input_file);
      Bot3ProfileAdjustments adjustments;
      adjustments.randomization=FileReadDouble(input_file);adjustments.price_delta=FileReadDouble(input_file);
      adjustments.stop_delta=FileReadDouble(input_file);adjustments.target_delta=FileReadDouble(input_file);
      adjustments.trail_delta=FileReadDouble(input_file);adjustments.aux_delta=FileReadDouble(input_file);
      adjustments.lock_delta=FileReadDouble(input_file);
      Bot3PreparationInputs before,inputs;ZeroMemory(before);Bot3RuntimeSetSentinels(before);inputs=before;
      Bot3ProfileRuntimeState state;ZeroMemory(state);state.random_seed=seed;state.native_6d324=70071;state.native_6d3c0=70072;
      int fault=0;
      Bot3LoadRuntimeProfile((uint)index,adjustments,inputs,state);
      int untouched=Bot3RuntimeUntouchedChanged(before,inputs);
      if(untouched!=0) failures++;
      FileWriteInteger(output,id);Bot3RuntimeWriteWords(output,inputs,state,fault,untouched);
   }
   FileClose(input_file);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status!=INVALID_HANDLE) { FileWriteInteger(status,failures);FileWriteInteger(status,count);FileClose(status); }
   return failures==0 ? 0 : 1;
}
