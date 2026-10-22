#property strict
#property version "1.00"
#property description "Recovered tester trading path; full UI/live behavior still under reconstruction."
#include <Trade/Trade.mqh>
#include "TwisterSettings.mqh"
#include "TwisterFilters.mqh"

// Original input names; original enum member names are not available.
input int InpMagic=31250001;
input string TradeComment="TwisterPro";
input int BrokerType=0;
input int EAMode=1;
input int Mode1Stop=0;
input bool UseFixedLot=false;
input double FixedLot=0.01;
input double RiskPercent=3.0;
input bool UseDD_Protection=false;
input int MaxConsecLosses=4;
input double DD_LotMultiplier=0.5;
input double MaxDailyDD_Pct=0.0;
input bool ShowPanel=true;
input int PanelX=15;
input int PanelY=15;
input bool ShowPnLLabels=true;
input bool UsePropFirmDelay=false;
input int PropFirmDelaySec=30;
input int InpSL_Points=0;
input int InpTP_Points=0;
input int InpTSL_Start=0;
input int InpTSL_Step=0;
input int InpTSL_Distance=0;
input bool UseNewsFilter=false;
input int NewsStopBeforeMin=30;
input int NewsStopAfterMin=30;
input string NewsCurrencies="USD";
input bool UseHolidayFilter=true;

TwisterRecoveredInputs r_inputs;
TwisterRecoveredSettings r_settings;
CTrade r_trade;

void ReadRecoveredInputs()
{
   r_inputs.InpMagic=InpMagic;
   r_inputs.TradeComment=TradeComment;
   r_inputs.BrokerType=BrokerType;
   r_inputs.EAMode=EAMode;
   r_inputs.Mode1Stop=Mode1Stop;
   r_inputs.UseFixedLot=UseFixedLot;
   r_inputs.FixedLot=FixedLot;
   r_inputs.RiskPercent=RiskPercent;
   r_inputs.UseDD_Protection=UseDD_Protection;
   r_inputs.MaxConsecLosses=MaxConsecLosses;
   r_inputs.DD_LotMultiplier=DD_LotMultiplier;
   r_inputs.MaxDailyDD_Pct=MaxDailyDD_Pct;
   r_inputs.ShowPanel=ShowPanel;
   r_inputs.PanelX=PanelX;
   r_inputs.PanelY=PanelY;
   r_inputs.ShowPnLLabels=ShowPnLLabels;
   r_inputs.UsePropFirmDelay=UsePropFirmDelay;
   r_inputs.PropFirmDelaySec=PropFirmDelaySec;
   r_inputs.InpSL_Points=InpSL_Points;
   r_inputs.InpTP_Points=InpTP_Points;
   r_inputs.InpTSL_Start=InpTSL_Start;
   r_inputs.InpTSL_Step=InpTSL_Step;
   r_inputs.InpTSL_Distance=InpTSL_Distance;
   r_inputs.UseNewsFilter=UseNewsFilter;
   r_inputs.NewsStopBeforeMin=NewsStopBeforeMin;
   r_inputs.NewsStopAfterMin=NewsStopAfterMin;
   r_inputs.NewsCurrencies=NewsCurrencies;
   r_inputs.UseHolidayFilter=UseHolidayFilter;
}

// These descriptive names are reconstruction names, not recovered author names.
bool r_ready=false;
bool r_tester=false;
bool r_friday_lock=false;
bool r_dd_active=false;
double r_point=0.0,r_gap=0.0,r_tick_size=0.0;
double r_volume_step=0.0,r_volume_min=0.0,r_volume_max=0.0,r_volume_limit=0.0;
int r_digits=0,r_day_orders=0,r_loss_streak=0,r_pause_bars=0;
int r_atr=INVALID_HANDLE,r_fast=INVALID_HANDLE,r_slow=INVALID_HANDLE;
int r_long_fast=INVALID_HANDLE,r_long_slow=INVALID_HANDLE;
double r_atr_values[],r_fast_values[],r_slow_values[],r_long_fast_values[],r_long_slow_values[];
datetime r_day_time=0,r_bar_time=0,r_level_time=0;
double r_day_balance=0.0,r_high_level=-2.0,r_low_level=-2.0;
ulong r_delay_tickets[50];
datetime r_delay_times[50];
int r_delay_count=0;

ENUM_TIMEFRAMES RecoveredTimeframe()
{
   return r_settings.v_2236c ? PERIOD_M15 : PERIOD_CURRENT;
}

// RVA 0xa930. Only the first trading session is queried by the original.
bool RecoveredCanTrade()
{
   int mode=(int)SymbolInfoInteger(_Symbol,SYMBOL_TRADE_MODE);
   if(mode==0 || mode==3) return false;
   datetime now=TimeCurrent();
   MqlDateTime dt;
   TimeToStruct(now,dt);
   if(dt.day_of_week==0 || dt.day_of_week==6) return false;
   if((dt.day_of_week==1 && dt.hour<=0) || (dt.day_of_week==5 && dt.hour>=22)) return false;
   datetime from=0,to=0;
   if(SymbolInfoSessionTrade(_Symbol,(ENUM_DAY_OF_WEEK)dt.day_of_week,0,from,to) && to>0)
   {
      datetime midnight=(now/86400)*86400;
      if(now>=midnight+to || now<midnight+from) return false;
   }
   if(r_tester) return true;
   if(!TerminalInfoInteger(TERMINAL_TRADE_ALLOWED) || !MQLInfoInteger(MQL_TRADE_ALLOWED) ||
      !AccountInfoInteger(ACCOUNT_TRADE_ALLOWED)) return false;
   double bid=SymbolInfoDouble(_Symbol,SYMBOL_BID),ask=SymbolInfoDouble(_Symbol,SYMBOL_ASK);
   return bid>0.0 && ask>0.0 && bid<=ask;
}

// RVA 0xab80. Preserve the exact dates stored in the original.
bool RecoveredHoliday()
{
   if(!UseHolidayFilter) return false;
   MqlDateTime dt;
   TimeToStruct(TimeCurrent(),dt);
   int y=dt.year,m=dt.mon,d=dt.day;
   if(m==1 && (d==1 || d==2)) return true;
   if((y==2026 && m==1 && d==19) || (y==2027 && m==1 && d==18)) return true;
   if((y==2026 && m==2 && d==16) || (y==2027 && m==2 && d==15)) return true;
   if((y==2025 && m==4 && d==18) || (y==2026 && m==4 && d==3) ||
      (y==2027 && m==3 && d==26)) return true;
   if((y==2025 && m==5 && d==26) || (y==2026 && m==5 && d==25) ||
      (y==2027 && m==5 && d==31)) return true;
   if(m==6 && (d==19 || d==20)) return true;
   if(m==7 && d>=3 && d<=5) return true;
   if((y==2025 && m==9 && d==1) || (y==2026 && m==9 && d==7) ||
      (y==2027 && m==9 && d==6)) return true;
   if(m==11 && ((y==2025 && (d==27 || d==28)) ||
               (y==2026 && (d==26 || d==27)) ||
               (y==2027 && (d==25 || d==26)))) return true;
   return m==12 && (d==24 || d==25 || d==26 || d==31);
}

// RVAs 0x175c0 and 0x17770. Rounding order is intentional.
bool RecoveredNormalizeVolume(double &volume)
{
   if(r_volume_step<=0.0 || r_volume_min<=0.0 || r_volume_max<=0.0) return false;
   volume=MathMin(r_volume_max,MathMax(r_volume_min,volume));
   volume=NormalizeDouble(MathFloor(volume/r_volume_step)*r_volume_step,2);
   return volume>=r_volume_min;
}

void RecoveredNormalizePrice(double &price)
{
   if(price<=0.0) return;
   if(r_tick_size>0.0) price=MathRound(price/r_tick_size)*r_tick_size;
   price=NormalizeDouble(price,r_digits);
}

// RVA 0x16270. The original calculates the one-step margin using BUY even for SELL.
double RecoveredLots(const double distance,const ENUM_ORDER_TYPE direction)
{
   if(direction!=ORDER_TYPE_BUY && direction!=ORDER_TYPE_SELL) return 0.0;
   double minimum=SymbolInfoDouble(_Symbol,SYMBOL_VOLUME_MIN);
   double maximum=SymbolInfoDouble(_Symbol,SYMBOL_VOLUME_MAX);
   double limit=SymbolInfoDouble(_Symbol,SYMBOL_VOLUME_LIMIT);
   if(limit>0.0) maximum=MathMin(maximum,limit);
   double step=SymbolInfoDouble(_Symbol,SYMBOL_VOLUME_STEP);
   double lots=r_settings.v_225b0;
   if(!r_settings.v_225ad)
   {
      if(distance<=0.0) return minimum;
      double risk=AccountInfoDouble(ACCOUNT_BALANCE)*r_settings.v_225b8;
      double tick_size=SymbolInfoDouble(_Symbol,SYMBOL_TRADE_TICK_SIZE);
      double tick_value=SymbolInfoDouble(_Symbol,SYMBOL_TRADE_TICK_VALUE);
      if(tick_size<=0.0 || tick_value<=0.0 || step<=0.0) return minimum;
      double risk_per_step=(distance/tick_size)*tick_value*step;
      if(risk_per_step<=0.0) return minimum;
      lots=MathFloor((risk/100.0)/risk_per_step)*step;
      lots=MathMin(maximum,MathMax(minimum,lots));
   }
   double multiplier=(r_dd_active && r_settings.v_225c0) ? r_settings.v_225c8 : 1.0;
   lots=MathMin(maximum,MathMax(minimum,lots*multiplier));
   lots=MathFloor(lots/step)*step;
   double free_margin=AccountInfoDouble(ACCOUNT_MARGIN_FREE),step_margin=0.0;
   if(OrderCalcMargin(ORDER_TYPE_BUY,_Symbol,step,SymbolInfoDouble(_Symbol,SYMBOL_ASK),step_margin) && step_margin>0.0)
   {
      double allowed=MathMax(minimum,MathFloor((free_margin*0.9)/step_margin)*step);
      lots=MathMin(lots,allowed);
   }
   lots=MathMax(minimum,MathMin(maximum,lots));
   lots=MathFloor(lots/step)*step;
   if(r_tester && lots>=100.0) lots=100.0;
   lots=MathFloor(lots/step)*step;
   return NormalizeDouble(MathMax(minimum,lots),2);
}

// RVA 0x18150.
bool RecoveredStopsAllowed(const ENUM_POSITION_TYPE direction,const double sl,const double tp)
{
   double gap=(double)(MathMax(SymbolInfoInteger(_Symbol,SYMBOL_TRADE_STOPS_LEVEL),
                              SymbolInfoInteger(_Symbol,SYMBOL_TRADE_FREEZE_LEVEL))+2)*r_point;
   double bid=SymbolInfoDouble(_Symbol,SYMBOL_BID),ask=SymbolInfoDouble(_Symbol,SYMBOL_ASK);
   if(direction==POSITION_TYPE_BUY)
      return (sl<=0.0 || bid-sl>=gap) && (tp<=0.0 || tp-bid>=gap);
   return (sl<=0.0 || sl-ask>=gap) && (tp<=0.0 || ask-tp>=gap);
}

// RVA 0xe3c0. This can restore a looser SL after a fill; preserve that behavior.
bool RecoveredAlignAfterFill(const ulong ticket,const double fill,const ENUM_DEAL_TYPE direction)
{
   if(ticket==0 || fill<=0.0) return true;
   if(!PositionSelectByTicket(ticket)) return false;
   double sl=PositionGetDouble(POSITION_SL),tp=PositionGetDouble(POSITION_TP);
   double open=PositionGetDouble(POSITION_PRICE_OPEN);
   if(sl<=0.0 || (direction!=DEAL_TYPE_BUY && direction!=DEAL_TYPE_SELL)) return true;
   double target=(direction==DEAL_TYPE_BUY) ? fill-r_settings.v_22630 : fill+r_settings.v_22630;
   RecoveredNormalizePrice(target);
   if(target<=0.0 || MathAbs(target-sl)<=r_point) return true;
   if(direction==DEAL_TYPE_BUY)
   {
      if(target>=open || (tp>0.0 && target>=tp)) return true;
   }
   else if(target<=open || (tp>0.0 && target<=tp)) return true;
   double gap=((double)MathMax(SymbolInfoInteger(_Symbol,SYMBOL_TRADE_STOPS_LEVEL),
                              SymbolInfoInteger(_Symbol,SYMBOL_TRADE_FREEZE_LEVEL))+10.0)*r_point;
   double distance=(direction==DEAL_TYPE_BUY) ? SymbolInfoDouble(_Symbol,SYMBOL_BID)-target :
                                               target-SymbolInfoDouble(_Symbol,SYMBOL_ASK);
   if(distance<gap) return true;
   if(!RecoveredStopsAllowed((ENUM_POSITION_TYPE)PositionGetInteger(POSITION_TYPE),target,tp)) return true;
   if(r_trade.PositionModify(ticket,target,tp)) return true;
   return r_tester;
}

// Trailing section of RVA 0x8970, before the new-bar check.
void RecoveredTrail()
{
   if(!r_settings.v_223a4 || PositionsTotal()<=0) return;
   if(UsePropFirmDelay)
   {
      int keep=0;
      for(int n=0;n<r_delay_count;n++)
      {
         bool found=false;
         for(int i=PositionsTotal()-1;i>=0;i--)
            if(PositionGetTicket(i)!=0 && (ulong)PositionGetInteger(POSITION_TICKET)==r_delay_tickets[n]) { found=true; break; }
         if(found)
         {
            r_delay_tickets[keep]=r_delay_tickets[n];
            r_delay_times[keep]=r_delay_times[n];
            keep++;
         }
      }
      r_delay_count=keep;
   }
   double ask=SymbolInfoDouble(_Symbol,SYMBOL_ASK),bid=SymbolInfoDouble(_Symbol,SYMBOL_BID);
   for(int i=PositionsTotal()-1;i>=0;i--)
   {
      if(PositionGetTicket(i)==0 || PositionGetString(POSITION_SYMBOL)!=_Symbol ||
         PositionGetInteger(POSITION_MAGIC)!=(long)InpMagic) continue;
      ulong ticket=(ulong)PositionGetInteger(POSITION_TICKET);
      double open=PositionGetDouble(POSITION_PRICE_OPEN),sl=PositionGetDouble(POSITION_SL),tp=PositionGetDouble(POSITION_TP);
      if(UsePropFirmDelay)
      {
         int found=-1;
         for(int n=0;n<r_delay_count;n++) if(r_delay_tickets[n]==ticket) { found=n; break; }
         if(found<0 && r_delay_count<50)
         {
            found=r_delay_count++;
            r_delay_tickets[found]=ticket;
            r_delay_times[found]=(datetime)PositionGetInteger(POSITION_TIME);
         }
         if(found<0 || r_delay_times[found]==0 ||
            (int)TimeCurrent()-(int)r_delay_times[found]<PropFirmDelaySec) continue;
      }
      ENUM_POSITION_TYPE type=(ENUM_POSITION_TYPE)PositionGetInteger(POSITION_TYPE);
      double target=sl;
      if(type==POSITION_TYPE_BUY)
      {
         if(bid-open<r_settings.v_22640) continue;
         target=bid-r_settings.v_22650;
         if(target<=sl+r_settings.v_22648) continue;
      }
      else if(type==POSITION_TYPE_SELL)
      {
         if(open-ask<r_settings.v_22640) continue;
         target=ask+r_settings.v_22650;
         if(sl!=0.0 && target>=sl-r_settings.v_22648) continue;
      }
      else continue;
      if(target==sl) continue;
      RecoveredNormalizePrice(target);
      if(RecoveredStopsAllowed(type,target,tp)) r_trade.PositionModify(ticket,target,tp);
   }
}

// RVA 0xadc0. Orders too close to current price are deliberately skipped.
int RecoveredDeletePending()
{
   int removed=0;
   double bid=SymbolInfoDouble(_Symbol,SYMBOL_BID),ask=SymbolInfoDouble(_Symbol,SYMBOL_ASK);
   double gap=(double)(SymbolInfoInteger(_Symbol,SYMBOL_TRADE_FREEZE_LEVEL)+2+
                       SymbolInfoInteger(_Symbol,SYMBOL_TRADE_STOPS_LEVEL))*r_point;
   for(int i=OrdersTotal()-1;i>=0;i--)
   {
      ulong ticket=OrderGetTicket(i);
      if(ticket==0 || OrderGetString(ORDER_SYMBOL)!=_Symbol || OrderGetInteger(ORDER_MAGIC)!=(long)InpMagic) continue;
      ENUM_ORDER_TYPE type=(ENUM_ORDER_TYPE)OrderGetInteger(ORDER_TYPE);
      if(type!=ORDER_TYPE_BUY_STOP && type!=ORDER_TYPE_SELL_STOP) continue;
      double price=OrderGetDouble(ORDER_PRICE_OPEN);
      if((type==ORDER_TYPE_BUY_STOP && price-ask<gap) || (type==ORDER_TYPE_SELL_STOP && bid-price<gap)) continue;
      if(r_trade.OrderDelete(ticket)) removed++;
   }
   return removed;
}

void RecoveredExpirePending()
{
   datetime now=TimeCurrent();
   long lifetime=(long)PeriodSeconds(RecoveredTimeframe())*r_settings.v_223a0;
   for(int i=OrdersTotal()-1;i>=0;i--)
   {
      ulong ticket=OrderGetTicket(i);
      if(ticket==0 || OrderGetString(ORDER_SYMBOL)!=_Symbol || OrderGetInteger(ORDER_MAGIC)!=(long)InpMagic) continue;
      datetime setup=(datetime)OrderGetInteger(ORDER_TIME_SETUP);
      if(OrderGetInteger(ORDER_TIME_EXPIRATION)==0 && setup>0 && now-setup>=lifetime) r_trade.OrderDelete(ticket);
   }
}

// RVAs 0xc390/0xcf80. Pivot width18, scan146; both are fixed in this EX5.
double RecoveredLevel(const bool high)
{
   ENUM_TIMEFRAMES timeframe=RecoveredTimeframe();
   datetime bar=iTime(_Symbol,timeframe,0);
   double cached=high ? r_high_level : r_low_level;
   if(bar==r_level_time && cached!=-2.0) return cached;
   double reference=SymbolInfoDouble(_Symbol,high ? SYMBOL_ASK : SYMBOL_BID),best=-1.0;
   int width=r_settings.v_22374 ? 18 : 0,scan=r_settings.v_22375 ? 146 : 0;
   for(int shift=width+1;shift<scan-width;shift++)
   {
      int found=high ? iHighest(_Symbol,timeframe,MODE_HIGH,2*width+1,shift-width) :
                       iLowest(_Symbol,timeframe,MODE_LOW,2*width+1,shift-width);
      if(found!=shift) continue;
      double candidate=high ? iHigh(_Symbol,timeframe,shift) : iLow(_Symbol,timeframe,shift);
      if(high ? candidate<reference+r_gap : candidate>reference-r_gap) continue;
      bool intact=true;
      for(int recent=1;recent<shift;recent++)
      {
         double value=high ? iHigh(_Symbol,timeframe,recent) : iLow(_Symbol,timeframe,recent);
         if(high ? value>=candidate : value<=candidate) { intact=false; break; }
      }
      if(intact && (best<0.0 || (high ? candidate<best : candidate>best))) best=candidate;
   }
   if(high) r_high_level=best; else r_low_level=best;
   r_level_time=bar;
   return best;
}

bool RecoveredRefreshIndicators()
{
   if(r_atr==INVALID_HANDLE || CopyBuffer(r_atr,0,0,5,r_atr_values)<5) return false;
   if(r_settings.v_223b4)
   {
      if(r_fast==INVALID_HANDLE || r_slow==INVALID_HANDLE || r_long_fast==INVALID_HANDLE || r_long_slow==INVALID_HANDLE) return false;
      if(CopyBuffer(r_fast,0,0,5,r_fast_values)<5 || CopyBuffer(r_slow,0,0,5,r_slow_values)<5 ||
         CopyBuffer(r_long_fast,0,0,3,r_long_fast_values)<3 || CopyBuffer(r_long_slow,0,0,3,r_long_slow_values)<3) return false;
   }
   return true;
}

void RecoveredCountDirections(int &buy,int &sell)
{
   buy=0; sell=0;
   for(int i=PositionsTotal()-1;i>=0;i--)
   {
      if(PositionGetTicket(i)==0 || PositionGetString(POSITION_SYMBOL)!=_Symbol || PositionGetInteger(POSITION_MAGIC)!=(long)InpMagic) continue;
      if(PositionGetInteger(POSITION_TYPE)==POSITION_TYPE_BUY) buy++; else sell++;
   }
   for(int i=OrdersTotal()-1;i>=0;i--)
   {
      if(OrderGetTicket(i)==0 || OrderGetString(ORDER_SYMBOL)!=_Symbol || OrderGetInteger(ORDER_MAGIC)!=(long)InpMagic) continue;
      if(OrderGetInteger(ORDER_TYPE)==ORDER_TYPE_BUY_STOP) buy++;
      if(OrderGetInteger(ORDER_TYPE)==ORDER_TYPE_SELL_STOP) sell++;
   }
}

bool RecoveredVolumeFilter()
{
   if(!r_settings.v_223b7) return true;
   long volumes[];
   ArraySetAsSeries(volumes,true);
   int copied=CopyTickVolume(_Symbol,RecoveredTimeframe(),1,3,volumes);
   if(copied<3) return true;
   return TwisterRecoveredVolume(true,copied,volumes[0],volumes[1],r_settings.v_223b8);
}

// RVAs 0xca60/0xd280; this initial integration is explicitly tester-only.
void RecoveredPlace(const bool buy,double price)
{
   if(!RecoveredCanTrade()) return;
   double quote=SymbolInfoDouble(_Symbol,buy ? SYMBOL_ASK : SYMBOL_BID);
   if(buy ? price<=quote+r_gap : price>=quote-r_gap) return;
   double sl=buy ? price-r_settings.v_22630 : price+r_settings.v_22630+0.0;
   double tp=buy ? price+r_settings.v_22638 : price-r_settings.v_22638;
   ENUM_ORDER_TYPE direction=buy ? ORDER_TYPE_BUY : ORDER_TYPE_SELL;
   double volume=RecoveredLots(buy ? price-sl : sl-price,direction);
   if(volume<=0.0 || !RecoveredNormalizeVolume(volume)) return;
   double margin=0.0;
   quote=SymbolInfoDouble(_Symbol,buy ? SYMBOL_ASK : SYMBOL_BID);
   if(!OrderCalcMargin(direction,_Symbol,volume,quote,margin) || margin<=0.0 ||
      margin>AccountInfoDouble(ACCOUNT_MARGIN_FREE)*0.9) return;
   RecoveredNormalizePrice(price); RecoveredNormalizePrice(sl); RecoveredNormalizePrice(tp);
   double gap=(double)(MathMax(SymbolInfoInteger(_Symbol,SYMBOL_TRADE_STOPS_LEVEL),
                              SymbolInfoInteger(_Symbol,SYMBOL_TRADE_FREEZE_LEVEL))+2)*r_point;
   if(buy ? ((sl>0.0 && price-sl<gap) || (tp>0.0 && tp-price<gap)) :
            ((sl>0.0 && sl-price<gap) || (tp>0.0 && price-tp<gap))) return;
   datetime expiry=(datetime)(iTime(_Symbol,RecoveredTimeframe(),0)+(long)PeriodSeconds(RecoveredTimeframe())*r_settings.v_223a0);
   bool sent=buy ? r_trade.BuyStop(volume,price,_Symbol,sl,tp,ORDER_TIME_SPECIFIED,expiry,TradeComment) :
                   r_trade.SellStop(volume,price,_Symbol,sl,tp,ORDER_TIME_SPECIFIED,expiry,TradeComment);
   if(sent) r_day_orders++;
}

int OnInit()
{
   r_tester=(bool)MQLInfoInteger(MQL_TESTER);
   if(!r_tester || MQLInfoInteger(MQL_VISUAL_MODE))
   {
      Print("TwisterRecovered: tester trading path only; UI/live reconstruction is incomplete.");
      return INIT_FAILED;
   }
   ReadRecoveredInputs();
   TwisterRecoverSettings(r_inputs,r_tester,r_settings);
   r_trade.SetExpertMagicNumber((ulong)(long)InpMagic);
   r_trade.SetDeviationInPoints(r_settings.v_2229d);
   r_trade.SetAsyncMode(false);
   r_trade.SetTypeFilling(ORDER_FILLING_FOK);
   r_point=SymbolInfoDouble(_Symbol,SYMBOL_POINT);
   if(r_point<=0.0) return INIT_FAILED;
   r_gap=MathMax((double)(SymbolInfoInteger(_Symbol,SYMBOL_TRADE_STOPS_LEVEL)+5)*r_point,r_point*r_settings.v_22378);
   r_tick_size=SymbolInfoDouble(_Symbol,SYMBOL_TRADE_TICK_SIZE);
   r_volume_step=SymbolInfoDouble(_Symbol,SYMBOL_VOLUME_STEP);
   r_volume_min=SymbolInfoDouble(_Symbol,SYMBOL_VOLUME_MIN);
   r_volume_max=SymbolInfoDouble(_Symbol,SYMBOL_VOLUME_MAX);
   r_volume_limit=SymbolInfoDouble(_Symbol,SYMBOL_VOLUME_LIMIT);
   r_digits=(int)SymbolInfoInteger(_Symbol,SYMBOL_DIGITS);
   if(r_tick_size<=0.0 || r_volume_step<=0.0 || r_volume_min<=0.0 || r_volume_max<=0.0) return INIT_FAILED;
   r_atr=iATR(_Symbol,PERIOD_M15,61);
   if(r_atr==INVALID_HANDLE) return INIT_FAILED;
   r_fast=iMA(_Symbol,PERIOD_M15,4,0,MODE_EMA,PRICE_CLOSE);
   r_slow=iMA(_Symbol,PERIOD_M15,49,0,MODE_EMA,PRICE_CLOSE);
   r_long_fast=iMA(_Symbol,(ENUM_TIMEFRAMES)r_settings.v_22370,236,0,MODE_EMA,PRICE_CLOSE);
   r_long_slow=iMA(_Symbol,(ENUM_TIMEFRAMES)r_settings.v_22370,1007,0,MODE_EMA,PRICE_CLOSE);
   if(r_fast==INVALID_HANDLE || r_slow==INVALID_HANDLE || r_long_fast==INVALID_HANDLE || r_long_slow==INVALID_HANDLE) return INIT_FAILED;
   ArraySetAsSeries(r_atr_values,true); ArraySetAsSeries(r_fast_values,true);
   ArraySetAsSeries(r_slow_values,true); ArraySetAsSeries(r_long_fast_values,true); ArraySetAsSeries(r_long_slow_values,true);
   r_day_time=iTime(_Symbol,PERIOD_D1,0);
   r_day_balance=AccountInfoDouble(ACCOUNT_BALANCE);
   TwisterRecoverPriceDistances(r_point,r_settings);
   r_ready=true;
   return INIT_SUCCEEDED;
}

void OnTick()
{
   if(!r_ready || SymbolInfoInteger(_Symbol,SYMBOL_TRADE_MODE)==0) return;
   MqlDateTime dt;
   TimeToStruct(TimeCurrent(),dt);
   if(dt.day_of_week==1) r_friday_lock=false;
   else if(dt.day_of_week==5 && !r_friday_lock && dt.hour>=(BrokerType==1 ? 17 : 19))
   {
      RecoveredDeletePending();
      r_friday_lock=true;
   }
   RecoveredTrail();
   datetime bar=iTime(_Symbol,RecoveredTimeframe(),0);
   if(bar==r_bar_time) return;
   r_bar_time=bar; r_high_level=-2.0; r_low_level=-2.0;
   RecoveredExpirePending();
   datetime day=iTime(_Symbol,PERIOD_D1,0);
   if(day!=r_day_time)
   {
      r_day_time=day; r_day_balance=AccountInfoDouble(ACCOUNT_BALANCE);
      r_day_orders=0; r_pause_bars=0;
   }
   if(!RecoveredCanTrade()) return;
   if(RecoveredHoliday()) { RecoveredDeletePending(); return; }
   // The original news predicate always returns false in the tester.
   if(r_pause_bars>0) { r_pause_bars--; return; }
   if(r_day_orders>=(r_settings.v_223c1 ? 17 : 0) || r_friday_lock) return;
   if(r_settings.v_225d0>0.0 && r_day_balance>0.0 &&
      ((r_day_balance-AccountInfoDouble(ACCOUNT_EQUITY))/r_day_balance)*100.0>=r_settings.v_225d0) return;
   if(!RecoveredRefreshIndicators()) return;
   double open=iOpen(_Symbol,RecoveredTimeframe(),1),close=iClose(_Symbol,RecoveredTimeframe(),1);
   double high=iHigh(_Symbol,RecoveredTimeframe(),1),low=iLow(_Symbol,RecoveredTimeframe(),1);
   int buys=0,sells=0;
   RecoveredCountDirections(buys,sells);
   int trend=TwisterRecoveredTrend(SymbolInfoDouble(_Symbol,SYMBOL_BID),r_fast_values,r_slow_values,
                                  r_long_fast_values,r_long_slow_values,r_settings.v_223b4,r_settings.v_223b5,r_settings.v_223b6);
   if(r_settings.v_223b4 && trend==0) return;
   if(buys==0 && (!r_settings.v_223b4 || trend>0))
   {
      double level=RecoveredLevel(true);
      if(level>0.0 && TwisterRecoveredCandle(true,open,high,low,close,r_point,r_settings.v_22388,
                                           r_settings.v_22380,r_settings.v_22390) && RecoveredVolumeFilter()) RecoveredPlace(true,level);
   }
   if(sells==0 && (!r_settings.v_223b4 || trend<0))
   {
      double level=RecoveredLevel(false);
      if(level>0.0 && TwisterRecoveredCandle(false,open,high,low,close,r_point,r_settings.v_22388,
                                           r_settings.v_22380,r_settings.v_22390) && RecoveredVolumeFilter()) RecoveredPlace(false,level);
   }
}

// RVA 0xdd50. The original counts all SL exits, including profitable trailing exits.
void OnTradeTransaction(const MqlTradeTransaction &trans,const MqlTradeRequest &request,const MqlTradeResult &result)
{
   if(trans.type!=TRADE_TRANSACTION_DEAL_ADD || trans.deal==0 || !HistoryDealSelect(trans.deal)) return;
   if((int)HistoryDealGetInteger(trans.deal,DEAL_MAGIC)!=InpMagic || HistoryDealGetString(trans.deal,DEAL_SYMBOL)!=_Symbol) return;
   ENUM_DEAL_ENTRY entry=(ENUM_DEAL_ENTRY)HistoryDealGetInteger(trans.deal,DEAL_ENTRY);
   if(entry==DEAL_ENTRY_IN)
   {
      double fill=HistoryDealGetDouble(trans.deal,DEAL_PRICE);
      ENUM_DEAL_TYPE direction=(ENUM_DEAL_TYPE)HistoryDealGetInteger(trans.deal,DEAL_TYPE);
      ulong position=(ulong)HistoryDealGetInteger(trans.deal,DEAL_POSITION_ID);
      if(fill>0.0) RecoveredAlignAfterFill(position,fill,direction);
      return;
   }
   if(entry!=DEAL_ENTRY_OUT) return;
   ENUM_DEAL_REASON reason=(ENUM_DEAL_REASON)HistoryDealGetInteger(trans.deal,DEAL_REASON);
   double net=HistoryDealGetDouble(trans.deal,DEAL_PROFIT)+HistoryDealGetDouble(trans.deal,DEAL_SWAP)+
              HistoryDealGetDouble(trans.deal,DEAL_COMMISSION);
   if(reason==DEAL_REASON_SL)
   {
      r_pause_bars=r_settings.v_223c4;
      r_loss_streak++;
      if(r_settings.v_225c0 && r_loss_streak>=r_settings.v_225c4) r_dd_active=true;
   }
   else if(net>0.0) { r_loss_streak=0; r_dd_active=false; }
}

void OnDeinit(const int reason)
{
   if(r_atr!=INVALID_HANDLE) IndicatorRelease(r_atr);
   if(r_fast!=INVALID_HANDLE) IndicatorRelease(r_fast);
   if(r_slow!=INVALID_HANDLE) IndicatorRelease(r_slow);
   if(r_long_fast!=INVALID_HANDLE) IndicatorRelease(r_long_fast);
   if(r_long_slow!=INVALID_HANDLE) IndicatorRelease(r_long_slow);
   r_ready=false;
}
