# Kiểm phần nối sau chuẩn bị

Tôi đã sửa bốn chỗ nối trước đó dựa trên địa chỉ của bot gốc:

| Trường | Bot 1 | Bot 3 | Nguồn đúng |
|---|---:|---:|---|
| Khung xác nhận | `6227c` | `6d2b4` | cài đặt khung xác nhận, không phải khung mở nến |
| Ngưỡng bước giá | `62510` | `6d600` | giá trị bước gốc, không phải đơn vị giá |
| Số nến phụ | `624e0` | `6d5d0` | số nến quét phụ, không phải số nến vào lệnh |
| Cờ hết hạn | `6a5e8` | `1d6fc8` | cài đặt gốc, không phải bản chép sau chuẩn bị |

Đồng thời đã nối các giá trị vốn, giới hạn chênh lệch và quản lý vị thế
từ cùng vùng dữ liệu gốc. Địa chỉ đối chiếu tại các công cụ
`kiem-vong-phat-sinh-lenh-bot-N.py`, `kiem-cap-nhat-muc-gia-bot-1-3.py`,
`kiem-khoi-phuc-lenh-da-luu-bot-1-3.py` và `check-position-management-flow.py`.

| Phép kiểm | Bot 1 | Bot 3 | Phạm vi |
|---|---:|---:|---|
| Giá trị được nối | 68 | 69 | Gồm hai chuỗi so bằng mã băm |
| So với bộ nhớ gốc sau chuẩn bị | 432/432 | 2.106/2.106 | Chỉ các giá trị được nối; chưa chạy khối đánh giá |
| Đầu khởi tạo | 1.600/1.600 | 1.600/1.600 | So cờ, thứ tự dịch vụ tài khoản/kiểm thử; cấp sẵn kết quả quyền |
| Giữ trạng thái khi thiếu dữ liệu | đạt | đạt | Hai lần gọi trong MT5 riêng; khối đánh giá được thay bằng bộ ghi |

Bộ kiểm cổng khởi tạo trước khi bổ sung thứ tự có 72 tình huống mỗi bot
mà bản cũ đặt sai cờ M1.
Ở phép thử nối, bốn cách gán cũ đều cho kết quả khác vùng dữ liệu gốc;
trường hết hạn được thay đổi có chủ ý sau chuẩn bị để phân biệt hai ô.

Phép thử hai lần gọi dùng thân chuẩn bị MQL5 thật, cấp dữ liệu thị trường,
và thay thân đánh giá bằng bộ ghi để kiểm giá, giờ, chỉ số, cờ và thời
hạn sau lần chuẩn bị thứ hai trả sớm. Kết quả này chưa chứng minh toàn bộ
khối đánh giá chạy cùng khối chuẩn bị trong mọi tình huống.

Đã chạy lại cùng phép thử với bản nối cũ từ Git `be60026`: bộ kiểm phát
hiện sai trạng thái ở cả hai bot (`wrong_state_bits=238`). Bản sửa vượt
qua phép thử với mã lỗi bằng 0. Nguồn của cả hai phép thử được lưu để
có thể xem lại; kết quả này không thay cho phép so hai EA hoàn chỉnh.

Các nguồn, mã băm, biên nhận và kết quả kiểm được kiểm lại bằng
`kiem-cau-noi-danh-gia-bot-1-3.py`. Chưa có EA chính, chưa chạy cặp
hai bot, chưa so toàn bộ cài đặt, giao diện, khởi động lại và lỗi.
