// Event-window selection from native RVA 0x7c30.
#ifndef BOT3_NEWS_BLOCK_MQH
#define BOT3_NEWS_BLOCK_MQH
struct Bot3NewsBlockState
{
   long block_time;
};

bool Bot3SelectNewsBlock(const long now,const bool nfp_enabled,const long nfp_time,const int nfp_minutes,
                         const bool ir_enabled,const long ir_time,const int ir_minutes,
                         const bool cpi_enabled,const long cpi_time,const int cpi_minutes,
                         Bot3NewsBlockState &out)
{
   out.block_time=0;
   if(nfp_enabled && nfp_time>0 && nfp_time+(long)nfp_minutes*60>now)
      out.block_time=nfp_time;
   if(ir_enabled && ir_time>0 && ir_time+(long)ir_minutes*60>now &&
      (out.block_time==0 || ir_time<out.block_time))
      out.block_time=ir_time;
   if(cpi_enabled && cpi_time>0 && cpi_time+(long)cpi_minutes*60>now &&
      (out.block_time==0 || cpi_time<out.block_time))
      out.block_time=cpi_time;
   return out.block_time>0;
}
#endif
