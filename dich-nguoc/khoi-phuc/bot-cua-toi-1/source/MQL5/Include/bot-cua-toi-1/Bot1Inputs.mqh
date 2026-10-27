#ifndef BOT1_INPUTS_MQH
#define BOT1_INPUTS_MQH
// Generated from the verified MT5 input snapshot; behavior is not inferred here.
enum Bot1BacktestSpeedValue
{
   Bot1BacktestSpeedValue_0 = 1, // normal
   Bot1BacktestSpeedValue_1 = 2, // fast
   Bot1BacktestSpeedValue_2 = 3 // ultra fast
};
enum Bot1FakeOutFilterValue
{
   Bot1FakeOutFilterValue_0 = 0, // OFF
   Bot1FakeOutFilterValue_1 = 1, // Low
   Bot1FakeOutFilterValue_2 = 2, // Medium
   Bot1FakeOutFilterValue_3 = 3 // High
};
enum Bot1RiskValue
{
   Bot1RiskValue_0 = 0, // use StartLots
   Bot1RiskValue_1 = 9999, // use lotsizeStep
   Bot1RiskValue_2 = 999, // use Manual RiskPerTrade
   Bot1RiskValue_3 = 3 // use Max Risk Per Strategy
};
input string lijntje = "============================================================="; // - - -
input bool ShowInfoPanel = true; // ShowInfoPanel
input bool UpdateInfoTesting = false; // update infopanel during testing
input double InfoPanelSizeAdjust = 1.0; // Adjustment for Infopanel size
input int SetFontSize = 0; // Force Font Size (0=disabled)
input string BacktestSpeed_string = "------------------------------ Backtest Speed settings ------------------------------"; // - - -
input Bot1BacktestSpeedValue BacktestSpeed = Bot1BacktestSpeedValue_0; // Backtest Speed
input string spreadfilter = "------------------------------ settings ------------------------------"; // - - -
input bool AllowBuyTrades = true; // Allow Buy Trades
input bool AllowSellTrades = true; // Allow Sell Trades
input bool RunStrategyA = true; // run strategy 1
input bool RunStrategyB = true; // run strategy 2
input bool RunStrategyC = true; // run strategy 3
input bool RunStrategyD = true; // run strategy 4
input bool RunStrategyE = true; // run strategy 5
input bool RunStrategyF = true; // run strategy 6
input bool RunStrategyG = true; // run strategy 7
input bool RunStrategyH = true; // run strategy 8
input double MaxSpread = 500.0; // Max Allowed Spread
input bool UseVariableValues = true; // UseVariableValues
input bool UseHL_TrailingSL = true; // UseHL_TrailingSL
input int FridayStopHour = 25; // Friday stop hour (brokertime; close all trades)
input bool setSL_TP_After_Entry = false; // setSL_TP_After_Entry
input bool Virtual_expiration = true; // Use Virtual Expiration
input double Randomization = 0.0; // Randomization (entries and exit) in pips
input Bot1FakeOutFilterValue FakeOutFilter = Bot1FakeOutFilterValue_1; // Fake Breakout Filter
input bool EnableVirtualSLTP = false; // Enable Virtual SL/TP (trailing by market close)
input int SetVSL_to_hardSL_sec_delay = 99; // Seconds before the real SL is pulled up to the virtual SL (0 =
input int ST1_MagicNumber = 9000; // Base Magicnumber
input string ST1_Comment = "Gold Trade Pro"; // Comment for trades
input bool RemoveCommentSuffix = false; // RemoveCommentSuffix
input string NFP_FILTER = "----------------------- NFP Filter -----------------------"; // NFP_FILTER
input bool EnableNFP_Filter = true; // EnableNFP_Filter
input bool UseMQL5Calendar = true; // UseMQL5Calendar
input bool AutoGMT = true; // AutoGMT
input int Broker_GMT_OFFSET_Winter = 2; // GMT_OFFSET_Winter (AutoGMT=false or backtesting)
input int Broker_GMT_OFFSET_Summer = 3; // MT_OFFSET_Summer (AutoGMT=false or backtesting)
input bool NFP_CloseOpenTrades = true; // NFP_CloseOpenTrades
input bool NFP_ClosePendingOrders = true; // NFP_ClosePendingOrders
input int NFP_MinutesBefore = 10; // NFP_MinutesBefore
input int NFP_MinutesAfter = 240; // NFP_MinutesAfter
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
input string LotSizeSettings = "----------------------- LotSize Settings -----------------------"; // - - -
input double ManualBalance = 0.0; // Set Balance To Use manually
input double StartLots = 0.01; // StartLots
input Bot1RiskValue Risk = Bot1RiskValue_0; // Lotsize calculation method
input double Manual_RiskPerTrade = 1.2; // Max risk per trade
input double MaxRiskPerStrategy = 3.0; // Max Risk Per Strategy
input double PropFirmMaxDailyDD = 0.0; // Set Max Daily Drawdown (Prop Firms)
input int LotPerBalance_step = 600; // LotsizeStep
input bool OnlyUp = true; // OnlyUp
input bool ResetHighestBalance = false; // Reset Highest Balance for OnlyUp
input bool ResetHighestBalanceOnWithdrawal = true; // Reset Highest Balance on a withdrawal
input bool CheckMargin = true; // CheckMargin
input bool UseEquity = false; // Use Equity Instead of Balance
input bool AdjustLotsizeToVariableValues = true; // AdjustLotsizeToVariableValues
#endif
