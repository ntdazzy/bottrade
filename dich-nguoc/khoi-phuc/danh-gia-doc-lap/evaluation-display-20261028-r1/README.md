# Nối cuối luồng đánh giá: thống kê và dọn bảng theo giờ

`Bot1EvaluateWithDisplay` và `Bot3EvaluateWithDisplay` gọi luồng đánh giá
đã kiểm tới quyết định trả về, sau đó gọi bảng thống kê lịch sử và dọn bảng
kết quả khi giờ trong `cached_calendar` đổi. Lời gọi dọn bảng dùng đúng
`queue.results` và vé cuối trong `execution`. Không tự thêm nhánh khi quyết
định là dừng.

| Bot | Ca gốc/MQL5 khớp | Lời gọi SDK | Thân con đã chạy |
|---|---:|---:|---|
| Bot 1 | 61/61 | 13.630 | đánh giá 61, mua 56, bán 56, gửi 107, sửa 40, dọn 9, đóng 9 |
| Bot 3 | 57/57 | 11.519 | đánh giá 57, mua 56, bán 56, gửi 93, sửa 36, dọn 8, đóng 11 |

Bộ kiểm `BotNEvaluationWithDisplayCheck.mq5` chạy trong MT5 riêng; bản
gốc được chạy bằng mô phỏng CPU giữ nguyên thân native và cùng băng trả lời
SDK. Hai biên nhận kiểm và hai biên nhận API đều ghi 0 lỗi/0 cảnh báo.

Đây là bằng chứng cho đoạn đánh giá liên tục kèm phần hiển thị cuối. Nó
chưa phải bằng chứng toàn EA: khởi tạo, sự kiện/thoát, menu/tài nguyên, mọi
nhánh lỗi và chạy song song hai EA thật vẫn còn phải kiểm riêng.
