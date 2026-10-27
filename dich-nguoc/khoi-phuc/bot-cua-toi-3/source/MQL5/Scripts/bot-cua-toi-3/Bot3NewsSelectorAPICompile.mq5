#property strict
#include "../../Include/bot-cua-toi-3/Bot3NewsSelector.mqh"
void OnStart()
{
   Bot3NewsEvents events;Bot3NewsWindows settings;Bot3NewsSelection selection;
   ZeroMemory(events);ZeroMemory(settings);Bot3UpdateNewsSelection(events,settings,selection);
}
