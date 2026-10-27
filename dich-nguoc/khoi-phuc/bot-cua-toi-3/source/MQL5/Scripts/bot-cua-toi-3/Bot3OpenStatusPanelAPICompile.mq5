#property strict
#include "../../Include/bot-cua-toi-3/Bot3OpenStatusPanel.mqh"
uchar PanelShow;
uchar PanelTester;
int PanelSeed;
string PanelSymbol;
double PanelBalance;
int PanelMode;
double PanelStrategyRisk;
int PanelFrequency;
double PanelManual;
double PanelDD;
Bot3NewsEvents Events;Bot3NewsWindows Windows;Bot3NewsSelection Selection;ulong LastTicket;
void OnStart() { Bot3UpdateOpenStatusPanel(PanelShow,PanelTester,PanelSeed,PanelSymbol,PanelBalance,PanelFrequency,PanelMode,PanelManual,PanelDD,PanelStrategyRisk,Events,Windows,Selection,LastTicket); }
