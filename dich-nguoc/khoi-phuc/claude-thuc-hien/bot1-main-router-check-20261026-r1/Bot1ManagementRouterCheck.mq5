// Router check: supplied position services, iTime, Print and Bot1ManagePositions around
// Bot1RoutePositionManagement; no orders.
#property strict
#property script_show_inputs
// Included before the macros for the types; its guard stops the router header from including
// it again, so the macros never reach the real manager.
#include "../../Include/bot-cua-toi-1/Bot1PositionManagement.mqh"
input string CheckRun="";
union RouterDoubleBits { double d;ulong u; };
struct RouterInput
{
   int id,index,timeframe,after_first_frame,buy_reply,sell_reply,change_first_bar,change_buy;
   int license_valid,tick_management,bar_override,profile,shrink_after_buy,magic;
   long previous,observed,second,after_first_bar;
};
struct RouterPosition
{
   ulong ticket;
   long magic,type;
   string symbol;
};
RouterInput RouterCase;
Bot1PositionManagementSettings RouterCfg;
Bot1PositionManagementState RouterShared;
Bot1PendingRequestState RouterRequests;
Bot1TradeSendOptions RouterOptions;
RouterPosition RouterPositions[6];
long RouterBars[8];
double RouterLevelsBuy[8],RouterLevelsSell[8];
uchar RouterLicenseValid=0,RouterTickManagement=0,RouterBarOverride=0;
int RouterFrame=0,RouterFault=0,RouterEvents=0,RouterTimeCalls=0,RouterLive=0,RouterSelected=-1;
int RouterTotalCalls=0,RouterBuyCalls=0,RouterSellCalls=0;
ulong RouterHash=0,RouterDeviation=0;
void RouterFail(const int value) { if(RouterFault==0) RouterFault=value; }
ulong RouterBits(const double value) { RouterDoubleBits bits;bits.d=value;return bits.u; }
ulong RouterHashWord(ulong hash,const ulong value)
{
   for(int i=0;i<8;i++) { hash^=(value>>(i*8))&255;hash*=(ulong)0x100000001b3; }
   return hash;
}
// FNV-1a 64 over the UTF-16LE characters, low byte first, without a terminating NUL.
ulong RouterText(const string value)
{
   ulong hash=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      const ushort c=StringGetCharacter(value,i);
      hash^=(ulong)(c&255);hash*=(ulong)0x100000001b3;
      hash^=(ulong)(c>>8);hash*=(ulong)0x100000001b3;
   }
   return hash;
}
// One event per supplied call: five words hashed in order, each low byte first.
void RouterEvent(const int api,const ulong a,const ulong b,const ulong c,const ulong d)
{
   ulong words[5];words[0]=(ulong)(long)api;words[1]=a;words[2]=b;words[3]=c;words[4]=d;
   for(int i=0;i<5;i++) RouterHash=RouterHashWord(RouterHash,words[i]);
   RouterEvents++;
}
bool RouterSelectedValid() { return RouterSelected>=0 && RouterSelected<RouterLive; }
// Same size and the same bits in every entry.
bool RouterSameLevels(const double &levels[],const double &expected[])
{
   if(ArraySize(levels)!=ArraySize(expected)) return false;
   for(int i=0;i<ArraySize(expected);i++)
      if(RouterBits(levels[i])!=RouterBits(expected[i])) return false;
   return true;
}
// total_calls counts this call first; profile 7 answers 0 on the second call only.
int FakePositionsTotal()
{
   RouterTotalCalls++;
   const int value=(RouterCase.profile==7 && RouterTotalCalls==2) ? 0 : RouterLive;
   RouterEvent(5,(ulong)(long)RouterTotalCalls,(ulong)(long)value,(ulong)(long)RouterLive,0);
   return value;
}
// A zero ticket or an index outside the live rows answers 0 and keeps the previous selection.
// The event is written after the selection.
ulong FakePositionGetTicket(const int index)
{
   ulong ticket=0;
   if(index>=0 && index<RouterLive && RouterPositions[index].ticket!=0)
   {
      ticket=RouterPositions[index].ticket;
      RouterSelected=index;
   }
   RouterEvent(6,(ulong)(long)index,ticket,(ulong)(long)RouterSelected,0);
   return ticket;
}
// Magic and type of the selected row are returned as full 64-bit values.
long FakePositionGetInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   long value=0;
   if(property!=POSITION_MAGIC && property!=POSITION_TYPE) RouterFail(41);
   if(!RouterSelectedValid()) RouterFail(40);
   else if(property==POSITION_MAGIC) value=RouterPositions[RouterSelected].magic;
   else if(property==POSITION_TYPE) value=RouterPositions[RouterSelected].type;
   RouterEvent(7,(ulong)(long)(int)property,(ulong)value,(ulong)(long)RouterSelected,0);
   return value;
}
string FakePositionGetString(const ENUM_POSITION_PROPERTY_STRING property)
{
   string value="";
   if(property!=POSITION_SYMBOL) RouterFail(43);
   if(!RouterSelectedValid()) RouterFail(42);
   else if(property==POSITION_SYMBOL) value=RouterPositions[RouterSelected].symbol;
   RouterEvent(8,(ulong)(long)(int)property,RouterText(value),(ulong)(long)RouterSelected,0);
   return value;
}
// Call 0 answers observed, later calls second. The event is written before call 0 moves
// RouterFrame and, with change_first_bar, the bar slot of the case index.
datetime FakeiTime(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   if(symbol!="CHECK") RouterFail(20);
   if(shift!=1) RouterFail(21);
   if(RouterTimeCalls>=2) RouterFail(22);
   const long value=RouterTimeCalls==0 ? RouterCase.observed : RouterCase.second;
   RouterEvent(1,(ulong)(uint)frame,1,(ulong)RouterBars[RouterCase.index],(ulong)value);
   if(RouterTimeCalls==0)
   {
      RouterFrame=RouterCase.after_first_frame;
      if(RouterCase.change_first_bar==1) RouterBars[RouterCase.index]=RouterCase.after_first_bar;
   }
   RouterTimeCalls++;
   return (datetime)value;
}
// Records the text only; nothing is printed.
void FakePrint(const string value)
{
   if(value!="Licence not valid!") RouterFail(23);
   RouterEvent(4,RouterText(value),0,0,0);
}
// Same signature as the real manager. The event reads the arguments, never the globals; after a
// buy event change_buy and shrink_after_buy move the globals. A sell call changes nothing.
bool FakeBot1ManagePositions(const bool buy,const Bot1PositionManagementSettings &settings,
                             Bot1PositionManagementState &shared,const double &levels[],
                             Bot1PendingRequestState &requests,Bot1TradeSendOptions &options,
                             const ulong &deviation)
{
   if(settings.symbol!="CHECK") RouterFail(30);
   if(deviation!=RouterDeviation) RouterFail(31);
   if(!(buy ? RouterSameLevels(levels,RouterLevelsBuy) : RouterSameLevels(levels,RouterLevelsSell)))
      RouterFail(32);
   if((buy ? RouterBuyCalls : RouterSellCalls)>=1) RouterFail(33);
   RouterEvent(buy ? 2 : 3,(ulong)(long)shared.counter,(ulong)(long)settings.finish.mode,
               (ulong)shared.strategy_index,RouterBits(levels[0]));
   if(buy) RouterBuyCalls++;
   else RouterSellCalls++;
   if(buy && RouterCase.change_buy==1)
   {
      RouterShared.counter++;RouterCfg.finish.mode++;
      RouterShared.strategy_index=(RouterShared.strategy_index+1)%8;
      RouterBars[RouterCase.index]+=10;
   }
   if(buy && RouterCase.shrink_after_buy==1) { RouterLive=0;RouterSelected=-1; }
   return buy ? RouterCase.buy_reply!=0 : RouterCase.sell_reply!=0;
}
#define iTime FakeiTime
#define PositionsTotal FakePositionsTotal
#define PositionGetTicket FakePositionGetTicket
#define PositionGetInteger FakePositionGetInteger
#define PositionGetString FakePositionGetString
#define Print FakePrint
#define Bot1ManagePositions FakeBot1ManagePositions
#include "../../Include/bot-cua-toi-1/Bot1ManagementRouter.mqh"
#undef iTime
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef PositionGetString
#undef Print
#undef Bot1ManagePositions

void RouterAdd(const ulong ticket,const long magic,const long type,const string symbol)
{
   RouterPositions[RouterLive].ticket=ticket;RouterPositions[RouterLive].magic=magic;
   RouterPositions[RouterLive].type=type;RouterPositions[RouterLive].symbol=symbol;
   RouterLive++;
}
// k is the case magic widened with its sign; wide is 2^32, past the int32 range.
// Profile 0 leaves the list empty.
void RouterSetPositions()
{
   const long k=(long)RouterCase.magic;
   const long wide=4294967296;
   ZeroMemory(RouterPositions);RouterLive=0;
   switch(RouterCase.profile)
   {
      case 1: RouterAdd(101,k,0,"CHECK");break;
      case 2: RouterAdd(102,k,1,"CHECK");break;
      case 3:
         RouterAdd(0,k,0,"CHECK");RouterAdd(202,k+1,0,"CHECK");RouterAdd(203,k,2,"CHECK");
         RouterAdd(204,k,0,"OTHER");RouterAdd(205,k,0,"CHECK");RouterAdd(206,k,1,"CHECK");
         break;
      case 4: RouterAdd(301,k+wide,0,"CHECK");RouterAdd(302,k+wide,1,"CHECK");break;
      case 5: RouterAdd(401,k,wide,"CHECK");RouterAdd(402,k,wide+1,"CHECK");break;
      case 6: RouterAdd(501,k,0,"OTHER");RouterAdd(502,k,1,"OTHER");break;
      case 7: RouterAdd(601,k,0,"CHECK");RouterAdd(602,k,1,"CHECK");break;
   }
}
void RouterInitialize()
{
   ZeroMemory(RouterCfg);ZeroMemory(RouterShared);ZeroMemory(RouterRequests);ZeroMemory(RouterOptions);
   RouterCfg.symbol="CHECK";RouterCfg.magic=RouterCase.magic;RouterCfg.finish.mode=1;
   RouterShared.counter=7;RouterShared.strategy_index=(uint)((RouterCase.index+1)%8);
   RouterShared.last_ticket=999;
   for(int i=0;i<8;i++) { RouterBars[i]=100+i;RouterLevelsBuy[i]=10.0+i;RouterLevelsSell[i]=20.0+i; }
   RouterBars[RouterCase.index]=RouterCase.previous;RouterFrame=RouterCase.timeframe;
   // The three flags keep the case values unchanged.
   RouterLicenseValid=(uchar)RouterCase.license_valid;
   RouterTickManagement=(uchar)RouterCase.tick_management;
   RouterBarOverride=(uchar)RouterCase.bar_override;
   RouterDeviation=(ulong)0x0123456789abcdef;RouterHash=(ulong)0xcbf29ce484222325;
   RouterSelected=-1;RouterTotalCalls=0;RouterBuyCalls=0;RouterSellCalls=0;
   RouterEvents=0;RouterTimeCalls=0;
   RouterSetPositions();
}
bool RouterFlag(const int value) { return value==0 || value==1; }
// Reads all 88 bytes of the case field by field before any check.
bool RouterReadCase(const int file,const int id)
{
   RouterCase.id=FileReadInteger(file);RouterCase.index=FileReadInteger(file);
   RouterCase.timeframe=FileReadInteger(file);RouterCase.after_first_frame=FileReadInteger(file);
   RouterCase.buy_reply=FileReadInteger(file);RouterCase.sell_reply=FileReadInteger(file);
   RouterCase.change_first_bar=FileReadInteger(file);RouterCase.change_buy=FileReadInteger(file);
   RouterCase.license_valid=FileReadInteger(file);RouterCase.tick_management=FileReadInteger(file);
   RouterCase.bar_override=FileReadInteger(file);RouterCase.profile=FileReadInteger(file);
   RouterCase.shrink_after_buy=FileReadInteger(file);RouterCase.magic=FileReadInteger(file);
   RouterCase.previous=FileReadLong(file);RouterCase.observed=FileReadLong(file);
   RouterCase.second=FileReadLong(file);RouterCase.after_first_bar=FileReadLong(file);
   return RouterCase.id==id && RouterCase.index>=0 && RouterCase.index<=7 &&
          RouterCase.profile>=0 && RouterCase.profile<=7 &&
          RouterFlag(RouterCase.buy_reply) && RouterFlag(RouterCase.sell_reply) &&
          RouterFlag(RouterCase.change_first_bar) && RouterFlag(RouterCase.change_buy) &&
          RouterFlag(RouterCase.license_valid) && RouterFlag(RouterCase.tick_management) &&
          RouterFlag(RouterCase.bar_override) && RouterFlag(RouterCase.shrink_after_buy);
}
// 128 bytes <12i2Q8q: id, returned, timeframe, counter, mode, shared.strategy_index, events,
// selected, total_calls, buy_calls, sell_calls, live_count, last_ticket, ordered hash, 8 bars.
void RouterWriteResult(const int file,const int id,const bool returned)
{
   FileWriteInteger(file,id);FileWriteInteger(file,(int)returned);FileWriteInteger(file,RouterFrame);
   FileWriteInteger(file,RouterShared.counter);FileWriteInteger(file,RouterCfg.finish.mode);
   FileWriteInteger(file,(int)RouterShared.strategy_index);FileWriteInteger(file,RouterEvents);
   FileWriteInteger(file,RouterSelected);FileWriteInteger(file,RouterTotalCalls);
   FileWriteInteger(file,RouterBuyCalls);FileWriteInteger(file,RouterSellCalls);
   FileWriteInteger(file,RouterLive);
   FileWriteLong(file,(long)RouterShared.last_ticket);FileWriteLong(file,(long)RouterHash);
   for(int i=0;i<8;i++) FileWriteLong(file,RouterBars[i]);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot1-management-router\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d525431 || version!=1 || count<1 || count>10000 || FileSize(source)!=(ulong)12+(ulong)count*88)
   { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int id=0;id<count;id++)
   {
      if(!RouterReadCase(source,id)) { RouterFail(9);break; }
      RouterInitialize();
      // strategy_index is the captured case value, not RouterShared.strategy_index.
      bool returned=Bot1RoutePositionManagement(RouterLicenseValid,RouterTickManagement,
                                                RouterBarOverride,RouterFrame,(uint)RouterCase.index,
                                                RouterBars,RouterCfg,RouterShared,RouterLevelsBuy,
                                                RouterLevelsSell,RouterRequests,RouterOptions,
                                                RouterDeviation);
      RouterWriteResult(output,id,returned);
   }
   if(FileTell(source)!=FileSize(source)) RouterFail(10);
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,RouterFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot1ManagementRouterCheck:",RouterFault,",",count);return RouterFault;
}
