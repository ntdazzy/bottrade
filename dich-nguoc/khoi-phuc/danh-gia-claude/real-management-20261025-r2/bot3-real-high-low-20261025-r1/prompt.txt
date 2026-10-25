Viết duy nhất Bot3ManagementRealHighLow.mqh và SUMMARY.md trong thư mục này. Viết theo chức năng đầy đủ dưới đây, không tự tìm thuật toán/đọc tài liệu phân tích lịch sử. Không sửa nguồn chính/Git/chạy lệnh/tác tử khác. Codex kiểm, ghép, chạy. Opus5.5 max; Ultracode yêu cầu. Không tự claim đã chạy.
Include Bot3ManagementPrelude.mqh và Bot3ManagementMessages.mqh. Dùng Bot3RoundPrice, không NormalizeDouble. Biến cài đặt/tick/index/mảng là tham chiếu có thể đổi sauAPI; position.sl do hàmghi, open_price/tp là cục bộ không bị API đổi. Không trùng vùng nhớ, index hợp lệ0..8.
Hai hàm void Bot3AdvanceHighLowRealBuyStop/SellStop, giao diện chung:
(const string &symbol,const int &enabled,const uchar eligible_flag,const int &gap_count,const double &unit,const uchar &before_open,const uchar &shift_setting,const double &gap,const double &freeze,const double &levels[],const uint &strategy_index,Bot3ManagedPosition &position,MqlTick &tick,bool &changed,Bot3PendingRequestState &state,Bot3TradeSendOptions &options,uint &error_count,const ulong ticket).
Chung: nếu enabled<=0 hoặc eligible_flag==0 thoát. eligible_flag là byte đã có của bên gọi, không tạo/lý giải thêm. Mọi phépso dương cóthứtự, NaN làmfalse. Dùngif(!(a<b))return. Mọi đường trướcModify giữchangedcũ; nếu đãgánSL mà cổngcuối sai vẫn giữSLmới.
BUY:
1 h1=levels[strategy_index] TRƯỚC DIGITS1; hỏiDIGITS1. SauAPI chụp x=gap+position.sl TRƯỚC POINT1. HỏiPOINT1; first=Bot3RoundPrice(x+point1,digits1); cần first<h1. Không đọcgap lại sauPOINT1.
2 SauPOINT1 đọc h2=levels[strategy_index] mới; q=tick.bid mới; count=(double)gap_count códấu; u=unit mới; cần h2<q-count*u. Nếu !(h2<position.open_price) và (before_open&1)!=0 thì thoát. H2 giữqua2APItiếp.
3 DIGITS2; sauAPI shift=shift_setting!=0 ?10.0:0.0; chụp v=(tick.bid-shift*unit)-gap TRƯỚC POINT2. HỏiPOINT2; boundary=Bot3RoundPrice(v-point2,digits2), cần h2<boundary. Không đọcunit/gap/bid lại cho boundary sauPOINT2.
4 đọcbid/freeze mới: cần tick.bid<position.tp-freeze.
5 DIGITS3; sauAPI new_sl=Bot3RoundPrice(levels[strategy_index],digits3); gánposition.sl ngay. Sauđóđọc bid/gap mới: cần new_sl<tick.bid-gap; sai vẫn giữSLmới.
6 bool ok=Bot3ModifyPosition(state,options,ticket,position.sl,position.tp); changed=true NGAY sauModify,trướcif(!ok). false mới gọi Bot3PrintHighLowError(error_count).
SELL:
1 h1=levels[strategy_index],x=position.sl-gap TRƯỚC POINT1. HỏiPOINT1; cần h1<x-point1. KHÔNGDIGITS/làmtrònởcổngđầu.
2 sauPOINT1 chụp u=unit,h2=levels[strategy_index],q=tick.ask; cần (double)gap_count*u+q<h2. Nếu !(position.open_price<h2) và before_openbit0 thìthoát.
3 shift=shift_setting!=0?10.0:0.0; chụp v=(q+u*shift)+gap TRƯỚC POINT2; HỏiPOINT2; cần v+point2<h2. Dùngu,q,h2đãchụp vàđúngthứtựnhânu*shift. KhôngDIGITS ởcổngnày.
4 sauPOINT2 đọc mới: freeze+position.tp<tick.ask.
5 DIGITS1; sauAPI first=Bot3RoundPrice(levels[strategy_index],digits1), cần first<position.sl cũ.
6 DIGITS2; sauAPI new_sl=Bot3RoundPrice(levels[strategy_index],digits2); gánposition.sl ngay. Sauđóđọcask/gapmới: cần tick.ask+gap<new_sl; sai giữSLmới.
7 Modify→changed=true→falsemớiBot3PrintHighLowError nhưbuy.

Định nghĩa void Bot3PrintHighLowError(uint &counter) trướchaihàm: intcode=(int)GetLastError() mộtlần; string message=Bot3TradeErrorText(code,counter) (helper cósẵncounter++); Print("error: '"+message+"' when modifying stoploss") đúngmộtlần. KhôngdùngBot3PrintManagementError vìprefix khác. Khôngresetlỗi/đếmthêm. Được đọcheaderBot3ManagementMessages.mqh/Bot3TradeErrors.mqh đểđúnggiao diện.
KhôngSymbolInfoTick,khôngđổiTP,khôngđóng/khốilượng,khôngghi bảng/Stamp. Khôngthêm luật hoặc sửa thứtự. SUMMARY nêuAPI/đọcghi/cờ/chưachạy.
