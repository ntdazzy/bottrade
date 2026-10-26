// Runtime calibration only; no trading or market queries.
#property strict
#property script_show_inputs
input int CheckMode=0;
input double Denominator=0.0;
double CheckedDivide(const double numerator,const double denominator)
{
   if(denominator==0.0)
   {
      const int divisor=(int)denominator;
      const int fault=1/divisor;
      return (double)fault;
   }
   return numerator/denominator;
}
void OnStart()
{
   Print("DIVISION_BEGIN:",CheckMode);
   double value=0.0;
   if(CheckMode==0) value=1.0/Denominator;
   if(CheckMode==1) value=Denominator/Denominator;
   if(CheckMode==2) { const int divisor=(int)Denominator;value=(double)(1/divisor); }
   if(CheckMode==3) value=CheckedDivide(1.0,Denominator);
   Print("DIVISION_RETURNED:",CheckMode,":",value);
}
