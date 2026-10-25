Viết Bot1ManagementRealDistance.mqh và SUMMARY.md vào đúng thư mục đề xuất này. Claude Opus5.5max, Ultracode được yêu cầu. Codex đã chốt mô tả chức năng dưới đây. Đây là phần dời dừng lỗ thật của quản lý vị thế MQL5. Chỉ đọc headers nguồn để dùng đúng giao diện; không đọc EX5/mã máy/phân tích, không tự tìm thuật toán. Không sửa nguồn chính/Git/MT5/chạy lệnh/tạo tác tử. Codex kiểm, ghép và đối chiếu.

Hai hàm bool Bot1AdvanceDistanceBuyStop và Bot1AdvanceDistanceSellStop nhận cùng giao diện:
(const string &symbol,const double &unit,const double &trail,
 const double &step,const double &start,const double &limit,
 const double anchor,const double &gap,const double &freeze,
 Bot1ManagedPosition &position,MqlTick &tick,const double &volumes[],
 const uint &strategy_index,bool &changed,Bot1PendingRequestState &state,
 Bot1TradeSendOptions &options,const ulong &deviation,uint &error_count,const ulong ticket)
Include Bot1ManagementPrelude.mqh và Bot1ManagementMessages.mqh. Dùng Bot1RoundPrice và các helper có sẵn, không viết lại chúng. Đường dẫn headers bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1. symbol/unit/trail/step/start/limit/gap/freeze/index và volumes là tham chiếu, có thể đổi sau lời gọi dịch vụ; anchor là bản chụp giá trị. position chứa sl,tp,open_price,volume như header. Không tự lấy anchor khác.

MUA, theo đúng thứ tự:
- Nếu !(0.0<trail), return false. double quote=tick.bid TRƯỚC DIGITS1.
- digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS); point=SymbolInfoDouble(symbol,SYMBOL_POINT).
- gate=Bot1RoundPrice((trail+step)*unit+(point+position.sl),digits1). Nếu !(gate<quote), false.
- double quote2=tick.bid TRƯỚC DIGITS2. Lấy digits2, rồi boundary=Bot1RoundPrice(start*unit+anchor,digits2). Nếu !(boundary<quote2), false.
- Nếu !(tick.bid<position.tp-freeze), false. KHÔNG thêm lần DIGITS ở đây.
- Lấy digits3; cap=Bot1RoundPrice(limit*unit+position.open_price,digits3). Nếu !(position.sl<cap), false.
- Lấy digits4; SAU lời gọi mới lấy quote3=tick.bid, new_sl=Bot1RoundPrice(quote3-trail*unit,digits4).
- Ghi position.sl=new_sl TRƯỚC kiểm khoảng trống. Nếu !(new_sl<quote3-gap), false, vẫn giữ sl mới và changed cũ.
- Đi phần CHUNG SAU SỬA.

BÁN, theo đúng thứ tự:
- Nếu !(0.0<trail), false. double quote=tick.ask TRƯỚC POINT; point=SymbolInfoDouble(symbol,SYMBOL_POINT). Không DIGITS ở đầu.
- Chụp captured_unit=unit SAU POINT; gate=(position.sl-point)-(trail+step)*captured_unit. Nếu !(quote<gate), false.
- quote=tick.ask; boundary=anchor-start*captured_unit. Nếu !(quote<boundary), false.
- Nếu !((freeze+position.tp)<quote), false.
- cap=position.open_price-captured_unit*limit. Nếu !(cap<position.sl), false.
- Lấy digits1; candidate=Bot1RoundPrice(trail*unit+tick.ask,digits1). Nếu !(candidate<position.sl), false. unit này đọc mới, không dùng captured_unit.
- Lấy digits2; quote=tick.ask SAU lời gọi; candidate=Bot1RoundPrice(trail*unit+quote,digits2), ghi position.sl=candidate TRƯỚC kiểm khoảng trống.
- Nếu !((quote+gap)<candidate), false, giữ sl mới và changed cũ.
- Đi phần CHUNG SAU SỬA.

CHUNG SAU SỬA:
- Gọi bool ok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp).
- Nếu false: Bot1PrintManagementError("' when setting trailing Exit_stop_ loss.  Trying again!",error_count), rồi changed=true, return false NGAY. Không đọc volumes, không hỏi khối lượng tối thiểu, không kiểm đóng trong nhánh lỗi.
- Nếu true: zero_volume=Bot1RoundPrice(volumes[strategy_index]*0.0,2), SAU đó changed=true. Giữ phép nhân thật vì Inf/NaN phải thành NaN, không gán hằng0.
- Nếu !(zero_volume<position.volume), false.
- minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN), nếu !(minimum<=zero_volume), false.
- Gọi Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket) với giá hiện có; KHÔNG SymbolInfoTick, không dùng kết quả đóng; return true vì đã tới lời gọi đó.

Giữ nguyên thứ tự các toán hạng và dấu so. Các điều kiện ghi dạng !(a<b) để NaN bị loại như mô tả. Không epsilon/NormalizeDouble thay helper/kiểm tra thêm/khôi phục sl. Giữ changed ban đầu trên mọi lối thoát trước phần sửa. Không đổi TP. Mã rõ, ngắn, không TODO/hàm rỗng. SUMMARY ghi đúng chưa biên dịch/chạy, không gọi100%.
