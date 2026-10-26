# Viết khối điều phối quản lý vị thế MQL5 bot 1

Viết `Bot1ManagementRouter.mqh` và `SUMMARY.md` trong CHÍNH thư mục đề xuất này. Codex đã phân tích và chốt chức năng dưới đây; bạn triển khai theo mô tả, không tự tìm thuật toán. Chỉ đọc các header MQL5 hiện hành trong `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1` để dùng đúng kiểu và giao diện. Có thể đọc `Bot3ManagementBarGate.mqh` về cách include, không suy quy tắc bot1 từ bot3. Không đọc EX5/mã máy/thư mục phân tích. Không sửa nguồn chính, chạy lệnh, Git hoặc MT5. Không tạo tác tử. Yêu cầu Opus5.5 max, ultracode; Codex kiểm cấu hình thực tế riêng. Nếu không ghi được thì trả đầy đủ nội dung, không đổi thư mục ghi.

Ngữ cảnh: các hàm quản lý vị thế MQL5 đã có. Khối này nối chúng vào chương trình gọi và giữ nguyên một cờ cấp phép do bên gọi quản lý. Không viết hay thay cách kiểm cấp phép; không đặt cờ đó thành hợp lệ, không bỏ nhánh bảo vệ. Không tạo EA hoàn chỉnh, hàm rỗng hoặc quy tắc khác.

Include `Bot1PositionManagement.mqh` với header guard. Dùng đúng các struct hiện hành. Hai hàm:

```mql5
int Bot1CountManagementPositions(const bool buy,const string &symbol,
                                 const int &magic,ulong &last_ticket);
bool Bot1RoutePositionManagement(const uchar &license_valid,
                                const uchar &tick_management,const uchar &bar_override,
                                const int &timeframe,const uint strategy_index,
                                long &last_times[],
                                const Bot1PositionManagementSettings &settings,
                                Bot1PositionManagementState &shared,
                                const double &buy_levels[],const double &sell_levels[],
                                Bot1PendingRequestState &requests,
                                Bot1TradeSendOptions &options,const ulong &deviation);
```

`strategy_index` là giá trị đã chụp của bên gọi, hợp lệ0..7; last_times có8ô, các levels đúng chiều và đủ8ô. Không dùng shared.strategy_index để chọn ô last_times. Không thêm kiểm kích thước hay tự đổi kiểu/chặn giá trị. Các tham chiếu cài đặt/trạng thái còn lại phải đọc mới sau mỗi dịch vụ, không sao chép cả cấu trúc hay chụp magic/symbol một lần.

## Hàm đếm vị thế

1. Tạo biến chuỗi cục bộ giữ tên mã của vị thế. count=0; gọi PositionsTotal() đúng một lần đầu. Nếu kết quả<1, trả0, không gọi PositionGetTicket.
2. Nếu có vị thế: index=0, xử lý trước rồi tăng index và gọi PositionsTotal() MỚI sau mỗi vòng, tiếp tục nếu index<kết quả mới. Duyệt tăng, không duyệt ngược, không chụp tổng cho cả vòng, không gọi Total lần thứ hai trước vé đầu.
3. Mỗi vòng: shared last_ticket=PositionGetTicket(index). Giá trị0 bỏ qua các truy vấn khác của vị thế đó. Vẫn tăng index/gọi Total ở cuối vòng.
4. Vé khác0: gọi PositionGetInteger(POSITION_MAGIC). So toàn bộ long64 với `(long)magic` đọc sau dịch vụ, gồm kéo dấu của int32. Không ép số nhận được về int32. Không bằng thì bỏ qua.
5. BUY: gọi PositionGetInteger(POSITION_TYPE) trước. Chỉ nếu long nhận được==0 mới gọi PositionGetString(POSITION_SYMBOL), ghi vào chuỗi cục bộ và so với symbol hiện tại; bằng thì count++.
6. SELL: gọi PositionGetString(POSITION_SYMBOL) trước, ghi chuỗi cục bộ và so với symbol hiện tại. Chỉ nếu bằng mới gọi PositionGetInteger(POSITION_TYPE); long nhận được==1 thì count++.
7. Không đọc giá/khối lượng/chọn vé lần nữa, không thay trạng thái khác. Chuỗi cục bộ ra khỏi phạm vi trước khi hàm đếm trả kết quả; hàm điều phối chỉ gọi manager SAU hàm đếm đã trả về. Giữ khác biệt thứ tự truy vấn mua/bán.

## Hàm điều phối

1. Đọc license_valid. Nếu byte==0: `Print("Licence not valid!");` rồi trảtrue. Không gọi Total/iTime/manager. Cờ khác0 cho phép đi tiếp; không sửa cờ. true ở đây chỉ báo bên gọi dừng phần còn lại của lượt.
2. Chọn nhánh nến mới nếu tick_management==0 HOẶC bar_override!=0 HOẶC PositionsTotal()<1. Đánh giá tuần tự có dừng sớm: khi cờ thứ nhất/chứng thứ hai đã chọn nhánh thì không gọi Total; chỉ gọi Total chọn nhánh nếu hai cờ cho phép nhánh từng lần nhận giá.
3. Nhánh nến mới:
   - Chụp `const ENUM_TIMEFRAMES frame=(ENUM_TIMEFRAMES)timeframe` trước; sau đó chụp `const long previous=last_times[strategy_index]` trước dịch vụ.
   - Gọi iTime(settings.symbol,frame,1) một lần. Nếu bằng previous thì trảfalse. Không dùng <=, không coi0 là lỗi và không ghi last_times khi bằng.
   - Khi khác: gọi iTime lần thứ hai với settings.symbol và timeframe ĐỌC MỚI sau lần thứ nhất. Ghi kết quả LẦN THỨ HAI vào last_times[strategy_index], không dùng kết quả đầu.
   - Gọi Bot1ManagePositions(true,settings,shared,buy_levels,requests,options,deviation), lưu bool.
   - LUÔN gọi Bot1ManagePositions(false,settings,shared,sell_levels,requests,options,deviation) sau BUY dù BUY trảtrue; dùng cùng tham chiếu đã được BUY thay đổi. Không thêm đếm/lọc vị thế ở nhánh nến mới.
   - Trả OR hai kết quả chỉ SAU khi gọi đủ cả hai hàm.
4. Nhánh từng lần nhận giá (hai cờ cho phép và Total chọn nhánh>0):
   - Đầu tiên gọi Bot1CountManagementPositions(true,settings.symbol,settings.magic,shared.last_ticket). Hàm này gọi Total riêng, không dùng kết quả Total chọn nhánh.
   - buy_changed=false; nếu count>0 mới gọi Bot1ManagePositions(true,...buy_levels...) và lưu bool. Không gọi nếu count<=0.
   - LUÔN tiếp tục đếm SELL bằng Bot1CountManagementPositions(false,settings.symbol,settings.magic,shared.last_ticket), dù BUY đã trảtrue. SELL đọc danh sách vị thế/trạng thái sau BUY, gọi Total riêng.
   - sell_changed=false; chỉ nếu count SELL>0 thì gọi Bot1ManagePositions(false,...sell_levels...) và lưu bool.
   - Trả buy_changed||sell_changed sau cả hai nhánh. Không gọi iTime, không ghi last_times trong nhánh này.
5. Không gọi phần tiếp theo của chương trình chính, không dọn cache/bảng dừng, không đặt lại last_ticket. false để bên gọi tiếp tục, true để bên gọi dừng phần còn lại của lượt. Không nhầm đây là chỉ kết quả gửi lệnh hoặc chỉ kết quả một manager.

Mã gọn, có khoảng trắng và tên dễ đọc, không TODO/luật bổ sung. SUMMARY nêu tệp đã viết và chưa biên dịch/chưa đối chiếu nếu chưa làm. Codex tự biên dịch, so mã gốc và ghép sau khi kiểm.
