#ifndef BOT1_STARTUP_CONTEXT_MQH
#define BOT1_STARTUP_CONTEXT_MQH
#include "Bot1StrategyContext.mqh"
#include "Bot1Preparation.mqh"
#include "Bot1StrategyHistory.mqh"
#include "Bot1PanelCreation.mqh"
#include "Bot1DailyLossGuard.mqh"

struct Bot1StartupContextState
{
   long panel_bar;
   uchar extended_cleanup;
   double cell_base_x,cell_base_y;
};

double Bot1StartupProduct(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left*right;
}

// OnInit 0x3827..0x3c9d. The earlier account block leaves XMM6 at +0.0.
void Bot1InitializeStartupContext(const string &chart_symbol,
                                  Bot1StrategyContextInputs &context_inputs,
                                  Bot1StrategyContextState &context,
                                  Bot1PreparationInputs &preparation_inputs,
                                  Bot1StrategyHistoryCache &history,
                                  Bot1PanelCreationState &panel,Bot1DailyLossState &daily,
                                  Bot1StartupContextState &state)
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
   panel.cell_x=Bot1StartupProduct(Bot1StartupProduct(factor_x,state.cell_base_x),panel.scale);
   const double factor_y=enabled ? 24.5 : 0.0;
   panel.cell_y=Bot1StartupProduct(panel.scale,Bot1StartupProduct(factor_y,state.cell_base_y));
   preparation_inputs.symbol=chart_symbol;
   if(context_inputs.symbol_suffix=="")
   {
      context_inputs.symbol_suffix=StringSubstr(preparation_inputs.symbol,6,10);
      if(context_inputs.symbol_suffix!="") Print("Suffix detected: "+context_inputs.symbol_suffix);
   }
}
#endif
