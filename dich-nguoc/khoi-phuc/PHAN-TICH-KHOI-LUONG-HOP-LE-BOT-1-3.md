# Khối lượng hợp lệ — bot 1 và bot 3

| Bot | Hàm gốc | Ca trả kết quả | Ca dừng vì chia 0 | Tổng khớp |
|---|---|---:|---:|---:|
| 1 | `0x3bfe0..0x3c66a` | 1.807 | 27 | 1.834/1.834 |
| 3 | `0x46ca0..0x4732a` | 1.807 | 27 | 1.834/1.834 |

Lượt hiện hành: `volume-validation-20261024-r5`, bản dựng
`b1-volume-validation-04` và `b3-volume-validation-04`, đều 0 lỗi,
0 cảnh báo. [Biên nhận chung](KIEM-CHUNG-KHOI-LUONG-HOP-LE-BOT-1-3.json).

## Luật và thứ tự đã chốt

1. Đọc `SYMBOL_VOLUME_MIN`; nhỏ hơn mức này thì in lỗi và trả `false`.
2. Đọc `SYMBOL_VOLUME_MAX`; lớn hơn mức này thì in lỗi và trả `false`.
3. Đọc `SYMBOL_VOLUME_STEP`; bước bằng 0 gây lỗi dừng chương trình.
4. Tính `MathRound(volume/step)`, đổi sang số nguyên 32 bit, nhân với
   bước; nếu độ lệch tuyệt đối lớn hơn `0.0000001` thì in lỗi và trả
   `false`. Còn lại trả `true`.

Không tự làm tròn khối lượng, giới hạn giá trị, đổi bước hoặc chặn mọi
số không hợp lệ. Lệnh gốc dùng `ucomisd` và `jbe`, nên khi xuất hiện
`NaN` không được thay phép so bằng cách phủ định `<=`. Trường hợp số
nguyên bị tràn cũng phải giữ phép đổi 32 bit; không dùng số thực thay.

Mã MQL5 giữ ba nội dung báo lỗi gốc và đúng thứ tự đọc dữ liệu. Nguồn:
[bot 1](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1VolumeValidation.mqh),
[bot 3](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3VolumeValidation.mqh).

## Lỗi chia 0 trên bản MT5 đang dùng

[Chương trình đối chứng rất nhỏ](doi-chung-mt5/chia-khong-20261024/ZeroDivisionProbe.mq5)
cho thấy phép chia số thực có thể trả vô hạn và tiếp tục chạy; phép
chia số nguyên với hai giá trị đọc khi chạy gây lỗi `Zero divide`.
Vì bot gốc dừng ở bước bằng 0, nguồn mới dùng phép chia số nguyên ở
riêng nhánh này để giữ việc dừng, trước khi có thông báo hay kết quả.
Không dùng cách trả `false` để thay lỗi dừng của bot gốc.

27 ca lỗi của **mỗi bot** được mở MT5 riêng từng lần. Mỗi ca đã có:

- Ba lần đọc dữ liệu đúng thứ tự, đúng từng bit giá trị như gốc.
- Tệp kết quả dừng sau mã ca, chưa ghi kết quả hàm.
- Nhật ký `Zero divide` của đúng chương trình kiểm.

## Phạm vi và giới hạn

Đã so cả biên bằng/nhỏ hơn/lớn hơn, độ lệch quanh `1e-7`, bước khác
0.01/0.1, số âm, vô hạn, `NaN`, đổi số nguyên 32 bit và chia 0.
Đã so kết quả cùng thứ tự đọc dữ liệu, loại thông báo và giá trị số
đưa vào thông báo.

Phần đổi số thành chuỗi trong bộ chạy gốc được cấp sẵn chuỗi rỗng;
chỉ tiền tố và giá trị số được so trực tiếp. Vì vậy chưa xác nhận
từng ký tự đuôi số của thông báo gốc. Phần này cũng chưa chứng minh
EA đã ghép đúng, lỗi đọc dữ liệu từ nơi giao dịch hay toàn bộ hoạt động
giao dịch. Các mục đó vẫn nằm trong P15/P31/P33.

Các lượt trước chưa đạt được giữ nguyên và ghi rõ lý do tại
[danh sách lượt lỗi](KIEM-CHUNG-LOI-LUOT-KHOI-LUONG-HOP-LE.json).
