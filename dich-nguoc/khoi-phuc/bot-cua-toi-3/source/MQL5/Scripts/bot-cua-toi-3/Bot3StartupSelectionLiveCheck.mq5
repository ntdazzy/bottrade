#property strict
input string CheckRun="";
void BootPrint(const string value);

datetime LiveTimeCurrent();bool LiveTimeToStruct(const datetime value,MqlDateTime &dt);double LiveMathMod(const double a,const double b);
int LiveStringConcatenate(string &output,const int year,const string &suffix);datetime LiveStringToTime(const string value);
double LiveAccountInfoDouble(const ENUM_ACCOUNT_INFO_DOUBLE property);string LiveAccountInfoString(const ENUM_ACCOUNT_INFO_STRING property);double LiveIClose(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift);

#define TimeCurrent LiveTimeCurrent
#define TimeToStruct LiveTimeToStruct
#define MathMod LiveMathMod
#define StringConcatenate LiveStringConcatenate
#define StringToTime LiveStringToTime
#define Print BootPrint
#define AccountInfoString LiveAccountInfoString
#define iClose LiveIClose
#include "../../Include/bot-cua-toi-3/Bot3AmericanDST.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VolumeCurrency.mqh"
#undef TimeCurrent
#undef TimeToStruct
#undef MathMod
#undef StringConcatenate
#undef StringToTime
#undef Print
#undef AccountInfoString
#undef iClose

#include "../../Include/bot-cua-toi-3/Bot3StrategyContext.mqh"
#include "../../Include/bot-cua-toi-3/Bot3Preparation.mqh"
#include "../../Include/bot-cua-toi-3/Bot3StrategyHistory.mqh"
#include "../../Include/bot-cua-toi-3/Bot3PanelCreation.mqh"
#include "../../Include/bot-cua-toi-3/Bot3DailyLossGuard.mqh"
#define Print BootPrint
#include "../../Include/bot-cua-toi-3/Bot3StartupContext.mqh"
#undef Print

Bot3StrategyContextInputs BootInputs;Bot3StrategyContextState BootContext;Bot3PreparationInputs BootPreparation;
Bot3StrategyHistoryCache BootHistory;Bot3PanelCreationState BootPanel;Bot3DailyLossState BootDaily;Bot3StartupContextState BootState;
int WinterHours,SummerHours,Frequency,Risk;long AdjustedTime;uchar VariableValues,Thresholds[3],Manual[9],Enabled[9];double FrequencyDivisor;
string BootChartSymbol;int BootOutput,BootPrints;
union BootNumber { double value;ulong word; };
ulong BootBits(const double value){BootNumber n;n.value=value;return n.word;}
double BootValue(const ulong value){BootNumber n;n.word=value;return n.value;}
void BootText(const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(BootOutput,n);if(n>0)FileWriteString(BootOutput,value,n);}
void LiveText(const string value){string text=value==NULL ? "" : value;int n=StringLen(text);FileWriteInteger(BootOutput,n);if(n>0)FileWriteString(BootOutput,text,n);}
string BootReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void BootSnapshot(const uint error)
{
   FileWriteLong(BootOutput,(long)BootContext.magic);FileWriteLong(BootOutput,(long)BootBits(BootContext.converted_value));
   FileWriteLong(BootOutput,(long)BootInputs.base_magic);FileWriteLong(BootOutput,(long)BootInputs.keep_comment);
   FileWriteLong(BootOutput,(long)BootBits(BootDaily.peak));FileWriteLong(BootOutput,(long)BootDaily.blocked);FileWriteLong(BootOutput,(long)BootDaily.bars);
   FileWriteLong(BootOutput,(long)BootState.panel_bar);FileWriteLong(BootOutput,(long)BootHistory.total);FileWriteLong(BootOutput,(long)BootHistory.count);
   FileWriteLong(BootOutput,(long)BootState.extended_cleanup);FileWriteLong(BootOutput,(long)BootPanel.cell_font_flag);
   FileWriteLong(BootOutput,(long)BootBits(BootState.cell_base_x));FileWriteLong(BootOutput,(long)BootBits(BootState.cell_base_y));
   FileWriteLong(BootOutput,(long)BootBits(BootPanel.scale));FileWriteLong(BootOutput,(long)BootBits(BootPanel.cell_x));FileWriteLong(BootOutput,(long)BootBits(BootPanel.cell_y));
   FileWriteLong(BootOutput,(long)WinterHours);FileWriteLong(BootOutput,(long)SummerHours);FileWriteLong(BootOutput,(long)AdjustedTime);
   FileWriteLong(BootOutput,(long)Frequency);FileWriteLong(BootOutput,(long)Risk);FileWriteLong(BootOutput,(long)BootBits(BootPanel.allowed_dd));
   FileWriteLong(BootOutput,(long)VariableValues);FileWriteLong(BootOutput,(long)BootPanel.frequency);FileWriteLong(BootOutput,(long)BootBits(FrequencyDivisor));
   FileWriteLong(BootOutput,(long)Thresholds[0]);FileWriteLong(BootOutput,(long)Thresholds[1]);FileWriteLong(BootOutput,(long)Thresholds[2]);
   for(int i=0;i<9;i++)FileWriteLong(BootOutput,(long)Manual[i]);
   for(int i=0;i<9;i++)FileWriteLong(BootOutput,(long)Enabled[i]);
   FileWriteLong(BootOutput,(long)error);BootText(BootInputs.comment_prefix);BootText(BootInputs.symbol_suffix);BootText(BootContext.order_comment);BootText(BootPreparation.symbol);BootText(BootChartSymbol);
}

int BootApiError;
void LiveApi(const int api){if(api<101 || api>108){BootApiError=1;return;}FileWriteInteger(BootOutput,api);}
void LiveBegin(const int api){BootSnapshot(GetLastError());LiveApi(api);}

#define TimeCurrent LiveTimeCurrent
#define AccountInfoDouble LiveAccountInfoDouble
#include "../../Include/bot-cua-toi-3/Bot3StartupSelectionContext.mqh"
#undef TimeCurrent
#undef AccountInfoDouble

long LiveClocks[128];int LiveClockCount,LiveClockIndex;ulong LiveBalanceBits;string LiveCurrencies[128];int LiveCurrencyCount,LiveCurrencyIndex;ulong LivePrices[128];int LivePriceCount,LivePriceIndex;
void LiveErrorAfter(const uint error){FileWriteLong(BootOutput,(long)error);}
datetime LiveTimeCurrent(){LiveBegin(101);int i=LiveClockIndex<LiveClockCount?LiveClockIndex:LiveClockCount-1;long result=LiveClocks[i];LiveClockIndex++;uint error=GetLastError();FileWriteLong(BootOutput,result);LiveErrorAfter(error);return (datetime)result;}
bool LiveTimeToStruct(const datetime value,MqlDateTime &dt){LiveBegin(102);bool ok=TimeToStruct(value,dt);uint error=GetLastError();FileWriteLong(BootOutput,(long)value);FileWriteLong(BootOutput,(long)ok);FileWriteInteger(BootOutput,dt.year);FileWriteInteger(BootOutput,dt.mon);FileWriteInteger(BootOutput,dt.day);FileWriteInteger(BootOutput,dt.hour);FileWriteInteger(BootOutput,dt.min);FileWriteInteger(BootOutput,dt.sec);FileWriteInteger(BootOutput,dt.day_of_week);FileWriteInteger(BootOutput,dt.day_of_year);LiveErrorAfter(error);return ok;}
double LiveMathMod(const double a,const double b){LiveBegin(103);double result=MathMod(a,b);uint error=GetLastError();FileWriteLong(BootOutput,(long)BootBits(a));FileWriteLong(BootOutput,(long)BootBits(b));FileWriteLong(BootOutput,(long)BootBits(result));LiveErrorAfter(error);return result;}
int LiveStringConcatenate(string &output,const int year,const string &suffix){LiveBegin(104);string before=output;int result=StringConcatenate(output,year,suffix);uint error=GetLastError();FileWriteLong(BootOutput,(long)year);FileWriteLong(BootOutput,(long)result);LiveText(before);LiveText(suffix);LiveText(output);LiveErrorAfter(error);return result;}
datetime LiveStringToTime(const string value){LiveBegin(105);datetime result=StringToTime(value);uint error=GetLastError();LiveText(value);FileWriteLong(BootOutput,(long)result);LiveErrorAfter(error);return result;}
double LiveAccountInfoDouble(const ENUM_ACCOUNT_INFO_DOUBLE property){LiveBegin(106);if(property!=ACCOUNT_BALANCE)BootApiError=1;double result=property==ACCOUNT_BALANCE?BootValue(LiveBalanceBits):0.0;uint error=GetLastError();FileWriteLong(BootOutput,(long)property);FileWriteLong(BootOutput,(long)BootBits(result));LiveErrorAfter(error);return result;}
string LiveAccountInfoString(const ENUM_ACCOUNT_INFO_STRING property){LiveBegin(107);if(property!=ACCOUNT_CURRENCY)BootApiError=1;int i=LiveCurrencyIndex<LiveCurrencyCount?LiveCurrencyIndex:LiveCurrencyCount-1;string result=property==ACCOUNT_CURRENCY?LiveCurrencies[i]:"";if(property==ACCOUNT_CURRENCY)LiveCurrencyIndex++;uint error=GetLastError();FileWriteLong(BootOutput,(long)property);LiveText(result);LiveErrorAfter(error);return result;}
double LiveIClose(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift){LiveBegin(108);if(timeframe!=PERIOD_D1 || shift!=1)BootApiError=1;int i=LivePriceIndex<LivePriceCount?LivePriceIndex:LivePriceCount-1;double result=BootValue(LivePrices[i]);LivePriceIndex++;uint error=GetLastError();LiveText(symbol);FileWriteLong(BootOutput,(long)timeframe);FileWriteLong(BootOutput,(long)shift);FileWriteLong(BootOutput,(long)BootBits(result));LiveErrorAfter(error);return result;}
void BootPrint(const string value){BootSnapshot(GetLastError());FileWriteInteger(BootOutput,99);LiveText(value);BootPrints++;}

int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-startup-selection-live\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x53433131 || version!=1 || count<1)return 3;
   BootOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(BootOutput==INVALID_HANDLE)return 4;FileWriteInteger(BootOutput,magic);FileWriteInteger(BootOutput,version);FileWriteInteger(BootOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);BootContext.magic=(int)FileReadLong(file);BootContext.converted_value=BootValue((ulong)FileReadLong(file));BootInputs.base_magic=(int)FileReadLong(file);BootInputs.keep_comment=(uchar)FileReadLong(file);BootDaily.peak=BootValue((ulong)FileReadLong(file));BootDaily.blocked=(uchar)FileReadLong(file);BootDaily.bars=(int)FileReadLong(file);BootState.panel_bar=FileReadLong(file);BootHistory.total=(int)FileReadLong(file);BootHistory.count=(int)FileReadLong(file);BootState.extended_cleanup=(uchar)FileReadLong(file);BootPanel.cell_font_flag=(uchar)FileReadLong(file);BootState.cell_base_x=BootValue((ulong)FileReadLong(file));BootState.cell_base_y=BootValue((ulong)FileReadLong(file));BootPanel.scale=BootValue((ulong)FileReadLong(file));BootPanel.cell_x=BootValue((ulong)FileReadLong(file));BootPanel.cell_y=BootValue((ulong)FileReadLong(file));WinterHours=(int)FileReadLong(file);SummerHours=(int)FileReadLong(file);AdjustedTime=FileReadLong(file);Frequency=(int)FileReadLong(file);Risk=(int)FileReadLong(file);BootPanel.allowed_dd=BootValue((ulong)FileReadLong(file));VariableValues=(uchar)FileReadLong(file);BootPanel.frequency=(int)FileReadLong(file);FrequencyDivisor=BootValue((ulong)FileReadLong(file));
      for(int i=0;i<3;i++)Thresholds[i]=(uchar)FileReadLong(file);for(int i=0;i<9;i++)Manual[i]=(uchar)FileReadLong(file);for(int i=0;i<9;i++)Enabled[i]=(uchar)FileReadLong(file);
      BootInputs.comment_prefix=BootReadText(file);BootInputs.symbol_suffix=BootReadText(file);BootContext.order_comment=BootReadText(file);BootPreparation.symbol=BootReadText(file);BootChartSymbol=BootReadText(file);int error=FileReadInteger(file);
      for(int i=0;i<4;i++)LiveClocks[i]=FileReadLong(file);LiveClockCount=4;LiveBalanceBits=(ulong)FileReadLong(file);LiveCurrencyCount=FileReadInteger(file);if(LiveCurrencyCount<1||LiveCurrencyCount>128)return 8;for(int i=0;i<LiveCurrencyCount;i++)LiveCurrencies[i]=BootReadText(file);LivePriceCount=FileReadInteger(file);if(LivePriceCount<1||LivePriceCount>128)return 8;for(int i=0;i<LivePriceCount;i++)LivePrices[i]=(ulong)FileReadLong(file);
      LiveClockIndex=0;LiveCurrencyIndex=0;LivePriceIndex=0;BootPrints=0;BootApiError=0;string primed=IntegerToString(12345);if(primed!="12345")return 5;
      FileWriteInteger(BootOutput,id);ulong at=FileTell(BootOutput);FileWriteInteger(BootOutput,0);ulong begin=FileTell(BootOutput);ResetLastError();if(error!=0)SetUserError(731);
      Bot3InitializeStartupSelectionContext(WinterHours,SummerHours,AdjustedTime,Frequency,Risk,VariableValues,Thresholds,Manual,Enabled,FrequencyDivisor,BootChartSymbol,BootInputs,BootContext,BootPreparation,BootHistory,BootPanel,BootDaily,BootState);
      BootSnapshot(GetLastError());FileWriteInteger(BootOutput,BootPrints);if(BootApiError!=0)return 9;ulong end=FileTell(BootOutput);FileSeek(BootOutput,(long)at,SEEK_SET);FileWriteInteger(BootOutput,(int)(end-begin));FileSeek(BootOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 6;FileClose(file);FileClose(BootOutput);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
