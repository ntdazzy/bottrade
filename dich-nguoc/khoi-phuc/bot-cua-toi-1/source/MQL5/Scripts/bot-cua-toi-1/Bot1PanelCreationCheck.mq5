#property strict
input string CheckRun="";
string MockIntegerText(const long value,const int width=0,const ushort fill=' ');
string MockDoubleText(const double value,const int digits=8);
bool MockCreate(const long chart,const string name,const ENUM_OBJECT type,const int window,const datetime time,const double price);
bool MockInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value);
bool MockText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
int MockFind(const long chart,const string name);
datetime MockServer();
string Bot1PanelDoubleText(const double value);
string Bot1PanelIntegerText(const int value);
string Bot1PanelTimeText(const datetime value);
#define BOT1_PANEL_TEXT_CASTS_MQH
#define IntegerToString MockIntegerText
#define DoubleToString MockDoubleText
#define ObjectCreate MockCreate
#define ObjectSetInteger MockInteger
#define ObjectSetString MockText
#define ObjectFind MockFind
#define TimeTradeServer MockServer
#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"
#undef IntegerToString
#undef DoubleToString
#undef ObjectCreate
#undef ObjectSetInteger
#undef ObjectSetString
#undef ObjectFind
#undef TimeTradeServer
Bot1PanelCreationState P;Bot1NewsEvents Events;Bot1NewsWindows Windows;Bot1NewsSelection Selection;
int TapeFile,Calls,FindReply,ErrorMode,Counts[9];long Clock;uint LogicalError;
struct Effect { int after,api,n,field;ulong word;string text; };Effect Effects[];
union Number { double value;ulong word; };
ulong Bits(const double value) { Number n;n.value=value;return n.word; }
double FromBits(const ulong word) { Number n;n.word=word;return n.value; }
string ReadText(const int file)
{ int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n)); }
void Text(const string value)
{ if(value==NULL) { FileWriteInteger(TapeFile,-1);return; }int n=StringLen(value);FileWriteInteger(TapeFile,n);if(n>0)FileWriteString(TapeFile,value,n); }
void Snapshot()
{
   ulong words[46];
   words[0]=(ulong)P.font;
   words[1]=Bits(P.scale);
   words[2]=(ulong)P.color_flag;
   words[3]=(ulong)P.mode;
   words[4]=Bits(P.strategy_risk);
   words[5]=Bits(P.trade_risk);
   words[6]=(ulong)P.balance_step;
   words[7]=Bits(P.cell_x);
   words[8]=Bits(P.cell_y);
   words[9]=(ulong)P.cell_font_flag;
   words[10]=(ulong)P.closed_star;
   words[11]=(ulong)P.rows_ready;
   words[12]=Bits(P.closed[0]);
   words[13]=Bits(P.closed[1]);
   words[14]=Bits(P.closed[2]);
   words[15]=Bits(P.closed[3]);
   words[16]=Bits(P.closed[4]);
   words[17]=Bits(P.closed[5]);
   words[18]=Bits(P.closed[6]);
   words[19]=Bits(P.closed[7]);
   words[20]=Bits(P.per_trade[0]);
   words[21]=Bits(P.per_trade[1]);
   words[22]=Bits(P.per_trade[2]);
   words[23]=Bits(P.per_trade[3]);
   words[24]=Bits(P.per_trade[4]);
   words[25]=Bits(P.per_trade[5]);
   words[26]=Bits(P.per_trade[6]);
   words[27]=Bits(P.per_trade[7]);
   words[28]=Bits(P.lots[0]);
   words[29]=Bits(P.lots[1]);
   words[30]=Bits(P.lots[2]);
   words[31]=Bits(P.lots[3]);
   words[32]=Bits(P.lots[4]);
   words[33]=Bits(P.lots[5]);
   words[34]=Bits(P.lots[6]);
   words[35]=Bits(P.lots[7]);
   words[36]=(ulong)Events.nfp;
   words[37]=(ulong)Events.interest;
   words[38]=(ulong)Events.cpi;
   words[39]=(ulong)Windows.nfp_enabled;
   words[40]=(ulong)Windows.interest_enabled;
   words[41]=(ulong)Windows.cpi_enabled;
   words[42]=(ulong)Windows.nfp_after;
   words[43]=(ulong)Windows.interest_after;
   words[44]=(ulong)Windows.cpi_after;
   words[45]=(ulong)Selection.block_time;
   FileWriteArray(TapeFile,words,0,46);Text(Selection.label);FileWriteLong(TapeFile,(long)LogicalError);
}
void SetField(const int index,const ulong word,const string text)
{
   switch(index)
   {
      case 0: P.font=(int)word;break;
      case 1: P.scale=FromBits(word);break;
      case 2: P.color_flag=(uchar)word;break;
      case 3: P.mode=(int)word;break;
      case 4: P.strategy_risk=FromBits(word);break;
      case 5: P.trade_risk=FromBits(word);break;
      case 6: P.balance_step=(int)word;break;
      case 7: P.cell_x=FromBits(word);break;
      case 8: P.cell_y=FromBits(word);break;
      case 9: P.cell_font_flag=(uchar)word;break;
      case 10: P.closed_star=(uchar)word;break;
      case 11: P.rows_ready=(uchar)word;break;
      case 12: P.closed[0]=FromBits(word);break;
      case 13: P.closed[1]=FromBits(word);break;
      case 14: P.closed[2]=FromBits(word);break;
      case 15: P.closed[3]=FromBits(word);break;
      case 16: P.closed[4]=FromBits(word);break;
      case 17: P.closed[5]=FromBits(word);break;
      case 18: P.closed[6]=FromBits(word);break;
      case 19: P.closed[7]=FromBits(word);break;
      case 20: P.per_trade[0]=FromBits(word);break;
      case 21: P.per_trade[1]=FromBits(word);break;
      case 22: P.per_trade[2]=FromBits(word);break;
      case 23: P.per_trade[3]=FromBits(word);break;
      case 24: P.per_trade[4]=FromBits(word);break;
      case 25: P.per_trade[5]=FromBits(word);break;
      case 26: P.per_trade[6]=FromBits(word);break;
      case 27: P.per_trade[7]=FromBits(word);break;
      case 28: P.lots[0]=FromBits(word);break;
      case 29: P.lots[1]=FromBits(word);break;
      case 30: P.lots[2]=FromBits(word);break;
      case 31: P.lots[3]=FromBits(word);break;
      case 32: P.lots[4]=FromBits(word);break;
      case 33: P.lots[5]=FromBits(word);break;
      case 34: P.lots[6]=FromBits(word);break;
      case 35: P.lots[7]=FromBits(word);break;
      case 36: Events.nfp=(long)word;break;
      case 37: Events.interest=(long)word;break;
      case 38: Events.cpi=(long)word;break;
      case 39: Windows.nfp_enabled=(uchar)word;break;
      case 40: Windows.interest_enabled=(uchar)word;break;
      case 41: Windows.cpi_enabled=(uchar)word;break;
      case 42: Windows.nfp_after=(int)word;break;
      case 43: Windows.interest_after=(int)word;break;
      case 44: Windows.cpi_after=(int)word;break;
      case 45: Selection.block_time=(long)word;break;
      case 46: Selection.label=text;break;
   }
}
void Record(const int api,const ulong a,const ulong b,const ulong c,const ulong d,const ulong e,const string name,const string value,const ulong reply)
{
   Snapshot();FileWriteInteger(TapeFile,api);ulong args[5];args[0]=a;args[1]=b;args[2]=c;args[3]=d;args[4]=e;
   FileWriteArray(TapeFile,args,0,5);Text(name);Text(value);FileWriteLong(TapeFile,(long)reply);
   Calls++;Counts[api]++;if(ErrorMode!=0)LogicalError=(uint)(9000+Calls);FileWriteInteger(TapeFile,(int)LogicalError);
   for(int i=0;i<ArraySize(Effects);i++)
      if((Effects[i].after>0 && Effects[i].after==Calls) || (Effects[i].api==api && Effects[i].n==Counts[api]))
         SetField(Effects[i].field,Effects[i].word,Effects[i].text);
}
string MockIntegerText(const long value,const int width,const ushort fill)
{ string reply=IntegerToString(value,width,fill);Record(1,(ulong)value,(ulong)(uint)width,(ulong)fill,0,0,reply,NULL,0);return reply; }
string MockDoubleText(const double value,const int digits)
{ string reply=DoubleToString(value,digits);Record(6,Bits(value),(ulong)(uint)digits,0,0,0,reply,NULL,0);return reply; }
bool MockCreate(const long chart,const string name,const ENUM_OBJECT type,const int window,const datetime time,const double price)
{ bool reply=Calls%2==0;Record(2,(ulong)chart,(ulong)type,(ulong)(uint)window,(ulong)time,Bits(price),name,NULL,(ulong)reply);return reply; }
bool MockInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value)
{ bool reply=Calls%2!=0;Record(3,(ulong)chart,(ulong)property,(ulong)value,0,0,name,NULL,(ulong)reply);return reply; }
bool MockText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value)
{ bool reply=Calls%2==0;Record(4,(ulong)chart,(ulong)property,0,0,0,name,value,(ulong)reply);return reply; }
int MockFind(const long chart,const string name)
{ Record(5,(ulong)chart,0,0,0,0,name,NULL,(ulong)(long)FindReply);return FindReply; }
datetime MockServer()
{ long reply=Clock;Record(7,0,0,0,0,0,NULL,NULL,(ulong)reply);return (datetime)reply; }
string Bot1PanelDoubleText(const double value)
{ string reply=(string)value;Record(8,Bits(value),0x58,0,0,0,reply,NULL,0);return reply; }
string Bot1PanelIntegerText(const int value)
{ string reply=(string)value;Record(8,(ulong)(long)value,0x52,0,0,0,reply,NULL,0);return reply; }
string Bot1PanelTimeText(const datetime value)
{ string reply=(string)value;Record(8,(ulong)value,0x54,0,0,0,reply,NULL,0);return reply; }
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-panel-create\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x50435231 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input_file);
      for(int k=0;k<46;k++) SetField(k,(ulong)FileReadLong(input_file),NULL);
      Selection.label=ReadText(input_file);FindReply=FileReadInteger(input_file);ErrorMode=FileReadInteger(input_file);Clock=FileReadLong(input_file);
      int n=FileReadInteger(input_file);ArrayResize(Effects,n);
      for(int k=0;k<n;k++)
      {
         Effects[k].after=FileReadInteger(input_file);Effects[k].api=FileReadInteger(input_file);Effects[k].n=FileReadInteger(input_file);Effects[k].field=FileReadInteger(input_file);
         Effects[k].word=0;Effects[k].text=NULL;
         if(Effects[k].field==46)Effects[k].text=ReadText(input_file);else Effects[k].word=(ulong)FileReadLong(input_file);
      }
      Calls=0;LogicalError=0;ArrayInitialize(Counts,0);
      string name=folder+"events-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE)return 5;
      Bot1CreateInfoPanel(P,Events,Windows,Selection);Snapshot();FileClose(TapeFile);
      int event_file=FileOpen(name,FILE_READ|FILE_BIN);if(event_file==INVALID_HANDLE)return 6;
      int size=(int)FileSize(event_file);uchar bytes[];ArrayResize(bytes,size);if(size>0)FileReadArray(event_file,bytes,0,size);FileClose(event_file);
      FileWriteInteger(output,id);FileWriteInteger(output,size);if(size>0)FileWriteArray(output,bytes,0,size);
   }
   FileClose(input_file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
