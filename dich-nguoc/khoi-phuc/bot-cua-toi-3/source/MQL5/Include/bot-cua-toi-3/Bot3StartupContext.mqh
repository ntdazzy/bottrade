#ifndef BOT3_STARTUP_CONTEXT_MQH
#define BOT3_STARTUP_CONTEXT_MQH
#include "Bot3StrategyContext.mqh"
#include "Bot3Preparation.mqh"
#include "Bot3StrategyHistory.mqh"
#include "Bot3PanelCreation.mqh"
#include "Bot3DailyLossGuard.mqh"

struct Bot3StartupContextState
{
   long panel_bar;
   uchar extended_cleanup;
   double cell_base_x,cell_base_y;
};

double Bot3StartupProduct(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left*right;
}

// OnInit 0x3ce6..0x4580, after initial frequency selection and before preparation.
void Bot3InitializeStartupContext(const string &chart_symbol,
                                  Bot3StrategyContextInputs &context_inputs,
                                  Bot3StrategyContextState &context,
                                  Bot3PreparationInputs &preparation_inputs,
                                  Bot3StrategyHistoryCache &history,
                                  Bot3PanelCreationState &panel,Bot3DailyLossState &daily,
                                  Bot3StartupContextState &state)
{
   context.order_comment=context_inputs.comment_prefix;
   daily.peak=0.0;
   daily.blocked=0;
   state.panel_bar=0;
   context.magic=context_inputs.base_magic;
   history.total=-1;
   history.count=0;
   state.extended_cleanup=1;
   const bool enabled=panel.cell_font_flag!=0;
   const double factor_x=enabled ? 175.0 : 0.0;
   panel.cell_x=Bot3StartupProduct(Bot3StartupProduct(factor_x,state.cell_base_x),panel.scale);
   const double factor_y=enabled ? 24.5 : 0.0;
   panel.cell_y=Bot3StartupProduct(panel.scale,Bot3StartupProduct(factor_y,state.cell_base_y));
   preparation_inputs.symbol=chart_symbol;
   if(context_inputs.symbol_suffix=="")
   {
      context_inputs.symbol_suffix=StringSubstr(preparation_inputs.symbol,6,10);
      if(context_inputs.symbol_suffix!="") Print("Suffix detected: "+context_inputs.symbol_suffix);
   }
}
#endif
