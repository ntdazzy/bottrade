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
Bot3StrategyContextInputs BootInputs;Bot3StrategyContextState BootContext;Bot3PreparationInputs BootPreparation;
Bot3StrategyHistoryCache BootHistory;Bot3PanelCreationState BootPanel;Bot3DailyLossState BootDaily;Bot3StartupContextState BootState;
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
   FileWriteLong(BootOutput,(long)error);
   BootText(BootInputs.comment_prefix);
   BootText(BootInputs.symbol_suffix);
   BootText(BootContext.order_comment);
   BootText(BootPreparation.symbol);
   BootText(BootChartSymbol);
}
void BootPrint(const string value){uint error=GetLastError();BootSnapshot(error);BootText(value);BootPrints++;}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-startup-context\\"+CheckRun+"\\";
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
      BootInputs.comment_prefix=BootReadText(file);
      BootInputs.symbol_suffix=BootReadText(file);
      BootContext.order_comment=BootReadText(file);
      BootPreparation.symbol=BootReadText(file);
      BootChartSymbol=BootReadText(file);
      int error=FileReadInteger(file);BootPrints=0;
      string primed=IntegerToString(12345);if(primed!="12345")return 5;
      FileWriteInteger(BootOutput,id);ulong at=FileTell(BootOutput);FileWriteInteger(BootOutput,0);ulong begin=FileTell(BootOutput);
      ResetLastError();if(error!=0)SetUserError(731);
      Bot3InitializeStartupContext(BootChartSymbol,BootInputs,BootContext,BootPreparation,BootHistory,BootPanel,BootDaily,BootState);
      uint final_error=GetLastError();BootSnapshot(final_error);FileWriteInteger(BootOutput,BootPrints);
      ulong end=FileTell(BootOutput);FileSeek(BootOutput,(long)at,SEEK_SET);FileWriteInteger(BootOutput,(int)(end-begin));FileSeek(BootOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 6;FileClose(file);FileClose(BootOutput);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
