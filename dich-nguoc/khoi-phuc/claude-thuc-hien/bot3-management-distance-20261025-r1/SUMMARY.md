# Tóm tắt — ứng viên phần B `Bot3AdvanceDistanceVirtualStop` bot 3 (r1)

Trạng thái thật: **chỉ là ứng viên. Chưa biên dịch, chưa chạy kiểm, chưa so
với EX5 gốc; không có số ca đạt.** Chỉ ghi hai tệp mới trong thư mục này
(`TASK.md` giữ nguyên). Không chạy lệnh, Git, MT5; không sửa nguồn chính
`bot-cua-toi-3/source/`; không đụng thư mục phần A/C.

## Nguồn đã đọc

- [contract r1](../../bot-cua-toi-3/phan-tich/dong-vi-the/management-virtual-20261025-r1/contract.md):
  chỉ dòng 1–23 (đầu tệp, phần chung) và 48–87 (phần B). Không đọc phần A,
  phần C và mục "Kiểm còn phải làm".
- [Prelude r2](../bot3-management-prelude-20261025-r2/Bot3ManagementPrelude.mqh)
  và SUMMARY của nó.
- Helper bot 3 hiện hành trong `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`:
  `Bot3PriceLevels`, `Bot3PositionClose`, `Bot3PositionModify`,
  `Bot3TradeSend`, `Bot3PendingRequest`, `Bot3VirtualStops`,
  `Bot3ManagementAnchor`; và [QUY-TRINH.md](../../tai-lieu-cu/QUY-TRINH.md)
  theo AGENTS.md.
- Không đọc EX5, C, mã máy hay capture.

## Quy tắc đã giữ

Số dòng là dòng trong [Bot3ManagementDistanceStop.mqh](Bot3ManagementDistanceStop.mqh).

| Quy tắc trong mô tả | Mã |
|---|---|
| Hàm `bool`, 20 tham số đúng thứ tự/kiểu của mô tả (kể cả `bool buy` không `const`; `anchor`, `ticket` truyền giá trị) | :9–17 |
| `!(0.0<trail_distance)` → false, chưa gọi API nào | :19 |
| Chụp `level=current_level` rồi `quote=buy?tick.bid:tick.ask` trước API POINT | :20–22 |
| Sau API: `trail=trail_distance`; `u=unit` (U, đọc một lần); `offset=(trail_step+trail)*u` | :23–25 |
| Mua: (1) `offset+(level+point)<quote` dùng giá trị đã chụp; (2) `trail_start*u+anchor<tick.bid` đọc lại tick; (3) `current_level<trail_limit*u+position.open_price` đọc lại mốc; đủ thì `current_level=tick.bid-trail*u` | :28–31 |
| Bán: `quote<((level-point)-offset)`; `tick.ask<(anchor-trail_start*u)`; `(position.open_price-trail_limit*u)<current_level`; đủ thì `current_level=trail*u+tick.ask` | :35–38 |
| So có thứ tự: viết `!(a<b)`, `!(a<=b)` nên NaN làm điều kiện hỏng; không đổi thành `>=`/`>` | :19, :28–30, :35–37, :42, :44 |
| Biểu thức giữ đúng thứ tự và ngoặc của mô tả; không làm tròn hay nắn giá thêm | :25, :28–31, :35–38 |
| `volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2)` rồi mới `changed=true`; giữ nguyên `*0.0`; không chặn/chỉnh chỉ số | :40–41 |
| Chỉ khi `volume<position.volume` mới đọc `SYMBOL_VOLUME_MIN` | :42–43 |
| `minimum<=volume` → `Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,ticket)` (0x47d20) rồi true; mọi đường khác trả false | :44–46 |
| Thoát sớm thì `current_level`, `changed` không đổi; không có chỗ nào đặt `changed=false` | :19–37 |
| Không có điều kiện chốt lời; `ticket` nhận riêng, không tính từ `position` | toàn hàm, :17 |
| Dùng `Bot3RoundPrice`, `Bot3TryClosePosition` có sẵn, không viết lại | :40, :45 |

## Điểm mô tả còn thiếu (Codex cần chốt)

1. **API POINT**: mô tả không ghi dạng gọi. Mã dùng
   `SymbolInfoDouble(symbol,SYMBOL_POINT)` (dạng trả double, cùng `symbol`
   như lời gọi VOLUME_MIN mà mô tả ghi rõ). Nếu gốc khác thì sửa :22.
2. **Khi một điều kiện hỏng**: mô tả chỉ ghi "nếu đủ thì cập nhật". Mã trả
   false ngay, không tính volume, không đặt cờ. Căn cứ: phần chung "changed
   giữ nguyên khi không có tác động" và phần B "không gọi helper thì false".
   Nếu gốc vẫn tính volume/đặt cờ khi không dời mốc thì phải sửa khối :26–39.
3. **Nguồn đối số khi ghép**: B không ghi `anchor` là mốc H (stack
   mua+0x78/bán+0x88) hay R (xmm15); không ghi nơi lưu `current_level`;
   không ghi nguồn `symbol`, `deviation`, `state`, `options`.
4. `ticket`: B ghi là ulong lấy từ ticket_number qua long ở phần mốc. Có thể
   ứng với `Bot3ManagementAnchorState.ticket` (`Bot3ManagementAnchor.mqh`
   :11, :25); tôi chỉ so tên, chưa kiểm.

## Chưa kiểm

- Biên dịch MetaEditor (mục tiêu 0 lỗi, 0 cảnh báo): chưa. Cần xem riêng:
  truyền `tick.bid`/`tick.ask` (thành viên của `MqlTick &`) vào
  `const double &` của helper; chỉ số `uint` với `const double &volumes[]`;
  hằng `2` cho tham số `uint digits`.
- MQL5 có giữ `x*0.0` (NaN, -0.0), thứ tự cộng/nhân (không gộp, không FMA)
  và so có thứ tự với NaN đúng như mã viết hay không.
- Chưa có bộ kiểm; chưa so với đoạn máy gốc.

Ca kiểm nên có (thay API bằng hàm giả; tôi chưa đọc danh sách ca của Codex):

- `trail_distance` 0/âm/NaN → false, 0 lần gọi API, mốc và cờ không đổi.
- Hàm giả POINT đổi `tick`, `trail_distance`, `unit`, `current_level` trong
  lúc gọi: điều kiện (1) dùng `level`/`quote` cũ nhưng `trail`/`u` mới;
  (2), (3), phép cập nhật và helper dùng giá trị mới.
- Từng điều kiện: hai vế bằng nhau (phép `<` thì hỏng, `minimum<=volume`
  thì qua), lệch 1 ULP, NaN ở từng biến; cả mua và bán; `changed` vào là
  true và false.
- `volumes[i]` dương, âm, ±Inf, NaN; `position.volume` 0/âm/NaN;
  VOLUME_MIN dương, 0, âm, NaN.
- Chặn ở `Bot3TryClosePosition`, không ở `Bot3ClosePosition`; kiểm đủ 8 đối
  số và giá trị trả.
- Chỉ dùng chỉ số mảng hợp lệ.

## Quan sát (suy từ mã, chưa chạy; không sửa)

Theo `Bot3RoundPrice` (`Bot3PriceLevels.mqh` :7–16), `volumes[i]` hữu hạn
cho `volume=0.0`; ±Inf/NaN cho NaN (nếu MQL5 đổi NaN sang `long` thành
`LONG_MIN`, nhánh :10). Vậy helper chỉ được gọi khi VOLUME_MIN ≤ 0. Với
VOLUME_MIN > 0, hàm chỉ dời mốc, đặt cờ và trả false. Helper đóng cả
`POSITION_VOLUME` (`Bot3PositionClose.mqh` :26), không dùng `volume`.
Đây là hành vi theo mô tả, giữ nguyên. Bộ kiểm cần hàm giả VOLUME_MIN ≤ 0
mới tới được nhánh helper.

## Phụ thuộc

- `Bot3ManagementPrelude.mqh` r2: `Bot3ManagedPosition` (`open_price`,
  `volume`). Qua include của nó: `Bot3PriceLevels.mqh` (`Bot3RoundPrice`),
  `Bot3PositionClose.mqh` (`Bot3TryClosePosition` → `Bot3ClosePosition`),
  `Bot3TradeSend.mqh` (`Bot3TradeSendOptions`), `Bot3PendingRequest.mqh`
  (`Bot3PendingRequestState`).
- Include tương đối: phải đặt tệp này cạnh Prelude và các `.mqh` bot 3
  trong `Include/bot-cua-toi-3/` mới biên dịch được.
- API MT5: `SymbolInfoDouble` (POINT, VOLUME_MIN); helper còn gọi
  `PositionSelectByTicket`, `PositionGet*`, `OrderSend`/`OrderSendAsync`.
- Tệp chỉ định nghĩa một hàm và guard riêng `BOT3_MANAGEMENT_DISTANCE_STOP_MQH`.

## Cấu hình phiên

Thông tin hệ thống ghi model `claude-opus-5-5` và "Ultracode is on"; mức
`max` không tự kiểm được từ trong phiên. Phiên không có công cụ Workflow
hay tác tử phụ; chỉ dùng Read/Grep/Glob/Write và tự rà từng mục mô tả với mã.
