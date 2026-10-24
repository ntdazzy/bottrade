## Kết luận nhanh

- Hai bot làm giống nhau. **Bảng A** có 500 dòng, mỗi dòng 3 số `double`: vé, mức dừng lỗ ảo, dấu thời gian. **Bot 3 có thêm bảng B**: 500 dòng × 2 `double` (vé, mức chốt lời ảo). Bot 1 không có bảng B và không có hàm nào giống 0x482b0.
- **Tìm vé:** quét từ dòng 0 đến 499, so số `double` đúng bằng, lấy dòng **đầu tiên** khớp. **Ô trống** là dòng có vé `== 0.0`.
- **Cập nhật:** các hàm được giao không sửa mức của dòng đã có. Mức chỉ được sửa thẳng trong hàm quản lý vị thế.
- **Khi hết ô:** gọi hàm đồng bộ để xóa dòng của các vé đã đóng, rồi thử lại. Nếu vẫn hết ô thì không lưu, vẫn trả mức, và in một thông báo (7 đối số) khi vé khác vé đã báo lần trước. Nội dung thông báo chưa đọc được.
- **Thời gian chờ** lấy từ cài đặt `SetVSL_to_hardSL_sec_delay` (mặc định 99 giây):
  - chờ ≤ 0 → luôn trả `false`;
  - dòng chưa có dấu thời gian → trả `true` ngay;
  - đã có dấu → trả `TimeCurrent() − dấu >= chờ`.
- **Giới hạn:** đây là kết quả đọc mã C trung gian. Tôi chưa chạy mã máy gốc và chưa biên dịch mã MQL5 ở mục 8.

Ký hiệu dùng trong bài:
- B1 = `dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c`
- B3 = `dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c`
- K1, K3 = `cai-dat-da-kiem.json` của bot 1 và bot 3.

## 1. Vị trí (khớp `danh-sach-ham.json` và bản đồ r5)

| Phần | Bot 1 | Bot 3 |
|---|---|---|
| Lấy/tạo mức dừng ảo | 0x3d200, [B1:27109](dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c:27109)–27190 | 0x47f10, [B3:31968](dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:31968)–32049 |
| Lấy/tạo mức chốt ảo | không có | 0x482b0, B3:32053–32109 |
| Kiểm thời gian chờ | 0x3d5a0, B1:27194–27219 | 0x484c0, B3:32113–32138 |
| Đóng dấu thời gian | 0x3d640, B1:27223–27244 | 0x48560, B3:32142–32163 |
| Đồng bộ (gọi khi hết ô) | 0x18790, B1:11091–11206 | 0x20bc0, B3:15263–15386 |

Đối chiếu: `ban-do-bot-1-3/luot-20261023-r5/bot-1.json:10053-10168` và `bot-3.json:11011-11170`; `danh-sach-ham.json` bot 1: 1442–1485, bot 3: 1417–1476.

## 2. Bảng và biến dùng chung

| Thành phần | Bot 1 (RVA) | Bot 3 (RVA) | Độ rộng / kích thước | Bằng chứng |
|---|---|---|---|---|
| Bảng A | 0x62590–0x6546f | 0x6d680–0x7055f | 500 × 24 byte: [0] vé, [1] mức, [2] dấu thời gian | vòng `-12000…0` bước `0x18`: B1:27124–27131; vòng 0…499: B1:11156–11171, B3:15317–15342 |
| Bảng B | — | 0x70560–0x7249f | 500 × 16 byte: [0] vé, [1] mức | B3:32065–32072 (`-8000`, bước `0x10`); B3:15345–15369 |
| Cờ G | 0x66410 | 0x73450 | 1 byte, so `== 1` | gán 1 ở B1:14893, B3:20483; grep không thấy chỗ ghi khác |
| W: vé đã báo hết ô ở bảng A | 0x66418 | 0x73458 | số nguyên 64 bit | B1:14892, 27184–27185; B3:20482, 32043–32044 |
| W2: vé đã báo hết ô ở bảng B | — | 0x73460 | 64 bit | B3:20481, 32103–32104 |
| D: thời gian chờ | 0x62420 | 0x6d518 | int 32 bit có dấu (ô ngay sau là biến khác: B1:3739, B3:7325) | B1:3738 và 14950 (=99); B3:7324 và 20540; K1:1517–1540; K3:1290–1312 |
| U: đơn vị khoảng cách | 0x66d98 | 0x73dd8 | double | B1:3705–3716; B3:7298–7307 |
| Mảng vé đang mở | 0x6a3c0 | 0x1d6d10 | mảng động, phần tử 8 byte, mã kiểu 0x55 (mã này cũng dùng cho giá trị `long` ở B1:907, 2536) | B1:11108–11133, 14792; B3:15283–15306 |

Luồng khởi tạo 0xc30 xóa bảng A khi G==1 (B1:2014–2016). Ở bot 3, đoạn này xóa cả bảng A và bảng B (B3:2114–2117).

## 3. Từng hàm

### 3.1 0x3d200 / 0x47f10: `double f(int side, double price, double distance, long ticket)`

Chữ ký ở B1:27113 và B3:31972.

**Đầu vào** (nghĩa lấy từ nơi gọi):
- `side`: 1 khi gọi từ hàm quản lý lệnh mua (mức nằm dưới giá), 2 khi gọi từ hàm lệnh bán (mức nằm trên giá). Bằng chứng: B1:17418, 18522; B3:23301, 24655.
- `price`: giá mở đã làm tròn, lấy bằng `PositionGetDouble` mã 4 (B1:17204–17217; B3:23047–23060).
- `distance`: khoảng dừng tính theo đơn vị U.
- `ticket`: vé. Nơi gọi giữ vé trong biến `double`, rồi đổi sang số nguyên trước khi truyền (B1:17203, 17351; B3:23046, 23234).

**Đầu ra:** mức dừng kiểu `double`.

**Các bước:**
1. Nếu G==1: gặp dòng đầu tiên có `vé == (double)ticket` thì trả ngay mức của dòng đó. Không gọi API, không ghi gì (B1:27123–27132).
2. Nếu không thấy, tính mức:
   - side 2: gọi `SymbolInfoInteger(sym, 0x11)` trước, rồi tính `x = distance*U + price`;
   - side 1: tính `x = price - distance*U`;
   - side khác: mức = `0.0`, không gọi API (B1:27133–27158).
3. Làm tròn mức (B1:27136–27159):
   - nếu `(long)x == LONG_MIN` thì giữ nguyên x;
   - nếu không: lấy số chữ số là 32 bit thấp, tối đa 11, rồi tính `(long)((x−nguyên)*10^d + h[x>0])/10^d + nguyên`.
   - Đây đúng là công thức của `Bot1RoundPrice`/`Bot3RoundPrice`. Chỉ khác là cặp hằng h nằm ở địa chỉ riêng của hàm này.
4. Nếu G==1: tìm ô trống đầu tiên. Ghi `{(double)ticket, mức, 0}` rồi trả mức (B1:27161–27168, 27175–27179).
5. Không có ô trống (hoặc G≠1): gọi đồng bộ, tìm ô trống lần nữa và ghi như bước 4 (B1:27169–27183).
6. Vẫn không có ô trống: nếu `W != ticket` thì gán `W = ticket`, gọi `PositionsTotal()`, rồi gọi Dispatch mã 2 với 7 đối số (B1:27184–27188). Hàm vẫn trả mức, nhưng không lưu (B1:27189).

### 3.2 0x482b0 (chỉ bot 3): `double f(double value, long ticket)`

Chữ ký ở B3:32057.

**Đầu vào:**
- `value`: nơi gọi truyền chốt lời thật đã làm tròn (`PositionGetDouble` mã 7: B3:23033–23045, truyền ở 23303). Nhánh bán truyền ở B3:24657.
- `ticket`: C **không hiện** đối số này ở cả hai điểm gọi.

**Các bước:**
- G==1:
  - thấy vé trong bảng B → trả mức đã lưu (B3:32063–32072);
  - không thấy và `value <= 0.0` → trả hằng `0.0`, không lưu (B3:32073–32075);
  - còn ô trống → ghi `{(double)ticket, value}` và trả `value` (B3:32076–32084, 32097–32098).
- G≠1 và `value <= 0.0` → trả `0.0` (B3:32086–32088).
- Hết ô: đồng bộ, thử lại. Vẫn hết thì xử lý W2 và in thông báo như mục 3.1, rồi trả `value` (B3:32089–32108).
- **Vì sao gọi là chốt lời ảo:** nơi gọi đóng vị thế khi `0 < mức && mức <= bid` với lệnh mua (B3:23305–23306) và `0 < mức && ask <= mức` với lệnh bán (B3:24659). Tên "chốt lời ảo" là tên phục dựng, suy từ cách dùng này.

### 3.3 0x3d5a0 / 0x484c0: `bool f(long ticket)`

- Cần `0 < D` và G==1. Nếu không thỏa → trả `false` (B1:27202, 27218).
- Với dòng đầu tiên có vé khớp, đặt `s = (long)dấu`:
  - `s == 0` → trả `true`, không gọi `TimeCurrent` (B1:27208, 27213);
  - ngược lại → trả `D <= TimeCurrent() - s`, so bằng số 64 bit (B1:27209–27211).
- Không thấy vé → `false`.
- Hàm chỉ đặt byte thấp của giá trị trả về; nơi gọi so `!= 0` (B1:17425–17426).

### 3.4 0x3d640 / 0x48560: `void f(long ticket)`

- Nếu G==1 và có dòng khớp: ghi vào dòng đầu tiên `dấu = (double)TimeCurrent()` rồi thoát (B1:27231–27238).
- Không thấy vé → không làm gì, không gọi API, **không thêm dòng mới**.

### 3.5 Hàm đồng bộ (chỉ xét phần cần cho các hàm trên)

- Đảm bảo mảng vé có ít nhất 64 phần tử (B1:11108–11110).
- Duyệt các vị thế: lấy vé có `PositionGetTicket(i) != 0` và `(ulong)PositionGetInteger(2) < 2`. Khi mảng đầy thì nới lên `count+64` (B1:11111–11137). Mảng là biến toàn cục và chỉ lớn lên.
- Nếu G==1: mỗi dòng có `0.0 < vé` mà `(long)vé` không nằm trong `count` vé đầu của mảng → xóa cả dòng (B1:11139–11197).
  - Bot 3 làm việc này cùng lúc cho dòng A và dòng B có cùng chỉ số (B3:15312–15374).
- Nếu chỉ số mảng vượt giới hạn → báo lỗi chạy chương trình rồi dừng bằng `int3` (B1:11199–11204). Đây tương ứng lỗi "array out of range" của MQL5.
- Luồng điều phối chỉ gọi hàm đồng bộ khi `EnableVirtualSLTP` bật (B1:9224–9226; B3:12986–12988). Mặc định cài đặt này là `false` (K1:1487; K3:1260). Khi tắt, bảng chỉ được dọn lúc hết ô.

## 4. Nơi gọi cần thiết

| Việc | Bot 1 | Bot 3 |
|---|---|---|
| Chế độ ảo khi `2-(EnableVirtualSLTP==0)` = 2 (B1:3737, B3:7323) | mua 17415–17460; bán 18519–18559 | mua 23298–23347; bán 24652–24696 |
| Chế độ thường **vẫn gọi** hàm lấy/tạo mức dừng, nên bảng A vẫn đầy dần | 17620, 18726 | 23628, 24977 |
| Đóng vị thế khi chạm mức dừng ảo | `bid <= mức` 17420; `mức <= ask` 18524 | 23305; 24659 |
| Sau khi qua thời gian chờ: sửa dừng lỗ thật rồi đóng dấu, không xét kết quả sửa | 17443–17460; 18542–18559 | 23329–23347; 24678–24696 |
| Sửa mức đã lưu (chỉ có ở nơi gọi) | A: 17606–17616, 18158–18165, 18712–18719, 19374–19381 | A: 23557–23567, 24252–24259, 24907–24914, 25695–25702; B: 23613–23623, 24962–24969 |

## 5. Phép so, lỗi dữ liệu, tác dụng phụ

**Phép so:**
- So vé theo chuẩn IEEE: NaN không bao giờ khớp. Vì `-0.0 == 0.0`, dòng có vé `-0.0` vẫn bị coi là ô trống.
- Gọi với `ticket = 0` sẽ khớp ô trống đầu tiên: trả mức đang nằm trong ô đó và không thêm dòng.
- Hàm đồng bộ chỉ xét dòng có `0.0 < vé`, nên dòng có vé âm hoặc NaN không bao giờ bị xóa.
- Vé lớn hơn 2^53 có thể bị trùng khóa sau khi đổi sang `double` (ca biên, vé thực tế nhỏ hơn nhiều).
- Dấu thời gian được đọc bằng cách cắt phần lẻ, nên dấu có |giá trị| < 1 bị coi như 0.
- Biên thời gian chờ là `>=`.
- Bảng B trả hằng `+0.0` khi `value <= 0` (không trả lại chính `value`).

**Lỗi dữ liệu (gốc không kiểm, giữ nguyên như vậy):**
- `SymbolInfoInteger` lỗi trả 0 → mức bị làm tròn thành số nguyên.
- U = 0 → mức bằng đúng giá mở.
- x quá lớn hoặc NaN → lưu và trả giá trị chưa làm tròn.
- `side` khác 1 và 2 → lưu mức `0.0`.
- Dấu thời gian là NaN → `(long)` cho LONG_MIN, phép trừ bị tràn → hàm chờ trả `false` mãi.

**Tác dụng phụ:**
- Ghi dòng mới (hàm lấy/tạo) và ghi dấu thời gian (hàm đóng dấu).
- Khi đồng bộ chạy, `PositionGetTicket` chọn lần lượt mọi vị thế. Vị thế đang được chọn vì vậy đổi sang vị thế đọc cuối cùng; nơi gọi đọc `PositionGet*` sau đó sẽ đọc vị thế khác.
- Ở bot 3, đồng bộ gọi từ bảng A cũng xóa dòng của bảng B, và ngược lại.
- Các hàm này không lưu GlobalVariable hay tệp. Sau khi khởi tạo lại, bảng bị xóa (nếu luồng khởi tạo đi tới đoạn B1:2014 / B3:2114; tôi chưa lần hết các nhánh của 0xc30).

## 6. Có bằng chứng và chưa đủ xác nhận

**Có bằng chứng trực tiếp trong C** (dòng đã dẫn ở trên):
- kích thước bảng, bước nhảy, thứ tự quét, điều kiện ô trống;
- công thức tính mức, thứ tự gọi API;
- hàm đồng bộ, W/W2, logic thời gian chờ, giá trị khởi tạo;
- nối D và chế độ với tên cài đặt;
- bảng lũy thừa 10 dùng chung với hàm mức giá đã được so khớp từng bit trước đây (B1:21609–21611; B3:26850–26852).

**Chưa đủ xác nhận:**
1. **Cặp hằng làm tròn riêng của hàm:**
   - bot 1 `DAT_23e5aa60f20`: tệp `bang-chung/captures/luot-20261023-r1/0000023e5aa5f000-program-data.bin`, vị trí 0x1f20;
   - bot 3 `DAT_171562a9180`: tệp `00000171562a7000-program-data.bin`, vị trí 0x2180.
   - Hàm mức giá đã kiểm dùng ±0.5000001 nhưng nằm ở địa chỉ khác (B1:21610). Mã MQL5 bên dưới đang **giả định** cặp hằng này cũng là ±0.5000001.
2. **Nội dung thông báo khi hết ô:** mã Dispatch 2 chưa có trong `api-calibration.json`. Rất có thể đây là `Print`: ví dụ B1:10621–10628 có ba lần `DoubleToString` rồi Dispatch(2,6). Chuỗi thông báo không hiện trong C (r5 ghi `"strings": []`).
3. **Đối số vé (RDX) khi gọi 0x482b0** không hiện ở B3:23303 và 24657. Nhánh bán còn hiện `SUB84(dVar28,0)`. Cần xem lệnh máy tại hai điểm gọi này.
4. **Vai trò cờ G** chưa rõ. Chỉ thấy G được gán 1. Mọi đường đi đã chụp đều có G = 1.
5. **`value <= 0.0` khi `value` là NaN** (B3:32073): theo C, NaN đi tiếp và được lưu. Cần chạy mã máy để chốt.
6. **Tham số vé là `long` hay `ulong`:** C hiện phép đổi có dấu. Hai kiểu chỉ khác nhau khi vé ≥ 2^63.
7. **Mã thuộc tính `PositionGetInteger(2)` = POSITION_TYPE:** khớp với cách dùng ở nơi gọi (B1:17226, 17237) nhưng chưa hiệu chuẩn riêng.

## 7. Ca kiểm có sức phân biệt

Cách làm giống các lượt kiểm trước:
- chạy mã máy gốc trong bộ mô phỏng CPU, giả lập các hàm MT5;
- chạy MQL5 với giả lập bằng `#define`;
- so bit giá trị trả về, toàn bộ 500 dòng sau mỗi lần gọi, W/W2 và thứ tự gọi API.

Cột "Dự đoán từ C" chỉ để thiết kế ca. **Kết quả chuẩn phải lấy từ lần chạy mã gốc.**

| Ca | Thiết lập → gọi | Dự đoán từ C | Bắt được lỗi gì |
|---|---|---|---|
| T1 | dòng 7 = (T, 1.2345, 0); gọi (1, 2.0, 50, T) | trả 1.2345, không gọi API | tính lại hoặc ghi đè mức |
| T2 | dòng 3 và dòng 9 cùng vé, mức khác nhau | trả mức dòng 3 | quét ngược |
| T3 | dòng 0–4 bận; dòng 5 có vé 0.0 nhưng mức 7, dấu 9 | ghi dòng 5 = (T, mức, 0), không gọi `Positions*` | coi "trống" là cả 3 trường bằng 0; luôn đồng bộ |
| T4 | dòng 0 có vé = -0.0 | ghi vào dòng 0 | so theo bit |
| T5 | side 2, distance 0, price ±1.0049999995, digits 2 | ±1.01 nếu hằng là ±0.5000001; ±1.00 nếu hằng là ±0.5 | đọc sai cặp hằng |
| T6 | digits giả = 4294967298, −1, 12 | dùng 2, 11, 11 | không cắt 32 bit; không giới hạn 11 |
| T7 | price = 1e19; price = NaN | lưu và trả nguyên giá trị | làm tròn cả khi tràn |
| T8 | side 0, rồi side 1, cùng vé | lần đầu lưu 0.0, không gọi `SymbolInfoInteger`; lần sau trả 0.0 | bỏ qua side lạ |
| T9 | ticket 0; dòng 2 trống nhưng còn mức cũ 5 | trả 5, không ghi | xử lý riêng vé 0 |
| T10 | 500 dòng bận, chỉ 10 vé còn mở | xóa 490 dòng, ghi vào dòng nhỏ nhất vừa trống; bot 3 xóa cả dòng B | chỉ xóa 1 dòng; quên bảng B |
| T11 | 500 dòng đều còn mở; gọi lần lượt T, T, U, T | lần 1 in; lần 2 đồng bộ nhưng không in; U in; T in lại; không lưu | in mọi lần; lưu đè |
| T12 | vị thế giả có loại = 2; có vé trả về 0 | vé loại 2 bị loại; vé 0 không gọi `PositionGetInteger` | lọc sai; sai thứ tự gọi |
| T13 | D = 0 và D = −5; có dòng khớp với dấu 0 | `false`, không gọi `TimeCurrent` | bỏ qua điều kiện D ≤ 0 |
| T14 | dấu = 0.0, 0.9, −0.9 | `true`, không gọi `TimeCurrent` | so `== 0.0` thay vì cắt phần lẻ |
| T15 | hiệu = D−1, D, D+1, và hiệu âm | `false`, `true`, `true`, `false` | dùng `>` thay vì `>=` |
| T16 | D = 2147483647, dấu = 1, bây giờ = 2^31+1 | `true` | tính hiệu bằng int 32 bit |
| T17 | dấu = NaN | `false`, có gọi `TimeCurrent` | |
| T18 | đóng dấu: vé không có; vé có ở 2 dòng | không gọi API; chỉ ghi dòng đầu | thêm dòng; ghi mọi dòng khớp |
| T19 | bảng B: vé đã có; `value` ≤ 0 hoặc khác mức lưu | trả mức đã lưu | |
| T20 | bảng B: vé chưa có; `value` = 0.0, −1, −0.0 | trả +0.0, không ghi, không gọi API | trả lại `value` |
| T21 | bảng B: vé chưa có; `value` = NaN | theo C: lưu và trả NaN | dùng `!(value > 0)` |
| T22 | bảng B đầy, mọi vé còn mở | W2 đổi, W giữ nguyên | dùng chung một biến W |
| T23 | chạy đoạn gọi 0x482b0 trong 0x32f60 và 0x37590 | xác định thanh ghi chứa vé | |

Kiểm thêm trên MT5 thử riêng, cho bản gốc và bản dựng cùng điều kiện:
- khởi tạo lại EA làm mất mức đã dời và dấu thời gian;
- D = 0 thì không có lần sửa dừng lỗ thật nào qua đường này; D = 99 thì các lần sửa cách nhau ít nhất 99 giây;
- `EnableVirtualSLTP=false` thì bảng A vẫn được ghi.

## 8. Mã MQL5 cho phần đã rõ

Chưa biên dịch. Phần lệnh in khi hết ô chưa được phục hồi và được đánh dấu rõ trong mã.

```mql5
// Bot1VirtualStops.mqh
// Reconstructed components only, not a complete EA. Bot 1 native RVAs:
// 0x3d200 stop level per ticket, 0x3d5a0 delay check, 0x3d640 time stamp,
// 0x18790 removal of closed tickets (also called from 0x10f60).
// Start-up: 0x20a00 C lines 14892-14893; clear: 0xc30 C lines 2014-2016.
// Not reconstructed: Print when no row is free (C lines 27186-27187).
// To verify: rounding pair at RVA 0x50f20 equals Bot1RoundPrice's +/-0.5000001.
#ifndef BOT1_VIRTUAL_STOPS_MQH
#define BOT1_VIRTUAL_STOPS_MQH
#include "Bot1PriceLevels.mqh"

#define BOT1_VIRTUAL_STOP_ROWS 500

struct Bot1VirtualStopTable
{
   double ticket[BOT1_VIRTUAL_STOP_ROWS]; // RVA 0x62590 stride 24; 0.0 marks a free row
   double level[BOT1_VIRTUAL_STOP_ROWS];  // row offset 8
   double stamp[BOT1_VIRTUAL_STOP_ROWS];  // row offset 16; TimeCurrent() as double, 0 = not stamped
   bool   guard;                          // RVA 0x66410; only the start-up write is known
   long   reported_ticket;                // RVA 0x66418
};

void Bot1StartVirtualStops(Bot1VirtualStopTable &table)
{
   table.reported_ticket=0;
   table.guard=true;
}

void Bot1ClearVirtualStops(Bot1VirtualStopTable &table)
{
   if(!table.guard) return;
   for(int i=0;i<BOT1_VIRTUAL_STOP_ROWS;i++)
   {
      table.ticket[i]=0.0;
      table.level[i]=0.0;
      table.stamp[i]=0.0;
   }
}

void Bot1DropClosedVirtualStops(Bot1VirtualStopTable &table,long &open_tickets[])
{
   if(ArraySize(open_tickets)<64) ArrayResize(open_tickets,64);
   int total=PositionsTotal();
   int count=0;
   for(int i=0;i<total;i++)
   {
      ulong ticket=PositionGetTicket(i);
      if(ticket==0) continue;
      if((ulong)PositionGetInteger(POSITION_TYPE)>=2) continue;
      if(ArraySize(open_tickets)<=count) ArrayResize(open_tickets,count+64);
      open_tickets[count]=(long)ticket;
      count++;
   }
   if(!table.guard) return;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
   {
      if(!(0.0<table.ticket[row])) continue;
      bool open=false;
      for(int k=0;k<count;k++)
         if(open_tickets[k]==(long)table.ticket[row]) { open=true; break; }
      if(open) continue;
      table.stamp[row]=0.0;
      table.level[row]=0.0;
      table.ticket[row]=0.0;
   }
}

bool Bot1StoreVirtualStop(Bot1VirtualStopTable &table,const long ticket,const double level)
{
   if(!table.guard) return false;
   for(int i=0;i<BOT1_VIRTUAL_STOP_ROWS;i++)
   {
      if(table.ticket[i]!=0.0) continue;
      table.ticket[i]=(double)ticket;
      table.level[i]=level;
      table.stamp[i]=0.0;
      return true;
   }
   return false;
}

double Bot1VirtualStopLevel(Bot1VirtualStopTable &table,long &open_tickets[],const int side,
                            const double price,const double distance,const long ticket,
                            const string symbol,const double unit)
{
   if(table.guard)
      for(int i=0;i<BOT1_VIRTUAL_STOP_ROWS;i++)
         if(table.ticket[i]==(double)ticket) return table.level[i];
   double level=0.0;
   if(side==2)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      level=Bot1RoundPrice(distance*unit+price,digits);
   }
   else if(side==1)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      level=Bot1RoundPrice(price-distance*unit,digits);
   }
   if(Bot1StoreVirtualStop(table,ticket,level)) return level;
   Bot1DropClosedVirtualStops(table,open_tickets);
   if(Bot1StoreVirtualStop(table,ticket,level)) return level;
   if(table.reported_ticket!=ticket)
   {
      table.reported_ticket=ticket;
      // Missing: native PositionsTotal() and a 7-argument Print here (C lines 27186-27187).
   }
   return level;
}

bool Bot1VirtualStopDelayPassed(const Bot1VirtualStopTable &table,const long ticket,const int delay_seconds)
{
   if(delay_seconds<=0 || !table.guard) return false;
   for(int i=0;i<BOT1_VIRTUAL_STOP_ROWS;i++)
   {
      if(table.ticket[i]!=(double)ticket) continue;
      long stamp=(long)table.stamp[i];
      if(stamp==0) return true;
      return delay_seconds<=(long)TimeCurrent()-stamp;
   }
   return false;
}

void Bot1VirtualStopStamp(Bot1VirtualStopTable &table,const long ticket)
{
   if(!table.guard) return;
   for(int i=0;i<BOT1_VIRTUAL_STOP_ROWS;i++)
   {
      if(table.ticket[i]!=(double)ticket) continue;
      table.stamp[i]=(double)(long)TimeCurrent();
      return;
   }
}
#endif
```

```mql5
// Bot3VirtualTables.mqh
// Reconstructed components only, not a complete EA. Bot 3 native RVAs:
// 0x47f10 stop level, 0x482b0 take level, 0x484c0 delay check, 0x48560 time stamp,
// 0x20bc0 removal of closed tickets (also called from 0x17f00).
// Start-up: 0x2bb80 C lines 20481-20483; clear: 0xc30 C lines 2114-2117.
// Not reconstructed: Print when no row is free (C lines 32045-32046 and 32105-32106).
// To verify: rounding pair at RVA 0x59180; ticket register at both 0x482b0 call sites.
#ifndef BOT3_VIRTUAL_TABLES_MQH
#define BOT3_VIRTUAL_TABLES_MQH
#include "Bot3PriceLevels.mqh"

#define BOT3_VIRTUAL_ROWS 500

struct Bot3VirtualTables
{
   double stop_ticket[BOT3_VIRTUAL_ROWS]; // RVA 0x6d680 stride 24; 0.0 marks a free row
   double stop_level[BOT3_VIRTUAL_ROWS];
   double stop_stamp[BOT3_VIRTUAL_ROWS];  // TimeCurrent() as double, 0 = not stamped
   double take_ticket[BOT3_VIRTUAL_ROWS]; // RVA 0x70560 stride 16; 0.0 marks a free row
   double take_level[BOT3_VIRTUAL_ROWS];
   bool   guard;                          // RVA 0x73450; only the start-up write is known
   long   stop_reported_ticket;           // RVA 0x73458
   long   take_reported_ticket;           // RVA 0x73460
};

void Bot3StartVirtualTables(Bot3VirtualTables &tables)
{
   tables.take_reported_ticket=0;
   tables.stop_reported_ticket=0;
   tables.guard=true;
}

void Bot3ClearVirtualTables(Bot3VirtualTables &tables)
{
   if(!tables.guard) return;
   for(int i=0;i<BOT3_VIRTUAL_ROWS;i++)
   {
      tables.stop_ticket[i]=0.0;
      tables.stop_level[i]=0.0;
      tables.stop_stamp[i]=0.0;
      tables.take_ticket[i]=0.0;
      tables.take_level[i]=0.0;
   }
}

bool Bot3TicketOpen(const long &open_tickets[],const int count,const long ticket)
{
   for(int k=0;k<count;k++)
      if(open_tickets[k]==ticket) return true;
   return false;
}

void Bot3DropClosedVirtualRows(Bot3VirtualTables &tables,long &open_tickets[])
{
   if(ArraySize(open_tickets)<64) ArrayResize(open_tickets,64);
   int total=PositionsTotal();
   int count=0;
   for(int i=0;i<total;i++)
   {
      ulong ticket=PositionGetTicket(i);
      if(ticket==0) continue;
      if((ulong)PositionGetInteger(POSITION_TYPE)>=2) continue;
      if(ArraySize(open_tickets)<=count) ArrayResize(open_tickets,count+64);
      open_tickets[count]=(long)ticket;
      count++;
   }
   if(!tables.guard) return;
   for(int row=0;row<BOT3_VIRTUAL_ROWS;row++)
   {
      if(0.0<tables.stop_ticket[row] && !Bot3TicketOpen(open_tickets,count,(long)tables.stop_ticket[row]))
      {
         tables.stop_stamp[row]=0.0;
         tables.stop_level[row]=0.0;
         tables.stop_ticket[row]=0.0;
      }
      if(0.0<tables.take_ticket[row] && !Bot3TicketOpen(open_tickets,count,(long)tables.take_ticket[row]))
      {
         tables.take_ticket[row]=0.0;
         tables.take_level[row]=0.0;
      }
   }
}

bool Bot3StoreVirtualStop(Bot3VirtualTables &tables,const long ticket,const double level)
{
   if(!tables.guard) return false;
   for(int i=0;i<BOT3_VIRTUAL_ROWS;i++)
   {
      if(tables.stop_ticket[i]!=0.0) continue;
      tables.stop_ticket[i]=(double)ticket;
      tables.stop_level[i]=level;
      tables.stop_stamp[i]=0.0;
      return true;
   }
   return false;
}

bool Bot3StoreVirtualTake(Bot3VirtualTables &tables,const long ticket,const double level)
{
   if(!tables.guard) return false;
   for(int i=0;i<BOT3_VIRTUAL_ROWS;i++)
   {
      if(tables.take_ticket[i]!=0.0) continue;
      tables.take_ticket[i]=(double)ticket;
      tables.take_level[i]=level;
      return true;
   }
   return false;
}

double Bot3VirtualStopLevel(Bot3VirtualTables &tables,long &open_tickets[],const int side,
                            const double price,const double distance,const long ticket,
                            const string symbol,const double unit)
{
   if(tables.guard)
      for(int i=0;i<BOT3_VIRTUAL_ROWS;i++)
         if(tables.stop_ticket[i]==(double)ticket) return tables.stop_level[i];
   double level=0.0;
   if(side==2)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      level=Bot3RoundPrice(distance*unit+price,digits);
   }
   else if(side==1)
   {
      uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
      level=Bot3RoundPrice(price-distance*unit,digits);
   }
   if(Bot3StoreVirtualStop(tables,ticket,level)) return level;
   Bot3DropClosedVirtualRows(tables,open_tickets);
   if(Bot3StoreVirtualStop(tables,ticket,level)) return level;
   if(tables.stop_reported_ticket!=ticket)
   {
      tables.stop_reported_ticket=ticket;
      // Missing: native PositionsTotal() and a 7-argument Print here (C lines 32045-32046).
   }
   return level;
}

double Bot3VirtualTakeLevel(Bot3VirtualTables &tables,long &open_tickets[],const double value,const long ticket)
{
   if(tables.guard)
   {
      for(int i=0;i<BOT3_VIRTUAL_ROWS;i++)
         if(tables.take_ticket[i]==(double)ticket) return tables.take_level[i];
      if(value<=0.0) return 0.0;
      if(Bot3StoreVirtualTake(tables,ticket,value)) return value;
   }
   else if(value<=0.0) return 0.0;
   Bot3DropClosedVirtualRows(tables,open_tickets);
   if(Bot3StoreVirtualTake(tables,ticket,value)) return value;
   if(tables.take_reported_ticket!=ticket)
   {
      tables.take_reported_ticket=ticket;
      // Missing: native PositionsTotal() and a 7-argument Print here (C lines 32105-32106).
   }
   return value;
}

bool Bot3VirtualStopDelayPassed(const Bot3VirtualTables &tables,const long ticket,const int delay_seconds)
{
   if(delay_seconds<=0 || !tables.guard) return false;
   for(int i=0;i<BOT3_VIRTUAL_ROWS;i++)
   {
      if(tables.stop_ticket[i]!=(double)ticket) continue;
      long stamp=(long)tables.stop_stamp[i];
      if(stamp==0) return true;
      return delay_seconds<=(long)TimeCurrent()-stamp;
   }
   return false;
}

void Bot3VirtualStopStamp(Bot3VirtualTables &tables,const long ticket)
{
   if(!tables.guard) return;
   for(int i=0;i<BOT3_VIRTUAL_ROWS;i++)
   {
      if(tables.stop_ticket[i]!=(double)ticket) continue;
      tables.stop_stamp[i]=(double)(long)TimeCurrent();
      return;
   }
}
#endif
```

**Ghi chú về mã:**
- Tên hàm và tên biến là tên phục dựng.
- Nơi gọi phải truyền `unit` và `symbol` đúng bằng giá trị biến toàn cục của gốc tại lúc gọi (bot 1: RVA 0x66d98 / 0x67918; bot 3: 0x73dd8 / 0x74958).
- Nơi gọi phải dùng **chung một mảng** `open_tickets` cho cả luồng điều phối và các hàm này, giống biến toàn cục của gốc.

## 9. Việc còn thiếu trước khi coi phần này là xong

1. Đọc 16 byte cặp hằng ở hai vị trí nêu tại mục 6, rồi chạy ca T5.
2. Chạy mã máy gốc ở nhánh hết ô để lấy đủ 7 đối số của lệnh in, sau đó mới viết lệnh in.
3. Xem lệnh máy tại hai điểm gọi 0x482b0 để chốt đối số vé.
4. Chạy bộ ca T1–T23 trên mã gốc và trên bản MQL5 đã biên dịch.

**Ghi chú ngoài phạm vi (chưa kiểm sâu):** `Bot1Withdrawal.mqh:36` gọi `Print` với 2 phần. Mã gốc ở B1:10621–10628 lại tạo 3 chuỗi số rồi gọi Dispatch(2,6). Phép so trước đây đã loại trừ nội dung thông báo (`kiem-rut-tien/.../comparison.json`), nên chỗ lệch này chưa được kiểm.