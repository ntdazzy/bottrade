# Đặc tả khối chuẩn bị bot1 tại RVA `0x7500`

Ngày 26/10/2026. Đây là đặc tả từ lệnh máy gốc, chưa phải mã MQL5.

## Bản gốc và mã kiểm

- Base: `0x23e5aa10000`.
- Hàm: `RVA 0x7500..0x831d`.
- SHA-256 thân hàm: `8679070031fe7f3309378147c8afc4bf2d4ab596b3ee22a73e8e6386db6c9d0d`.
- SHA-256 vùng mã capture: `e099f124084093c3fdc8651d5f5326709b165248982e5d4eb7394afcbb8177a4`.
- EX5 gốc theo `catalog.json` index 5 (Gold Trade Pro MT5): `A3B0DE423A06E10EBEDC279307B93D7CB9188BA2BB5DE77131A913C865B0E922`. Tệp EX5 đầy đủ không có trong workspace để băm lại.
- Mã C trung gian dùng đối chiếu: SHA-256 `C6389DFE5BD1EF95ED7616EAF5C16B7D041FBD279E650753D239B28E3EA65A8D`.
- Raw lệnh máy trong `raw-instructions.txt`: SHA-256 `3392856140A1634057EDF8CDFC091E5A5DC7FA6D1A8F8413F2D8409B50B484DB`.

## Giao diện đã biết

Hàm nhận một giá trị 32-bit trong `ECX`; lệnh `0x7510` giữ nó vào `ESI`, rồi `0x76e0` ghi vào vùng `RVA 0x678f4`. Đây là đầu ra chỉ số/giá trị gọi bên ngoài; tên chính xác chưa có bằng chứng.

Hàm làm việc trên các vùng dữ liệu sau:

- Chỉ báo: handle `0x62188`, bộ đệm `0x62190`, cờ series `0x62192`, độ dài `0x62198`, mảng dữ liệu `0x621ac + index*8`.
- Mã giao dịch: chuỗi tại `0x67918`; tick tại `0x67750`; thời gian tại `0x67790`.
- Điểm và đơn vị: điểm `0x67928`, đơn vị `0x66d98`.
- Giá trị chuẩn hoá và cài đặt được ghi vào các vùng `0x6242c..0x62550`; bảng đầy đủ ở [bindings.json](bindings.json).
- Thời hạn: số giây `0x66da0`, thời điểm hết hạn `0x67450`.

Các trường chưa có tên chắc chắn giữ dạng `native_RVA_*`; không được tự đổi thành tên chức năng.

## Thứ tự xử lý và đầu ra

1. Gọi dịch vụ tạo chỉ báo tại `0x7587`, lưu kết quả vào `0x62188`. Kết quả âm đi nhánh báo lỗi `0x78ea` rồi kết thúc.
2. Gọi `CopyBuffer` tại `0x75d0`, lấy 100 giá trị từ vị trí 0 vào `0x62190`. Kết quả bằng 0 kết thúc tại `0x8286`.
3. Đọc cờ/độ dài mảng tại `0x75e8..0x7602`, đánh dấu series nếu cần. Độ dài nhỏ hơn 2 đi các lệnh runtime tại `0x82a6` và `0x82d0`; không được thay bằng kiểm nhẹ hơn.
4. Tính hệ số từ vùng `0x4fd40`, tham chiếu `0x62180`, cờ `0x6a5c8`, cờ điều chỉnh lô `0x6a798`, và mảng `0x621ac`. Hai kết quả ghi vào `0x682e8` và `0x682f0`. Các phép so sánh NaN giữ theo cờ máy trong `0x7637..0x76b4`.
5. Ghi chỉ số nhận từ `ECX`, đọc tick một lần tại `0x76f6`, đọc thời gian tại `0x7753`, rồi đọc điểm bằng `SymbolInfoDouble` tại `0x7775` và đọc chữ số. Chữ số 3 hoặc 5 nhân điểm với 10; chữ số 1 chia điểm cho 10; lệnh máy tại `0x77bb..0x7832` là nguồn quyết định.
6. Tính spread bằng ask trừ bid tại `0x7856..0x7878`. Đọc thêm chữ số tại `0x787c`, nhưng bỏ kết quả.
7. Chép nhóm trường đầu theo đúng thứ tự lệnh `0x7889..0x7d77`, chép chuỗi comment tại `0x7e4e`, rồi chép nhóm sau comment tại `0x7e72..0x7ef1`. Không đọc/ghi toàn bộ struct một lần.
8. Đọc lại điểm, mức dừng và mức đóng; tính giới hạn dừng tại `0x7f8d`/`0x7fb9`. Nếu mức dừng hoặc mục tiêu không dương, ghi 1.0 tại `0x7f1f..0x7f42`.
9. Chuẩn hoá khoảng cách, độ rộng nến, độ rộng gần, mức đóng, vùng đóng băng và các trường phụ tại `0x8045..0x818d`. Các phép `ucomisd`, `jbe`, `jne`, `jnp` phải giữ nguyên vì NaN có thể đi nhánh khác.
10. Tính số giây hết hạn bằng phép nhân số nguyên 32-bit với `0xe10` tại `0x81e0..0x81f7`. Nếu số giờ lớn hơn 0, gọi thời gian hiện tại tại `0x820f`; chỉ ghi thời điểm hết hạn khi byte `0x62419` bằng 0 tại `0x8272..0x8283`.

## Nhánh dừng và lỗi

- Handle chỉ báo âm: `0x7597..0x759d` → `0x78ea` → kết thúc.
- `CopyBuffer` trả 0: `0x75d3..0x75d5` → `0x8286`.
- Mảng ngắn: `0x75fc..0x7602` → hai lời gọi runtime ở `0x82a6`, `0x82d0`.
- Hệ số bằng 0 hoặc phép chia không hợp lệ: các nhánh `0x8089`, `0x82bc`, `0x82fc`, `0x8310`. Văn bản lỗi host chưa được xác định trực tiếp.
- Kết thúc bình thường: `0x8286..0x829b` khôi phục thanh ghi và `ret`.

## Những gì chưa đủ bằng chứng

- Chưa xác định chắc tên/kiểu chức năng của mọi trường đầu vào tại `0x62214..0x623a0`; xem `bindings.json`.
- Chưa xác định đầy đủ ý nghĩa tham số dịch vụ tại `0x7587` ngoài thanh ghi/lệnh thực tế.
- Chưa có toàn bộ caller, trạng thái lưu, khởi động lại, giao diện, lịch và EA hoàn chỉnh.
- Chưa có phép chạy cặp EA; không gọi khối này là hoàn thành toàn bot.

## Tái lập

```powershell
python -I -B dich-nguoc/khoi-phuc/cong-cu/xem-quan-ly-goc.py 1 7500 831d --full-snapshot
```

Lệnh trên phải in đúng dòng `snapshot_sha256=8679070031fe7f3309378147c8afc4bf2d4ab596b3ee22a73e8e6386db6c9d0d`.
