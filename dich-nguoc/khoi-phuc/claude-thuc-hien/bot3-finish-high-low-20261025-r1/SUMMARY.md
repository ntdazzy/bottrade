# Tóm tắt — phần A `Bot3AdvanceVirtualHighLow`, bot 3 (r1)

Trạng thái thật: **chỉ là đề xuất. Chưa biên dịch, chưa chạy, chưa so với
EX5 gốc; chưa có ca kiểm nào.** Chỉ ghi [part.mqh](part.mqh) và tệp này
(`TASK.md` giữ nguyên). Không sửa `bot-cua-toi-3/source/`, bằng chứng cũ,
thư mục phần B/C, Git hay cài đặt. Không chạy lệnh, MT5, không gọi tác tử phụ.

## Nguồn đã đọc

- `AGENTS.md`, `tai-lieu-cu/QUY-TRINH.md`, `TASK.md`.
- [contract.md](../../bot-cua-toi-3/phan-tich/dong-vi-the/management-virtual-finish-20261025-r1/contract.md):
  tệp ngắn nên đã đọc cả 137 dòng; mã chỉ theo dòng 9–35 (chung) và
  37–66 (phần A). Không viết phần B, C hay vòng quản lý bên ngoài.
- Kiểu dữ liệu: `Bot3ManagementPrelude.mqh` (`Bot3ManagedPosition`).
  Đã xem `Bot3VirtualStops.mqh`, `Bot3PriceLevels.mqh`; phần A không cần.
  Cách viết theo `Bot3ManagementVirtual*.mqh` trong Include bot 3.
- Chỉ đọc để theo định dạng: SUMMARY lượt virtual-start và slippage,
  `bot3-nan-review-20261025-r1/REVIEW.md` (thứ tự toán hạng khi hai NaN),
  đề xuất timed-stop, và `TASK.md` phần B (để dùng cùng guard struct).
- Đối chiếu hợp đồng với lệnh gốc trong `management-20261025-r1/analysis.json`:
  dòng 15900–16697 (mua 0x3660b..0x3692e), 35100–35679 (bán 0x3a8fd..0x3ab24);
  tìm mọi lệnh nhảy vào vùng A và mọi lệnh ghi `xmm7`; `native-guards.txt`
  dòng 35–45 (thanh ghi cố định của hàm mua). Không dùng mã C dịch ngược.

Kết quả đối chiếu: hợp đồng phần A khớp lệnh gốc ở mọi bước dưới đây;
không thấy chỗ nào cần sửa mô tả.

## Từng bước: mã ↔ lệnh gốc

Địa chỉ đã trừ base 0x17156250000. Số dòng là dòng trong `part.mqh`.

| Bước | Mua | Bán | Mã |
|---|---|---|---|
| Cổng `high_low_enabled>0` (int có dấu) | 0x36671 `cmp dword,0` + `jg` 0x36674 / `jmp` 0x3667a; giống ở 0x36740/0x36743 và 0x36827/0x3682a | 0x3a987 + `jle` 0x3a98a | :40 |
| 1. Đọc chỉ số (32 bit, mở rộng 0 = uint32), P, level1, gap trước POINT | 0x36770, 0x36773, 0x3677b, 0x3678c | 0x3a9b7, 0x3a9ba, 0x3a9c2, 0x3a9d3 | :41–43 |
| POINT lần 1 | 0x3679b | 0x3a9e2 | :44 |
| Mua `(P+gap)+point<level1`; bán `level1<(P-gap)-point` | 0x3679d, 0x367a3 + `jbe` | 0x3a9e4, 0x3a9e9 + `jbe` | :45 |
| 2. Đọc lại chỉ số, level2 | 0x367ae, 0x367b1 | 0x3a9f4, 0x3a9f7 | :46 |
| Mua `level2<open`, bán `open<level2`; nếu không thì cần `(before_open&1)==0` | 0x367b8 `ucomisd xmm6,xmm8` + `ja`; 0x367c9 `test byte,1` + `jne` | 0x3a9fe `ucomisd xmm8,xmm6` + `ja`; 0x3aa0f + `jne` | :47–48 |
| 3. `k = shift==0 ? +0.0 : hằng mua/bán` | 0x367dc; 0x367e1 `xorpd`; 0x36866 đọc 0x58488 | 0x3aa22; 0x3aa27 `xorpd`; 0x3aa5f đọc 0x584b0 | :49–50 |
| `offset=k*unit` (luôn nhân, kể cả k=0) | 0x3688a | 0x3aa84 | :51 |
| Chụp quote (bid/ask), rồi gap, trước POINT 2 | 0x3688e, 0x368a2 | 0x3aa93, 0x3aa98 | :52–53 |
| Mua `limit=(bid-offset)-gap`; bán `limit=(offset+ask)+gap` | 0x3689d, 0x368a2 | 0x3aa93, 0x3aa98 | :53 |
| POINT lần 2 | 0x368b1 | 0x3aaa7 | :54 |
| Mua `level2<limit-point`; bán `limit+point<level2`; level2 không đọc lại | 0x368b3, 0x368b9 + `jbe` | 0x3aaa9, 0x3aaae + `jbe` | :55 |
| 4. Đọc tick, freeze mới: mua `bid<tp-freeze`; bán `freeze+tp<ask` | 0x368c0 `movapd xmm0,xmm7`, 0x368ce, 0x368d2 + `jbe` | 0x3aabf, 0x3aac4, 0x3aac8 `addsd xmm1,xmm7`, 0x3aacc + `jbe` | :56 |
| `changed=true` (r12b) | 0x368f7 | 0x3aae6 | :57 |
| Đọc lại chỉ số, level3; `P=level3` | 0x368fa, 0x368fc, 0x3690b | 0x3aae9, 0x3aaeb, 0x3aafa | :58 |

Sáu lần đọc hợp đồng nêu (mua 3677b/3679b/367b1/3688e/368b1/368fc; bán
3a9c2/3a9e2/3a9f7/3aa93/3aaa7/3aaeb) ứng với :42, :44, :46, :52, :54, :58.

Các so sánh gốc đều là `ucomisd` + `jbe`/`ja`: NaN làm điều kiện không đạt.
Mã viết `if(!(a<b)) return;` (hoặc `!(...) && ...` ở bước 2) cho cùng kết quả.

## Thứ tự toán hạng

Giữ đúng toán hạng đầu (thanh ghi đích) như gốc, phòng khi hai NaN gặp nhau:
mua `level+gap`, `limit+point`, `shift*unit`, `(quote-offset)-gap`,
`limit-point`, `position.tp-freeze`; bán `level-gap`, `limit-point`,
`shift*unit`, `(offset+quote)+gap`, `limit+point`, `freeze+position.tp`.
Ở phần A các giá trị này chỉ đi vào phép so, nên phần trị NaN không lộ ra ngoài.

## Luồng điều khiển đã kiểm

- Lối vào mua: 0x36667 (chạy tiếp từ 0x36663); 0x36736 (nhảy từ 0x364fb,
  0x36514, 0x365cd, 0x365f3; chạy tiếp từ 0x3672c, nơi 0x36580 nhảy tới);
  0x36813 (nhảy từ 0x365a7). Cả ba cùng một phép thử cổng.
- Lối vào bán: 0x3a97d (nhảy từ 0x3a81c, 0x3a835, 0x3a8a0, 0x3a8c7,
  0x3a8e3, 0x3a911; chạy tiếp từ 0x3a979).
- Nhảy vào giữa thân A chỉ đến từ chính A (mua 0x367d2/0x3685c/0x3686a,
  bán 0x3aa18/0x3aa55/0x3aa64).
- Lối ra: mua 0x3691b (thẳng, hoặc qua 0x36911); bán 0x3aafe.
- Ghi bộ nhớ duy nhất: P 0x6d670 (0x3690b/0x3aafa). Lời gọi duy nhất: hai
  lần POINT mỗi phía. Không đổi `position`, không Modify/Print/Stamp/đóng,
  không xóa `changed`.
- Đã loại, không thuộc A: mua 0x3667f..0x36727 (thân tách đoạn khác),
  0x3672c (chỉ đặt r14), 0x367ea..0x3680e, 0x36835..0x36857 (ghi
  [rax+0x70568] và thử mode==2); bán 0x3aa2e..0x3aa50. Các lệnh nhảy từ
  ngoài vào các khối này (0x35d46→0x36835, 0x366e1→0x367ea,
  0x39fd6→0x3aa2e) không đi vào A.

## Còn chưa chắc, cần Codex kiểm

1. **Chưa biên dịch.** Include tương đối: đặt cạnh `Bot3ManagementPrelude.mqh`
   trong `Include/bot-cua-toi-3/`. Struct `Bot3VirtualFinishSettings` nằm
   trong guard `BOT3_VIRTUAL_FINISH_SETTINGS_MQH`; khi ghép với B/C cần
   chắc ba bản giống hệt nhau. Guard riêng của tệp `BOT3_VIRTUAL_HIGH_LOW_MQH`
   chỉ để thử độc lập.
2. **NaN với `<`.** Chưa đo riêng hàm này; cần xem bản biên dịch MQL5 cho
   `<` là so có thứ tự (NaN → false), như các phần trước.
3. **`0.0*unit`.** Gốc luôn nhân (0x3688a/0x3aa84 chạy cả khi k=0). Với
   `unit` NaN/vô cực, offset là NaN và bước 3 không đạt. Cần xem trình
   biên dịch không bỏ phép nhân và không gộp nhân với cộng/trừ (FMA).
4. **Chỉ số ngoài 0..8.** Gốc đọc thẳng `[bảng+index*8]` không kiểm biên
   (0x3677b/0x367b1/0x368fc, 0x3a9c2/0x3a9f7/0x3aaeb). MQL5 kiểm biên mảng
   và dừng EA khi vượt kích thước mảng truyền vào. Hợp đồng chỉ nêu 0..8
   hợp lệ; mã không thêm kiểm tra. Khác biệt chỉ có ngoài miền này.
5. **`position.tp`/`position.open_price` thay cho XMM7/XMM6.** Trong A gốc
   chỉ đọc XMM7 (0x368c0, 0x3aac8), không ghi. XMM7 được ghi ở phần đầu
   (mua 0x331e2..0x33253, 0x3366f..0x336e4), ở nhánh dời chốt thật (mua
   0x347a2..0x34818, bán 0x38cde..0x38d49; chốt mới vào `xmm2` cho Modify
   0x3485f/0x38d80) và trong phần B (0x36acd, 0x3acb5). Vòng ngoài phải bảo đảm `position.tp` lúc vào A
   bằng XMM7 gốc; tôi chưa lần hết mọi đường tới A.
6. **Dạng gọi POINT.** Dùng `SymbolInfoDouble(symbol,SYMBOL_POINT)` trả
   `double`, như Include hiện có. Gốc gọi 0x7ff6846e2890 với r8d=0x10, đọc
   kết quả ở ô 0x17156426e48 (mua qua r13 đặt ở 0x3307c/0x33479; bán qua r14
   đặt ở 0x376a6/0x37a6e/0x37abd). Không tự kiểm ánh xạ hàm runtime.
7. **Thanh ghi cho phần B.** Gốc đặt r14=0x74838 ở 0x368d7/0x36911 trước khi
   sang B. Đây chỉ là địa chỉ, không ghi bộ nhớ; mã MQL5 không cần thể hiện.

## Ca kiểm đề xuất

- Cổng: `high_low_enabled` 0, 1, -1, INT_MIN, INT_MAX.
- `before_open` 0, 1, 2, 3, 255 (chỉ bit 0 có tác dụng); `shift` 0, 1, 255.
- Hằng shift 0, -0, âm, NaN, vô cực; `unit` NaN/vô cực khi shift=0.
- Mỗi phép so: hai vế bằng nhau (phải thoát), lệch nhỏ nhất hai phía, NaN ở
  P, level, gap, point, bid/ask, freeze, tp, open.
- Hàm giả API đổi dữ liệu trong lúc gọi POINT: P/level1/gap dùng giá trị
  trước POINT 1; chỉ số + level2 lấy sau POINT 1; unit/quote/gap lấy trước
  POINT 2; level2 không đọc lại; tick/freeze lấy sau POINT 2; chỉ số + level3
  lấy lúc ghi P.
- `changed` vào true/false đều giữ nguyên ở mọi lối thoát sớm; `position`
  không đổi; không có lời gọi giao dịch hay Print.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`; hệ thống báo bật
"Ultracode". Phiên không có công cụ Workflow và TASK cấm tác tử phụ, nên
làm một mình bằng Read/Grep/Glob/Write. Không tự kiểm được mức `max`.
