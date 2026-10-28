#property strict
input string CheckRun="";
datetime MockCurrent();datetime MockBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
#define TimeCurrent MockCurrent
#define iTime MockBar
#include "../../Include/bot-cua-toi-3/Bot3DispatchGate.mqh"
#undef TimeCurrent
#undef iTime
Bot3DispatchGateState State;uchar Mode,M1;string GateSymbol;
long Times[256],BarsData[256],Effects[256][4];int TimeCount,BarCount,EffectCount,TimePos,BarPos,Counts[3];
int Tape,ErrorOverride=-1;bool Final=false,Stopped=false;
void Word(const ulong value){FileWriteLong(Tape,(long)value);}
void Text(const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,value,n);}
string ReadText(const int file){int n=FileReadInteger(file);if(n<0)return NULL;return n==0 ? "" : FileReadString(file,n);}
void Snapshot(){uint e=ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride;Word(Mode);Word(M1);Word((ulong)State.last_time);Word((ulong)State.last_bar);Text(GateSymbol);Word(e);if(Final)Word((ulong)Stopped);}
void Begin(){ulong start=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)start,SEEK_SET);FileWriteInteger(Tape,(int)(end-start-4));FileSeek(Tape,(long)end,SEEK_SET);}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if(Effects[i][0]!=api || Effects[i][1]!=n)continue;long f=Effects[i][2],v=Effects[i][3];if(f==1)Mode=(uchar)v;else if(f==2)M1=(uchar)v;else if(f==3)State.last_time=v;else if(f==4)State.last_bar=v;}}
void End(const int api,const ulong a,const ulong b,const ulong c,const string value=NULL){uint e=GetLastError();FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Word(0);Text(value);Text(NULL);Text(NULL);Text(NULL);FileWriteInteger(Tape,0);FileWriteInteger(Tape,(int)e);}
datetime MockCurrent(){Begin();long value=Times[TimePos<TimeCount ? TimePos : TimeCount-1];TimePos++;Effect(1);End(1,(ulong)value,0,0);return (datetime)value;}
datetime MockBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();long value=BarsData[BarPos<BarCount ? BarPos : BarCount-1];BarPos++;Effect(2);End(2,(ulong)frame,(ulong)(long)shift,(ulong)value,symbol);return (datetime)value;}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-dispatch-gate\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x47415431 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);FileWriteInteger(tapes,magic);FileWriteInteger(tapes,version);FileWriteInteger(tapes,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file);Mode=(uchar)FileReadLong(file);M1=(uchar)FileReadLong(file);State.last_time=FileReadLong(file);State.last_bar=FileReadLong(file);GateSymbol=ReadText(file);
      TimeCount=FileReadInteger(file);if(TimeCount<1 || TimeCount>256)return 8;for(int j=0;j<TimeCount;j++)Times[j]=FileReadLong(file);
      BarCount=FileReadInteger(file);if(BarCount<1 || BarCount>256)return 8;for(int j=0;j<BarCount;j++)BarsData[j]=FileReadLong(file);
      EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>256)return 8;for(int j=0;j<EffectCount;j++)for(int k=0;k<4;k++)Effects[j][k]=FileReadLong(file);
      TimePos=0;BarPos=0;ArrayInitialize(Counts,0);string name=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(name,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();Final=false;ErrorOverride=-1;Stopped=Bot3DispatchGate(Mode,M1,GateSymbol,State);int error=GetLastError();FileClose(Tape);
      int part=FileOpen(name,FILE_READ|FILE_BIN);if(part==INVALID_HANDLE)return 6;int bytes=(int)FileSize(part);uchar raw[];ArrayResize(raw,bytes);if(bytes>0)FileReadArray(part,raw);FileClose(part);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,bytes);if(bytes>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;Final=true;ErrorOverride=error;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
