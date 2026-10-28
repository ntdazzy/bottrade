#property strict
#include "../../Include/bot-cua-toi-1/Bot1StartupContext.mqh"
void OnStart()
{
   Bot1StrategyContextInputs inputs;Bot1StrategyContextState context;Bot1PreparationInputs preparation;
   Bot1StrategyHistoryCache history;Bot1PanelCreationState panel;Bot1DailyLossState daily;Bot1StartupContextState startup;
   ZeroMemory(inputs);ZeroMemory(context);ZeroMemory(preparation);ZeroMemory(panel);ZeroMemory(daily);ZeroMemory(startup);
   inputs.comment_prefix="Gold Trade Pro";inputs.base_magic=9000;inputs.symbol_suffix="";
   panel.scale=1.0;panel.cell_font_flag=1;startup.cell_base_x=1.0;startup.cell_base_y=1.0;
   Bot1InitializeStartupContext(_Symbol,inputs,context,preparation,history,panel,daily,startup);
}
