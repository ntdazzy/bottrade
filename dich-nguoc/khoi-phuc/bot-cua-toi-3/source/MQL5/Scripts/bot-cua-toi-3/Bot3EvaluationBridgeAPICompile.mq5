#property strict
#include "../../Include/bot-cua-toi-3/Bot3EvaluationBridge.mqh"
void OnStart()
{
   Bot3PreparationInputs inputs;Bot3PreparationState preparation;
   Bot3StrategyContextState context;Bot3NfpExecution execution;
   Bot3PendingRestoreSettings restore;Bot3EntryLoopSettings loop;
   Bot3LevelCacheSettings levels;ZeroMemory(inputs);ZeroMemory(preparation);
   ZeroMemory(context);ZeroMemory(execution);ZeroMemory(restore);ZeroMemory(loop);ZeroMemory(levels);
   inputs.symbol=_Symbol;Bot3ProjectPreparationToEvaluation(inputs,preparation,context,0,0,execution,preparation.unit,restore,loop,levels);
   Print(execution.strategy_magic,execution.symbol,levels.timeframe);
}
