# Bảng giá mở và mốc dùng dời dừng

Đọc lệnh máy trước nguồn: mua `0x27c51..0x27e46`, bán
`0x2b667..0x2b85f`. Bảng 100×2 bắt đầu `0x65dd0`; không phải bảng
dừng ảo 500×3. Dùng lại đúng vùng dữ liệu mà hàm dọn bảng đã xử lý.

1. Sao chép double tại `0x62510` sang `0x673e8` trước lời gọi số chữ số.
2. Đọc số chữ số qua `SymbolInfoInteger` của mã giá đang quản lý.
3. Đổi vé số thực đã đọc sang long, rồi trở lại double. Tìm hàng đầu
   có cột 0 bằng giá trị này; NaN không bằng. Vé 0 cũng tìm thấy hàng 0.
4. Nếu tìm thấy: lấy cột 1 và làm tròn như `Bot1RoundPrice`. Không tìm
   thấy: lấy số 0 rồi vẫn đi qua phép làm tròn tương tự.
5. Nếu mức sau làm tròn khác 0 (NaN cũng vào nhánh này): cộng
   `unit*(-0.0)`. Hằng tại `0x50238` và `0x50260` đều đúng âm 0.
   Phép nhân/cộng vẫn phải giữ vì unit vô hạn hoặc NaN tạo NaN.
6. Nếu mức bằng 0: tìm hàng đầu có cột 0 bằng 0, ghi vé số thực rồi
   giá mở hiện tại. Bảng đầy thì không ghi. Cả hai trường hợp chọn
   giá mở hiện tại làm mức tham chiếu, không giữ số 0.
7. Cờ khoảng cách chỉ đúng khi cả hai phép so đều có thứ tự:
   mua `0-unit*0 < mức` và `ngưỡng*unit < giá_mở-mức`;
   bán `unit*0+0 < mức` và `ngưỡng*unit < mức-giá_mở`.
   NaN trong phép so làm cờ sai; không theo biểu thức C thiếu kiểm NaN.
8. Mốc dùng tiếp bằng giá mở nếu byte `0x62410` bằng 0; mọi byte khác
   0 lấy mức tham chiếu. Giữ khác biệt với các cờ bắt buộc đúng bằng 1.

Đây là đoạn có ranh giới, không phải toàn bộ hàm quản lý. Chưa chạy
các nhánh dời dừng sau ranh giới này. Bảng 100×2 phải được đưa từ
trạng thái dùng chung khi ghép EA; không tạo bảng riêng cho mỗi lần gọi.

## Nhánh chế độ đã xác nhận tĩnh

Mua `0x27e8b..0x27ea2`, bán `0x2b89b..0x2b8ad`: giá trị int tại
`0x6241c` đúng bằng 2 đi thẳng vào dừng ảo. Các giá trị khác đi qua
nhánh sửa dừng thật. Cuối nhánh thật đọc lại biến này (mua `0x29878`,
bán `0x2cfb8` cần kiểm mốc chính xác), nên không được xóa nhánh cuối
chỉ vì cho rằng chế độ không thay đổi giữa các lời gọi. Chưa kiểm chạy
cả phần này hoặc chốt đầy đủ cách ghép.
