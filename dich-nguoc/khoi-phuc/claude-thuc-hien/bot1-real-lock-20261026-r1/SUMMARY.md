# SUMMARY: bot1-real-lock-20261026-r1

## Trạng thái
- Đã viết `Bot1ManagementRealLock.mqh` theo mô tả trong `TASK.md` của thư mục này.
- **Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.** Phiên này không chạy lệnh;
  Codex kiểm, ghép, biên dịch và so độc lập.
- Không sửa nguồn chính, Git hay MT5. Không tạo tác tử.

## Tệp
- `Bot1ManagementRealLock.mqh` (mới, 83 dòng, chỉ ký tự ASCII).
- `SUMMARY.md` (tệp này).

## Vị trí trong mã
- Dòng 4-7: guard `BOT1_MANAGEMENT_REAL_LOCK_MQH`; include `Bot1ManagementPrelude.mqh`
  và `Bot1ManagementMessages.mqh` (tệp sau mang `Bot1TradeErrorText` qua `Bot1TradeErrors.mqh`).
- Dòng 10-15: `void Bot1PrintRealLockError(uint &counter)`: `int code=(int)GetLastError();`
  một lần, `Bot1TradeErrorText(code,counter)` (helper tự tăng counter), rồi `Print(...)`.
  Không `ResetLastError`, không tự tăng counter.
- Dòng 17-48: `Bot1AdvanceRealLockBuyStop`, 13 tham số đúng thứ tự TASK.md, `ticket` truyền giá trị.
- Dòng 50-82: `Bot1AdvanceRealLockSellStop`, cùng 13 tham số.

## Đối chiếu từng bước
| Bước | MUA (dòng) | BÁN (dòng) |
|---|---|---|
| 1 | 23 `!(0.0<start)` | 56 `!(0.0<start)`; 58-60 `captured_unit`, `trigger`, `!(tick.ask<trigger)`; không DIGITS/làm tròn |
| 2 | 25 `quote1` trước DIGITS1 (26); 27-28 `gate1`, `!(gate1<quote1)` | 61 `candidate` trước POINT1 (62); 63 `!(candidate<position.sl-point)`; không tính lại |
| 3 | 29-30 DIGITS2, `candidate` đọc ref mới; 32 POINT1 sau làm tròn; 33 `!((point+position.sl)<candidate)`; không tính lại | 65-67 `offset`, `quote` đọc mới sau POINT1; `!(quote<(position.open_price-offset)-gap)` |
| 4 | 34 `quote2` trước DIGITS3 (35); 36-37 `gate2`, `!(gate2<quote2)` | 68 `!((freeze+position.tp)<quote)`, cùng `quote` bước 3 |
| 5 | 38 `!(tick.bid<position.tp-freeze)`; không DIGITS | 70-72 DIGITS1, `gate`, `!(gate<position.sl)`; chưa ghi sl |
| 6 | 39-43 DIGITS4, `new_sl`, ghi `position.sl` trước `!(new_sl<tick.bid-gap)` | 73-77 DIGITS2, `new_sl`, ghi `position.sl` trước `!((tick.ask+gap)<new_sl)` |
| 7 | 45-47 Modify, `changed=true`, rồi `if(!ok)` báo lỗi | 79-81 như MUA |

## Số lần gọi theo đường ra (đếm từ mã này, không phải từ EX5)
| Thoát tại | MUA DIGITS/POINT | BÁN DIGITS/POINT |
|---|---|---|
| Bước 1 sai | 0/0 | 0/0 |
| Bước 2 sai | 1/0 | 0/1 |
| Bước 3 sai | 2/1 | 0/1 |
| Bước 4 sai | 3/1 | 0/1 |
| Bước 5 sai | 3/1 | 1/1 |
| Bước 6 sai (gap) | 4/1, `position.sl=new_sl` | 2/1, `position.sl=new_sl` |
| Tới Modify | 4/1 + 1 Modify | 2/1 + 1 Modify |

- Mọi đường ra trước Modify giữ `changed` cũ; chỉ bước 6 sai để lại sl mới.
- Tới Modify: `changed=true` dù `ok` đúng hay sai. Khi `!ok`: `GetLastError` 1 lần,
  `error_count` tăng 1 (trong `Bot1TradeErrorText`), `Print` 1 lần. Khi `ok`: không in gì.

## Kiểm tĩnh đã làm (Grep, không biên dịch)
- Chuỗi Print ở dòng 14 khớp nguyên văn chuỗi trong `TASK.md` dòng 7 (cùng một mẫu regex khớp cả hai).
- Không có `NormalizeDouble`, `ResetLastError`, `SymbolInfoTick`, `TryClose`, `VOLUME`,
  `TimeCurrent`, `position.tp=`, `++`, `DBL_EPSILON`, `MathAbs`, `mode`.
- Tên hai hàm mới, helper và guard không trùng trong `bot-cua-toi-1/source/MQL5`.

## Đã đọc / không đọc
- Đọc: `TASK.md`; header Bot1 trong `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`:
  `Bot1ManagementPrelude.mqh`, `Bot1ManagementMessages.mqh`, `Bot1ManagementRealDistance.mqh`,
  `Bot1ManagementRealSlippage.mqh`, `Bot1ManagementRealStore.mqh`, `Bot1ManagementRealTimed.mqh`,
  `Bot1PriceLevels.mqh`, `Bot1PositionModify.mqh`, `Bot1TradeErrors.mqh`.
- Không đọc: EX5, mã máy, thư mục phân tích, `QUY-TRINH.md` (TASK.md chỉ cho đọc header Bot1).

## Codex cần kiểm
1. Biên dịch bằng MetaEditor; xem cảnh báo (ví dụ ép `(int)GetLastError()` thừa nhưng đúng mô tả).
2. Dịch vụ giả: thứ tự và số lần DIGITS/POINT như bảng trên; tham chiếu được đọc lại sau mỗi lần gọi.
   Giá trị chỉ được chụp vào biến cục bộ ở `quote1`, `quote2`, `quote`, `captured_unit`,
   `candidate`, `offset`, `gate1`, `gate2`, `gate`, `new_sl`.
3. NaN ở từng cổng; `changed` giữ nguyên ở mọi đường ra trước Modify; `error_count` chỉ tăng khi Modify lỗi.
4. So với EX5 gốc trên cùng dữ liệu và điều kiện.

## Cấu hình phiên
- Theo thông tin hệ thống của phiên: mô hình Opus 5.5 (`claude-opus-5-5`), Ultracode bật.
  Mức `max`: không tự kiểm được từ trong phiên; Codex cần xem cấu hình chạy thực tế.
- Không dùng tác tử con hay quy trình con (TASK.md cấm; phiên cũng không có công cụ đó).
