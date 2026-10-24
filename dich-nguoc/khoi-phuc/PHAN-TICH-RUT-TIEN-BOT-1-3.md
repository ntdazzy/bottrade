# Bot 1 và 3 — cập nhật vốn sau khi rút tiền

Ngày kiểm: 23/10/2026. Đã dựng phần nhận biết khoản rút mới, cập nhật
mức vốn cao nhất và ghi trạng thái. **Chưa ghép vào bot hoàn chỉnh.**

| Phần kiểm | Bot 1 | Bot 3 |
|---|---:|---:|
| Ca khớp với hàm gốc | 915/915 | 915/915 |
| Ghi thật rồi đóng/mở lại MT5 riêng để đọc | Đạt | Đạt |
| Dữ liệu tạm của phép ghi/đọc đã dọn | Đạt | Đạt |
| Biên dịch hiện hành | 0 lỗi, 0 cảnh báo | 0 lỗi, 0 cảnh báo |

## Nguồn và bằng chứng

| Nội dung | Bot 1 | Bot 3 |
|---|---|---|
| Nguồn dựng lại | [Bot1Withdrawal.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1Withdrawal.mqh) | [Bot3Withdrawal.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3Withdrawal.mqh) |
| So với mã gốc | [comparison.json](bot-cua-toi-1/bang-chung/kiem-rut-tien/withdrawal-20261023-r1/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-rut-tien/withdrawal-20261023-r1/comparison.json) |
| Ghi/đọc qua hai lần mở MT5 | [comparison.json](bot-cua-toi-1/bang-chung/kiem-luu-trang-thai/storage-20261023-r1/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-luu-trang-thai/storage-20261023-r1/comparison.json) |
| Biên nhận nguồn hiện hành | [b1-withdrawal-storage-01](bot-cua-toi-1/bang-chung/bien-dich/b1-withdrawal-storage-01/bien-nhan.json) | [b3-withdrawal-storage-01](bot-cua-toi-3/bang-chung/bien-dich/b3-withdrawal-storage-01/bien-nhan.json) |

Hàm gốc: bot 1 tại `0x173f0`, bot 3 tại `0x1fd00`, tính từ đầu vùng mã
đã chụp. Đã kiểm các vị trí này thuộc bảng hàm gốc.

## Quy tắc đã xác minh

1. Chỉ chạy khi bật tính năng. Bỏ qua khi giá trị báo đang đo lại quá
   khứ bằng 1.
2. Chỉ kiểm lại sau ít nhất 60 giây. Đọc thời gian riêng cho bước so,
   bước lưu lần kiểm và giới hạn cuối của khoảng lịch sử.
3. Chọn lịch sử từ thời điểm đã xử lý đến thời gian hiện tại cộng một
   ngày. Nếu đọc thất bại, vẫn giữ lần kiểm mới và gọi phục hồi vùng
   lịch sử về khoảng `0..2147483647`.
4. Chỉ xét bản ghi điều chỉnh số dư, có vé khác 0 và thời điểm mới hơn
   thời điểm đã xử lý. Lấy thời điểm lớn nhất; cộng riêng các khoản âm.
   Khoản dương không làm giảm vốn, nhưng vẫn có thể nâng thời điểm đã xử lý.
5. Ghi thời điểm mới trước. Khi có tổng khoản âm và vốn hiện tại thấp
   hơn mức cao nhất đã lưu, hạ mức cao nhất về vốn hiện tại rồi ghi lại.
6. Giữ cách xét các bản ghi cùng thời điểm và dữ liệu không xếp theo
   thời gian; không tự thêm lọc theo mã giao dịch hoặc chiến lược.

## Phạm vi đối chiếu

- So ba giá trị cuối: lần kiểm, thời điểm đã xử lý và vốn cao nhất.
- So số lần và mã kiểm tra thứ tự gọi các hàm thời gian, lịch sử, ghi
  trạng thái và phát thông báo. Tên mục lưu và từng giá trị ghi cũng
  tham gia mã kiểm tra. Dấu vết phía gốc lưu tối đa 80 lời gọi đầu mỗi ca.
- Có ca tắt tính năng, đang đo lại quá khứ, sát mốc 59/60 giây, đọc lịch
  sử thất bại, vé 0, sai loại, khoản âm/dương/0, trùng thời điểm, dữ liệu
  đảo thứ tự, tên mục rỗng/tiếng Việt và tổng số bản ghi không thông thường.
- Các phép đối chiếu cấp sẵn dữ liệu thời gian/lịch sử và thay việc ghi
  thật bằng bộ ghi nhận. Không so nội dung/định dạng thông báo hoặc lỗi
  cấp bộ nhớ. Các số thực trong lượt này là hữu hạn.

## Kiểm việc lưu thật

Phép kiểm riêng dùng chính hàm MQL5 vừa dựng với hai bản ghi mẫu:
khoản âm ở thời điểm 600 và khoản dương ở thời điểm 700. Vốn hiện tại
9.000, vốn cao nhất cũ 10.000. Hàm ghi vốn cao nhất mới 9.000 và thời điểm 700.

Sau đó MT5 riêng đóng bình thường. Một tiến trình MT5 mới đọc lại đúng
hai giá trị trên. Phép kiểm không gọi ép ghi dữ liệu xuống đĩa trước
khi đóng. Sau khi đọc, chỉ hai mục tạm vừa tạo được xóa và kiểm là đã hết.
Không ghi dữ liệu vào MT5 chính hoặc gửi lệnh giao dịch.

Tên mục lưu trong phép kiểm là tên riêng mới của từng lượt. Chưa khôi
phục cách bot gốc tạo tên mục và nạp trạng thái lúc khởi động. Chưa kiểm
lỗi ghi dữ liệu hoặc mất điện/dừng đột ngột.

Một cảnh báo ép kiểu thời gian trong chương trình kiểm bot 1 đã được
sửa bằng phép đổi kiểu rõ ràng. Nguồn hàm giao dịch không đổi; bản kiểm
hiện hành của cả hai bot đều biên dịch 0 lỗi, 0 cảnh báo.

## Còn phải ghép

Đưa bước cập nhật này vào đúng chỗ trước khi chọn vốn và tính khối lượng;
khôi phục tên mục/nạp trạng thái khi khởi động. Tiếp đó là kiểm ký quỹ,
quản lý lệnh, chọn chiến lược và các bộ lọc.

Cách chạy lại: [cong-cu/BOT-1-3.md](cong-cu/BOT-1-3.md).
