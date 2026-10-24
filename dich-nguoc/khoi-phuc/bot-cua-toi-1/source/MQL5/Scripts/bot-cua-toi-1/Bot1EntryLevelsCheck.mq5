// Reads supplied prices/orders and checks components. Never sends orders.
#property script_show_inputs false
input string CheckRun="";
double prices[],confirm_prices[];
ulong order_tickets[];
long order_magics[],order_types[];
double order_prices[];
string order_symbols[];
int selected,search_tf,check_digits,calls;
ulong call_hash;
union EntryCheckBits { double d; ulong u; };
ulong ValueBits(const double value) { EntryCheckBits b; b.d=value; return b.u; }
void MixWord(const ulong value)
{
   for(int k=0;k<8;k++) { call_hash^=(value>>(8*k))&0xff; call_hash*=(ulong)0x100000001b3; }
}
void Trace(const int api,const long first,const long second,const ulong value)
{
   MixWord((ulong)api); MixWord((ulong)first); MixWord((ulong)second); MixWord(value); calls++;
}
ulong TextHash(const string value)
{
   ulong hash=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      uint ch=StringGetCharacter(value,i);
      hash^=ch&0xff; hash*=(ulong)0x100000001b3;
      hash^=(ch>>8)&0xff; hash*=(ulong)0x100000001b3;
   }
   return hash;
}
double PriceAt(const int tf,const int shift)
{
   if(tf==search_tf) return shift>=0 && shift<ArraySize(prices) ? prices[shift] : 0.0;
   return shift>=0 && shift<ArraySize(confirm_prices) ? confirm_prices[shift] : 0.0;
}
double MockHigh(const string s,const ENUM_TIMEFRAMES tf,const int shift) { double v=PriceAt((int)tf,shift); Trace(1,shift,(int)tf,ValueBits(v)); return v; }
double MockLow(const string s,const ENUM_TIMEFRAMES tf,const int shift) { double v=PriceAt((int)tf,shift); Trace(2,shift,(int)tf,ValueBits(v)); return v; }
long MockSymbolInteger(const string s,const ENUM_SYMBOL_INFO_INTEGER property) { Trace(3,(long)property,0,(ulong)(long)check_digits); return check_digits; }
int MockOrdersTotal() { int n=ArraySize(order_tickets); Trace(4,0,0,(ulong)n); return n; }
ulong MockOrderTicket(const int index)
{
   ulong ticket=0;
   if(index>=0 && index<ArraySize(order_tickets)) { selected=index; ticket=order_tickets[index]; }
   Trace(5,index,0,ticket); return ticket;
}
long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
   long value=property==ORDER_MAGIC ? order_magics[selected] : order_types[selected];
   Trace(6,(long)property,0,(ulong)value); return value;
}
string MockOrderString(const ENUM_ORDER_PROPERTY_STRING property)
{
   string value=order_symbols[selected]; Trace(7,(long)property,0,TextHash(value)); return value;
}
double MockOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property)
{
   double value=order_prices[selected]; Trace(8,(long)property,0,ValueBits(value)); return value;
}
#define iHigh MockHigh
#define iLow MockLow
#define SymbolInfoInteger MockSymbolInteger
#define OrdersTotal MockOrdersTotal
#define OrderGetTicket MockOrderTicket
#define OrderGetInteger MockOrderInteger
#define OrderGetString MockOrderString
#define OrderGetDouble MockOrderDouble
#include "../../Include/bot-cua-toi-1/Bot1EntryLevels.mqh"
#include "../../Include/bot-cua-toi-1/Bot1EntryProfiles.mqh"

string ReadText(const int h) { int n=FileReadInteger(h); return n>0 ? FileReadString(h,n) : ""; }
void ReadPrices(const int h,double &data[]) { int n=FileReadInteger(h); ArrayResize(data,n); for(int i=0;i<n;i++) data[i]=FileReadDouble(h); }
int OnStart()
{
   string folder="bot1-entry-levels\\"+CheckRun+"\\";
   if(CheckRun=="") { Print("CheckRun is required"); return 1; }
   int profiles=FileOpen(folder+"profiles.bin",FILE_WRITE|FILE_BIN);
   if(profiles==INVALID_HANDLE) return 1;
   FileWriteInteger(profiles,0x50524631);FileWriteInteger(profiles,1);FileWriteInteger(profiles,8);
   for(int index=0;index<8;index++)
   {
      Bot1EntryProfile profile;
      if(!Bot1LoadEntryProfile(index,profile)) { FileClose(profiles); return 1; }
      FileWriteInteger(profiles,index);FileWriteInteger(profiles,profile.confirmation_frame);
      FileWriteInteger(profiles,profile.hour1_flag);
      FileWriteInteger(profiles,profile.older_width);FileWriteInteger(profiles,profile.recent_width);
      FileWriteInteger(profiles,profile.last_shift);FileWriteDouble(profiles,profile.gap_points);
   }
   FileClose(profiles);
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) { Print("Missing check data: ",GetLastError()); return 1; }
   int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x454e5431 || version!=1) { FileClose(h); return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(h); return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   int enums[]={ORDER_MAGIC,ORDER_TYPE,ORDER_SYMBOL,ORDER_PRICE_OPEN,ORDER_TYPE_BUY_STOP,ORDER_TYPE_SELL_STOP,SYMBOL_DIGITS};
   FileWriteInteger(output,ArraySize(enums));for(int e=0;e<ArraySize(enums);e++) FileWriteInteger(output,enums[e]);
   for(int c=0;c<count;c++)
   {
      int id=FileReadInteger(h),kind=FileReadInteger(h),buy=FileReadInteger(h);search_tf=FileReadInteger(h);
      int confirm_tf=FileReadInteger(h),older=FileReadInteger(h),recent=FileReadInteger(h),last=FileReadInteger(h);
      check_digits=FileReadInteger(h);int strategy_magic=FileReadInteger(h);ulong ticket=(ulong)FileReadLong(h);
      double quote=FileReadDouble(h),gap=FileReadDouble(h),unit=FileReadDouble(h),buy_offset=FileReadDouble(h);
      double sell_offset=FileReadDouble(h),radius=FileReadDouble(h),level=FileReadDouble(h);
      string symbol=ReadText(h);ReadPrices(h,prices);ReadPrices(h,confirm_prices);
      int orders=FileReadInteger(h);ArrayResize(order_tickets,orders);ArrayResize(order_magics,orders);
      ArrayResize(order_types,orders);ArrayResize(order_prices,orders);ArrayResize(order_symbols,orders);
      for(int i=0;i<orders;i++)
      {
         order_tickets[i]=(ulong)FileReadLong(h);order_magics[i]=FileReadLong(h);order_types[i]=FileReadInteger(h);
         order_prices[i]=FileReadDouble(h);order_symbols[i]=ReadText(h);
      }
      calls=0;call_hash=(ulong)0xcbf29ce484222325;selected=-1;ulong result;
      if(kind==0) result=(ulong)Bot1NearbyPending(buy!=0,level,symbol,strategy_magic,buy_offset,sell_offset,unit,radius,ticket);
      else result=ValueBits(Bot1EntryLevel(buy!=0,symbol,(ENUM_TIMEFRAMES)search_tf,(ENUM_TIMEFRAMES)confirm_tf,
                       older,recent,last,quote,gap,unit,strategy_magic,buy_offset,sell_offset,radius,ticket));
      FileWriteInteger(output,id);FileWriteLong(output,(long)result);FileWriteLong(output,(long)ticket);
      FileWriteInteger(output,calls);FileWriteLong(output,(long)call_hash);
   }
   FileClose(h);FileClose(output);Print("Bot1EntryLevelsCheck: ",count," cases written");
   return 0;
}
