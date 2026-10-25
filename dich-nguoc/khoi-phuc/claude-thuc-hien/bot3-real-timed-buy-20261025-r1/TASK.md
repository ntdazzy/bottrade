Bạn phụ trách viết mã MQL5 theo đặc tả chức năng đã chốt bên dưới. Hãy triển khai đúng đặc tả; không tự tìm thuật toán hay thay đổi công thức. Chỉ ghi trong thư mục đề xuất được giao. Không sửa nguồn chính, chạy lệnh, dùng tác tử lồng hoặc sửa Git. Không cần đọc các bản phân tích lịch sử của dự án. Nếu thiếu chi tiết chức năng, ghi rõ điểm thiếu, không tự điền. Tệp mã phải đầy đủ, không hàm rỗng hoặc TODO. Codex sẽ biên dịch, đối chiếu và ghép.
Dùng Opus 5.5 max; Ultracode được yêu cầu. Cấu hình thực tế được kiểm qua nhật ký riêng.
Các kiểu sẵn có: Bot3ManagedPosition trong Bot3ManagementPrelude.mqh; Bot3PendingRequestState, Bot3TradeSendOptions, Bot3ModifyPosition từ các include có sẵn. Các giá trị position là bản cục bộ đã đọc trước đó, API không thay đổi open_price/tp/opened của chúng; các biến tick, unit và cài đặt là tham chiếu có thể thay đổi sau lời gọi API. Giữ các lần đọc trước/sau API đúng vị trí. Các trường dữ liệu độc lập, không trùng vùng nhớ. Dùng Bot3RoundPrice(value,(uint)digits), không NormalizeDouble.
Thư mục duy nhất được ghi: dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-real-timed-buy-20261025-r1/. Ghi Bot3TimedRealBuy.mqh và SUMMARY.md nêu cách giữ thứ tự đọc/ghi, kiểu số và điểm còn thiếu; không nói đã biên dịch hoặc đã kiểm khi chưa chạy.
Viết bool Bot3AdvanceTimedBuyStop(const string &symbol,const double &unit,const double &activation,
 const double &distance,const int &delay_seconds,const double &gap,const double &freeze,
 Bot3ManagedPosition &position,MqlTick &tick,Bot3PendingRequestState &state,
 Bot3TradeSendOptions &options,uint &error_count,const ulong ticket). Include Bot3ManagementPrelude.mqh và Bot3ManagementMessages.mqh.
Hành vi, theo đúng thứ tự:
1. Nếu !(0.0<activation) trả false. Gọi TimeCurrent() đúng một lần, ép sang long có dấu. Sau lời gọi đọc delay_seconds int32 và position.opened long. Tính mốc opened+(long)delay_seconds theo số 64 bit cuộn vòng; nếu now<mốc có dấu trả false.
2. Chụp quote=tick.bid TRƯỚC gọi SymbolInfoInteger(symbol,SYMBOL_DIGITS) lần 1. Lưu digits1 (uint). Gọi SymbolInfoDouble(symbol,SYMBOL_POINT).
3. Sau POINT mới đọc distance, unit để tính offset=distance*unit; gate=offset+(point+position.sl), sau đó gate=Bot3RoundPrice(gate,digits1). Chỉ tiếp khi gate<quote có thứ tự. Không tự đổi ngoặc thành (SL+point)+offset.
4. Đọc tick.bid và freeze mới. Chỉ tiếp khi tick.bid<position.tp-freeze.
5. Hỏi SYMBOL_DIGITS lần 2. SAU đó chụp quote2=tick.bid; đọc distance/unit mới, candidate=Bot3RoundPrice(quote2-distance*unit,digits2). Gán position.sl=candidate NGAY, kể cả khi điều kiện tiếp theo thất bại.
6. Đọc gap mới; chỉ tiếp nếu candidate<quote2-gap. Sai thì false và giữ position.sl vừa gán.
7. Gọi Bot3ModifyPosition(state,options,ticket,position.sl,position.tp). Dù bool sửa là false hay true, kết quả hàm này là true (true nghĩa đã đi tới yêu cầu sửa).
8. Nếu Modify trả false: gọi Bot3PrintManagementError("' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!",error_count). Không tự sửa error_count ngoài hàm báo lỗi. Nếu Modify true không báo.
Các so sánh số thực đều có thứ tự: NaN không làm cổng dương đạt. Không thêm kiểm hợp lệ số, không sửa tp, không đóng vị thế, không ghi bảng, không Stamp/Delay. Mọi trường hợp trước yêu cầu sửa trả false. long cuộn vòng có thể tính qua ulong rồi ép lại long; không đổi mốc sang double hoặc dùng phép trừ now-opened.

