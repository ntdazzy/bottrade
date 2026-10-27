#property strict
input string CheckRun="";
bool MockObjectDelete(const long chart,const string name);
string MockIntegerText(const long value,const int digits=0,const ushort fill=' ');
bool MockIndicatorRelease(const int handle);
int MockObjectsDeleteAll(const long chart,const int sub_window=-1,const int object_type=-1);
#define ObjectDelete MockObjectDelete
#define IntegerToString MockIntegerText
#define IndicatorRelease MockIndicatorRelease
#define ObjectsDeleteAll MockObjectsDeleteAll
#include "../../Include/bot-cua-toi-3/Bot3Lifecycle.mqh"
#undef ObjectDelete
#undef IntegerToString
#undef IndicatorRelease
#undef ObjectsDeleteAll
int EventFile,CaseId;
void Word(const ulong value) { FileWriteLong(EventFile,(long)value); }
void Text(const string value) { int n=StringLen(value);FileWriteInteger(EventFile,n);if(n>0) FileWriteString(EventFile,value,n); }
void Record(const int api,const long a,const long b,const long c,const string name) { Word(api);Word((ulong)a);Word((ulong)b);Word((ulong)c);Text(name); }
bool MockObjectDelete(const long chart,const string name) { Record(1,chart,0,0,name);return true; }
string MockIntegerText(const long value,const int digits,const ushort fill) { Record(2,value,digits,fill,"");return IntegerToString(value,digits,fill); }
bool MockIndicatorRelease(const int handle) { Record(3,handle,0,0,"");return true; }
int MockObjectsDeleteAll(const long chart,const int sub_window,const int object_type) { Record(4,chart,sub_window,object_type,"");return 0; }
int OnStart()
{
 if(CheckRun=="")return 1;string folder="bot3-lifecycle\\"+CheckRun+"\\";
 int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE)return 2;
 int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);if(magic!=0x4c594331||version!=1||count<1)return 3;
 int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
 FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
 for(int row=0;row<count;row++){ CaseId=FileReadInteger(input_file);bool extended=FileReadInteger(input_file)!=0;int indicator=FileReadInteger(input_file);string name=folder+"events-"+IntegerToString(CaseId)+".bin";EventFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(EventFile==INVALID_HANDLE)return 5;Bot3DeinitializePanel(extended,indicator);FileClose(EventFile);int ev=FileOpen(name,FILE_READ|FILE_BIN);if(ev==INVALID_HANDLE)return 6;int size=(int)FileSize(ev);uchar bytes[];ArrayResize(bytes,size);if(size>0)FileReadArray(ev,bytes,0,size);FileClose(ev);FileWriteInteger(output,CaseId);FileWriteInteger(output,size);if(size>0)FileWriteArray(output,bytes,0,size);}
 FileClose(input_file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
