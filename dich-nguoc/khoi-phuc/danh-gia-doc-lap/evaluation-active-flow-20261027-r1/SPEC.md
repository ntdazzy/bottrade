# Ghép sau quản lý vị thế đến hết vòng tạo lệnh

Chốt bằng thân evaluator gốc B1 `18aa0..1ef9c` SHA
`45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd`,
B3 `20ef0..2a1bc` SHA
`6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.
Phạm vi ghép bắt đầu B1 `1a620`, B3 `22851`; kết thúc trước bảng/thống kê
B1 `1e94f`, B3 `29c88`. Hai thân quản lý trước đó trả kết quả không chặn.

## Cổng trước lọc tin

`BotNAllowsOrderEvaluation(const uchar &day_switch_filter,const MqlDateTime &calendar,uchar &notice)`:

1. MQLInfoInteger mã6. Nếu kết quả==0 mới đọc MQLInfoInteger mã4.
   Nếu cả hai==0: nếu notice==0 thì Print đúng một chuỗi
   `Market closed... waiting to continue`; sau đó notice=1, trả false.
2. Nếu day_switch_filter!=0 && calendar.hour==0 && calendar.min<=4:
   nếu notice==0, chuyển số int5 thành string, Print một chuỗi ghép:
   `DAYSWITCH -> Market might be closed... waiting ` + số5 +
   ` minutes before setting order..`; notice=1, trả false.
3. Còn lại trả true, không sửa notice. NFP ngay sau đó tự đặt notice=0.

Các phép so với0/1 giữ nguyên; không thay bằng cách hiểu tên enum.
Cổng B1 `1b343..1b44f`, nhánh ngoài `1b8a7..1b8ef`, `1ea3e..1ec60`;
B3 `23620..2372b`, `238b0..238f8`, `238fd..23bbc`.
Chuỗi đã đọc từ descriptor B1 `54688/54710`, B3 `5cde8/5ce70`;
hậu tố31ký tự ở buffer B1 `54720+12`, B3 `5ce80+12`.
Không có lời gọi thời gian hay lịch trong chính cổng này. Các đoạn sau
`1b44f`/`2372b` là nhánh NFP đã có nguồn riêng.

## Dùng chung dữ liệu bảng tin

Thêm hàm `BotNUpdateOpenStatusPanelFields` dựa trên thân bảng đã kiểm:
thay đối số `const BotNNewsWindows &windows` bằng sáu tham chiếu:
`const uchar &nfp_enabled,const int &nfp_after,const uchar &interest_enabled,
const int &interest_after,const uchar &cpi_enabled,const int &cpi_after`.
Thân gọi `BotNUpdateNewsSelectionFields` với events tương ứng, không chép
windows vào biến mới. Giữ `BotNUpdateOpenStatusPanel` có giao diện cũ,
thân chỉ chuyển windows.field sang hàm Fields; không đổi hành vi đã kiểm.

## Hàm ghép BotNEvaluateActiveFlow

Giữ toàn bộ tham số tham chiếu và thứ tự của `BotNEvaluateTradeFlow`.
Thêm ở cuối các tham số: `const uchar &panel_show,const uchar &panel_tester`,
B1 thêm `const int &panel_mode,const double &panel_trade_risk,const int &panel_balance_step`,
B3 thêm `const double &panel_manual_lots`;
sau đó `const bool evaluation_blocked,const uchar &day_switch_filter,
const double &balance_change_percent,double &previous_balance`.

Thứ tự thân:

1. Gọi PanelFields với các giá trị sống: seed=execution.magic_base,
   symbol=execution.symbol, balance=volume_state.effective_balance,
   B1 first_volume=volumes[0]; strategy_risk=volume_settings.strategy_risk;
   B3 mode=volume_state.mode (uint), frequency=volume_settings.frequency,
   allowed_dd=volume_settings.max_total_dd. Ba trường B3 này là cùng địa chỉ
   với dữ liệu khối lượng, không truyền thêm bản sao riêng cho bảng.
   cờ/phút tin lấy thẳng nfp_settings.enabled/after_minutes,
   interest_settings.enabled/after_minutes, cpi_settings.enabled/after_minutes.
   selection/events/last_ticket là đối tượng chung, không sao chép.
2. Nếu evaluation_blocked thì trả BOTN_LEVEL_STOP. B1 từ byte frame+c0;
   B3 từ OR của cờ đầu vào DL (frame+88 trước tái dùng) và phiên đóng
   (frame+f8). Thân quản lý đã chặn trước điểm đầu không thuộc phạm vi.
3. Gọi nguyên `BotNRefreshEvaluationPending` và bỏ kết quả bool:
   volume_enabled=loop_settings.volume_enabled, stop_distance=restore.sl_distance,
   settings/state/keys/thời gian/rút tiền dùng đúng đối tượng volume;
   B3 có weight_denominator/enabled; strategy_magic=execution.strategy_magic,
   virtual_expiration=restore.virtual_expiration, symbol=execution.symbol,
   suffix, change_percent=balance_change_percent, previous=previous_balance,
   strategy_index=current_index, volumes, last_ticket=execution.last_ticket,
   results=queue.results, trade=execution.trade, options=execution.options.
4. Gọi cổng trên với cached_calendar và nfp.initialization_notice.
   Trả STOP khi cổng không cho phép.
5. Trả nguyên kết quả `BotNEvaluateTradeFlow`, chuyển nguyên mọi đối tượng.

Thêm hai header `BotNEvaluationAvailability.mqh` và `BotNEvaluationActiveFlow.mqh`;
không hàm rỗng, không gọi EX5 gốc trong nguồn, không tạo trạng thái thay thế.

## Điểm nối gốc

| Dữ liệu thêm | B1 | B3 |
|---|---|---|
| panel_show / panel_tester | 6a528 / 6a530 | 1d6f38 / 1d6f40 |
| panel_mode | 6a748 | 6d630 |
| panel_trade_risk / panel_balance_step | 6a750 / 6a768 | không dùng |
| panel_frequency / manual_lots / allowed_dd | không dùng | 6d21c / 1d7138 / 1d7140 |
| day_switch_filter | 62568 | 6d658 |
| change_percent / previous_balance | 62528 / 67480 | 6d618 / 744c0 |

Các phép so modeB3 là so32bit; kiểu `uint &` dùng chung trực tiếp với
`Bot3VolumeState.mode`. Bot1 mode của bảng ở6a748 tách với mode khối lượng
ở62540; không được gộp hai địa chỉ đó.

B3 slot frame+88: `20f51` ghi byteDL, `212ff` đọc để dọn lệnh,
`22851` đọc cờ chặn; `22977` ghi lại qword từR14 và từ đó là ô tạm/chỉ số.
Không xem cùng một ô stack là một biến sống xuyên toàn hàm.

Kiểm chạy nguyên các thân bảng→vốn→khối lượng→sửa/xóa/gửi→cổng→tin→tạo lệnh
trong cùng bộ nhớ, không đặt lại trạng thái giữa các phần. Chưa gồm đầu evaluator,
khởi tạo, bảng lịch sử, ảnh giao diện hoặc toàn EA.
