#ifndef BOT1_INITIALIZATION_GATE_MQH
#define BOT1_INITIALIZATION_GATE_MQH

struct Bot1InitializationGateState
{
   uchar active;
   uchar dispatch_mode;
   uchar m1_enabled;
};

// Called before the real authorization check. The account read is retained
// even though its value is not used by this part of OnInit.
void Bot1StartInitializationGate(Bot1InitializationGateState &state)
{
   state.active=0;
   AccountInfoInteger((ENUM_ACCOUNT_INFO_INTEGER)32);
}

// The caller invokes the authorization check between Start and Finish and
// supplies its result. The denial alert remains the caller's responsibility.
bool Bot1FinishInitializationGate(const bool authorized,const int &backtest_speed,
                                  Bot1InitializationGateState &state)
{
   if(!authorized) return false;
   state.active=1;
   if((int)MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6)==1)
   {
      if(backtest_speed==2) { state.dispatch_mode=1;state.m1_enabled=1; }
      else if(backtest_speed==3) { state.dispatch_mode=0;state.m1_enabled=1; }
   }
   return true;
}

#endif
