#ifndef BOT3_STARTUP_SELECTION_CONTEXT_MQH
#define BOT3_STARTUP_SELECTION_CONTEXT_MQH
#include "Bot3AmericanDST.mqh"
#include "Bot3VolumeCurrency.mqh"
#include "Bot3StartupContext.mqh"

// OnInit 0x3840..0x4580. Arrays have the original fixed widths:
// thresholds[3], manual[9], enabled[9]. Preserve raw enabled bytes.
void Bot3InitializeStartupSelectionContext(const int &winter_hours,const int &summer_hours,
   long &adjusted_time,const int &frequency,const int &risk,const uchar &variable_values,
   const uchar &thresholds[],const uchar &manual[],uchar &enabled[],double &divisor,
   const string &chart_symbol,Bot3StrategyContextInputs &context_inputs,
   Bot3StrategyContextState &context,Bot3PreparationInputs &preparation_inputs,
   Bot3StrategyHistoryCache &history,Bot3PanelCreationState &panel,
   Bot3DailyLossState &daily,Bot3StartupContextState &state)
{
   const bool summer=Bot3AmericanDST();
   const long now=(long)TimeCurrent();
   const int seconds=(int)((uint)(summer ? summer_hours : winter_hours)*(uint)3600);
   adjusted_time=(long)((ulong)now-(ulong)(long)seconds);
   int mode=frequency;
   if(mode==5 && risk==1234)
   {
      const double balance=AccountInfoDouble(ACCOUNT_BALANCE);
      const double converted=Bot3VolumeCurrency(balance,context_inputs.symbol_suffix,true);
      const double drawdown=panel.allowed_dd;
      const bool upper_enabled=thresholds[2]!=0;
      const double budget=(drawdown/100.0)*converted;
      if(budget>(upper_enabled ? 810.0 : 0.0)) mode=3;
      else if(budget>(thresholds[1]!=0 ? 560.0 : 0.0)) mode=2;
      else if(budget>(thresholds[0]!=0 ? 330.0 : 0.0)) mode=1;
      else mode=0;
   }
   panel.frequency=mode;
   if(mode>=0 && mode<=4)
   {
      enabled[4]=(uchar)(mode>=2);
      enabled[5]=(uchar)(mode>=1);
      enabled[3]=(uchar)(mode>=1);
      enabled[8]=(uchar)(mode>=3);
      enabled[7]=(uchar)(mode>=2);
      enabled[6]=(uchar)(mode==4);
      if(mode==0) divisor=variable_values!=0 ? 3.0 : 2.4;
      else if(mode==1) divisor=variable_values!=0 ? 4.0 : 3.4;
      else if(mode==2) divisor=variable_values!=0 ? 5.0 : 4.1;
      else if(mode==3) divisor=variable_values!=0 ? 5.6 : 4.8;
      else divisor=variable_values!=0 ? 6.0 : 5.1;
   }
   else if(mode==6)
   {
      enabled[0]=manual[0];enabled[1]=manual[1];enabled[2]=manual[2];
      enabled[3]=manual[3];enabled[5]=manual[4];enabled[4]=manual[5];
      enabled[7]=manual[6];enabled[8]=manual[7];enabled[6]=manual[8];
   }
   Bot3InitializeStartupContext(chart_symbol,context_inputs,context,preparation_inputs,
                                 history,panel,daily,state);
}
#endif
