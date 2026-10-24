# Bảng dừng lỗ/chốt lời ảo — bot 1 và 3

Trạng thái: **đã phân tích; chưa có nguồn MQL5 được kiểm đạt cho phần này**.
[Claude phân tích độc lập](danh-gia-claude/virtual-stops-20261024-r1/analysis.md),
[kết luận sau khi tự đối chiếu](danh-gia-claude/virtual-stops-20261024-r1/host-verdict.json).

| Phần | Bot 1 | Bot 3 |
|---|---|---|
| Bảng dừng lỗ và thời gian | 500 hàng × 3 số, `0x62590` | 500 hàng × 3 số, `0x6d680` |
| Bảng chốt lời | Chưa thấy bảng tương ứng | 500 hàng × 2 số, `0x70560` |
| Lấy/tạo mức dừng | `0x3d200` | `0x47f10` |
| Lấy/tạo mức chốt | Không có trong danh sách đã chụp | `0x482b0` |
| Kiểm chờ/đóng dấu giờ | `0x3d5a0`, `0x3d640` | `0x484c0`, `0x48560` |
| Xóa vé đã đóng khỏi bảng | `0x18790` | `0x20bc0`, tác động cả hai bảng |

Mỗi hàng lưu số vé bằng số thực. Vé 0 đánh dấu ô trống nhưng cũng có
thể khớp ngay trong vòng tìm vé; phải giữ đúng thứ tự và cách đổi kiểu.
Cờ cho phép được so đúng với byte `1`, chưa được tự đổi thành điều
kiện “khác 0”. Mức đã có trả lại mức lưu, không tính lại.

Mình đã bổ sung ba bằng chứng:

- [Hằng làm tròn](doi-chung-mt5/bang-dung-ao-20261024/rounding.json)
  đúng `-0.5000001` và `+0.5000001` ở cả hai bot.
- [Hai nơi gọi chốt lời bot 3](doi-chung-mt5/bang-dung-ao-20261024/take-profit-call-sites.json)
  truyền cùng vé với lời gọi dừng lỗ liền trước, ở cả nhánh mua/bán.
- [Sáu ca chạy hàm chốt lời gốc](doi-chung-mt5/bang-dung-ao-20261024/native-take-nan.json):
  với bảng trống, vé 1, cờ 1; `+0`, `-0`, `-1` không tạo hàng;
  `1`, số không xác định (`NaN`) và vô hạn dương được ghi. Đây chưa
  phải phép so với MQL5 hoặc bằng chứng cho toàn bộ bảng.

Claude đã trả [lượt phân tích bổ sung ở Max với Ultracode](danh-gia-claude/virtual-stops-ultracode-20261024-r2/analysis.md).
Sau đó mình đọc lệnh máy và giải đủ chuỗi cùng 7 đối số của ba chỗ
báo đầy bảng; [bằng chứng](doi-chung-mt5/bang-dung-ao-20261024/full-table-warning-schema.json).
Thứ tự là ghi vé đã báo → đếm vị thế → báo thông tin. Số ô trong
thông báo bằng 0 nếu byte cờ bằng 0, còn lại bằng 500; khác với điều
kiện cho phép truy cập bảng là byte cờ đúng bằng 1.

Đề xuất nguồn cũ còn bỏ thông báo và lần đếm vị thế khi đầy bảng nên
chưa được đưa vào nguồn chính. Còn phải đối chứng mã gọi thông báo,
việc chọn vị thế/đổi kích thước mảng khi dọn bảng, các lỗi, vé lớn/trùng,
trạng thái sau khởi động lại rồi mới dựng và so đầy đủ. P22 vẫn còn mở.
