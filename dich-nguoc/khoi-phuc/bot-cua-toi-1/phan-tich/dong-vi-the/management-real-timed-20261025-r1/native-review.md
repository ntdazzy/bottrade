# Dừng lỗ thật theo thời gian — bot 1

Codex đọc trực tiếp hai thân quản lý trong management-20261025-r1/analysis.json,
đúng EX5 SHA a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922,
base 0x23e5aa10000. Mua 27ee4..28220, bán 2b8ed..2bc82, cạnh ra bán 2b938.
Không phải toàn bộ hàm quản lý.

Giá trị: activation624f8, distance62500, unit66d98, delay int32 tại6745c,
gap66a70, freeze67468, bid67758/ask67760. SL trong XMM8, TP XMM7,
zero XMM10. Giờ mở ở SP70/SP80; vé mua SP30, bán RBP; cờ SP50/SP58.

- Chung: chỉ chạy khi 0<activation. TimeCurrent, cộng giờ mở và delay
  đã mở dấu lên64bit theo phép cộng tràn64bit, so thời gian có dấu.
- Mua: chụp bid trước DIGITS1, rồi POINT; làm tròn
  distance*unit+(point+SL), yêu cầu kết quả<bid đã chụp. Đọc bid mới,
  yêu cầu bid<TP-freeze. DIGITS2, đọc bid mới, SL=Round(bid-distance*unit),
  gán SL ngay trước phép so SL<bid đã chụp-gap. Không đạt vẫn giữ SL vừa gán.
- Bán: chụp ask trước POINT, không hỏi DIGITS/làm tròn ở cổng đầu;
  yêu cầu ask<(SL-point)-distance*unit. Đọc ask mới, freeze+TP<ask.
  DIGITS1 rồi Round(distance*unit+ask)<SL cũ. DIGITS2, đọc ask mới,
  SL=Round(distance*unit+ask), gán trước cổng ask đã chụp+gap<SL.
- Qua cổng cuối thì gọi sửa26d20. Cờ yêu cầu=true dù sửa trảfalse;
  false mới báo lỗi. Không kiểm khối lượng hoặc đóng ở lát này.
- Mua gọi sửa2811d, lỗi2812e; bán2bb64, lỗi2bb75. Chuỗi đầu ở55978,
  chuỗi cuối đọc trực tiếp5599c là
  `' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!`.
  Hàm đổi lỗi336d0, dữ liệu lỗi6a410, chuỗi trả6a43c, ô số trả6a448.

Sau khi so từng công thức/thứ tự, Codex chuyển riêng tên Bot3→Bot1 từ
hai hàm Claude đã viết. Thân tính không đổi. Có biên nhận chuyển nguồn;
chỉ phép so native/MQL5 mới xác định kết quả, không coi việc đổi tên là đạt.
Khối tạo/in thông báo sẽ được cấp câu trả lời tại ranh giới ở phép kiểm
tính toán, vì vậy không tuyên bố đã chạy thân thông báo hoặc toàn bộ EA.
