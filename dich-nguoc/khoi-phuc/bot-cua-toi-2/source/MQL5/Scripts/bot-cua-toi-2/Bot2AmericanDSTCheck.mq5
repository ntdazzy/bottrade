#property strict
// Supplies clock reads; records real MT5 calendar/math/string results for native comparison.
input string CheckRun="";
union DoubleBits { double value;ulong bits; };
ulong ValueBits(const double value) { DoubleBits b;b.value=value;return b.bits; }
int case_id=0,fixture=INVALID_HANDLE,trace_file=INVALID_HANDLE;
int now_index=0,struct_index=0,string_index=0,fail_mask=0,zero_mask=0,year_override=0;
int call_count=0;
long clock_values[3];
ulong call_hash=0;
bool api_error=false;
ulong TextHash(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      uint c=StringGetCharacter(value,i);
      h^=c&255;h*=(ulong)0x100000001b3;
      h^=(c>>8)&255;h*=(ulong)0x100000001b3;
   }
   return h;
}
void WriteText(const string value)
{
   FileWriteInteger(fixture,StringLen(value));
   for(int i=0;i<StringLen(value);i++) FileWriteInteger(fixture,StringGetCharacter(value,i),SHORT_VALUE);
}
void FixtureHeader(const int kind)
{
   FileWriteInteger(fixture,case_id);FileWriteInteger(fixture,kind);
}
void Trace(const ulong api,const ulong a,const ulong b,const ulong c)
{
   ulong words[4];words[0]=api;words[1]=a;words[2]=b;words[3]=c;
   FileWriteInteger(trace_file,case_id);
   for(int n=0;n<4;n++)
   {
      FileWriteLong(trace_file,(long)words[n]);
      for(int j=0;j<8;j++) { call_hash^=(words[n]>>(8*j))&255;call_hash*=(ulong)0x100000001b3; }
   }
   call_count++;
}
ulong StructHash(const MqlDateTime &dt)
{
   int words[8];words[0]=dt.year;words[1]=dt.mon;words[2]=dt.day;words[3]=dt.hour;
   words[4]=dt.min;words[5]=dt.sec;words[6]=dt.day_of_week;words[7]=dt.day_of_year;
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<8;i++)
   {
      FileWriteInteger(fixture,words[i]);
      for(int j=0;j<4;j++) { h^=((uint)words[i]>>(8*j))&255;h*=(ulong)0x100000001b3; }
   }
   return h;
}
datetime MockTimeCurrent()
{
   if(now_index>=3) { api_error=true;return 0; }
   long value=clock_values[now_index];
   FixtureHeader(1);FileWriteLong(fixture,value);
   Trace(1,(ulong)now_index,(ulong)value,0);now_index++;
   return (datetime)value;
}
bool MockTimeToStruct(const datetime value,MqlDateTime &dt)
{
   bool forced=((fail_mask&(1<<struct_index))!=0);
   bool ok=false;
   if(!forced) ok=TimeToStruct(value,dt);
   if(struct_index==0 && year_override!=0) dt.year=year_override;
   FixtureHeader(2);FileWriteLong(fixture,(long)value);
   FileWriteInteger(fixture,(int)forced);FileWriteInteger(fixture,(int)ok);
   ulong hash=StructHash(dt);
   Trace(2,(ulong)value,(ulong)ok,hash);struct_index++;
   return ok;
}
double MockMathMod(const double a,const double b)
{
   double value=MathMod(a,b);
   FixtureHeader(3);FileWriteDouble(fixture,a);FileWriteDouble(fixture,b);FileWriteDouble(fixture,value);
   Trace(3,ValueBits(a),ValueBits(b),ValueBits(value));return value;
}
int MockConcatenate(string &output,const int year,const string suffix)
{
   string before=output;
   if(before!="") api_error=true;
   int result=StringConcatenate(output,year,suffix);
   FixtureHeader(4);FileWriteInteger(fixture,year);FileWriteInteger(fixture,result);
   WriteText(before);WriteText(suffix);WriteText(output);
   Trace(4,(ulong)year,TextHash(suffix),TextHash(output));return result;
}
datetime MockStringToTime(const string value)
{
   datetime result=StringToTime(value);
   if((zero_mask&(1<<string_index))!=0) result=0;
   FixtureHeader(5);WriteText(value);FileWriteLong(fixture,(long)result);
   Trace(5,TextHash(value),(ulong)result,(ulong)string_index);string_index++;
   return result;
}
void MockPrint(const string value)
{
   FixtureHeader(6);WriteText(value);Trace(6,TextHash(value),0,0);
}
#define TimeCurrent MockTimeCurrent
#define TimeToStruct MockTimeToStruct
#define MathMod MockMathMod
#define StringConcatenate MockConcatenate
#define StringToTime MockStringToTime
#define Print MockPrint
#include "../../Include/bot-cua-toi-2/Bot2AmericanDST.mqh"
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot2-american-dst\\"+CheckRun+"\\";
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x44535431 || version!=1 || count<1 || FileSize(source)!=(ulong)12+(ulong)count*40)
   { FileClose(source);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN);
   trace_file=FileOpen(folder+"mql5-trace.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE || fixture==INVALID_HANDLE || trace_file==INVALID_HANDLE)
   {
      FileClose(source);
      if(output!=INVALID_HANDLE) FileClose(output);
      if(fixture!=INVALID_HANDLE) FileClose(fixture);
      if(trace_file!=INVALID_HANDLE) FileClose(trace_file);
      return 1;
   }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   FileWriteInteger(fixture,magic);FileWriteInteger(fixture,version);FileWriteInteger(fixture,count);
   for(int i=0;i<count;i++)
   {
      case_id=FileReadInteger(source);
      for(int j=0;j<3;j++) clock_values[j]=FileReadLong(source);
      fail_mask=FileReadInteger(source);zero_mask=FileReadInteger(source);year_override=FileReadInteger(source);
      now_index=0;struct_index=0;string_index=0;call_count=0;
      call_hash=(ulong)0xcbf29ce484222325;api_error=false;
      bool result=Bot2AmericanDST();
      FileWriteInteger(output,case_id);FileWriteInteger(output,api_error ? -2 : (int)result);
      FileWriteInteger(output,call_count);FileWriteLong(output,(long)call_hash);
   }
   bool exact=FileTell(source)==FileSize(source);
   FileClose(source);FileClose(output);FileClose(fixture);FileClose(trace_file);
   return exact ? 0 : 1;
}
