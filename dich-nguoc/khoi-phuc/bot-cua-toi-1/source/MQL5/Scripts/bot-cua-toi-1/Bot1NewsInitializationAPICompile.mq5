#property strict
#include "../../Include/bot-cua-toi-1/Bot1NewsInitialization.mqh"
void OnStart(){Bot1NewsWindows windows;Bot1NewsEvents events;Bot1NewsSelection selection;long query=0;ZeroMemory(windows);ZeroMemory(events);Bot1InitializeNews(windows,events,selection,query);}
