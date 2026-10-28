# Giới hạn lỗ ngày — bot 1 và 3

Phạm vi: toàn nhánh giới hạn lỗ ngày nằm trong hàm điều phối ngoài.
Chưa phải hàm điều phối đầy đủ hoặc EA đầy đủ. Tệp EX5 gốc giữ nguyên.

| Nội dung | Bot 1 | Bot 3 |
|---|---|---|
| Hàm ngoài | `10f60..173e4` | `17f00..1fcf9` |
| Bắt đầu đoạn kiểm | `11bd6` | `19084` |
| Tiếp tục chiến lược | `11ed7` | `194ef` |
| Dừng lượt gọi | `16d74` | `1fb27` |
| Phần trăm giới hạn | `6a760` | `1d7158` |
| Số nến ngày đã nhớ | `682e4`, int32 | `75324`, int32 |
| Cờ dừng ngày | `682e0`, byte | `75320`, byte |
| Vốn đỉnh trong ngày | `68318`, double | `75348`, double |

Địa chỉ là độ lệch trong bản chụp đã kiểm. Mã kiểm tra cả hàm ngoài,
thông báo nguyên bản và lệnh máy lưu trong `botN-native.json`,
`botN-raw.txt` cùng thư mục. Bot 1 bắt đầu sau lệnh ghi giờ UTC nên
bộ kiểm cấp sẵn RSI=Bars, RDX=địa chỉ mã giá, R8D=PERIOD_D1,
R14=ô kết quả double. Bot 3 cấp R14=AccountInfoDouble, R15=ô kết quả.
Đây là trạng thái khung hàm đã có ở vị trí đó, không phải khởi tạo EA.

Trình tự đã đọc từ mã máy:

1. Gọi Bars với khung ngày. Nếu khác số đã nhớ, gọi Bars lần nữa rồi
   ghi kết quả lần hai; đặt cờ dừng và vốn đỉnh về 0.
2. Giữ phần trăm giới hạn sau bước trên. Nếu giá trị không lớn hơn 0,
   chỉ trả về cờ dừng hiện có. NaN cũng đi nhánh này.
3. Đọc vốn chủ sở hữu, rồi số dư. Nếu bằng nhau, trả về cờ dừng ngay.
   Nếu khác nhau, đọc vốn chủ sở hữu lần nữa; nếu lớn hơn vốn đỉnh,
   đọc thêm lần nữa để ghi vốn đỉnh.
4. HistorySelect từ 0 tới `0x7fffffff`. Nếu thành công, lấy tổng số
   giao dịch; duyệt ngược từ tổng trừ 1 tới 0. Mỗi vòng lấy mã giao
   dịch kể cả mã 0, đọc thời gian rồi gọi iTime khung ngày, lệch 0.
   Chỉ cộng khi thời gian giao dịch không trước nến ngày và DEAL_ENTRY
   bằng long 1. Không lọc mã giá, mã chiến lược hoặc loại giao dịch.
5. Đọc lãi, phí, phí qua đêm đúng thứ tự. Tính `part=lãi+phí`,
   `part=part+phí qua đêm`, rồi `sum=sum+part`. Không đổi thứ tự cộng.
6. Đọc vốn chủ sở hữu, rồi số dư lần cuối. Tính chênh lệch vốn, cộng
   tổng lịch sử rồi đảo bit dấu. Đây không phải trị tuyệt đối.
   Ngưỡng bằng `(phần_trăm_đã_giữ * vốn_đỉnh_hiện_tại)/100`.
7. Chỉ khi mức lỗ lớn hơn ngưỡng: nếu cờ dừng bằng 0 thì in đúng
   thông báo gốc; đóng vị thế mua, bán và xóa lệnh chờ đúng bộ lọc đã
   có; sau các tác dụng phụ mới ghi cờ=1, vốn đỉnh=0 và dừng lượt gọi.
   Bot 1 gọi thân `30010`; bot 3 có thân này viết ngay trong hàm ngoài,
   không phụ thuộc hai cài đặt đóng cuối tuần.

Phép kiểm phải so mọi lời gọi dịch vụ, đối số, trạng thái ngay trước
dịch vụ, mã lỗi, chuỗi và kết quả cuối từng bit. Các phép cộng, trừ,
nhân, chia của đoạn gốc dùng lệnh SSE2 thực thi trên CPU thật để tránh
khác biệt NaN đã đo ở Unicorn. Chỉ thay nơi thực hiện phép số học của
bộ kiểm; không sửa byte mã hoặc kết quả thuật toán EX5.

Giới hạn: phản hồi MT5 và khung đầu đoạn được cấp trong bộ kiểm; chưa
chứng minh mọi lỗi cấp phát, tổng số giao dịch INT_MIN hoặc việc khớp
lệnh ở nơi giao dịch thật. Không dùng kết quả này làm tỷ lệ toàn bot.
