#property strict
#include "../../Include/bot-cua-toi-3/Bot3EvaluationBridge.mqh"
void OnStart()
{
   Bot3PreparationInputs inputs;Bot3PreparationState preparation;Bot3ProfileRuntimeState profile_state;
   Bot3StrategyContextState context;Bot3NfpExecution execution;
   Bot3PendingRestoreSettings restore;Bot3EntryLoopSettings loop;
   Bot3LevelCacheSettings levels;ZeroMemory(inputs);ZeroMemory(preparation);
   ZeroMemory(context);ZeroMemory(execution);ZeroMemory(restore);ZeroMemory(loop);ZeroMemory(levels);
   Bot3ProfileAdjustments adjustments;ZeroMemory(adjustments);Bot3StrategyContextInputs context_inputs;ZeroMemory(context_inputs);
   inputs.symbol=_Symbol;context_inputs.base_magic=0;Bot3SetupAndProjectEvaluation(0,adjustments,inputs,context_inputs,profile_state,context,preparation,0,0,execution,preparation.unit,restore,loop,levels);
   Print(execution.strategy_magic,execution.symbol,levels.timeframe);
}
