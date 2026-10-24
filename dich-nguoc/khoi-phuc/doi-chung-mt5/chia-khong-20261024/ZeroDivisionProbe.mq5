#property strict
input double Numerator=7.0;
input double Denominator=0.0;
input bool IntegerDivision=false;
int OnStart()
{
   int h=FileOpen("zero-division-probe.bin",FILE_WRITE|FILE_BIN);
   FileWriteInteger(h,1);FileFlush(h);
   if(IntegerDivision)
   {
      int numerator=(int)Numerator,denominator=(int)Denominator;
      int value=numerator/denominator;
      FileWriteInteger(h,2);FileWriteInteger(h,value);
   }
   else
   {
      double value=Numerator/Denominator;
      FileWriteInteger(h,3);FileWriteDouble(h,value);
   }
   FileClose(h);return 0;
}
