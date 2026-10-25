// Supplied terminal, error, print, modify and close replies for the six real management blocks; no live trading.
#property strict
#property script_show_inputs
// Included before the macros so their own calls stay real; none of them loads the error message headers.
#include "../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VirtualStops.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementVirtualFinish.mqh"
input string CheckRun="";
union BlocksDoubleBits { double d;ulong u; };
int BlocksCalls=0,BlocksFault=0,BlocksScenario=0,BlocksModifyOk=0,BlocksErrorCode=0;
int BlocksDigits[4],BlocksDigitIndex=0,BlocksPointIndex=0;
ulong BlocksHash=0;
// Per-case settings, price and state given to the blocks, plus the supplied point and minimum volume replies.
double BlocksUnit=0,BlocksTrail=0,BlocksStep=0,BlocksStart=0,BlocksLimit=0,BlocksReference=0,BlocksAnchor=0;
double BlocksGap=0,BlocksFreeze=0,BlocksPoint=0,BlocksMinimum=0,BlocksLockStart=0,BlocksLockExtra=0;
double BlocksStepReference=0,BlocksStepDistance=0,BlocksCopiedStep=0,BlocksInitialStop=0;
double BlocksTicketNumber=0,BlocksCurrentStop=0,BlocksVolumes[9],BlocksLevels[9];
int BlocksEnabled=0,BlocksGapCount=0,BlocksMinimumSteps=0,BlocksCounter=0;
uchar BlocksBeforeOpen=0,BlocksShiftSetting=0,BlocksStepEnabled=0;
uint BlocksIndex=0,BlocksErrorCount=0;
ulong BlocksDeviation=0;
MqlTick BlocksTick;
Bot3PendingRequestState BlocksState;
Bot3TradeSendOptions BlocksOptions;
Bot3VirtualStopState BlocksTable;
// Keeps the first fault of the run; a later fault never replaces it.
void BlocksFail(const int code) { if(BlocksFault==0) BlocksFault=code; }
ulong BlocksBits(const double value) { BlocksDoubleBits b;b.d=value;return b.u; }
// FNV-1a 64 over the eight little-endian bytes of one word.
ulong BlocksHashWord(ulong hash,const ulong word)
{
   for(int j=0;j<8;j++) { hash^=(word>>(8*j))&255;hash*=(ulong)0x100000001b3; }
   return hash;
}
// FNV-1a 64 over the UTF-16LE bytes of a text.
ulong BlocksText(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      ushort c=StringGetCharacter(value,i);
      h^=(ulong)(c&255);h*=(ulong)0x100000001b3;
      h^=(ulong)(c>>8);h*=(ulong)0x100000001b3;
   }
   return h;
}
void BlocksTrace(const int api,const ulong a=0,const ulong b=0,const ulong v=0,const ulong w=0)
{
   ulong words[5];words[0]=(ulong)api;words[1]=a;words[2]=b;words[3]=v;words[4]=w;
   for(int i=0;i<5;i++) BlocksHash=BlocksHashWord(BlocksHash,words[i]);
   BlocksCalls++;
}
// Called after each API event. Targets: digits 1/3/4/5 and point 2/6 by call order, modify 7, error print 8,
// other print 9, minimum volume 10, close 11. Position, reference, anchor, step reference, initial stop,
// ticket number, volumes, point, minimum, enabled, gap count, minimum steps, flags and the error counter
// never change here.
void BlocksMutate(const int target)
{
   if(BlocksScenario!=target) return;
   BlocksUnit*=2.0;BlocksTrail+=.5;BlocksStep+=.125;BlocksStart+=.25;BlocksLimit+=.75;
   BlocksGap+=.125;BlocksFreeze+=.25;BlocksLockStart+=.5;BlocksLockExtra+=.25;
   BlocksStepDistance+=.25;BlocksCopiedStep+=.125;BlocksTick.bid+=.25;BlocksTick.ask+=.5;
   BlocksIndex=(BlocksIndex+1)%9;BlocksLevels[BlocksIndex]+=1.25;BlocksDeviation++;
   BlocksCounter=(int)((uint)BlocksCounter+1);BlocksCurrentStop+=1.25;
   BlocksTable.guard=(uchar)(((int)BlocksTable.guard+1)%3);
}
long BlocksSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS || BlocksDigitIndex>=4) { BlocksFail(1);return 0; }
   int index=BlocksDigitIndex;int digit=BlocksDigits[index];
   BlocksTrace(3,17,(ulong)(long)digit,(ulong)index);BlocksDigitIndex++;
   BlocksMutate(index==0 ? 1 : (index==1 ? 3 : (index==2 ? 4 : 5)));return (long)digit;
}
double BlocksSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="CHECK" || (property!=SYMBOL_POINT && property!=SYMBOL_VOLUME_MIN) ||
      (property==SYMBOL_POINT && BlocksPointIndex>=2)) { BlocksFail(2);return 0.0; }
   if(property==SYMBOL_VOLUME_MIN)
   {
      BlocksTrace(4,34,BlocksBits(BlocksMinimum));BlocksMutate(10);return BlocksMinimum;
   }
   int index=BlocksPointIndex;
   BlocksTrace(4,16,BlocksBits(BlocksPoint),(ulong)index);BlocksPointIndex++;
   BlocksMutate(index==0 ? 2 : 6);return BlocksPoint;
}
// The supplied code only: no event, no mutation and no counter change.
int BlocksGetLastError() { return BlocksErrorCode; }
bool BlocksStartsWith(const string text,const string prefix)
{
   return StringSubstr(text,0,StringLen(prefix))==prefix;
}
// Records the text built by the real message bodies and the counter at the print.
// The "error when" messages are covered by the "error" prefix.
void BlocksPrint(const string text)
{
   BlocksTrace(13,BlocksText(text),(ulong)BlocksErrorCount);
   bool is_error=BlocksStartsWith(text,"TrailStop") || BlocksStartsWith(text,"error");
   BlocksMutate(is_error ? 8 : 9);
}
// Records the request only; nothing is sent.
bool BlocksModify(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                  const ulong ticket,const double sl,const double tp)
{
   BlocksTrace(5,ticket,BlocksBits(sl),BlocksBits(tp),(ulong)(long)BlocksModifyOk);BlocksMutate(7);
   return BlocksModifyOk!=0;
}
// Records the received close arguments only: no price refresh and no request; callers ignore the result.
bool BlocksTryClose(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                    const ulong &deviation,const double &bid,const double &ask,
                    const double &gap,const double &freeze,const ulong ticket)
{
   BlocksTrace(6,ticket,deviation,BlocksBits(bid),BlocksBits(ask));
   BlocksTrace(7,BlocksBits(gap),BlocksBits(freeze));
   BlocksMutate(11);return true;
}
#define SymbolInfoInteger BlocksSymbolInteger
#define SymbolInfoDouble BlocksSymbolDouble
#define GetLastError BlocksGetLastError
#define Print BlocksPrint
#define Bot3ModifyPosition BlocksModify
#define Bot3TryClosePosition BlocksTryClose
// Messages and Bot3TradeErrors are first loaded here; with the block headers below, the messages,
// high-low and lock error reporters run their real bodies and texts on the supplied error code.
#include "../../Include/bot-cua-toi-3/Bot3ManagementMessages.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealDistance.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealSlippage.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealHighLow.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealLock.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealCounter.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealStore.mqh"
#undef SymbolInfoInteger
#undef SymbolInfoDouble
#undef GetLastError
#undef Print
#undef Bot3ModifyPosition
#undef Bot3TryClosePosition

bool BlocksIsByte(const int value) { return value>=0 && value<=255; }
// Rows 0..499 of both tables, the supplied guard, then only the ticket cells of the pattern;
// pattern 4 writes no ticket cell.
void BlocksFillTable(const uchar guard,const int pattern)
{
   ZeroMemory(BlocksTable);
   for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
   {
      BlocksTable.rows[row][0]=10000.0+row;BlocksTable.rows[row][1]=20000.0+row;
      BlocksTable.rows[row][2]=-30000.0-row;
      BlocksTable.take_rows[row][0]=40000.0+row;BlocksTable.take_rows[row][1]=-50000.0-row;
   }
   BlocksTable.guard=guard;
   if(pattern==0) BlocksTable.rows[0][0]=BlocksTicketNumber;
   else if(pattern==1) BlocksTable.rows[250][0]=BlocksTicketNumber;
   else if(pattern==2) BlocksTable.rows[499][0]=BlocksTicketNumber;
   else if(pattern==3)
   {
      BlocksTable.rows[1][0]=BlocksTicketNumber;BlocksTable.rows[17][0]=BlocksTicketNumber;
      BlocksTable.rows[499][0]=BlocksTicketNumber;
   }
   else if(pattern==5)
   {
      BlocksDoubleBits bits;bits.u=(ulong)0x7ff8000000000011;
      BlocksTable.rows[0][0]=bits.d;BlocksTable.rows[499][0]=BlocksTicketNumber;
   }
}
// Stop rows 0..499 with three cells each, then take rows 0..499 with two cells each.
ulong BlocksTableHash()
{
   ulong hash=(ulong)0xcbf29ce484222325;
   for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
      for(int cell=0;cell<3;cell++) hash=BlocksHashWord(hash,BlocksBits(BlocksTable.rows[row][cell]));
   for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
      for(int cell=0;cell<2;cell++) hash=BlocksHashWord(hash,BlocksBits(BlocksTable.take_rows[row][cell]));
   return hash;
}
// Calls the case's block on the per-case globals; only the distance block returns a value.
bool BlocksRunStage(const int stage,const bool buy,const uchar passed_flag,const uchar eligible_flag,
                    const ulong ticket,Bot3ManagedPosition &position,bool &changed)
{
   if(stage==0)
   {
      if(buy) return Bot3AdvanceDistanceBuyStop("CHECK",BlocksUnit,BlocksTrail,BlocksStep,BlocksStart,BlocksLimit,
                                                BlocksAnchor,BlocksGap,BlocksFreeze,position,BlocksTick,
                                                BlocksVolumes,BlocksIndex,changed,BlocksState,BlocksOptions,
                                                BlocksDeviation,BlocksErrorCount,ticket);
      return Bot3AdvanceDistanceSellStop("CHECK",BlocksUnit,BlocksTrail,BlocksStep,BlocksStart,BlocksLimit,
                                         BlocksAnchor,BlocksGap,BlocksFreeze,position,BlocksTick,
                                         BlocksVolumes,BlocksIndex,changed,BlocksState,BlocksOptions,
                                         BlocksDeviation,BlocksErrorCount,ticket);
   }
   if(stage==1)
   {
      if(buy) Bot3AdvanceSlippageRealBuyStop("CHECK",BlocksUnit,BlocksEnabled,passed_flag,BlocksReference,
                                             BlocksTrail,BlocksStart,BlocksLimit,BlocksGap,BlocksFreeze,
                                             position,BlocksTick,changed,BlocksState,BlocksOptions,
                                             BlocksErrorCount,ticket);
      else Bot3AdvanceSlippageRealSellStop("CHECK",BlocksUnit,BlocksEnabled,passed_flag,BlocksReference,
                                           BlocksTrail,BlocksStart,BlocksLimit,BlocksGap,BlocksFreeze,
                                           position,BlocksTick,changed,BlocksState,BlocksOptions,
                                           BlocksErrorCount,ticket);
   }
   else if(stage==2)
   {
      if(buy) Bot3AdvanceHighLowRealBuyStop("CHECK",BlocksEnabled,eligible_flag,BlocksGapCount,BlocksUnit,
                                            BlocksBeforeOpen,BlocksShiftSetting,BlocksGap,BlocksFreeze,
                                            BlocksLevels,BlocksIndex,position,BlocksTick,changed,BlocksState,
                                            BlocksOptions,BlocksErrorCount,ticket);
      else Bot3AdvanceHighLowRealSellStop("CHECK",BlocksEnabled,eligible_flag,BlocksGapCount,BlocksUnit,
                                          BlocksBeforeOpen,BlocksShiftSetting,BlocksGap,BlocksFreeze,
                                          BlocksLevels,BlocksIndex,position,BlocksTick,changed,BlocksState,
                                          BlocksOptions,BlocksErrorCount,ticket);
   }
   else if(stage==3)
   {
      if(buy) Bot3AdvanceRealLockBuyStop("CHECK",BlocksLockStart,BlocksLockExtra,BlocksUnit,BlocksGap,
                                         BlocksFreeze,position,BlocksTick,changed,BlocksState,BlocksOptions,
                                         BlocksErrorCount,ticket);
      else Bot3AdvanceRealLockSellStop("CHECK",BlocksLockStart,BlocksLockExtra,BlocksUnit,BlocksGap,
                                       BlocksFreeze,position,BlocksTick,changed,BlocksState,BlocksOptions,
                                       BlocksErrorCount,ticket);
   }
   else if(stage==4)
   {
      if(buy) Bot3AdvanceRealCounterBuyStop("CHECK",BlocksStepEnabled,BlocksStepReference,BlocksMinimumSteps,
                                            BlocksStepDistance,BlocksUnit,BlocksCopiedStep,BlocksAnchor,
                                            BlocksGap,BlocksFreeze,BlocksCounter,position,BlocksTick,changed,
                                            BlocksState,BlocksOptions,ticket);
      else Bot3AdvanceRealCounterSellStop("CHECK",BlocksStepEnabled,BlocksStepReference,BlocksMinimumSteps,
                                          BlocksStepDistance,BlocksUnit,BlocksCopiedStep,BlocksAnchor,
                                          BlocksGap,BlocksFreeze,BlocksCounter,position,BlocksTick,changed,
                                          BlocksState,BlocksOptions,ticket);
   }
   // Stage 5, the only value left after the case check.
   else Bot3StoreRealStop("CHECK",BlocksInitialStop,BlocksCurrentStop,BlocksTicketNumber,BlocksTable);
   return false;
}
// Reads the whole 456-byte case before any check; only a valid case reaches its block,
// then one 400-byte result with every final input value is written.
bool BlocksRunCase(const int source,const int output,const int expected_id)
{
   int id=FileReadInteger(source);int buy=FileReadInteger(source);int stage=FileReadInteger(source);
   BlocksScenario=FileReadInteger(source);BlocksModifyOk=FileReadInteger(source);
   BlocksErrorCode=FileReadInteger(source);
   for(int i=0;i<4;i++) BlocksDigits[i]=FileReadInteger(source);
   BlocksEnabled=FileReadInteger(source);BlocksGapCount=FileReadInteger(source);
   BlocksMinimumSteps=FileReadInteger(source);BlocksCounter=FileReadInteger(source);
   int passed_flag=FileReadInteger(source);int eligible_flag=FileReadInteger(source);
   int before_open=FileReadInteger(source);int shift_setting=FileReadInteger(source);
   int step_enabled=FileReadInteger(source);int guard=FileReadInteger(source);
   int prior_changed=FileReadInteger(source);int table_pattern=FileReadInteger(source);
   long ticket=FileReadLong(source);BlocksDeviation=(ulong)FileReadLong(source);
   BlocksIndex=(uint)FileReadInteger(source);BlocksErrorCount=(uint)FileReadInteger(source);
   Bot3ManagedPosition position;ZeroMemory(position);
   position.sl=FileReadDouble(source);position.tp=FileReadDouble(source);
   position.open_price=FileReadDouble(source);position.volume=FileReadDouble(source);
   ZeroMemory(BlocksTick);BlocksTick.bid=FileReadDouble(source);BlocksTick.ask=FileReadDouble(source);
   BlocksUnit=FileReadDouble(source);BlocksTrail=FileReadDouble(source);BlocksStep=FileReadDouble(source);
   BlocksStart=FileReadDouble(source);BlocksLimit=FileReadDouble(source);
   BlocksReference=FileReadDouble(source);BlocksAnchor=FileReadDouble(source);
   BlocksGap=FileReadDouble(source);BlocksFreeze=FileReadDouble(source);
   BlocksPoint=FileReadDouble(source);BlocksMinimum=FileReadDouble(source);
   BlocksLockStart=FileReadDouble(source);BlocksLockExtra=FileReadDouble(source);
   BlocksStepReference=FileReadDouble(source);BlocksStepDistance=FileReadDouble(source);
   BlocksCopiedStep=FileReadDouble(source);BlocksInitialStop=FileReadDouble(source);
   BlocksTicketNumber=FileReadDouble(source);BlocksCurrentStop=FileReadDouble(source);
   for(int i=0;i<9;i++) BlocksVolumes[i]=FileReadDouble(source);
   for(int i=0;i<9;i++) BlocksLevels[i]=FileReadDouble(source);
   if(id!=expected_id || (buy!=0 && buy!=1) || stage<0 || stage>5 || BlocksScenario<0 ||
      BlocksScenario>11 || BlocksIndex>8 || !BlocksIsByte(passed_flag) || !BlocksIsByte(eligible_flag) ||
      !BlocksIsByte(before_open) || !BlocksIsByte(shift_setting) || !BlocksIsByte(step_enabled) ||
      !BlocksIsByte(guard) || (prior_changed!=0 && prior_changed!=1) || table_pattern<0 ||
      table_pattern>5 || (BlocksModifyOk!=0 && BlocksModifyOk!=1)) return false;
   BlocksCalls=0;BlocksDigitIndex=0;BlocksPointIndex=0;BlocksHash=(ulong)0xcbf29ce484222325;
   ZeroMemory(BlocksState);ZeroMemory(BlocksOptions);BlocksFillTable((uchar)guard,table_pattern);
   BlocksBeforeOpen=(uchar)before_open;BlocksShiftSetting=(uchar)shift_setting;
   BlocksStepEnabled=(uchar)step_enabled;
   bool changed=prior_changed!=0;
   bool returned=BlocksRunStage(stage,buy!=0,(uchar)passed_flag,(uchar)eligible_flag,(ulong)ticket,
                                position,changed);
   FileWriteInteger(output,id);FileWriteInteger(output,(int)returned);FileWriteInteger(output,(int)changed);
   FileWriteInteger(output,BlocksCounter);FileWriteInteger(output,(int)BlocksTable.guard);
   FileWriteInteger(output,(int)BlocksIndex);FileWriteInteger(output,(int)BlocksErrorCount);
   FileWriteLong(output,(long)BlocksDeviation);
   FileWriteDouble(output,position.sl);FileWriteDouble(output,position.tp);
   FileWriteDouble(output,position.open_price);FileWriteDouble(output,position.volume);
   FileWriteDouble(output,BlocksTick.bid);FileWriteDouble(output,BlocksTick.ask);
   FileWriteDouble(output,BlocksUnit);FileWriteDouble(output,BlocksTrail);FileWriteDouble(output,BlocksStep);
   FileWriteDouble(output,BlocksStart);FileWriteDouble(output,BlocksLimit);
   FileWriteDouble(output,BlocksReference);FileWriteDouble(output,BlocksAnchor);
   FileWriteDouble(output,BlocksGap);FileWriteDouble(output,BlocksFreeze);
   FileWriteDouble(output,BlocksPoint);FileWriteDouble(output,BlocksMinimum);
   FileWriteDouble(output,BlocksLockStart);FileWriteDouble(output,BlocksLockExtra);
   FileWriteDouble(output,BlocksStepReference);FileWriteDouble(output,BlocksStepDistance);
   FileWriteDouble(output,BlocksCopiedStep);FileWriteDouble(output,BlocksInitialStop);
   FileWriteDouble(output,BlocksTicketNumber);FileWriteDouble(output,BlocksCurrentStop);
   for(int i=0;i<9;i++) FileWriteDouble(output,BlocksVolumes[i]);
   for(int i=0;i<9;i++) FileWriteDouble(output,BlocksLevels[i]);
   FileWriteInteger(output,BlocksCalls);FileWriteLong(output,(long)BlocksHash);
   FileWriteLong(output,(long)BlocksTableHash());
   return true;
}
// Writes the result header and every case in order; a bad case stops the run before its call.
void BlocksRunCases(const int source,const string path,const int magic,const int version,const int count)
{
   int output=FileOpen(path,FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { BlocksFail(8);return; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
      if(!BlocksRunCase(source,output,i)) { BlocksFail(9);break; }
   FileClose(output);
   if(FileTell(source)!=FileSize(source)) BlocksFail(10);
}

int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot3-management-real-blocks\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d524233 || version!=1 || count<1 || count>100000 ||
      FileSize(source)!=(ulong)12+(ulong)count*456) BlocksFail(7);
   else BlocksRunCases(source,folder+"mql5-results.bin",magic,version,count);
   FileClose(source);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,BlocksFault);FileWriteInteger(status,count);FileClose(status);
   // The macros are undefined above, so this is the terminal Print and never reaches a case hash.
   Print("Bot3ManagementRealBlocksCheck:",BlocksFault,",",count);return BlocksFault;
}
