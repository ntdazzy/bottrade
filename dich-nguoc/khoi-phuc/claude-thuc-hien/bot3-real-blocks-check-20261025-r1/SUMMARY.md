# Bot3ManagementRealBlocksCheck — tóm tắt đề xuất r1

**Trạng thái:** mới viết mã. Chưa biên dịch, chưa chạy MT5, chưa so với EX5 gốc. Không sửa nguồn chính,
Git hay tệp nào ngoài hai tệp trong thư mục này. Không chạy lệnh hay tác tử khác.

Cấu hình lượt này: mô hình `claude-opus-5-5` (theo thông tin môi trường của phiên). Mức `max` và ultracode
không tự kiểm được từ trong phiên. Phiên không có công cụ Workflow và yêu cầu cấm tác tử khác, nên làm một mình.

## Tệp
- `Bot3ManagementRealBlocksCheck.mq5`: đích `MQL5/Scripts/bot-cua-toi-3/`, `input string CheckRun`.
- `SUMMARY.md`: tệp này.

## Giao diện đã đọc (chỉ lấy chữ ký và thứ tự nạp)
Nếu không ghi khác, `Bot3*.mqh` nằm ở `dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`.

| Phần | Vị trí |
|---|---|
| Mẫu tệp/băm/lỗi | `source/MQL5/Scripts/bot-cua-toi-3/Bot3ManagementRealTakeCheck.mq5` |
| Messages → TradeErrors | `Bot3ManagementMessages.mqh:5,8`; `Bot3TradeErrors.mqh:4` |
| Distance | `Bot3ManagementRealDistance.mqh:7,55` |
| Slippage | `Bot3ManagementRealSlippage.mqh:8,48` |
| HighLow, `Bot3PrintHighLowError` | `Bot3ManagementRealHighLow.mqh:9,18,62` |
| Lock, `Bot3PrintRealLockError` | `claude-thuc-hien/bot3-real-lock-20261025-r1/Bot3ManagementRealLock.mqh:9,20,54` |
| Counter | `claude-thuc-hien/bot3-real-counter-20261025-r1/Bot3ManagementRealCounter.mqh:6,45` |
| Store | `claude-thuc-hien/bot3-real-store-20261025-r1/Bot3ManagementRealStore.mqh:8` |
| Bảng `Bot3VirtualStopState` | `Bot3VirtualStops.mqh:5,7` (500 hàng, `rows[][3]`, `take_rows[][2]`, `guard`) |

Lock, Counter và Store chưa có trong Include chính, nên Codex cần đặt chúng vào đó trước khi biên dịch. Bản r1
của Slippage và HighLow trong `claude-thuc-hien` có chữ ký giống bản chính.

## Thứ tự nạp (`.mq5:5-7`, `116-136`)
1. Trước macro: Prelude, VirtualStops, VirtualFinish. Theo các dòng `#include` trong Include chính, chuỗi nạp
   của chúng (PriceLevels, PositionModify, PositionClose, TradeSend, TradeMessages, PendingRequest, Filling)
   không nạp Messages hay TradeErrors. Vì vậy `Print` nhiều đối số (`Bot3VirtualStops.mqh:103,139`) và
   `SymbolInfoInteger` 3 đối số (`Bot3TradeMessages.mqh:31,70`) vẫn gọi hàm thật, không đụng hàm giả.
2. Macro: `SymbolInfoInteger`, `SymbolInfoDouble`, `GetLastError`, `Print`, `Bot3ModifyPosition`,
   `Bot3TryClosePosition`.
3. Trong vùng macro: Messages (lúc này mới nạp TradeErrors lần đầu), rồi Distance, Slippage, HighLow, Lock,
   Counter, Store. Sau đó `#undef` cả sáu macro.
4. Kết quả: `Bot3PrintManagementError`, `Bot3PrintHighLowError` và `Bot3PrintRealLockError` chạy thân nguồn
   với `GetLastError`/`Print` giả. `Bot3TradeErrorText` là thân nguồn (tăng counter rồi chọn chuỗi theo mã).
   Runner không thay các hàm này và không tự ghép chuỗi lỗi; nó chỉ băm chuỗi mà `Print` nhận được.
5. `Print` trạng thái ở cuối `OnStart` nằm sau `#undef`, nên là `Print` thật và không vào băm ca.

## Hàm giả (`.mq5:47-115`)
Mỗi sự kiện gồm 5 `uint64`, băm FNV-1a 64 từng byte LE và được đếm. Mutate chỉ gọi sau khi ghi xong sự kiện,
và chỉ đổi dữ liệu khi `scenario==target`.

| API | Sự kiện | Mutate target | Trả về |
|---|---|---|---|
| DIGITS lần 0..3 | (3,17,(ulong)(long)digit,lần,0), rồi tăng số lần | 1,3,4,5 | digit |
| POINT lần 0..1 | (4,16,bits(point),lần,0), rồi tăng số lần | 2,6 | point |
| VOLUME_MIN | (4,34,bits(minimum),0,0) | 10 | minimum |
| Modify | (5,ticket,bits(sl),bits(tp),modify_ok) | 7 | modify_ok!=0 |
| Print | (13,textHash UTF-16LE,error_count lúc in,0,0) | 8 nếu bắt đầu bằng `TrailStop`/`error`, còn lại 9 | — |
| TryClose | (6,ticket,deviation,bits(bid),bits(ask)) rồi (7,bits(gap),bits(freeze),0,0) | 11 | true |
| GetLastError | không ghi sự kiện, không đổi gì | — | error_code |

Mutate (`.mq5:57`) chỉ đổi đúng các biến hợp đồng liệt kê. Nó không đổi position, reference, anchor,
step_reference, initial_stop, ticket_number, volumes, point, minimum, enabled, gap_count, minimum_steps, các cờ
hay error_count. NaN được cộng như phép tính MQL thường, không chuẩn hoá.

## Ca và kết quả (`.mq5:138-310`)
- Đọc đủ 456 byte (22 int32, int64, uint64, 2 uint32, 43 double) rồi mới kiểm; chỉ ca hợp lệ mới được gọi khối.
- Điều kiện kiểm: `id` bằng số thứ tự ca tính từ 0; buy 0/1; stage 0..5; scenario 0..11; index 0..8; sáu byte
  cờ trong 0..255; prior_changed 0/1; table_pattern 0..5; modify_ok 0/1. Các int khác giữ nguyên int32 có dấu.
- Mỗi ca: xoá state/options; dựng bảng 500 hàng theo công thức; `guard=(uchar)guard`; ghi các ô theo pattern
  0..5 (pattern 5 ghi NaN bit `0x7ff8000000000011` ở hàng 0 và ticket ở hàng 499; pattern 4 không ghi ô nào).
- `returned` chỉ lấy giá trị trả về của Distance; các khối void cho `false`.
- Ghi 400 byte: 5 int32, 2 uint32, uint64, 43 double giá trị cuối, int32 số sự kiện, băm sự kiện, băm 2500 double
  của bảng (stop hàng 0..499 × 3 ô, rồi take hàng 0..499 × 2 ô, FNV-1a 64 LE). Double được đọc/ghi bằng
  `FileReadDouble`/`FileWriteDouble`.

## Mã lỗi
- `OnStart` trả mã và không ghi status: 4 `CheckRun` sai; 5 đã có `mql5-results.bin` hoặc `script-status.bin`;
  6 không mở được `cases.bin`; 11 không mở được `script-status.bin`.
- Ghi vào `script-status.bin` (fault, count), giữ lỗi đầu tiên, không đặt lại mỗi ca:
  - 1: SymbolInfoInteger sai symbol/thuộc tính, hoặc DIGITS quá 4 lần.
  - 2: SymbolInfoDouble sai symbol/thuộc tính, hoặc POINT quá 2 lần.
  - 7: đầu tệp sai, hoặc kích thước khác `12+456*count`.
  - 8: không mở được `mql5-results.bin`.
  - 9: ca sai (dừng trước khi gọi khối).
  - 10: chưa đọc hết tệp.

## Chỗ hợp đồng chưa nói rõ — đã làm theo mẫu hoặc theo cách hẹp nhất (Codex cần xác nhận)
1. CONTRACT không ghi tên tệp vào/ra: dùng `cases.bin` và `mql5-results.bin` như mẫu.
2. "id thứ tự": hiểu là `id` bằng số thứ tự ca tính từ 0, như mẫu.
3. "flag bytes": hiểu là passed_flag, eligible_flag, before_open, shift_setting, step_enabled, guard.
4. Kiểm symbol `CHECK` ở cả SymbolInfoInteger lẫn SymbolInfoDouble, như mẫu. Khi sai: giữ lỗi 1 hoặc 2, trả 0,
   không ghi sự kiện, không Mutate, rồi chạy tiếp.
5. VOLUME_MIN: hợp đồng không giới hạn số lần gọi, nên không thêm giới hạn.
6. "rồi tăng index" ở DIGITS/POINT: hiểu là số lần gọi của chính API đó, không phải strategy index.
7. Bảng được dựng lại cho mọi ca, không chỉ stage 5, vì final_guard và table_hash được ghi cho mọi ca và
   Mutate có đổi guard.
8. Không đưa phần kiểm tham chiếu state/options của mẫu (`TakeSuppliedReferences`, lỗi 12) vào TryClose, vì
   hợp đồng không ghi.
9. Các trường position ngoài sl/tp/open_price/volume (kể cả `position.ticket_number`) để 0.
10. Tiền tố "error when" đã nằm trong tiền tố "error", nên chỉ so "TrailStop" và "error".
11. Ca sai: không ghi kết quả của ca đó, các ca trước vẫn giữ; đầu tệp kết quả vẫn ghi count đầu vào, như mẫu.

## Chưa có bằng chứng
- Chưa biên dịch, nên chưa biết MetaEditor có chấp nhận `#define Print` và `#define GetLastError` với bộ header
  này không (mẫu RealTakeCheck chỉ thay SymbolInfo*, Modify, Report và TryClose).
- Chưa chạy; chưa so số liệu và băm với bộ kiểm Python của Codex.
- Lock, Counter, Store là bản đề xuất r1 chưa duyệt và chưa biên dịch. Nếu Codex đổi chữ ký, phải sửa
  `BlocksRunStage` (`.mq5:176`).
- Chi phí chạy: mỗi ca băm 20.000 byte bảng, nên 100.000 ca ≈ 2×10⁹ bước FNV; chưa đo thời gian.
