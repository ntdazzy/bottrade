#property strict
#property version "1.00"
#import "Ex5ApiProbeLibraryV6.ex5"
void ProbeDispatch(const int selected);
#import
input int InpApiCase=-1;
int OnInit()
{
   if(!MQLInfoInteger(MQL_TESTER)) return INIT_FAILED;
   Print("EX5_API_MAP_BEGIN");
   ProbeDispatch(InpApiCase);
   ulong started=GetTickCount64();
   while(!IsStopped() && GetTickCount64()-started<20000) {}
   Print("EX5_API_MAP_END");
   return INIT_SUCCEEDED;
}
void OnTick() {}
