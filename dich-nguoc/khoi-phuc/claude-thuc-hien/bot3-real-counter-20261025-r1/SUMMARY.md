# Bot3ManagementRealCounter — tóm tắt

Ngày 25/10/2026. Đây là bản đề xuất: **chưa biên dịch, chưa chạy, chưa so với EX5 gốc**.
Mã viết theo đặc tả trong `TASK.md` (trùng nội dung yêu cầu của người dùng).
Không đọc EX5, mã máy hay bản phân tích cũ.

## Tệp và giao diện

- `Bot3ManagementRealCounter.mqh`, guard `BOT3_MANAGEMENT_REAL_COUNTER_MQH`, hai hàm `void`:
  `Bot3AdvanceRealCounterBuyStop` (dòng 6–42) và `Bot3AdvanceRealCounterSellStop` (dòng 45–77).
- Hai hàm cùng chữ ký đúng đặc tả: 17 tham số, cùng thứ tự; chỉ `selected_anchor` và `ticket`
  truyền theo giá trị, còn lại là tham chiếu.
- Include đường dẫn tương đối, chỉ một tệp: `Bot3ManagementPrelude.mqh`. Thư mục đề xuất này
  không có tệp đó, nên phải chép vào `source/MQL5/Include/bot-cua-toi-3/` rồi mới biên dịch.
- Dùng hàm/kiểu có sẵn, không sửa: `Bot3RoundPrice`, `Bot3ModifyPosition`,
  `Bot3ManagedPosition`, `Bot3PendingRequestState`, `Bot3TradeSendOptions` (lấy qua Prelude).
- Tên biến giữ như đặc tả: `quote`, `u`, `product`, `candidate`, `new_sl`; riêng `off` đặt là `offset`.

## Lời gọi API trong hàm

Mỗi hàm có đúng 3 lời gọi tới MT5/giao dịch, theo thứ tự; mỗi lời chỉ chạy khi tới được bước đó:

1. `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` → `digits1` (khi cổng 2, 3, 4 đạt)
2. `SymbolInfoInteger(symbol,SYMBOL_DIGITS)` → `digits2` (khi cổng 5 đạt, sau `counter=0`)
3. `Bot3ModifyPosition(state,options,ticket,position.sl,position.tp)` (sau khi ghi SL mới)

`Bot3RoundPrice` gọi 2 lần (`candidate`, `new_sl`); đây là hàm tính có sẵn, không hỏi MT5.
Không có `SymbolInfoDouble` (không POINT), `SymbolInfoTick`, `NormalizeDouble`, `Print`,
`GetLastError`, báo lỗi, khối lượng, đóng lệnh, Stamp hay mảng. Chọn vị thế chỉ có bên trong
`Bot3ModifyPosition` có sẵn.

## Bộ đếm `counter`

- Chỉ ghi ở 2 chỗ: tăng `counter=(int)((uint)counter+1)` (dòng 17/56) và `counter=0` (dòng 35/71).
- Tăng ngay sau bước 1, trước mọi cổng; cổng sau sai vẫn giữ giá trị đã tăng.
- `changed` đã `true` hoặc `enabled!=1`: thoát trước khi tăng, `counter` không đổi.
- Cổng 4 so `counter<minimum_steps` kiểu `int` có dấu, dùng giá trị đã tăng.
- `counter=0` đặt ngay trước DIGITS2. Sau đó hàm không ghi `counter` nữa: nếu DIGITS2 làm
  `counter` đổi thì giữ giá trị đó, không đặt `0` lần hai.
- Theo công thức (chưa chạy): `2147483647` → `-2147483648`, `-1` → `0`.

## Thứ tự đọc/ghi trong mã (hàm mua)

| Bước | Thứ tự trong mã (dòng) | Đọc tại đây | Ghi | Sai thì |
|---|---|---|---|---|
| 1 | `if(changed) return;` (15) → `if(enabled!=1) return;` (16) → tăng `counter` (17) | `changed`, `enabled`, `counter` | `counter` | thoát |
| 2 | chụp `quote=tick.bid` (19), `u=unit` (20); `product=step_distance*u` (21); cần `(product+position.sl)+gap<quote` (22), rồi `quote<position.tp-freeze` (23) | `tick.bid`, `unit`, `step_distance`, `position.sl`, `gap`, `position.tp`, `freeze` | biến cục bộ | thoát |
| 3 | nếu `reference_setting!=0.0` (25): `offset=u*copied_step` (27); cần `selected_anchor+offset<quote` (28) | `reference_setting`, `copied_step`, `selected_anchor`; `u`, `quote` đã chụp | biến cục bộ | thoát |
| 4 | thoát nếu `counter<minimum_steps` (30) | `counter` đã tăng, `minimum_steps` | — | thoát |
| 5 | `digits1` (31) → `candidate=Bot3RoundPrice(step_distance*unit+position.sl,digits1)` (32); cần `position.sl<candidate` (33) | `step_distance`, `unit` đọc lại sau DIGITS1; `position.sl` cũ | — | thoát, không đặt lại `counter`/SL/`changed` |
| 6 | `counter=0` (35) → `digits2` (36) → `new_sl=Bot3RoundPrice(position.sl+step_distance*unit,digits2)` (37) → `position.sl=new_sl` (38) | `step_distance`, `unit` đọc lại sau DIGITS2; `position.sl` cũ | `counter`, `position.sl` | — |
| 7 | `Bot3ModifyPosition(...)` (40), bỏ kết quả → `changed=true` (41) | `ticket`, `position.sl` mới, `position.tp` | `state` (trong hàm có sẵn), `changed` | — |

Hàm bán khác hàm mua ở các chỗ sau; bước 1, 4, 7 giống hệt (dòng 54–56, 67, 75–76):

| Bước | Hàm bán (dòng) |
|---|---|
| 2 | `quote=tick.ask` (57); cần `quote<(position.sl-product)-gap` (60), rồi `freeze+position.tp<quote` (61) |
| 3 | cần `quote<selected_anchor-offset` (65) |
| 5 | `candidate=Bot3RoundPrice(position.sl-step_distance*unit,digits1)` (69); cần `candidate<position.sl` (70) |
| 6 | `counter=0` (71) → `digits2` (72) → `new_sl=Bot3RoundPrice(position.sl-step_distance*unit,digits2)` (73) → `position.sl=new_sl` (74) |

## Kết quả theo nhánh

| Thoát tại | `counter` | `position.sl` | `changed` | Lời gọi đã chạy |
|---|---|---|---|---|
| Bước 1: `changed` đã `true` | không đổi | không đổi | `true` | không |
| Bước 1: `enabled!=1` | không đổi | không đổi | `false` | không |
| Cổng 2, 3 hoặc 4 sai | +1 (tràn 32 bit) | không đổi | `false` | không |
| Cổng 5 sai | +1; hàm không ghi thêm | không đổi | `false` | DIGITS1 |
| Tới cuối, sửa đạt | `0`, hoặc giá trị DIGITS2 ghi | `new_sl` | `true` | DIGITS1, DIGITS2, Modify |
| Tới cuối, sửa sai | như trên | `new_sl` | `true` | DIGITS1, DIGITS2, Modify |

Hàm không trả giá trị; đầu ra chỉ là `counter`, `position.sl`, `changed` và phần `state`
do `Bot3ModifyPosition` có sẵn ghi. Không sửa `position.tp`, `position.open_price`, `tick`
hay tham số cài đặt.

## Ghi chú kỹ thuật

- Cổng số thực viết dạng `if(!(a<b)) return;`, nên NaN làm cổng sai và hàm thoát (nếu MQL5
  so `<` theo IEEE; xem mục kiểm 3). So chặt: hai bên bằng nhau là sai.
- Cổng mốc dùng `reference_setting!=0.0`: `+0.0`, `-0.0` bỏ cổng; số khác 0 và NaN vào cổng
  (theo IEEE; cần đo). Mốc so luôn là `selected_anchor` ở cả hai hướng, không dùng
  `reference_setting` làm mốc.
- Giữ ngoặc và thứ tự toán hạng như đặc tả: `(product+position.sl)+gap`, `position.tp-freeze`,
  `(position.sl-product)-gap`, `freeze+position.tp`, `u*copied_step`, `selected_anchor+offset`,
  `selected_anchor-offset`. Hàm mua: bước 5 `step_distance*unit+position.sl`, bước 6
  `position.sl+step_distance*unit` (khác thứ tự có chủ ý). Không rút gọn biểu thức.
- `quote`, `u` chụp trước mọi API và chỉ dùng ở cổng 2, 3. Bước 5 và 6 đọc lại `step_distance`,
  `unit` ngay sau từng lần DIGITS, không dùng `product` hay `u`.
- Không đọc `tick` sau API; không có cổng gap/freeze sau làm tròn.
- `position.sl` chỉ do hàm này ghi (dòng 38/74), nên ở bước 5, 6 `position.sl` vẫn là SL cũ.
- Gọi `Bot3ModifyPosition` bỏ kết quả, giống cách Prelude gọi trong `Bot3FillManagementInitialLevels`.
- Đã dò bằng Grep: tệp không có `NormalizeDouble`, `SYMBOL_POINT`, `SymbolInfoDouble`,
  `SymbolInfoTick`, `Print`, `GetLastError`, `TODO`, `open_price`, `volume`, `Stamp`, `[`.
  Ghi `counter` chỉ ở dòng 17, 35, 56, 71; ghi `position.sl` chỉ ở dòng 38, 74.
  Đây là dò chữ, không phải biên dịch.

## Cần Codex kiểm

1. Biên dịch sau khi chép vào thư mục include; ghi lỗi và cảnh báo (chú ý `(uint)counter+1`
   và lời gọi `Bot3ModifyPosition` bỏ kết quả).
2. Phép ép `(int)` của `uint` từ 2^31 trở lên có ra số âm (không bão hòa) không:
   ca `counter=2147483647` và `counter=-1`.
3. MQL5 so `<`, `!=` với NaN có theo IEEE không; ca NaN ở `tick.bid`/`tick.ask`, `unit`,
   `step_distance`, `gap`, `freeze`, `copied_step`, `selected_anchor`, `reference_setting`.
   `Bot3RoundPrice` với NaN phụ thuộc phép ép `(long)` trong hàm có sẵn. Cần đo thật.
4. Ca `reference_setting` bằng `+0.0`, `-0.0` (bỏ cổng mốc), khác 0, NaN.
5. Ca sát ngưỡng ở từng cổng (bằng nhau phải sai) và `counter` vừa bằng `minimum_steps`.
6. Ca `Bot3ModifyPosition` trả `false`: vẫn `counter=0`, SL mới, `changed=true`, không báo lỗi.
7. Theo IEEE, `a+b` và `b+a` cho cùng giá trị số, nên khác thứ tự ở bước 5/6 của hàm mua
   chỉ có thể lộ ra qua NaN. Cần đo nếu muốn phân biệt.
8. So thứ tự lời gọi (DIGITS 2 lần, sửa SLTP) và từng nhánh với EX5 gốc.

## Cấu hình phiên

- Mô hình theo thông tin phiên: Opus 5.5 (`claude-opus-5-5`); phiên báo Ultracode bật.
  Mức `max` không tự kiểm được từ trong phiên.
- Phiên không có công cụ Workflow, và đề bài cấm chạy lệnh/tác tử khác, nên làm một mình;
  chỉ ghi hai tệp trong thư mục này.
- Đã đọc: `TASK.md`; giao diện trong nguồn chính (`Bot3ManagementPrelude.mqh`,
  `Bot3PositionModify.mqh`, 20 dòng đầu `Bot3PriceLevels.mqh`); mẫu cách viết
  (`Bot3ManagementRealTimed.mqh`, `bot3-real-take-buy-20261025-r1/SUMMARY.md`); 140 dòng đầu
  `QUY-TRINH.md` theo yêu cầu của `AGENTS.md`. Grep tìm định nghĩa trong thư mục include có
  hiện vài dòng gọi hàm của các tệp khác; không dùng các dòng đó để lấy thuật toán.
- Đã tự rà mã với 7 bước đặc tả bằng cách đọc lại; đây không phải phép kiểm bằng máy.
