# Bot 1 và bot 3 — kết quả ngày 23/10/2026

**Đã xuất mã trung gian của các hàm trong bảng mã đã chụp, và dựng lại hai hàm mức giá của mỗi bot bằng MQL5. Chưa có bot MQL5 hoàn chỉnh để giao dịch.**

**Cập nhật lượt tiếp:** đã dựng thêm bước xác nhận mức giá và kiểm lệnh
chờ gần (1.096/1.096 ca mỗi bot), cùng bảng tham số gốc của 8/9 chiến lược
(102 giá trị). Xem [phần vào lệnh mới](PHAN-TICH-VAO-LENH-BOT-1-3.md).
Các kết quả 1.104 ca bên dưới thuộc bộ kiểm mức giá ban đầu và vẫn được giữ.

| Phần đã kiểm | Bot 1 | Bot 3 |
|---|---:|---:|
| EX5 gốc khớp mã kiểm tra trong hồ sơ | Có | Có |
| Hàm trong bảng mã mới | 84 | 82 |
| Hàm đã xuất sang C trung gian | 84/84 | 82/82 |
| Dòng tham số đọc từ nhật ký gốc, gồm các tiêu đề | 72 | 80 |
| Hàm mức giá đã dựng lại bằng MQL5 | 2 | 2 |
| Ca so đoạn mã gốc với MQL5 | 1.104/1.104 trùng | 1.104/1.104 trùng |
| Biên dịch bộ kiểm mới nhất | 0 lỗi, 0 cảnh báo | 0 lỗi, 0 cảnh báo |

“84/84” và “82/82” chỉ là số hàm xuất được từ bảng trong bản chụp này.
Mã C còn tên tự sinh, kiểu dữ liệu và lời gọi cần kiểm tiếp. Các số này
**không có nghĩa đã khôi phục toàn bộ bot hoặc giống bản gốc 100%**.

## Mở kết quả

| Nội dung | Bot 1 | Bot 3 |
|---|---|---|
| Nguồn MQL5 đã kiểm | [Bot1PriceLevels.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1PriceLevels.mqh) | [Bot3PriceLevels.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3PriceLevels.mqh) |
| Mã C trung gian mới | [ma-trung-gian.c](bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c) | [ma-trung-gian-day-du.c](bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c) |
| Danh sách hàm, vị trí và lời gọi MT5 | [danh-sach-ham.json](bot-cua-toi-1/phan-tich/luot-20261023-data-v2/danh-sach-ham.json) | [danh-sach-ham.json](bot-cua-toi-3/phan-tich/luot-20261023-data/danh-sach-ham.json) |
| Tham số quan sát khi chạy bản gốc | [tham-so-quan-sat.json](bot-cua-toi-1/phan-tich/luot-20261023-data-v2/tham-so-quan-sat.json) | [tham-so-quan-sat.json](bot-cua-toi-3/phan-tich/luot-20261023-data/tham-so-quan-sat.json) |
| Kết quả so hai hàm mức giá | [comparison.json](bot-cua-toi-1/bang-chung/kiem-muc-gia/gia-20261023-r1/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-muc-gia/gia-20261023-r1/comparison.json) |
| Bản biên dịch dùng để kiểm | [bien-nhan.json](bot-cua-toi-1/bang-chung/bien-dich/b1-price-levels-02/bien-nhan.json) | [bien-nhan.json](bot-cua-toi-3/bang-chung/bien-dich/b3-price-levels-02/bien-nhan.json) |

## Quy tắc của hai hàm mức giá đã xác minh

Hai bot cho cùng kết quả trên bộ 1.104 ca đã chạy. Mỗi bot vẫn được kiểm
bằng vùng mã riêng của chính nó.

1. Bắt đầu từ nến có chỉ số `recent_width + 1`, rồi đi dần về quá khứ.
2. Với mức trên, đỉnh được chọn phải không thấp hơn các đỉnh trong hai
   khoảng nến được yêu cầu. Với mức dưới, đáy phải không cao hơn các đáy
   trong hai khoảng đó. Giá bằng nhau vẫn được chấp nhận ở bước này.
3. Mức trên phải **lớn hơn** giá mua cộng khoảng cách. Mức dưới phải
   **nhỏ hơn** giá bán trừ khoảng cách. Bằng đúng ngưỡng thì không đạt.
4. Trả mức đầu tiên đạt theo thứ tự nến đang xét; không chọn mức gần giá
   hiện tại nhất trong tất cả các mức.
5. Giá trả về được làm tròn theo cách trong mã gốc: giới hạn số chữ số ở
   11 và dùng hằng `0.5000001` theo dấu. Đã giữ phép tính này trong nguồn.
6. Không tìm thấy: hàm mức trên trả `9999.0`, hàm mức dưới trả `0.0`.
7. Mã gốc luôn xét ứng viên đầu tiên một lần, kể cả khi giới hạn nến nhỏ
   hơn vị trí bắt đầu. Bản dựng giữ điều này và đã có ca kiểm riêng.

Vị trí hai hàm trong vùng mã: bot 1 `0x32890` / `0x32ac0`; bot 3
`0x3e040` / `0x3e270`. Tên MQL5 là tên đặt khi dựng lại.

**Chưa xác minh đầy đủ cách từng chiến lược cấp tham số cho các hàm này.**
Vì vậy chưa thể dùng riêng hai hàm để kết luận toàn bộ điều kiện vào lệnh.

## Cách kiểm chứng

- Phía gốc: chạy trực tiếp đoạn lệnh máy đã chụp trong bộ mô phỏng CPU.
  Các lời đọc giá cao/thấp và số chữ số được thay bằng dữ liệu ca kiểm.
- Phía mới: chạy MQL5 đã biên dịch trong MT5 riêng; chương trình kiểm chỉ
  tính toán, không gửi lệnh giao dịch.
- So đúng từng bit của giá trả về, số lần đọc và mã kiểm tra thứ tự đọc.
  Cả hai bot có tệp kết quả gốc và MQL5 giống hệt nhau.
- Bộ ca gồm dữ liệu ngẫu nhiên cố định, giá bằng nhau, giá sát ngưỡng,
  giới hạn nến, dữ liệu mẫu thiếu, số âm, số rất lớn và số không hợp lệ.
- Giới hạn: đây là phép kiểm hai hàm với đầu vào cấp sẵn. Chưa so toàn bộ
  bot, khớp lệnh của sàn, giao diện, lịch tin, lưu trạng thái hoặc lợi nhuận.

## Những phần đã thấy nhưng chưa khôi phục xong

| Phần | Bằng chứng hiện có | Việc còn phải làm |
|---|---|---|
| Lựa chọn chiến lược bot 1 | Đã kiểm 6 giá trị gốc × 8 bảng; có MQL5 | Nối đầy đủ với nhánh bật/tắt và phần điều chỉnh động |
| Lựa chọn chiến lược bot 3 | Đã kiểm 6 giá trị gốc × 9 bảng; có MQL5 | Xác định đầy đủ tác động của `TradeFrequency` và các lựa chọn bật/tắt |
| Tìm mức giá | Hàm ban đầu, xác nhận mức chưa bị phá và kiểm lệnh chờ gần đã có MQL5, có phép so | Ghép vào toàn bộ điều kiện vào lệnh |
| Quét lệnh và vị thế | Mã C có lời gọi đọc lệnh/vị thế; xem danh sách hàm | Giải nghĩa các trường, điều kiện lọc, thứ tự sửa/hủy/đóng |
| Khối lượng và giới hạn lỗ | Có các tham số `Risk`, `CheckMargin`, `UseEquity`, giới hạn lỗ ngày | Dựng công thức và so riêng từng chế độ; chưa coi tên tham số là bằng chứng công thức |
| Dời dừng lỗ, dừng lỗ/chốt lời ẩn | Có các tham số liên quan trong nhật ký | Xác định toàn bộ điều kiện kích hoạt và xử lý sau khớp |
| Tin kinh tế | Có nhóm tham số NFP, lãi suất, CPI | Xác định lịch, múi giờ và cách xử lý từng tình huống |
| Hiển thị, khởi động lại và lỗi | Có mã trung gian và các lời gọi tương ứng | Dựng lại và kiểm bằng chạy thực tế |

Bộ `.set` đi kèm không được dùng làm danh sách giá trị mặc định. Ví dụ:
bot 1 trong lượt gốc có `Risk=0`, còn bộ `.set` là `999`; bot 3 có
`TradeFrequency=5`, còn bộ `.set` là `2`. Đây là các cấu hình khác nhau.
Lượt gốc có chủ động đặt `AutoGMT=false`, giờ mùa đông/mùa hè bằng 0;
các giá trị đó không được báo là giá trị mặc định của tác giả.

## Dữ liệu và phạm vi chạy

- EX5 bot 1: `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
- EX5 bot 3: `ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`.
- Cả hai lấy từ thư mục MT5, khớp hồ sơ gốc. Không dùng EX5 đã sửa nhãn
  trong các thư mục đánh số làm chuẩn.
- Máy thử riêng xác nhận tài khoản demo. Lượt bot 1 dài được dừng sau khi
  chụp thành công; lượt bot 3 bị quá 300 giây. **Hai lượt này không có báo
  cáo giao dịch hoàn tất**, không dùng chúng để kết luận lời/lỗ.
- Bảng hàm mới được đọc từ dữ liệu chương trình đã chụp, kiểm thứ tự,
  giới hạn địa chỉ và thông tin khôi phục ngăn xếp. Định dạng đối chiếu:
  [tài liệu x64 của Microsoft](https://learn.microsoft.com/en-us/cpp/build/exception-handling-x64).
- 141 nhãn hàm MT5 và 81 dạng lời gọi kế thừa bộ đo trước, sau khi xác nhận
  cùng mã kiểm tra `metatester64.exe` và địa chỉ nền của đúng tiến trình.
  Không tái dùng các vị trí lời gọi riêng của bot 13.
- Thư mục dự án Ghidra tạm được giữ tại `tam-bot1-3-20261023/` để tiếp tục
  đọc mã. Đây không phải nguồn MQL5 bàn giao.

## Bước tiếp

1. Nối hai hàm mức giá với bảng thông số của từng chiến lược.
2. Khôi phục điều kiện mở lệnh, tính khối lượng và quản lý lệnh theo từng
   phần, mỗi phần có phép so với đoạn mã gốc.
3. Ghép thành EA, biên dịch và chạy bản gốc/bản dựng trên cùng điều kiện.
4. Chỉ kết luận hoàn chỉnh khi các phần còn lại đã được dựng và kiểm.

Công cụ và cách chạy: [cong-cu/BOT-1-3.md](cong-cu/BOT-1-3.md).
