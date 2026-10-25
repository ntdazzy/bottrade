// All terminal queries use supplied test data. Modify/try-close children are only
// recorded at their call boundary; no position is selected, modified or closed.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3PriceLevels.mqh"
#include "../../Include/bot-cua-toi-3/Bot3PositionModify.mqh"
#include "../../Include/bot-cua-toi-3/Bot3PositionClose.mqh"
input string CheckRun="";
union PreludeBits { double d;ulong u; };
int Fault=0,Calls=0,DigitIndex=0,TimeIndex=0,CloseIndex=0,OpenIndex=0;
ulong Hash=0,Ticket=0,LastTicket=0;
long PositionType=0,PositionMagic=0,Opened=0,Times[6];
int ExpectedMagic=0,Enabled=0,TestDigits[5],TickOk=0;
double SL=0.0,TP=0.0,PriceOpen=0.0,Volume=0.0,Unit=0.0,Stop=0.0,Take=0.0;
double Bid=0.0,Ask=0.0,Closes[6],Opens[3];
uchar CandleOn[3],Timeframes[3],Shift=0;
string TestSymbol,PositionSymbol,TestComment;
MqlTick TestTick;
// Distinct values the candle groups must forward unchanged to the try-close helper.
ulong Deviation=(ulong)0x0123456789abcdef;
double ThresholdA=1.25,ThresholdB=2.5;

ulong Bits(const double value) { PreludeBits x;x.d=value;return x.u; }
ulong TextHash(const string value)
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
void Trace(const int api,const ulong a=0,const ulong b=0,const ulong v=0,const ulong w=0)
{
   ulong words[5];words[0]=(ulong)api;words[1]=a;words[2]=b;words[3]=v;words[4]=w;
   for(int i=0;i<5;i++)
      for(int j=0;j<8;j++) { Hash^=(words[i]>>(8*j))&255;Hash*=(ulong)0x100000001b3; }
   Calls++;
}
long CheckDigits(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(property!=SYMBOL_DIGITS || DigitIndex>=5) { Fault=1;return 0; }
   long value=(long)TestDigits[DigitIndex++];
   Trace(1,(ulong)property,TextHash(symbol),(ulong)value,(ulong)(symbol==NULL));return value;
}
ulong CheckTicket(const int index)
{
   if(index!=0) Fault=2;
   Trace(2,(ulong)index,0,Ticket);return Ticket;
}
double CheckDouble(const ENUM_POSITION_PROPERTY_DOUBLE property)
{
   double value=0.0;
   if(property==POSITION_SL) value=SL;
   else if(property==POSITION_TP) value=TP;
   else if(property==POSITION_PRICE_OPEN) value=PriceOpen;
   else if(property==POSITION_VOLUME) value=Volume;
   else Fault=3;
   Trace(3,(ulong)property,0,Bits(value));return value;
}
long CheckInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   long value=0;
   if(property==POSITION_TIME) value=Opened;
   else if(property==POSITION_TYPE) value=PositionType;
   else if(property==POSITION_MAGIC) value=PositionMagic;
   else Fault=4;
   Trace(4,(ulong)property,0,(ulong)value);return value;
}
string CheckString(const ENUM_POSITION_PROPERTY_STRING property)
{
   string value;
   if(property==POSITION_COMMENT) value=TestComment;
   else if(property==POSITION_SYMBOL) value=PositionSymbol;
   else Fault=5;
   Trace(5,(ulong)property,TextHash(value),(ulong)(value==NULL));return value;
}
bool CheckTick(const string symbol,MqlTick &tick)
{
   Trace(6,TextHash(symbol),(ulong)TickOk,Bits(Bid),Bits(Ask));
   if(TickOk!=0) { tick.bid=Bid;tick.ask=Ask; }
   return TickOk!=0;
}
void CheckPrint(const string text) { Trace(7,TextHash(text)); }
bool CheckModify(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                 const ulong ticket,const double sl,const double tp)
{
   Trace(8,ticket,Bits(sl),Bits(tp));return false;
}
// Native 0x47d20 takes only the ticket; the other values are its globals, so they are
// checked here against the forwarded references and not added to the compared trace.
void CheckTryClose(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,const ulong &deviation,
                   const double &reference_a,const double &reference_b,
                   const double &threshold_a,const double &threshold_b,const ulong ticket)
{
   if(deviation!=Deviation || Bits(reference_a)!=Bits(TestTick.bid) || Bits(reference_b)!=Bits(TestTick.ask) ||
      Bits(threshold_a)!=Bits(ThresholdA) || Bits(threshold_b)!=Bits(ThresholdB)) Fault=9;
   Trace(9,ticket);
}
// The candle groups must call the guarded helper; a direct close is a fault.
void CheckDirectClose(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                      const ulong &deviation,const ulong ticket) { Fault=19;Trace(19,ticket); }
datetime CheckTime(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   if(TimeIndex>=6) { Fault=10;return 0; }
   long value=Times[TimeIndex++];Trace(10,(ulong)timeframe,(ulong)shift,(ulong)value,TextHash(symbol));return (datetime)value;
}
double CheckClosePrice(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   if(CloseIndex>=6) { Fault=11;return 0.0; }
   double value=Closes[CloseIndex++];Trace(11,(ulong)timeframe,(ulong)shift,Bits(value),TextHash(symbol));return value;
}
double CheckOpenPrice(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   if(OpenIndex>=3) { Fault=12;return 0.0; }
   double value=Opens[OpenIndex++];Trace(12,(ulong)timeframe,(ulong)shift,Bits(value),TextHash(symbol));return value;
}
#define SymbolInfoInteger CheckDigits
#define PositionGetTicket CheckTicket
#define PositionGetDouble CheckDouble
#define PositionGetInteger CheckInteger
#define PositionGetString CheckString
#define SymbolInfoTick CheckTick
#define Print CheckPrint
#define Bot3ModifyPosition CheckModify
#define Bot3TryClosePosition CheckTryClose
#define Bot3ClosePosition CheckDirectClose
#define iTime CheckTime
#define iClose CheckClosePrice
#define iOpen CheckOpenPrice
#include "../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh"
#undef SymbolInfoInteger
#undef PositionGetTicket
#undef PositionGetDouble
#undef PositionGetInteger
#undef PositionGetString
#undef SymbolInfoTick
#undef Print
#undef Bot3ModifyPosition
#undef Bot3TryClosePosition
#undef Bot3ClosePosition
#undef iTime
#undef iClose
#undef iOpen

string ReadText(const int file)
{
   int null=FileReadInteger(file),length=FileReadInteger(file);
   if((null!=0 && null!=1) || length<0 || length>4096 || (null==1 && length!=0)) { Fault=20;return NULL; }
   string value="";
   for(int i=0;i<length;i++) value+=ShortToString((ushort)FileReadInteger(file,SHORT_VALUE));
   if(null==1) value=NULL;
   return value;
}
uchar ReadByte(const int file)
{
   int value=FileReadInteger(file);
   if(value<0 || value>255) Fault=29;
   return (uchar)value;
}
void WritePosition(const int file,const int id,const bool accepted,const ulong ticket,
                   const Bot3ManagedPosition &position,const MqlTick &tick)
{
   FileWriteInteger(file,id);FileWriteInteger(file,(int)accepted);FileWriteLong(file,(long)ticket);
   FileWriteInteger(file,(int)(ticket!=0));
   FileWriteDouble(file,position.sl);FileWriteDouble(file,position.tp);FileWriteDouble(file,position.ticket_number);
   FileWriteDouble(file,position.open_price);FileWriteDouble(file,position.volume);
   FileWriteLong(file,position.opened);FileWriteLong(file,position.type);FileWriteLong(file,position.magic);
   FileWriteLong(file,(long)TextHash(position.comment));FileWriteLong(file,(long)TextHash(position.symbol));
   FileWriteInteger(file,(int)(position.comment==NULL));FileWriteInteger(file,(int)(position.symbol==NULL));
   FileWriteDouble(file,tick.bid);FileWriteDouble(file,tick.ask);
   FileWriteInteger(file,Calls);FileWriteLong(file,(long)Hash);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 21;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 21;
   }
   string folder="bot3-management-prelude\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 22;
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(input_file==INVALID_HANDLE) return 23;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x4d505233 || version!=1 || count<1 || count>100000) { FileClose(input_file);return 24; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(input_file);return 25; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int index=0;index<count;index++)
   {
      int id=FileReadInteger(input_file),buy=FileReadInteger(input_file),scenario=FileReadInteger(input_file);
      if(id!=index || (buy!=0 && buy!=1) || scenario!=0) { Fault=26;break; }
      Ticket=(ulong)FileReadLong(input_file);PositionType=FileReadLong(input_file);PositionMagic=FileReadLong(input_file);
      ExpectedMagic=FileReadInteger(input_file);Enabled=FileReadInteger(input_file);
      for(int j=0;j<5;j++) TestDigits[j]=FileReadInteger(input_file);
      SL=FileReadDouble(input_file);TP=FileReadDouble(input_file);PriceOpen=FileReadDouble(input_file);Volume=FileReadDouble(input_file);
      Unit=FileReadDouble(input_file);Stop=FileReadDouble(input_file);Take=FileReadDouble(input_file);
      TickOk=FileReadInteger(input_file);
      int padding=FileReadInteger(input_file);padding|=FileReadInteger(input_file);
      if((TickOk!=0 && TickOk!=1) || padding!=0) { Fault=26;break; }
      Bid=FileReadDouble(input_file);Ask=FileReadDouble(input_file);Opened=FileReadLong(input_file);
      for(int j=0;j<6;j++) Times[j]=FileReadLong(input_file);
      for(int j=0;j<3;j++) CandleOn[j]=ReadByte(input_file);
      for(int j=0;j<3;j++) Timeframes[j]=ReadByte(input_file);
      Shift=ReadByte(input_file);
      for(int j=0;j<6;j++) Closes[j]=FileReadDouble(input_file);
      for(int j=0;j<3;j++) Opens[j]=FileReadDouble(input_file);
      TestSymbol=ReadText(input_file);PositionSymbol=ReadText(input_file);TestComment=ReadText(input_file);
      if(Fault!=0) break;
      Bot3ManagedPosition position;ZeroMemory(position);
      ZeroMemory(TestTick);TestTick.bid=-100.0;TestTick.ask=-101.0;
      Bot3PendingRequestState state;ZeroMemory(state);Bot3TradeSendOptions options;ZeroMemory(options);
      LastTicket=0;Calls=DigitIndex=TimeIndex=CloseIndex=OpenIndex=0;Hash=(ulong)0xcbf29ce484222325;
      bool accepted=Bot3ReadManagementPosition(0,buy!=0,ExpectedMagic,Enabled,TestSymbol,LastTicket,TestTick,position);
      if(accepted)
      {
         Bot3FillManagementInitialLevels(buy!=0,TestSymbol,Unit,Stop,Take,position,state,options);
         for(int group=0;group<3;group++)
            Bot3CloseManagementCandle(buy!=0,TestSymbol,group,CandleOn[group],Timeframes[group],Shift,
                                      position,TestTick,state,options,Deviation,ThresholdA,ThresholdB);
      }
      WritePosition(output,id,accepted,LastTicket,position,TestTick);
   }
   if(Fault==0 && FileTell(input_file)!=FileSize(input_file)) Fault=27;
   FileClose(input_file);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 28;
   FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot3ManagementPreludeCheck:",Fault,",",count);
   return Fault;
}
