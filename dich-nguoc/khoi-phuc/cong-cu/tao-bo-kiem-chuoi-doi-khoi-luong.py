"""Reuse verified SDK check helpers to build the joined resize-flow checker."""
from pathlib import Path
import re
ROOT=Path(__file__).resolve().parents[1]
TEMPLATE=r'''#property strict
#include "BotNResizeFlowPendingApi.mqh"
input int FlowOnlyCase=-1;
double FlowPrevious;
#include "BotNResizeFlowVolumeApi.mqh"
#include "../../Include/bot-cua-toi-N/BotNEvaluationResizeFlow.mqh"
void CopyFlowFile(const int target,const string name)
{
   int file=FileOpen(name,FILE_READ|FILE_BIN);
   if(file==INVALID_HANDLE) { Fail(701);return; }
   int size=(int)FileSize(file);uchar bytes[];ArrayResize(bytes,size);
   if(size>0 && (int)FileReadArray(file,bytes,0,size)!=size) Fail(702);
   if(size>0) FileWriteArray(target,bytes,0,size);
   FileClose(file);
}
void FinishPendingFlow()
{
   EndEvents();WriteStopTrade();FileWriteLong(OutputFile,(long)SelectedOrder);FileWriteLong(OutputFile,(long)ResizeLastTicket);
   DoubleBits n;
   for(int i=0;i<100;i++) for(int j=0;j<2;j++) { n.value=CleanupResults[i][j];FileWriteLong(OutputFile,(long)n.bits); }
   FileWriteLong(OutputFile,(long)ResizeIndex);
   for(int i=0;i<ARRAY_COUNT;i++) { n.value=ResizeVolumes[i];FileWriteLong(OutputFile,(long)n.bits); }
   WriteText(ActiveInputs.symbol);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>32) return 1;
   string folder="botN-resize-flow\\"+CheckRun+"\\";
   int gate_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   int volume_file=FileOpen(folder+"volume-cases.bin",FILE_READ|FILE_BIN);
   InputFile=FileOpen(folder+"pending-cases.bin",FILE_READ|FILE_BIN);
   if(gate_file==INVALID_HANDLE || volume_file==INVALID_HANDLE || InputFile==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(gate_file),version=FileReadInteger(gate_file),count=FileReadInteger(gate_file);
   int pm=FileReadInteger(InputFile),pv=FileReadInteger(InputFile),pc=FileReadInteger(InputFile);
   int vm=FileReadInteger(volume_file),vv=FileReadInteger(volume_file),vb=FileReadInteger(volume_file),vc=FileReadInteger(volume_file);
   if(magic!=0x52464c31 || version!=1 || count<1 || count!=pc || pm!=RESIZE_MAGIC || pv!=1 || vm!=0x56525431 || vv!=1 || vb!=N || vc!=count) return 3;
   int casts=FileOpen(folder+"cast-results.bin",FILE_WRITE|FILE_BIN),fixed=FileOpen(folder+"fixed-results.bin",FILE_WRITE|FILE_BIN);
   if(casts==INVALID_HANDLE || fixed==INVALID_HANDLE) return 4;
   FileWriteInteger(casts,0x56525431);FileWriteInteger(casts,1);FileWriteInteger(casts,0);
   FileWriteInteger(fixed,0x56525431);FileWriteInteger(fixed,1);FileWriteInteger(fixed,0);
   int normals=0,cast_count=0,fixed_count=0;
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(gate_file),fatal=FileReadInteger(gate_file);
      FileReadLong(gate_file);FileReadLong(gate_file);FileReadInteger(gate_file);FileReadLong(gate_file);
      if(fatal==0) normals++;
      if(FileReadInteger(volume_file)!=id) Fail(703);FileReadInteger(volume_file);V_ReadCase(volume_file);
      if(!ReadCase(InputFile) || !ReadStopCase(InputFile) || !ReadCleanupCase(InputFile) || !ReadResizeExtra(InputFile)) Fail(704);
      for(int j=0;j<ArraySize(V_replies34);j++) { V_Measure(casts,V_replies34[j],false);cast_count++; }
      for(int j=0;j<ArraySize(V_replies35);j++) { V_Measure(casts,V_replies35[j],false);cast_count++; }
      V_Measure(casts,ResizePercent,false);cast_count++;
      V_Measure(fixed,V_check_context.balance,true);V_Measure(fixed,V_check_context.equity,true);V_Measure(fixed,V_check_state.highest_balance,true);fixed_count+=3;
      double withdrawn=0.0;
      for(int j=0;j<ArraySize(V_tickets);j++)
         if(V_tickets[j]!=0 && (int)V_deal_types[j]==2 && V_deal_times[j]>V_deal_time && V_profits[j]<0.0) withdrawn+=V_profits[j];
      V_Measure(fixed,-withdrawn,true);fixed_count++;
   }
   FileSeek(casts,8,SEEK_SET);FileWriteInteger(casts,cast_count);FileClose(casts);
   FileSeek(fixed,8,SEEK_SET);FileWriteInteger(fixed,fixed_count);FileClose(fixed);
   FileSeek(gate_file,12,SEEK_SET);FileSeek(volume_file,16,SEEK_SET);FileSeek(InputFile,12,SEEK_SET);
   int master=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(master==INVALID_HANDLE) return 5;
   FileWriteInteger(master,magic);FileWriteInteger(master,version);FileWriteInteger(master,normals);FileFlush(master);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(gate_file),fatal=FileReadInteger(gate_file);DoubleBits n;
      n.bits=(ulong)FileReadLong(gate_file);double current=n.value;n.bits=(ulong)FileReadLong(gate_file);FlowPrevious=n.value;
      uchar volume_enabled=(uchar)FileReadInteger(gate_file);n.bits=(ulong)FileReadLong(gate_file);double distance=n.value;
      if(!ReadCase(InputFile) || !ReadStopCase(InputFile) || !ReadCleanupCase(InputFile) || !ReadResizeExtra(InputFile)) { Fail(705);break; }
      if(FileReadInteger(volume_file)!=id) Fail(706);FileReadInteger(volume_file);V_ReadCase(volume_file);
      if(FlowOnlyCase<0 ? fatal!=0 : id!=FlowOnlyCase) continue;
      ZeroMemory(ActiveInputs);ActiveInputs.symbol=CurrentCase.symbol;HEADFLAG=0;
      ActiveStop.magic=StopCase.magic;SelectedPosition=-1;SelectedOrder=-1;ResizeChanged=false;StopChanged=false;
      SeedStopTrade();ResizeLastTicket=(ulong)0x1122334455667788;ResizeCastText=(string)ResizePercent;
      V_check_state.effective_balance=current;
      string volume_name=folder+"volume-events-"+IntegerToString(id)+".bin";
      string pending_name=folder+"pending-events-"+IntegerToString(id)+".bin";
      V_output=FileOpen(volume_name,FILE_WRITE|FILE_BIN);OutputFile=FileOpen(pending_name,FILE_WRITE|FILE_BIN);
      if(V_output==INVALID_HANDLE || OutputFile==INVALID_HANDLE) { Fail(707);break; }
      FileWriteInteger(OutputFile,id);FileFlush(OutputFile);Print("RESIZE_FLOW_CASE:",id);
      bool changed=CALL_FLOW;
      FinishPendingFlow();FileClose(OutputFile);FileClose(V_output);
      int vol_read=FileOpen(volume_name,FILE_READ|FILE_BIN),pen_read=FileOpen(pending_name,FILE_READ|FILE_BIN);
      if(vol_read==INVALID_HANDLE || pen_read==INVALID_HANDLE) { Fail(708);break; }
      int volume_size=(int)FileSize(vol_read),pending_size=(int)FileSize(pen_read);FileClose(vol_read);FileClose(pen_read);
      FileWriteInteger(master,id);FileWriteInteger(master,(int)changed);n.value=FlowPrevious;FileWriteLong(master,(long)n.bits);
      FileWriteInteger(master,volume_size);CopyFlowFile(master,volume_name);V_output=master;V_State();
      FileWriteInteger(master,pending_size);CopyFlowFile(master,pending_name);FileFlush(master);
   }
   FileClose(master);FileClose(gate_file);FileClose(volume_file);FileClose(InputFile);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 6;
   FileWriteInteger(status,Fault);FileWriteInteger(status,normals);FileClose(status);return Fault;
}
'''
for bot in [1,3]:
    h=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    pending=(h/f'Bot{bot}EvaluationPendingResizeCheck.mq5').read_text(encoding='utf-8-sig').split('int OnStart()',1)[0]
    (h/f'Bot{bot}ResizeFlowPendingApi.mqh').write_text(pending,encoding='utf-8',newline='\n')
    api=(h/f'Bot{bot}VolumeRuntimeCheck.mq5').read_text(encoding='utf-8-sig').split('int OnStart()',1)[0]
    api=re.sub(r'^input .*\n','',api,flags=re.M)
    names=['DoubleBits','Bits','ReadText','WriteText','State','Event','Reply','ReadCase','Measure','output','event_count',
      'check_settings','check_context','check_state','strategy_enabled','check_time','deal_time','times','check_symbol','check_suffix','check_peak_key','check_time_key','currencies',
      'withdrawal_enabled','select_ok','restore_ok','tester','reported','mutate_after','mutate_index','prices','replies26','replies34','replies35','replies36','tickets','deal_types','deal_times','profits',
      'counters26','counters34','counters35','counters36','symbol_calls','currency_calls','price_calls','clock_calls','select_calls','MockAccount','MockSymbol','MockMql','MockTime','MockSelect','MockTotal','MockTicket','Find','MockInteger','MockDouble','MockSet','MockCurrency','MockClose','MockPrint','MockAlert','MockFixed']
    for name in sorted(names,key=len,reverse=True):api=re.sub(r'\b'+name+r'\b','V_'+name,api)
    api=api.replace('strategy_index','ResizeIndex').replace('check_volumes','ResizeVolumes')
    require='uint ResizeIndex;double ResizeVolumes['+str(8 if bot==1 else 9)+'];'
    assert require in api;api=api.replace(require,'')
    needle='}\nvoid V_Event(';assert needle in api;api=api.replace(needle,'   FileWriteLong(V_output,(long)V_Bits(FlowPrevious));\n}\nvoid V_Event(',1)
    for name in ['AccountInfoDouble','SymbolInfoDouble','MQLInfoInteger','TimeCurrent','HistorySelect','HistoryDealsTotal','HistoryDealGetTicket','HistoryDealGetInteger','HistoryDealGetDouble','GlobalVariableSet','AccountInfoString','iClose','Print','Alert','DoubleToString']:api+='\n#undef '+name
    (h/f'Bot{bot}ResizeFlowVolumeApi.mqh').write_text(api+'\n',encoding='utf-8',newline='\n')
    extra='V_check_context.weight_denominator,V_strategy_enabled,' if bot==3 else ''
    call=f'Bot{bot}RefreshEvaluationPending(volume_enabled,distance,V_check_settings,V_check_state,V_withdrawal_enabled,V_check_peak_key,V_check_time_key,V_check_time,V_deal_time,{extra}ActiveStop.magic,ResizeVirtual,ActiveInputs.symbol,V_check_suffix,ResizePercent,FlowPrevious,ResizeIndex,ResizeVolumes,ResizeLastTicket,CleanupResults,ActiveTrade,ActiveOptions)'
    headflag='ActiveInputs.native_6a3b4' if bot==1 else 'ActiveInputs.native_1d6d08'
    source=TEMPLATE.replace('CALL_FLOW',call).replace('HEADFLAG',headflag).replace('ARRAY_COUNT',str(8 if bot==1 else 9)).replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}').replace('vb!=N',f'vb!={bot}')
    (h/f'Bot{bot}EvaluationResizeFlowCheck.mq5').write_text(source,encoding='utf-8',newline='\n')
