# SUMMARY — bot1-main-router-20261026-r1

## Tệp đã viết

- `Bot1ManagementRouter.mqh` (thư mục này): guard `BOT1_MANAGEMENT_ROUTER_MQH`,
  include `Bot1PositionManagement.mqh`, đúng hai hàm theo `TASK.md`:
  - `Bot1CountManagementPositions`: dòng 9–49.
  - `Bot1RoutePositionManagement`: dòng 54–103.
- `SUMMARY.md` (tệp này).

Không thêm hàm, kiểm kích thước, chặn giá trị, đổi kiểu hay luật nào khác.
Không viết hoặc thay cách kiểm cấp phép: `license_valid` là `const uchar&`, chỉ được đọc;
nhánh `Print("Licence not valid!")` + trả `true` giữ nguyên.

## Ánh xạ mô tả → mã (tự rà lại mã, chưa biên dịch)

| Mục TASK | Dòng |
|---|---|
| Đếm 1: chuỗi cục bộ `position_symbol` → `count=0` → `PositionsTotal()` lần đầu; `<1` trả `0`, không gọi `PositionGetTicket` | 12–15 |
| Đếm 2: `do/while` tăng từ 0; vé đầu đọc trước lần Total thứ hai; cuối vòng `index++` rồi gọi Total mới, tiếp tục khi `index<total` | 16–19, 43–47 |
| Đếm 3: `last_ticket=PositionGetTicket(index)` ghi vào tham chiếu chung; vé 0 bỏ các truy vấn khác nhưng vẫn tăng index/gọi Total | 19–21, 43–45 |
| Đếm 4: `PositionGetInteger(POSITION_MAGIC)` giữ trong `long`, so với `(long)magic` đọc sau lời gọi; không ép số nhận được về int32 | 24–25 |
| Đếm 5: BUY đọc TYPE trước; chỉ khi `==0` mới đọc SYMBOL vào chuỗi cục bộ rồi so với `symbol` | 28–35 |
| Đếm 6: SELL đọc SYMBOL vào chuỗi cục bộ trước; chỉ khi bằng mới đọc TYPE (`&&` dừng sớm); `==1` thì đếm | 36–40 |
| Đếm 7: không đọc giá/khối lượng, không chọn vé lại; chuỗi cục bộ hủy khi hàm trả về | cả hàm |
| Điều phối 1: `license_valid==0` → `Print("Licence not valid!")`, trả `true`; không gọi Total/iTime/manager | 65–69 |
| Điều phối 2: `tick_management==0 \|\| bar_override!=0 \|\| PositionsTotal()<1`; Total chỉ được gọi khi hai cờ cho phép nhánh từng lần nhận giá | 72 |
| Điều phối 3: chụp `frame` rồi `previous`; iTime lần 1, bằng thì trả `false`, không ghi; khác thì iTime lần 2 với `settings.symbol` và `timeframe` đọc lại, ghi kết quả lần 2 vào `last_times[strategy_index]`; manager BUY rồi luôn manager SELL; trả OR sau khi gọi đủ hai hàm | 74–86 |
| Điều phối 4: đếm BUY → `buy_changed=false` → manager BUY chỉ khi số đếm `>0`; luôn đếm SELL (Total riêng, sau BUY) → `sell_changed=false` → manager SELL chỉ khi `>0`; trả OR; không gọi iTime, không ghi `last_times` | 89–102 |
| Điều phối 5: không gọi phần khác của chương trình, không dọn cache/bảng dừng, không đặt lại `last_ticket` | cả hàm |

Ô `last_times` chọn bằng tham số `strategy_index`, không dùng `shared.strategy_index`.
`settings.symbol`, `settings.magic`, `shared.last_ticket` được truyền tham chiếu ở mỗi lời gọi,
không sao chép cấu trúc.

## Đã đọc

- `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1PositionManagement.mqh`: struct
  `Bot1PositionManagementSettings`, `Bot1PositionManagementState`, chữ ký `Bot1ManagePositions`.
- `.../Bot1ManagementPrelude.mqh`: cách viết `PositionGet*` hiện hành.
- Tìm trong cùng thư mục: `Bot1PendingRequestState` (`Bot1PendingRequest.mqh`),
  `Bot1TradeSendOptions` (`Bot1TradeSend.mqh`). Không có hàm, guard, biến toàn cục hay macro
  trùng tên với tệp mới.
- `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3ManagementBarGate.mqh`: chỉ xem cách
  include/guard.
- `TASK.md` của thư mục này.

Không đọc EX5, mã máy, thư mục phân tích hay bằng chứng. Không chạy lệnh, Git, MT5; không sửa
nguồn chính; không tạo tác tử.

## Chưa làm

- Chưa biên dịch.
- Chưa chạy ca kiểm nào, chưa đối chiếu với EX5 gốc.
- Cần Codex xác nhận khi biên dịch/so: mã dựa vào việc `||` (dòng 72) và `&&` (dòng 39) của
  MQL5 đánh giá trái sang phải và dừng sớm.

## Cấu hình phiên

Ngữ cảnh phiên ghi: mô hình `claude-opus-5-5`, mức suy luận `max`, ultracode bật. Đây là thông
tin phiên tự báo, không phải bằng chứng độc lập; Codex kiểm cấu hình thực tế riêng.
