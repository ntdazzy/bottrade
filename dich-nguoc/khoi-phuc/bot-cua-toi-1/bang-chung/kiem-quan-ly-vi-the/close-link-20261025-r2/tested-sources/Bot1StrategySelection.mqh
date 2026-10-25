// Strategy enable gates from native RVA 0x10f60.
// The native code only compares each input with zero and branches; it does
// not rewrite the input or another state value in this bounded part.
#ifndef BOT1_STRATEGY_SELECTION_MQH
#define BOT1_STRATEGY_SELECTION_MQH

struct Bot1StrategySelectionInput
{
   bool run_strategy_a;
   bool run_strategy_b;
   bool run_strategy_c;
   bool run_strategy_d;
   bool run_strategy_e;
   bool run_strategy_f;
   bool run_strategy_g;
   bool run_strategy_h;
};

struct Bot1StrategySelectionState
{
   uint enabled_mask;
};

void Bot1SelectStrategies(const Bot1StrategySelectionInput &settings,
                          Bot1StrategySelectionState &state)
{
   state.enabled_mask=0;
   if(settings.run_strategy_a) state.enabled_mask|=(uint)1;
   if(settings.run_strategy_b) state.enabled_mask|=(uint)2;
   if(settings.run_strategy_c) state.enabled_mask|=(uint)4;
   if(settings.run_strategy_d) state.enabled_mask|=(uint)8;
   if(settings.run_strategy_e) state.enabled_mask|=(uint)16;
   if(settings.run_strategy_f) state.enabled_mask|=(uint)32;
   if(settings.run_strategy_g) state.enabled_mask|=(uint)64;
   if(settings.run_strategy_h) state.enabled_mask|=(uint)128;
}

#endif
