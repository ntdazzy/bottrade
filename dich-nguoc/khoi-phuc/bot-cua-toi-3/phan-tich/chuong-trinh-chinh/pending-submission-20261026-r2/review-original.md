# Review đặc tả đặt lệnh chờ bot3

Ngày 26/10/2026. Đây là kiểm độc lập TASK r2 với mã gốc, không sửa nguồn.

## Bản gốc đã kiểm

- Hàm: `RVA 0x20ef0..0x2a1bc`.
- Base: `0x17156250000`.
- SHA-256 vùng mã từ `xem-quan-ly-goc.py 3 --full-snapshot`: `6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.
- `Original(3)` khởi tạo đúng base `0x17156250000`; vùng thực thi đã nạp có SHA riêng `7464a1dcb3a66d1438d510f365a08fbcdfa4aaa00f03afb49259225bc7d5cfbb`.

## Kết quả đối chiếu

| Mục trong TASK | Bằng chứng gốc | Kết quả |
|---|---|---|
| Kiểm tiền và thứ tự đọc volume trước chuỗi mã | `0x280d7..0x2812a`: cờ tại `0x6d51c`, volume tại `0x74934`/`0x73ac0`, rồi gọi dịch vụ tại `0x2812a` | Khớp |
| Giá vào mua, nhân trước cộng sau | `0x2817c..0x2818a`: lấy `unit`, nhân với `xmm9` rồi cộng `xmm10` | Khớp |
| Giá vào bán và dấu `-0.0` | `0x2926e..0x29280`: `unit * xmm9 + base`; C gốc ghi `DAT_171562c3dd8 * DAT_171562a81f8 + dVar34` | Khớp; giữ dấu số 0 |
| Dừng/chốt mua | Dừng `0x28225..0x2823c` là `base - (stop+0)*unit`; chốt `0x282dd..0x282f1` là `take*unit + base` | Khớp |
| Dừng/chốt bán | Dừng `0x29320..0x2932a` là `(stop+0)*unit + base`; chốt `0x293da..0x293ec` là `base - take*unit` | Khớp |
| Số lần đọc Digits | Mua tại `0x28149`, `0x281ed`, `0x282aa`; bán tại `0x2923b`, `0x292e8`, `0x293a2` | Khớp: đúng 3 lần, trước mỗi giá |
| Đọc volume lại và kiểm volume | `0x2835f..0x28384`, gọi hàm kiểm tại `0x2837a`; bán `0x2945a..0x2947f` | Khớp |
| Cho phép đặt lệnh | Mua `0x2838e..0x2839c`; bán `0x29489..0x29497` | Khớp |
| Kiểm ask/bid, freeze trước stop, so sánh nghiêm ngặt | Mua `0x283a2..0x283e2`; bán `0x2949d..0x294dd` | Khớp |
| Đọc expiry trước cờ bỏ SL/TP | `0x28406` đọc `0x74490`, sau đó `0x28409` đọc cờ `0x6d510` | Khớp |
| Cấp chuỗi, volume, symbol trong mỗi lần đặt | Mua lần đầu `0x28417..0x28468`, nhánh dùng chung `0x295e0..0x29634`; bán `0x29512..0x29566`, dùng chung `0x29906..0x2995a`. C trung gian giữ cùng thứ tự: sao chép chuỗi, đọc volume, rồi sao chép symbol tại các đoạn tương ứng dòng 16437–16449 và 17330–17342 | Khớp |
| Lần đặt đầu accepted và ghi bảng | Mua gọi tại `0x29664`, kiểm kết quả `0x29678`; bán `0x2998a`, kiểm `0x2999e`. Vòng tìm ô trống và ghi giá cơ sở tại `0x29683..0x296a5`, `0x29c2c..0x29c55` và tương ứng `0x299a9..0x299cb`, `0x29c5a..0x29c83` | Khớp; giá ghi là giá cơ sở, không phải giá đã làm tròn |
| Ô NaN không được coi là trống | `0x29692..0x2969f` và `0x299b3..0x299c9`: so sánh rồi nhánh theo cờ NaN | Khớp |
| Thử lại lỗi 132, bỏ qua bool lần sau | Mua `0x296b9..0x29861`, bán `0x299df..0x29b87`: đọc mã lỗi `0x1d6e10`, so `0x84`, ngủ `0x9c4`, đặt lại; kết quả lần đặt lại chỉ dẫn tới kiểm mã lỗi tiếp | Khớp |
| Báo lỗi sau khi vòng kết thúc, không ghi bảng | Mua `0x296c7..0x29796`, bán `0x299ed..0x29abc`; C trung gian dòng 16450–16475 và 17343–17368 | Khớp |

## Điểm đặc biệt đã kiểm

- Ba công thức dùng đúng thứ tự phép tính và giá trị cục bộ giữ qua lần thử lại.
- Mua dùng `+0.0`; bán dùng nguồn số 0 âm ở `0x29272`, nên không được rút gọn phép nhân thành bỏ qua số 0.
- Cờ bỏ SL/TP chỉ chọn gửi `0.0/0.0`; ba lần đọc Digits vẫn xảy ra trước đó.
- Nhánh thành công ghi `(double)(uint)accepted` và giá cơ sở; nhánh thử lại không ghi bảng.
- Vòng quét dùng bước `0x10`, từ `-0x640` đến `0`, tương ứng đủ 100 hàng theo cách mảng gốc được truyền vào.

## Kết luận

TASK r2 khớp các đoạn gốc đã yêu cầu trong phạm vi `0x280d7..0x284be`, `0x291c6..0x295b9` và các nhánh gửi `0x295e0..0x29c85` (kèm phần tiếp nối cần để kiểm vòng thử lại và ghi bảng). Chưa thấy lỗi cần báo trong đặc tả. Đây chỉ là kiểm đặc tả với mã gốc; chưa phải bằng chứng EA đầy đủ hay phép chạy hai bot.

## Lệnh tái lập

```powershell
python -I -B dich-nguoc/khoi-phuc/cong-cu/xem-quan-ly-goc.py 3 20ef0 21800 280d7 284be 291c6 295b9 295e0 29c86 --full-snapshot
python -I -B -c "import importlib.util,hashlib; p='dich-nguoc/khoi-phuc/cong-cu/kiem-gia-vao-bot-1-3.py'; s=importlib.util.spec_from_file_location('x',p); m=importlib.util.module_from_spec(s); s.loader.exec_module(m); o=m.Original(3); print(hex(o.base))"
```
