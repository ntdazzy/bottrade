// Event-window selection from native RVA 0x3?10 (bot 1 RVA 0x7310).
#ifndef BOT1_NEWS_BLOCK_MQH
#define BOT1_NEWS_BLOCK_MQH
struct Bot1NewsBlockState
{
   long block_time;
};

long Bot1NewsMinutes32(const int minutes) { return (long)(int)((uint)minutes*60); }

bool Bot1SelectNewsBlock(const long now,const bool nfp_enabled,const long nfp_time,const int nfp_minutes,
                         const bool ir_enabled,const long ir_time,const int ir_minutes,
                         const bool cpi_enabled,const long cpi_time,const int cpi_minutes,
                         Bot1NewsBlockState &out)
{
   out.block_time=0;
   if(nfp_enabled && nfp_time>0 && nfp_time+Bot1NewsMinutes32(nfp_minutes)>now)
      out.block_time=nfp_time;
   if(ir_enabled && ir_time>0 && ir_time+Bot1NewsMinutes32(ir_minutes)>now &&
      (out.block_time==0 || ir_time<out.block_time))
      out.block_time=ir_time;
   if(cpi_enabled && cpi_time>0 && cpi_time+Bot1NewsMinutes32(cpi_minutes)>now &&
      (out.block_time==0 || cpi_time<out.block_time))
      out.block_time=cpi_time;
   return out.block_time>0;
}
#endif
