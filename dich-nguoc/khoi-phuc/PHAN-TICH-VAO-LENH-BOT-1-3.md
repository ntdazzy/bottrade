# Bot 1 và 3 — phần mức giá dùng trước khi vào lệnh

Ngày kiểm: 23/10/2026. **Đã dựng và kiểm thêm bộ lọc lệnh chờ gần, bước
xác nhận mức giá chưa bị phá và bảng tham số gốc. Chưa ghép thành EA hoàn chỉnh.**

Cập nhật sau: đã dựng phần điều chỉnh khoảng cách và bảng cơ bản mở rộng;
xem [kết quả tiếp theo](PHAN-TICH-DIEU-CHINH-BOT-1-3.md).

| Kết quả mới | Bot 1 | Bot 3 |
|---|---:|---:|
| Nhánh mã gốc được đối chiếu trong phần mới | 4 | 4 |
| Ca kiểm khớp | 1.096/1.096 | 1.096/1.096 |
| Bảng chiến lược gốc khớp | 8/8 | 9/9 |
| Giá trị gốc khớp, 6 giá trị mỗi bảng | 48/48 | 54/54 |
| Biên dịch bản mới nhất | 0 lỗi, 0 cảnh báo | 0 lỗi, 0 cảnh báo |

## Mã và bằng chứng

| Nội dung | Bot 1 | Bot 3 |
|---|---|---|
| Tìm mức giá và kiểm lệnh chờ | [Bot1EntryLevels.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1EntryLevels.mqh) | [Bot3EntryLevels.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3EntryLevels.mqh) |
| Bảng tham số gốc | [Bot1EntryProfiles.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1EntryProfiles.mqh) | [Bot3EntryProfiles.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3EntryProfiles.mqh) |
| Kết quả so MQL5 | [comparison.json](bot-cua-toi-1/bang-chung/kiem-gia-vao/entry-20261023-r3/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-gia-vao/entry-20261023-r3/comparison.json) |
| Kiểm bảng tham số bằng lệnh máy | [kiem-tham-so-goc.json](bot-cua-toi-1/phan-tich/luot-20261023-data-v2/kiem-tham-so-goc.json) | [kiem-tham-so-goc.json](bot-cua-toi-3/phan-tich/luot-20261023-data/kiem-tham-so-goc.json) |
| Vị trí gán tham số trong mã C | [noi-tham-so-muc-gia.json](bot-cua-toi-1/phan-tich/luot-20261023-data-v2/noi-tham-so-muc-gia.json) | [noi-tham-so-muc-gia.json](bot-cua-toi-3/phan-tich/luot-20261023-data/noi-tham-so-muc-gia.json) |
| Tình huống kiểm cụ thể | [coverage.json](bot-cua-toi-1/bang-chung/kiem-gia-vao/entry-20261023-r3/coverage.json) | [coverage.json](bot-cua-toi-3/bang-chung/kiem-gia-vao/entry-20261023-r3/coverage.json) |

## Quy tắc đã xác minh

**Kiểm lệnh chờ gần mức giá**

- Chỉ xét lệnh có cùng mã giao dịch và cùng số nhận dạng chiến lược.
- Với chiều mua, chỉ xét lệnh chờ mua khi giá tăng tới mức đặt; với chiều
  bán, chỉ xét lệnh chờ bán khi giá giảm tới mức đặt.
- Mức so của chiều mua = mức giá tìm được + độ dịch mua × đơn vị giá.
  Mức so của chiều bán = mức giá tìm được − độ dịch bán × đơn vị giá.
- Đã có lệnh gần nếu khoảng cách tuyệt đối từ giá đặt lệnh đến mức so
  **nhỏ hơn** đơn vị giá × ngưỡng khoảng cách. Giữ dấu `<` và thứ tự tính
  trong bản gốc; không tự làm tròn khoảng cách trước khi so.
- Giữ cách duyệt của bản gốc, kể cả lượt đầu đọc tại chỉ số bằng tổng số
  lệnh. Giá trị vé lệnh được lưu sau mỗi lần đọc cũng được đối chiếu.

**Tìm mức giá được phép dùng tiếp**

1. Tìm đỉnh/đáy theo hai khoảng nến và khoảng cách tới giá hiện tại.
2. Đọc thêm từ nến 0 đến đúng chỉ số ứng viên trên khung kiểm tra.
   Giữ nguyên chỉ số nến; không tự đổi số nến theo tỷ lệ hai khung.
3. Với mức trên: đỉnh cao nhất trong đoạn kiểm không được vượt ứng viên.
   Với mức dưới: đáy thấp nhất trong đoạn kiểm không được thấp hơn ứng viên.
4. Làm tròn ứng viên rồi gọi bộ kiểm lệnh chờ gần.
5. Nếu bị loại, đi tiếp về quá khứ. Trả mức đầu tiên đạt; không có mức đạt
   thì trả `0.0` cho cả hai chiều của hàm mới này.

Hàm mới khác hai hàm đã dựng ở lượt trước về bước xác nhận và kiểm lệnh
chờ. Hai hàm cũ vẫn được giữ nguyên; không đổi giá trị báo không tìm thấy.

Vị trí gốc: bot 1 `0x265a0`, `0x26960`, `0x3c670`, `0x3c8d0`;
bot 3 `0x31cd0`, `0x32090`, `0x47380`, `0x475e0`.

## Ví dụ đã chạy

Với ba mức mua hợp lệ 102, 103, 104:

| Lệnh chờ đã có gần các mức | Kết quả cả bản gốc và MQL5 |
|---|---:|
| Không có | 102 |
| Gần 102 | 103 |
| Gần 102 và 103 | 104 |
| Gần cả ba | 0 |
| Giá trên khung kiểm đã vượt cả ba mức | 0 |

Chiều bán đã kiểm tương ứng 98 → 97 → 96 → 0. Đây là dữ liệu cấp sẵn
để kiểm hàm, không phải ví dụ lợi nhuận hoặc khuyến nghị giao dịch.

## Phạm vi bộ kiểm

- Mỗi bot: 299 ca kiểm lệnh chờ bán, 249 ca mức bán, 299 ca kiểm lệnh chờ
  mua và 249 ca mức mua.
- Có ca trùng/khác số nhận dạng, khác mã giao dịch, vé bằng 0, sai loại
  lệnh, sát ngưỡng khoảng cách, giá bị phá, nhiều mức liên tiếp bị chặn,
  chuỗi rỗng/tiếng Việt, dữ liệu mẫu thiếu và số không hợp lệ.
- So từng bit kết quả, vé lệnh cuối, số lời gọi và mã kiểm tra thứ tự
  gọi các hàm MT5. Các mã thuộc tính/lệnh cũng được lấy từ MQL5 đã biên dịch.
- Đoạn mã gốc chạy trong bộ mô phỏng CPU. Bộ mô phỏng cấp giá, danh sách
  lệnh và bộ nhớ chuỗi hợp lệ; mã sao chép chuỗi của bot vẫn được chạy.
  Chưa kiểm trường hợp cấp phát bộ nhớ thất bại hoặc toàn bộ mã lỗi MT5.
- Lượt `r3` chạy lại MQL5 có mã hoàn tất rõ ràng và kiểm bảng tham số. Kết quả lệnh máy
  của `r1` được dùng lại vì đầu vào và vùng mã không đổi; có tệp
  `original-reuse.json` ghi rõ việc này.

## Bảng tham số gốc

Đã đối chiếu 6 giá trị mỗi chiến lược bằng lệnh gán thật trong mã máy,
rồi so với bảng MQL5. Gồm hai giá trị chọn khung, hai chiều rộng nến,
giới hạn tìm và khoảng cách gốc. Các khoảng cách này còn được điều chỉnh
ở bước sau; **chưa phải toàn bộ cấu hình giao dịch cuối cùng**.

Một giá trị của bot 1 được nạp trước nhánh chiến lược rồi dùng lại. Bộ
kiểm lần ngược các đường đi và chỉ chấp nhận khi mọi nơi gán đều chứa
cùng một hằng số. Không lấy giá trị dự kiến để điền vào bộ mô phỏng.

Các số thứ tự là mã nội bộ của bot. Chưa đồng nhất chúng với tên bật/tắt
trên giao diện khi chưa kiểm đủ nhánh chọn chiến lược.

## Lỗi bộ kiểm đã xử lý

Lượt `r1/r2` dùng `void OnStart()` và nhật ký MT5
ghi script đóng máy với mã `2`, dù đã tạo đủ kết quả. Bộ kiểm đã chuyển
sang `int OnStart()`, trả `0` khi hoàn tất và `1` khi đầu vào/tệp không
hợp lệ, theo [hướng dẫn OnStart của MQL5](https://www.mql5.com/en/docs/event_handlers/onstart).
Lượt `r3` của cả hai bot thoát `0`, dữ liệu vẫn khớp từng byte. Đã thử
thiếu tên lượt và sai tiêu đề tệp: cả hai bị từ chối bằng mã `1`.
Thay đổi nằm ở chương trình kiểm, không đổi các quy tắc giao dịch vừa dựng.

## Còn phải làm

1. Ghép đúng nhánh chọn chiến lược và hệ số điều chỉnh các khoảng cách.
2. Khôi phục tính khối lượng, dừng lỗ/chốt lời, đặt/sửa/hủy/đóng lệnh.
3. Kiểm các bộ lọc thời gian/tin, giới hạn lỗ, khởi động lại và lỗi.
4. Chạy toàn bộ EA dựng lại và bản gốc trên cùng điều kiện.

Không có kết luận giống toàn bộ bot 100% từ các phép kiểm trên.
