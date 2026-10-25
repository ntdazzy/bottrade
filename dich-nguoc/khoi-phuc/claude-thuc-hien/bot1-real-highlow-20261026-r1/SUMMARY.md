# Bot1ManagementRealHighLow: tóm tắt đề xuất

**Trạng thái:** đã viết mã theo `TASK.md`. **Chưa biên dịch, chưa chạy, chưa so với EX5 gốc.**
Chưa có kết quả kiểm nào. Codex sẽ tự kiểm, ghép, biên dịch và so với bản gốc.

## Tệp đã viết

| Tệp | Nội dung |
|---|---|
| `Bot1ManagementRealHighLow.mqh` | 99 dòng; guard `BOT1_MANAGEMENT_REAL_HIGH_LOW_MQH`; include `Bot1ManagementPrelude.mqh`, `Bot1ManagementMessages.mqh` |
| `SUMMARY.md` | tệp này |

Các hàm:

- `void Bot1PrintHighLowError(uint &counter)`: dòng 10–15.
- `void Bot1AdvanceHighLowRealBuyStop(...)`: dòng 17–57, 18 tham số đúng thứ tự và kiểu trong TASK.
- `void Bot1AdvanceHighLowRealSellStop(...)`: dòng 59–98, cùng 18 tham số.

Mã chỉ dùng `Bot1RoundPrice`, `Bot1ModifyPosition` và `Bot1TradeErrorText` có sẵn. Không dùng
`NormalizeDouble`, không viết lại helper, không đổi TP, không đóng vị thế, không hỏi khối lượng,
không lấy tick mới, không ghi bảng mức, không ghi `before_open`/`shift_setting`/`eligible_flag`/`levels`.

## Đối chiếu TASK với dòng mã

### Hàm báo lỗi

| Yêu cầu | Dòng |
|---|---|
| Đọc `GetLastError` 1 lần, không `ResetLastError` | 12 |
| `string message=Bot1TradeErrorText(code,counter);` không tự tăng `counter` | 13 |
| `Print("error: '"+message+"' when modifying stoploss");` | 14 |

### MUA

| Bước | Mã | Dòng |
|---|---|---|
| Đầu | `enabled<=0 \|\| eligible_flag==0` thì return | 25 |
| 1 | `level1` → DIGITS1 → `gate_base=gap+position.sl` → POINT1 → `gate=Bot1RoundPrice(gate_base+point1,digits1)` → `!(gate<level1)` | 27–32 |
| 2 | `quote=tick.bid`, `level2` đọc mới, `count=(double)gap_count`, `captured_unit=unit` → `!(level2<quote-count*captured_unit)` | 33–37 |
| 3 | `!(level2<position.open_price) && (before_open&1)!=0` | 39 |
| 4 | DIGITS2 → `shift`, `tick.bid`, `unit`, `gap` đọc mới → POINT2 → `boundary=Bot1RoundPrice(boundary_base-point2,digits2)` → `!(level2<boundary)` (level2 của bước 2) | 41–46 |
| 5 | `!(tick.bid<position.tp-freeze)`, không có DIGITS | 47 |
| 6 | DIGITS3 → `new_sl=Bot1RoundPrice(levels[strategy_index],digits3)` → `position.sl=new_sl` → `!(new_sl<tick.bid-gap)` | 48–52 |
| 7 | `ok=Bot1ModifyPosition(...)` → `changed=true` → `if(!ok)` báo lỗi; nhánh thành công không in | 54–56 |

### BÁN

| Bước | Mã | Dòng |
|---|---|---|
| Đầu | giống MUA | 67 |
| 1 | `level1`, `gate_base=position.sl-gap` → POINT1 → `!(level1<gate_base-point1)`; không DIGITS, không làm tròn | 69–72 |
| 2 | `captured_unit=unit`, `level2` đọc mới, `quote=tick.ask` → `!(((double)gap_count*captured_unit+quote)<level2)` | 73–76 |
| 3 | `!(position.open_price<level2) && (before_open&1)!=0` | 78 |
| 4 | `shift`, `boundary_base=(quote+captured_unit*shift)+gap` → POINT2 → `!((boundary_base+point2)<level2)`; không đọc lại unit/quote/level2 | 80–83 |
| 5 | `!((freeze+position.tp)<tick.ask)`, ask đọc mới sau POINT2 | 84 |
| 6 | DIGITS1 → `candidate=Bot1RoundPrice(levels[strategy_index],digits1)` → `!(candidate<position.sl)`; chưa ghi sl | 86–88 |
| 7 | DIGITS2 → `new_sl` đọc index/mức mới → `position.sl=new_sl` → `!((tick.ask+gap)<new_sl)` | 89–93 |
| 8 | `ok` → `changed=true` → báo lỗi nếu `!ok` | 95–97 |

## Thứ tự gọi dịch vụ theo mã (để so bằng dịch vụ giả)

- MUA, đi hết: DIGITS → POINT → DIGITS → POINT → DIGITS → `Bot1ModifyPosition` → chỉ khi lỗi: `GetLastError` → `Print`.
- BÁN, đi hết: POINT → POINT → DIGITS → DIGITS → `Bot1ModifyPosition` → chỉ khi lỗi: `GetLastError` → `Print`.
- Mỗi lần thoát sớm dừng ngay tại cổng đó, không gọi thêm gì.

## Trạng thái khi thoát

| Lối thoát | `position.sl` | `changed` | `error_count` |
|---|---|---|---|
| Cổng đầu; cổng 1–5 MUA; cổng 1–6 BÁN | giữ | giữ | giữ |
| Cổng gap (MUA dòng 52, BÁN dòng 93) | `new_sl` | giữ | giữ |
| Sửa thành công | `new_sl` | `true` | giữ, không in |
| Sửa lỗi | `new_sl` | `true` | +1 do `Bot1TradeErrorText`, in 1 dòng |

## Chỗ cách viết cần Codex kiểm

1. Cổng `before_open` dùng `&&` ngắn mạch: chỉ đọc `before_open` khi phép so `<` thất bại.
   Giữa hai vế không có lời gọi dịch vụ. Với NaN, phép so thất bại; nếu bit thấp bằng 0 thì đi tiếp,
   không thêm kiểm NaN.
2. Cổng đầu so cả byte `eligible_flag==0`, không lấy bit thấp, đúng chữ trong TASK.
3. `Bot1PrintHighLowError` trả `void` vì TASK không nêu kiểu trả.
4. Phép nhân luôn được tính kể cả khi `shift==0.0` hoặc `gap_count==0`, nên `0*Inf` vẫn ra NaN; không rút gọn.
5. BÁN bước 2 đọc `gap_count` trong biểu thức so, sau `captured_unit`, `level2`, `quote`; ở giữa không có lời gọi dịch vụ.
6. Tên guard đặt theo mẫu các header khác. Đã tìm `HighLow`/`HIGH_LOW` trong `bot-cua-toi-1/source`:
   chỉ có `Bot1AdvanceVirtualHighLow`, không trùng tên.
7. Dòng đầu tệp ghi `Candidate only: not compiled, not run, not compared with the original EX5.`
   Codex sửa dòng này khi đã có bằng chứng.

## Đã đọc và không đọc

- Đã đọc: `TASK.md`; header bot1 hiện hành trong `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`:
  `Bot1ManagementPrelude.mqh`, `Bot1ManagementMessages.mqh`, `Bot1ManagementRealSlippage.mqh`,
  `Bot1ManagementRealDistance.mqh`, `Bot1ManagementRealStore.mqh`, `Bot1ManagementRealTimed.mqh`,
  `Bot1ManagementVirtualFinish.mqh`, `Bot1TradeErrors.mqh`, `Bot1PriceLevels.mqh`, `Bot1PositionModify.mqh`.
- Đã tìm (không mở tệp): tên struct `Bot1PendingRequestState`/`Bot1TradeSendOptions`; tên `HighLow`/`HIGH_LOW`;
  tên biến cục bộ có thể trùng biến toàn cục trong `*.mq5` của `source`. Chỉ thấy biến cục bộ trong script kiểm.
- Không đọc EX5, mã máy, thư mục phân tích hay bản bot3.
- Không sửa nguồn chính, Git hay MT5. Không chạy lệnh. Không tạo tác tử.

## Cấu hình lượt này

- Theo thông tin môi trường của phiên: mô hình Claude Opus 5.5 (`claude-opus-5-5`), Ultracode bật.
- Mức `max`: không tự xác minh được từ trong phiên; Codex cần kiểm cấu hình thực tế.
- Ultracode khuyên dùng Workflow/tác tử, nhưng TASK cấm tạo tác tử và phiên không có công cụ Workflow,
  nên tôi làm một mình.
- Phần tự rà của Claude chỉ đối chiếu mã với TASK; không thay cho biên dịch và so với bản gốc.

## Chưa làm

- Chưa biên dịch bằng MetaEditor.
- Chưa chạy bộ kiểm hay dịch vụ giả.
- Chưa so với EX5 gốc.
