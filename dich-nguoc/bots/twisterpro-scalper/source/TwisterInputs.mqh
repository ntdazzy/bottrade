// Original input names and defaults: twister-inputs-from-log.json.
// Enum type/member names were not recovered; their observed storage is int.
// This is a recovered component, not the complete EA.
#ifndef TWISTER_RECOVERED_INPUTS_MQH
#define TWISTER_RECOVERED_INPUTS_MQH
struct TwisterRecoveredInputs
{
   int InpMagic;
   string TradeComment;
   int BrokerType;
   int EAMode;
   int Mode1Stop;
   bool UseFixedLot;
   double FixedLot;
   double RiskPercent;
   bool UseDD_Protection;
   int MaxConsecLosses;
   double DD_LotMultiplier;
   double MaxDailyDD_Pct;
   bool ShowPanel;
   int PanelX;
   int PanelY;
   bool ShowPnLLabels;
   bool UsePropFirmDelay;
   int PropFirmDelaySec;
   int InpSL_Points;
   int InpTP_Points;
   int InpTSL_Start;
   int InpTSL_Step;
   int InpTSL_Distance;
   bool UseNewsFilter;
   int NewsStopBeforeMin;
   int NewsStopAfterMin;
   string NewsCurrencies;
   bool UseHolidayFilter;
};

void TwisterRecoveredDefaults(TwisterRecoveredInputs &p)
{
   p.InpMagic=31250001;
   p.TradeComment="TwisterPro";
   p.BrokerType=0;
   p.EAMode=1;
   p.Mode1Stop=0;
   p.UseFixedLot=false;
   p.FixedLot=0.01;
   p.RiskPercent=3.0;
   p.UseDD_Protection=false;
   p.MaxConsecLosses=4;
   p.DD_LotMultiplier=0.5;
   p.MaxDailyDD_Pct=0.0;
   p.ShowPanel=true;
   p.PanelX=15;
   p.PanelY=15;
   p.ShowPnLLabels=true;
   p.UsePropFirmDelay=false;
   p.PropFirmDelaySec=30;
   p.InpSL_Points=0;
   p.InpTP_Points=0;
   p.InpTSL_Start=0;
   p.InpTSL_Step=0;
   p.InpTSL_Distance=0;
   p.UseNewsFilter=false;
   p.NewsStopBeforeMin=30;
   p.NewsStopAfterMin=30;
   p.NewsCurrencies="USD";
   p.UseHolidayFilter=true;
}
#endif
