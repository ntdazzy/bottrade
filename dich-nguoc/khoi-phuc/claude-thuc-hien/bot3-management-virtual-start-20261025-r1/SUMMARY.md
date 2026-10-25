# Tóm tắt — phần A `Bot3StartVirtualManagement` bot 3 (r1)

Trạng thái thật: **chỉ là ứng viên. Chưa biên dịch, chưa chạy, chưa so với
EX5 gốc; không có ca đạt.** Chỉ ghi `Bot3ManagementVirtualStart.mqh` và tệp
này (`TASK.md` giữ nguyên). Không sửa `bot-cua-toi-3/source/`, không đụng
thư mục phần B. Không đọc EX5/C/native, không chạy lệnh, Git hay MT5.

Logic chỉ lấy từ
[contract](../../bot-cua-toi-3/phan-tich/dong-vi-the/management-virtual-levels-20261025-r1/contract.md)
dòng 1–14 (chung) và 16–62 (phần A). Chữ ký hàm con lấy từ nguồn chính
`bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`.

## Điều đã giữ

Số dòng là dòng trong [Bot3ManagementVirtualStart.mqh](Bot3ManagementVirtualStart.mqh).

| Mô tả | Mã |
|---|---|
| `bool`, 19 tham số đúng thứ tự/kiểu; `ticket` là long nhận vào, không đọc lại từ `position` | :13–21 |
| 1. `Bot3VirtualStopLevel(table,open_tickets,symbol,unit,buy?1:2,position.open_price,stop_distance,ticket)`; ghi `current_stop=initial_stop` trước lời gọi lấy chốt | :23–25 |
| 2. `Bot3VirtualTakeLevel(table,open_tickets,position.tp,ticket)`; ghi `current_take=initial_take` | :26–27 |
| 3. Chạm — mua: `current_stop>=tick.bid` hoặc (`0.0<initial_take` và `tick.bid>=initial_take`); bán: `tick.ask>=current_stop` hoặc (`0.0<initial_take` và `initial_take>=tick.ask`). Đọc `current_stop` sau lời gọi lấy chốt; dùng `initial_take` | :28–29 |
| Chạm → `SymbolInfoTick` (bỏ bool) → `Bot3TryClosePosition` (0x47d20) đủ 8 đối số, vé `(ulong)ticket` → true. Không Print, không gọi `Bot3ClosePosition` (0x2e370) | :30–36 |
| 4. `Bot3VirtualStopDelayPassed(table,delay_seconds,ticket)` false → false | :37 |
| 5. digits → đọc `current_stop` → `Bot3RoundPrice` → `SymbolInfoDouble(symbol,SYMBOL_POINT)`; mua cần `position.sl+point<candidate`, bán cần `candidate<position.sl-point`; không đạt → false | :38–41 |
| 6. digits lần hai → đọc lại `current_stop` → làm tròn → ghi `position.sl`; `Bot3ModifyPosition` bỏ bool; `Bot3VirtualStopStamp` luôn gọi | :42–45 |
| 7. Trả false | :46 |
| So có thứ tự: điều kiện dương viết thẳng (`>=`, `<`) hoặc trong `!(...)`, để NaN không đi nhánh | :28–29, :41 |
| Không sửa `position.tp`, không có cờ `changed`; `position.sl` chỉ ghi ở bước 6, không ghi giá tạm sau ±point | toàn hàm |
| Dùng hàm con có sẵn, không viết lại; không `NormalizeDouble` | :23–45 |

## Giới hạn, cần Codex kiểm

1. Chưa biên dịch. Cần xem: bỏ bool của `SymbolInfoTick` có cảnh báo không
   (dạng giống `Bot1ManagementPrelude.mqh:146`, `Bot3Margin.mqh:8`); truyền
   `tick.bid`/`tick.ask` vào `const double &` (giống `Bot3ManagementVirtual.mqh:64`).
2. Chưa đo xem MQL5 xử lý `>=` với NaN có đúng kiểu so có thứ tự không. Mã
   giữ đúng chiều trong mô tả (`current_stop>=tick.bid`), không đổi sang
   `!(current_stop<tick.bid)` vì dạng đó cho NaN đi nhánh đóng.
3. Chưa có bộ kiểm. Ca nên có: chạm do dừng, do chốt, cả hai, không chạm;
   hai vế bằng nhau; NaN ở `current_stop`, `initial_take`, bid/ask,
   `position.sl`, POINT; chốt 0/âm; hàm giả API (digits, POINT, API trong
   `Bot3VirtualTakeLevel` khi bảng đầy/guard≠1) đổi `current_stop`/tick giữa
   chừng; Delay false; Modify trả false mà Stamp vẫn gọi; chặn ở
   `Bot3TryClosePosition`, không chặn ở `Bot3ClosePosition`.
4. Chú thích `Bot3VirtualStops.mqh:145` ghi Delay/Stamp "Not compiled;
   verification is pending". Tôi không kiểm lại hai hàm này.
5. Hàm cùng dạng của bot 1 (`Bot1StartVirtualManagement`) có 924/924 ca đoạn
   riêng (`bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/virtual-start-20261025-r6/comparison.json`).
   Chỉ để tham khảo, không thay cho kiểm bot 3.

## Phụ thuộc

- `Bot3ManagementPrelude.mqh`: `Bot3ManagedPosition`; qua include của nó:
  `Bot3RoundPrice`, `Bot3ModifyPosition`, `Bot3TryClosePosition`,
  `Bot3TradeSendOptions`, `Bot3PendingRequestState`.
- `Bot3VirtualStops.mqh`: `Bot3VirtualStopState`, `Bot3VirtualStopLevel`,
  `Bot3VirtualTakeLevel`, `Bot3VirtualStopDelayPassed`, `Bot3VirtualStopStamp`.
- Include tương đối: phải đặt tệp trong `Include/bot-cua-toi-3/` cạnh các header trên.
- Bên gọi khi ghép phải cấp: `ticket` (có thể là `Bot3ManagementAnchorState.ticket`,
  kiểu long, `Bot3ManagementAnchor.mqh:11,25`; chưa kiểm là cùng ô stack mua+40/bán+48),
  `delay_seconds` 0x6d518 (không phải 0x7449c), `current_stop` 0x6d670,
  `current_take` 0x724a0, `unit` 0x73dd8, `stop_distance` 0x6d588, tick
  (bid 0x74798/ask 0x747a0). Mô tả phần A không ghi địa chỉ deviation/threshold.
- API MT5 gọi trực tiếp: `SymbolInfoTick`, `SymbolInfoInteger(SYMBOL_DIGITS)`,
  `SymbolInfoDouble(SYMBOL_POINT)`.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`; thông tin phiên ghi
"Ultracode is on". Mức `max` không tự kiểm được. Phiên không có công cụ
Workflow hay tác tử phụ; chỉ dùng Read/Grep/Glob/Write/Edit và tự rà từng bước mô tả với mã.
