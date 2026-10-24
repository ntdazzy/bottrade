#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1NewsBlock.mqh"
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot1-news-block\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(input_file==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x4e455731 || version!=1 || count<1) { FileClose(input_file);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(input_file);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input_file),now=FileReadInteger(input_file),flags=FileReadInteger(input_file);
      long nfp=FileReadInteger(input_file),ir=FileReadInteger(input_file),cpi=FileReadInteger(input_file);
      int nfp_m=FileReadInteger(input_file),ir_m=FileReadInteger(input_file),cpi_m=FileReadInteger(input_file);
      Bot1NewsBlockState state;Bot1SelectNewsBlock(now,(flags&1)!=0,nfp,nfp_m,(flags&2)!=0,ir,ir_m,(flags&4)!=0,cpi,cpi_m,state);
      FileWriteInteger(output,id);FileWriteLong(output,state.block_time);
   }
   bool exact=FileTell(input_file)==FileSize(input_file);FileClose(input_file);FileClose(output);return exact?0:1;
}
