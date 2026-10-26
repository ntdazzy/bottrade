// Pending submission check: supplied digits, margin, volume, account limit, orders total, send, sleep,
// error-text and print replies around the real Bot1SubmitPendingAfterPrice; nothing reaches the account.
#property strict
#property script_show_inputs
// Included before the macros so their own calls stay real; their guards stop the submission header
// from loading them again, so the macros reach only the submission body.
#include "../../Include/bot-cua-toi-1/Bot1PriceLevels.mqh"
#include "../../Include/bot-cua-toi-1/Bot1Margin.mqh"
#include "../../Include/bot-cua-toi-1/Bot1VolumeValidation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1TradeSend.mqh"
#include "../../Include/bot-cua-toi-1/Bot1TradeErrors.mqh"
// Bot1RoundPrice and Bot1SubmissionDifference stay real. The fakes are defined after the header, once
// the settings type exists.
#define SymbolInfoInteger FakeSymbolInfoInteger
#define Bot1MarginGuard FakeMarginGuard
#define Bot1ValidateVolume FakeValidateVolume
#define AccountInfoInteger FakeAccountInfoInteger
#define OrdersTotal FakeOrdersTotal
#define Bot1OpenPending FakeOpenPending
#define Sleep FakeSleep
#define GetLastError FakeGetLastError
#define Bot1TradeErrorText FakeTradeErrorText
#define Print FakePrint
#include "../../Include/bot-cua-toi-1/Bot1PendingSubmission.mqh"
#undef SymbolInfoInteger
#undef Bot1MarginGuard
#undef Bot1ValidateVolume
#undef AccountInfoInteger
#undef OrdersTotal
#undef Bot1OpenPending
#undef Sleep
#undef GetLastError
#undef Bot1TradeErrorText
#undef Print

input string CheckRun="";
union PendingDoubleBits { double d;ulong u; };
struct PendingCheckCase
{
   int id,buy,check_free_margin,omit_real_sl_tp,virtual_expiration,strategy_magic,strategy_index;
   int digit0,digit1,digit2,margin_reply,volume_reply,orders_total,initial_accept,retry_count;
   int retry_accept_mask,initial_error,final_error,cache_mode,mutation_at,case_tag;
   uint error_count;
   long expiration,order_limit;
   double base_price,unit,stop_distance,take_distance,minimum_stop_price,minimum_freeze_price,ask,bid;
   string symbol,comment;
};
PendingCheckCase Case;
// Fixture passed to the block; the fakes change only these globals, never the block's locals.
Bot1PendingSubmissionSettings S;
double V[8];
uint Index=0,Errors=0;
double Table[][2];
Bot1PendingRequestState T;
Bot1TradeSendOptions O;
int Fault=0,FakeLastError=0,Events=0,MutationCount=0;
int DigitsCalls=0,MarginCalls=0,VolumeCalls=0,AccountLimitCalls=0,OrdersTotalCalls=0;
int SendCalls=0,SleepCalls=0,PrintCalls=0,ErrorCalls=0;
ulong Hash=0;

// Keeps the first fault of the run; a later fault never replaces it.
void Fail(const int code) { if(Fault==0) Fault=code; }
ulong Bits(const double value) { PendingDoubleBits b;b.d=value;return b.u; }
double FromBits(const ulong value) { PendingDoubleBits b;b.u=value;return b.d; }
ulong Signed(const long value) { return (ulong)value; }
// FNV-1a 64 over the eight bytes of one word, low byte first.
void HashWord(const ulong word)
{
   for(int i=0;i<8;i++) { Hash^=(word>>(8*i))&255;Hash*=(ulong)0x100000001b3; }
}
// FNV-1a 64 from a fresh basis over each UTF-16 unit, low byte then high byte.
ulong TextHash(const string text)
{
   ulong hash=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(text);i++)
   {
      ushort unit=StringGetCharacter(text,i);
      hash^=(ulong)(unit&255);hash*=(ulong)0x100000001b3;
      hash^=(ulong)(unit>>8);hash*=(ulong)0x100000001b3;
   }
   return hash;
}
void BeginEvent(const int kind) { Events++;HashWord(Signed(kind)); }
// Once per case, at the trigger named by mutation_at: 1..3 digits calls, 4 margin, 5 volume,
// 6 account limit, 7 first send, 8 first sleep, 9 second send, 10 orders total.
// Event 9 comes before any change; order_limit and orders_total keep the values read from the case.
void ApplyMutation(const int trigger)
{
   if(Case.mutation_at!=trigger || MutationCount!=0) return;
   BeginEvent(9);HashWord(Signed(trigger));MutationCount++;
   S.symbol="NEXT";S.comment="changed";S.unit=0.25;S.stop_distance=7.25;S.take_distance=9.5;
   S.expiration=(datetime)9876543210;S.strategy_magic=-77;
   S.omit_real_sl_tp=(uchar)(S.omit_real_sl_tp==0 ? 255 : 0);S.virtual_expiration=255;
   Index=(Index+1)%8;
   for(int i=0;i<8;i++) V[i]=0.25*(i+5);
   S.ask=Case.base_price-5.0;S.bid=Case.base_price+5.0;
   S.minimum_freeze_price=2.125;S.minimum_stop_price=1.25;
   T.magic=(ulong)0xfedcba9876543210;O.async_mode=5;O.log_level=-2;O.margin_mode=2;
}

// Each fake reads its own arguments and writes its event before any mutation and before returning.
// A fourth digits call is outside the contract: fault 20 and 0, with no event, count or mutation.
long FakeSymbolInfoInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop)
{
   if(DigitsCalls>=3) { Fail(20);return 0; }
   long reply=DigitsCalls==0 ? Case.digit0 : (DigitsCalls==1 ? Case.digit1 : Case.digit2);
   BeginEvent(1);HashWord(Signed((int)prop));HashWord(TextHash(symbol));HashWord(Signed(reply));
   DigitsCalls++;ApplyMutation(DigitsCalls);
   return reply;
}
bool FakeMarginGuard(const string symbol,const ENUM_ORDER_TYPE type,const double volume)
{
   BeginEvent(2);HashWord(TextHash(symbol));HashWord(Signed((int)type));HashWord(Bits(volume));
   HashWord(Signed(Case.margin_reply));
   MarginCalls++;ApplyMutation(4);
   return Case.margin_reply!=0;
}
bool FakeValidateVolume(const string symbol,const double volume)
{
   BeginEvent(3);HashWord(TextHash(symbol));HashWord(Bits(volume));HashWord(Signed(Case.volume_reply));
   VolumeCalls++;ApplyMutation(5);
   return Case.volume_reply!=0;
}
// The property passed (ACCOUNT_LIMIT_ORDERS is 47) and the full 64-bit reply, never a bool.
long FakeAccountInfoInteger(const ENUM_ACCOUNT_INFO_INTEGER prop)
{
   long reply=Case.order_limit;
   BeginEvent(4);HashWord(Signed((int)prop));HashWord(Signed(reply));
   AccountLimitCalls++;ApplyMutation(6);
   return reply;
}
// The signed int32 count, sign-extended into its word.
int FakeOrdersTotal()
{
   int reply=Case.orders_total;
   BeginEvent(10);HashWord(Signed(reply));
   OrdersTotalCalls++;ApplyMutation(10);
   return reply;
}
// Same signature as the real sender; nothing is prepared or sent. A fifth call is this check's own
// stop against an endless retry loop: fault 21, error 999 and false, with no event, count or mutation.
bool FakeOpenPending(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                     const int strategy_magic,const uchar virtual_expiration,const string symbol,
                     const ENUM_ORDER_TYPE type,const double volume,const double price,
                     const double sl,const double tp,const string comment,const datetime expiration)
{
   int ordinal=SendCalls;
   if(ordinal>=4) { Fail(21);FakeLastError=999;return false; }
   int reply=Case.initial_accept;
   if(ordinal>0) reply=(int)(((uint)Case.retry_accept_mask>>(ordinal-1))&1);
   BeginEvent(5);
   HashWord(Signed((int)type));HashWord(Bits(volume));HashWord(Bits(price));HashWord(Bits(sl));HashWord(Bits(tp));
   HashWord(Signed((long)expiration));HashWord(Signed(strategy_magic));HashWord((ulong)virtual_expiration);
   HashWord(TextHash(symbol));HashWord(TextHash(comment));HashWord(state.magic);
   HashWord((ulong)options.async_mode);HashWord(Signed(options.log_level));HashWord(Signed(options.margin_mode));
   HashWord(Signed(reply));
   SendCalls++;
   FakeLastError=ordinal==0 ? Case.initial_error : (ordinal>=Case.retry_count ? Case.final_error : 132);
   if(ordinal==0) ApplyMutation(7);
   if(ordinal==1) ApplyMutation(9);
   return reply!=0;
}
// No real wait.
void FakeSleep(const int milliseconds)
{
   BeginEvent(6);HashWord(Signed(milliseconds));
   SleepCalls++;
   if(SleepCalls==1) ApplyMutation(8);
}
// The supplied code only: no event.
int FakeGetLastError() { return FakeLastError; }
// Counts through the argument the block passes, not through Errors.
string FakeTradeErrorText(const int code,uint &counter)
{
   uint old=counter;counter++;
   string text="error-"+IntegerToString(code);
   BeginEvent(7);HashWord(Signed(code));HashWord((ulong)old);HashWord((ulong)counter);HashWord(TextHash(text));
   ErrorCalls++;
   return text;
}
void FakePrint(const string text)
{
   BeginEvent(8);HashWord(TextHash(text));
   PrintCalls++;
}

bool Available(const int file,const long bytes) { return (long)FileTell(file)+bytes<=(long)FileSize(file); }
bool Flag(const int value) { return value==0 || value==1; }
bool Within(const int value,const int high) { return value>=0 && value<=high; }
// An int32 count of UTF-16 units, then exactly that many units without a terminating null.
// Returns 0; 9 for a count outside 0..128 or a unit the string cannot keep; 12 for missing bytes.
int ReadText(const int file,string &text)
{
   text="";
   if(!Available(file,4)) return 12;
   int length=FileReadInteger(file);
   if(length<0 || length>128) return 9;
   if(!Available(file,2*length)) return 12;
   for(int i=0;i<length;i++)
   {
      ushort unit=(ushort)FileReadInteger(file,SHORT_VALUE);
      text+=ShortToString(unit);
      if(StringLen(text)!=i+1 || StringGetCharacter(text,i)!=unit) return 9;
   }
   return 0;
}
// Reads the record in file order, then checks it. Returns 0, 9 (invalid data) or 12 (missing bytes).
// orders_total and order_limit take any signed value and are not checked.
int ReadCase(const int file,const int id)
{
   if(!Available(file,168)) return 12;
   Case.id=FileReadInteger(file);Case.buy=FileReadInteger(file);
   Case.check_free_margin=FileReadInteger(file);Case.omit_real_sl_tp=FileReadInteger(file);
   Case.virtual_expiration=FileReadInteger(file);Case.strategy_magic=FileReadInteger(file);
   Case.strategy_index=FileReadInteger(file);
   Case.digit0=FileReadInteger(file);Case.digit1=FileReadInteger(file);Case.digit2=FileReadInteger(file);
   Case.margin_reply=FileReadInteger(file);Case.volume_reply=FileReadInteger(file);
   Case.orders_total=FileReadInteger(file);Case.initial_accept=FileReadInteger(file);
   Case.retry_count=FileReadInteger(file);Case.retry_accept_mask=FileReadInteger(file);
   Case.initial_error=FileReadInteger(file);Case.final_error=FileReadInteger(file);
   Case.cache_mode=FileReadInteger(file);Case.mutation_at=FileReadInteger(file);
   Case.error_count=(uint)FileReadInteger(file);Case.case_tag=FileReadInteger(file);
   Case.expiration=FileReadLong(file);Case.order_limit=FileReadLong(file);
   Case.base_price=FileReadDouble(file);Case.unit=FileReadDouble(file);
   Case.stop_distance=FileReadDouble(file);Case.take_distance=FileReadDouble(file);
   Case.minimum_stop_price=FileReadDouble(file);Case.minimum_freeze_price=FileReadDouble(file);
   Case.ask=FileReadDouble(file);Case.bid=FileReadDouble(file);
   int strings=ReadText(file,Case.symbol);
   if(strings==0) strings=ReadText(file,Case.comment);
   if(strings!=0) return strings;
   bool valid=Case.id==id && Flag(Case.buy) && Flag(Case.margin_reply) && Flag(Case.volume_reply) &&
              Flag(Case.initial_accept) && Within(Case.check_free_margin,255) &&
              Within(Case.omit_real_sl_tp,255) && Within(Case.virtual_expiration,255) &&
              Within(Case.strategy_index,7) && Within(Case.retry_count,3) && Within(Case.cache_mode,5) &&
              Within(Case.mutation_at,10);
   return valid ? 0 : 9;
}
// Fresh fixture for one case, after its record has been read and checked.
void Initialize()
{
   ZeroMemory(S);ZeroMemory(T);ZeroMemory(O);
   S.symbol=Case.symbol;S.comment=Case.comment;
   S.check_free_margin=(uchar)Case.check_free_margin;S.omit_real_sl_tp=(uchar)Case.omit_real_sl_tp;
   S.virtual_expiration=(uchar)Case.virtual_expiration;S.strategy_magic=Case.strategy_magic;
   S.expiration=(datetime)Case.expiration;S.unit=Case.unit;
   S.stop_distance=Case.stop_distance;S.take_distance=Case.take_distance;
   S.minimum_stop_price=Case.minimum_stop_price;S.minimum_freeze_price=Case.minimum_freeze_price;
   S.ask=Case.ask;S.bid=Case.bid;
   Index=(uint)Case.strategy_index;Errors=Case.error_count;FakeLastError=0;
   for(int i=0;i<8;i++) V[i]=0.125*(i+1);
   T.magic=(ulong)0x0123456789abcdef;O.async_mode=2;O.log_level=3;O.margin_mode=1;
   Events=0;MutationCount=0;Hash=(ulong)0xcbf29ce484222325;
   DigitsCalls=0;MarginCalls=0;VolumeCalls=0;AccountLimitCalls=0;OrdersTotalCalls=0;
   SendCalls=0;SleepCalls=0;PrintCalls=0;ErrorCalls=0;
   for(int row=0;row<100;row++) { Table[row][0]=1000.0+row;Table[row][1]=2000.0+row; }
   // Special values come from their bits so no sign of zero or NaN payload depends on the compiler.
   const ulong quiet_nan=(ulong)0x7ff8000000000000,negative_zero=(ulong)0x8000000000000000;
   switch(Case.cache_mode)
   {
      case 0: ArrayInitialize(Table,0.0);break;
      case 1: Table[50][0]=0.0;break;
      case 2: Table[99][0]=0.0;break;
      case 4: Table[0][0]=FromBits(quiet_nan);Table[1][0]=FromBits(negative_zero);break;
      case 5:
         Table[0][0]=FromBits((ulong)0x7ff0000000000000);Table[1][0]=FromBits((ulong)0xfff0000000000000);
         Table[2][0]=FromBits(quiet_nan);Table[3][0]=FromBits(negative_zero);break;
   }
}
void PutWord(const int file,const ulong word) { FileWriteLong(file,(long)word); }
// id, fault, then 241 words: 15 counters and state, 14 settings, 4 trade/options, 8 volumes, 200 cells.
void WriteResult(const int file)
{
   FileWriteInteger(file,Case.id);FileWriteInteger(file,Fault);
   PutWord(file,Signed(Events));PutWord(file,Hash);PutWord(file,Signed(DigitsCalls));
   PutWord(file,Signed(MarginCalls));PutWord(file,Signed(VolumeCalls));PutWord(file,Signed(AccountLimitCalls));
   PutWord(file,Signed(OrdersTotalCalls));PutWord(file,Signed(SendCalls));PutWord(file,Signed(SleepCalls));
   PutWord(file,Signed(PrintCalls));PutWord(file,Signed(ErrorCalls));PutWord(file,Signed(MutationCount));
   PutWord(file,(ulong)Errors);PutWord(file,Signed(FakeLastError));PutWord(file,(ulong)Index);
   PutWord(file,(ulong)S.check_free_margin);PutWord(file,(ulong)S.omit_real_sl_tp);
   PutWord(file,(ulong)S.virtual_expiration);PutWord(file,Signed(S.strategy_magic));
   PutWord(file,Signed((long)S.expiration));PutWord(file,Bits(S.unit));PutWord(file,Bits(S.stop_distance));
   PutWord(file,Bits(S.take_distance));PutWord(file,Bits(S.minimum_stop_price));
   PutWord(file,Bits(S.minimum_freeze_price));PutWord(file,Bits(S.ask));PutWord(file,Bits(S.bid));
   PutWord(file,TextHash(S.symbol));PutWord(file,TextHash(S.comment));
   PutWord(file,T.magic);PutWord(file,(ulong)O.async_mode);PutWord(file,Signed(O.log_level));
   PutWord(file,Signed(O.margin_mode));
   for(int i=0;i<8;i++) PutWord(file,Bits(V[i]));
   for(int row=0;row<100;row++) for(int column=0;column<2;column++) PutWord(file,Bits(Table[row][column]));
}
int OnStart()
{
   int length=StringLen(CheckRun);
   if(length<1 || length>50) return 4;
   for(int i=0;i<length;i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot1-pending-submission\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   if(ArrayResize(Table,100)!=100) return 3;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   if(!Available(source,12)) { FileClose(source);return 7; }
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x50534231 || version!=1 || count<1 || count>10000) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int id=0;id<count;id++)
   {
      // A record that cannot be read or checked is not run and not written.
      int read=ReadCase(source,id);
      if(read!=0) { Fail(read);break; }
      Initialize();
      Bot1SubmitPendingAfterPrice(Case.buy!=0,Case.base_price,S,V,Index,Table,Errors,T,O);
      WriteResult(output);
      if(Fault!=0) break;
   }
   if(FileTell(source)!=FileSize(source)) Fail(10);
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot1PendingSubmissionCheck:",Fault,",",count);return Fault;
}
