// Only data initialization; never sends a request.
class NativeTradeLayout
{
public:
   MqlTradeRequest request;
   MqlTradeResult result;
   MqlTradeCheckResult check;
   uchar end_marker;
};
NativeTradeLayout layout_block;
#define layout_request layout_block.request
#define layout_result layout_block.result
#define layout_check layout_block.check
void SeedTradeLayout()
{
   layout_request.action=(ENUM_TRADE_REQUEST_ACTIONS)101;
   layout_request.magic=0x1122334455667788;
   layout_request.order=0x2132435465768798;
   layout_request.symbol="TRADE_LAYOUT_SYMBOL";
   layout_request.volume=1101.25;
   layout_request.price=1102.25;
   layout_request.stoplimit=1103.25;
   layout_request.sl=1104.25;
   layout_request.tp=1105.25;
   layout_request.deviation=0x31425364758697a8;
   layout_request.type=(ENUM_ORDER_TYPE)102;
   layout_request.type_filling=(ENUM_ORDER_TYPE_FILLING)103;
   layout_request.type_time=(ENUM_ORDER_TYPE_TIME)104;
   layout_request.expiration=(datetime)0x415263748596a7b8;
   layout_request.comment="TRADE_LAYOUT_COMMENT";
   layout_request.position=0x5162738495a6b7c8;
   layout_request.position_by=0x61728394a5b6c7d8;
   layout_result.retcode=201;
   layout_result.deal=0x1234567812345678;
   layout_result.order=0x2345678923456789;
   layout_result.volume=1201.25;
   layout_result.price=1202.25;
   layout_result.bid=1203.25;
   layout_result.ask=1204.25;
   layout_result.comment="TRADE_LAYOUT_RESULT";
   layout_result.request_id=202;
   layout_result.retcode_external=203;
   layout_check.retcode=301;
   layout_check.balance=1301.25;
   layout_check.equity=1302.25;
   layout_check.profit=1303.25;
   layout_check.margin=1304.25;
   layout_check.margin_free=1305.25;
   layout_check.margin_level=1306.25;
   layout_check.comment="TRADE_LAYOUT_CHECK";
   layout_block.end_marker=0xab;
}
