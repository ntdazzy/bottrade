# Nội dung mã lỗi — bot 1 và 3

Đã dựng `BotNTradeErrors.mqh`: **5.826/5.826 ca mỗi bot khớp**.
Đã chạy mọi mã từ -1 đến 4207, thêm các biên 32 bit và năm giá trị
bộ đếm; 92 mã cố định được kiểm với nhiều trạng thái. Các bản
`bN-trade-errors-02` biên dịch 0 lỗi, 0 cảnh báo.
[Biên nhận chung](KIEM-CHUNG-HANG-DOI-BOT-1-3-R2.json).

Phân tích trước khi dựng: bot 1 `0x336d0`, C 21960–22524; bot 3
`0x3ee80`, C 27201–27765. Đã đọc thân hàm, chuỗi từ mã chụp và
đối chiếu với một agent chỉ đọc. Hai bot có cùng 92 mã/chuỗi cố định.
[Bot 1](bot-cua-toi-1/bang-chung/kiem-chuoi-loi/errors-20261024-r3/analysis.json),
[bot 3](bot-cua-toi-3/bang-chung/kiem-chuoi-loi/errors-20261024-r3/analysis.json).

Hàm tăng bộ đếm 32 bit không dấu trước khi chọn chuỗi, kể cả mã 0
hoặc mã chưa biết; hết giới hạn thì quay về 0. Bộ đếm ở
`0x6744c/0x7448c`. Mã chưa liệt kê dùng `unknown error ` cộng giá trị
32 bit có dấu. Không tự sửa chữ hoặc lỗi chính tả của chuỗi gốc.

Hàm gốc ghi chuỗi vào vùng trả chuỗi dùng chung
`0x6a43c/0x1d6e3c`; không in thông báo. Nguồn MQL5 dựng lại trả
chuỗi và cập nhật bộ đếm được truyền vào. Bộ kiểm đã so đúng toàn bộ
chữ và bộ đếm, đồng thời kiểm tăng đếm trước lời chép chuỗi ở mã gốc.

[Kết quả bot 1](bot-cua-toi-1/bang-chung/kiem-chuoi-loi/errors-20261024-r3/comparison.json),
[kết quả bot 3](bot-cua-toi-3/bang-chung/kiem-chuoi-loi/errors-20261024-r3/comparison.json).
Đã nối chắc mã `0x52/0x53/0x55` với int32/uint32/int64 bằng thư viện
có nguồn trên cùng MT5; [bằng chứng](doi-chung-mt5/hang-doi-20261024/queue-native-r2/typed-cast-proof.json).
Chuỗi chữ số do hàm thật của MT5 tạo, không tự viết lại hàm đổi số.

Claude Opus 5.5 đã rà 92 cặp mã/chuỗi và không thấy lỗi nguồn đã chứng
minh. Mức `max` đã được xác nhận ở năm yêu cầu thực tế, `ultracode`
được bật trong cấu hình; luồng agent con của Claude chưa chạy.
[Đánh giá](danh-gia-claude/error-text-ultracode-20261024-r1/review.md),
[cấu hình thực tế](danh-gia-claude/error-text-ultracode-20261024-r1/receipt.json).
Sau đánh giá đã bổ sung miền mã -1..4207, bằng chứng kiểu số, tăng
đếm trước chép, trạng thái hoàn tất của script, kiểm nguồn ở MT5 riêng
và nối mã kiểm tra của nguồn/EX5/biên nhận/kết quả.

Giới hạn: ba trạng thái chuỗi cũ chỉ được kiểm trực tiếp trên vùng lưu
của mã gốc. Nguồn MQL5 trả chuỗi; chưa chứng minh cách cấp/giải phóng
riêng của trình chạy MQL5. Chưa kiểm lỗi cấp bộ nhớ hoặc mọi nơi gọi
trong EA. Phần hàng đợi đã dùng hàm này và so riêng; chưa toàn bộ bot.

Lượt phân tích `r1` đếm nhầm các mã đi nhánh mặc định vào nhóm chuỗi
cố định. Đã dừng trước khi tạo nguồn, lưu lỗi và sửa bộ đọc; `r2`
đọc đúng 92 mã. Lượt `r2` đã khớp 1.725 ca; `r3` mở rộng bằng chứng
như trên. Nhận xét Claude nói tệp so bị ghi đè đã được đối chiếu lại:
hàm lưu dùng `open('x')`, luôn chặn ghi đè. Không lấy mọi nhận xét làm
kết luận khi chưa kiểm lại.
