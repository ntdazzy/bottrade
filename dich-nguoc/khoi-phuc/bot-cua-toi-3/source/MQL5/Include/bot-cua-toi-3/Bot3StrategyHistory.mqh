#ifndef BOT3_STRATEGY_HISTORY_MQH
#define BOT3_STRATEGY_HISTORY_MQH
#include "Bot3HistorySort.mqh"

struct Bot3StrategyHistoryCache
{
   int total;
   int count;
   ulong positions[];
   long magics[];
};

// Preserve ADDSD's left NaN sign and payload when both operands are NaNs.
double Bot3HistorySum(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left+right;
}

// Full native 0x2a1c0..0x2a7ff; the dispatcher supplies a valid strategy index.
double Bot3StrategyClosedProfit(const uchar &show_tester,const string &symbol,const int &magic,
                                const uint &strategy,int &closed_trades[],Bot3StrategyHistoryCache &cache)
{
   if(MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6)==1 && show_tester==0) return 0.0;
   closed_trades[strategy]=0;
   if(!HistorySelect((datetime)0,(datetime)0x7fffffff)) return 0.0;
   const int total=HistoryDealsTotal();
   if(total!=cache.total)
   {
      cache.count=0;
      cache.total=total;
      ArrayResize(cache.positions,total,0);
      ArrayResize(cache.magics,total,0);
      for(int i=0;i<total;i++)
      {
         const ulong ticket=HistoryDealGetTicket(i);
         if(ticket!=0 && ((uint)HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)3)&0xfffffffe)==0 &&
            (int)HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)4)==0)
         {
            const ulong position=(ulong)HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)12);
            cache.positions[cache.count]=position;
            const long owner=HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)11);
            cache.magics[cache.count]=owner;
            cache.count=(int)((uint)cache.count+1);
         }
      }
      if(cache.count>1) Bot3HistorySort(cache.positions,cache.magics,0,cache.count-1);
   }
   double result=0.0;
   const int last=(int)((uint)HistoryDealsTotal()-1);
   for(int i=last;i>=0;i--)
   {
      const ulong ticket=HistoryDealGetTicket(i);
      if(ticket==0 || ((uint)HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)3)&0xfffffffe)!=0) continue;
      const string deal_symbol=HistoryDealGetString(ticket,(ENUM_DEAL_PROPERTY_STRING)0);
      if(deal_symbol!=symbol) continue;
      const ulong position=(ulong)HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)12);
      long owner=HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)11);
      int left=0,right=(int)((uint)cache.count-1);
      while(left<=right)
      {
         const int middle=(int)((uint)left+(uint)right)/2;
         const ulong key=cache.positions[middle];
         if(key==position) { owner=cache.magics[middle];break; }
         if(position<=key) right=middle-1;
         else left=middle+1;
      }
      if(owner!=(long)magic) continue;
      if(((uint)HistoryDealGetInteger(ticket,(ENUM_DEAL_PROPERTY_INTEGER)4)&0xfffffffd)==1)
         closed_trades[strategy]=(int)((uint)closed_trades[strategy]+1);
      result=Bot3HistorySum(result,HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)9));
      result=Bot3HistorySum(result,HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)7));
      result=Bot3HistorySum(result,HistoryDealGetDouble(ticket,(ENUM_DEAL_PROPERTY_DOUBLE)8));
   }
   return result;
}
#endif
