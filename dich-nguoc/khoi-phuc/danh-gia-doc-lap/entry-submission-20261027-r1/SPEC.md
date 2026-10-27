# Bot1: toàn vòng phát sinh lệnh sau nến mới

Nguồn `Bot1EntryLoop.mqh`, `Bot1EntrySubmissionLive.mqh`; vùng gốc
`0x1ca24..0x1e94f`. Dừng trước thống kê/hiển thị. EX5 gốc giữ nguyên.
Các ghi chú BUY/SELL ban đầu chưa được xác nhận chỉ là lịch sử phân tích;
nguồn đã đối chiếu, bản đồ trong `native-bindings.json` và tài liệu này
là căn cứ hiện hành.

## Luồng chính

- Giới hạn không dương thì thoát. Chụp cờ mua/bán một lần; giới hạn
  vòng vẫn được đọc lại sau mỗi lượt.
- Mỗi lượt chạy nguyên hàm khối lượng `0x34780`, nhân100hoặc0theo
  byte0x62554 hiện tại; áp trần `max_lots` sau khi hàm trả.
- Khi cài đặt hạn dương: đọc giờ rồi cộng số giây32bit **không dấu**.
  Chế độ xóa quá hạn đặt mốc hạn về0, duyệt tổng lệnh xuống0, lọc
  magic/symbol/type4hoặc lần đọc thứ hai5. Đọc giờ trước thuộc tính
  số1; khi giờ>=thuộc tính1+số giây thì chạy thân xóa thật.
- Mỗi chiều: cổng vị thế cùng chiều, nếu được phép thì tìm mức qua
  hàmEntryLevel, rồi kiểm lệnh gần lần nữa. Vòng vị thế đi tăng, đọc
  tổng mới ở cuối mỗi lượt; vòng lệnh đi giảm và gồm chỉ số tổng.
- Đếm lệnh cùng chiều; **chỉ** khi `count==maximum` mới dò cực trị.
  Giữ candidate chụp trước lần quét cực trị, nhưng đọc lại cờ thay lệnh.
- Đọc chữ số rồi làm tròn candidate sống; khác0kể cảNaN thì sao
  `step_reference` vào `active_step`. Đọc chữ số mới, tính giá dịch
  theo offset/đơn vị hiện tại. Mức mua/bán đi độc lập, không bỏ chiều
  còn lại chỉ vì chiều đầu không qua cổng.
- Gọi ký quỹ khi bật, làm tròn giá/SL/TP, kiểm khối lượng, giới hạn
  tài khoản và hai khoảng cách. Gửi bằng thân mở/chọn khớp/gửi thật.
  Nhận lần đầu: ghi bool1và giá cơ sở vào ô trống đầu bảng kết quả.
  Thất bại: lỗi132thì chờ2500/gửi lại, giữ giá nhưng đọc lại cấu hình;
  bỏ qua bool retry, báo lỗi cuối kể cả retry thành công.

`Bot1EntryLevels.mqh` đổi các dữ liệu toàn cục sang tham chiếu hằng:
symbol, độ rộng, last_shift, khung xác nhận, quote/gap/đơn vị/magic và
offset/radius. Khung dò được truyền bằng giá trị như thanh ghi đầu vào
gốc. Thân tìm mức không đổi; bản trước được giữ nguyên byte.

## Bằng chứng chạy

`kiem-vong-phat-sinh-lenh-bot-1.py prepare|mql5|original|compare 1 RUN`;
`mql5` cần `--build BUILD`. Bộ ghi tạo bằng
`tao-bo-kiem-vong-phat-sinh-lenh-bot-1.py`.

R3: **168/168ca khớp**, **14.103 lần gọi dịch vụ**. So mọi đối số,
trạng thái sử dụng/ghi của vòng và35trường/4chuỗi giao dịch trước
dịch vụ/cuối vòng. Các thân khối lượng, tìm mức, lệnh gần, ký quỹ,
kiểm khối lượng, mở/chọn khớp/gửi/báo lỗi gốc tự chạy; không cấp kết
quả hàm con. Nguồn trực tiếp/bộ kiểm0lỗi/0cảnh báo.

Có giới hạn-1/0/1/2/3, cờ0/1/255, hai chiều, vị thế cùng/khác mã,
lệnh gần và thay ởcount==maximum, hạn không dấu0xffffffff, ký quỹ,
cờ bỏSLTP/hạn ảo, gửi đồng bộ/bất đồng bộ, lỗi3/132/999và thử lại.

Bộ ghi chỉ so trạng thái thực sự thuộc vòng này. Không tái dùng vùng
đệm cache100ô từ lát trước như các biến độc lập: địa chỉ0x673e8 là
`active_step`, trùng ô cuối của vùng cache được cấp giả trong lát cũ.
Các chỉ số chiến lược hợp lệ của bot1là0..7. `write-map-case22.json`
ghi các vùng chương trình thực sự bị sửa trong ca mua+bán: candidate,
rounded, active_step, khối lượng, bảng kết quả, giao dịch và vốn;
tất cả nằm trong bảng trạng thái đang so.

Rà độc lập `friday_flow_review`: không thấy sai khác cụ thể trong hai
nguồn mới; nhận xét không thay phép so.

## Giới hạn

Lượt ghép này dùng chế độ khối lượng0và tắt rút tiền. Các chế độ khác
đã có bộ kiểm hàm khối lượng riêng nhưng chưa ghép lại trong lượt này.
Giá/dữ liệu tài khoản/trả lời dịch vụ/lỗi được cấp; chờ được ghi,
không chờ thật. Không kiểm lỗi cấp phát, nguồn vốn thật hoặc môi
trường giao dịch thật. Chưa nối vòng này với toàn evaluator, khởi tạo,
thống kê/hiển thị và các sự kiện EA. Chưa là bot hoàn chỉnh hoặc cặp
bot gốc/dựng lại. Không lấy168ca làm phần trăm toàn bot.
