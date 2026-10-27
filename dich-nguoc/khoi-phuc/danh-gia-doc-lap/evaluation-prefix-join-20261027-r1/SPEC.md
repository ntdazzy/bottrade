# Nối đầu đánh giá với quản lý và phần tạo lệnh

Đọc lại đúng thân evaluator B1 `18aa0..1ef9c`, B3 `20ef0..2a1bc`.
SHA thân lần lượt45d532...7cbd và6bead1...920; hai EX5 chuẩn giữ nguyên.

## Dữ liệu đầu đánh giá

Chỉ số đầu vào là bản chụp tại stack B1+bc/B3+b0; KHÔNG phải ô chỉ số
hiện hành678f4/74934. Thân đầu đánh giá không ghi hai ô global này.
Không đồng nhất hai chỉ số khi ghép. Căn cứ hàm state trong hai bộ kiểm
`tests/check-evaluation-prelude.py` và các lệnh gốc được đọc lại.

Thêm `BotNPrepareEvaluationFields` với toàn bộ đối số cũ, thêm cuối:
`const string &symbol,MqlTick &tick,double &spread,
MqlDateTime &current_calendar,bool &reported_sessions`.
Trong thân thay inputs.symbol bằng symbol, state.tick/spread/current_calendar
bằng các đối số tương ứng. B3 gọi BeginEvaluationFields mô tả dưới đây.
Đặt reported_sessions=false ở đầu hàm; true trong đúng nhánh gọi báo phiên.
Các trường index, server_time, calendar, selected_symbol, session_flag giữ
nguyên. Wrapper cũ chỉ chuyển inputs.symbol và các state.field cũ vào,
dùng biến bool cục bộ khởi tạo false. Không chép nguyên state.

B3 thêm `Bot3BeginEvaluationFields`, đối số cũ cộng `const string &symbol`
ở cuối; chỉ thay inputs.symbol trong thân. Wrapper cũ chuyển inputs.symbol.
Đây là để đầu đánh giá đọc thẳng execution.symbol và ghi execution.tick.

## Bổ sung mức dừng/chốt

Thêm hàm trả int `BotNFillEvaluationStopsFields(const string &symbol,
const uchar &enabled,const int &magic,const double &stop_distance,
const double &target_distance,const double &unit,
BotNPendingRequestState &trade,BotNTradeSendOptions &options)`.
Thân giữ nguyên thuật toán cũ, thay inputs.field bằng tham chiếu tương ứng.
enabled==0 trả0, không gọi PositionsTotal. Còn lại đọc total một lần,
duyệt như cũ rồi trả đúng total ban đầu (kể cả âm). Wrapper void cũ chuyển
inputs.field vào và bỏ kết quả. Tổng này phục vụ cờ ngữ cảnh bot1, không
đọc PositionsTotal thêm lần nữa.

## Bộ điều phối quản lý

Thêm Fields cho Bot1RoutePositionManagement và Bot3ManageOnBarChange:
giữ đối số cũ, thêm cuối16tham chiếu theo đúng ManagerFields đã kiểm:
`copied_step,cache,volumes,current_index,error_count,last_ticket,tick,
symbol,magic,unit,stop_distance,take_distance,gap,freeze,high_low_enabled,step_reference,
management_enabled,emergency_offset`.
Ở B1 tên chỉ số chụp cũ là strategy_index; đối số ngoài dùng current_index
để không trùng. Hai đối số cuối mới thêm vào ManagerFields để nối enabled
62428/6d520 với pending_enabled và emergency_offset62560/6d650 với spread.
Chỉ các lượt manager nhận current_index, chọn bảng thời gian
vẫn dùng strategy_index chụp. Các lần đếm/đọc symbol/magic/last_ticket nhận
đối số ngoài. Thay gọi ManagePositions thành ManagePositionsFields và
chuyển đủ18đối số theo thứ tự. B3 đã có symbol; không thêm symbol lần nữa,
chỉ thêm17đối số còn lại, chuyển symbol cũ vào vị trí thứ8 của ManagerFields.
Wrapper cũ chuyển toàn bộ trường cũ, không đổi chữ ký.

Giữ thứ tự mua rồi bán, kể cả mua trảtrue. B1 giữ nguyên nhánh licence0,
thông báo và quyết định dừng; không đặt cờ hoặc bỏ kiểm quyền dùng.

## Hàm đánh giá ghép

Thêm BotNEvaluationPrefixSettings gồm inputs của prelude, settings của
manager và timeframe quản lý; B1 thêm license_valid/tick_management/
bar_override/incoming_changed, B3 thêm caller_flag. PrefixState gồm
prelude, manager và mảng thời gian quản lý8/9ô. Các core field trùng địa chỉ
trong manager/input là chỗ tương thích cũ, hàm ghép luôn chuyển tham chiếu
canonical từ execution/restore/unit/queue/loop_state/level_settings/volumes.

BotNEvaluate bắt đầu như EvaluateActiveFlow nhưng cached_calendar có thể ghi,
bỏ đối số evaluation_blocked đã tính từ ngoài, thêm PrefixSettings/State cuối.

1. PreludeFields: symbol=execution.symbol,tick=execution.tick,spread=spread,
   current_calendar=cached_calendar; nhận reported_sessions, giữ chỉ số chụp.
2. B3 dọn lệnh chờ bằng caller_flag và queue.results; B1 không thêm nhánh này.
3. FillEvaluationStopsFields: enabled=loop_settings.submission.omit_real_sl_tp,
   magic=execution.strategy_magic,stop/target=restore.sl_distance/tp_distance,
   unit=unit. B1 giữ tổng ban đầu để tính ngữ cảnh.
4. B1 tính Bot1BarFirstZeroTicketChanged từ đúng cờ trên, tổng ban đầu,
   prelude.calendar.day_of_week,reported_sessions,prefix.incoming_changed.
   Sau đó RouterFields; B3 gọi ManageOnBarChangeFields. Nếu quản lý trảtrue
   thì trả BOTN_LEVEL_STOP trước bảng thông tin.
5. Gọi EvaluateActiveFlow với evaluation_blocked = session_flag!=0 (B1),
   hoặc caller_flag!=0 || session_flag!=0 (B3). Trả nguyên kết quả.

Core ManagerFields nối: copied_step=loop_state.active_step,cache=queue.results,
volumes, current_index,error_count=queue.error_count,last_ticket=execution.last_ticket,
tick=execution.tick,symbol=execution.symbol,magic=execution.strategy_magic,unit,
stop/target=restore.sl_distance/tp_distance,gap=execution.threshold_a,
freeze=execution.gap,high_low_enabled=level_settings.aux_older,
step_reference=loop_settings.step_reference,management_enabled=pending_enabled,
emergency_offset=spread. Mức mua dùng lower, mức bán dùng upper.

Ngữ cảnh incoming_changed của B1 còn cần nối từ hàm gọi ngoài để thành EA;
phép kiểm hàm đánh giá cấp rõ byte này. Không tự gán0 hoặc70 cho mọi đường.
Thống kê lịch sử/hiển thị cuối hàm và khởi tạo/thoát chưa nằm trong lượt này.


## Nối thống kê lịch sử và dọn bảng theo giờ

Sau `BotNEvaluate` giữ nguyên quyết định; chỉ khi quyết định không phải
`BOTN_LEVEL_STOP` mới gọi `BotNUpdateClosedStatusPanel`. Nếu giờ trong
`cached_calendar` khác `display.last_hour`, ghi giờ mới rồi gọi
`BotNCleanPendingResults(queue.results,execution.last_ticket)`. Bộ kiểm
`evaluation-display-20261028-r1` đối chiếu 61/61 ca bot 1 và 57/57 ca bot 3
qua thân native, gồm cả thứ tự lời gọi và trạng thái cuối.
