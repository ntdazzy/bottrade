Hệ thống chặn workflow nên chưa có đánh giá độc lập từ tác tử phụ. Tôi tự rà bằng Read/Grep/Glob; không chạy hay sửa gì. Mọi kết quả ca kiểm bên dưới đều là **đề xuất, chưa chạy**.

Nguồn chính là mã máy đã dịch:
- I1 = `doi-chung-mt5/gio-mua-he-20261024/bot-1-native-instructions.txt` (L# = số dòng trong tệp).
- I3 = tệp tương ứng của bot 3.

Hai tệp đều 235 dòng, trùng từng lệnh, cùng dài 0x4d7. Các lệnh nhảy ở L33/42/44/102/200/221 trỏ tới cùng dòng; chỉ địa chỉ tuyệt đối khác nhau.

## 1. Hợp đồng tại biên API (bot 3 giống bot 1)
Engine base là 0x7ff683f20000. RVA của các API khớp nhãn đo bằng chương trình nguồn biết trước, trên cùng bản tester:
- `bot-cua-toi-13/phan-tich/ky-hieu-v4/native-labels.json:470-478, 551-559, 596-604, 997-1005`
- SHA của engine bị khóa ở `cong-cu/tao-ho-so-ma-chup.py:25-26`.

| API | Đầu vào/ra (I1) | Trạng thái |
|---|---|---|
| TimeCurrent 0x7d1c40 | rcx=ctx, rdx=0 → rax int64. L10-12/24-25, L186-189, L202-209 | Đã chốt |
| TimeToStruct 0x7d1f60 | rcx=ctx, rdx=int64, r8=rsp+0x90; cả 5 lần dùng cùng 32 byte. L26-30, 190-193, 195-198, 210-213, 215-218. Không thử `al` | Đã chốt |
| Đọc `dt` | `year` đọc 1 lần ở L31 (`[rsp+0x90]`→r15d). `day_of_year` = `[rsp+0xac]`, đọc ở L194, L199, L214, L219 | Đã chốt |
| MathMod 0xaa9970 | xmm0 = số bị chia, xmm1 = 7.0 (K0) → xmm0. rcx không phải ctx (đang giữ &K0/&K2). L51-56, 57-66, 110-116, 117-122 | Đã chốt |
| StringConcatenate (dispatcher 0x7b49f0) | edx=0x174, r8d=3, r9d=0x59000a, `[rsp+0x20]`=&chuỗi đích, `[rsp+0x28]`=dword 0x520004, `[rsp+0x30]`=dword năm (4 byte cao không ghi), `[rsp+0x38]`=dword 0x590008, `[rsp+0x40]`=&hằng chuỗi. Giá trị trả bị bỏ. L80-92, 134-146, 156-165 | Op đã chốt (`api-calibration.json:14`); thẻ kiểu mới suy ra |
| Print (op 2) | edx=2, r8d=1, r9d=0x590008, `[rsp+0x20]`=0x23e5aa6cbb8 (bot 3: 0x171562b6e58). L34-41 | Đã chốt: `api-extra-r2/calibration.json:89-103` + `RecoveryApiLibrary.mq5:6-9` |
| StringToTime 0x7cd370 | rcx=ctx, rdx=&mô tả chuỗi 12 byte {u32 ở +0, u64 con trỏ UTF-16 ở +4} → rax int64. s1: L166-171, s2: L173-178 | Đã chốt |
| Gán chuỗi (RVA 0x5c0) | rcx=&đích, rdx=&RVA 0x517e0 (bot 3: 0x59d20), r8d=0, r9 = địa chỉ vị trí (không dùng khi r8=0). L68-79, 93-100, 123-133, 147-154 | B1:429-449 (B3 trùng): chỉ chép 12 byte, tăng refcount nếu u32 đầu ≠ 0; không cấp phát (0x7d1190), không có lỗi |
| Giải phóng (RVA 0x0) | s2 rồi s1, L179-184. B1:15-25: giảm refcount ở ptr−8 khi u32 đầu ≠ 0 và u32 ở ptr−0xc ≠ 0; gọi 0x7d1200 khi về 0; rồi xóa 12 byte | Đã chốt |
| Giá trị trả | AL=1 (L220-221) hoặc EAX=0 (L222); các byte cao của RAX là rác. Nơi gọi chỉ thử 1 byte (B1:8351) | Đã chốt |

**Chưa chốt:**
- **U1.** Thẻ kiểu 0x59000a/0x590008/0x520004 chỉ thấy trong dữ liệu bot 13 (chưa biết nguồn), tại `bot-cua-toi-13/bang-chung/dispatch-callsite-types.json`. Chưa có hiệu chuẩn bằng nguồn biết trước. Script kiểm thay API bằng `#define` (`Bot1AmericanDSTCheck.mq5:102-107`), nên op và thẻ kiểu của bản MQL5 biên dịch thật chưa từng được thấy.
- **U2.** Nội dung byte tại RVA 0x517e0 / 0x59d20 (xem mục 3).
- **U3.** Trình biên dịch MQL5 có tự xóa `MqlDateTime dt;` không. Mã gốc không xóa.
- **U4.** TimeToStruct thật có ghi, hoặc ghi một phần, khi gặp giá trị sai không; `StringToTime("")` trả về gì.

## 2. Nhánh lỗi
**Biến cục bộ trong mã gốc:**
- `dt` (`[rsp+0x90..0xaf]`) không được khởi tạo; L16-23 chỉ xóa 4 ô chuỗi 0x50/0x60/0x70/0x80.
- Ô chuỗi: nhánh cũ s1=0x80, s2=0x70; nhánh mới s1=0x60, s2=0x50. Mỗi ô được xóa lại ngay trước khi gán (L73-74, 97-98, 128-130, 151-152).
- Thanh ghi: r15 giữ năm rồi đổi sang tS (L174); r14 giữ tE; xmm7=S, xmm6=E, xmm8=c.

`.mqh` dùng một `dt` duy nhất và bỏ qua mọi giá trị trả (`Bot1AmericanDST.mqh:6-7, 37-45`), nên đi đúng các nhánh dưới đây mà không thêm kiểm lỗi.

| Lỗi | Điều xảy ra trong mã gốc | Kết quả |
|---|---|---|
| TTS#1 không ghi | r15d lấy byte cũ trên ngăn xếp | Không tất định: năm ≤1986 (so có dấu) → Print + false; ngược lại chạy tiếp với năm rác |
| TTS#2 không ghi | edi = doy của lần 1 (L194) | "Hôm nay" lấy từ lần đọc 1 |
| TTS#3 không ghi | So edi với chính nó, `jle` (L199-200) | false, 2 lần TimeCurrent |
| TTS#4 không ghi | ebx = startDoy (L214) | Kết quả = startDoy < endDoy |
| TTS#5 không ghi | So ebx với chính nó (L219) | false |
| Ghi đủ nhưng trả false | `al` không được thử | Như bình thường |
| Ghi một phần | Hàm chỉ đọc `year` (lần 1) và `day_of_year` | Quy về hai trường hợp trên, xét theo từng trường |
| StringToTime(s1)=0 | rsi = 0x1c20 + ((int)S−1)·86400 (L185) | startDoy = (int)S−1 (năm 1970) |
| StringToTime(s2)=0 | Tương tự ở L208 | endDoy = (int)E−1 |
| Concat không ghi | s vẫn là bản chép từ 0x517e0/0x59d20 | Phụ thuộc U2 và U4 |

## 3. Số nguyên 32 bit và chuỗi khởi tạo
**`year*5/4+1` (nhánh mới) khớp mã gốc với mọi giá trị int32.**
- Mã gốc (L103-109): `lea` tính 5y (tràn vòng), cộng 3 nếu âm (`test`/`cmovns`), `sar 2`, rồi `inc`. Tức là chia có dấu cắt về 0, rồi +1. L111 đổi sang double bằng `cvtsi2sd` có dấu.
- MQL5 `int` cũng tràn vòng khi nhân và `/` cắt về 0, nên ra cùng giá trị.
- Nếu dùng chia làm tròn xuống (floor) sẽ sai. Ví dụ y=858993459: mã gốc cho c=1, floor cho c=0.

**Nhánh cũ:**
- Mã gốc dùng `shr` không dấu (L49, L61); `.mqh` dùng `/` có dấu. Nhánh này chỉ vào được khi 1987 ≤ năm ≤ 2006 (L32-33 `jg` có dấu, L43-44 `ja` không dấu), nên hai cách cho cùng giá trị.
- L54/L65 dùng `cvtsi2sd` **có dấu**. Bản C ở B1:10696 hiện như uint→double: sai kiểu, nhưng cùng giá trị trong phạm vi này.

**Ép kiểu và cộng giờ:** `(int)S`/`(int)E` dùng `cvttsd2si` (L169, L201). Phép nhân/cộng 86400 tính bằng int32 rồi mở rộng bằng `movsxd`/`cdqe` (L172-176, L204-207). +0x1c20 cộng 64 bit (L185, L208). Khớp `.mqh:39, 44`.

**Chuỗi khởi tạo: chưa thể nói chắc là rỗng.** Bằng chứng gián tiếp:
- Hằng chuỗi có dạng: [đầu (0, 2, độ dài), căn 16 byte][chữ UTF-16][u16 0][đệm tới 8][mô tả {u32, u64}] (`tao-ho-so-ma-chup.py:75-81`). Ví dụ ".04.01": chữ ở 0x23e5aa6cbdc, mô tả ở 0x23e5aa6cbf0 (L81).
- 0x617e0 nằm ngay trước đầu của "GTP5" (0x617f0; `refs.tsv:1` = 0x61808). Vị trí này chỉ vừa với một hằng dài 0, hoặc dài 1 ký tự không in được.
- Bộ trích chuỗi cần ít nhất 1 ký tự in được (`:71`), nên chuỗi rỗng không bao giờ được liệt kê.
- Cùng nguồn này được dùng để khởi tạo các chuỗi toàn cục (B1:15110-15121).

**Byte cần xem để chốt** (giả thuyết đúng nếu khớp, sai nếu u32 độ dài ở 0x27d8/0x2d18 ≠ 0):
- Bot 1, tệp `0000023e5aa5f000-program-data.bin`:
  - offset 0x27d0: `00000000 02000000 00000000`
  - offset 0x27dc: `0000`
  - u64 ở 0x27e4: `DC17A65A3E020000` (0x23e5aa617dc), hoặc 0.
- Bot 3, tệp `00000171562a7000-program-data.bin`:
  - offset 0x2d10..0x2d1d: giống bot 1
  - u64 ở 0x2d24: `1C9D2A5671010000`.

Chạy công cụ cũng trả lời trực tiếp được câu này: `kiem-gio-mua-he-bot-1-3.py:178` so chuỗi ở ô đích với `before` = "" (`Bot1AmericanDSTCheck.mq5:83-84`).

## 4. Ma trận kiểm đề xuất (chưa chạy)
**Ngày đầu (S) và cuối (E) theo công thức gốc** (doy đếm từ 0):

| Năm | Nhánh | S (doy) | E (doy) |
|---|---|---|---|
| 1986 | lỗi | Print 1 lần, false, 1 lần TimeCurrent | |
| 1987 | cũ | 05/04 (94) | 25/10 (297) |
| 1999 | cũ, E=31 | 04/04 (93) | 31/10 (303) |
| 2000 | cũ, năm nhuận chia hết 400 | 02/04 (92) | 29/10 (302) |
| 2006 | cũ | 02/04 (91) | 29/10 (301) |
| 2007 | mới, c=2509 | 11/03 (69) | 04/11 (307) |
| 2024 | mới, nhuận | 10/03 (69) | 03/11 (307) |
| 2026 / 2099 / 3000 | mới | 08/03 (66) | 01/11 (304) |
| 2100 | thế kỷ, không nhuận | 13/03 (71) | 06/11 (309) |
| 2400 | nhuận, chia hết 400 | 09/03 (68) | 02/11 (306) |

**Biên cả ngày** (3 lần đọc giờ bằng nhau, áp dụng cho mọi năm trên):
- Kỳ vọng false: S−1 lúc 23:59:59; ngày S lúc 00:00, 02:00 và 23:59:59; ngày E lúc 00:00 và 23:59:59; ngày E+1; 01/01 lúc 00:00; 31/12 lúc 23:59:59.
- Kỳ vọng true: S+1 lúc 00:00; E−1 lúc 23:59:59.

**Lỗi chuyển đổi, năm 2026** (kết quả / số lần TimeCurrent; ô in đậm là ô khác với bình thường):

| Ca | 01/03 | 01/06 | 01/11 |
|---|---|---|---|
| Bình thường | F/2 | T/3 | F/3 |
| TTS#3 không ghi | F/2 | **F/2** | **F/2** |
| TTS#4 không ghi | F/2 | T/3 | **T/3** |
| TTS#5 không ghi | F/2 | **F/3** | F/3 |
| TTS#2..5 không ghi | F/2 | **F/2** | **F/2** |
| s1=0 | **T/3** | T/3 | F/3 |
| s2=0 | F/2 | **F/3** | F/3 |
| s1=s2=0 | **F/3** | **F/3** | F/3 |

**Năm 1987:**
- 01/11, TTS#4 không ghi → T/3 (bình thường F/3).
- 01/03, s1=0 → T/3 (bình thường F/2).
- 01/06, s2=0 → F/3 (bình thường T/3).

**Đổi giờ giữa các lần đọc** (lần đọc 1 → 2 → 3):
- 2026: 31/10 → 31/10 → 01/11 → F/3.
- 2026: 08/03 23:59:59 → 09/03 00:00 → 09/03 00:00:01 → T/3.
- 2026: 01/11 00:00 → 01/11 00:00 → 31/10 23:59:59 → T/3.
- 2025-12-31 23:59:59 → 2026-01-01 → F/2; chuỗi dựng là "2025.03.01".
- 2006-12-31 23:59:59 → 2007-07-01 → 2007-07-01 → T/3; đi nhánh cũ với chuỗi "2006.04.01".
- 1986-12-31 → … → Print, F/1.
- **Ca mới đề xuất:** 2026-03-01 → 06-01 → 06-01 kèm TTS#2 không ghi → F/2 (nếu không lỗi thì T/3).

**Ép giá trị `dt.year` sau TTS#1.** Ca này chỉ so đối số của MathMod và Concat; kết quả cuối lấy từ MT5 thật.

| Năm ép | 5y (int32) | c | fmod | S/E |
|---|---|---|---|---|
| −1, −2147483648 (ca mới) | — | — | — | nhánh lỗi: Print, F/1 |
| 429496729 | 2147483645 | 536870912 | 4 | 10/3 |
| 429496730 | −2147483646 | −536870910 | −2 | 16/9 |
| 536870912 | −1610612736 | −402653183 | −2 | 16/9 |
| 858993459 | −1 | 1 | 1 | 13/6 |
| 858993460 | 4 | 2 | 2 | 12/5 |
| 1073741823 | 1073741819 | 268435455 | 1 | 13/6 |
| 2147483647 | 2147483643 | 536870911 | 3 | 11/4 |

## 5. Nhận xét về bộ kiểm hiện có
**Mức vừa:**
- `kiem-gio-mua-he-bot-1-3.py:53-58` chọn ngày biên theo Chủ nhật của lịch thật. Với 2100/2400/3000, lịch thật cho 14/03–07/11, 12/03–05/11 và 09/03–02/11, lệch với công thức gốc. Vì vậy biên thật của bot cho ba năm này chỉ được phủ bởi nhóm kiểm mỗi ngày lúc 12:00 (`:48-52`). Nên lấy ngày biên từ S/E của công thức gốc.
- Cách thay API bằng `#define` không chứng minh được op, thẻ kiểu hay thanh ghi của bản biên dịch thật (U1). Cần một bản build không có hàm giả, gọi `Bot1AmericanDST`/`Bot3AmericanDST`, chụp mã máy rồi so với I1/I3. Hoặc chạy cùng bộ giả lập trên hàm đã biên dịch đó.

**Mức thấp:**
- Còn thiếu các ca: năm âm, TimeCurrent=0, "ghi đủ nhưng trả false", và "Concat không ghi".
- Nếu thêm ca "Concat không ghi": hằng chuỗi có u32 ở ptr−0xc = 0 nên sẽ không được giải phóng (B1:15-16). Khi đó điều kiện `frees in (0,2)` ở `:201` phải sửa.
- TTS#1 không ghi vẫn chưa so tất định được; công cụ đã ghi giới hạn này ở `:261`.
- `Bot1AmericanDST.mqh:20, 31` gán `end_text` trước Concat(s1), trong khi mã gốc gán s2 sau Concat(s1) (L92 rồi L93-100). Giữa hai bước không có lời gọi API nào nên vết kiểm không đổi; nếu muốn khớp từng bước thì tách khai báo như đề xuất trước.
- Các phép gán 0 ở `.mqh:14-15` không có trong mã gốc nhưng vô hại.

Kết luận: các bước trong mã máy của hai bot giống nhau, chỉ khác địa chỉ, và hai hàm gán chuỗi cũng giống nhau (B3:390-450 = B1:390-450). Chưa có kiểm chạy nào, nên tôi không xác nhận bản MQL5 khớp 100% với bản gốc.
