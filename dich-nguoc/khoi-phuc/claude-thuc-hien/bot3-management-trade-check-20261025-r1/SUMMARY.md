# Bot3PositionManagementFlowCheck – chế độ ExecuteTradeChildren (đề xuất của Claude)

**Trạng thái:** mới viết mã theo `TASK.md`. **Chưa biên dịch, chưa chạy MT5, chưa so với bản gốc.**
Đây là chương trình kiểm, không phải thuật toán quản lý. Codex kiểm, ghép và chạy.

Chỉ tạo 2 tệp trong thư mục này: `Bot3PositionManagementFlowCheck.mq5`, `SUMMARY.md`.
Không sửa nguồn chính, header, bộ kiểm Python, Git hay MT5; không chạy lệnh, không tạo tác tử.
Tệp `.mq5` phải đặt vào `source/MQL5/Scripts/bot-cua-toi-3/` thì các include `../../Include/...` mới đúng.

Cấu hình lượt: mô hình `claude-opus-5-5`, phiên báo bật Ultracode. Mức `max` không tự kiểm được
từ bên trong. Phiên không có công cụ Workflow và giao việc cấm tạo tác tử nên làm một mình.

## Nguồn đã đọc (chỉ để dùng đúng giao diện)
- Script hiện hành `Scripts/bot-cua-toi-3/Bot3PositionManagementFlowCheck.mq5` (368 dòng).
- Header: PositionModify, PositionClose, TradeSend, PendingRequest, Filling, TradeMessages,
  VirtualStops, PriceLevels, PositionManagement và mọi header Management* nó nạp, TradeErrors.
- Chỉ grep `tests/check-position-management-flow.py` để biết preset và phiên bản đang đọc; không sửa.
- Không đọc EX5, mã máy hay tài liệu phân tích. Không viết lại hàm nào trong header.

## Thay đổi (số dòng của tệp mới)
| Mục giao việc | Dòng | Cách làm |
|---|---|---|
| Input mới | 6 | `input bool ExecuteTradeChildren=false;` |
| Kiểm tổ hợp input | 453 | `ExecuteTradeChildren && !ExecuteTableChildren` → `return 12`, trước mọi thao tác tệp |
| Thứ tự include | 18–244, 287–317 | SDK giả + prototype → 17 macro SDK (không có Print, 223–239) → PositionModify, PositionClose (240–241, kéo theo TradeSend, PendingRequest, Filling, TradeMessages) → `#define Print FPrint` (243) → VirtualStops (244) → 6 wrapper → macro wrapper → PositionManagement (293) → `#undef` đủ 24 macro |
| 1 IsStopped | 192 | `FIsStopped` luôn `false`, không trace |
| 2 PositionSelectByTicket | 96–102 | `FSelectByTicket`: hàng sống đầu tiên có ticket khớp; thấy thì `FSelected=i`, không thấy giữ `FSelected` cũ; trace 27 sau cập nhật; không xóa vị thế |
| 3 SymbolInfoInteger | 136–147 | EXEMODE→2, FILLING_MODE→1; trace `1,(ulong)property,FText(symbol),value,symbol==NULL`; không tăng `FDigitCalls`, không gọi `FAfterDigits`; symbol khác CHECK → `FFail(23)`. DIGITS và property lạ đi đúng đường cũ |
| 4 SymbolInfoDouble | 153–160 | giữ dòng cũ, thêm BID→`FBid`, ASK→`FAsk`; vẫn trace 18; guard 24 nhận thêm BID/ASK |
| 5 OrderSend/Async | 203–221 | `FOrderSend` (mode 0), `FOrderSendAsync` (mode 1) → `FTradeService`. SLTP: `FCase[10]`, DEAL: `FCase[11]`, khác: `FFail(32)`. Băm request và result cũ → `ZeroMemory(result)` → gán đúng các trường mô tả (comment để NULL) → trace 28, trace 29 → `FTradeSends++` → DEAL được nhận và profile≠7 thì xóa hàng sống đầu tiên khớp `request.position`. Không sửa request |
| 6 FModify | 270–275 | chế độ mới: trace 30 rồi `return Bot3ModifyPosition(...)` thật; chế độ cũ giữ trace 8 |
| 7 FTryClose | 276–285 | kiểm `FCloseReferences` như cũ; chế độ mới: trace 31, gọi `Bot3TryClosePosition(...)` thật, `return true`, không xóa ở wrapper; chế độ cũ giữ trace 9 và xóa như cũ |
| Khởi tạo | 349–350 | sau ZeroMemory: `FRequests.magic=0`, `preferred=ORDER_FILLING_FOK`, `async_mode=0`, `margin_mode=0`, `log_level=0`; `FTradeSends=0` mỗi ca. `FDeviation`, vị thế, cài đặt, giá giữ nguyên |
| Băm | 39–77, 412–419 | seed `cbf29ce484222325`, `FHashWord` có sẵn; string = 2 word `FText`, `==NULL`; enum/int32 qua `(long)(int)`; uint32 thẳng `ulong`; datetime qua `long`; thứ tự trường đúng mô tả. Metadata nhận tham chiếu `FRequests`, `FOptions`, `FDeviation` |
| Đầu ra | 444–449, 468 | header version 3; mỗi ca = 156 byte của chế độ bảng + 4 `uint64` (request, result, check, metadata của `FRequests` sau vòng quản lý) + `int32 FTradeSends` = 192 byte. Version 1/2, `cast-values.bin`, `script-status.bin`, `cases.bin` giữ nguyên |

Trace mới (word thứ 5 bằng 0 nếu không ghi):
| Mã | Word |
|---|---|
| 27 | ticket, found, `FSelected` sau cập nhật |
| 28 | mode, requestHash, oldResultHash, newResultHash |
| 29 | action, accepted, `FTradeSends` trước khi tăng |
| 30 | ticket, bits(sl), bits(tp) |
| 31 | ticket |

## Chỗ chưa rõ / tự chọn (Codex cần xác nhận)
1. **Mã lỗi tổ hợp input:** mô tả không cho số; chọn `12` (chưa dùng ở script này), đặt đầu `OnStart`.
2. **Overload 3 đối số `FSymbolInteger(symbol,property,long &value)` (149–152):** không có trong mô tả
   nhưng bắt buộc để biên dịch, vì macro nay có hiệu lực trước Filling, PendingRequest, TradeMessages
   và các tệp đó gọi `SymbolInfoInteger(name,property,value)`. Làm guard: `FFail(23)`, trả `false`,
   không trace, không ghi `value`. Theo nguồn, luồng này không tới đó: `log_level=0` nên không định
   dạng thông điệp; EXEMODE=2 trả trước `Bot3ExpirationAllowed`; quản lý không gọi
   `Bot3PreparePendingRequest`. Muốn mã lỗi riêng thì đổi 23.
3. Dạng 2 đối số `SymbolInfoInteger(symbol,SYMBOL_EXPIRATION_MODE)` trong PendingRequest nay vào đường
   DIGITS cũ (`FFail(23)`); cũng không được gọi trong luồng này.
4. **Action khác SLTP/DEAL:** mô tả chỉ nói báo `FFail(32)`. Đã cho `accepted=false` rồi vẫn chạy luồng
   chung (băm, ghi result, trace 28/29, tăng `FTradeSends`), không xóa vị thế.
5. **`async_mode` kiểu `uchar`:** mô tả không có quy tắc cho uchar; dùng `(ulong)` thẳng (giá trị 0..255
   nên bit giống `(long)(int)`). Trace 29 dùng `(ulong)action` đúng chữ mô tả (bit giống quy tắc enum).
6. **`FRemovePosition` (193–201)** dùng chung cho chế độ cũ và dịch vụ giả; vòng lặp giống hệt đoạn cũ
   (khớp đầu tiên, dồn trái, `FLive--`, `FSelected=-1`).
7. Gán `FRequests`/`FOptions` ở 349 chạy mọi chế độ; giá trị bằng kết quả ZeroMemory nên không đổi chế độ cũ.
8. Ở hai chế độ cũ, thân PositionModify/PositionClose/TradeSend/Filling/PendingRequest/TradeMessages
   nay biên dịch với SDK giả (trước là SDK thật). Các hàm này không được gọi ở chế độ cũ, nên trace và
   kết quả **phải** trùng byte với bằng chứng cũ – cần chạy hồi quy để xác nhận.
9. `Print` nhiều đối số và `PrintFormat` trong các header gửi lệnh vẫn là hàm thật, được biên dịch nhưng
   không được gọi (IsStopped giả `false`, `log_level=0`). `Bot3OpenPending` cũng đi vào dịch vụ giả.

## Chưa làm / cần kiểm
| Việc | Trạng thái |
|---|---|
| Biên dịch | Chưa. Có thể có cảnh báo về tham số không dùng ở overload 3 đối số, ép enum→`ulong`; cần trình biên dịch xác nhận 0 lỗi/0 cảnh báo |
| Chạy MT5 chế độ mới | Chưa |
| Hồi quy version 1/2 | Chưa; cần so byte với bằng chứng cũ (vd. `manager-parent-regression-20261025-r1`, `manager-tables-20261025-r2`) |
| Bộ kiểm Python | Chưa sửa; hiện chỉ ghi preset `CheckRun`/`ExecuteTableChildren` và đọc version 1/2. Cần thêm `ExecuteTradeChildren=true`, version 3, 192 byte/ca |
| So với EX5 gốc | Chưa; kết quả mong đợi phải lấy từ bản gốc, không lấy từ tệp này |
