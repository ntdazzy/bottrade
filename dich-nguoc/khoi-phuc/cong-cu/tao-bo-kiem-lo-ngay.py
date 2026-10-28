"""Sinh script MQL5 kiểm tra giới hạn lỗ trong ngày cho bot 1 và bot 3.

Chỉ đọc BotNNewsFridayCheck.mq5 hiện có rồi tạo BotNDailyLossCheck.mq5.
Không chạy biên dịch hay MT5; lệnh dùng: python tao-bo-kiem-lo-ngay.py BOT.
"""
from pathlib import Path
import argparse

ROOT = Path(__file__).resolve().parents[1]
MAX = 256


def replace_once(source: str, old: str, new: str, label: str) -> str:
    count = source.count(old)
    if count != 1:
        raise RuntimeError(f"{label}: cần đúng 1 lần, thấy {count}")
    return source.replace(old, new, 1)


def build(bot: int) -> Path:
    if bot not in (1, 3):
        raise ValueError("BOT phải là 1 hoặc 3")
    source_dir = ROOT / f"bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}"
    source_path = source_dir / f"Bot{bot}NewsFridayCheck.mq5"
    target = source_dir / f"Bot{bot}DailyLossCheck.mq5"
    source = source_path.read_text(encoding="utf-8")

    source = replace_once(source, f"int MockInfo(const ENUM_MQL_INFO_INTEGER property);", f"""int MockInfo(const ENUM_MQL_INFO_INTEGER property);
int MockBars(const string symbol,const ENUM_TIMEFRAMES period);
double MockAccountInfoDouble(const ENUM_ACCOUNT_INFO_DOUBLE property);
bool MockHistorySelect(const datetime from,const datetime to);
int MockHistoryDealsTotal();
ulong MockHistoryDealGetTicket(const int index);
long MockHistoryDealGetInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property);
double MockHistoryDealGetDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property);
datetime MockITime(const string symbol,const ENUM_TIMEFRAMES period,const int shift);""", "prototypes")
    source = replace_once(source, "#define MQLInfoInteger MockInfo", """#define MQLInfoInteger MockInfo
#define Bars MockBars
#define AccountInfoDouble MockAccountInfoDouble
#define HistorySelect MockHistorySelect
#define HistoryDealsTotal MockHistoryDealsTotal
#define HistoryDealGetTicket MockHistoryDealGetTicket
#define HistoryDealGetInteger MockHistoryDealGetInteger
#define HistoryDealGetDouble MockHistoryDealGetDouble
#define iTime MockITime""", "defines")
    source = replace_once(source, "#undef MQLInfoInteger", """#undef MQLInfoInteger
#undef Bars
#undef AccountInfoDouble
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetDouble
#undef iTime""", "undefines")
    source = source.replace(
        f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}NewsFridayFlow.mqh"',
        f'''#include "../../Include/bot-cua-toi-{bot}/Bot{bot}NewsFridayFlow.mqh"
#include "../../Include/bot-cua-toi-{bot}/Bot{bot}DailyLossGuard.mqh"''',
        1,
    )
    if source.count(f'Bot{bot}DailyLossGuard.mqh') != 1:
        raise RuntimeError("daily guard include không được chèn đúng")

    source = replace_once(
        source,
        f"long Extra[18],FridayData[12];Bot{bot}FridaySettings Friday;uchar FridayClosed;",
        f"""long Extra[18],FridayData[12];Bot{bot}FridaySettings Friday;uchar FridayClosed;
double Percent;Bot{bot}DailyLossState Daily;
long BarsReplies[{MAX}],EquityReplies[{MAX}],BalanceReplies[{MAX}],TimeReplies[{MAX}];
int BarsReplyCount,EquityReplyCount,BalanceReplyCount,TimeReplyCount;
int BarsReplyPos,EquityReplyPos,BalanceReplyPos,TimeReplyPos;
long DealTicket[{MAX}],DealTime[{MAX}],DealEntry[{MAX}],DealProfit[{MAX}],DealCommission[{MAX}],DealSwap[{MAX}];int DealCount,SelectedDeal;
long EffectApi[{MAX}],EffectN[{MAX}],EffectField[{MAX}],EffectValue[{MAX}];int EffectCount,ApiN[64];""",
        "state declarations",
    )
    friday_fields = "Word(Friday.enabled);Word((ulong)(long)Friday.hour);Word(FridayClosed);"
    if bot == 3:
        friday_fields += "Word(Friday.delete_pending);Word(Friday.close_positions);"
    snapshot = f"   {friday_fields}\n   Word(Bits(Percent));Word((ulong)(long)Daily.bars);Word(Daily.blocked);Word(Bits(Daily.peak));"
    source = replace_once(
        source,
        "   Word(Friday.enabled);Word((ulong)(long)Friday.hour);Word(FridayClosed);" + ("Word(Friday.delete_pending);Word(Friday.close_positions);" if bot == 3 else "") + "\n   if(RecordFinal) Word((ulong)NewsBlocked);",
        snapshot + "\n   if(RecordFinal) Word((ulong)NewsBlocked);",
        "snapshot",
    )
    source = replace_once(
        source,
        "void Begin()\n{",
        """int ReplyInt(const long &items[],const int count,int &pos)
{
   if(count<=0) return 0;
   const int index=pos<count ? pos : count-1;pos++;return (int)items[index];
}
ulong ReplyBits(const long &items[],const int count,int &pos)
{
   if(count<=0) return 0;
   const int index=pos<count ? pos : count-1;pos++;return (ulong)items[index];
}
int DealIndex(const ulong ticket)
{
   if(SelectedDeal>=0 && SelectedDeal<DealCount && (ticket==0 || (ulong)DealTicket[SelectedDeal]==ticket)) return SelectedDeal;
   return -1;
}
void DailyEffect(const int api)
{
   const int n=(api>=0 && api<64) ? ++ApiN[api] : 0;
   for(int i=0;i<EffectCount;i++)
   {
      if((int)EffectApi[i]!=api || (int)EffectN[i]!=n) continue;
      if(EffectField[i]==1) { NumberBits bits;bits.bits=(ulong)EffectValue[i];Percent=bits.value; }
      else if(EffectField[i]==2) { NumberBits bits;bits.bits=(ulong)EffectValue[i];Daily.peak=bits.value; }
      else if(EffectField[i]==3) Daily.blocked=(uchar)EffectValue[i];
      else if(EffectField[i]==4) Daily.bars=(int)EffectValue[i];
   }
}
void Begin()
{""",
        "helpers",
    )
    # Existing service effects are kept; the daily effect is applied after their mutations below.
    service_tail = "   if(mode==5 && api==15 && !Mutated) { Friday.delete_pending=0;Mutated=true; }\n" if bot == 3 else ""
    service_tail += "}\nvoid MockPrint(const string value)"
    source = replace_once(source, service_tail, service_tail.replace("}\nvoid MockPrint(const string value)", "   DailyEffect(api);\n}\nvoid MockPrint(const string value)"), "service effect order")
    source = source.replace(
        "void MockPrint(const string a,const string b) { Begin();End(10,2,0,0,0,a,b); }",
        "void MockPrint(const string a,const string b) { Begin();DailyEffect(10);End(10,2,0,0,0,a,b); }",
        1,
    )
    api_block = r'''int MockBars(const string symbol,const ENUM_TIMEFRAMES period)
{ Begin();const int value=ReplyInt(BarsReplies,BarsReplyCount,BarsReplyPos);DailyEffect(32);End(32,(ulong)period,(ulong)(long)value,0,0,symbol);return value; }
double MockAccountInfoDouble(const ENUM_ACCOUNT_INFO_DOUBLE property)
{ Begin();const ulong bits=property==ACCOUNT_EQUITY ? ReplyBits(EquityReplies,EquityReplyCount,EquityReplyPos) : ReplyBits(BalanceReplies,BalanceReplyCount,BalanceReplyPos);NumberBits n;n.bits=bits;DailyEffect(33);End(33,(ulong)property,bits,0,0);return n.value; }
bool MockHistorySelect(const datetime from,const datetime to)
{ Begin();const bool value=ReplyInt(BarsReplies,0,BarsReplyPos)!=0;DailyEffect(34);End(34,(ulong)from,(ulong)to,(ulong)value,0);return value; }
int MockHistoryDealsTotal()
{ Begin();const int value=(int)HistoryDealsTotalReply;DailyEffect(35);End(35,(ulong)(long)value,0,0,0);return value; }
ulong MockHistoryDealGetTicket(const int index)
{ Begin();SelectedDeal=index>=0 && index<DealCount ? index : -1;const ulong value=SelectedDeal>=0 ? (ulong)DealTicket[SelectedDeal] : 0;DailyEffect(36);End(36,(ulong)(long)index,value,0,0);return value; }
long MockHistoryDealGetInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{ Begin();const int i=DealIndex(ticket);long value=0;if(i>=0) value=property==DEAL_TIME ? DealTime[i] : property==DEAL_ENTRY ? DealEntry[i] : 0;DailyEffect(37);End(37,ticket,(ulong)property,(ulong)value,0);return value; }
double MockHistoryDealGetDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property)
{ Begin();const int i=DealIndex(ticket);ulong bits=0;if(i>=0) bits=(ulong)(property==DEAL_PROFIT ? DealProfit[i] : property==DEAL_COMMISSION ? DealCommission[i] : property==DEAL_SWAP ? DealSwap[i] : 0);NumberBits n;n.bits=bits;DailyEffect(39);End(39,ticket,(ulong)property,bits,0);return n.value; }
datetime MockITime(const string symbol,const ENUM_TIMEFRAMES period,const int shift)
{ Begin();const long value=(long)ReplyBits(TimeReplies,TimeReplyCount,TimeReplyPos);DailyEffect(38);End(38,(ulong)period,(ulong)(long)shift,(ulong)value,0,symbol);return (datetime)value; }
'''
    source = replace_once(source, "bool MockStopped() { return false; }", api_block + "bool MockStopped() { return false; }", "daily APIs")
    source = replace_once(source, "{ Begin();const bool value=ReplyInt(BarsReplies,0,BarsReplyPos)!=0;DailyEffect(34);", "{ Begin();const bool value=HistorySelectReply!=0;DailyEffect(34);", "history select reply")
    source = replace_once(source, "long BarsReplies[", "long HistorySelectReply,HistoryDealsTotalReply;long BarsReplies[", "history select state")
    source = replace_once(source, "      for(int i=0;i<12;i++) FridayData[i]=FileReadLong(file);", """      for(int i=0;i<12;i++) FridayData[i]=FileReadLong(file);
      NumberBits percent_bits;percent_bits.bits=(ulong)FileReadLong(file);Percent=percent_bits.value;
      NumberBits peak_bits;peak_bits.bits=(ulong)FileReadLong(file);Daily.peak=peak_bits.value;Daily.bars=(int)FileReadLong(file);Daily.blocked=(uchar)FileReadLong(file);
      BarsReplyCount=FileReadInteger(file);if(BarsReplyCount<0 || BarsReplyCount>256) { FileClose(file);return 8; }for(int i=0;i<BarsReplyCount;i++) BarsReplies[i]=FileReadLong(file);BarsReplyPos=0;
      EquityReplyCount=FileReadInteger(file);if(EquityReplyCount<0 || EquityReplyCount>256) { FileClose(file);return 8; }for(int i=0;i<EquityReplyCount;i++) EquityReplies[i]=FileReadLong(file);EquityReplyPos=0;
      BalanceReplyCount=FileReadInteger(file);if(BalanceReplyCount<0 || BalanceReplyCount>256) { FileClose(file);return 8; }for(int i=0;i<BalanceReplyCount;i++) BalanceReplies[i]=FileReadLong(file);BalanceReplyPos=0;
      TimeReplyCount=FileReadInteger(file);if(TimeReplyCount<0 || TimeReplyCount>256) { FileClose(file);return 8; }for(int i=0;i<TimeReplyCount;i++) TimeReplies[i]=FileReadLong(file);TimeReplyPos=0;
      HistorySelectReply=FileReadInteger(file);HistoryDealsTotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>256) { FileClose(file);return 8; }SelectedDeal=-1;
      for(int i=0;i<DealCount;i++) { DealTicket[i]=FileReadLong(file);DealTime[i]=FileReadLong(file);DealEntry[i]=FileReadLong(file);DealProfit[i]=FileReadLong(file);DealCommission[i]=FileReadLong(file);DealSwap[i]=FileReadLong(file); }
      EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>256) { FileClose(file);return 8; }for(int i=0;i<EffectCount;i++) { EffectApi[i]=FileReadLong(file);EffectN[i]=FileReadLong(file);EffectField[i]=FileReadLong(file);EffectValue[i]=FileReadLong(file); }ArrayInitialize(ApiN,0);""", "input format")
    source = replace_once(source, "      ZeroMemory(Friday);Friday.enabled=", "      ZeroMemory(Friday);Friday.enabled=", "daily initialization")
    source = replace_once(source, f"NewsBlocked=Bot{bot}ProcessNewsAndFriday(Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection,Friday,FridayClosed);", f"NewsBlocked=Bot{bot}ProcessDailyLoss(Percent,Daily,Execution);", "daily call")
    source = replace_once(source, f'folder="bot{bot}-news-friday\\\\"+CheckRun+"\\\\";', f'folder="bot{bot}-daily-loss\\\\"+CheckRun+"\\\\";', "folder")
    source = replace_once(source, f'Print("NEWS_FRIDAY_CASE:",id);', f'Print("DAILY_LOSS_CASE:",id);', "case label")
    target.write_text("\n".join(line.rstrip() for line in source.splitlines()) + "\n", encoding="utf-8", newline="\n")
    return target


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("bot", type=int, choices=(1, 3))
    args = parser.parse_args()
    print(build(args.bot))


if __name__ == "__main__":
    main()
