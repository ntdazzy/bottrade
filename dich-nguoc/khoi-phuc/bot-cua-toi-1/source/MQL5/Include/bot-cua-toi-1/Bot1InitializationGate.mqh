#ifndef BOT1_INITIALIZATION_GATE_MQH
#define BOT1_INITIALIZATION_GATE_MQH

struct Bot1InitializationGateState
{
   uchar active;
   uchar dispatch_mode;
   uchar m1_enabled;
};

// The authorization result is supplied by the caller. A failed result keeps
// the native inactive state and never turns the gate on.
bool Bot1InitializeGate(const bool authorized,const int tester_mode,const int backtest_speed,
                        Bot1InitializationGateState &state)
{
   state.active=0;
   if(!authorized) return false;
   state.active=1;
   if(tester_mode==1)
   {
      if(backtest_speed==2) state.dispatch_mode=1;
      else if(backtest_speed==3) state.dispatch_mode=0;
      state.m1_enabled=1;
   }
   return true;
}

#endif
