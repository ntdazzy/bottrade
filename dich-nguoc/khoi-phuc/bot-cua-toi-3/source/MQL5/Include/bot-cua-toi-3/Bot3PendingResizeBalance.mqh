// Native balance-change gate before volume preparation and pending-order resize.
#ifndef BOT3_PENDING_RESIZE_BALANCE_MQH
#define BOT3_PENDING_RESIZE_BALANCE_MQH
bool Bot3CheckResizeBalance(const double current,double &previous,const double change_percent)
{
   if(current==previous) return false;
   const double factor=change_percent/100.0+1.0;
   if(current>previous*factor)
   {
      return true;
   }
   if(previous/factor>current)
   {
      return true;
   }
   return false;
}
#endif
