# REVIEW — `Bot3AdvanceTimedVirtualStop` (bot 3), lượt `bot3-timed-audit-20261025-r1`

Ngày 25/10/2026. Bối cảnh: chủ dự án khôi phục nguồn MQL5 đã mất của
The Gold Reaper MT5 (EX5 SHA-256 `ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`)
theo `AGENTS.md`; Codex đã chốt mô tả trong `contract.md`. Phiên nhận đủ
phạm vi này. Không động tới bản quyền/kích hoạt; chỉ đọc bằng chứng và chỉ ghi tệp này.

## 0. Phạm vi và cấu hình phiên

- Đã đọc `AGENTS.md`, `tai-lieu-cu/QUY-TRINH.md`, `TASK.md`.
- Mô hình theo thông tin hệ thống: `claude-opus-5-5`. Thông báo hệ thống ghi
  Ultracode bật; mức `max` không tự kiểm được. Không có công cụ Workflow và
  TASK cấm tác tử lồng, nên làm một mình. Chỉ dùng Read/Glob/Grep/Write; không
  chạy Bash, PowerShell, Python, MT5; không tính lại SHA-256.
- Chỉ xét `Bot3AdvanceTimedVirtualStop` (`Bot3ManagementVirtual.mqh:7-26`).
  Không xét nhánh khoảng giá, trượt giá, dời chốt lời ảo; không viết bộ kiểm.
- Nguồn chính đọc được giống hệt bản đã kiểm
  `bang-chung/kiem-quan-ly-vi-the/virtual-20261025-r1/tested-sources/Bot3ManagementVirtual.mqh`
  (so cả tệp bằng mắt). SHA `e74e2780…` trong `baseline.json:15`,
  `final-verification.json:29` chưa được tính lại ở phiên này.
- Địa chỉ dưới đây là RVA = địa chỉ tuyệt đối − `0x17156250000`.
  Lệnh lấy từ `phan-tich/dong-vi-the/management-20261025-r1/native-guards.txt`
  (viết tắt `ng`), byte từ `analysis.json` (viết tắt `aj`) cùng thư mục.

## 1. Kết luận

1. **Không thấy lỗi nguồn có bằng chứng → không viết header sửa.**
2. Đọc từng byte: phép tính, phép so, kiểu số, thứ tự đọc/ghi và lối ra của
   hàm khớp mã gốc ở cả mua và bán (mục 2–3).
3. Nhóm stage 1 khớp 156/156 trong 560/560 (`comparison.json:6-9`), nhưng
   còn khoảng trống cụ thể (mục 4): bốn phép so giá chưa có ca hai vế bằng
   nhau; dấu của phép so thời gian 64-bit và dạng cộng tràn chưa được phân
   biệt; thứ tự chụp trước API chưa được phân biệt. Đây là **thiếu chứng
   minh**, không phải lỗi đã thấy.
4. Đây chỉ là một đoạn của 0x32f60/0x37590; chưa phải toàn hàm quản lý hay EA.

## 2. Đối chiếu nguồn ↔ mã gốc

| Bước | Nguồn | Mua | Bán | Ý nghĩa |
|---|---|---|---|---|
| Cổng activation | :13 | 0x35f8f nạp `[0x6d5e8]`; 0x35f9d `66410f2ec3` ucomisd xmm0,xmm11; 0x35fa2 `762f` jbe 0x35fd3 | 0x3a228 `66410f2ec3`; 0x3a22d `0f86c4000000` jbe 0x3a2f7 | xmm11=0.0 (`xorpd` 0x33086/0x376b0; ngoài lệnh khôi phục ở phần kết hàm, không lệnh nào khác ghi xmm11). Đi tiếp chỉ khi `activation>0` và có thứ tự |
| TimeCurrent | :14 | 0x35fa4–0x35fb3: rcx=rsi, edx=0, gọi 0x7ff6846f1c40 | 0x3a233–0x3a242 | = eb+0x7d1c40 = `TimeCurrent` (`virtual-stops-20261025-r1/api-contract.json:236`), dạng không MqlDateTime. Gọi một lần, sau cổng 1 |
| So thời gian | :15 | 0x35fbf `mov rdx,[rsp+0x60]`; 0x35fc4 `486309` movsxd; 0x35fc7 `4801ca` add rdx,rcx; 0x35fca `4839d0` cmp rax,rdx; 0x35fcd `0f8dac060000` jge 0x3667f | `[rsp+0x70]`; 0x3a253/56/59 cùng byte; 0x3a25c `0f8c95000000` jl 0x3a2f7 | int32 mở rộng có dấu, cộng 64-bit tràn vòng, so có dấu; không trừ, không đổi sang số thực. delay/opened đọc sau lời gọi |
| Chụp P, quote | :16–17 | 0x3669f `[0x6d670]`→xmm14; 0x366a4 `[0x74798]`→xmm8; trước call 0x366b3 | 0x3a282 `[0x6d670]`; 0x3a287 `[0x747a0]`; trước 0x3a296 | Chụp sau TimeCurrent, trước POINT |
| POINT | :18 | rdx=rdi (`0x74958`), r8d=0x10, gọi 0x7ff6846e2890; 0x366bf `f2450f587500` addsd xmm14,[r13] | 0x3a2a2 `f2450f5c36` subsd xmm14,[r14] | eb+0x7c2890 = `SymbolInfoDouble` 2 tham số (`doi-chung-mt5/dong-vi-the-20261024/close-api-r1/api-contract.json:65-76`). [r13]/[r14] = ô kết quả 0x1d6e48 (r13 đặt 0x33479; r14 đặt 0x37a6e/0x37abd; không ghi lại trước đoạn này) |
| offset | :19 | 0x366c5 `[0x6d5f0]`; 0x366d3 mulsd `[0x73dd8]` | 0x3a2a7; 0x3a2b5 | `distance*unit`, đọc sau POINT |
| So 1 | :20–21 | 0x366d7 addsd xmm14,xmm0; 0x366dc `66450f2ec6` ucomisd xmm8,xmm14; 0x366e1 `0f8603010000` jbe 0x367ea | 0x3a2b9 subsd; 0x3a2be `66450f2ef0` ucomisd xmm14,xmm8; 0x3a2c3 `7632` jbe | Mua: `((P+point)+offset)<quote`; bán: `quote<((P-point)-offset)`. Bằng nhau/NaN → thoát |
| So 2 | :22–23 | 0x366e7 movapd xmm2,xmm7 (T); 0x366f5 đọc lại `[0x74798]`; 0x36704 `f20f5c10` subsd `[0x744a8]`; 0x36708 `660f2ed1` ucomisd xmm2,xmm1; 0x3670c jbe | 0x3a2cf đọc lại `[0x747a0]`; 0x3a2d8 `f20f58d7` addsd xmm2(freeze),xmm7; 0x3a2dc `660f2eca` ucomisd xmm1,xmm2; 0x3a2e0 `7615` jbe | Mua `bid<(T-freeze)`; bán `(freeze+T)<ask` |
| Ghi | :24–25 | 0x36712 `41b401` r12b=1; 0x36715 `f20f5cc8` bid−offset; 0x36723 ghi `[0x6d670]` | 0x3a2e2 r12b=1; 0x3a2e5 `f20f58c1` offset+ask; 0x3a2f3 ghi `[0x6d670]` | `changed` rồi P; dùng offset đã tính |
| Lối ra | `return` | 0x35fd3 hoặc 0x367ea | 0x3a2f7 | 0x367ea–0x3680e chỉ đặt r14 rồi lặp lại cổng `[0x6d598]` của 0x35fd3–0x35fe7, cùng đích 0x35fed/0x36189 ⇒ mọi lối ra đi tiếp cùng chỗ; hàm `void` đúng |

Nguồn lệnh: `ng:2342-2359, 2667-2695, 2728-2733` (mua), `ng:5521-5565` (bán).
Byte: `aj:14077-14146, 16075-16180, 33161-33230, 33293-33392`. Hai đoạn chỉ có
một lối vào (0x35f8f/0x3a21a); không lệnh nhảy trực tiếp nào vào giữa đoạn
(đã tìm mọi đích nhảy trong khoảng; chỉ có 0x36580→0x3672c, nằm sau đoạn). Bản chạy gốc
đã đi qua mọi lệnh của hai đoạn (`original-run.json:29-48, 190-222, 227-268`).

## 3. Các điểm TASK yêu cầu

- **Tham chiếu, bản chụp.** Chữ ký khớp `contract.md:30-35`; `const bool buy`
  truyền trị như `bool buy`. `opened` gốc ở `[rsp+0x60]`/`[rsp+0x70]`, chỉ được
  ghi tại 0x333a7/0x379d3 từ `PositionGetInteger(1)` (`ng:204, 3551`), tương
  ứng `position.opened` (long). Phép so 2 và phép ghi đọc lại `tick.*` như gốc;
  gốc ghi bằng giá trị đọc ở phép so 2, nguồn đọc lần ba, giữa hai lần chỉ có
  `changed` (bool, không thể trùng vùng nhớ double) nên cùng giá trị.
  T gốc là thanh ghi xmm7; nguồn đọc `position.tp` — chỉ đúng khi người gọi
  truyền đúng giá trị xmm7 (mục 5, L1).
- **int64.** Dùng `long` có dấu và ép `(long)` cho cả `TimeCurrent()` lẫn
  `delay_seconds`; khớp `movsxd`+`add`+`jge/jl`. Không có phép trừ thời gian
  hay đổi sang double. Khi ghép nên giữ ép `(long)`.
- **So có thứ tự.** Năm phép so số thực (activation và bốn phép so giá) đều
  `ucomisd`+`jbe` (thoát khi ≤ hoặc không thứ tự); nguồn viết `!(a<b)` nên NaN thoát ở cả hai. Ca NaN đã có cho
  activation, P, point, distance, unit, freeze, tp và đều khớp.
  Khi bid/ask không đổi giữa các lần đọc (đúng trong MT5), qua được cả hai
  phép so thì bid/ask hữu hạn, offset hữu hạn hoặc −∞, nên giá trị ghi không
  thể là NaN. Khác biệt phần trị NaN Unicorn/CPU
  (`cpu-nan-20261025-r1/probe.json:16-208`) không ảnh hưởng đầu ra hàm này.
- **Thứ tự cập nhật.** `changed` chỉ gán `true`, chỉ sau cả hai phép so,
  trước ghi P; không Print/Modify/Close. Trace mỗi ca có 0, 1 hoặc 2 sự kiện.
- **Ngưỡng.** activation `>0` chặt; thời gian `now >= opened+delay`; bốn phép
  so giá chặt (bằng nhau → thoát).

## 4. Khoảng trống của bộ 560 ca cho hàm này

Stage 1 mỗi chiều: 24 ca activation/thời gian + 48 ca số + 2 ca đọc lại + 4 ca
cộng có dấu = 78; tổng 156 (`check-management-virtual-start.py:35-45`). Giá trị
nền (`:21`): bid=ask=100, unit=0.1, point=0.01, distance=3, freeze=0.1,
P=95/105, T=120/80, now=1020, opened=1000, delay=20.

| Mã | Chưa được phân biệt | Bằng chứng | Ảnh hưởng thật |
|---|---|---|---|
| G1 | Bốn phép so giá không có ca nào hai vế bằng đúng nhau (đã tính hết 156 ca; nền: 95.31↔100, 119.9↔100, 104.69↔100, 80.1↔100; gần nhất là tp=100 → 99.9, P=100 → 100.31/99.69). Đổi `<` thành `<=` ở bất kỳ phép nào vẫn 560/560 | `:21, :39-41` | Có thể xảy ra: ví dụ T=2010.0, freeze=0.5, bid=2009.5 đều là số nhị phân đúng |
| G2 | Dấu của phép so 64-bit: mọi ca có `now` và tổng hoặc bằng nhau, hoặc cùng dương nhỏ (1019–1021 ↔ 1020) ⇒ `jge/jl` và `jae/jb` cho cùng kết quả | `:35-38, :44-45` | Chỉ khi thời gian âm hoặc ≥2^63 |
| G3 | Tràn chỉ kiểm ở điểm bằng nhau ⇒ không phân biệt `now<opened+delay` với `now-opened<delay` hay `now-delay<opened`. **Đã phân biệt được:** mở rộng có dấu (ca 1000/−20/980) và không đổi sang double (ca 2^63−2/20/−2^63+18) | `:44` | Chỉ khi tràn |
| G4 | Chụp P/quote trước POINT: kịch bản 4/5 cộng 1.25 cho cả P, bid, ask; ngưỡng cách 4.69 nên đọc trước hay sau đều cùng nhánh. Chỉ phép ghi được phân biệt (mua 100.95↔99.7, bán 101.55↔100.3). Kịch bản 2 (chỉ đổi P khi gọi POINT) có sẵn ở hai bộ chạy (`check-management-virtual.py:63`, `Bot3ManagementVirtualCheck.mq5:33`) nhưng không có ca stage 1 | `:42-43` | Không quan sát được trong MT5 (API không ghi biến chương trình); chỉ là chứng minh cho hợp đồng |
| G5 | Phép so 2 đọc lại tick sau POINT: chưa phân biệt (119.9/80.1 xa 100/101.25) | như G4 | như G4 |
| G6 | Chưa có: bid/ask NaN/∞; activation −0.0/+∞; delay INT_MIN/INT_MAX; `changed=true` vào rồi trượt ở phép so giá; đổi distance/unit/freeze/delay/activation khi gọi API (bộ chạy không đổi chúng) | `:35-45` | Thấp; cùng loại lệnh với ca đã kiểm |

Ca đề xuất cho Codex (chưa chạy; kết quả dưới đây chỉ là dự đoán theo byte,
phải chạy bản gốc để lấy kỳ vọng). Chung: unit=0.5, distance=0.5 (offset=0.25),
point=0.25, bid=ask=100, now=1020, opened=1000, delay=20, activation=1,
changed=0; mọi số là nhị phân đúng.

| Ca | Chiều | Thay đổi | Dự đoán | Bắt được |
|---|---|---|---|---|
| E1 | mua | P=99.5, T=120, freeze=0.1 | 100.0<100 sai → thoát; P=99.5 | `<=` ở so 1 mua |
| E2 | mua | P=95, T=120, freeze=20 | so 1 qua; 100<100 sai → thoát | `<=` ở so 2 mua |
| E3 | bán | P=100.5, T=80, freeze=0.1 | 100<100.0 sai → thoát | `<=` ở so 1 bán |
| E4 | bán | P=105, T=80, freeze=20 | so 1 qua; 100<100 sai → thoát | `<=` ở so 2 bán |
| T1 | cả hai | P/T/freeze như nền; now=−1 | −1<1020 có dấu → thoát sau TimeCurrent, 1 sự kiện | so không dấu |
| T2 | cả hai | như T1; opened=2^63−2, now=1021 | tổng tràn −2^63+18; đi tiếp, ghi P=99.75 (mua)/100.25 (bán) | so không dấu, dạng trừ |
| T3 | cả hai | như T1; opened=2^63−2, now=2^63−1 | đi tiếp, ghi P như T2 | dạng `now-opened<delay` |
| C1 | mua | kịch bản 2, P=98.5, bid=ask=99.5, T=120, freeze=0.1 | 99.0<99.5 qua → P=99.25, changed=1 | đọc P sau POINT (sẽ thoát, P=99.75) |
| C1' | bán | kịch bản 2, P=100.5, T=80, freeze=0.1 | 100<100.0 sai → thoát, P=101.75 | đọc P sau POINT (sẽ ghi P=100.25) |
| C2 | mua | kịch bản 5, P=99.5, T=120, freeze=0.1 | thoát; P=100.75, bid=ask=101.25 | đọc quote sau POINT (sẽ ghi P=101.0) |
| C2' | bán | kịch bản 5, P=101, T=80, freeze=0.1 | 100<100.5 qua → P=101.5, changed=1 | đọc quote sau POINT (sẽ thoát, P=102.25) |
| C3 | mua | kịch bản 5, P=95, T=101.5, freeze=0.5 | so 2: 101.25<101.0 sai → thoát, P=96.25 | so 2 dùng quote đã chụp |
| C3' | bán | kịch bản 5, P=105, T=100, freeze=0.5 | so 2: 100.5<101.25 qua → P=101.5 | so 2 dùng quote đã chụp |

## 5. Lưu ý khi ghép (không phải lỗi của hàm)

- **L1 — T là xmm7 lúc vào, không phải TP của lệnh.** Ngoài prelude
  (0x33253/0x3787f) và nhánh điền TP khi bằng 0 (0x336e4/0x37d25), xmm7 còn
  bị ghi ở 0x347a2–0x34818 (mua: làm tròn `[0x6d378]*unit+bid`) và
  0x38cde–0x38d49 (bán: `bid-[0x6d378]*unit`) **trước** phép chặn
  0x3483d/0x34841 (mua) và 0x38d5a/0x38d62 (bán). Chặn không đạt thì nhảy
  0x34b22/0x38f3a mà không trả lại xmm7 (`ng:1167-1213, 4463-4511`). Không
  còn lệnh ghi xmm7 nào trước 0x35f8f/0x3a21a (`ng` liệt kê đủ). Vậy
  `position.tp` truyền vào hàm phải bằng xmm7 tại lúc vào, kể cả TP mới chưa
  gửi. Chưa lần hết đường 0x34b22/0x38f3a → 0x35f8f/0x3a21a; nhánh đó chưa có
  nguồn MQL5 nên chưa kiểm được.
- **L2 — current_level là P (0x6d670), không phải H.** Đọc ở 0x3669f/0x3a282,
  ghi ở 0x36723/0x3a2f3; khớp `root-review.md:7-12` (dòng mô tả sai của
  SUMMARY lượt trước không có trong mã).
- **L3 — Lối vào.** 0x35f8f có ba đường tới: `je` 0x35e0c, `jbe` 0x35ecf, và
  rơi xuống sau Modify 0x35f7e + gọi 0x48560 tại 0x35f8d; bán: 0x3a098,
  0x3a15a, 0x3a218 (`ng:2265, 2303, 2334-2341, 5444, 5482`). Hàm không dùng giá
  trị trả về của các lời gọi đó (rax/xmm0 bị ghi đè ở 0x35f8f/0x35f99, bán
  0x3a21a/0x3a224). Người
  gọi phải gọi hàm ở cả ba đường.
- **L4 — Phạm vi bản dịch.** Bằng chứng chỉ cho bản dịch `cpu='X64 Regular'`
  (`bien-dich/b3-management-virtual-01/metaeditor.log:48`), với
  `TimeCurrent`/`SymbolInfoDouble` bị macro thay
  (`Bot3ManagementVirtualCheck.mq5:58-63`); lời gọi API thật chưa chạy. Đổi
  đích CPU khi dịch EA thì phải kiểm lại.

## 6. Trả lời 4 điểm còn mở trong SUMMARY lượt trước

1. Chụp P/quote **sau** TimeCurrent, trước POINT: đúng gốc (0x3669f/0x366a4
   sau call 0x35fb3; 0x3a282/0x3a287 sau 0x3a242).
2. So có dấu, cộng tràn vòng: đúng gốc (`jge`/`jl`, `add` 64-bit).
3. Sau thân mua 0x36727 và mọi lối ra: đều đi tiếp cổng `[0x6d598]` (mục 2,
   dòng Lối ra) ⇒ `void` đúng.
4. `const bool buy`: không đổi cách gọi.

## 7. Giới hạn của báo cáo

- Chỉ đọc tĩnh byte/lệnh đã chụp và kết quả đã lưu; chưa tháo mã máy của bản
  MQL5 đã dịch. Ở các vùng G1–G6, việc bản dịch giữ đúng ngữ nghĩa chỉ dựa
  vào ngữ nghĩa MQL5, chưa có phép chạy.
- Tên API dựa vào bảng API sẵn có (mục 2), không tự đo lại.
- 156/156 là kết quả của bộ ca đã nêu, không phải mọi đầu vào; không chứng
  minh toàn hàm 0x32f60/0x37590, toàn bộ quản lý lệnh hay bot 3.
