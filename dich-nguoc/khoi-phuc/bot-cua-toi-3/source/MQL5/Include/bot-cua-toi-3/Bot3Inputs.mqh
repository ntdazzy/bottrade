#ifndef BOT3_INPUTS_MQH
#define BOT3_INPUTS_MQH
// Generated from the verified MT5 input snapshot; behavior is not inferred here.
enum Bot3BacktestSpeedValue
{
   Bot3BacktestSpeedValue_0 = 1, // normal
   Bot3BacktestSpeedValue_1 = 2, // fast
   Bot3BacktestSpeedValue_2 = 3 // ultra fast
};
enum Bot3TradeFrequencyValue
{
   Bot3TradeFrequencyValue_0 = 0, // extreme conservative
   Bot3TradeFrequencyValue_1 = 1, // conservative
   Bot3TradeFrequencyValue_2 = 2, // moderate
   Bot3TradeFrequencyValue_3 = 3, // Intense
   Bot3TradeFrequencyValue_4 = 4, // Extreme (high risk!)
   Bot3TradeFrequencyValue_5 = 5, // Auto (based on balance and risk)
   Bot3TradeFrequencyValue_6 = 6 // Manual strategy selection
};
enum Bot3FakeOutFilterValue
{
   Bot3FakeOutFilterValue_0 = 0, // OFF
   Bot3FakeOutFilterValue_1 = 1, // Low
   Bot3FakeOutFilterValue_2 = 2, // Medium
   Bot3FakeOutFilterValue_3 = 3 // High
};
enum Bot3RiskValue
{
   Bot3RiskValue_0 = 0, // use StartLots
   Bot3RiskValue_1 = 1234, // Max Allowed Total Drawdown
   Bot3RiskValue_2 = 3 // Max Risk Per Strategy
};
input string lijntje = "============================================================="; // - - -
input bool UseVariableValues = true; // UseVariableValues
input bool AdjustLotsizeToVariableValues = true; // AdjustLotsizeToVariableValues
input bool ShowInfoPanel = true; // ShowInfoPanel
input bool UpdateInfoTesting = false; // update infopanel during testing
input double InfoPanelSizeAdjust = 1.0; // Adjustment for Infopanel size
input int SetFontSize = 0; // Force Font Size (0=disabled)
input string BacktestSpeed_string = "------------------------------ Backtest Speed settings ------------------------------"; // - - -
input Bot3BacktestSpeedValue BacktestSpeed = Bot3BacktestSpeedValue_0; // Backtest Speed
input string spreadfilter = "------------------------------ settings ------------------------------"; // - - -
input bool AllowBuyTrades = true; // Allow Buy Trades
input bool AllowSellTrades = true; // Allow Sell Trades
input Bot3TradeFrequencyValue TradeFrequency = Bot3TradeFrequencyValue_5; // TradeFrequency
input double MaxSpread = 500.0; // Max Allowed Spread
input bool UseHL_TrailingSL = true; // UseHL_TrailingSL
input int FridayStopHour = 25; // Friday stop hour (brokertime; close all trades+pending)
input bool FridayClosePending = true; // delete pending orders
input bool FridayCloseOpen = true; // close open trades
input bool setSL_TP_After_Entry = false; // setSL_TP_After_Entry
input bool Virtual_expiration = true; // Use Virtual Expiration
input double Randomization = 0.0; // Randomization (entries and exit) in pips
input Bot3FakeOutFilterValue FakeOutFilter = Bot3FakeOutFilterValue_2; // Fake Breakout Filter
input bool EnableVirtualSLTP = false; // Enable Virtual SL/TP (trailing by market close)
input int SetVSL_to_hardSL_sec_delay = 99; // Seconds before the real SL is pulled up to the virtual SL (0 =
input int ST1_MagicNumber = 8000; // Base Magicnumber
input string ST1_Comment = "The Gold Reaper"; // Comment for trades
input bool RemoveCommentSuffix = false; // RemoveCommentSuffix
input string NFP_FILTER = "----------------------- NFP Filter -----------------------"; // NFP_FILTER
input bool EnableNFP_Filter = true; // EnableNFP_Filter
input bool UseMQL5Calendar = true; // UseMQL5Calendar
input bool AutoGMT = true; // AutoGMT
input int Broker_GMT_OFFSET_Winter = 2; // GMT_OFFSET_Winter (AutoGMT=false or backtesting)
input int Broker_GMT_OFFSET_Summer = 3; // MT_OFFSET_Summer (AutoGMT=false or backtesting)
input bool NFP_CloseOpenTrades = true; // NFP_CloseOpenTrades
input bool NFP_ClosePendingOrders = true; // NFP_ClosePendingOrders
input int NFP_MinutesBefore = 100; // NFP_MinutesBefore
input int NFP_MinutesAfter = 60; // NFP_MinutesAfter
input string IR_FILTER = "----------------------- Interest Rate Filter -----------------------"; // - - -
input bool EnableIR_Filter = false; // EnableIR_Filter
input bool IR_CloseOpenTrades = true; // IR_CloseOpenTrades
input bool IR_ClosePendingOrders = true; // IR_ClosePendingOrders
input int IR_MinutesBefore = 100; // IR_MinutesBefore
input int IR_MinutesAfter = 60; // IR_MinutesAfter
input string CPI_FILTER = "----------------------- CPI Filter -----------------------"; // - - -
input bool EnableCPI_Filter = false; // EnableCPI_Filter
input bool CPI_CloseOpenTrades = true; // CPI_CloseOpenTrades
input bool CPI_ClosePendingOrders = true; // CPI_ClosePendingOrders
input int CPI_MinutesBefore = 100; // CPI_MinutesBefore
input int CPI_MinutesAfter = 60; // CPI_MinutesAfter
input string propfirmsettings = "----------------------- Propfirm unique trades settings -----------------------"; // - - -
input double AdjustEntry = 0.0; // AdjustEntry
input double AdjustSL = 0.0; // AdjustSL
input double AdjustTP = 0.0; // AdjustTP
input double AdjustTrailSL = 0.0; // AdjustTrailSL
input double AdjustTrailTP = 0.0; // AdjustTrailTP
input double AdjustBreakEven = 0.0; // AdjustBreakEven
input string LotSizeSettings = "----------------------- LotSize Settings -----------------------"; // - - -
input double ManualBalance = 0.0; // manually set balance to use (if > 0)
input Bot3RiskValue Risk = Bot3RiskValue_1; // Lotsize calculation method
input double StartLots = 0.01; // StartLots
input double MaxAllowedDD = 30.0; // Max Allowed TOTAL Drawdown
input bool UseWeightedLots = true; // Weighted Lotsize
input double MaxRiskPerStrategy_ = 1.0; // Max Risk Per Strat
input double PropFirmMaxDailyDD = 0.0; // Set Max DAILY Drawdown (Prop Firms)
input bool OnlyUp = true; // OnlyUp
input bool ResetHighestBalance = false; // Reset Highest Balance for OnlyUp
input bool ResetHighestBalanceOnWithdrawal = true; // Reset Highest Balance on a withdrawal
input bool CheckMargin = true; // CheckMargin
input bool UseEquity = false; // Use Equity Instead of Balance
input string ManualStratSelect = "------------------------- Manual Strategy Selection -------------------------"; // - - -
input string ManStratWarn = "!! DO NOT RUN MANUAL STRATEGIES WHILE USING 'MAX ALLOWED TOTAL DD' OPTION !! "; // - - -
input bool RunStrat1 = true; // Run Strategy 1 (low risk)
input bool RunStrat2 = true; // Run Strategy 2 (low risk)
input bool RunStrat3 = true; // Run Strategy 3 (low risk)
input bool RunStrat4 = true; // Run Strategy 4 (med risk)
input bool RunStrat5 = true; // Run Strategy 5 (med risk)
input bool RunStrat6 = true; // Run Strategy 6 (med risk)
input bool RunStrat7 = true; // Run Strategy 7 (med risk)
input bool RunStrat8 = true; // Run Strategy 8 (high risk)
input bool RunStrat9 = true; // Run Strategy 9 (high risk)
#endif
