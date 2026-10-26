# Điều phối quản lý vị thế bot1

Đã ghép `Bot1ManagementRouter.mqh`, biên dịch **0 lỗi/0 cảnh báo**,
so **1.536/1.536 ca khớp** ở `b1-management-router-20261026-r1`.
Nguồn MQL5 do hai phiên Claude viết theo mô tả chức năng Codex chốt;
Codex tự nối bộ chạy gốc, kiểm mã và đối chiếu kết quả.

Phần gốc được chạy: nhánh cờ hợp lệ, lựa chọn quản lý từng lần nhận giá
hoặc nến mới, đếm vị thế từng chiều và thứ tự gọi hai hàm quản lý.
Vùng nằm trong hàm `0x18aa0..0x1ef9c`, bắt đầu `0x1a152`, dừng tại
`0x1a620` nếu tiếp tục hoặc `0x1a63a` nếu dừng lượt; SHA thân hàm trong
`native-bindings.json`. Cờ cấp phép chỉ được đọc, giữ nhánh thông báo;
không thay EX5, cách kiểm cấp phép hoặc ép cờ thành hợp lệ.

So22trường/128byte mỗi ca: kết quả, khung, bộ đếm/chế độ/chỉ số, số lời
gọi, lựa chọn vị thế, danh sách còn sống, vé cuối, băm thứ tự/đối số và
đủ8mốc nến. Hai kết quả cùngSHA:
`d106ddc3a526d93e7517acb7930f9a4f9b6365505c17af616b120100bb26f18a`.
[Kết quả](../../../bang-chung/kiem-quan-ly-vi-the/b1-management-router-20261026-r1/comparison.json).

Các ca gồm cờ tắt/bật/chặn, nến bằng/khác, khung đổi sau lần đọc đầu,
giữ đúng ô đã chụp, vé0, sai mã/sai chiều, số nhận dạng64bit cùng phần
thấp32bit, BUY thay trạng thái hoặc xóa danh sách, Total thay giữa lần
chọn nhánh và lần đếm. BUY đọc chiều trước tên mã; SELL đọc tên mã trước
chiều. SELL vẫn được xét khi BUY đã báo dừng.

Hai thân quản lý và dịch vụ MT5 được cấp trả lời trong lượt này;
thân quản lý có phép so riêng352ca, chưa phải phép ghép cả hai tầng.
Chỉ số hợp lệ0..7, cấp phát chuỗi thành công; chưa kiểm mọi lỗi bộ nhớ,
dữ liệu nơi giao dịch, chương trình chính đầy đủ hoặc chạy cặp hai EA.
**Chưa có EA hoàn chỉnh, không lấy số ca làm phần trăm hoàn thành.**

Lặp lại bằng `tests/check-management-router.py` theo thứ tự prepare,
original, mql5 với --build, rồi compare; chọn tên lượt/build mới để
giữ hồ sơ cũ. MQL5 chỉ dùng MT5 kiểm thử riêng, các hàm gửi không được
gọi bởi chương trình kiểm này. Hai phiên viết đã xác nhận Opus5.5max
bằng nhật ký thực tế; chưa xác nhận được ultracode lúc chạy.
