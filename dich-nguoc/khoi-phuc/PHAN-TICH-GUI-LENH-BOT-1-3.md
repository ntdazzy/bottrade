# Gửi lệnh và thông báo — bot 1 và 3

Phân tích trước khi dựng: hàm `0x950` ở cả hai bot, C 601–658;
định dạng kết quả `0x235c0/0x2ecf0`, yêu cầu `0x23fa0/0x2f6d0`,
loại lệnh `0x26060/0x31790` và giá `0x26360/0x31a90`.
Đã đọc hai thân hàm gửi, mã máy và chuỗi mẫu; hai lượt phân tích chỉ
đọc độc lập bổ sung bảng nhánh/tham số trước khi dựng.

Đã dựng `BotNTradeMessages.mqh`, `BotNTradeSend.mqh`: **1.201/1.201
ca mỗi bot khớp** hàm gửi và toàn bộ các hàm thông báo đã liệt kê.
Đã ghép từ đầu hàm tạo yêu cầu qua hai lần kiểm cách khớp, gửi và
thông báo: **1.687/1.687 ca mỗi bot khớp**. Các bản biên dịch
`bN-trade-send-03`, `bN-open-pending-01` đều 0 lỗi, 0 cảnh báo.
[Biên nhận đối chiếu nguồn/bằng chứng](KIEM-CHUNG-GUI-LENH-BOT-1-3.json).

| Thứ tự | Hành vi gốc |
|---|---|
| Gửi | Byte chế độ bằng 0 gọi `OrderSend`, khác 0 gọi `OrderSendAsync`; không tự kiểm mã kết quả để đổi giá trị trả của hàm gửi |
| Chọn ghi nhật ký | Nếu hàm gửi trả sai: cần mức ghi >0. Nếu trả đúng: cần mức ghi >1. Mức là số nguyên có dấu, đọc sau khi gửi |
| Tạo thông báo | Định dạng kết quả trước, yêu cầu sau; cuối cùng `PrintFormat("CTrade::OrderSend: %s [%s]",request_text,result_text)` |
| Thoát | Hủy bốn chuỗi cục bộ, trả lại kết quả hàm gửi; không tự thử lại trong hàm này |

[Chuỗi và mã kiểm hàm gửi](doi-chung-mt5/gui-lenh-20261024/wrapper-analysis.json).
Không bỏ nhánh thông báo khi dựng, vì chúng còn đọc thuộc tính mã giá
và xử lý số/chuỗi sau lời gọi gửi.

Định dạng kết quả luôn đọc số chữ số giá, rồi cách thực hiện lệnh;
khi đọc lỗi dùng `_Digits` và cách 0. Mã 10004 dùng `bid/ask` nhưng
đổi `ask` sang chuỗi trước `bid`. Mã 10009/10010 chỉ thêm giá khi hành
động bằng 1 và cách thực hiện (32 bit không dấu) <3. Mã 10039 là
`close order already exists`, 10040 là `limit positions`; 10037,
10038, 10041 và mã ngoài bảng dùng `unknown retcode ` cộng số không dấu.

Định dạng yêu cầu giữ đủ hành động 1/5/6/7/8/10 và nhánh còn lại.
Vé vị thế chỉ xuất hiện ở nhánh điều kiện chế độ bằng 2 và vé khác 0;
mẫu xóa lệnh dùng vé lệnh. Dừng/chốt khác 0, kể cả `NaN`, được thêm
theo thứ tự dừng rồi chốt. Giá có thêm mức kích hoạt nếu mức đó khác
0, kể cả `NaN`; giữ nguyên chữ, khoảng trắng và thứ tự đổi số thành chuỗi.

Phép kiểm cần so cả hai chế độ gửi, kết quả đúng/sai, các mức ghi,
toàn bộ nhánh thông báo, dữ liệu và lỗi đọc thuộc tính, kiểu số và
chuỗi. Chỉ cấp kết quả gửi trong bộ kiểm riêng, không gọi tài khoản
thật. Chưa chứng minh gửi/khớp trên nơi giao dịch bằng phân tích này.

## Phép kiểm đã chạy và giới hạn

| Phạm vi | Bot 1 | Bot 3 |
|---|---|---|
| Hàm gửi và thông báo: hai chế độ, mức ghi, mã kết quả, hành động, loại, giá/khối lượng, mã giá rỗng/NULL, lỗi đọc thuộc tính, dừng/chốt | [1.201/1.201](bot-cua-toi-1/bang-chung/kiem-gui-lenh/send-20261024-r3/comparison.json) | [1.201/1.201](bot-cua-toi-3/bang-chung/kiem-gui-lenh/send-20261024-r3/comparison.json) |
| Ghép tạo yêu cầu → gửi → thông báo; 35 trường, số nhận diện, cách khớp, kết quả và thứ tự/đối số có kiểu | [1.687/1.687](bot-cua-toi-1/bang-chung/kiem-ghep-dat-lenh-cho/open-pending-20261024-r1/comparison.json) | [1.687/1.687](bot-cua-toi-3/bang-chung/kiem-ghep-dat-lenh-cho/open-pending-20261024-r1/comparison.json) |
| Kiểm bổ sung vùng lưu gốc 628 byte: 364 byte riêng được xóa; nhánh dừng chỉ đổi mã kết quả trong vùng đó | [Đạt 1.687 ca](bot-cua-toi-1/bang-chung/kiem-ghep-dat-lenh-cho/open-pending-20261024-r1/native-storage-audit.json) | [Đạt 1.687 ca](bot-cua-toi-3/bang-chung/kiem-ghep-dat-lenh-cho/open-pending-20261024-r1/native-storage-audit.json) |

Mã máy gốc chạy các hàm định dạng và quản lý chuỗi; lời gọi gửi được
cấp kết quả rõ ràng. Phép đổi số/định dạng chuỗi được đo bằng MT5 thật,
rồi đối chiếu đúng đối số, kiểu và thứ tự gọi của mã gốc. Không lấy
chuỗi do nguồn dựng lại tự tính làm kết quả mong đợi của thuật toán gốc.
Đã giữ bộ kiểm không gửi lệnh cả khi chạy trong MT5 riêng.

Hai điểm yếu từ [lượt kiểm độc lập](danh-gia-doc-lap/gui-lenh-20261024/review.md)
đã được bổ sung: kiểm vùng lưu gốc và điều kiện xác nhận sơ đồ 35 trường.
Chưa so byte đệm riêng của lớp MQL5. Chưa kiểm kết quả từ nơi giao dịch,
lỗi cấp bộ nhớ hoặc toàn bộ EA. Hàng đợi 100 lệnh, thử lại và hàm đổi mã
lỗi vẫn là phần tiếp theo; không đánh dấu P16/P31 hoàn tất.

Lượt `send-20261024-r1` của bot 1 phát hiện bộ kiểm dùng lại con trỏ
chuỗi cũ và nguồn thiếu tiền tố `request`. Đã giữ bằng chứng lỗi và
bản nguồn lúc lệch; sửa rồi chạy lượt `r2` (697 ca) và `r3` (1.201 ca).
Không dùng lượt lỗi làm bằng chứng đạt. Phần kiểm độc lập nêu trên do
agent nội bộ thực hiện; chưa có đánh giá Claude cho phần gửi này.
