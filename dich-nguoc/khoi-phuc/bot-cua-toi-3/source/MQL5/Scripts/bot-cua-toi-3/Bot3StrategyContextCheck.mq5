// Compare comment/magic/currency context only. Terminal replies are supplied.
#property strict
#property script_show_inputs
input string CheckRun="";
input int OnlyCase=-1;
union Bits { double d;ulong u; };
ulong ValueBits(const double value) { Bits b;b.d=value;return b.u; }
double Prices[4];string Currency,AccountSequence[];int AccountReads,PriceReads,Fault;ulong PriceHash,ServiceHash;
ulong TextHash(const string value) { ulong h=(ulong)0xcbf29ce484222325;for(int i=0;i<StringLen(value);i++) { ushort c=StringGetCharacter(value,i);h^=(ulong)(c&255);h*=(ulong)0x100000001b3;h^=(ulong)(c>>8);h*=(ulong)0x100000001b3; }return h; }
void HashWord(ulong &h,const ulong word) { for(int i=0;i<8;i++) { h^=(word>>(i*8))&255;h*=(ulong)0x100000001b3; } }
string FakeAccount(const ENUM_ACCOUNT_INFO_STRING property) { if(property!=ACCOUNT_CURRENCY) Fault=20;string value=AccountReads<ArraySize(AccountSequence) ? AccountSequence[AccountReads] : Currency;AccountReads++;HashWord(ServiceHash,10);HashWord(ServiceHash,TextHash(value));return value; }
double FakeClose(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   HashWord(ServiceHash,11);
   if(PriceReads>=4) { Fault=21;return 0.0; }
   double value=Prices[PriceReads++];
   HashWord(PriceHash,TextHash(symbol));HashWord(PriceHash,(ulong)frame);HashWord(PriceHash,(ulong)shift);HashWord(PriceHash,ValueBits(value));
   return value;
}
#define AccountInfoString FakeAccount
#define iClose FakeClose
#include "../../Include/bot-cua-toi-3/Bot3StrategyContext.mqh"
#undef AccountInfoString
#undef iClose
string ReadText(const int file) { int length=FileReadInteger(file);if(length<0 || length>10000) { Fault=22;return ""; }return length==0 ? "" : FileReadString(file,length); }
void WriteText(const int file,const string value) { FileWriteInteger(file,StringLen(value));if(StringLen(value)>0) FileWriteString(file,value,StringLen(value)); }
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++) { ushort c=StringGetCharacter(CheckRun,i);if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4; }
   string folder="bot3-strategy-context\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x53435431 || version!=2 || count<1 || count>10000 || OnlyCase>=count) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   int selected=OnlyCase<0 ? count : 1;
   FileWriteInteger(output,0x53435431);FileWriteInteger(output,2);FileWriteInteger(output,selected);FileWriteInteger(output,7);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(source);uint index=(uint)FileReadInteger(source);
      Bot3StrategyContextInputs inputs;ZeroMemory(inputs);
      inputs.keep_comment=(uchar)FileReadInteger(source);uchar alternate=(uchar)FileReadInteger(source);
      inputs.base_magic=FileReadInteger(source);double reference=FileReadDouble(source);
      for(int j=0;j<4;j++) Prices[j]=FileReadDouble(source);
      inputs.comment_prefix=ReadText(source);
      Bot3StrategyContextState state;ZeroMemory(state);state.order_comment=ReadText(source);state.converted_value=-987.5;
      Currency=ReadText(source);inputs.symbol_suffix=ReadText(source);
      int sequence_count=FileReadInteger(source);if(sequence_count<0 || sequence_count>1000) { FileClose(source);FileClose(output);return 10; }
      ArrayResize(AccountSequence,sequence_count);for(int j=0;j<sequence_count;j++) AccountSequence[j]=ReadText(source);
      if(OnlyCase>=0 && id!=OnlyCase) continue;
      if(OnlyCase>=0) { Print("STRATEGY_CONTEXT_CASE:",id);FileFlush(output); }
      AccountReads=0;PriceReads=0;PriceHash=(ulong)0xcbf29ce484222325;ServiceHash=(ulong)0xcbf29ce484222325;
      inputs.native_1d6f28=alternate;
      Bot3LoadStrategyContext(index,inputs,reference,state);
      FileWriteInteger(output,id);FileWriteInteger(output,1);
      FileWriteLong(output,(long)state.magic);FileWriteLong(output,(long)ValueBits(state.converted_value));FileWriteLong(output,(long)ValueBits(reference));
      FileWriteLong(output,AccountReads);FileWriteLong(output,PriceReads);FileWriteLong(output,(long)PriceHash);FileWriteLong(output,(long)ServiceHash);
      WriteText(output,state.order_comment);
   }
   if(FileTell(source)!=FileSize(source)) Fault=23;FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,Fault);FileWriteInteger(status,selected);FileClose(status);return Fault;
}

