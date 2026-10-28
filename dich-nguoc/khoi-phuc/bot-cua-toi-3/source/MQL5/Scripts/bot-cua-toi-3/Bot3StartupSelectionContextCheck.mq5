#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-3/Bot3StrategyContext.mqh"
#include "../../Include/bot-cua-toi-3/Bot3Preparation.mqh"
#include "../../Include/bot-cua-toi-3/Bot3StrategyHistory.mqh"
#include "../../Include/bot-cua-toi-3/Bot3PanelCreation.mqh"
#include "../../Include/bot-cua-toi-3/Bot3DailyLossGuard.mqh"
void BootPrint(const string value);
#define Print BootPrint
#include "../../Include/bot-cua-toi-3/Bot3StartupContext.mqh"
#undef Print

#include "../../Include/bot-cua-toi-3/Bot3AmericanDST.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VolumeCurrency.mqh"
bool SelectSummer();datetime SelectNow();double SelectBalance(const ENUM_ACCOUNT_INFO_DOUBLE property);
double SelectConvert(const double amount,const string &suffix,const bool to_usd);
#define Bot3AmericanDST SelectSummer
#define TimeCurrent SelectNow
#define AccountInfoDouble SelectBalance
#define Bot3VolumeCurrency SelectConvert
#include "../../Include/bot-cua-toi-3/Bot3StartupSelectionContext.mqh"
#undef Bot3AmericanDST
#undef TimeCurrent
#undef AccountInfoDouble
#undef Bot3VolumeCurrency
Bot3StrategyContextInputs BootInputs;Bot3StrategyContextState BootContext;Bot3PreparationInputs BootPreparation;
Bot3StrategyHistoryCache BootHistory;Bot3PanelCreationState BootPanel;Bot3DailyLossState BootDaily;Bot3StartupContextState BootState;

int WinterHours,SummerHours,Frequency,Risk;long AdjustedTime;uchar VariableValues,Thresholds[3],Manual[9],Enabled[9];double FrequencyDivisor;
int SelectSummerReply,SelectEffectCount;long SelectNowReply;double SelectBalanceReply,SelectConvertReply;ulong SelectEffects[16][3];

string BootChartSymbol;int BootOutput,BootPrints;
union BootNumber { double value;ulong word; };
ulong BootBits(const double value){BootNumber n;n.value=value;return n.word;}
double BootValue(const ulong value){BootNumber n;n.word=value;return n.value;}
void BootText(const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(BootOutput,n);if(n>0)FileWriteString(BootOutput,value,n);}
string BootReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void BootSnapshot(const uint error)
{
   FileWriteLong(BootOutput,(long)BootContext.magic);
   FileWriteLong(BootOutput,(long)BootBits(BootContext.converted_value));
   FileWriteLong(BootOutput,(long)BootInputs.base_magic);
   FileWriteLong(BootOutput,(long)BootInputs.keep_comment);
   FileWriteLong(BootOutput,(long)BootBits(BootDaily.peak));
   FileWriteLong(BootOutput,(long)BootDaily.blocked);
   FileWriteLong(BootOutput,(long)BootDaily.bars);
   FileWriteLong(BootOutput,(long)BootState.panel_bar);
   FileWriteLong(BootOutput,(long)BootHistory.total);
   FileWriteLong(BootOutput,(long)BootHistory.count);
   FileWriteLong(BootOutput,(long)BootState.extended_cleanup);
   FileWriteLong(BootOutput,(long)BootPanel.cell_font_flag);
   FileWriteLong(BootOutput,(long)BootBits(BootState.cell_base_x));
   FileWriteLong(BootOutput,(long)BootBits(BootState.cell_base_y));
   FileWriteLong(BootOutput,(long)BootBits(BootPanel.scale));
   FileWriteLong(BootOutput,(long)BootBits(BootPanel.cell_x));
   FileWriteLong(BootOutput,(long)BootBits(BootPanel.cell_y));
   FileWriteLong(BootOutput,(long)WinterHours);
   FileWriteLong(BootOutput,(long)SummerHours);
   FileWriteLong(BootOutput,(long)AdjustedTime);
   FileWriteLong(BootOutput,(long)Frequency);
   FileWriteLong(BootOutput,(long)Risk);
   FileWriteLong(BootOutput,(long)BootBits(BootPanel.allowed_dd));
   FileWriteLong(BootOutput,(long)VariableValues);
   FileWriteLong(BootOutput,(long)BootPanel.frequency);
   FileWriteLong(BootOutput,(long)BootBits(FrequencyDivisor));
   FileWriteLong(BootOutput,(long)Thresholds[0]);
   FileWriteLong(BootOutput,(long)Thresholds[1]);
   FileWriteLong(BootOutput,(long)Thresholds[2]);
   FileWriteLong(BootOutput,(long)Manual[0]);
   FileWriteLong(BootOutput,(long)Manual[1]);
   FileWriteLong(BootOutput,(long)Manual[2]);
   FileWriteLong(BootOutput,(long)Manual[3]);
   FileWriteLong(BootOutput,(long)Manual[4]);
   FileWriteLong(BootOutput,(long)Manual[5]);
   FileWriteLong(BootOutput,(long)Manual[6]);
   FileWriteLong(BootOutput,(long)Manual[7]);
   FileWriteLong(BootOutput,(long)Manual[8]);
   FileWriteLong(BootOutput,(long)Enabled[0]);
   FileWriteLong(BootOutput,(long)Enabled[1]);
   FileWriteLong(BootOutput,(long)Enabled[2]);
   FileWriteLong(BootOutput,(long)Enabled[3]);
   FileWriteLong(BootOutput,(long)Enabled[4]);
   FileWriteLong(BootOutput,(long)Enabled[5]);
   FileWriteLong(BootOutput,(long)Enabled[6]);
   FileWriteLong(BootOutput,(long)Enabled[7]);
   FileWriteLong(BootOutput,(long)Enabled[8]);
   FileWriteLong(BootOutput,(long)error);
   BootText(BootInputs.comment_prefix);
   BootText(BootInputs.symbol_suffix);
   BootText(BootContext.order_comment);
   BootText(BootPreparation.symbol);
   BootText(BootChartSymbol);
}
void BootPrint(const string value){uint error=GetLastError();BootSnapshot(error);BootText(value);BootPrints++;}

void SelectionEffect(const int api){for(int i=0;i<SelectEffectCount;i++){if((int)SelectEffects[i][0]!=api)continue;ulong v=SelectEffects[i][2];switch((int)SelectEffects[i][1]){case 0:BootContext.magic=(int)v;break;case 1:BootContext.converted_value=BootValue(v);break;case 2:BootInputs.base_magic=(int)v;break;case 3:BootInputs.keep_comment=(uchar)v;break;case 4:BootDaily.peak=BootValue(v);break;case 5:BootDaily.blocked=(uchar)v;break;case 6:BootDaily.bars=(int)v;break;case 7:BootState.panel_bar=(long)v;break;case 8:BootHistory.total=(int)v;break;case 9:BootHistory.count=(int)v;break;case 10:BootState.extended_cleanup=(uchar)v;break;case 11:BootPanel.cell_font_flag=(uchar)v;break;case 12:BootState.cell_base_x=BootValue(v);break;case 13:BootState.cell_base_y=BootValue(v);break;case 14:BootPanel.scale=BootValue(v);break;case 15:BootPanel.cell_x=BootValue(v);break;case 16:BootPanel.cell_y=BootValue(v);break;case 17:WinterHours=(int)v;break;case 18:SummerHours=(int)v;break;case 19:AdjustedTime=(long)v;break;case 20:Frequency=(int)v;break;case 21:Risk=(int)v;break;case 22:BootPanel.allowed_dd=BootValue(v);break;case 23:VariableValues=(uchar)v;break;case 24:BootPanel.frequency=(int)v;break;case 25:FrequencyDivisor=BootValue(v);break;case 26:Thresholds[0]=(uchar)v;break;case 27:Thresholds[1]=(uchar)v;break;case 28:Thresholds[2]=(uchar)v;break;case 29:Manual[0]=(uchar)v;break;case 30:Manual[1]=(uchar)v;break;case 31:Manual[2]=(uchar)v;break;case 32:Manual[3]=(uchar)v;break;case 33:Manual[4]=(uchar)v;break;case 34:Manual[5]=(uchar)v;break;case 35:Manual[6]=(uchar)v;break;case 36:Manual[7]=(uchar)v;break;case 37:Manual[8]=(uchar)v;break;case 38:Enabled[0]=(uchar)v;break;case 39:Enabled[1]=(uchar)v;break;case 40:Enabled[2]=(uchar)v;break;case 41:Enabled[3]=(uchar)v;break;case 42:Enabled[4]=(uchar)v;break;case 43:Enabled[5]=(uchar)v;break;case 44:Enabled[6]=(uchar)v;break;case 45:Enabled[7]=(uchar)v;break;case 46:Enabled[8]=(uchar)v;break;}}}
void SelectionRecord(const int api,const ulong argument,const string value,const ulong reply){BootSnapshot(GetLastError());FileWriteInteger(BootOutput,api);FileWriteLong(BootOutput,(long)argument);BootText(value);FileWriteLong(BootOutput,(long)reply);SelectionEffect(api);}
bool SelectSummer(){SelectionRecord(1,0,NULL,(ulong)SelectSummerReply);return SelectSummerReply!=0;}
datetime SelectNow(){SelectionRecord(2,0,NULL,(ulong)SelectNowReply);return (datetime)SelectNowReply;}
double SelectBalance(const ENUM_ACCOUNT_INFO_DOUBLE property){SelectionRecord(3,(ulong)property,NULL,BootBits(SelectBalanceReply));return SelectBalanceReply;}
double SelectConvert(const double amount,const string &suffix,const bool to_usd){SelectionRecord(4,BootBits(amount),suffix,BootBits(SelectConvertReply));if(!to_usd)SetUserError(900);return SelectConvertReply;}

int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-startup-selection-context\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x53433131 || version!=1 || count<1)return 3;
   BootOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(BootOutput==INVALID_HANDLE)return 4;
   FileWriteInteger(BootOutput,magic);FileWriteInteger(BootOutput,version);FileWriteInteger(BootOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);
      BootContext.magic=(int)FileReadLong(file);
      BootContext.converted_value=BootValue((ulong)FileReadLong(file));
      BootInputs.base_magic=(int)FileReadLong(file);
      BootInputs.keep_comment=(uchar)FileReadLong(file);
      BootDaily.peak=BootValue((ulong)FileReadLong(file));
      BootDaily.blocked=(uchar)FileReadLong(file);
      BootDaily.bars=(int)FileReadLong(file);
      BootState.panel_bar=FileReadLong(file);
      BootHistory.total=(int)FileReadLong(file);
      BootHistory.count=(int)FileReadLong(file);
      BootState.extended_cleanup=(uchar)FileReadLong(file);
      BootPanel.cell_font_flag=(uchar)FileReadLong(file);
      BootState.cell_base_x=BootValue((ulong)FileReadLong(file));
      BootState.cell_base_y=BootValue((ulong)FileReadLong(file));
      BootPanel.scale=BootValue((ulong)FileReadLong(file));
      BootPanel.cell_x=BootValue((ulong)FileReadLong(file));
      BootPanel.cell_y=BootValue((ulong)FileReadLong(file));
      WinterHours=(int)FileReadLong(file);
      SummerHours=(int)FileReadLong(file);
      AdjustedTime=FileReadLong(file);
      Frequency=(int)FileReadLong(file);
      Risk=(int)FileReadLong(file);
      BootPanel.allowed_dd=BootValue((ulong)FileReadLong(file));
      VariableValues=(uchar)FileReadLong(file);
      BootPanel.frequency=(int)FileReadLong(file);
      FrequencyDivisor=BootValue((ulong)FileReadLong(file));
      Thresholds[0]=(uchar)FileReadLong(file);
      Thresholds[1]=(uchar)FileReadLong(file);
      Thresholds[2]=(uchar)FileReadLong(file);
      Manual[0]=(uchar)FileReadLong(file);
      Manual[1]=(uchar)FileReadLong(file);
      Manual[2]=(uchar)FileReadLong(file);
      Manual[3]=(uchar)FileReadLong(file);
      Manual[4]=(uchar)FileReadLong(file);
      Manual[5]=(uchar)FileReadLong(file);
      Manual[6]=(uchar)FileReadLong(file);
      Manual[7]=(uchar)FileReadLong(file);
      Manual[8]=(uchar)FileReadLong(file);
      Enabled[0]=(uchar)FileReadLong(file);
      Enabled[1]=(uchar)FileReadLong(file);
      Enabled[2]=(uchar)FileReadLong(file);
      Enabled[3]=(uchar)FileReadLong(file);
      Enabled[4]=(uchar)FileReadLong(file);
      Enabled[5]=(uchar)FileReadLong(file);
      Enabled[6]=(uchar)FileReadLong(file);
      Enabled[7]=(uchar)FileReadLong(file);
      Enabled[8]=(uchar)FileReadLong(file);
      BootInputs.comment_prefix=BootReadText(file);
      BootInputs.symbol_suffix=BootReadText(file);
      BootContext.order_comment=BootReadText(file);
      BootPreparation.symbol=BootReadText(file);
      BootChartSymbol=BootReadText(file);
      int error=FileReadInteger(file);BootPrints=0;SelectSummerReply=(int)FileReadLong(file);SelectNowReply=FileReadLong(file);SelectBalanceReply=BootValue((ulong)FileReadLong(file));SelectConvertReply=BootValue((ulong)FileReadLong(file));SelectEffectCount=FileReadInteger(file);if(SelectEffectCount<0 || SelectEffectCount>16)return 8;for(int i=0;i<SelectEffectCount;i++){SelectEffects[i][0]=(ulong)FileReadInteger(file);SelectEffects[i][1]=(ulong)FileReadInteger(file);SelectEffects[i][2]=(ulong)FileReadLong(file);}
      string primed=IntegerToString(12345);if(primed!="12345")return 5;
      FileWriteInteger(BootOutput,id);ulong at=FileTell(BootOutput);FileWriteInteger(BootOutput,0);ulong begin=FileTell(BootOutput);
      ResetLastError();if(error!=0)SetUserError(731);
      Bot3InitializeStartupSelectionContext(WinterHours,SummerHours,AdjustedTime,Frequency,Risk,VariableValues,Thresholds,Manual,Enabled,FrequencyDivisor,BootChartSymbol,BootInputs,BootContext,BootPreparation,BootHistory,BootPanel,BootDaily,BootState);
      uint final_error=GetLastError();BootSnapshot(final_error);FileWriteInteger(BootOutput,BootPrints);
      ulong end=FileTell(BootOutput);FileSeek(BootOutput,(long)at,SEEK_SET);FileWriteInteger(BootOutput,(int)(end-begin));FileSeek(BootOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 6;FileClose(file);FileClose(BootOutput);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
