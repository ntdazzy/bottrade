#property strict
#include "../../Include/bot-cua-toi-1/Bot1OpenStatusPanel.mqh"
uchar PanelShow;
uchar PanelTester;
int PanelSeed;
string PanelSymbol;
double PanelBalance;
int PanelMode;
double PanelStrategyRisk;
double PanelVolume;
double PanelTradeRisk;
int PanelStep;
Bot1NewsEvents Events;Bot1NewsWindows Windows;Bot1NewsSelection Selection;ulong LastTicket;
void OnStart() { Bot1UpdateOpenStatusPanel(PanelShow,PanelTester,PanelSeed,PanelSymbol,PanelBalance,PanelVolume,PanelMode,PanelTradeRisk,PanelStrategyRisk,PanelStep,Events,Windows,Selection,LastTicket); }
