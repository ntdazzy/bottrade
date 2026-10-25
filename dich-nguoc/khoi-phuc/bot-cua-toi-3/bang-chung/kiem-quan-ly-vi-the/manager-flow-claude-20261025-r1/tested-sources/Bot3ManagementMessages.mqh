// Candidate only: not compiled, not run, not compared with the original EX5.
// Management "TrailStop error" print; the caller passes the suffix and the error counter.
#ifndef BOT3_MANAGEMENT_MESSAGES_MQH
#define BOT3_MANAGEMENT_MESSAGES_MQH
#include "Bot3TradeErrors.mqh"

// Reads GetLastError once and never resets it; Bot3TradeErrorText increments error_count.
void Bot3PrintManagementError(const string &suffix,uint &error_count)
{
   int code=GetLastError();
   string result=Bot3TradeErrorText(code,error_count);
   string message="TrailStop error: '"+result+suffix;
   Print(message);
}
#endif
