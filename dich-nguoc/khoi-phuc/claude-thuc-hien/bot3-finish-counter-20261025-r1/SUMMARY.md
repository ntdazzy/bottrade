# Tóm tắt — phần B `Bot3AdvanceVirtualBreakEvenCounter`, bot 3, r1

Trạng thái thật: **chỉ là đề xuất. Chưa biên dịch, chưa chạy, chưa so với
EX5 gốc; chưa có ca kiểm nào.** Chỉ ghi hai tệp trong thư mục này:
[part.mqh](part.mqh) và tệp này. Không sửa nguồn chuẩn, bằng chứng cũ,
việc khác, Git hay cài đặt. Không chạy Bash/PowerShell/MT5, không gọi
tác tử con. Không viết phần A, C hay vòng quản lý bao ngoài.

## Nguồn đã đọc

- `AGENTS.md`, `tai-lieu-cu/QUY-TRINH.md`.
- [contract.md](../../bot-cua-toi-3/phan-tich/dong-vi-the/management-virtual-finish-20261025-r1/contract.md):
  phần chung (dòng 1–35), phần B (68–103), phần bao ngoài (129–136).
- Kiểu: `Bot3ManagementPrelude.mqh` (`Bot3ManagedPosition`),
  `Bot3VirtualStops.mqh`, `Bot3PriceLevels.mqh` (phần B không làm tròn).
- Lệnh máy gốc trong `management-20261025-r1/analysis.json` (EX5 SHA-256
  ee063d3d…2feb83, base 0x17156250000): mua 0x3691b..0x36b19 và
  0x36f72..0x36fd4; bán 0x3aafe..0x3ad01 và 0x3b162..0x3b1c7. Không dùng
  `functions.c` (mã giải ngược).
- Chỉ để viết cùng kiểu và biết cách bộ kiểm đổi dữ liệu trong lúc gọi
  API: các tệp quản lý ảo bot 3 trong Include, đề xuất phần A cùng lượt,
  `Bot1ManagementVirtualFinish.mqh` và bộ kiểm cũ. Không sửa tệp nào.

## Đối chiếu: hợp đồng → mã → lệnh gốc

Đã đọc lại từng lệnh ở hai đoạn; mọi công thức, thứ tự toán hạng và
điều kiện trong hợp đồng khớp lệnh gốc. Số dòng là dòng trong `part.mqh`.

| Bước | Mã | Mua (0x32f60) | Bán (0x37590) |
|---|---|---|---|
| 1. `0<lock_start` (một lần đọc), `mode==2` | :43–44 | 0x36925..0x3692e; 0x3693e `cmp dword,2` | 0x3ab08..0x3ab11; 0x3ab21 |
| 1. chụp `u`, quote; `lock_start*u`; trigger | :46–50 | u 0x3695b, bid 0x36960, 0x36964, `+open` 0x36969, so 0x3696d | u 0x3ab38, 0x3ab46, `open-` 0x3ab4a, so với [ask] 0x3ab4e |
| 2. `u*lock_extra`, candidate, `old=P` trước API | :52–54 | 0x3698d, 0x369ab, 0x3699c | 0x3ab73, 0x3ab90, 0x3ab81 |
| 2. POINT (`r8d=0x10`) | :55 | gọi 0x369b0 | gọi 0x3ab95 |
| 2. `old+point<cand` / `cand<old-point` | :56 | 0x369b2, 0x369b8 | 0x3ab97, 0x3ab9c |
| 3. đọc lại extra, quote, unit; `extra*unit`; candidate mới | :59–62 | 0x369d3, 0x369d7, 0x369e5, `open+` 0x369f7 | 0x3abb7, 0x3abbb, 0x3abc9, `open-` 0x3abd7 |
| 3. `gap+cand<quote` / `quote<cand-gap` | :63–64 | 0x369f3..0x36a03 | 0x3abdf..0x3abe7 |
| 3. `quote<tp-freeze` / `freeze+tp<quote` | :63–64 | 0x36a05..0x36a1b | 0x3abf3..0x3abff |
| 3. `P=cand`, `changed=true`, không đặt lại counter | :66–67 | 0x36fb9..0x36fc6 (vào sau 0x36fb3) | 0x3b1ac..0x3b1b9 (vào sau 0x3b1a6) |
| 4. cờ true thì bỏ counter | :74 | 0x36a2b `test r12b; je` | 0x3ac0f/0x3ac12 |
| 4. chụp quote, `old=P` trước `step_enabled==1` | :75–77 | 0x36a65, 0x36a69, `cmp byte,1` 0x36a6d | 0x3ac49, 0x3ac4d, 0x3ac51 |
| 4. counter +1 cuộn int32; unit; `step_distance*u`; next | :78–84 | counter đọc 0x36a94, `inc` 0x36a9f, ghi 0x36aa5; unit 0x36a96; step_distance 0x36a9b; nhân 0x36aa1; `+old` 0x36ab1 | counter 0x3ac85, 0x3ac8b, 0x3ac91; unit 0x3ac7c; step_distance 0x3ac81; nhân 0x3ac87; `old-` 0x3ac8d |
| 5. `gap+next<quote` / `quote<next-gap` | :85 | 0x36ab5..0x36ac1 | 0x3aca1..0x3aca9 |
| 5. `quote<tp-freeze` / `freeze+tp<quote` | :86 | 0x36acd..0x36ad5 | 0x3acb5..0x3acbd |
| 6. ±0 bỏ mốc; khác 0 hoặc NaN thì so mốc với `u*copied_step` | :88–92 | 0x36ae1..0x36af0 (`jne`/`jp`); 0x36f72..0x36f91, anchor [rsp+0x78] | 0x3acc9..0x3acd8; 0x3b162..0x3b184, anchor [rsp+0x88] |
| 7. `steps>=min_steps` có dấu → counter=0, P=next, changed=true | :93–96 | 0x36b00/0x36b02 hoặc 0x36fa1/0x36fa3; 0x36fa9..0x36fc6 | 0x3ace8/0x3acea hoặc 0x3b194/0x3b196; 0x3b19c..0x3b1b9 |

## Thứ tự đọc quanh API

- Khối khóa chạy cả khi `changed` đã true (gốc không kiểm r12b trước
  0x3691b/0x3aafe); chỉ bộ đếm bị bỏ.
- Trước POINT: lock_start, mode, `u=unit`, quote, lock_extra lần 1, `old=P`.
- Sau POINT: point, lock_extra lần 2, tick lần 2, unit lần 2, gap, freeze.
  Bước 2 so bằng `old`/candidate tính trước API; P được ghi bằng candidate
  tính lại ở bước 3.
- Bộ đếm không gọi API. `u` ở bước 6 là bản chụp unit của bước 4.
- `open_price`/`tp` chụp một lần ở đầu hàm vì gốc giữ trong xmm6/xmm7
  (thanh ghi không đổi qua lời gọi). Các phần chuẩn khác đọc qua tham
  chiếu lúc so; hai cách chỉ khác nhau nếu bộ kiểm đổi `position` trong
  lúc gọi POINT, khi đó cách chụp này mới khớp gốc.

## Chi tiết số

- Mọi phép so là `<` có thứ tự; nhánh không đạt viết bằng `!(...)` hoặc
  không vào khối, không đổi sang `>=`. NaN làm điều kiện sai.
- `step_reference!=0.0`: +0/−0 bằng 0 → bỏ mốc; NaN và số khác → so mốc,
  đúng `jne`+`jp`. Điều này cần MQL5 coi NaN là khác 0 khi so `!=`; các
  tệp chuẩn đã qua kiểm cũng dựa vào tính chất đó (ví dụ `left!=left` ở
  `Bot3PendingQueue.mqh:26`). Chưa kiểm riêng cho hàm này.
- Bộ đếm cộng trên `uint` rồi ép `int`, nên INT_MAX+1 chắc chắn thành
  INT_MIN, không dựa vào tràn số có dấu. So `steps<min_steps` có dấu như
  `jl`/`jge`; `steps` là bản sao như `eax` gốc. Giá trị đã tăng được giữ
  khi điều kiện sau không đạt.
- Không làm tròn, không Modify (không có 0x32a90), không Print, không
  đóng, không ghi `position`.

## Khác cách viết so với lệnh gốc (kết quả không đổi)

1. Bán bước 5: gốc 0x3acb5 là `addsd xmm7,[freeze]` = tp+freeze; mã theo
   hợp đồng `freeze+tp`. Phép cộng IEEE-754 giao hoán đúng từng bit, kể cả
   ±0 và vô cực; giá trị chỉ dùng để so nên NaN cũng không khác. Có thể
   đổi thành `tp+freeze` nếu muốn đúng thứ tự gốc.
2. Gốc xóa r12b ở 0x36b08/0x36f82 (mua), 0x3acf0/0x3b175 (bán). Chỉ vào
   bộ đếm qua `test r12b; je`, nên tại đó cờ đã false; mã không ghi lại.
3. Gốc ghi đè xmm7 ở 0x36acd/0x3acb5 và xmm6; mã dùng biến cục bộ, không
   sửa `position.tp`. Trong analysis.json, sau 0x36ad1 lần xuất hiện xmm7
   kế tiếp của hàm mua là 0x37347; của hàm bán sau 0x3acb9 là 0x3b8a8 (đều
   là khôi phục thanh ghi cuối hàm). Đầu vòng nạp lại xmm7 ở
   0x331e2/0x3780f. Chưa dò từng cạnh nhảy để chứng minh hết mọi đường.
4. Mua/bán đọc counter, unit, step_distance theo thứ tự khác nhau; không
   có API ở giữa nên không quan sát được.

## Ghi chú cho người ghép phần bao ngoài

Sau B, phép chạm gốc so bằng bản sao thanh ghi (P trong xmm6, quote trong
xmm0) hoặc đọc lại bộ nhớ (0x36a30/0x3ac14 khi cờ đã true). Không có API
hay lệnh ghi nào giữa các lần đọc đó và phép so, nên bên gọi đọc lại
`current_level`/`tick` cho cùng giá trị. Đích gốc: mua 0x36b19 (lưu) hoặc
0x36fd4 (đóng); bán 0x3ad01 hoặc 0x3b1c7.

## Chưa kiểm / còn chưa chắc

1. Biên dịch (mục tiêu 0 lỗi, 0 cảnh báo); đặt cạnh
   `Bot3ManagementPrelude.mqh`. Tên `u/quote/old` dùng lại ở khối khóa và
   bộ đếm nhưng khác phạm vi, giống bản bot 1 đã có tệp biên dịch
   (finish-20261025-r24, biên nhận không ghi số cảnh báo).
2. Mã máy MQL5 phải nhân rồi mới cộng/trừ (hai lần làm tròn), không gộp FMA.
3. Ca so native/MQL5 đề xuất:
   - cổng: lock_start 0/−0/âm/NaN/+vô cực; mode 2 và khác 2;
     step_enabled 0/1/2/255; changed vào true/false;
   - mỗi phép so: hai vế bằng nhau (phải không đạt), lệch 1 ulp,
     NaN/±vô cực ở từng toán hạng;
   - đổi P, tick, unit, gap, freeze, lock_extra trong lúc gọi POINT:
     bước 2 dùng giá trị cũ, bước 3 dùng giá trị mới;
   - khóa đạt: counter không đổi, bộ đếm bị bỏ;
   - step_reference +0/−0/NaN/khác 0; min_steps âm/0/INT_MIN/INT_MAX;
     counter INT_MAX→INT_MIN, −1→0; điều kiện 5/6 không đạt vẫn giữ
     counter đã tăng.
4. Không tự xác minh giá trị hằng 0x58488/0x584b0 (thuộc phần A).

## Phụ thuộc

- `Bot3ManagementPrelude.mqh`: `Bot3ManagedPosition` (chỉ `open_price`, `tp`).
- API MT5: `SymbolInfoDouble(symbol,SYMBOL_POINT)`.
- `Bot3VirtualFinishSettings` giống hệt đề xuất phần A cùng lượt (cùng
  guard `BOT3_VIRTUAL_FINISH_SETTINGS_MQH`) để ghép không bị định nghĩa trùng.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`. Hệ thống báo bật
`ultracode`, nhưng phiên này không có công cụ Workflow và việc giao cấm
gọi tác tử con, nên làm một mình. Không tự kiểm được mức `max` từ bên
trong phiên. Chỉ dùng Read/Grep/Glob/Write.
