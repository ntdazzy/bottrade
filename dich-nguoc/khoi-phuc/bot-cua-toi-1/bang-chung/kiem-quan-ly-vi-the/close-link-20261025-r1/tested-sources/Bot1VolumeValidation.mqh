// Volume min/max/step validator from native RVA 0x3bfe0.
#ifndef BOT1_VOLUME_VALIDATION_MQH
#define BOT1_VOLUME_VALIDATION_MQH

bool Bot1ValidateVolume(const string symbol,const double volume)
{
   double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   if(minimum>volume)
   {
      Print("Volume is less than the minimal allowed SYMBOL_VOLUME_MIN="+(string)minimum);
      return false;
   }
   double maximum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MAX);
   if(volume>maximum)
   {
      Print("Volume is greater than the maximal allowed SYMBOL_VOLUME_MAX="+(string)maximum);
      return false;
   }
   double step=SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP);
   // This MT5 build allows floating division by zero inside MathRound.
   // Integer division preserves the original fatal error before any message.
   if(step==0.0)
   {
      int dividend=(int)volume,divisor=(int)step;
      return (dividend/divisor)!=0;
   }
   int multiple=(int)MathRound(volume/step);
   double difference=MathAbs(multiple*step-volume);
   if(difference>0.0000001)
   {
      Print("Volume is not a multiple of the minimal step SYMBOL_VOLUME_STEP="+(string)step);
      return false;
   }
   return true;
}

#endif
