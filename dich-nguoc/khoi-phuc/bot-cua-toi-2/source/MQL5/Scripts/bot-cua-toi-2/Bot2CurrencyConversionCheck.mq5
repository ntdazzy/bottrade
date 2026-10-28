#property strict

input string CheckRun="";

union DoubleBits { double value; ulong bits; };

int OutputFile=INVALID_HANDLE;
string CurrencyReplies[128];
double PriceReplies[128];
int CurrencyCount=0,PriceCount=0;
int CurrencyIndex=0,PriceIndex=0;
bool ApiBad=false;

string CurrencyRead(const ENUM_ACCOUNT_INFO_STRING property);
double PriceRead(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift);

#define AccountInfoString CurrencyRead
#define iClose PriceRead
#include "../../Include/bot-cua-toi-2/Bot2CurrencyConversion.mqh"
#undef AccountInfoString
#undef iClose

void WriteText(const int file,const string value)
{
   int length=StringLen(value);
   FileWriteInteger(file,length);
   for(int i=0;i<length;i++) FileWriteInteger(file,StringGetCharacter(value,i),SHORT_VALUE);
}

string ReadText(const int file)
{
   int length=FileReadInteger(file);
   return length>0 ? FileReadString(file,length) : "";
}

ulong DoubleValueBits(const double value)
{
   DoubleBits bits;bits.value=value;return bits.bits;
}

double BitsDouble(const ulong bits)
{
   DoubleBits value;value.bits=bits;return value.value;
}

bool KnownSymbol(const string symbol)
{
   string pairs[]={"EURUSD","GBPUSD","AUDUSD","USDJPY","USDCHF","USDHKD","USDRUB","USDSGD",
                   "BTCUSD","ETHUSD","BCHUSD","BCCUSD","XRPUSD","LTCUSD","XMRUSD","DSHUSD",
                   "EOSUSD","TRXUSD","ADAUSD","BSVUSD","XLMUSD","GLDUSD","ZECUSD","XEMUSD",
                   "USDCZK","USDCNH","USDCNY"};
   for(int i=0;i<ArraySize(pairs);i++)
   {
      int base=StringLen(pairs[i]);
      if(StringLen(symbol)>=base && StringSubstr(symbol,0,base)==pairs[i]) return true;
   }
   return false;
}

string CurrencyRead(const ENUM_ACCOUNT_INFO_STRING property)
{
   if(property!=ACCOUNT_CURRENCY) ApiBad=true;
   int index=CurrencyIndex<CurrencyCount ? CurrencyIndex : CurrencyCount-1;
   string value=CurrencyReplies[index];
   CurrencyIndex++;
   FileWriteInteger(OutputFile,1);
   FileWriteInteger(OutputFile,(int)property);
   WriteText(OutputFile,value);
   return value;
}

double PriceRead(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   if(timeframe!=PERIOD_D1 || shift!=1 || !KnownSymbol(symbol)) ApiBad=true;
   int index=PriceIndex<PriceCount ? PriceIndex : PriceCount-1;
   double value=PriceReplies[index];
   PriceIndex++;
   FileWriteInteger(OutputFile,2);
   WriteText(OutputFile,symbol);
   FileWriteInteger(OutputFile,(int)timeframe);
   FileWriteInteger(OutputFile,shift);
   FileWriteLong(OutputFile,(long)DoubleValueBits(value));
   return value;
}

int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot2-currency-full\\"+CheckRun+"\\";
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x43553231 || version!=1 || count<1)
   { FileClose(source);return 1; }
   OutputFile=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(OutputFile==INVALID_HANDLE) { FileClose(source);return 1; }
   FileWriteInteger(OutputFile,magic);FileWriteInteger(OutputFile,version);FileWriteInteger(OutputFile,count);
   int fault=0;
   for(int c=0;c<count;c++)
   {
      int id=FileReadInteger(source),to_usd=FileReadInteger(source);
      double amount=BitsDouble((ulong)FileReadLong(source));
      string suffix=ReadText(source);
      CurrencyCount=FileReadInteger(source);
      if(CurrencyCount<1 || CurrencyCount>128) { fault=2;break; }
      for(int i=0;i<CurrencyCount;i++) CurrencyReplies[i]=ReadText(source);
      PriceCount=FileReadInteger(source);
      if(PriceCount<1 || PriceCount>128) { fault=2;break; }
      for(int i=0;i<PriceCount;i++) PriceReplies[i]=BitsDouble((ulong)FileReadLong(source));
      uint initial_error=(uint)FileReadInteger(source);
      CurrencyIndex=0;PriceIndex=0;ApiBad=false;
      ResetLastError();
      if(initial_error!=0) SetUserError((ushort)(initial_error-65536));
      FileWriteInteger(OutputFile,id);
      ulong block_start=FileTell(OutputFile);
      FileWriteInteger(OutputFile,0);
      double result=Bot2CurrencyConversion(amount,suffix,to_usd!=0);
      uint last_error=(uint)GetLastError();
      ulong result_bits=DoubleValueBits(result);
      FileWriteInteger(OutputFile,0);
      FileWriteLong(OutputFile,(long)result_bits);
      FileWriteInteger(OutputFile,(int)last_error);
      ulong block_end=FileTell(OutputFile);
      FileSeek(OutputFile,(long)block_start,SEEK_SET);
      FileWriteInteger(OutputFile,(int)(block_end-block_start-4));
      FileSeek(OutputFile,(long)block_end,SEEK_SET);
      if(ApiBad) fault=3;
   }
   bool exact=FileTell(source)==FileSize(source);
   if(!exact && fault==0) fault=4;
   FileClose(source);FileClose(OutputFile);OutputFile=INVALID_HANDLE;
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 1;
   FileWriteInteger(status,fault);FileWriteInteger(status,count);FileClose(status);
   return fault;
}
