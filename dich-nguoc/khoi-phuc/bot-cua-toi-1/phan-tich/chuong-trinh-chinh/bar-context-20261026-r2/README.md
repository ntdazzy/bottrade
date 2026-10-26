# Ngữ cảnh nhánh nến mới `0x1a245`

Ngày 26/10/2026. Phạm vi là đường đi trong hàm gốc `RVA 0x18aa0..0x1ef9c` của bot 1.

## Bản gốc và mã kiểm

- Vùng mã: base `0x23e5aa10000`, `RVA 0x18aa0..0x1ef9c`.
- SHA-256 vùng mã chụp lại: `45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd`.
- Không sửa EX5, không sửa mã trung gian, không chạy MT5.

## Điều kiện vào `0x1a245`

Đường chung đi qua `0x1a141`, gọi hàm tại `0x0`, rồi kiểm byte tại `RVA 0x67470` (`0x1a152..0x1a15f`). Nếu byte bằng 0 thì đi `0x1a20a`, không vào nhánh này.

Khi byte `0x67470` khác 0, có ba đường vào `0x1a245`:

1. `RVA 0x62490` khác 0 thì không nhảy ở `0x1a172`; sau đó nếu `RVA 0x62000` bằng 0 thì `0x1a185` nhảy vào `0x1a245`.
2. Nếu cả hai kiểm trên không nhảy, gọi hàm đếm tại `0x1a19f`; kết quả `<= 0` thì `0x1a1a3` nhảy vào `0x1a245`.
3. Nếu lần gọi thứ nhất dương, gọi lần thứ hai tại `0x1a1c4`; kết quả `<= 0` thì đi `0x1a43a`, không vào `0x1a245`. Chỉ khi dương mới tới `0x1a1d8` và gán R12 ở `0x1a1ef`.

Vì vậy điều kiện dạng trạng thái là:

`byte_0x67470 != 0` và (`byte_0x62490 == 0` hoặc `byte_0x62000 == 0` hoặc `count_1 <= 0`).

`count_2` chỉ được gọi khi ba điều kiện trước đều không đúng; nó không tạo thêm đường vào `0x1a245` vì kết quả `<= 0` đi `0x1a43a`.

## R12 tại nhánh này

Tại `0x1a245` không có lệnh gán R12. Nhánh này dùng R12 tại `0x1a326` làm địa chỉ gọi hàm, sau các bước đọc vị thế (`0x1a30f..0x1a321`). Vì R12 là thanh ghi được giữ qua lời gọi, giá trị dùng cho vé đầu bằng 0 là giá trị đến từ trước nhánh hoặc từ bên gọi hàm.

Phép lần dấu trên toàn vùng ghi các nguồn có thể tới hai lời gọi parent `0x1a2cd` và `0x1a2db`: `0x18f13` (địa chỉ dữ liệu), `0x18f55` (địa chỉ ngăn xếp), `0x19237`/`0x1936e` (độ dài chuỗi), `0x1924e`/`0x19385`/`0x194d6` (0), và `0x19b9d` (tăng dần). Bốn điểm vào hàm chưa giải được: `0x18aa0`, `0x19034`, `0x1994d`, `0x19be1`. Các nguồn này không chứng minh một byte thấp cố định trên đường `0x1a245`.

Kết luận: **chưa đủ bằng chứng để chọn `true`, `false`, hay một giá trị R12 cụ thể cho cờ vé đầu bằng 0 của nhánh nến mới**. Không được dùng địa chỉ dịch vụ đã gán tại `0x1a1ef` làm mặc định cho nhánh này. Cần thêm bằng chứng từ bên gọi trực tiếp hàm chứa `0x18aa0` hoặc một lần chạy gốc ghi giá trị R12 ngay trước `0x1a245`.

## Lệnh tái lập

Chạy tại thư mục dự án:

```powershell
python -I -B dich-nguoc/khoi-phuc/cong-cu/xem-quan-ly-goc.py 1 18aa0 1a245 1a245 1a2b0 1a300 1a414 1a460 1a5c0 1a640 --full-snapshot
python -I -B dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/dong-vi-the/first-zero-ticket-20261026-r1/trace-newbar-r12.py
```

Lệnh thứ hai chỉ chạy được khi đổi tên đầu ra tạm thời hoặc dùng bản sao thư mục, vì bản r1 cố ý không ghi đè `newbar-r12-definitions.json`. Kết quả đã lưu ở `../first-zero-ticket-20261026-r1/newbar-r12-definitions.json`.
