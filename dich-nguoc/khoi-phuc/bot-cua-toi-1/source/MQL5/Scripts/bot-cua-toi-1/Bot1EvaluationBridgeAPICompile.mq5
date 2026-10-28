#property strict
#include "../../Include/bot-cua-toi-1/Bot1EvaluationBridge.mqh"
void OnStart()
{
   Bot1PreparationInputs inputs;Bot1PreparationState preparation;Bot1ProfileRuntimeState profile_state;
   Bot1StrategyContextState context;Bot1NfpExecution execution;
   Bot1PendingRestoreSettings restore;Bot1EntryLoopSettings loop;
   Bot1LevelCacheSettings levels;ZeroMemory(inputs);ZeroMemory(preparation);
   ZeroMemory(context);ZeroMemory(execution);ZeroMemory(restore);ZeroMemory(loop);ZeroMemory(levels);
   Bot1ProfileAdjustments adjustments;ZeroMemory(adjustments);Bot1StrategyContextInputs context_inputs;ZeroMemory(context_inputs);
   inputs.symbol=_Symbol;context_inputs.base_magic=0;Bot1SetupAndProjectEvaluation(0,false,adjustments,inputs,context_inputs,profile_state,context,preparation,0,0,execution,preparation.unit,restore,loop,levels);
   Print(execution.strategy_magic,execution.symbol,levels.timeframe);
}
