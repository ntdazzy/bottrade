# Điều kiện thay đổi vốn trước tính khối lượng/tạo lại lệnh

Mỗi bot **973/973 ca thường khớp** theo từng byte của kết quả và mốc
vốn. Thêm **6/6 ca chia0 mỗi bot** dừng đúng trong MT5 riêng. Hai bản
dựng bộ kiểm đều0lỗi/0cảnh báo, bật kiểm chia0. Chưa ghép toànEA.

Đã giữ thứ tự: bằng thì bỏ qua; factor=phầntrăm/100+1; xét vốn hiện
tại>mốc*factor trước, chỉ khi chưa chọn mới tính mốc/factor. Vì vậy
factor0 vẫn có nhánh gọi tiếp mà không chia0; không tự chặn trước.
Khi chọn thay đổi, bot1 ghi mốc=vốn hiện tại trước lời gọi kế; bot3
không ghi ở cổng này. Không sửa khác biệt đó thành một quy tắc chung.

Các ca thường có số âm/dương,±0, số rất nhỏ,NaN/vô cực và các phần
trăm gần-100. Sáu ca lỗi chạy riêng từng lần: có dữ liệu trước lỗi,
không có bản ghi kết quả thường/trạng thái hoàn tất, nhật ký mới chứa
đúng mã ca và lỗi zero divide. MT5 kết thúc4294967295 ở ca lỗi; bộ
chạy ban đầu đòi mã0 đã được sửa để đánh giá bằng lỗi/dừng thực tế,
không sửa nguồn cổng hoặc bỏ kiểm lỗi. Bản bộ chạy cũ được giữ riêng.

Phạm vi chỉ là cổng số học: native chạy từ1a6e5/22920 tới ngay trước
gọi tính khối lượng, nhánh bỏ qua hoặc điểm báo lỗi. Không cấp trả
lời SDK/hàm con. Còn phải nối trạng thái thật từ quản lý và bước tính
khối lượng/vòng tạo lại lệnh. Hàm khối lượng cũ có bằng chứng phần số
và rút/lưu vốn; thứ tự đọc dịch vụ và nội dung thông báo vẫn cần kiểm
trước khi ghép trọn hàm. Kết quả cổng không chứng minh các phần đó.

[Đặc tả](SPEC.md), [mã kiểm gốc](native-evidence.json),
[bộ so](../../cong-cu/kiem-cong-doi-von-bot-1-3.py),
[bot1](../../bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/b1-resize-balance-20261027-r2/comparison.json),
[bot3](../../bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/b3-resize-balance-20261027-r2/comparison.json).
