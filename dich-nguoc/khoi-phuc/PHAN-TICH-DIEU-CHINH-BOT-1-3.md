# Bot 1 và 3 — điều chỉnh khoảng cách và bảng chiến lược

Ngày kiểm: 23/10/2026. Đã dựng thêm phần tính khoảng cách, thời hạn lệnh
và bảng giá trị cơ bản của từng chiến lược. **Chưa có EA hoàn chỉnh.**

Cập nhật sau: đã ghép phần đổi tiền tệ và tính khối lượng;
xem [kết quả tiếp theo](PHAN-TICH-KHOI-LUONG-BOT-1-3.md).

| Phần đã kiểm | Bot 1 | Bot 3 |
|---|---:|---:|
| Ca đối chiếu mới khớp | 1.050/1.050 | 1.034/1.034 |
| Ca tính xong, so từng bit | 1.040 | 1.016 |
| Ca lỗi chia cho 0, cùng từ chối kết quả | 10 | 18 |
| Số giá trị so trong mỗi ca tính xong | 33 | 35 |
| Bảng chiến lược cơ bản | 16/16 | 9/9 |
| Giá trị trong các bảng khớp | 352/352 | 225/225 |
| Biên dịch hiện hành | 0 lỗi, 0 cảnh báo | 0 lỗi, 0 cảnh báo |

Bot 1 có 8 chiến lược × 2 chế độ dời dừng lỗ. Bot 3 có 9 chiến lược.
Bảng cơ bản áp dụng khi phần điều chỉnh thêm và ngẫu nhiên bằng 0.
Chưa phục hồi hai phần điều chỉnh đó hoặc nhánh bật/tắt chiến lược.

## Mã và bằng chứng

| Nội dung | Bot 1 | Bot 3 |
|---|---|---|
| Tính khoảng cách | [Bot1DistanceSettings.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1DistanceSettings.mqh) | [Bot3DistanceSettings.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3DistanceSettings.mqh) |
| Bảng cơ bản | [Bot1BaseDistances.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1BaseDistances.mqh) | [Bot3BaseDistances.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3BaseDistances.mqh) |
| Kết quả so MQL5 | [comparison.json](bot-cua-toi-1/bang-chung/kiem-dieu-chinh/settings-20261023-r2/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-dieu-chinh/settings-20261023-r2/comparison.json) |
| Bảng lấy bằng lệnh máy | [native-profiles.json](bot-cua-toi-1/bang-chung/kiem-dieu-chinh/settings-20261023-r2/native-profiles.json) | [native-profiles.json](bot-cua-toi-3/bang-chung/kiem-dieu-chinh/settings-20261023-r2/native-profiles.json) |
| Địa chỉ từng giá trị | [fields.json](bot-cua-toi-1/bang-chung/kiem-dieu-chinh/settings-20261023-r2/fields.json) | [fields.json](bot-cua-toi-3/bang-chung/kiem-dieu-chinh/settings-20261023-r2/fields.json) |
| Biên nhận biên dịch | [b1-distance-settings-02](bot-cua-toi-1/bang-chung/bien-dich/b1-distance-settings-02/bien-nhan.json) | [b3-distance-settings-02](bot-cua-toi-3/bang-chung/bien-dich/b3-distance-settings-02/bien-nhan.json) |

Nguồn hiện hành trùng mã kiểm tra trong biên nhận. Hai chương trình kiểm
chạy trong MT5 riêng, thoát với mã 0 và không có lệnh mua/bán.
Đã thử tệp sai tiêu đề ở bot 1 và tệp thiếu byte ở bot 3: cả hai dừng
với mã 1, công cụ từ chối nhận kết quả. Bằng chứng nằm trong các thư mục
`settings-invalid-b1-20261023` và `settings-invalid-b3-20261023` cùng nơi kiểm.

## Quy tắc đã xác minh

- Bot 1: khi mức tham chiếu dương, lấy giá trị được đọc từ bộ chỉ báo
  chia cho mức tham chiếu. Nếu tắt điều chỉnh thì hệ số bằng 1.
- Bot 3: chỉ lấy giá mở cửa ngày trước chia cho mức tham chiếu khi mức
  tham chiếu từ 1.000 trở lên. Nếu tắt điều chỉnh thì hệ số bằng 1.
- Hệ số bằng 0: bot 1 thay bằng 1 trước khi tính hệ số khối lượng.
  Bot 3 tính nghịch đảo trước bước thay thế; nếu bật điều chỉnh khối
  lượng thì báo lỗi chia cho 0. Bản dựng trả `false`, yêu cầu bên gọi
  dừng bước chuẩn bị; chưa mô phỏng cách toàn bộ EA xử lý lỗi này.
- Đơn vị giá bằng bước giá × 10 khi có 3 hoặc 5 chữ số sau dấu phẩy;
  bằng bước giá ÷ 10 khi có 1 chữ số; các trường hợp khác giữ bước giá.
- Các khoảng cách được nhân với hệ số. Độ dịch của mức giá phụ được
  giữ nguyên trong bước này. Hai chiều rộng tìm đỉnh/đáy ít nhất là 1.
- Khoảng dừng lỗ/chốt lời không dương được đổi thành 1, rồi nâng lên
  nếu nhỏ hơn hai lần khoảng tối thiểu mà nơi giao dịch yêu cầu.
  Khoảng tìm điểm vào cũng được nâng theo giới hạn đó và ít nhất là 0,1.
- Khoảng dời dừng lỗ khác 0 được nâng theo giới hạn đặt/sửa lệnh.
  Giá trị 0 giữ nguyên ở bước này. Chưa khôi phục toàn bộ luật dời lệnh.
- Thời hạn tính bằng số giờ × 3.600. Giữ phép nhân 32 bit và cách cộng
  của bản gốc, kể cả khi số quá lớn. Nếu bot tự quản lý hết hạn thì
  thời hạn gửi cho nơi giao dịch bằng 0.

Hàm gốc đối chiếu: bot 1 tại `0x7500`, bot 3 tại `0xe0c0`.
Đây là vị trí tính từ đầu vùng mã đã chụp, không phải địa chỉ cố định
khi chạy lại chương trình.

## Phạm vi kiểm

Đã chạy nguyên hàm chuẩn bị trong mã máy với dữ liệu đọc từ MT5 được
cấp sẵn; không thay các phép tính và nhánh của bot bằng kết quả dự kiến.
Chỉ so 33/35 giá trị nêu trong `fields.json`. Chưa so toàn bộ trạng thái
khởi tạo, thứ tự mọi lời gọi hoặc việc tạo bộ chỉ báo.

Bộ ca có số âm, 0, sát ngưỡng, các độ chia giá, quá giới hạn số nguyên,
thời hạn quá lớn và các bảng chiến lược vừa lấy được. Các số thực đầu
vào trong lượt này là hữu hạn; chưa kiểm mọi số không hợp lệ. Khi mã
gốc lỗi chia cho 0, chỉ so việc từ chối kết quả, không so các ô nhớ đã
ghi dở trước lỗi.

Các bảng cơ bản được lấy bằng cách chạy đoạn gán thật đến trước lời gọi
kế tiếp. Mỗi giá trị được kiểm là đã được đoạn mã ghi. Những giá trị
giữ trong thanh ghi từ trước được lần ngược mọi đường đi liên quan;
chỉ dùng khi đều có cùng hằng số. Đã kiểm cả hai nhánh dời dừng lỗ của
bot 1 và so lại sáu giá trị của bảng cũ.

Bot 3 gán mức tham chiếu ở đoạn sau, nên bảng mới chưa chứa giá trị
này. Hai trường `native_6d368` và `native_6d370` giữ tên theo địa chỉ:
đã xác minh giá trị và phép nhân, chưa kết luận đầy đủ vai trò giao dịch.

## Ghép nguồn và việc tiếp theo

`BotNLoadBaseDistances` nạp các trường thuộc bảng, dùng lại
`BotNLoadEntryProfile`. Bên gọi vẫn phải cấp các tham số chung còn lại.
`BotNPrepareDistances` nhận dữ liệu giá/thời gian đã đọc và trả các
khoảng cách đã điều chỉnh. Chỉ dùng đầu ra khi hàm trả `true`.

Còn phải khôi phục phần điều chỉnh thêm/ngẫu nhiên, chọn chiến lược,
đọc bộ chỉ báo, tính khối lượng hoàn chỉnh, đặt/sửa/hủy/đóng lệnh,
bộ lọc thời gian/tin và giới hạn lỗ. Sau đó mới so toàn bộ EA dựng lại
với bản gốc trong cùng điều kiện.

Cách chạy lại: [cong-cu/BOT-1-3.md](cong-cu/BOT-1-3.md).
Kết quả 2.084 ca ở đây chỉ chứng minh phần đã kiểm, không phải toàn bộ bot.
