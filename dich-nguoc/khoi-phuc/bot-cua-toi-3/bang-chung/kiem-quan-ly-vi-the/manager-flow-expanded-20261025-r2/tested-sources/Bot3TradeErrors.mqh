// Native error helper 0x3ee80; increments the counter before selection.
#ifndef BOT3_TRADE_ERRORS_MQH
#define BOT3_TRADE_ERRORS_MQH
string Bot3TradeErrorText(const int code,uint &error_count)
{
   error_count++;
   switch(code)
   {
      case 0:return "no error";
      case 1:return "no error";
      case 2:return "common error";
      case 3:return "invalid trade parameters";
      case 4:return "trade server is busy";
      case 5:return "old version of the client terminal";
      case 6:return "no connection with trade server";
      case 7:return "not enough rights";
      case 8:return "too frequent requests";
      case 9:return "malfunctional trade operation (never returned error)";
      case 64:return "account disabled";
      case 65:return "invalid account";
      case 128:return "trade timeout";
      case 129:return "invalid price";
      case 130:return "invalid stops";
      case 131:return "invalid trade volume";
      case 132:return "market is closed";
      case 133:return "trade is disabled";
      case 134:return "not enough money";
      case 135:return "price changed";
      case 136:return "off quotes";
      case 137:return "broker is busy (never returned error)";
      case 138:return "requote";
      case 139:return "order is locked";
      case 140:return "long positions only allowed";
      case 141:return "too many requests";
      case 145:return "modification denied because order too close to market";
      case 146:return "trade context is busy";
      case 147:return "expirations are denied by broker";
      case 148:return "amount of open and pending orders has reached the Exit_limit_";
      case 149:return "hedging is prohibited";
      case 150:return "prohibited by FIFO rules";
      case 4000:return "no error (never generated code)";
      case 4001:return "wrong function pointer";
      case 4002:return "array index is out of range";
      case 4003:return "no memory for function call stack";
      case 4004:return "recursive stack overflow";
      case 4005:return "not enough stack for parameter";
      case 4006:return "no memory for parameter string";
      case 4007:return "no memory for temp string";
      case 4008:return "not initialized string";
      case 4009:return "not initialized string in array";
      case 4010:return "no memory for array' string";
      case 4011:return "too long string";
      case 4012:return "remainder from zero divide";
      case 4013:return "zero divide";
      case 4014:return "unknown command";
      case 4015:return "wrong jump (never generated error)";
      case 4016:return "not initialized array";
      case 4017:return "dll calls are not allowed";
      case 4018:return "cannot load library";
      case 4019:return "cannot call function";
      case 4020:return "expert function calls are not allowed";
      case 4021:return "not enough memory for temp string returned from function";
      case 4022:return "system is busy (never generated error)";
      case 4050:return "invalid function parameters count";
      case 4051:return "invalid function parameter value";
      case 4052:return "string function internal error";
      case 4053:return "some array error";
      case 4054:return "incorrect series array using";
      case 4055:return "custom indicator error";
      case 4056:return "arrays are incompatible";
      case 4057:return "global variables processing error";
      case 4058:return "global variable not found";
      case 4059:return "function is not allowed in testing mode";
      case 4060:return "function is not confirmed";
      case 4061:return "send mail error";
      case 4062:return "string parameter expected";
      case 4063:return "integer parameter expected";
      case 4064:return "double parameter expected";
      case 4065:return "array as parameter expected";
      case 4066:return "requested history data in update state";
      case 4099:return "end of file";
      case 4100:return "some file error";
      case 4101:return "wrong file name";
      case 4102:return "too many opened files";
      case 4103:return "cannot open file";
      case 4104:return "incompatible access to a file";
      case 4105:return "no order selected";
      case 4106:return "unknown symbol";
      case 4107:return "invalid price parameter for trade function";
      case 4108:return "invalid ticket";
      case 4109:return "trade is not allowed in the expert properties";
      case 4110:return "longs are not allowed in the expert properties";
      case 4111:return "shorts are not allowed in the expert properties";
      case 4200:return "object is already exist";
      case 4201:return "unknown object property";
      case 4202:return "object is not exist";
      case 4203:return "unknown object type";
      case 4204:return "no object name";
      case 4205:return "object coordinates error";
      case 4206:return "no specified subwindow";
   }
   return "unknown error "+(string)code;
}
#endif
