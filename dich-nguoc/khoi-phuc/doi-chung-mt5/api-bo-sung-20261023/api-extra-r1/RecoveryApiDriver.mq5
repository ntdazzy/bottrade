#property strict
#property version "1.00"
#import "RecoveryApiLibrary.ex5"
long P_Anchor(const long k,const double x,const string s);
#import

ulong probe_ticks=0;

int OnInit()
{
   if(!MQLInfoInteger(MQL_TESTER)) return INIT_FAILED;
   Print("RECOVERY_API_DRIVER_BEGIN:",P_Anchor(42731,0.0,"local-probe"));
   ulong started=GetTickCount64();
   while(!IsStopped() && GetTickCount64()-started<20000) Sleep(50);
   Print("RECOVERY_API_DRIVER_CAPTURE_WINDOW_END");
   return INIT_SUCCEEDED;
}

void OnTick()
{
   probe_ticks++;
}

double OnTester()
{
   Print("RECOVERY_API_DRIVER_TICKS:",probe_ticks);
   return (double)probe_ticks;
}

void OnDeinit(const int reason)
{
   Print("RECOVERY_API_DRIVER_END:",reason);
}
