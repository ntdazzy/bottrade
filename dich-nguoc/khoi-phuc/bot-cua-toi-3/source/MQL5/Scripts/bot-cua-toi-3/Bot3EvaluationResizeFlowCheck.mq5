#property strict
#include "Bot3ResizeFlowPendingApi.mqh"
input int FlowOnlyCase=-1;
double FlowPrevious;
#include "Bot3ResizeFlowVolumeApi.mqh"
#include "../../Include/bot-cua-toi-3/Bot3EvaluationResizeFlow.mqh"
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
   for(int i=0;i<9;i++) { n.value=ResizeVolumes[i];FileWriteLong(OutputFile,(long)n.bits); }
   WriteText(ActiveInputs.symbol);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>32) return 1;
   string folder="bot3-resize-flow\\"+CheckRun+"\\";
   int gate_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   int volume_file=FileOpen(folder+"volume-cases.bin",FILE_READ|FILE_BIN);
   InputFile=FileOpen(folder+"pending-cases.bin",FILE_READ|FILE_BIN);
   if(gate_file==INVALID_HANDLE || volume_file==INVALID_HANDLE || InputFile==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(gate_file),version=FileReadInteger(gate_file),count=FileReadInteger(gate_file);
   int pm=FileReadInteger(InputFile),pv=FileReadInteger(InputFile),pc=FileReadInteger(InputFile);
   int vm=FileReadInteger(volume_file),vv=FileReadInteger(volume_file),vb=FileReadInteger(volume_file),vc=FileReadInteger(volume_file);
   if(magic!=0x52464c31 || version!=1 || count<1 || count!=pc || pm!=RESIZE_MAGIC || pv!=1 || vm!=0x56525431 || vv!=1 || vb!=3 || vc!=count) return 3;
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
      ZeroMemory(ActiveInputs);ActiveInputs.symbol=CurrentCase.symbol;ActiveInputs.native_1d6d08=0;
      ActiveStop.magic=StopCase.magic;SelectedPosition=-1;SelectedOrder=-1;ResizeChanged=false;StopChanged=false;
      SeedStopTrade();ResizeLastTicket=(ulong)0x1122334455667788;ResizeCastText=(string)ResizePercent;
      V_check_state.effective_balance=current;
      string volume_name=folder+"volume-events-"+IntegerToString(id)+".bin";
      string pending_name=folder+"pending-events-"+IntegerToString(id)+".bin";
      V_output=FileOpen(volume_name,FILE_WRITE|FILE_BIN);OutputFile=FileOpen(pending_name,FILE_WRITE|FILE_BIN);
      if(V_output==INVALID_HANDLE || OutputFile==INVALID_HANDLE) { Fail(707);break; }
      FileWriteInteger(OutputFile,id);FileFlush(OutputFile);Print("RESIZE_FLOW_CASE:",id);
      bool changed=Bot3RefreshEvaluationPending(volume_enabled,distance,V_check_settings,V_check_state,V_withdrawal_enabled,V_check_peak_key,V_check_time_key,V_check_time,V_deal_time,V_check_context.weight_denominator,V_strategy_enabled,ActiveStop.magic,ResizeVirtual,ActiveInputs.symbol,V_check_suffix,ResizePercent,FlowPrevious,ResizeIndex,ResizeVolumes,ResizeLastTicket,CleanupResults,ActiveTrade,ActiveOptions);
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
