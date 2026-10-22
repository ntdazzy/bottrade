// Recovered input-derived settings from native function RVA 0x18c0.
// v_<hex> names identify original storage RVAs, not author variable names.
// Does not implement indicator creation, trading, news, or the display.
#ifndef TWISTER_RECOVERED_SETTINGS_MQH
#define TWISTER_RECOVERED_SETTINGS_MQH
#include "TwisterInputs.mqh"

struct TwisterRecoveredSettings
{
   bool v_22294;
   long v_22295;
   ulong v_2229d;
   int v_222a5;
   bool v_2236c;
   int v_22370;
   bool v_22374;
   bool v_22375;
   double v_22378;
   double v_22380;
   double v_22388;
   double v_22390;
   int v_22398; // Stop distance in points.
   int v_2239c; // Target distance in points.
   int v_223a0;
   bool v_223a4;
   int v_223a8; // Trailing activation, points.
   int v_223ac; // Trailing step, points.
   int v_223b0; // Trailing distance, points.
   bool v_223b4;
   bool v_223b5;
   bool v_223b6;
   bool v_223b7;
   double v_223b8;
   bool v_223c0;
   bool v_223c1;
   int v_223c4;
   int v_223c8;
   bool v_225ad;
   double v_225b0;
   double v_225b8;
   bool v_225c0;
   int v_225c4;
   double v_225c8;
   double v_225d0;
   double v_22630;
   double v_22638;
   double v_22640;
   double v_22648;
   double v_22650;
};

void TwisterRecoverSettings(const TwisterRecoveredInputs &p,const bool tester,
                           TwisterRecoveredSettings &s)
{
   // Constant bytes at RVAs 0x1ba90..0x1baa8: 1000, 0.01, 100, 1.
   s.v_225ad=p.UseFixedLot;
   s.v_225b0=p.FixedLot<0.01 ? 0.01 : (p.FixedLot<=1000.0 ? p.FixedLot : 1000.0);
   s.v_225b8=p.RiskPercent<0.01 ? 0.01 : (p.RiskPercent<=100.0 ? p.RiskPercent : 100.0);
   s.v_225c0=p.UseDD_Protection;
   s.v_225c4=p.MaxConsecLosses<100 ? p.MaxConsecLosses : 100;
   if(s.v_225c4<2) s.v_225c4=1;
   s.v_225c8=p.DD_LotMultiplier<0.01 ? 0.01 :
              (p.DD_LotMultiplier<=1.0 ? p.DD_LotMultiplier : 1.0);
   s.v_225d0=p.MaxDailyDD_Pct<0.0 ? 0.0 :
              (p.MaxDailyDD_Pct<=100.0 ? p.MaxDailyDD_Pct : 100.0);
   if(p.EAMode==2)
   {
      s.v_223c4=16;
      s.v_223b0=32;
      s.v_223ac=67;
      s.v_223a8=131;
      s.v_223a0=186;
      s.v_22398=302;
      s.v_22370=1;
   }
   else
   {
      s.v_223c4=18;
      s.v_223ac=30;
      s.v_223a8=60;
      s.v_223a0=164;
      s.v_223b0=30;
      s.v_22398=p.Mode1Stop==1 ? 220 : 850;
      s.v_22370=5;
   }
   s.v_2236c=true;
   s.v_22378=658.0;
   s.v_22380=0.6;
   s.v_22388=123.0;
   s.v_22390=2.1;
   s.v_22374=true;
   s.v_223a4=true;
   s.v_2239c=3164;
   s.v_22375=true;
   s.v_223b4=true;
   s.v_223c0=true;
   s.v_223b5=true;
   s.v_223c1=true;
   s.v_223b6=true;
   s.v_223b8=0.62;
   s.v_223b7=true;
   s.v_223c8=120;
   int scale=1;
   if(p.BrokerType==1)
   {
      if(p.EAMode==1)
      {
         s.v_223ac=460;
         s.v_223a8=360;
         s.v_22398=p.Mode1Stop==1 ? 2200 : 8500;
         s.v_223b0=390;
      }
      else
      {
         s.v_223b0=320;
         s.v_223ac=670;
         s.v_223a8=1310;
         s.v_22398=3020;
      }
      s.v_2239c=31640;
      s.v_223c8=1200;
      s.v_22378=6580.0;
      s.v_22388=1230.0;
      scale=10;
   }
   if(p.InpSL_Points>0)
      s.v_22398=(p.InpSL_Points<1000000 ? p.InpSL_Points : 1000000)*scale;
   if(p.InpTP_Points>0)
      s.v_2239c=(p.InpTP_Points<1000000 ? p.InpTP_Points : 1000000)*scale;
   if(p.InpTSL_Start>0)
      s.v_223a8=(p.InpTSL_Start<1000000 ? p.InpTSL_Start : 1000000)*scale;
   if(p.InpTSL_Step>0)
      s.v_223ac=(p.InpTSL_Step<1000000 ? p.InpTSL_Step : 1000000)*scale;
   if(p.InpTSL_Distance>0)
      s.v_223b0=(p.InpTSL_Distance<1000000 ? p.InpTSL_Distance : 1000000)*scale;
   s.v_22295=(long)p.InpMagic;
   s.v_2229d=(p.BrokerType==1 && !tester) ? 1040 : 104;
   s.v_22294=false;
   s.v_222a5=0;
}

// Original calls this only after successful symbol/indicator validation.
void TwisterRecoverPriceDistances(const double point,TwisterRecoveredSettings &s)
{
   s.v_22630=(double)s.v_22398*point;
   s.v_22638=(double)s.v_2239c*point;
   s.v_22640=(double)s.v_223a8*point;
   s.v_22648=(double)s.v_223ac*point;
   s.v_22650=(double)s.v_223b0*point;
}
#endif
