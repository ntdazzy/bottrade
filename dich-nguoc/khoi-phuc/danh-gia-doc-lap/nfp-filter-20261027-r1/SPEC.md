# Ghép nguyên nhánh xử lý tin NFP

| Phần | Bot1 | Bot3 |
|---|---|---|
| Đoạn evaluator đã ghép |1b44f..1bdfd|2372b..24437|
| Hàm nguồn chính |Bot1ProcessNfpFilter|Bot3ProcessNfpFilter|
| Lấy lịch |61b0|6ad0|
| Kiểm giờ mùa hè |17840|7e20|
| Lấy năm/tháng |2ffb0/2ffe0|3d5f0/3d620|
| Hủy chờ mua/bán |2f5c0/2f7e0|3ca00/3cc20|
| Lọc/đóng vị thế mua/bán |2fa00/2fce0|3ce40/3d220|
| Kiểm đóng/đóng/chọn khớp/gửi |3d010/22c40/231c0/950|47d20/2e370/2e8f0/950|

Mã SHA từng thân gốc được lưu tại native-evidence.json, cùng bản liệt kê
nguyên đoạn điều phối. Codex đã đọc/chốt thuật toán trước khi viết.
Bản đề xuất ban đầu có sai khác trong thứ tự đọc giờ/phép tính và điều
kiện; được giữ riêng dưới tên rejected-proposal, không dùng để bàn giao.
Nguồn hiện hành do Codex viết lại, đã so với toàn đoạn gốc.

## Hành vi giữ nguyên

- Luôn xóa cờ thông báo khởi tạo của đoạn trước; NFPtắt thì giữ các
  trạng thái khác. Không tự xóa cờ chặnNFPchỉ vì cài đặt tắt.
- Khi dùng lịch và MQL_TESTERkhác1, đọc giờ máy chủ trước; sau đọc mới
  xét mốc lần hỏi và cờ giãn900giây. Chỉ khi giờ>mốc+thời lượng mới
  gọi lịch và ghi thời điểmNFP, rồi đọc giờ máy chủ lần nữa để lưu mốc.
- Thông báo lịch có lại dùng đúng chuỗi gốc, TimeToStringvới cờ3,
  và cờnotice&1; xóa toàn byte trước định dạng/in. Giữ tên/chuỗi nguyên bản.
- Cửa sổ lịch gọi TimeCurrent trước rồi mới đọc mốc và số phút.
  Chỉ khi qua đầu khoảng mới đọc TimeCurrent lần hai và xét cuối.
  Không tự thêm điều kiệnmốcNFP>0ở bước này. Ngoài cửa sổ ghi cờ0.
- Đọc lại MQL_TESTERở hai điểm sau cửa sổ. Có mốcNFPkhác0vàkhông
  chạy máy đo quá khứ thì bỏ nhánh dự phòng. Nếu mốc0vànotice0,
  đặt notice1 trước in thông báo dùng ngày có sẵn.
- Nhánh dự phòng chạy nguyên AmericanDSTvà lấy năm/tháng bằng
  TimeCurrent(MqlDateTime&). Năm<=2026quét300ô, đọc lại năm/tháng
  theo từng mốc; tìm được thì giữ đúng công thức đổi qua UTCRef.
  Kiểm cửa sổ bằngUTCRefvà mốc+bù; không cộng thêm giờ máy chủ.
- Năm>2026chỉ xét ngày đã lưu<=7vàthứ6(giá trị5). Ghép nguyên
  năm+tháng+ngày+SPACE+1230, giữ thứ tự các lần đọc mới; không sửa
  chuỗi lạ thành mẫu ngày khác. Nhánh này không ghi lại thời điểmNFP.
- Mọi thời lượng phút nhân ở32bit, mở rộng dấu rồi mới cộng/trừ64bit;
  không đưa dấu trừ vào trong phép nhân32bit vì sẽ lệch tại ngưỡng tràn.
- Trong khoảng chặn: hủy chờ mua rồi bán nếu bật; sau đó mới đọc cờ
  đóng, lọc/đóng mua rồi bán. Giữ cùng vé cuối, hai giá tham chiếu và
  khoảng cách/ngưỡng. Mã chiến lược và mã gốc là hai ô khác nhau.
- Sau các hành động, chỉ in khi cờ chặn cũ0, rồi ghi1. Các hàm con
  lịch, giờ, quét/hủy, kiểm/đóng, chọn khớp và gửi đều là nguồn thật.

## Phép so toàn chuỗi

107tình huống mỗi bot. Có bật/tắt, lịch/máy đo quá khứ, cờ thông báo,
ngưỡng giãn900giây, sát cửa sổ, số phút lớn/tràn, thiếu lịch, mốc dự
phòng, trước/sau2026, ngày đã lưu, có/không lệnh chờ và vị thế,
gửi đồng bộ/bất đồng bộ và chấp nhận/từ chối. Mỗi bot đi qua42lần
thân gửi và17lần thân đóng vị thế; các con khác có bộ đếm trong
verification.json, không nhận xét đã chạy chỉ từ tên hàm được nạp.

Bộ MQL5 chạy nguồn và ghi trả lời tại đúng ranh giới dịch vụ MT5.
Các phép đổi ngày/số/chuỗi/toán học được đo bằng hàm MT5thật, còn giờ,
lịch và dữ liệu giao dịch được cấp theo ca. Bộ chạy mã gốc phải dùng
cùng đầu vào, yêu cầu đúng thứ tự/đối số và có toàn trạng thái trước
mỗi lần gọi. Không lấy kết quả thuật toán của nguồn mới làm câu trả lời
cho hàm gốc. Không đặt lại dữ liệu ở ranh giới các hàm con.

So toàn bộ cài đặt/trạng tháiNFP, ba thời điểm tin, lịch đã lưu, các ô
mã/giá/ngưỡng/vé/độ lệch,35trường/4chuỗi giao dịch, cài đặt gửi và mã
lỗi cuối. Bộ trả lời giờ/bật máy thử/tổng số/vé/chấp nhận được buộc với
đầu vào; các hàm con chạy nguyên lệnh máy gốc, kể cả helperchuỗi và
dọn mảng. Hai mã kiểu mảng ngoài bản chụp chỉ được cấp cho ranh giới
SDK như phép kiểm lịch trước, không dùng làm điều kiện thuật toán.

## Giới hạn

Đã ghép nguyên nhánh NFP, chưa ghép toàn evaluator hoặcEA. Dữ liệu trước
đoạn này và khung gọi ban đầu được cấp, danh sách lệnh/vị thế còn đơn
giản, log_level0, chưa thử lỗi cấp phát hay giao dịch/tài khoản thật.
Chưa chạy bản gốc và nguồn hoàn chỉnh song song vìEAchính chưa đủ.
Bộ ca đạt không phải xác nhận mọi tổ hợp đầu vào hoặc toàn bot đạt100%.
