Bạn phụ trách viết mã MQL5 theo đặc tả chức năng đã chốt bên dưới. Hãy triển khai đúng đặc tả; không tự tìm thuật toán hay thay đổi công thức. Chỉ ghi trong thư mục đề xuất được giao. Không sửa nguồn chính, chạy lệnh, dùng tác tử lồng hoặc sửa Git. Không cần đọc các bản phân tích lịch sử của dự án. Nếu thiếu chi tiết chức năng, ghi rõ điểm thiếu, không tự điền. Tệp mã phải đầy đủ, không hàm rỗng hoặc TODO. Codex sẽ biên dịch, đối chiếu và ghép.
Dùng Opus 5.5 max; Ultracode được yêu cầu. Cấu hình thực tế được kiểm qua nhật ký riêng.
Các kiểu sẵn có: Bot3ManagedPosition trong Bot3ManagementPrelude.mqh; Bot3PendingRequestState, Bot3TradeSendOptions, Bot3ModifyPosition từ các include có sẵn. Các giá trị position là bản cục bộ đã đọc trước đó, API không thay đổi open_price/tp/opened của chúng; các biến tick, unit và cài đặt là tham chiếu có thể thay đổi sau lời gọi API. Giữ các lần đọc trước/sau API đúng vị trí. Các trường dữ liệu độc lập, không trùng vùng nhớ. Dùng Bot3RoundPrice(value,(uint)digits), không NormalizeDouble.
Thư mục duy nhất được ghi: dich-nguoc/khoi-phuc/claude-thuc-hien/bot3-virtual-finish-flow-20261025-r1/. Ghi Bot3ManagementVirtualFinishFlow.mqh và SUMMARY.md nêu cách giữ thứ tự đọc/ghi, kiểu số và điểm còn thiếu; không nói đã biên dịch hoặc đã kiểm khi chưa chạy.
Viết Bot3ManagementVirtualFinishFlow.mqh, include Bot3ManagementVirtualFinish.mqh. Hàm:
bool Bot3FinishVirtualManagement(const bool buy,const string &symbol,
 const Bot3VirtualFinishSettings &settings,const double &unit,const double &gap,const double &freeze,
 const double selected_anchor,const double &copied_step,const Bot3ManagedPosition &position,
 MqlTick &tick,const double &levels[],const uint &strategy_index,
 double &current_level,double &current_take,bool &changed,int &counter,
 const double initial_stop,const double initial_take,const long ticket,
 Bot3VirtualStopState &table,Bot3PendingRequestState &state,
 Bot3TradeSendOptions &options,const ulong &deviation).
Các hàm sẵn có trong header include: Bot3AdvanceVirtualHighLow, Bot3AdvanceVirtualBreakEvenCounter, Bot3StoreVirtualLevels. Không viết lại các hàm đó.
1. Gọi Bot3AdvanceVirtualHighLow(buy,symbol,settings,unit,gap,freeze,position,tick,levels,strategy_index,current_level,changed).
2. Gọi Bot3AdvanceVirtualBreakEvenCounter(buy,symbol,settings,unit,gap,freeze,selected_anchor,copied_step,position,tick,current_level,changed,counter). Luôn gọi sau bước1; không skip chỉ vì changed true (bên trong hàm tự xử lý).
3. Đọc giá mới sau hai bước: hit=(buy ? current_level>=tick.bid : tick.ask>=current_level), so có thứ tự. Nếu hit: SymbolInfoTick(symbol,tick) một lần, bỏ bool trả; Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket) rồi return true. Không gọi đóng trực tiếp khác, không in, không hỏi khối lượng, không lưu bảng sau nhánh đóng.
4. Nếu không hit: Bot3StoreVirtualLevels(symbol,initial_stop,initial_take,current_level,current_take,(double)ticket,table); return false.
Không reset changed/counter, không tạo cờ tổng mới, không xử lý vòng vị thế, không thêm luật. Kiểu ticketlong épulonggiữbit; cached_ticket_number khi lưu là(double)ticket đã đổi trước đó. Chỉ số mảng hợp lệ là tiền đề đã có; không thêm kiểm mảng.

