#property strict
#property tester_file "arithmetic-runtime-r1-input.bin"
#import "RecoveryApiLibrary.ex5"
double P_Subtract(const double left,const double right);
double P_SubtractCompound(const double left,const double right);
#import
union DoubleBits { double value;ulong bits; };
int OnInit()
{
   int input_file=FileOpen("arithmetic-runtime-r1-input.bin",FILE_READ|FILE_BIN);
   if(input_file==INVALID_HANDLE) return INIT_FAILED;
   int magic=FileReadInteger(input_file,INT_VALUE),n=FileReadInteger(input_file,INT_VALUE);
   if(magic!=0x53554231 || n!=25) { FileClose(input_file);return INIT_FAILED; }
   int output_file=FileOpen("arithmetic-runtime-r1-output.bin",FILE_WRITE|FILE_BIN);
   if(output_file==INVALID_HANDLE) { FileClose(input_file);return INIT_FAILED; }
   FileWriteInteger(output_file,magic,INT_VALUE);FileWriteInteger(output_file,n,INT_VALUE);
   for(int i=0;i<n;i++)
   {
      DoubleBits left,right,ordinary,compound,direct;
      left.bits=(ulong)FileReadLong(input_file);right.bits=(ulong)FileReadLong(input_file);
      ordinary.value=P_Subtract(left.value,right.value);
      compound.value=P_SubtractCompound(left.value,right.value);
      direct.value=left.value-right.value;
      FileWriteLong(output_file,(long)ordinary.bits);FileWriteLong(output_file,(long)compound.bits);FileWriteLong(output_file,(long)direct.bits);
   }
   FileClose(input_file);FileClose(output_file);Print("SUBTRACTION_MEASURED:25");return INIT_SUCCEEDED;
}
void OnTick() { ExpertRemove(); }
