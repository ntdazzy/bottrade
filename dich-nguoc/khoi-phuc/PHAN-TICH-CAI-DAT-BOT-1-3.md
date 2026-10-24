# Phân tích cài đặt bot 1 và 3 — 23/10/2026

Đã nối **152 dòng đầu vào** với vị trí lưu trong bot gốc, kiểm giá trị
mặc định bằng lượt chạy không ghi đè cài đặt và đối chiếu 9 lượt mỗi bot.
Đây là kết quả phân tích cài đặt, chưa phải nguồn EA hoàn chỉnh.

Cập nhật sau lượt này: đã đọc nhãn/thứ tự nhìn thấy và nối 28 lựa chọn
của bảy menu trong MT5 riêng; [bằng chứng mới](PHAN-TICH-MENU-VA-KHOI-TAO-BOT-1-3.md).
Các kết quả phía dưới giữ phạm vi của 18 bản chụp trước đó.

| Phạm vi | Bot 1 | Bot 3 |
|---|---|---|
| Tổng dòng | 72 | 80 |
| Cài đặt / tiêu đề | 64 / 8 | 71 / 9 |
| Bật/tắt | 35 | 39 |
| Số thực | 12 | 14 |
| Số nguyên, chưa chốt kiểu khai báo/menu | 16 | 16 |
| Chuỗi, gồm cả tiêu đề | 9 | 11 |
| Vị trí đầu → cuối vùng đầu vào, cuối không tính | `0x6a518` → `0x6a7a0` | `0x1d6f18` → `0x1d71f0` |
| Kết quả so tên/giá trị/vị trí lưu | **648/648** | **720/720** |
| Có lời đọc trực tiếp trong mã C trung gian | 64 dòng | 70 dòng |

Danh sách từng dòng, vị trí, mặc định và nơi sử dụng:

- [Bot 1](bot-cua-toi-1/phan-tich/cai-dat-20261023/cai-dat-da-kiem.md), [dữ liệu chi tiết](bot-cua-toi-1/phan-tich/cai-dat-20261023/cai-dat-da-kiem.json).
- [Bot 3](bot-cua-toi-3/phan-tich/cai-dat-20261023/cai-dat-da-kiem.md), [dữ liệu chi tiết](bot-cua-toi-3/phan-tich/cai-dat-20261023/cai-dat-da-kiem.json).
- [Kiểm lại bằng chứng](KIEM-CHUNG-CAI-DAT-BOT-1-3.json).

## Cách kiểm và giới hạn

Chỉ chạy đúng EX5 chuẩn trong máy thử riêng, trên tài khoản demo đã
được phép. Mỗi lượt có mã kiểm tra EX5, máy thử, mã/dữ liệu chụp, nhật
ký, mã tiến trình và thời điểm khởi chạy. Giữ nguyên các EX5 gốc.

Mỗi bot có một lượt không ghi đè giá trị; sáu lượt thay các mục bật/tắt
theo mẫu riêng cho từng mục; hai lượt đổi thêm các giá trị chế độ. Mọi
mục bật/tắt đều có cả hai giá trị và không trùng mẫu với mục khác. Các
số dùng giá trị phân biệt; chuỗi được so trực tiếp lúc bot đang chạy.
Sau đó đối chiếu lại với nhật ký cuối cùng đã lưu, không dựa vào nhật
ký đang ghi dở. Đã đọc lại và kiểm mã của mọi vùng dữ liệu trong 18 lượt.

Đã xác nhận tên và thứ tự **trong nhật ký**, cách lưu quan sát được,
vị trí và giá trị mặc định. Chưa xác nhận đầy đủ thứ tự/nhãn trên cửa
sổ cài đặt, kiểu khai báo chính xác của số nguyên, mọi lựa chọn trong
menu, phạm vi giá trị hợp lệ hoặc tác dụng toàn bộ của từng mục. Lời
đọc trong C chỉ giúp tìm nơi cần phân tích; không tự chứng minh ý nghĩa.

Các lượt này chủ động dừng sau khi thu bằng chứng. Một số lượt tự chạy
xong trước khi dừng; không dùng cả nhóm này làm phép so giao dịch hay
kết luận lợi nhuận. Bot 1 có một lượt phải kiểm lại bằng tệp đã lưu sau
khi công cụ dọn báo tiến trình đã tự thoát; không tự điền mã thoát còn thiếu.

## Mặc định cần giữ đúng

| Mục | Bot 1 | Bot 3 |
|---|---|---|
| `AutoGMT` | `true` | `true` |
| `Broker_GMT_OFFSET_Winter` | `2` | `2` |
| `Broker_GMT_OFFSET_Summer` | `3` | `3` |
| `BacktestSpeed` | `1` | `1` |
| `FakeOutFilter` | `1` | `2` |
| `Risk` | `0` | `1234` |
| `TradeFrequency` | không có trong 72 dòng | `5` |

Ba mục giờ trong bản quan sát cũ là `false/0/0`, do lượt đó có ghi đè
cài đặt. Lượt không ghi đè mới xác nhận mặc định là `true/2/3` ở cả hai
bot. Không dùng tệp `.set` đã chỉnh làm mặc định của tác giả.

`ManStratWarn` của bot 3 dài 77 ký tự, có **một dấu cách cuối chuỗi**.
Phép đọc mới giữ dấu cách này; bỏ nó sẽ làm sai bản dựng.

## Lỗi công cụ đã xử lý và bằng chứng giữ lại

| Lỗi | Nguyên nhân và sửa | Bằng chứng không dùng làm kết luận mới |
|---|---|---|
| Bot 1 chưa có đủ dòng cài đặt | Mã đã xuất hiện trước khi nhật ký ghi xong. Chờ đủ tên hoặc dùng nhật ký cuối đã lưu. | `inputs-20261023-r1` |
| Bộ đọc đang chạy thấy thiếu dòng | Tệp nhật ký bị tạo lại/ngắn đi nhưng còn dùng vị trí đọc cũ. Đặt lại vị trí khi tệp ngắn đi; phép so lấy nhật ký cuối. | `inputs-20261023-r2/bits-0/journal-revalidation.json` |
| Dọn tiến trình báo lỗi sau lượt đã tự xong | Kiểm lại mã tiến trình, thời điểm và đường dẫn; tiến trình đã thoát được coi là đã dọn. | `inputs-20261023-r2/bits-5/capture-run.json` ghi rõ kiểm lại, không bịa mã thoát |
| Bot 3 không khớp chuỗi cảnh báo | Bộ đọc cũ bỏ dấu cách cuối. Chỉ bỏ khoảng trắng đầu dòng, giữ nguyên phần giá trị. | `inputs-20261023-r2/defaults`; dùng lượt `r3` mới cho kết quả |

Công cụ: [phan-tich-cai-dat-bot-1-3.py](cong-cu/phan-tich-cai-dat-bot-1-3.py),
các hàm `stop_owned`, `logged_inputs`, `parse_saved_inputs` và pha `audit`.
Các lượt cũ vẫn được giữ nguyên để truy lại lỗi.

## Việc tiếp theo

Kiểm kiểu/menu trực tiếp; phân tích tác dụng từng cài đặt trong các hàm
đã nối; sau đó mới viết khai báo và ghép vào EA. Phần chọn chiến lược
bot 3 đã có [phép so riêng với mã gốc](PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md).

Claude trả lỗi từ chối với nhãn `[cyber]`, mã thoát 1; chưa có đánh giá
độc lập. [Biên nhận](../.local/bot1-3-inputs-20261023/claude-method-review/run.json)
và câu trả lời được giữ lại. Không tính phản hồi này là xác nhận.
