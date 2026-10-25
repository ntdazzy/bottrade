Bạn phụ trách viết mã MQL5 theo đặc tả chức năng đã chốt bên dưới. Hãy triển khai đúng đặc tả; không tự tìm thuật toán hay thay đổi công thức. Chỉ ghi trong thư mục đề xuất được giao. Không sửa nguồn chính, chạy lệnh, dùng tác tử lồng hoặc sửa Git. Không cần đọc các bản phân tích lịch sử của dự án. Nếu thiếu chi tiết chức năng, ghi rõ điểm thiếu, không tự điền. Tệp mã phải đầy đủ, không hàm rỗng hoặc TODO. Codex sẽ biên dịch, đối chiếu và ghép.
Dùng Opus 5.5 max; Ultracode được yêu cầu. Cấu hình thực tế được kiểm qua nhật ký riêng.
Các kiểu sẵn có: Bot3ManagedPosition trong Bot3ManagementPrelude.mqh; Bot3PendingRequestState, Bot3TradeSendOptions, Bot3ModifyPosition từ các include có sẵn. Các giá trị position là bản cục bộ đã đọc trước đó, API không thay đổi open_price/tp/opened của chúng; các biến tick, unit và cài đặt là tham chiếu có thể thay đổi sau lời gọi API. Giữ các lần đọc trước/sau API đúng vị trí. Các trường dữ liệu độc lập, không trùng vùng nhớ. Dùng Bot3RoundPrice(value,(uint)digits), không NormalizeDouble.
Thư mục duy nhất được ghi: dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-real-timed-sell-20261025-r1/. Ghi Bot3TimedRealSell.mqh và SUMMARY.md nêu cách giữ thứ tự đọc/ghi, kiểu số và điểm còn thiếu; không nói đã biên dịch hoặc đã kiểm khi chưa chạy.
Viết bool Bot3AdvanceTimedSellStop(const string &symbol,const double &unit,const double &activation,
 const double &distance,const int &delay_seconds,const double &gap,const double &freeze,
 Bot3ManagedPosition &position,MqlTick &tick,Bot3PendingRequestState &state,
 Bot3TradeSendOptions &options,uint &error_count,const ulong ticket). Include Bot3ManagementPrelude.mqh và Bot3ManagementMessages.mqh.
Hành vi theo đúng thứ tự, phía bán CÓ cách đọc/làm tròn riêng:
1. Nếu !(0.0<activation) trả false. TimeCurrent() một lần ép long; sau đó đọc int32 delay_seconds và position.opened; mốc opened+(long)delay_seconds cuộn64bit, so có dấu; now<mốc thì false.
2. Chụp quote=tick.ask trước gọi SymbolInfoDouble(symbol,SYMBOL_POINT). Không hỏi digits tại bước này. Sau POINT tính offset=distance*unit; gate=(position.sl-point)-offset, KHÔNG làm tròn gate. Yêu cầu quote<gate.
3. Sau POINT đọc tick.ask/freeze mới, yêu cầu freeze+position.tp<tick.ask.
4. Hỏi SYMBOL_DIGITS lần1. Sau API tính candidate1=Bot3RoundPrice(distance*unit+tick.ask,digits1), distance/unit/ask đều đọc mới sau API. Chỉ tiếp nếu candidate1<position.sl. CHƯA gán SL ở bước này.
5. Hỏi SYMBOL_DIGITS lần2. Sau API đọc quote2=tick.ask, distance và unit; candidate2=Bot3RoundPrice(distance*unit+quote2,digits2). Nhân distance*unit trước cộng quote2, giữ thứ tự hai toán hạng. Gán position.sl=candidate2 NGAY.
6. Đọc gap mới; yêu cầu quote2+gap<candidate2. Sai thì false nhưng giữ SL đã gán.
7. Gọi Bot3ModifyPosition(state,options,ticket,position.sl,position.tp); bool sửa false hoặc true đều trả true từ hàm này.
8. Chỉ nếu Modify false: gọi Bot3PrintManagementError("' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!",error_count).
NaN làm điều kiện dương sai. Không thêm luật, không NormalizeDouble, không đổi tp, đóng vị thế hoặc ghi bảng. Các lần trả trước Modify là false. Giữ cộng thời gian cuộn64bit bằng ulong rồi long, không dùng double.

