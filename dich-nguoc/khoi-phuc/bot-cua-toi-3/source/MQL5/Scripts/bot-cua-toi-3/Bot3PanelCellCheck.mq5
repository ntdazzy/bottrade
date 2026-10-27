#property strict
input string CheckRun="";
string MockIntegerText(const long value,const int width=0,const ushort fill=' ');
bool MockCreate(const long chart,const string name,const ENUM_OBJECT type,const int window,const datetime time,const double price);
bool MockInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value);
bool MockText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
#define IntegerToString MockIntegerText
#define ObjectCreate MockCreate
#define ObjectSetInteger MockInteger
#define ObjectSetString MockText
#include "../../Include/bot-cua-toi-3/Bot3PanelCell.mqh"
#undef IntegerToString
#undef ObjectCreate
#undef ObjectSetInteger
#undef ObjectSetString
int TapeFile,Calls,ErrorMode;double X,Y;uchar Flag;string Label;uint LogicalError;
struct Effect { int after;double x,y;uchar flag;string text; };Effect Effects[];
union Number { double value;ulong word; };
ulong Bits(const double value) { Number n;n.value=value;return n.word; }
string ReadText(const int file)
{ int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n)); }
void Text(const string value)
{ if(value==NULL) { FileWriteInteger(TapeFile,-1);return; }int n=StringLen(value);FileWriteInteger(TapeFile,n);if(n>0) FileWriteString(TapeFile,value,n); }
void Snapshot()
{ FileWriteLong(TapeFile,(long)Bits(X));FileWriteLong(TapeFile,(long)Bits(Y));FileWriteLong(TapeFile,(long)Flag);Text(Label);FileWriteLong(TapeFile,(long)LogicalError); }
void Record(const int api,const ulong a,const ulong b,const ulong c,const ulong d,const ulong e,
            const string name,const string value,const ulong reply)
{
   Snapshot();FileWriteInteger(TapeFile,api);FileWriteLong(TapeFile,(long)a);FileWriteLong(TapeFile,(long)b);
   FileWriteLong(TapeFile,(long)c);FileWriteLong(TapeFile,(long)d);FileWriteLong(TapeFile,(long)e);Text(name);Text(value);FileWriteLong(TapeFile,(long)reply);
   Calls++;if(ErrorMode!=0) LogicalError=(uint)(9000+Calls);FileWriteInteger(TapeFile,(int)LogicalError);
   for(int i=0;i<ArraySize(Effects);i++) if(Effects[i].after==Calls)
   { X=Effects[i].x;Y=Effects[i].y;Flag=Effects[i].flag;Label=Effects[i].text; }
}
string MockIntegerText(const long value,const int width,const ushort fill)
{ string reply=IntegerToString(value,width,fill);Record(1,(ulong)value,(ulong)(uint)width,(ulong)fill,0,0,reply,NULL,0);return reply; }
bool MockCreate(const long chart,const string name,const ENUM_OBJECT type,const int window,const datetime time,const double price)
{ bool reply=Calls%2==0;Record(2,(ulong)chart,(ulong)type,(ulong)(uint)window,(ulong)time,Bits(price),name,NULL,(ulong)reply);return reply; }
bool MockInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value)
{ bool reply=Calls%2!=0;Record(3,(ulong)chart,(ulong)property,(ulong)value,0,0,name,NULL,(ulong)reply);return reply; }
bool MockText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value)
{ bool reply=Calls%2==0;Record(4,(ulong)chart,(ulong)property,0,0,0,name,value,(ulong)reply);return reply; }
int OnStart()
{
   if(CheckRun=="") return 1;string folder="bot3-panel-cell\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x50434c31 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input_file),base_y=FileReadInteger(input_file),index=FileReadInteger(input_file),row=FileReadInteger(input_file),column=FileReadInteger(input_file);
      uint color_value=(uint)FileReadInteger(input_file);X=FileReadDouble(input_file);Y=FileReadDouble(input_file);Flag=(uchar)FileReadInteger(input_file);
      Label=ReadText(input_file);ErrorMode=FileReadInteger(input_file);int n=FileReadInteger(input_file);ArrayResize(Effects,n);
      for(int k=0;k<n;k++)
      { Effects[k].after=FileReadInteger(input_file);Effects[k].x=FileReadDouble(input_file);Effects[k].y=FileReadDouble(input_file);Effects[k].flag=(uchar)FileReadInteger(input_file);Effects[k].text=ReadText(input_file); }
      Calls=0;LogicalError=0;string name=folder+"events-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE)return 5;
      Bot3CreatePanelCell(base_y,index,Label,row,column,color_value,X,Y,Flag);Snapshot();FileClose(TapeFile);
      int event_file=FileOpen(name,FILE_READ|FILE_BIN);if(event_file==INVALID_HANDLE)return 6;
      int size=(int)FileSize(event_file);uchar bytes[];ArrayResize(bytes,size);if(size>0)FileReadArray(event_file,bytes,0,size);FileClose(event_file);
      FileWriteInteger(output,id);FileWriteInteger(output,size);if(size>0)FileWriteArray(output,bytes,0,size);
   }
   FileClose(input_file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
