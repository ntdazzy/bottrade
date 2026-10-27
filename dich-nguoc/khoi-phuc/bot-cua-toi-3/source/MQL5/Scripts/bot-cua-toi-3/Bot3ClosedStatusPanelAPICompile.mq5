#property strict
#include "../../Include/bot-cua-toi-3/Bot3ClosedStatusPanel.mqh"
uchar Show;
uchar Tester;
int Seed;
string PanelSymbol;
double Wins;
double Losses;
void OnStart() { Bot3UpdateClosedStatusPanel(Show,Tester,Seed,PanelSymbol,Wins,Losses); }
