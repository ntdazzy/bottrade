# Đối chiếu nối cấu hình → chuẩn bị bot 1 và bot 3

- Bot 1: thêm dạng gọi nạp đầy đủ vào `Bot1PreparationInputs`, gồm sáu
  trường còn thiếu. Tám hàng được lấy từ lệnh native với kiểm đủ 142 byte.
- Bot 1: **432/432 ca**, 119 giá trị khớp; mã kiểm `80c2d915...`.
- Bot 3: **2.106/2.106 ca**, 124 giá trị khớp; mã kiểm `c9db2f15...`.
- Hai thân native chạy nối tiếp trong cùng bộ nhớ; không lấy kết quả MQL5
  làm dữ liệu mong đợi. Các bộ kiểm ghi dữ liệu thật của hàm sản phẩm.
- Giao diện nạp cũ của bot 1 được kiểm lại 432/432; mã kiểm `6dc91e38...`.
- Bốn Script kiểm/API của hai chuỗi và Script kiểm cũ bot 1 biên dịch sạch.
- Trả lời dịch vụ, tên mã, comment và vốn ở giữa được cấp cùng dữ liệu.
  Chưa chạy đoạn cấp các giá trị đó, toàn dispatcher hoặc toàn EA.

## Rà mã trước ghép

Đã bỏ bản kiểm thử bot 3 chỉ ghi số 0 do tác tử đề xuất. Bản được bàn giao
ghi toàn bộ giá trị thật; đã biên dịch và so native/MQL5, không dùng một bản
khung làm bằng chứng đã đạt.

Hai APICompile mặc định `InvokeFunctions=false`, chỉ biên dịch và không chạy.
Các lượt chạy chỉ dùng Script/dịch vụ giả trong MT5 riêng, không gửi lệnh.
Tệp đệm Python do kiểm thử tạo ra không được đưa vào Git; công cụ từ chối
thao tác xóa tệp đệm này nên giữ nguyên trên máy, không thử đường xóa khác.

## Còn thiếu

Nơi gọi và thứ tự toàn chương trình; nạp tên mã/comment/vốn thật; điều kiện
mua/bán còn lại; menu/hiển thị; lưu/khởi động lại; phép chạy hai EA hoàn chỉnh.
Mục tiêu vẫn là khôi phục đủ các phần đó, không đổi thành chỉ bàn giao hai khối.
