#property strict
#include "../../Include/bot-cua-toi-1/Bot1EvaluationBridge.mqh"
void OnStart()
{
   Bot1PreparationInputs inputs;Bot1PreparationState preparation;
   Bot1StrategyContextState context;Bot1NfpExecution execution;
   Bot1PendingRestoreSettings restore;Bot1EntryLoopSettings loop;
   Bot1LevelCacheSettings levels;ZeroMemory(inputs);ZeroMemory(preparation);
   ZeroMemory(context);ZeroMemory(execution);ZeroMemory(restore);ZeroMemory(loop);ZeroMemory(levels);
   inputs.symbol=_Symbol;Bot1ProjectPreparationToEvaluation(inputs,preparation,context,0,0,execution,preparation.unit,restore,loop,levels);
   Print(execution.strategy_magic,execution.symbol,levels.timeframe);
}
