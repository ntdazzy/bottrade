# REVIEW – 10 ca lệch NaN, phần đầu quản lý bot3 (`prelude-20261025-r1`)

Ngày 25/10/2026. Kiểm độc lập, chỉ đọc; chỉ ghi tệp này.

## 0. Phạm vi và giới hạn

- Đã đọc `AGENTS.md` và `TASK.md`.
- Mô hình của phiên: Opus 5.5 (`claude-opus-5-5`, theo thông tin hệ thống
  của phiên). `TASK.md:19` yêu cầu mức `max` và `ultracode`; báo cáo không tự
  khẳng định mức thực tế đã dùng.
- Phiên này chỉ có công cụ đọc, tìm và ghi tệp: không chạy Python, MT5 hay
  CPU. Phép ghép NaN ở mục 4 là đối chiếu tay trên dữ liệu đã lưu. Chưa tính
  lại SHA-256 (comparison.json, probe.json) và hash FNV `ordered_hash`.
- Không sửa kỳ vọng, bộ kiểm, nguồn hay bằng chứng. Kết quả vẫn là 626/636;
  nhóm `nan-payload-operand-order` vẫn 2/12 (`comparison.json:58-61`).

Ký hiệu: A=`7ff8000000000123` (9221120237041090851),
B=`fff8000000000456` (18444492273895867478),
C=`7ff8000000000789` (9221120237041092489). O=open, S=stop, T=take, U=unit.
Đường dẫn ngắn: `py`/`mq5` = `tested-sources/check-management-prelude.py` và
`tested-sources/Bot3ManagementPreludeCheck.mq5` của lượt r1.

## 1. Kết luận ngắn

1. Không thấy sai ở bộ tạo ca, pack/đọc, vòng reset hay trace có thể gây
   10 lệch (mục 2).
2. 10 lệch trùng hoàn toàn với khác biệt đã đo trong
   `cpu-nan-20261025-r1/probe.json`: khi cả hai toán hạng là NaN, CPU trả
   toán hạng đầu; Unicorn 2.1.4 trả NaN có phần trị lớn hơn. Ghép từng phép
   theo thứ tự byte gốc cho ra đúng cả hai cột của 12/12 ca (mục 4).
3. Vì vậy cột `original` của 10 ca là giá trị của bộ mô phỏng, không phải
   giá trị CPU. Không có bằng chứng nguồn sai ở 10 ca.
4. Chưa có phép đo trực tiếp "byte gốc chạy trên CPU cho đúng giá trị MQL5"
   với 10 ca; phần còn thiếu ghi ở mục 5. Nhóm này vẫn chưa đạt.

## 2. Kiểm cách kiểm

| Hạng mục | Bằng chứng | Kết quả |
|---|---|---|
| Bộ tạo ca | `py:126-127` gán A,B,C theo thứ tự trường. `cases.json:8193-8199, 8260-8266, 8327-8333, 8394-8400, 8461-8467, 8528-8534, 29499-29505, 29566-29572, 29633-29639, 29700-29706, 29767-29773, 29834-29840` | Đúng thiết kế; sl=tp=0 nên cả hai nhánh mức ban đầu đều chạy; nến tắt. |
| Hai bên cùng dữ liệu | `py:331` (rows), `py:342` (`cases.bin == encode(rows)`), `py:346-347` (bên gốc dùng chính rows) | Cùng một bộ ca. |
| Pack ↔ đọc MQL5 | `py:36, 172-175` ↔ `mq5:195-212`; `mq5:228` (FileTell==FileSize); `py:374, 385` (status 0,636) | Thứ tự và kích thước khớp; không lệch khung đọc. |
| Giữ bit NaN khi chuyển | Đầu ra hai bên có đúng A/B/C: ca 124 MQL5 sl=A (từ stop), tp=B (từ unit) `comparison.json:208-209`; ca 126 gốc sl=tp=C (từ unit) `comparison.json:293-294`. Nhóm numeric-* có một NaN đều 18/18 (`comparison.json:30-53`) | Không thấy mất hay đổi phần trị. |
| Ghi/đọc kết quả | `mq5:163-175` ↔ `py:37, 316-319`; so nguyên bit cả bản ghi `py:390` | Không nới so sánh. |
| Vòng reset bên gốc | `py:289-301`: nạp lại vùng dữ liệu ghi được, xoá GPR và XMM0-15, MXCSR=0x1f80, xoá ngăn xếp, ghi lại stop/take/unit mỗi ca | Không có trạng thái mang sang. |
| Vòng reset MQL5 | `mq5:214-217` | Không có trạng thái mang sang. |
| Trace | `py:350` chỉ lưu ca đầu của mỗi nhóm/chiều, nên nhóm NaN chỉ có 122 và 440. Ca 440: hai lần sửa nhận sl=B (`original-traces.json:6510-6530`), đúng với sl ở cột gốc. MQL5 chỉ lưu hash, không lưu từng sự kiện (`mq5:35-41`) | Hai bên đều 18 lời gọi. Sự kiện duy nhất mang giá trị tính toán là lời gọi sửa lệnh (`py:238-239` ↔ `mq5:87-91`), nên khác `ordered_hash` phù hợp với khác sl/tp. Chưa tính lại FNV. |
| Các nhóm khác | Các nhóm khác có tối đa một NaN trong phép SSE, hoặc NaN chỉ vào phép so sánh (`py:121-124, 145-150`) | Đúng vùng mà probe cho thấy hai bên trùng; phù hợp với việc chỉ nhóm này lệch. |

Giới hạn thiết kế, không phải lỗi pack/đọc: theo quy tắc Unicorn đã đo,
kết quả bên gốc của nhóm này luôn là NaN có phần trị lớn nhất (C>B>A), không
phụ thuộc thứ tự toán hạng. Với bộ mô phỏng hiện tại, nhóm không kiểm được
thứ tự toán hạng; chú thích `py:125` chỉ đúng cho phía CPU. Ca 122 và 441 khớp
chỉ vì NaN ở toán hạng đầu cũng có phần trị lớn hơn (B so với A). Ví dụ ngược:
nếu nguồn viết sai thành `unit*stop`, ca 124 bán cho sl=B và lại "khớp" cột
gốc. Vì vậy không được sửa nguồn để khớp cột `original` hiện tại.

## 3. Mã máy gốc và nguồn (đã đọc byte)

| Công thức | RVA, byte, lệnh | analysis.json |
|---|---|---|
| mua sl | 3358c `66440f28c6` movapd xmm8,xmm6; 3359b `f20f1001` movsd xmm0,[stop]; 335a9 `f20f5901` mulsd xmm0,[unit]; 335ad `f2440f5cc0` subsd xmm8,xmm0 | 1807-1846 |
| mua tp | 3366f `f20f1039` movsd xmm7,[take]; 3367d `f20f5939` mulsd xmm7,[unit]; 33681 `f20f58fe` addsd xmm7,xmm6 | 2053-2086 |
| bán sl | 37bd6 `f2440f1001` movsd xmm8,[stop]; 37be5 `f2440f5901` mulsd xmm8,[unit]; 37bea `f2440f58c6` addsd xmm8,xmm6 | 21929-21962 |
| bán tp | 37ca2 `660f28fe` movapd xmm7,xmm6; 37cb0 `f20f1001` movsd xmm0,[take]; 37cbe `f20f5901` mulsd xmm0,[unit]; 37cc2 `f20f5cf8` subsd xmm7,xmm0 | 22169-22208 |

- Địa chỉ nạp `0x171562bd588/…bd590/…c3dd8` = CODE_BASE + `0x6d588/0x6d590/0x73dd8`
  = stop/take/unit (`py:30, 50-51`).
- xmm6 = open: suy từ việc trường `open` (đọc XMM6, `py:306`) và nhóm
  numeric-open khớp 18/18; chưa lần ngược chỗ ghi xmm6.
- Sau mỗi phép: cvttsd2si, so với `0x8000000000000000`, je
  (`analysis.json:1849-1864, 2089-2104, 21965-21979, 22211-22226`) ↔
  `Bot3PriceLevels.mqh:9-10`. NaN đi qua bước làm tròn nguyên bit.
- Nguồn giữ cùng thứ tự: `Bot3ManagementPrelude.mqh:57-58, 65-66`;
  mô tả `contract.md:58-65`. Cặp phép tính ghi trong `TASK.md:9-12` đúng với byte.

## 4. Phép đo đã có và đối chiếu 12 ca

### 4.1 `probe.json`

- Công cụ `bot-cua-toi-3/tests/check-nan-cpu.py` chạy
  `movsd xmm0,[rcx]; op xmm0,[rdx]` (`f20f1001 f20f{59|58|5c}02`) trên CPU qua
  VirtualAlloc và trên Unicorn (dòng 26-27, 45-55), MXCSR 0x1f80 (dòng 40).
  Unicorn nạp từ cùng thư mục với bộ kiểm prelude: `check-nan-cpu.py:9-10` và
  `kiem-muc-gia-bot-1-3.py:20, 74-75`.
- `probe.json:3-15`: Unicorn 2.1.4; 363 hàng, 339 trùng, 24 khác. Cả 24 hàng
  khác đều có hai toán hạng NaN (`probe.json:16-208`).
- Quy tắc đo được. CPU: luôn trả toán hạng đầu, SNaN được bật bit quiet; ví dụ
  mul A,B→A (`795-801`), mul B,C→B (`891-897`), sub A,B→A (`145-152`),
  sub A,C→A (`153-160`). Unicorn: trả NaN phần trị lớn hơn, QNaN thắng SNaN;
  cùng các hàng trên cho B, C, B, C. add B,A→B và add C,A→C ở cả hai bên
  (`1843-1849, 1931-1937`). NaN với số thường: hai bên trùng.
- Đối chiếu cũ: đo trong MT5 ngày 24/10 cho `A-B`, `A+B`, `A*B` đều ra A
  (`doi-chung-mt5/hang-doi-20261024/arithmetic-runtime-r2/results.json:94-106`);
  `danh-gia-doc-lap/hang-doi-20261024/nan-checkpoint.md:34-38` ghi cùng hiện
  tượng. Bộ kiểm hàng đợi đã dùng quy tắc CPU đo được khi cả hai là NaN
  (`cong-cu/kiem-hang-doi-bot-1-3.py:139-176`); bộ kiểm prelude và các helper
  không có phần này. Đây là dữ kiện, không phải đề nghị đổi kỳ vọng.

### 4.2 Ghép theo thứ tự byte gốc

Mua sl = O−S·U; mua tp = T·U+O; bán sl = S·U+O; bán tp = O−T·U. Toán hạng
bên trái là toán hạng đầu của lệnh.

| Ca | Chiều | NaN vào | Dự đoán CPU (sl,tp) | Dự đoán Unicorn (sl,tp) | original | mql5 | Lệch |
|---|---|---|---|---|---|---|---|
| 122 | bán | O=A,S=B | B,A | B,A | B,A | khớp | — |
| 123 | bán | O=A,T=B | A,A | A,B | A,B | A,A | tp |
| 124 | bán | S=A,U=B | A,B | B,B | B,B | A,B | sl |
| 125 | bán | T=A,U=B | B,A | B,B | B,B | B,A | tp |
| 126 | bán | O=A,S=B,U=C | B,A | C,C | C,C | B,A | sl,tp |
| 127 | bán | O=A,T=B,U=C | C,A | C,C | C,C | C,A | tp |
| 440 | mua | O=A,S=B | A,A | B,A | B,A | A,A | sl |
| 441 | mua | O=A,T=B | A,B | A,B | khớp | khớp | — |
| 442 | mua | S=A,U=B | A,B | B,B | B,B | A,B | sl |
| 443 | mua | T=A,U=B | B,A | B,B | B,B | B,A | tp |
| 444 | mua | O=A,S=B,U=C | A,C | C,C | C,C | A,C | sl |
| 445 | mua | O=A,T=B,U=C | A,B | C,C | C,C | A,B | sl,tp |

- Số original/mql5 lấy từ `comparison.json:119-651` (vị trí 4=sl, 5=tp). Ca 122
  gốc lấy từ trace (`original-traces.json:2128-2134`). Ca 441 chỉ biết là khớp;
  giá trị nằm trong tệp nhị phân, phiên này không đọc.
- Kết quả: cột original trùng phép ghép theo quy tắc Unicorn; cột mql5 trùng
  phép ghép theo quy tắc CPU; trường lệch trùng `fields` trong comparison.json.
- Theo quy tắc CPU đã đo, kết quả MQL5 xác định thứ tự toán hạng của bản biên
  dịch: 124/442 → mul(stop,unit); 125/443 → mul(take,unit); 122/441 →
  add(tích,open); 123/440 → sub(open,tích). Đều trùng byte gốc.

## 5. Đã chắc và còn cần đo

Đã chắc, có bằng chứng trực tiếp:
- Dữ liệu vào hai bên như nhau và giữ nguyên bit NaN; chỉ khác sl/tp và hash
  suy ra từ đó.
- Thứ tự toán hạng gốc theo byte (mục 3); nguồn giữ cùng thứ tự.
- Unicorn 2.1.4 và CPU của máy chạy probe khác nhau đúng ở phép có hai NaN,
  dạng `op xmm0,[rdx]` (probe.json).

Suy ra từ đo, chưa chạy thành chuỗi:
- Ghép các phép đơn đã đo theo thứ tự gốc tái tạo đúng cả hai cột 12/12.

Còn cần đo CPU (chưa có trong probe):
1. Đúng byte thanh ghi–thanh ghi của phép cộng/trừ gốc: `f2440f5cc0`,
   `f20f58fe`, `f2440f58c6`, `f20f5cf8`; và mul với thanh ghi đích khác:
   `f20f5939`, `f2440f5901`. Probe chỉ đo `f20f5902`, `f20f5802`, `f20f5c02`
   (`probe.json:7-9`).
2. Chuỗi liền ba NaN như ca 126, 127, 444, 445; hiện chỉ ghép từ phép đơn.
3. Bằng chứng trực tiếp còn thiếu: chạy trên CPU đoạn byte gốc từ lúc nạp tới
   cổng làm tròn (`0x33582-0x335ba`, `0x3365b-0x3368d`, `0x37bc2-0x37bf7`,
   `0x37c98-0x37cce`; có movabs địa chỉ tuyệt đối) với 12 bộ vào, rồi so nguyên
   bit với `mql5-results.bin`.

Ghi nhận thêm:
4. `original-run.json` không ghi phiên bản Unicorn; `probe.json` và
   `mql5-run.json` không ghi CPU/máy. Hiện chỉ biết cùng đường dẫn nạp
   Unicorn; phiên này không liệt kê được thư mục
   `.local/claude-recovery-20261023/python`.
5. Chưa tháo mã máy MQL5 đã biên dịch; thứ tự của bản biên dịch chỉ suy từ
   kết quả.

## 6. Ghi chú phụ (không gây lệch)

- `Bot3ManagementPrelude.mqh:1` vẫn ghi "Candidate only: not compiled, not run,
  not compared", trong khi bản này đã được biên dịch và chạy
  (`mql5-run.json:27-29`). Chỉ là chú thích cũ.
