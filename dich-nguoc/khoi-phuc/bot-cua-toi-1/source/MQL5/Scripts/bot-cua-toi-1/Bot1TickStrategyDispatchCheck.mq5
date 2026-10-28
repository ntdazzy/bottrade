// Supplied positions/time/digits; actual array resizing. No orders.
#property strict
#property script_show_inputs
input string CheckRun="";
input int OnlyCase=-1;

int Fixture=INVALID_HANDLE,EventCount=0;
bool FullSnapshots=false;
long EventCountPosition=0;
int CaseKind,CaseSide,CaseDelay,Selected=-1,PositionTotal;
long CaseDigits,CaseTicket,CaseNow;
double CasePrice,CaseDistance,CurrentUnit;

long OpenTickets[],PositionTypes[];
ulong PositionTickets[];
int Hits[9],ControlApi,ControlHit,ControlKind,ControlRow,FailResizeCall;
long ControlInteger;
double ControlValues[3];
union MatrixBits { double d;long q; };

double ReadDouble(const int file)
{
   MatrixBits value;value.q=FileReadLong(file);return value.d;
}
void WriteDouble(const int file,const double number)
{
   MatrixBits value;value.d=number;FileWriteLong(file,value.q);
}
string ReadText(const int file)
{
   int size=FileReadInteger(file);
   if(size<0 || size>2048) return "";
   return size==0 ? "" : FileReadString(file,size);
}
void WriteText(const int file,const string text)
{
   int size=StringLen(text);FileWriteInteger(file,size);
   if(size>0) FileWriteString(file,text,size);
}
void WriteSnapshot(const int file);
void ApplyControl(const int api);
void BeginEvent(const int api)
{
   FileWriteInteger(Fixture,api);WriteSnapshot(Fixture);Hits[api]++;
}
void EndEvent(const int api)
{
   ApplyControl(api);WriteSnapshot(Fixture);
   EventCount++;
   long tail=(long)FileTell(Fixture);
   FileSeek(Fixture,EventCountPosition,SEEK_SET);FileWriteInteger(Fixture,EventCount);
   FileSeek(Fixture,tail,SEEK_SET);FileFlush(Fixture);
}
void WriteArray(const int file,const long &values[])
{
   int size=ArraySize(values);bool series=ArrayGetAsSeries(values);
   FileWriteInteger(file,size);FileWriteInteger(file,(int)series);
   for(int physical=0;physical<size;physical++)
      FileWriteLong(file,values[series ? size-1-physical : physical]);
}
long MatrixInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   BeginEvent(1);FileWriteInteger(Fixture,(int)property);WriteText(Fixture,symbol);
   FileWriteLong(Fixture,CaseDigits);EndEvent(1);return CaseDigits;
}
datetime MatrixTime()
{
   BeginEvent(2);FileWriteLong(Fixture,CaseNow);EndEvent(2);return (datetime)CaseNow;
}
int MatrixResize(long &values[],const int count,const int reserve=0)
{
   BeginEvent(3);FileWriteInteger(Fixture,count);FileWriteInteger(Fixture,reserve);
   WriteArray(Fixture,values);
   int result=(FailResizeCall<0 || Hits[3]==FailResizeCall) ? -1 : ArrayResize(values,count,reserve);
   FileWriteInteger(Fixture,result);WriteArray(Fixture,values);EndEvent(3);return result;
}
int MatrixTotal()
{
   BeginEvent(4);FileWriteInteger(Fixture,PositionTotal);EndEvent(4);return PositionTotal;
}
ulong MatrixTicket(const int index)
{
   BeginEvent(5);ulong value=0;
   if(index>=0 && index<ArraySize(PositionTickets))
   {
      value=PositionTickets[index];
      if(value!=0) Selected=index;
   }
   FileWriteInteger(Fixture,index);FileWriteLong(Fixture,(long)value);
   EndEvent(5);return value;
}
long MatrixPosition(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   BeginEvent(6);long value=Selected>=0 ? PositionTypes[Selected] : 0;
   FileWriteInteger(Fixture,(int)property);FileWriteLong(Fixture,value);
   EndEvent(6);return value;
}
void MatrixWarning(const string first,const int slots,const string second,const int positions,
                   const string third,const long ticket,const string fourth)
{
   BeginEvent(7);WriteText(Fixture,first);FileWriteInteger(Fixture,slots);
   WriteText(Fixture,second);FileWriteInteger(Fixture,positions);
   WriteText(Fixture,third);FileWriteLong(Fixture,ticket);WriteText(Fixture,fourth);
   EndEvent(7);
}
#define SymbolInfoInteger MatrixInteger
#define TimeCurrent MatrixTime
#define ArrayResize MatrixResize
#define PositionsTotal MatrixTotal
#define PositionGetTicket MatrixTicket
#define PositionGetInteger MatrixPosition
#define Print MatrixWarning
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
#undef SymbolInfoInteger
#undef TimeCurrent
#undef ArrayResize
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef Print
#include "../../Include/bot-cua-toi-1/Bot1TickStrategyPreparation.mqh"

void WriteRouteText(const int file,const string value);
#include "../../Include/bot-cua-toi-1/Bot1StrategyCycle.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StrategySelection.mqh"
Bot1PreparationInputs JoinInputs;Bot1EvaluationPrefixState JoinState;
#define Table JoinState.management.table
#define CaseSymbol JoinInputs.symbol
Bot1StrategySelectionInput LoopFlags;int LoopCalls,LoopIndexes[8],LoopEffectCall,LoopEffectField,LoopEffectValue,LoopFault,LoopCleanupApi,LoopCleanupHit;bool LoopHL,LoopHour;
void SetLoopFlag(const int field,const bool value){switch(field){case 0:LoopFlags.run_strategy_a=value;break;case 1:LoopFlags.run_strategy_b=value;break;case 2:LoopFlags.run_strategy_c=value;break;case 3:LoopFlags.run_strategy_d=value;break;case 4:LoopFlags.run_strategy_e=value;break;case 5:LoopFlags.run_strategy_f=value;break;case 6:LoopFlags.run_strategy_g=value;break;case 7:LoopFlags.run_strategy_h=value;break;}}
uint LoopMask(){uint mask=0;if(LoopFlags.run_strategy_a)mask|=1;if(LoopFlags.run_strategy_b)mask|=2;if(LoopFlags.run_strategy_c)mask|=4;if(LoopFlags.run_strategy_d)mask|=8;if(LoopFlags.run_strategy_e)mask|=16;if(LoopFlags.run_strategy_f)mask|=32;if(LoopFlags.run_strategy_g)mask|=64;if(LoopFlags.run_strategy_h)mask|=128; return mask;}
Bot1EntryLevelDecision LoopProbe(const uint index,const bool use_hl,
                                            const Bot1ProfileAdjustments &adjustments,
                                            Bot1PreparationInputs &inputs,
                                            const Bot1StrategyContextInputs &context_inputs,
                                            Bot1ProfileRuntimeState &profile_state,
                                            Bot1StrategyContextState &context_state,
                                            Bot1PreparationState &preparation,
                                            Bot1NfpExecution &execution,
                                            const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                            const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                            const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                            Bot1NewsEvents &events,MqlDateTime &cached_calendar,
                                            const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                            Bot1NewsSelection &selection,const Bot1FridaySettings &friday,uchar &friday_closed,
                                            Bot1SpreadSettings &spread_settings,double &spread,
                                            Bot1PendingQueue &queue,Bot1PendingRestoreSettings &restore,
                                            Bot1LevelCacheSettings &level_settings,
                                            uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                            Bot1EntryLoopSettings &loop_settings,Bot1EntryLoopState &loop_state,
                                            Bot1VolumeSettings &volume_settings,Bot1VolumeState &volume_state,
                                            const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                            long &last_check,long &last_deal_time,const string &suffix,double &volumes[],
                                            const uchar &panel_show,const uchar &panel_tester,const int &panel_mode,
                                            const double &panel_trade_risk,const int &panel_balance_step,
                                            const uchar &day_switch_filter,const double &balance_change_percent,
                                            double &previous_balance,Bot1EvaluationPrefixSettings &prefix,
                                            Bot1EvaluationPrefixState &state,Bot1DisplayState &display,
                                            const bool hour_changed,int &closed_trades[],
                                            Bot1StrategyHistoryCache &history_cache,
                                            double &strategy_totals[],double &strategy_average[])
{
   BeginEvent(8);FileWriteInteger(Fixture,(int)index);FileWriteInteger(Fixture,(int)LoopMask());FileWriteInteger(Fixture,(int)use_hl);FileWriteInteger(Fixture,(int)hour_changed);
   for(int r=0;r<500;r++)for(int c=0;c<3;c++)WriteDouble(Fixture,state.management.table.rows[r][c]);
   WriteArray(Fixture,OpenTickets);WriteRouteText(Fixture,inputs.symbol);
   if(LoopCalls>=8 || use_hl!=LoopHL || hour_changed!=LoopHour)LoopFault|=1;
   else LoopIndexes[LoopCalls++]=(int)index;
   if(LoopCalls==LoopEffectCall && LoopCleanupApi==0)SetLoopFlag(LoopEffectField,LoopEffectValue!=0);
   EndEvent(8);return BOT1_LEVEL_STOP;
}
#define Bot1SetupEvaluateAndUpdateStatistics LoopProbe
#include "../../Include/bot-cua-toi-1/Bot1TickStrategyDispatch.mqh"
#undef Bot1SetupEvaluateAndUpdateStatistics


void WriteSnapshot(const int file)
{
   uint error=GetLastError();
   FileWriteInteger(file,(int)Table.guard);FileWriteLong(file,Table.reported_ticket);
   FileWriteInteger(file,CaseDelay);WriteDouble(file,CurrentUnit);WriteText(file,CaseSymbol);
   FileWriteInteger(file,Selected);FileWriteInteger(file,ArraySize(OpenTickets));
   FileWriteInteger(file,(int)ArrayGetAsSeries(OpenTickets));
   for(int column=0;column<3;column++) WriteDouble(file,Table.rows[ControlRow][column]);
   if(FullSnapshots)
      for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
         for(int column=0;column<3;column++) WriteDouble(file,Table.rows[row][column]);
   FileWriteLong(file,(long)error);
}
void ApplyControl(const int api)
{
   if(api==LoopCleanupApi && Hits[api]==LoopCleanupHit)SetLoopFlag(LoopEffectField,LoopEffectValue!=0);
   if(api!=ControlApi || Hits[api]!=ControlHit) return;
   if(ControlKind==1) CurrentUnit=ControlValues[0];
   if(ControlKind==2) CaseDelay=(int)ControlInteger;
   if(ControlKind==3 || ControlKind==7) Table.guard=(uchar)ControlInteger;
   if(ControlKind==4 || ControlKind==7)
      for(int column=0;column<3;column++) Table.rows[ControlRow][column]=ControlValues[column];
   if(ControlKind==5) Table.reported_ticket=ControlInteger;
}
bool LoadCase(const int file,int &id,bool &fatal)
{
   ZeroMemory(Table);
   id=FileReadInteger(file);CaseKind=FileReadInteger(file);fatal=FileReadInteger(file)!=0;
   int guard=FileReadInteger(file);CaseSide=FileReadInteger(file);CaseDelay=FileReadInteger(file);
   CaseDigits=FileReadLong(file);CaseTicket=FileReadLong(file);
   Table.reported_ticket=FileReadLong(file);CaseNow=FileReadLong(file);
   CasePrice=ReadDouble(file);CaseDistance=ReadDouble(file);CurrentUnit=ReadDouble(file);CaseSymbol=ReadText(file);
   int series=FileReadInteger(file),size=FileReadInteger(file);
   if(size<0 || size>4096 || CaseKind<0 || CaseKind>3 || guard<0 || guard>255 || (series!=0 && series!=1)) return false;
   ArrayFree(OpenTickets);ArraySetAsSeries(OpenTickets,false);
   if(ArrayResize(OpenTickets,size,0)!=size) return false;
   for(int index=0;index<size;index++) OpenTickets[index]=FileReadLong(file);
   ArraySetAsSeries(OpenTickets,series!=0);
   PositionTotal=FileReadInteger(file);int count=FileReadInteger(file);
   if(count<0 || count>1024) return false;
   if(ArrayResize(PositionTickets,count)!=count || ArrayResize(PositionTypes,count)!=count) return false;
   for(int index=0;index<count;index++)
   {
      PositionTickets[index]=(ulong)FileReadLong(file);PositionTypes[index]=FileReadLong(file);
   }
   int fill=FileReadInteger(file);
   MatrixBits nan;nan.q=(long)0x7ff8000000000001;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
   {
      if(fill==1 || fill==3)
      {
         Table.rows[row][0]=(fill==1 ? 1.0 : -1.0)*(double)(row+1);
         Table.rows[row][1]=100.0+(double)row*0.125;
         Table.rows[row][2]=2000.0+(double)row;
      }
      if(fill==2) { Table.rows[row][0]=nan.d;Table.rows[row][1]=111.25; }
   }
   count=FileReadInteger(file);
   if(count<0 || count>500) return false;
   for(int index=0;index<count;index++)
   {
      int row=FileReadInteger(file);if(row<0 || row>=BOT1_VIRTUAL_STOP_ROWS) return false;
      for(int column=0;column<3;column++) Table.rows[row][column]=ReadDouble(file);
   }
   ControlApi=FileReadInteger(file);ControlHit=FileReadInteger(file);
   ControlKind=FileReadInteger(file);ControlRow=FileReadInteger(file);
   ControlInteger=FileReadLong(file);
   for(int column=0;column<3;column++) ControlValues[column]=ReadDouble(file);
   FailResizeCall=FileReadInteger(file);
   if(ControlRow<0 || ControlRow>=BOT1_VIRTUAL_STOP_ROWS || ControlApi<0 || ControlApi>7 ||
      ControlKind<0 || ControlKind>7 || ControlKind==6 || fill<0 || fill>3) return false;
   Table.guard=(uchar)guard;Selected=-1;ArrayInitialize(Hits,0);
   return true;
}
string ReadChart(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void WriteRouteText(const int file,const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(file,n);if(n>0)FileWriteString(file,value,n);}

int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 2;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 2;
   }
   string folder="bot1-tick-dispatch\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"api-fixtures.bin")) return 3;
   int handle_in=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN|FILE_UNICODE);
   if(handle_in==INVALID_HANDLE) return 4;
   int magic=FileReadInteger(handle_in),version=FileReadInteger(handle_in);
   int count=FileReadInteger(handle_in),normal=FileReadInteger(handle_in);
   if(magic!=0x54534d31 || version!=3 || count<1 || normal<1 || OnlyCase>=count) return 5;
   int expected=OnlyCase>=0 ? 1 : normal;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   Fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(output==INVALID_HANDLE || Fixture==INVALID_HANDLE) return 6;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,expected);
   FileWriteInteger(Fixture,magic);FileWriteInteger(Fixture,version);FileWriteInteger(Fixture,expected);
   Bot1NfpFilterSettings nfp_settings;Bot1NfpFilterState nfp;Bot1ReleaseFilterSettings interest_settings,cpi_settings;Bot1ReleaseFilterState interest,cpi;Bot1NewsEvents events;Bot1NewsSelection selection;Bot1NfpExecution execution;MqlDateTime cached;
   Bot1LevelCacheSettings levels;uint current=0;long bars[100];double upper[100],lower[100];Bot1EntryLoopSettings loop;Bot1EntryLoopState loop_state;Bot1VolumeSettings volume;Bot1VolumeState volume_state;
   string peak="",time="",suffix="";long last_check=0,last_deal=0;double volumes[8];uchar show=0,tester=0,day_switch=0;int mode=0,balance_step=0;double risk=0,change=0,previous=0,spread=0;
   Bot1PendingRestoreSettings restore;Bot1SpreadSettings spread_settings;Bot1PendingQueue queue;Bot1FridaySettings friday;uchar friday_closed=0;long nfp_history[300],interest_history[300],cpi_history[300];Bot1EvaluationPrefixSettings prefix;Bot1DisplayState display;
   Bot1PreparationState preparation;Bot1ProfileRuntimeState profile_state;Bot1ProfileAdjustments adjustments;Bot1StrategyContextInputs context_inputs;Bot1StrategyContextState context_state;
   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(selection);ZeroMemory(execution);ZeroMemory(cached);ZeroMemory(levels);ZeroMemory(loop);ZeroMemory(loop_state);ZeroMemory(volume);ZeroMemory(volume_state);ZeroMemory(restore);ZeroMemory(spread_settings);ZeroMemory(queue);ZeroMemory(friday);ZeroMemory(prefix);ZeroMemory(JoinState);ZeroMemory(display);ZeroMemory(JoinInputs);ZeroMemory(preparation);ZeroMemory(profile_state);ZeroMemory(adjustments);ZeroMemory(context_inputs);ZeroMemory(context_state);
   ArrayInitialize(bars,0);ArrayInitialize(upper,0);ArrayInitialize(lower,0);ArrayInitialize(volumes,0);ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);JoinInputs.symbol=_Symbol;context_inputs.base_magic=0;

   int loop_closed[8];double loop_total[8],loop_average[8];Bot1StrategyHistoryCache loop_cache;

   int processed=0;
   for(int index=0;index<count;index++)
   {
      int id=0;bool fatal=false;
      if(!LoadCase(handle_in,id,fatal) || id!=index) return 7;
      uint route_error=(uint)FileReadInteger(handle_in);uchar virtual_flag=(uchar)FileReadInteger(handle_in);string chart=ReadChart(handle_in);
      int mask=FileReadInteger(handle_in);LoopEffectCall=FileReadInteger(handle_in);LoopEffectField=FileReadInteger(handle_in);LoopEffectValue=FileReadInteger(handle_in);LoopHL=FileReadInteger(handle_in)!=0;LoopHour=FileReadInteger(handle_in)!=0;LoopCleanupApi=FileReadInteger(handle_in);LoopCleanupHit=FileReadInteger(handle_in);
      for(int i=0;i<8;i++)SetLoopFlag(i,(mask&(1<<i))!=0);LoopCalls=0;LoopFault=0;ArrayInitialize(LoopIndexes,-1);

      if((OnlyCase<0 && fatal) || (OnlyCase>=0 && OnlyCase!=id)) continue;
      FullSnapshots=fatal && OnlyCase>=0;
      FileWriteInteger(Fixture,id);EventCountPosition=(long)FileTell(Fixture);
      FileWriteInteger(Fixture,0);FileWriteInteger(Fixture,(int)FullSnapshots);EventCount=0;
      Print("VIRTUAL_MATRIX_CASE:",id);FileFlush(Fixture);FileFlush(output);
      MatrixBits result;result.q=0;
      ResetLastError();if(route_error!=0)SetUserError((ushort)(route_error-65536));
      if(CaseKind==0) result.q=(long)Bot1RunConfiguredTick(chart,virtual_flag,OpenTickets,LoopFlags,LoopHL,adjustments,JoinInputs,context_inputs,profile_state,context_state,preparation,execution,nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,nfp_history,interest_history,cpi_history,selection,friday,friday_closed,spread_settings,spread,queue,restore,levels,current,bars,upper,lower,loop,loop_state,volume,volume_state,false,peak,time,last_check,last_deal,suffix,volumes,show,tester,mode,risk,balance_step,day_switch,change,previous,prefix,JoinState,display,LoopHour,loop_closed,loop_cache,loop_total,loop_average);
      if(CaseKind==1) result.d=Bot1VirtualStopLevel(Table,OpenTickets,CaseSymbol,CurrentUnit,CaseSide,CasePrice,CaseDistance,CaseTicket);
      if(CaseKind==2) result.q=(long)Bot1VirtualStopDelayPassed(Table,CaseDelay,CaseTicket);
      if(CaseKind==3) Bot1VirtualStopStamp(Table,CaseTicket);
      FileWriteInteger(output,id);FileWriteInteger(output,CaseKind);FileWriteLong(output,result.q);
      WriteSnapshot(output);
      for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
         for(int column=0;column<3;column++) WriteDouble(output,Table.rows[row][column]);
      WriteArray(output,OpenTickets);WriteRouteText(output,chart);WriteRouteText(output,CaseSymbol);FileWriteInteger(output,LoopCalls);FileWriteInteger(output,(int)LoopMask());FileWriteInteger(output,LoopFault);for(int i=0;i<8;i++)FileWriteInteger(output,LoopIndexes[i]);processed++;
   }
   if(FileTell(handle_in)!=FileSize(handle_in) || processed!=expected) return 8;
   FileClose(handle_in);FileClose(output);FileClose(Fixture);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,0);FileWriteInteger(status,processed);FileClose(status);
   Print("Bot1VirtualStopsCheck:0,",processed);return 0;
}
