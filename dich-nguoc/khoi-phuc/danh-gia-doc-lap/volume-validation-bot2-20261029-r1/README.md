# Kiểm khối lượng — bot 2

`Bot2VolumeValidation.mqh` phục hồi hàm gốc `0x3cfb0..0x3d63a`:
kiểm mức nhỏ nhất, lớn nhất và bước khối lượng; giữ thứ tự hỏi,
phép làm tròn số nguyên 32 bit, ngưỡng `0.0000001`, thông báo và
lỗi chia cho 0. SHA-256 thân mã gốc:
`0f1ee410718814fe9908848d05ae3303b2350483c0dda0292e3d9d75eed489b3`.

Lượt **`b2-volume-validation-20261029-r9`: 1.834/1.834 ca khớp**:

- **1.807 ca thường:** giá trị trả về, số/thứ tự đọc mức, bit số,
  toàn văn thông báo và mã lỗi cuối; mỗi thông báo chỉ ghi một lần.
- **27 ca chia cho 0:** chạy riêng trong MT5, so đầy đủ các lời
  gọi trước lỗi với mã gốc; lưu phần kết quả đã ghi, dữ liệu từng
  lời gọi và nhật ký có `zero divide` đúng script/tệp nguồn.

Các ca có mức sát ngưỡng, bước âm, số vượt phạm vi nguyên 32 bit,
số không xác định (NaN), vô cực và số 0 âm. Bộ kiểm giữ nguyên
hành vi gốc, không sửa những trường hợp bất thường thành luật mới.

Thân gốc và các hàm chép/hủy chuỗi chạy nguyên mã. Chỉ phản hồi
dịch vụ và cấp phát thành công được cấp. Chuỗi số được đo từ MT5;
phía mã gốc kiểm đúng giá trị/kiểu đem đổi, rồi chạy nối chuỗi và
so toàn văn UTF-16. Mã giá `XAUUSD` được kiểm ở mỗi lần hỏi mức.

## Sửa bộ kiểm và giữ bằng chứng

Lượt cũ `r8` không dùng để bàn giao: bộ ghi `Print` bị đăng ký hai
lần, và phía MQL5 cũng ghi hai lần để khớp. Đã sửa đúng chỗ đăng
ký và bỏ lần ghi dư. Ca từ chối đầu giờ có đúng 2 lời gọi: hỏi
mức nhỏ nhất rồi thông báo. Giữ các mã cũ ở `r8/tested-sources`.

Lượt `r9` dùng định dạng dữ liệu mới, thêm mã lỗi cuối. Bộ kiểm
lưu và kiểm lại từng byte/header/mã ca của phần kết quả lỗi,
chuỗi lời gọi trước lỗi và mã kiểm tra nhật ký. Không dùng riêng
cờ `passed` hoặc độ dài tệp để kết luận.

Nguồn kiểm `b2-volume-validation-20261029-build-r4` và bộ ghép
3 tệp `.mqh` `b2-all-headers-api-20261029-r2` đều **0 lỗi, 0 cảnh báo**.
Kiểm độc lập xác nhận không còn lỗi chặn trong phạm vi hàm này.

## Chạy lại và giới hạn

`kiem-khoi-luong-hop-le-bot-2.py`: `prepare RUN`, biên dịch nguồn
kiểm, `mql5 RUN --build BUILD`, `original RUN`,
`faults RUN --build BUILD`, `compare RUN`. Dùng tên lượt mới và
MT5 bot 3 riêng; công cụ không gửi lệnh thật.

`kiem-ban-git-khoi-luong-bot-2.py` kiểm nguồn Git đúng từng byte,
hai biên nhận biên dịch, bằng chứng thường/lỗi và EX5 gốc. Mã
EX5 đúng bắt đầu `390d8ab1`; bản gốc không thay đổi.

Chưa so toàn bộ trạng thái tại điểm lỗi (`exact_fault_state=false`),
chưa kiểm lỗi cấp phát/định dạng số hoặc nguồn quyền dùng. Đây mới
là hàm kiểm khối lượng, chưa phải toàn bộ cách tính khối lượng,
EA đầy đủ hoặc phép chạy cặp hai bot.

[Số liệu](verification.json), [danh sách tệp](../volume-validation-bot2-20261029-r1-manifest.txt).
