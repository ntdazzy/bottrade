# Bot3Preparation — bản đề xuất của Claude

## Trạng thái

- Đã viết `Bot3Preparation.mqh` trong thư mục này theo `TASK.md`.
- **Chưa biên dịch, chưa chạy, chưa đối chiếu với EX5 gốc.** Đây là bản đề xuất;
  Codex tự kiểm, biên dịch và so với bằng chứng gốc trước khi ghép. Không gọi khối
  này hay bot là hoàn tất.
- Tệp đã đọc: `TASK.md`; `Bot3EntryProfiles.mqh`, `Bot3DistanceSettings.mqh` hiện
  hành (chỉ lấy tên trường/kiểu); `tai-lieu-cu/QUY-TRINH.md` (AGENTS.md bắt buộc
  đọc quy trình trước khi viết mã; tệp này không có thuật toán).
- Không đọc EX5, mã máy, thư mục phân tích, SPEC nháp `preparation-full-r1/r2`.
  Không gọi `Bot3PrepareDistances`, không include `Bot3DistanceSettings.mqh`.
  Không sửa nguồn chính/Git/MT5, không chạy lệnh, không tạo tác tử, không viết bộ
  kiểm (không được giao).
- Cấu hình lượt này: môi trường ghi mô hình `claude-opus-5-5`; phiên báo ultracode
  bật. Tôi không thấy mức suy luận nên chưa tự xác nhận được mức `max`; Codex kiểm
  cấu hình thực tế. Không dùng tác tử con vì mô tả cấm tạo tác tử.
- Tệp chỉ biên dịch được khi đặt cạnh `Bot3EntryProfiles.mqh` trong
  `Include/bot-cua-toi-3/`.

## Sai khác duy nhất so với mô tả

| Mô tả | Mã | Lý do |
|---|---|---|
| `const Bot3PreparationInputs &input` | `const Bot3PreparationInputs &inputs` (`Bot3Preparation.mqh:143-146`) | `input` là từ khóa dành riêng của MQL5 (cùng nhóm `extern`/`static`), không đặt làm tên tham số được. Kiểu, thứ tự, `const &` giữ nguyên; bên gọi không đổi. |

## Giao diện

- `Bot3PreparationInputs` (54 trường): `symbol, comment, indicator_timeframe,
  indicator_period, reference, variable_distances, adjust_lots, entry` + 40 trường
  của bảng chép đầu + 6 trường bảng cuối, đúng kiểu cột đầu; mọi cờ là `uchar`.
- `Bot3PreparationState` (71 trường): 11 trường chung (`indicator_handle,
  indicator_values[], strategy_index, tick, calendar, scale, lot_scale, point,
  unit, spread, comment`) + 50 trường bảng đầu + 6 trường bảng cuối +
  `stop_min_price, freeze_min_price, expiration_seconds, expiration`.
  Không có `symbol`, không có trường trùng.
- `Bot3EntryProfile.confirmation_frame` có trong struct hiện hành nhưng không dùng
  (mô tả không có).

## Thứ tự gọi dịch vụ (đường đi đầy đủ)

1. Đọc `indicator_timeframe`, `indicator_period` vào biến cục bộ →
   `iATR(symbol,(ENUM_TIMEFRAMES)frame,period)`.
2. `GetLastError()` + `Print` chỉ khi handle < 0.
3. `CopyBuffer(handle,0,0,100,indicator_values)` → `ArraySetAsSeries(...,true)` →
   `ArraySize(...)`.
4. `iOpen(symbol,PERIOD_D1,1)` chỉ khi `reference>=1000.0`.
5. `SymbolInfoTick(symbol,tick)` (+ `Print("Tick not ok")` khi false) →
   `TimeCurrent(calendar)`.
6. `SYMBOL_POINT` lần 1 → `SYMBOL_DIGITS` lần 1; lần 2 chỉ khi lần 1 ≠ 3; lần 3 luôn
   (so `==1`) → ghi `spread` → `SYMBOL_DIGITS` thêm một lần, bỏ kết quả.
7. `SYMBOL_POINT` để so với `candidate`; thêm một lần `SYMBOL_POINT` khi
   `candidate` nhỏ hơn.
8. `SYMBOL_TRADE_STOPS_LEVEL` → `SYMBOL_POINT`; `SYMBOL_TRADE_FREEZE_LEVEL` →
   `SYMBOL_POINT`.
9. `TimeCurrent()` không tham số, chỉ khi `state.expiration_hours>=1`.

Mọi lời gọi dùng `inputs.symbol` đọc tại chỗ; trường của `inputs` được đọc ngay câu
dùng, không chụp cả struct. Chỗ phải đọc sau dịch vụ được tách câu để không phụ
thuộc thứ tự tính toán hạng: `sample` rồi `reference` (`:169-170`),
`current_point` rồi `state.unit` (`:253-254`), `now` rồi `expiration_seconds`
(`:300-301`).

## Output theo thứ tự ghi

| Bước | Trường ghi | Điều kiện |
|---|---|---|
| A1 `:151` | `indicator_handle` | luôn |
| A2 `:157-159` | `indicator_values` (do CopyBuffer), cờ series | cờ series chỉ khi `copied!=0` |
| A5 `:172-176` | `scale` → `lot_scale` → `scale=1.0` | `lot=1.0/state.scale` khi `adjust_lots!=0`; `scale=1.0` khi `scale==0.0` (NaN giữ nguyên) |
| B `:178-187` | `strategy_index`, `tick`, `calendar`, `point`, `unit`, `spread` | `unit=state.point*10.0` khi Digits lần 1 ==3 hoặc lần 2 ==5; `state.point/10.0` khi lần 3 ==1 |
| C `:191-241` | 50 trường bảng đầu đúng thứ tự | `scale` chụp một lần `:191`; `locked_distance=scale*locked_distance` |
| 11 `:242-249` | `comment`, chụp `candidate`, 6 trường bảng cuối | |
| D12 `:251-255` | `min_change` | `candidate<POINT` |
| D13 `:256-259` | `stop_min_price`, `freeze_min_price` | `(double)long*POINT` của lần đọc ngay sau |
| D14 `:260-273` | `stop_distance=1.0`, `target_distance=1.0`, `locked_distance=trigger_distance+0.1` | `<=0.0`; `trigger<locked` |
| D15 `:274-276` | `freeze_buffer=(int)freeze_units` (cắt phần lẻ) | `(double)freeze_buffer<freeze_units` |
| D16 `:277-280` | `trail_distance` (tối đa 2 lần) | `!=0.0` và nhỏ hơn `freeze_units`; rồi `!=0.0` và nhỏ hơn `stop_min_price/unit` |
| D17 `:281-287` | `native_6d5f0` (tối đa 2 lần) | `native_6d5e8>0.0` và nhỏ hơn từng mốc |
| D18 `:288-291` | `stop_distance`, `target_distance`, `gap_points` = `twice_stop` | so với `stop`/`target` cục bộ và `state.gap_points` |
| D19 `:292-294` | `older_width=1`, `recent_width=1`, `gap_points=0.1` | `<1`, `<1`, `<0.1` |
| D20 `:296-304` | `expiration_seconds` (uint, tràn 32 bit), `expiration` | `expiry` khi `state.virtual_expiration==0`, ngược lại 0 |

## Nhánh trả sớm và lỗi giữ nguyên

| Chỗ | Điều kiện | Kết quả | Đã ghi trước đó |
|---|---|---|---|
| A1 `:152-156` | `indicator_handle<0` | Print + `GetLastError()`, return | `indicator_handle` |
| A2 `:158` | `copied==0` (không dùng `<=0`) | return, chưa đặt series | + `indicator_values` do CopyBuffer để lại |
| A3 `:160-165` | `ArraySize<2` | đọc `indicator_values[1]` → lỗi chỉ mục dừng chương trình; `scale` chưa ghi | + cờ series |
| A4 `:170` | chia cho `reference` đọc lại | không chặn; nếu 0 → lỗi chia 0, `scale` chưa ghi | như A3 |
| A5 `:174` | `adjust_lots!=0` và `scale==0.0` | lỗi chia 0, `lot_scale` chưa ghi | + `scale` |
| D12 `:254` | `candidate<POINT` và `unit==0.0` | lỗi chia 0, `min_change` chưa ghi lại | A, B, C |
| D15 `:275` | `unit==0.0` | lỗi chia 0 trước mọi ghi của bước 15 | + D12–D14 |

Giữ nguyên dù trông thừa: `return;` sau lệnh đọc ô `[1]`; `copied<0` vẫn chạy tiếp;
tick lỗi vẫn chạy tiếp; bỏ giá trị trả về của `TimeCurrent(calendar)` và lần Digits
cuối; nhánh `native_6d5e8>0.0` dù trường vừa đặt `+0.0`. Không ZeroMemory/reset
state, không thêm GetLastError, không IndicatorRelease, không kiểm `copied<100` hay
`iOpen==0`, không MathMax/MathRound, không kiểm cấp phép.

## Codex cần kiểm

1. Biên dịch: có thể có cảnh báo bỏ giá trị trả về ở `TimeCurrent(state.calendar)`
   `:180`, `SymbolInfoInteger(...,SYMBOL_DIGITS)` `:189` hoặc `ArraySetAsSeries`
   `:159`; nếu có, giữ lời gọi.
2. Hành vi MQL5 mã dựa vào, chưa kiểm: đọc ngoài mảng và chia `double` cho 0 là
   lỗi nghiêm trọng làm dừng chương trình; các phép so `>=, <, <=, >, !=` với NaN
   phải sinh mã giống bản gốc; kết quả `(int)freeze_units` khi NaN/vô cực/ngoài
   khoảng int32.
3. Digits dùng `if/else if` (`:184-186`) để số lần gọi đúng mô tả mà không dựa vào
   `||`. `&&` ở D16 không có tác dụng phụ.
4. Mỗi lần chạy đều gọi `iATR` và không giải phóng handle — theo mô tả, cần so với
   bản gốc.
