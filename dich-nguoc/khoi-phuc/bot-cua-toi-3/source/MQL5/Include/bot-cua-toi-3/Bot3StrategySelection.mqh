// Strategy selector from native RVAs 0x3892..0x3ce6 and 0x18c50..0x19084.
// Currency conversion and account reading are inputs to this bounded part.
#ifndef BOT3_STRATEGY_SELECTION_MQH
#define BOT3_STRATEGY_SELECTION_MQH

struct Bot3StrategySelectionInput
{
   int trade_frequency;
   int risk;
   double max_allowed_dd;
   double converted_balance;
   bool use_variable_values;
   uint manual_menu_mask;
   uint initial_enabled_mask;
   int initial_mode;
   double initial_divisor;
   uint threshold_flags;
};

struct Bot3StrategySelectionState
{
   int mode;
   uint enabled_mask;
   double divisor;
};

void Bot3SelectStrategies(const Bot3StrategySelectionInput &settings,
                          Bot3StrategySelectionState &state)
{
   int mode=settings.trade_frequency;
   state.mode=settings.initial_mode;
   state.enabled_mask=settings.initial_enabled_mask;
   state.divisor=settings.initial_divisor;

   if(mode==5 && settings.risk==1234)
   {
      double budget=(settings.max_allowed_dd/100.0)*settings.converted_balance;
      if(budget>((settings.threshold_flags&4)!=0 ? 810.0 : 0.0)) mode=3;
      else if(budget>((settings.threshold_flags&2)!=0 ? 560.0 : 0.0)) mode=2;
      else if(budget>((settings.threshold_flags&1)!=0 ? 330.0 : 0.0)) mode=1;
      else mode=0;
   }

   if(mode>=0 && mode<=4)
   {
      uint extras=0;
      if(mode==1) extras=(uint)8|(uint)32;
      else if(mode==2) extras=(uint)8|(uint)16|(uint)32|(uint)128;
      else if(mode==3) extras=(uint)8|(uint)16|(uint)32|(uint)128|(uint)256;
      else if(mode==4) extras=(uint)8|(uint)16|(uint)32|(uint)64|(uint)128|(uint)256;
      state.enabled_mask=(state.enabled_mask&7)|extras;
      if(mode==0) { state.divisor=settings.use_variable_values ? 3.0 : 2.4; }
      else if(mode==1) { state.divisor=settings.use_variable_values ? 4.0 : 3.4; }
      else if(mode==2) { state.divisor=settings.use_variable_values ? 5.0 : 4.1; }
      else if(mode==3) { state.divisor=settings.use_variable_values ? 5.6 : 4.8; }
      else { state.divisor=settings.use_variable_values ? 6.0 : 5.1; }
   }
   else if(mode==6)
   {
      // These mask bits are native flag slots, not evaluator indices.
      int menu_to_internal[9]={0,1,2,3,5,4,7,8,6};
      state.enabled_mask=0;
      for(int menu=0;menu<9;menu++)
         if((settings.manual_menu_mask&((uint)1<<menu))!=0)
            state.enabled_mask|=((uint)1<<menu_to_internal[menu]);
   }
   state.mode=mode;
}

#endif
