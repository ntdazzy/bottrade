#property strict
#include "Bot3DistanceCancelApi.mqh"
int DistanceEnabled,DistanceBuy,DistanceMutationKind;
double DistanceQuote,DistanceGap;
bool DistanceChanged=false;
void DistanceMutation(const int api,const int property)
{
   if(DistanceChanged) return;
   if(api==507 && property==9)
   {
      if(DistanceMutationKind==1) DistanceQuote=DistanceBuy!=0 ? 1000. : -1000.;
      else if(DistanceMutationKind==2) DistanceGap=100.;
      else if(DistanceMutationKind==5) ResizeLastTicket=777;
      else return;
   }
   else if(api==503 && property==15 && DistanceMutationKind==3) ActiveStop.magic++;
   else if(api==504 && property==0 && DistanceMutationKind==4) ActiveInputs.symbol="Đổi mã";
   else return;
   DistanceChanged=true;
}
#define OrdersTotal PendingTotal
#define OrderGetTicket PendingTicket
#define OrderGetInteger PendingInteger
#define OrderGetString PendingString
#define OrderGetDouble PendingDouble
#define Bot3DeletePending ObservedResizeDelete
#include "../../Include/bot-cua-toi-3/Bot3PendingDistanceCancel.mqh"
#undef Bot3DeletePending
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-pending-distance\\"+CheckRun+"\\";
   InputFile=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(InputFile==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(InputFile),version=FileReadInteger(InputFile),count=FileReadInteger(InputFile);
   if(magic!=0x44434131 || version!=1 || count<1) { FileClose(InputFile);return 3; }
   OutputFile=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(OutputFile==INVALID_HANDLE) { FileClose(InputFile);return 4; }
   FileWriteInteger(OutputFile,magic);FileWriteInteger(OutputFile,version);FileWriteInteger(OutputFile,count);
   for(int row=0;row<count;row++)
   {
      if(!ReadCase(InputFile) || !ReadStopCase(InputFile) || !ReadCleanupCase(InputFile) || !ReadResizeExtra(InputFile)) { Fail(801);break; }
      DistanceEnabled=FileReadInteger(InputFile);DistanceBuy=FileReadInteger(InputFile);DoubleBits n;
      n.bits=(ulong)FileReadLong(InputFile);DistanceQuote=n.value;n.bits=(ulong)FileReadLong(InputFile);DistanceGap=n.value;DistanceMutationKind=FileReadInteger(InputFile);
      ZeroMemory(ActiveInputs);ActiveInputs.symbol=CurrentCase.symbol;ActiveInputs.native_1d6d08=0;
      ActiveStop.magic=StopCase.magic;SelectedPosition=-1;SelectedOrder=-1;ResizeChanged=false;StopChanged=false;DistanceChanged=false;
      ResizeMutationKind=0;SeedStopTrade();ResizeLastTicket=(ulong)0x1122334455667788;
      FileWriteInteger(OutputFile,row);
      Bot3CancelDistantPending(DistanceEnabled,DistanceBuy!=0,ActiveStop.magic,ActiveInputs.symbol,
                               DistanceQuote,DistanceGap,ResizeLastTicket,ActiveTrade,ActiveOptions);
      EndEvents();WriteStopTrade();FileWriteLong(OutputFile,(long)SelectedOrder);FileWriteLong(OutputFile,(long)ResizeLastTicket);
      n.value=DistanceQuote;FileWriteLong(OutputFile,(long)n.bits);n.value=DistanceGap;FileWriteLong(OutputFile,(long)n.bits);
      FileWriteLong(OutputFile,(long)ActiveStop.magic);WriteText(ActiveInputs.symbol);
   }
   if(FileTell(InputFile)!=FileSize(InputFile)) Fail(802);
   FileClose(InputFile);FileClose(OutputFile);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 5;FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
