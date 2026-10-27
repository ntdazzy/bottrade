# Đối chiếu đoạn trước chuẩn bị — 27/10/2026

Codex phân tích bản gốc, viết nguồn/bộ kiểm và tự đối chiếu. Không có
đánh giá ngoài từ Claude trong lượt này. Chưa có EA hoàn chỉnh.

| Nội dung | Bot 1 | Bot 3 |
|---|---|---|
| Ghi chú/mã/đổi tiền, chuỗi UTF-16 đầy đủ và thứ tự đọc | 760/760 | 1.818/1.818 |
| Chia 0, đúng loại lỗi và không ghi kết quả thường | 2/2 | 3/3 |
| Bản dùng dịch vụ thật, chỉ biên dịch | 0 lỗi/0 cảnh báo | 0 lỗi/0 cảnh báo |
| Bản kiểm dùng câu trả lời được cấp | 0 lỗi/0 cảnh báo | 0 lỗi/0 cảnh báo |

Mã gốc được chạy từ các đoạn trong hàm gọi cùng thân hàm đổi tiền,
chuỗi và dọn chuỗi. Bộ kiểm cung cấp thanh ghi/khung ngăn xếp, cấp
chuỗi thành công và dịch vụ MT5. Các lệnh so trước điểm bắt đầu được
chạy thêm từ đúng byte gốc khi điểm bắt đầu là lệnh nhảy. Không sửa
EX5 gốc. Lỗi chỉ chứng minh loại dừng; chưa so mọi trạng thái trước lỗi.

Hai sai khác đã được xử lý bằng bằng chứng gốc:

- Lượt r1: đọc tiền tài khoản một lần không giữ đúng các lần đọc ở
  từng điều kiện. Giá trị tiền giống chưa đủ. Bản sửa đọc mới, giữ
  thứ tự và hai nhánh CHF của bot 1/CZK của bot 3.
- Lượt r2: JPY khớp phải bỏ kiểm YEN, vì chúng cùng một điều kiện.
  Ngoài ra một số đoạn bắt đầu ở lệnh nhảy; bộ kiểm ban đầu thiếu
  kết quả phép so nằm trước lần ghi cuối của khối cấu hình. Đã sửa
  bằng cách chạy đúng lệnh so gốc, không tự gán kết quả mong đợi.

`first-comparison/` và `second-comparison/` giữ đúng byte nguồn/bộ
kiểm của hai lượt chưa đạt. Các báo cáo r1/r2 được giữ và không được
dùng làm bằng chứng đạt. Lượt hiện hành là r3. `verification.json`
ghi mã kiểm kết quả; `native-account-conditions.json` ghi vị trí chuỗi,
thứ tự điều kiện từ mã trung gian, mã kiểm của hàm máy gốc; phép chạy
và so MQL5 là bằng chứng kiểm độc lập cho dữ liệu trong bảng.

Nguồn mới: `Bot1StrategyContext.mqh`, `Bot3StrategyContext.mqh`.
Hai bản `BotNStrategyContextAPICompile.mq5` nối lời gọi nạp cấu hình →
ngữ cảnh → chuẩn bị để kiểm biên dịch, mặc định không chạy chức năng.
Chưa gọi ba thân này liên tục trong cùng phép so; bước kế tiếp là nối
phép chạy đó rồi tiếp tục chương trình chính. Vẫn còn các nhánh vào
lệnh, vòng đời, hiển thị và so toàn bộ hai EA. Số ca đạt không phải % bot.
