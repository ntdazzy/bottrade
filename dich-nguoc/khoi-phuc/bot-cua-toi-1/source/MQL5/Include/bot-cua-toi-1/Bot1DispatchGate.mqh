#ifndef BOT1_DISPATCH_GATE_MQH
#define BOT1_DISPATCH_GATE_MQH

struct Bot1DispatchGateState
{
   long last_time;
   long last_bar;
};

bool Bot1DispatchGate(const uchar &mode,const uchar &m1,const string &symbol,
                     Bot1DispatchGateState &state)
{
   uchar stop=0;
   uchar bar_mode=0;
   if(mode==1)
   {
      const long now=(long)TimeCurrent();
      bar_mode=mode;
      const long threshold=(long)((ulong)state.last_time+(ulong)bar_mode);
      if(now<=threshold)
      {
         stop=1;
      }
      else
      {
         stop=0;
         const long second=(long)TimeCurrent();
         bar_mode=mode;
         state.last_time=second;
      }
   }
   else
   {
      stop=m1;
      bar_mode=0;
   }
   if(m1!=0 || (bar_mode&1)!=0)
   {
      const long first_bar=(long)iTime(symbol,PERIOD_M1,1);
      if(first_bar>state.last_bar)
      {
         state.last_bar=(long)iTime(symbol,PERIOD_M1,1);
         return false;
      }
   }
   return (stop&1)!=0;
}

#endif
