// Isolated checks of the two anchor segments. No trading functions.
#property strict
#property script_show_inputs
input string CheckRun="";

long AnchorInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property);
#define SymbolInfoInteger AnchorInteger
#include "../../Include/bot-cua-toi-3/Bot3ManagementAnchor.mqh"
#undef SymbolInfoInteger

Bot3ManagementAnchorState Table;
double Unit,StepSetting,Limit,ControlValues[2];
uchar UseAnchor;
long DigitsReply;
int Output=INVALID_HANDLE,Control,ControlRow,Calls,Fault;
union AnchorBits { double d;long q; };

double ReadBits(const int file)
{
   AnchorBits value;value.q=FileReadLong(file);return value.d;
}
void WriteBits(const int file,const double number)
{
   AnchorBits value;value.d=number;FileWriteLong(file,value.q);
}
void WriteSnapshot()
{
   WriteBits(Output,Table.step_reference);WriteBits(Output,Unit);
   WriteBits(Output,StepSetting);WriteBits(Output,Limit);
   FileWriteInteger(Output,(int)UseAnchor);
   for(int row=0;row<100;row++)
      for(int column=0;column<2;column++) WriteBits(Output,Table.rows[row][column]);
}
long AnchorInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   WriteSnapshot();Calls++;
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS) Fault=1;
   if(Control==1) Unit=ControlValues[0];
   if(Control==2) StepSetting=ControlValues[0];
   if(Control==3) Limit=ControlValues[0];
   if(Control==4) UseAnchor=(uchar)(long)ControlValues[0];
   if(Control==5)
      for(int column=0;column<2;column++) Table.rows[ControlRow][column]=ControlValues[column];
   WriteSnapshot();return DigitsReply;
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 2;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 2;
   }
   string folder="bot3-management-anchor\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 3;
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(input_file==INVALID_HANDLE) return 4;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x414e4333 || version!=1 || count<1) return 5;
   Output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(Output==INVALID_HANDLE) return 6;
   FileWriteInteger(Output,magic);FileWriteInteger(Output,version);FileWriteInteger(Output,count);
   int total_faults=0;
   for(int index=0;index<count;index++)
   {
      ZeroMemory(Table);Calls=0;Fault=0;
      int id=FileReadInteger(input_file),side=FileReadInteger(input_file);
      int flag=FileReadInteger(input_file),fill=FileReadInteger(input_file);
      if(id!=index || side<0 || side>1 || flag<0 || flag>255 || fill<0 || fill>3) return 7;
      UseAnchor=(uchar)flag;DigitsReply=FileReadLong(input_file);
      double ticket=ReadBits(input_file),opened=ReadBits(input_file);
      Unit=ReadBits(input_file);StepSetting=ReadBits(input_file);Limit=ReadBits(input_file);
      Table.step_reference=ReadBits(input_file);
      AnchorBits nan;nan.q=(long)0x7ff8000000000001;
      for(int row=0;row<100;row++)
      {
         if(fill==1 || fill==3)
         {
            Table.rows[row][0]=(double)(row+1)*(fill==1 ? 1.0 : -1.0);
            Table.rows[row][1]=100.0+(double)row*0.125;
         }
         if(fill==2) { Table.rows[row][0]=nan.d;Table.rows[row][1]=111.25; }
      }
      int changes=FileReadInteger(input_file);
      if(changes<0 || changes>100) return 8;
      for(int j=0;j<changes;j++)
      {
         int row=FileReadInteger(input_file);if(row<0 || row>=100) return 8;
         for(int column=0;column<2;column++) Table.rows[row][column]=ReadBits(input_file);
      }
      Control=FileReadInteger(input_file);ControlRow=FileReadInteger(input_file);
      for(int column=0;column<2;column++) ControlValues[column]=ReadBits(input_file);
      if(Control<0 || Control>5 || ControlRow<0 || ControlRow>=100) return 8;
      FileWriteInteger(Output,id);FileWriteInteger(Output,side);
      string symbol="CHECK";
      Bot3PrepareManagementAnchor(Table,symbol,Unit,StepSetting,Limit,UseAnchor,side!=0,ticket,opened);
      FileWriteLong(Output,Table.ticket);WriteBits(Output,Table.level);WriteBits(Output,Table.reference);
      FileWriteInteger(Output,(int)Table.gap_passed);WriteSnapshot();
      FileWriteInteger(Output,Calls);FileWriteInteger(Output,Fault);total_faults+=Fault;
   }
   if(FileTell(input_file)!=FileSize(input_file)) return 9;
   FileClose(input_file);FileClose(Output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 10;
   FileWriteInteger(status,total_faults);FileWriteInteger(status,count);FileClose(status);
   Print("Bot3ManagementAnchorCheck:",total_faults,",",count);
   return total_faults;
}
