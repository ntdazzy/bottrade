#property strict
#property script_show_inputs
input string CheckRun="";
int CheckOutput=INVALID_HANDLE,CheckScenario=0,CheckMagic=0,CheckKind=0;
int CheckSelectedOrder=-1,CheckSelectedPosition=-1,CheckTotalIndex=0;
int CheckTotalCount=0,CheckOrderCount=0,CheckPositionCount=0;
int CheckOrderCalls=0,CheckPositionCalls=0,CheckIntegerCalls=0,CheckStringCalls=0;
int CheckTotals[100],CheckOrderNull[100];
ulong CheckTicket=0,CheckOrderTickets[100],CheckPositions[100];
long CheckLimit=0,CheckOrderMagic[100],CheckOrderTypes[100];
string CheckSymbol,CheckOrderSymbols[100];
double CheckResults[100][2];
bool CheckBad=false;
union DoubleBits { double value;ulong bits; };
void WriteText(const int file,const string text)
{
   int n=StringLen(text);FileWriteInteger(file,n);
   if(n>0) FileWriteString(file,text,n);
}
string ReadText(const int file)
{
   int n=FileReadInteger(file);
   if(n<0 || n>4096) { CheckBad=true;return ""; }
   return n>0 ? FileReadString(file,n) : "";
}
void ApplyChange(const int api)
{
   if(api==1 && CheckTotalIndex==1 && CheckScenario==1)
   { CheckResults[0][0]=99.9;CheckResults[0][1]=-7.5; }
   if(api==5 && CheckPositionCalls==1 && CheckScenario==2)
   { CheckResults[0][0]=88.75;CheckResults[0][1]=.125; }
   if(api==2 && CheckOrderCalls==1 && CheckScenario==3)
   { CheckMagic=-1;CheckSymbol="Renamed"; }
   if(api==3 && CheckIntegerCalls==1 && CheckScenario==4) CheckMagic=43;
   if(api==4 && CheckStringCalls==1 && CheckScenario==5) CheckSymbol="Renamed";
}
int ScanOrdersTotal()
{
   if(CheckTotalIndex>=CheckTotalCount) { CheckBad=true;return -1; }
   int value=CheckTotals[CheckTotalIndex++];
   FileWriteInteger(CheckOutput,1);FileWriteInteger(CheckOutput,value);ApplyChange(1);return value;
}
ulong ScanOrderGetTicket(const int index)
{
   ulong value=0;
   if(index>=0 && index<CheckOrderCount) value=CheckOrderTickets[index];
   if(value!=0) CheckSelectedOrder=index;
   FileWriteInteger(CheckOutput,2);FileWriteInteger(CheckOutput,index);FileWriteLong(CheckOutput,(long)value);FileWriteInteger(CheckOutput,CheckSelectedOrder);
   CheckOrderCalls++;ApplyChange(2);return value;
}
ulong ScanPositionGetTicket(const int index)
{
   ulong value=0;
   if(index>=0 && index<CheckPositionCount) value=CheckPositions[index];
   if(value!=0) CheckSelectedPosition=index;
   FileWriteInteger(CheckOutput,5);FileWriteInteger(CheckOutput,index);FileWriteLong(CheckOutput,(long)value);FileWriteInteger(CheckOutput,CheckSelectedPosition);
   CheckPositionCalls++;ApplyChange(5);return value;
}
long ScanOrderGetInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
   long value=0;
   if(CheckSelectedOrder<0 || CheckSelectedOrder>=CheckOrderCount) CheckBad=true;
   else if(property==ORDER_MAGIC) value=CheckOrderMagic[CheckSelectedOrder];
   else if(property==ORDER_TYPE) value=CheckOrderTypes[CheckSelectedOrder];
   else CheckBad=true;
   FileWriteInteger(CheckOutput,3);FileWriteInteger(CheckOutput,(int)property);FileWriteLong(CheckOutput,value);
   CheckIntegerCalls++;ApplyChange(3);return value;
}
string ScanOrderGetString(const ENUM_ORDER_PROPERTY_STRING property)
{
   string value;
   if(property!=ORDER_SYMBOL || CheckSelectedOrder<0 || CheckSelectedOrder>=CheckOrderCount) CheckBad=true;
   else if(CheckOrderNull[CheckSelectedOrder]!=0) value=NULL;
   else value=CheckOrderSymbols[CheckSelectedOrder];
   FileWriteInteger(CheckOutput,4);FileWriteInteger(CheckOutput,(int)property);WriteText(CheckOutput,value);
   CheckStringCalls++;ApplyChange(4);return value;
}
long ScanAccountInfoInteger(const ENUM_ACCOUNT_INFO_INTEGER property)
{
   if(property!=ACCOUNT_LIMIT_ORDERS) CheckBad=true;
   FileWriteInteger(CheckOutput,6);FileWriteInteger(CheckOutput,(int)property);FileWriteLong(CheckOutput,CheckLimit);return CheckLimit;
}
#define OrdersTotal ScanOrdersTotal
#define OrderGetTicket ScanOrderGetTicket
#define PositionGetTicket ScanPositionGetTicket
#define OrderGetInteger ScanOrderGetInteger
#define OrderGetString ScanOrderGetString
#define AccountInfoInteger ScanAccountInfoInteger
#include <bot-cua-toi-1/Bot1OrderScan.mqh>
#undef OrdersTotal
#undef OrderGetTicket
#undef PositionGetTicket
#undef OrderGetInteger
#undef OrderGetString
#undef AccountInfoInteger
int OnStart()
{
   string folder="bot1-order-scan\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN|FILE_UNICODE);
   if(file==INVALID_HANDLE) return 3;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x53434e31 || version!=1 || count<1 || count>10000) { FileClose(file);return 4; }
   CheckOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(CheckOutput==INVALID_HANDLE) { FileClose(file);return 5; }
   FileWriteInteger(CheckOutput,magic);FileWriteInteger(CheckOutput,version);FileWriteInteger(CheckOutput,count);FileWriteInteger(CheckOutput,6);
   FileWriteInteger(CheckOutput,(int)ORDER_MAGIC);FileWriteInteger(CheckOutput,(int)ORDER_TYPE);FileWriteInteger(CheckOutput,(int)ORDER_SYMBOL);
   FileWriteInteger(CheckOutput,(int)ACCOUNT_LIMIT_ORDERS);FileWriteInteger(CheckOutput,(int)ORDER_TYPE_BUY_STOP);FileWriteInteger(CheckOutput,(int)ORDER_TYPE_SELL_STOP);
   for(int i=0;i<count;i++)
   {
      CheckBad=false;
      int id=FileReadInteger(file);CheckKind=FileReadInteger(file);CheckScenario=FileReadInteger(file);CheckMagic=FileReadInteger(file);
      int symbol_null=FileReadInteger(file);CheckSelectedOrder=FileReadInteger(file);CheckSelectedPosition=FileReadInteger(file);
      CheckTicket=(ulong)FileReadLong(file);CheckLimit=FileReadLong(file);CheckSymbol=ReadText(file);if(symbol_null!=0) CheckSymbol=NULL;
      CheckTotalCount=FileReadInteger(file);
      if(id!=i || CheckKind<0 || CheckKind>2 || CheckTotalCount<0 || CheckTotalCount>100 || CheckScenario<0 || CheckScenario>5) return 6;
      for(int j=0;j<CheckTotalCount;j++) CheckTotals[j]=FileReadInteger(file);
      CheckOrderCount=FileReadInteger(file);if(CheckOrderCount<0 || CheckOrderCount>100) return 7;
      for(int j=0;j<CheckOrderCount;j++)
      {
         CheckOrderTickets[j]=(ulong)FileReadLong(file);CheckOrderMagic[j]=FileReadLong(file);CheckOrderTypes[j]=FileReadLong(file);
         CheckOrderNull[j]=FileReadInteger(file);CheckOrderSymbols[j]=ReadText(file);
      }
      CheckPositionCount=FileReadInteger(file);if(CheckPositionCount<0 || CheckPositionCount>100) return 8;
      for(int j=0;j<CheckPositionCount;j++) CheckPositions[j]=(ulong)FileReadLong(file);
      for(int row=0;row<100;row++) for(int col=0;col<2;col++) CheckResults[row][col]=FileReadDouble(file);
      CheckTotalIndex=0;CheckOrderCalls=0;CheckPositionCalls=0;CheckIntegerCalls=0;CheckStringCalls=0;
      FileWriteInteger(CheckOutput,id);int result=0;
      if(CheckKind==0) result=Bot1CountBuyPending(CheckMagic,CheckSymbol,CheckTicket);
      else if(CheckKind==1) result=Bot1CountSellPending(CheckMagic,CheckSymbol,CheckTicket);
      else Bot1CleanPendingResults(CheckResults,CheckTicket);
      FileWriteInteger(CheckOutput,0);FileWriteInteger(CheckOutput,result);FileWriteLong(CheckOutput,(long)CheckTicket);
      FileWriteInteger(CheckOutput,CheckSelectedOrder);FileWriteInteger(CheckOutput,CheckSelectedPosition);FileWriteInteger(CheckOutput,CheckTotalIndex);FileWriteInteger(CheckOutput,CheckMagic);WriteText(CheckOutput,CheckSymbol);
      for(int row=0;row<100;row++) for(int col=0;col<2;col++)
      { DoubleBits value;value.value=CheckResults[row][col];FileWriteLong(CheckOutput,(long)value.bits); }
      if(CheckBad || CheckTotalIndex!=CheckTotalCount) { FileClose(file);FileClose(CheckOutput);return 9; }
   }
   bool consumed=FileTell(file)==FileSize(file);FileClose(file);FileClose(CheckOutput);if(!consumed) return 10;
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
