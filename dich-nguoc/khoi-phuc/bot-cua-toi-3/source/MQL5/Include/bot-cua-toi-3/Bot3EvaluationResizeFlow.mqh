// Evaluator balance gate -> complete volume function -> pending delete/open/send.
#ifndef BOT3_EVALUATION_RESIZE_FLOW_MQH
#define BOT3_EVALUATION_RESIZE_FLOW_MQH
#include "Bot3PendingResizeBalance.mqh"
#include "Bot3VolumeRuntime.mqh"
#include "Bot3EvaluationPendingResize.mqh"
bool Bot3RefreshEvaluationPending(const uchar &volume_enabled,const double &stop_distance,
                             const Bot3VolumeSettings &settings,Bot3VolumeState &volume_state,
                             const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                             long &last_check,long &last_deal_time,
                             const double &weight_denominator,const uchar &enabled[],
                             const int &strategy_magic,const uchar &virtual_expiration,
                             const string &symbol,const string &suffix,const double &change_percent,
                             double &previous,const uint &strategy_index,double &volumes[],
                             ulong &last_ticket,double &results[][2],
                             Bot3PendingRequestState &trade,Bot3TradeSendOptions &options)
{
   if(!Bot3CheckResizeBalance(volume_state.effective_balance,previous,change_percent)) return false;
   Bot3PrepareVolumeRuntime(stop_distance,volume_enabled!=0 ? 100 : 0,symbol,suffix,settings,volume_state,
                              reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,
                              weight_denominator,enabled,strategy_index,volumes);
   Bot3ResizeEvaluationPending(strategy_magic,virtual_expiration,symbol,change_percent,
                                volumes,strategy_index,last_ticket,results,trade,options);
   return true;
}
#endif
