"""Generate distance-cancel checkers using the verified pending SDK adapters."""
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
TEMPLATE=r'''#property strict
#include "BotNDistanceCancelApi.mqh"
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
#define BotNDeletePending ObservedResizeDelete
#include "../../Include/bot-cua-toi-N/BotNPendingDistanceCancel.mqh"
#undef BotNDeletePending
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="botN-pending-distance\\"+CheckRun+"\\";
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
      ZeroMemory(ActiveInputs);ActiveInputs.symbol=CurrentCase.symbol;HEADFLAG=0;
      ActiveStop.magic=StopCase.magic;SelectedPosition=-1;SelectedOrder=-1;ResizeChanged=false;StopChanged=false;DistanceChanged=false;
      ResizeMutationKind=0;SeedStopTrade();ResizeLastTicket=(ulong)0x1122334455667788;
      FileWriteInteger(OutputFile,row);
      BotNCancelDistantPending(DistanceEnabled,DistanceBuy!=0,ActiveStop.magic,ActiveInputs.symbol,
                               DistanceQuote,DistanceGap,ResizeLastTicket,ActiveTrade,ActiveOptions);
      EndEvents();WriteStopTrade();FileWriteLong(OutputFile,(long)SelectedOrder);FileWriteLong(OutputFile,(long)ResizeLastTicket);
      n.value=DistanceQuote;FileWriteLong(OutputFile,(long)n.bits);n.value=DistanceGap;FileWriteLong(OutputFile,(long)n.bits);
      FileWriteLong(OutputFile,(long)ActiveStop.magic);WriteText(ActiveInputs.symbol);
   }
   if(FileTell(InputFile)!=FileSize(InputFile)) Fail(802);
   FileClose(InputFile);FileClose(OutputFile);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 5;FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
'''
for bot in [1,3]:
    home=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    api=(home/f'Bot{bot}EvaluationPendingResizeCheck.mq5').read_text(encoding='utf-8-sig').split('int OnStart()',1)[0]
    api='void DistanceMutation(const int api,const int property);\n'+api
    api=api.replace('StopEvent(25,(ulong)property,(ulong)value,(ulong)(long)SelectedOrder);return value;','StopEvent(25,(ulong)property,(ulong)value,(ulong)(long)SelectedOrder);DistanceMutation(503,(int)property);return value;')
    api=api.replace('StopEvent(26,(ulong)property,(ulong)(long)SelectedOrder,0,0,0,value);return value;','StopEvent(26,(ulong)property,(ulong)(long)SelectedOrder,0,0,0,value);DistanceMutation(504,(int)property);return value;')
    api=api.replace('StopEvent(31,(ulong)property,value,(ulong)(long)SelectedOrder);DoubleBits n;','StopEvent(31,(ulong)property,value,(ulong)(long)SelectedOrder);DistanceMutation(507,(int)property);DoubleBits n;')
    (home/f'Bot{bot}DistanceCancelApi.mqh').write_text(api,encoding='utf-8',newline='\n')
    source=TEMPLATE.replace('HEADFLAG','ActiveInputs.native_6a3b4' if bot==1 else 'ActiveInputs.native_1d6d08').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}').replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}')
    (home/f'Bot{bot}PendingDistanceCancelCheck.mq5').write_text(source,encoding='utf-8',newline='\n')
    (home/f'Bot{bot}PendingDistanceCancelAPICompile.mq5').write_text(f'''#property strict
#include "../../Include/bot-cua-toi-{bot}/Bot{bot}PendingDistanceCancel.mqh"
void OnStart()
{{
   Bot{bot}PendingRequestState state;Bot{bot}TradeSendOptions options;ZeroMemory(state);ZeroMemory(options);
   string symbol="XAUUSD";int magic=42;double quote=100.,gap=1.;ulong ticket=0;
   Bot{bot}CancelDistantPending(0,true,magic,symbol,quote,gap,ticket,state,options);
}}
''',encoding='utf-8',newline='\n')
