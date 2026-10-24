# Tạo yêu cầu lệnh chờ — bot 1 và 3

Đã dựng MQL5: **1.607/1.607 ca mỗi bot khớp** 35 trường yêu cầu/
kết quả/kiểm, số nhận diện, cách khớp và thứ tự/đối số lời gọi.
Hai bản `b1-pending-request-01`, `b3-pending-request-01` biên dịch
0 lỗi, 0 cảnh báo. [Biên nhận chung](KIEM-CHUNG-TAO-YEU-CAU-CHO-BOT-1-3.json).

Phân tích trước khi dựng: bot 1 `0x32dd0..0x336c8`, C 21722–21955;
bot 3 `0x3e580..0x3ee78`, C 26963–27196. Đã đọc cả hai thân hàm và
lệnh máy của bot 1; không lấy mã thư viện MT5 hiện tại thay cho bản gốc.

| Thứ tự | Hành vi gốc | C bot 1 |
|---|---|---|
| 1 | Đổi mã chiến lược từ số nguyên 32 bit có dấu sang 64 bit, ghi số nhận diện chung trước khi kiểm dừng | 21745–21751 |
| 2 | Nếu chương trình đang dừng: in đúng thông báo, ghi mã 10027; giữ những trường cũ khác, trả sai | 21748–21751 |
| 3 | Xóa yêu cầu, kết quả gửi và kết quả kiểm. Chạy kiểm cách khớp lần đầu; sai thì dừng | 21753–21836 |
| 4 | Nếu không dùng hết hạn ảo: chọn thời hạn 2. Nếu dùng hết hạn ảo: chọn 0; riêng lúc giờ hết hạn bằng 0 thì đọc thuộc tính 49, thử cờ 1 rồi 2. Không có cả hai thì mã 10022, ghi `Invalid expiration type`, trả sai | 21838–21848 |
| 5 | Ghi hành động 5, mã giá, mã chiến lược, khối lượng, loại lệnh, giá đặt, dừng/chốt, kiểu và giờ hết hạn. **Cả `price` và `stoplimit` đều bằng giá đầu vào** | 21849–21868 |
| 6 | Đọc thuộc tính 71 có cờ thành công; khi lỗi dùng 0. Loại 0/1 cần cờ 1, 2/3 cần 2, 4/5 cần 4, 6/7 cần 8. Loại khác hoặc thiếu cờ: mã 10035, in thông báo và dừng | 21869–21897 |
| 7 | Nếu dừng/chốt khác 0 hoặc không xác định: cờ 16/32 thiếu thì xóa trường tương ứng | 21898–21908 |
| 8 | Kiểm cách khớp lần hai trên yêu cầu đã ghi. Sai: ghi đè mã 10030 và in thông báo | 21909–21912, 21953 |
| 9 | Kiểm lại thuộc tính hết hạn 49. Kiểu 0/1/2/3 cần cờ 1/2/4/8. Sai: mã 10022 và thông báo | 21914–21943, 21949–21953 |
| 10 | Ghi ghi chú lệnh rồi gọi hàm gửi `0x950`; kết quả trả là byte thấp của hàm gửi | 21944–21947 |

Đối số gốc: `symbol` ở RCX, loại ở EDX, khối lượng ở XMM2, giá ở XMM3;
dừng lỗ/chốt lời/ghi chú/giờ hết hạn là bốn đối số ngăn xếp tiếp theo.
Cài đặt `Virtual_expiration` đã nối chắc với byte `0x6a5e8` / `0x1d6fc8`.

**Bản nguồn mới chỉ chuẩn bị yêu cầu đến ngay trước bước gửi.** Tên hàm
có chữ `Prepare`; trả đúng nghĩa là đã qua các bước chuẩn bị, chưa đặt
lệnh. Hàm gửi, thông báo kết quả và xả hàng đợi 100 hàng phải phục hồi
riêng, không được coi phần chuẩn bị là toàn bộ P16.

Đã đối chứng 35 trường của ba kiểu yêu cầu/kết quả bằng chương trình
có nguồn chạy trong máy thử riêng; không gửi lệnh. Khoảng cách lưu
trong lớp là 240 byte từ yêu cầu tới kết quả, rồi 196 byte tới kết
quả kiểm; không nhầm với số byte các trường nhìn thấy.
[Bằng chứng trong lớp](doi-chung-mt5/thu-tu-truong-lenh-class-20261024/layout-class-r1/trade-layout.json).
Bản đo các biến đứng riêng có khoảng đệm khác; không dùng khoảng
cách 208 byte của bản đó để khởi tạo dữ liệu trong lớp.

Claude đã từ chối cung cấp phân tích P16 trong lượt mới; ghi đúng là
chưa có đánh giá. [Phản hồi và biên nhận](danh-gia-claude/order-request-ultracode-20261024-r2/receipt.json).
Phép so trực tiếp ở [bot 1](bot-cua-toi-1/bang-chung/kiem-tao-yeu-cau-cho/pending-20261024-r2/comparison.json)
và [bot 3](bot-cua-toi-3/bang-chung/kiem-tao-yeu-cau-cho/pending-20261024-r2/comparison.json).

Đã thêm 16 ca mỗi bot, tách riêng trường hợp số không xác định
(`NaN`) ở dừng lỗ/chốt lời và việc thiếu từng cờ cho phép đặt dừng/chốt.
[Bot 1](bot-cua-toi-1/bang-chung/kiem-tao-yeu-cau-cho/pending-protection-20261024-r1/comparison.json),
[bot 3](bot-cua-toi-3/bang-chung/kiem-tao-yeu-cau-cho/pending-protection-20261024-r1/comparison.json).
Một lượt kiểm độc lập nữa không tìm thấy lỗi đáng kể trong phạm vi
nguồn và bộ so đã giao; [phạm vi kiểm](danh-gia-doc-lap/trade-components-20261024/review.md).

Lượt tiếp đã dựng hàm gửi/thông báo và ghép với phần chuẩn bị, khớp
1.687 ca mỗi bot. [Phạm vi mới](PHAN-TICH-GUI-LENH-BOT-1-3.md).
Hàm `Prepare` ở trên vẫn chỉ là bước chuẩn bị; hàm `OpenPending`
trong `BotNTradeSend.mqh` mới nối bước gửi và trả đúng kết quả gửi.

Phạm vi còn thiếu: kết quả gửi thật, hàng đợi/thử lại, lỗi dữ
liệu thật của MT5, chuỗi cũ đã cấp bộ nhớ và lỗi cấp bộ nhớ. Lượt
`pending-20261024-r1` của bot 1 giữ bằng chứng khởi tạo bộ kiểm sai;
không dùng làm kết quả đạt. Lượt `r2` dùng bố cục trong lớp đã đo lại.
