# Đuôi khởi động bot 1

## Phạm vi

Đoạn này phục hồi phần `OnInit` bot 1 từ độ lệch `0x4e77..0x5658` trong bản chụp mã gốc. Hàm dựng lại là `Bot1InitializeStartupTail` trong `Bot1StartupTail.mqh`.

Phần đã so gồm:

- tạo bốn chuỗi lệnh `B1`, `B2`, `S1`, `S2`;
- lưu giờ lịch, đặt `bar_times[0]` về 0 và đọc `SYMBOL_DIGITS`;
- nâng `panel.lots[strategy_index]` lên `start_lots` khi cần;
- các cổng bảng, quét lịch sử theo mã chiến lược và giới hạn 90 ngày;
- thứ tự gọi ba hàm bảng: tạo bảng, trạng thái lệnh mở, trạng thái đã đóng.

## Kết quả có bằng chứng

Lượt `b1-startup-tail-20261028-r1` có **309/309 ca khớp**, 74 trường và `1.968` lời gọi dịch vụ. Kết quả nằm trong `comparison.json`; bản gốc và bản MQL5 đều được kiểm bằng cùng `sdk-tape`.

Biên nhận biên dịch `b1-startup-tail-check-20261028-r4` ghi 0 lỗi và 0 cảnh báo. Mã SHA-256 của EX5 gốc được giữ trong `baseline.json` và là `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.

Sau khi thêm header tail vào bộ ghép, lượt `b1-all-headers-api-20261028-r24`
biên dịch 102 header với 0 lỗi và 0 cảnh báo; đây chỉ là kiểm ghép mã.

## Giới hạn

Ba hàm bảng được ghi nhận đối số và thay đổi trạng thái; thân của chúng có bằng chứng riêng. Dữ liệu trả lời MT5 và cấp phát chuỗi thành công được cấp cho lượt kiểm. Chưa kiểm nhánh lỗi `0x5659..0x5877`, cấp phát lỗi, toàn bộ `OnInit`, sự kiện EA hoặc chạy song song hai EA. Vì vậy đây là kiểm từng phần, không phải xác nhận toàn bot.

## Cách lặp lại

Không chạy lại khi nguồn và biên nhận không đổi. Nếu cần lặp, dùng công cụ `cong-cu/kiem-duoi-khoi-dong-bot-1.py` theo thứ tự `prepare`, `mql5`, `original`, `compare`, với tên lượt mới và MT5 thử riêng.
