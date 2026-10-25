# Bot3ManagementBarGate.mqh — tóm tắt

## Đã viết
- `Bot3ManagementBarGate.mqh`: guard `BOT3_MANAGEMENT_BAR_GATE_MQH`,
  `#include "Bot3PositionManagement.mqh"` và đúng một hàm `Bot3ManageOnBarChange` với giao diện
  ghi trong `TASK.md`.
- `SUMMARY.md`: tệp này. Không tạo hoặc sửa tệp nào khác.

## Đã đọc
- `TASK.md` trong thư mục này (cùng nội dung yêu cầu), chỉ để xác định đúng thư mục ghi.
- `dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3PositionManagement.mqh`
  (chỉ đọc, không sửa): guard `BOT3_POSITION_MANAGEMENT_MQH`; kiểu
  `Bot3PositionManagementSettings`, `Bot3PositionManagementState`; chữ ký
  `bool Bot3ManagePositions(const bool buy,const Bot3PositionManagementSettings &settings,
  Bot3PositionManagementState &shared,const double &levels[],Bot3PendingRequestState &requests,
  Bot3TradeSendOptions &options,const ulong &deviation)` (dòng 272–275). Header này include
  bằng dạng tương đối `"..."`, nên tệp mới dùng cùng dạng.
- Không đọc EX5, mã máy, tài liệu phân tích hay tệp nguồn khác.

## Trình tự trong mã

| Bước theo mô tả | Dòng | Cách viết |
|---|---|---|
| 1 | 16–19 | `frame=(ENUM_TIMEFRAMES)timeframe`; chụp `previous=last_times[strategy_index]` trước `iTime`; `observed=(long)iTime(symbol,frame,1)`; `previous==observed` → `return false` (không ghi ô, không gọi quản lý). |
| 2 | 21–22 | `iTime` lần 2 với `(ENUM_TIMEFRAMES)timeframe` đọc lại, `symbol` tham chiếu, shift 1; gán `(long)` vào `current` rồi mới ghi `last_times[strategy_index]=current`. Không dùng `observed` để ghi; không kiểm 0/lỗi, không vòng chờ. |
| 3 | 24–25 | `buy_changed=Bot3ManagePositions(true,settings,shared,buy_levels,requests,options,deviation)`. |
| 4 | 26–27 | `sell_changed=Bot3ManagePositions(false,settings,shared,sell_levels,requests,options,deviation)`, luôn gọi sau mua kể cả khi mua trả `true`; truyền thẳng tham chiếu, không copy, chụp hay reset. |
| 5 | 28 | `return buy_changed || sell_changed;` sau khi cả hai lời gọi xong; `||` chỉ đọc hai biến cục bộ nên không bỏ lời gọi bán. |

Ô thời gian được chọn bằng tham số `strategy_index` (giá trị chụp), không đọc
`shared.strategy_index`. Ngoài 2 lời gọi `iTime` và 2 lời gọi `Bot3ManagePositions` không có lời
gọi nào khác: không lấy tick, không thêm giờ giao dịch, không vào lệnh, không đọc mode, không kiểm
biên mảng (bên gọi bảo đảm chỉ số 0..8 và mảng đủ 9 ô).

## Trạng thái kiểm
- CHƯA biên dịch, CHƯA chạy, CHƯA so với EX5 gốc. Không chạy lệnh, không đụng MT5, Git hay nguồn
  chính.
- Thư mục đề xuất không có `Bot3PositionManagement.mqh`; muốn biên dịch phải đặt tệp cạnh header
  đó (`MQL5/Include/bot-cua-toi-3/`).
- Cần Codex kiểm độc lập: biên dịch; thứ tự `previous` → `iTime` lần 1 → so sánh → `iTime` lần 2
  → ghi ô; mua luôn chạy trước bán và bán vẫn chạy khi mua trả `true`; hai lối trả về.

## Cấu hình phiên
- Mô hình theo thông tin môi trường của phiên: `claude-opus-5-5`. Thông báo của phiên ghi
  Ultracode đang bật.
- Mức suy luận `max`: trong phiên không thấy dấu hiệu nào xác nhận trực tiếp, nên không tự xác
  nhận.
- Không tạo tác tử hay Workflow vì yêu cầu cấm tạo tác tử; làm trong một phiên.
