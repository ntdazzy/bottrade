Viết duy nhất Bot1ManagementRealSlippage.mqh và SUMMARY.md trong thư mục đề xuất này. Opus5.5max, Ultracode được yêu cầu. Đây là hai chức năng MQL5 điều chỉnh dừng lỗ sau kiểm trượt giá. Codex đã chốt trình tự dưới đây. Chỉ đọc header nguồn để đúng kiểu/cách viết, không đọc EX5/mã máy/phân tích hoặc tự tìm thuật toán. Không sửa nguồn chính/Git/MT5/chạy lệnh/tạo tác tử. Codex kiểm, ghép, biên dịch và so.

Header guard và include Bot1ManagementPrelude.mqh, Bot1ManagementMessages.mqh. Hàmvoid Bot1AdvanceSlippageRealBuyStop và Bot1AdvanceSlippageRealSellStop, cùng tham số:
(const string &symbol,const double &unit,const int &enabled,
 const uchar passed_flag,const double reference,
 const double &trail,const double &start,const double &limit,
 const double &gap,const double &freeze,Bot1ManagedPosition &position,
 MqlTick &tick,bool &changed,Bot1PendingRequestState &state,
 Bot1TradeSendOptions &options,uint &error_count,const ulong ticket).
Các kiểu/helper ởbot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1. Dùng Bot1RoundPrice, Bot1ModifyPosition, Bot1PrintManagementError hiện có. Không viết lại helper. reference/passed_flag/ticket là giá trị đã chụp. reference nhận từcaller, không đổi thành position.open_price hoặc một mốc khác. Cácdouble& là tham chiếu có thể đổi sau dịch vụ; phần đã yêu cầu chụp thì dùng bản chụp.

Chungđầu: nếu enabled!=1 hoặc(passed_flag&1)!=1 hoặc!(0.0<trail) thìreturn, không đổi changed/sl.

MUA theo thứ tự:
1.quote=tick.bid TRƯỚC DIGITS1, rồi digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS), point=SymbolInfoDouble(symbol,SYMBOL_POINT).
2.gate=Bot1RoundPrice(trail*unit+(point+position.sl),digits1). Nếu !(gate<quote),return.
3.quote2=tick.bid TRƯỚC DIGITS2; lấy digits2, boundary=Bot1RoundPrice(start*unit+reference,digits2); nếu !(boundary<quote2),return.
4.nếu !(tick.bid<position.tp-freeze),return. Không thêm DIGITS ở đây.
5.lấy digits3, limit_price=Bot1RoundPrice(limit*unit+position.open_price,digits3); nếu !(position.sl<limit_price),return.
6.lấy digits4; SAU dịch vụ mới quote3=tick.bid; new_sl=Bot1RoundPrice(quote3-trail*unit,digits4). Ghi position.sl=new_sl TRƯỚC kiểm khoảng trống. Nếu !(new_sl<quote3-gap),return và giữsl mới/changed cũ.
7.Gọi Bot1ModifyPosition(state,options,ticket,position.sl,position.tp). True:Print("Slippage control active"). False:Bot1PrintManagementError("' when setting Slip TL.  Trying again!",error_count). SAU thông báo đặtchanged=true.

BÁN theo thứ tự:
1.quote=tick.ask TRƯỚC POINT; point=SymbolInfoDouble(symbol,SYMBOL_POINT); khôngDIGITS ở đầu. captured_unit=unit SAU POINT.
2.gate=(position.sl-point)-trail*captured_unit. Nếu !(quote<gate),return.
3.quote2=tick.ask; boundary=reference-start*captured_unit. Nếu !(quote2<boundary),return.
4.nếu !((freeze+position.tp)<quote2),return.
5.limit_price=position.open_price-captured_unit*limit. Nếu !(limit_price<position.sl),return.
6.lấy digits1; candidate=Bot1RoundPrice(trail*unit+tick.ask,digits1), dùngunit MỚI sau lời gọi, không dùngcaptured_unit. Nếu !(candidate<position.sl),return.
7.lấy digits2; SAU dịch vụ mới quote3=tick.ask; new_sl=Bot1RoundPrice(trail*unit+quote3,digits2). Ghi position.sl=new_sl TRƯỚC kiểm khoảng trống. Nếu !((quote3+gap)<new_sl),return và giữsl mới/changed cũ.
8.Gọi Modify nhưmua. True:Print("Slippage controle active") (giữ chữcontrole). False:gọi cùng helper lỗi và đúng hậu tố trên. SAU thông báo đặtchanged=true.

Mọi lần làm tròn dùng Bot1RoundPrice, không NormalizeDouble/epsilon. Giữ thứ tự toán hạng, dấu<, không thêm luật. position.sl là giá trị cục bộ được truyền xuyên các khối; cập nhật nó khi giá mới được tính dù cổng gap hỏng. Không nhầm nó với cập nhật dừng lỗ trên tài khoản. Không gọi đóng, không hỏi khối lượng, không làm mới tick, không đổiTP. Cờchanged cũ giữ nguyên trước bước sửa; sau cả hai kết quả sửa thìtrue khi thông báo hoàn tất. Nếu nền tảng dừng vì lỗi cấp phát thì không tự bắt hoặc mô phỏng tiếp. Mã đầy đủ/gọn/rõ; khôngTODO/hàm rỗng. SUMMARY nói đúng chưa chạy/biên dịch nếu chưa, không tuyên bố100%.
