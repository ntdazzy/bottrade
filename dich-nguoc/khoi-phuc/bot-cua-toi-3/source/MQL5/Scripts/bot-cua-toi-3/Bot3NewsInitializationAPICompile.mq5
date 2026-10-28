#property strict
#include "../../Include/bot-cua-toi-3/Bot3NewsInitialization.mqh"
void OnStart(){Bot3NewsWindows windows;Bot3NewsEvents events;Bot3NewsSelection selection;long query=0;ZeroMemory(windows);ZeroMemory(events);Bot3InitializeNews(windows,events,selection,query);}
