#property strict
input string CheckRun="";
int PresenceSeed,PresencePositionTotal,PresenceOrderTotal,PresencePositionCount,PresenceOrderCount;
ulong PresencePositionTickets[32],PresenceOrderTickets[32];long PresencePositionMagic[32],PresenceOrderMagic[32];
uchar PresenceFlags[20];int PresenceCounts[7],PresenceEffects[128][4],PresenceEffectCount,PresenceSelectedPosition,PresenceSelectedOrder,PresenceOutput;
void PresenceRecord(const int api,const int argument,const ulong reply)
{
   FileWriteInteger(PresenceOutput,api);FileWriteInteger(PresenceOutput,argument);FileWriteLong(PresenceOutput,(long)reply);
   FileWriteInteger(PresenceOutput,PresenceSeed);for(int i=0;i<20;i++)FileWriteInteger(PresenceOutput,(int)PresenceFlags[i]);
   int n=++PresenceCounts[api];
   for(int i=0;i<PresenceEffectCount;i++)
   {
      if(PresenceEffects[i][0]!=api || PresenceEffects[i][1]!=n)continue;
      int field=PresenceEffects[i][2],value=PresenceEffects[i][3];
      if(field==-1)PresenceSeed=value;else PresenceFlags[field]=(uchar)value;
   }
}
int MockPositions(){PresenceRecord(1,0,(ulong)(long)PresencePositionTotal);return PresencePositionTotal;}
ulong MockPositionTicket(const int index)
{
   PresenceSelectedPosition=index;ulong value=index>=0 && index<PresencePositionCount ? PresencePositionTickets[index] : 0;
   PresenceRecord(2,index,value);return value;
}
long MockPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   long value=PresencePositionMagic[PresenceSelectedPosition];PresenceRecord(3,(int)property,(ulong)value);return value;
}
int MockOrders(){PresenceRecord(4,0,(ulong)(long)PresenceOrderTotal);return PresenceOrderTotal;}
ulong MockOrderTicket(const int index)
{
   PresenceSelectedOrder=index;ulong value=index>=0 && index<PresenceOrderCount ? PresenceOrderTickets[index] : 0;
   PresenceRecord(5,index,value);return value;
}
long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
   long value=PresenceOrderMagic[PresenceSelectedOrder];PresenceRecord(6,(int)property,(ulong)value);return value;
}
#define PositionsTotal MockPositions
#define PositionGetTicket MockPositionTicket
#define PositionGetInteger MockPositionInteger
#define OrdersTotal MockOrders
#define OrderGetTicket MockOrderTicket
#define OrderGetInteger MockOrderInteger
#include "../../Include/bot-cua-toi-3/Bot3StrategyPresence.mqh"
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef OrdersTotal
#undef OrderGetTicket
#undef OrderGetInteger
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-strategy-presence\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x50523331 || version!=1 || count<1)return 3;
   PresenceOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(PresenceOutput==INVALID_HANDLE)return 4;
   FileWriteInteger(PresenceOutput,magic);FileWriteInteger(PresenceOutput,version);FileWriteInteger(PresenceOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);PresenceSeed=FileReadInteger(file);PresencePositionTotal=FileReadInteger(file);PresenceOrderTotal=FileReadInteger(file);
      for(int i=0;i<20;i++)PresenceFlags[i]=(uchar)FileReadInteger(file);
      PresencePositionCount=FileReadInteger(file);if(PresencePositionCount<0 || PresencePositionCount>32)return 5;
      for(int i=0;i<PresencePositionCount;i++){PresencePositionTickets[i]=(ulong)FileReadLong(file);PresencePositionMagic[i]=FileReadLong(file);}
      PresenceOrderCount=FileReadInteger(file);if(PresenceOrderCount<0 || PresenceOrderCount>32)return 5;
      for(int i=0;i<PresenceOrderCount;i++){PresenceOrderTickets[i]=(ulong)FileReadLong(file);PresenceOrderMagic[i]=FileReadLong(file);}
      PresenceEffectCount=FileReadInteger(file);if(PresenceEffectCount<0 || PresenceEffectCount>128)return 5;
      for(int i=0;i<PresenceEffectCount;i++)for(int j=0;j<4;j++)PresenceEffects[i][j]=FileReadInteger(file);
      ArrayInitialize(PresenceCounts,0);PresenceSelectedPosition=-1;PresenceSelectedOrder=-1;
      FileWriteInteger(PresenceOutput,id);ulong length_at=FileTell(PresenceOutput);FileWriteInteger(PresenceOutput,0);ulong begin=FileTell(PresenceOutput);
      Bot3CollectStrategyPresence(PresenceSeed,PresenceFlags);
      FileWriteInteger(PresenceOutput,0);FileWriteInteger(PresenceOutput,PresenceSeed);
      for(int i=0;i<20;i++)FileWriteInteger(PresenceOutput,(int)PresenceFlags[i]);
      for(int i=1;i<=6;i++)FileWriteInteger(PresenceOutput,PresenceCounts[i]);
      ulong end=FileTell(PresenceOutput);FileSeek(PresenceOutput,(long)length_at,SEEK_SET);FileWriteInteger(PresenceOutput,(int)(end-begin));FileSeek(PresenceOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 6;
   FileClose(file);FileClose(PresenceOutput);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
