#property strict
#include "../../Include/bot-cua-toi-1/Bot1ClosedStatusPanel.mqh"
uchar Show;
uchar Tester;
int Seed;
string PanelSymbol;
double Wins;
double Losses;
void OnStart() { Bot1UpdateClosedStatusPanel(Show,Tester,Seed,PanelSymbol,Wins,Losses); }
