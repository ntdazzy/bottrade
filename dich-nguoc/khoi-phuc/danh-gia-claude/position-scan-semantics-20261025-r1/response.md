# Checklist dựng lại 4 hàm quét vị thế (bot1 0x2fa00/0x2fce0, bot3 0x3ce40/0x3d220)

**Kết luận:** Cả 4 hàm dùng chung một khung. Khác nhau ở ba điểm:
- **Số định danh magic:** bot1 có 8 (gốc+1…+8), bot3 có 15 (gốc+1…+15).
- **Giá trị so loại vị thế:** hàm mua so `==0`, hàm bán so `==1`.
- **Địa chỉ.**

Tôi chưa so khi chạy thật. Hai tệp analysis.json đều ghi `analysis_complete=false` và `runtime_verified=false`.

**Tệp bằng chứng** (số sau dấu `:` là số dòng):
- B1N/B3N: `bot-cua-toi-{1,3}/phan-tich/dong-vi-the/scan-20261025-r1/native-guards.txt`
- B1F/B3F: `functions.c` cùng thư mục
- C1N/C3N: `close-20261024-r1/native-guards.txt`
- C1S/C3S: `close-20261024-r1/semantics.json`

Các lệnh tôi tra chéo trong analysis.json đều khớp với native-guards.

## 1. Địa chỉ tương đối (= địa chỉ tuyệt đối − code_base)

| Vai trò | Bot1 (−0x23e5aa10000) | Bot3 (−0x17156250000) |
|---|---|---|
| Hàm quét mua / bán | 0x2fa00 / 0x2fce0 | 0x3ce40 / 0x3d220 |
| Gốc định danh (đọc 4 byte) | 0x6a610 | 0x1d6ff0 |
| Biến vé toàn cục (8 byte) | 0x677f8 | 0x74838 |
| Con trỏ chuỗi toàn cục đem so | 0x6791c | 0x7495c |
| Đối số 2 / đối số 4 (mua; bán) của 0x5c0 | 0x6a43c / 0x5ec20; 0x5ec30 | 0x1d6e3c / 0x68fb0; 0x68fc0 |
| Hàm 0x5c0 (gán chuỗi) / 0x0 (dọn chuỗi) | 0x5c0 / 0x0 | 0x5c0 / 0x0 |
| Guard (trùng RVA trong C1S/C3S) | 0x3d010 | 0x47d20 |
| Nơi guard ghi magic | 0x67725 (C1N:253-255) | 0x74765 (C3N:253-255) |

- Con trỏ ngữ cảnh API 0x23e575eae78 / 0x171514ca538 nằm thấp hơn code_base (−0x3425188 / −0x4d85ac8). Các hàm API ở 0x7ff6846f7da0…8010 nằm ngoài ảnh mã. Vì vậy chúng không có địa chỉ tương đối.
- Cảnh báo đọc đuôi số: 0x23e5aa7a610 → **0x6a610** (không phải 0x7a610). 0x17156426ff0 → **0x1d6ff0** (không phải 0x26ff0).

## 2. Checklist chung cho cả 4 hàm

**Khung hàm và vòng lặp**
1. Khai một biến `string` cục bộ ở phạm vi hàm. Khi vào hàm nó là NULL. Dùng lại qua mọi vòng, chỉ dọn một lần khi thoát (B1N:12-13, B1N:166-168). Không có lệnh dọn nào trong thân vòng, nên không khai biến này trong vòng.
2. Gọi `PositionsTotal()` đúng 1 lần (B1N:14). Nếu kết quả `<0` (so số nguyên 32-bit có dấu, B1N:15-16) thì bỏ cả vòng và không đọc gốc định danh.
3. Viết `for(int i=PositionsTotal(); i>=0; i--)`:
   - Bắt đầu từ chỉ số **total**, nhảy thẳng vào thân vòng (B1N:17, :47).
   - Dừng sau khi xử lý i=0 (B1N:57-60, phép so dùng giá trị chỉ số cũ).
   - Tổng cộng total+1 vòng. Khi total=0 vẫn gọi `PositionGetTicket(0)`.
   - Không dùng total−1. Không gọi lại `PositionsTotal` giữa vòng.

**Định danh magic**
4. Đọc gốc định danh **1 lần**, 32-bit, sau `PositionsTotal` (B1N:24, B3N:24). Chụp vào biến cục bộ kiểu `int` hoặc truyền theo giá trị. Không truyền tham chiếu rồi đọc trong vòng.
5. id_k = `(long)(int)(gốc+k)`: cộng trong 32-bit (cho phép tràn vòng), rồi mở rộng có dấu lên 64-bit (B1N:25-46, lệnh `lea` + `movsxd`/`cdqe`). Trong MQL5 viết `PositionGetInteger(POSITION_MAGIC)==base+k` với `base` kiểu int. Không viết `(long)base+k`.
6. Phạm vi k: bot1 từ 1 đến 8 (B1N:67-106), bot3 từ 1 đến 15 (B3N:88-162). So theo thứ tự tăng dần, không có k=0.
7. Mỗi phép so **gọi lại** `PositionGetInteger(12)` và dừng ở lần khớp đầu tiên (chuỗi `||`). So đủ 64-bit. Không lưu magic vào biến tạm.
8. Dòng bot3 `lVar11 = local_50` (B3F:100, :218) chỉ là nạp lại thanh ghi r12 từ bản sao id1 trên ngăn xếp (B3N:36→209 cho hàm mua, B3N:271→437 cho hàm bán). Nó **không** đọc lại gốc định danh.

**Biến vé**
9. Gọi `PositionGetTicket(i)` rồi ghi ngay kết quả vào biến vé toàn cục, **kể cả khi bằng 0**, trước khi rẽ nhánh (B1N:63-66). Phép kiểm `!=0` dùng giá trị vừa trả về, so 64-bit.
10. Biến vé phải là biến tồn tại lâu (biến toàn cục, hoặc trường trạng thái truyền theo tham chiếu), không phải biến cục bộ. Trong hàm không có lần ghi vé nào khác.

**So chuỗi**
11. Chỉ sau khi khớp magic mới gọi `PositionGetString(0)` (là symbol, theo hợp đồng API trong C1S), rồi gán vào biến ở mục 1 (B1N:108-116).
12. Đọc con trỏ chuỗi toàn cục **mỗi lần so**, ngay sau phép gán (B1N:117-119). Không chụp trước vòng.
13. So bằng `==` viết thẳng trong hàm (không gọi `StringCompare` hay API). Biến cục bộ đứng bên trái. Quy tắc:
    - Cùng con trỏ → bằng, kể cả NULL==NULL (B1N:120-121).
    - Chỉ một bên NULL → khác. NULL khác với "" có vùng nhớ (B1N:122-125).
    - Độ dài lấy từ ô uint32 ngay trước con trỏ (ptr−4), rồi lấy độ dài nhỏ hơn, so không dấu (B1N:126-130).
    - So từng mã UTF-16 (không dấu) đến chỗ khác đầu tiên hoặc hết độ dài nhỏ hơn, có so cả ký tự cuối (B1N:139-147).
    - Nếu hết mà không khác thì bằng khi và chỉ khi hai độ dài bằng nhau (B1N:131-132, 148-157).
    - Phân biệt hoa/thường, không cắt khoảng trắng.

**Loại vị thế, khối lượng, guard**
14. Chỉ khi chuỗi bằng mới gọi `PositionGetInteger(2)`, 1 lần, so đủ 64-bit: hàm mua `==0` (B1N:50-54), hàm bán `==1` (B1N:329-333). **Không** chép ép kiểu `(uint)` ở Bot1PositionClose.mqh:20 — chỗ đó là phép so 32-bit thấp của hàm đóng lệnh trực tiếp, khác với hàm quét.
15. Khi khớp loại: gọi `PositionGetDouble(3)` đúng 1 lần và bỏ kết quả (B1N:158-161; không lệnh nào dùng xmm0 sau đó).
16. Ngay sau đó đọc lại vé từ biến toàn cục (B1N:162, lệnh `mov rcx,[r13]`). Gọi **trọn** guard `Bot1TryClosePosition`/`Bot3TryClosePosition` (Bot1PositionClose.mqh:31) với vé đó. Không kiểm kết quả trả về, chuyển sang i−1.
    - reference/threshold vẫn truyền theo tham chiếu, để guard tự đọc lại đúng thời điểm như C1S mô tả.
    - Không bỏ phép kiểm loại của hàm quét dù guard có kiểm lại.
    - Không đưa phép lọc SL/giá vào hàm quét.

**Độ rộng phép so:** vé, magic, loại, con trỏ = 64-bit; total và chỉ số = int32 có dấu; độ dài = uint32 (chỉ xét hiệu bằng 0); ký tự = uint16.

## 3. Bot1 khác bot3 ở đâu

| | Bot1 | Bot3 |
|---|---|---|
| Định danh | 8 (gốc+1…+8) | 15 (gốc+1…+15) |
| Mặc định theo cai-dat-da-kiem.md | 9000 → 9001…9008 (:41) | 8000 → 8001…8015 (:37) |
| Số lần gọi magic với vị thế không khớp | 8 | 15 |
| Gốc làm chỉ id cuối bị tràn | 2147483640 → id8 = −2147483648 | 2147483633 → id15 = −2147483648 |
| Gốc âm làm một id bằng 0 | −8…−1 | −15…−1 |
| Khung ngăn xếp; thanh ghi tạm khi so chuỗi | 0x68; r13 (nạp lại địa chỉ vé) | 0xa8; r12 (nạp lại từ [rsp+0x98]) |

## 4. Vị trí lệnh theo từng hàm

| Việc | B1 mua | B1 bán | B3 mua | B3 bán |
|---|---|---|---|---|
| PositionsTotal | 0x2fa35 | 0x2fd15 | 0x3ce78 | 0x3d258 |
| Đọc gốc (1 lần) | 0x2fa7d | 0x2fd5d | 0x3cec0 | 0x3d2a0 |
| GetTicket / ghi vé | 0x2fb12/0x2fb17 | 0x2fdd2/0x2fdd7 | 0x3cfb2/0x3cfb7 | 0x3d372/0x3d377 |
| Gọi magic (đầu…cuối) | 0x2fb25…0x2fb9c | 0x2fde5…0x2fe5c | 0x3cfc5…0x3d0db | 0x3d385…0x3d49b |
| GetString / gán 0x5c0 | 0x2fbb5/0x2fbde | 0x2fe75/0x2fe9e | 0x3d0f5/0x3d11e | 0x3d4b5/0x3d4de |
| Đọc con trỏ chuỗi toàn cục | 0x2fbef | 0x2feaf | 0x3d12f | 0x3d4ef |
| Loại vị thế | 0x2fae8 ==0 | 0x2ff50 ==1 | 0x3cf88 ==0 | 0x3d58e ==1 |
| GetDouble(3) (bỏ kết quả) | 0x2fc9f | 0x2ff6e | 0x3d1dd | 0x3d5ac |
| Đọc lại vé → gọi guard | 0x2fca1→0x2fcaf | 0x2ff70→0x2ff7e | 0x3d1df→0x3d1ed | 0x3d5ae→0x3d5bc |
| Dọn chuỗi | 0x2fcc5 | 0x2ff94 | 0x3d203 | 0x3d5d2 |

## 5. Lời gọi có thể đổi biến toàn cục giữa hai lần đọc

| Biến | Lời gọi nằm giữa | Ca kiểm bắt lỗi giữ giá trị cũ sai chỗ (bộ chạy mã máy có giả lập API) |
|---|---|---|
| Gốc định danh | Chỉ đọc 1 lần sau PositionsTotal. C1N/C3N không có tham chiếu trực tiếp tới địa chỉ này. Nếu đúng là `input` thì mã EA không gán được. | Đổi gốc trong lời gọi giả PositionsTotal → bản gốc phải dùng giá trị mới. Đổi trong GetTicket, GetInteger hoặc guard → bản gốc vẫn dùng bản chụp. |
| Vé | GetInteger(12)×k, GetString(0), 0x5c0, GetInteger(2), GetDouble(3) | Đổi vé trong lời gọi giả GetDouble(3) → guard phải nhận vé mới. |
| Con trỏ chuỗi | Giữa hai lần so: guard → đóng lệnh trực tiếp → FillingCheck (0x231c0/0x2e8f0), gửi lệnh (0x950); rồi GetTicket, GetInteger, GetString, 0x5c0 | Đổi chuỗi trong GetString(0) → ảnh hưởng ngay lần so đó. Đổi trong guard → ảnh hưởng lần so sau. |
| Magic vị thế | Mỗi phép so là một lần gọi mới | Cho lời gọi giả trả các giá trị khác nhau mỗi lần, và đếm số lần gọi. |

- Trong C1N/C3N, guard và hàm đóng lệnh trực tiếp không tham chiếu trực tiếp vé, chuỗi hay gốc định danh. Guard chỉ ghi magic ở 0x67725/0x74765, là ô mà hàm quét không đọc.
- Thân các hàm 0x5c0, FillingCheck và 0x950 không có trong các tệp này, nên chưa loại trừ được việc chúng ghi vào các biến trên.
- Trong MT5 thật, các sự kiện chạy lần lượt, không chen ngang giữa hàm. Vì vậy các ca "đổi giữa chừng" chỉ làm được trong bộ chạy mã máy có giả lập API.

## 6. Ca biên cần kiểm

- **total=0:** gọi đúng 1 lần `GetTicket(0)`, và sau hàm biến vé bằng 0. Bản viết kiểu total−1 sẽ giữ nguyên giá trị cũ.
- **total=N:** lần GetTicket đầu tiên dùng chỉ số N, tổng N+1 lần. Sau hàm, biến vé = vé ở chỉ số 0, kể cả khi vị thế đó có magic lạ.
- **Magic:**
  - Magic = id+2³² → không khớp.
  - Gốc = INT_MAX → id1 = 0xFFFFFFFF80000000. Magic 2147483648 → không khớp.
  - Gốc âm → các vị thế magic 0 cũng khớp.
- **Loại:** giả lập loại trả 0x100000000 → không gọi guard.
- **Chuỗi:**
  - NULL/NULL → bằng; NULL/"" → khác; ""/"" → bằng.
  - Chuỗi là tiền tố của chuỗi kia, khác ở ký tự cuối, hoặc chỉ khác hoa/thường → khác.
  - Cùng nội dung nhưng khác vùng nhớ → bằng.
- **Khối lượng:** trả NaN, 0 hoặc số âm → vẫn gọi guard đúng 1 lần.
- **Thứ tự gọi:** magic → chuỗi → loại → khối lượng → guard.
- **Trạng thái sau hàm:** vị thế đang được chọn và `_LastError` (do `GetTicket(total)`) cần đo, không đoán.

## 7. Phần chưa rõ nguồn gốc (không viết luật theo suy đoán)

- Hàm nào gọi 4 hàm này và gọi khi nào.
- Ý nghĩa của chuỗi toàn cục 0x6791c/0x7495c. Không gọi nó là `_Symbol` khi chưa có bằng chứng.
- Ngoài 4 hàm này, còn ai đọc hoặc ghi biến vé.
- Ngữ nghĩa của hàm 0x5c0: cờ `r8b=1`, vai trò của 0x6a43c/0x1d6e3c (C1N:40-52 có cùng mẫu gọi, nhưng mới là dấu hiệu) và vai trò của đối số 4. Thân hàm 0x0 cũng chưa có.
- `ST1_MagicNumber` mới được ánh xạ từ cai-dat-da-kiem.md, và tệp đó ghi kiểu khai báo "chưa chốt". Mã máy chỉ chứng minh phép cộng là int32 có dấu. Chưa rõ ý nghĩa của 8/15 khoảng bù.
- Các hằng 0xc, 2, 3, 0 lấy theo hợp đồng API trong C1S. analysis.json của lượt quét ghi rằng các hằng này vẫn cần xác nhận.
- reference/threshold của guard chưa rõ tên và nguồn; **không** gọi là bid/ask. Hàm quét không đọc các giá trị này.

## 8. Giới hạn

- **Cấu hình lượt này:** claude-opus-5-5, mức suy luận max (theo thông tin phiên). Ultracode đang bật, nhưng tôi không chạy Workflow hay agent vì yêu cầu cấm. Đây là đánh giá của một mình tôi, cần đối chiếu lại.
- Tôi không chạy lệnh shell, nên chưa tự tính lại SHA-256 của các tệp trong `receipt.json`.
- Tệp `scan-20261025-r1/semantics.json` của cả hai bot xuất hiện **trong lúc tôi đang phân tích** (lần Glob đầu chưa có). Tôi không đọc và không dùng hai tệp này.
- `Bot1PositionSelection.mqh` và `Bot3PositionSelection.mqh` đã tồn tại (dòng 1 ghi đúng các RVA trên). Tôi chưa xem nội dung; có thể dùng checklist này để đối chiếu.
- Đạt các ca kiểm trên chỉ chứng minh 4 hàm này đúng trên bộ ca đó, không chứng minh toàn bộ EA.