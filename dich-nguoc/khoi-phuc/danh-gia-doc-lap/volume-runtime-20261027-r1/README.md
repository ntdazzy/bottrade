# Kết quả phục hồi bước tính khối lượng

- Bot 1: 1.003/1.003 ca thường, 5/5 ca chia0 khớp.
- Bot 3: 1.039/1.039 ca thường, 6/6 ca chia0 khớp.
- Bốn lượt biên dịch nguồn trực tiếp/bộ kiểm:0lỗi,0cảnh báo.

So toàn thân khối lượng, rút tiền và đổi tiền bằng mã gốc, gồm các
lần đọc thay đổi, thông báo đầy đủ và trạng thái trước từng dịch vụ.
Mỗi ca lỗi chạy MT5 riêng, có nhật ký mới, dừng thật và chuỗi dịch vụ
trước lỗi khớp từng byte. Không có lệnh giao dịch thật.

Lượt r2 bắt được NaN bị mất ở phép giới hạn khối lượng. Đã sửa đúng
MAXSD/MINSD gốc, thêm14ca kiểm mức sàn/trần mỗi bot và chạy lại r3.
Bằng chứng r2 và nguồn đã kiểm của lượt đó được giữ riêng. Đề xuất bộ
kiểm đầu chưa đạt được giữ trong hai tệp rejected-check-proposal;
không dùng để chứng minh kết quả hiện hành.

Chưa có EA chính hoàn chỉnh. Phép kiểm này chưa chứng minh toàn bộ
người gọi, lỗi cấp phát bộ nhớ hoặc trạng thái thay đổi sau dịch vụ
cuối ngay trước lỗi. [Đặc tả](SPEC.md), [kết quả/mã kiểm](verification.json).
