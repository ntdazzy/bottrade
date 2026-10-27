#property strict
#include "../../Include/bot-cua-toi-1/Bot1NewsSelector.mqh"
void OnStart()
{
   Bot1NewsEvents events;Bot1NewsWindows settings;Bot1NewsSelection selection;
   ZeroMemory(events);ZeroMemory(settings);Bot1UpdateNewsSelection(events,settings,selection);
}
