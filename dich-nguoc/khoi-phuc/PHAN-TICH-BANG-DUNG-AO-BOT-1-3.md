# Bảng dừng lỗ/chốt lời ảo — bot 1 và 3

Trạng thái: **bot 1 khớp 220 ca thường và hai ca lỗi mảng trong phạm vi đã ghi;
chưa ghép quản lý vị thế hoặc toàn EA**. Bot 3 có mô tả năm hàm và
đang được năm Claude viết các phần độc lập; chưa có kết quả so nguồn.
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

Claude đã trả [lượt phân tích bổ sung yêu cầu Max và Ultracode](danh-gia-claude/virtual-stops-ultracode-20261024-r2/analysis.md).
Sau đó mình đọc lệnh máy và giải đủ chuỗi cùng 7 đối số của ba chỗ
báo đầy bảng; [bằng chứng](doi-chung-mt5/bang-dung-ao-20261024/full-table-warning-schema.json).
Thứ tự là ghi vé đã báo → đếm vị thế → báo thông tin. Số ô trong
thông báo bằng 0 nếu byte cờ bằng 0, còn lại bằng 500; khác với điều
kiện cho phép truy cập bảng là byte cờ đúng bằng 1.

Đã nối [mã gọi thông báo 2 với `Print`](doi-chung-mt5/bang-dung-ao-20261024/print-opcode-proof.json)
bằng chương trình có nguồn và bản chụp cũ, không đoán theo tên chuỗi.
Đề xuất nguồn cũ còn bỏ thông báo và lần đếm vị thế khi đầy bảng nên
chưa được đưa vào nguồn chính. Đây là tình trạng ở lượt cũ; các phép
kiểm mới của bot 1 được nêu bên dưới. P22 vẫn còn mở.

Lượt mới do Codex trực tiếp làm theo phân công người dùng đã xác nhận:

- [Phân tích bốn hàm bot 1](bot-cua-toi-1/phan-tich/dong-vi-the/virtual-stops-20261025-r1/analysis.md):
  420 lệnh, đủ hàm dọn bảng, lấy mức, kiểm chờ và ghi giờ. Bằng chứng
  có nguồn cũ đã xác nhận lời gọi `ArrayResize` tại `0x7aa0e0`; không
  còn đoán tên lời gọi này từ cách dùng.
- [Nguồn mới](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1VirtualStops.mqh)
  biên dịch 0 lỗi/cảnh báo; [bảy bước ban đầu](bot-cua-toi-1/bang-chung/kiem-bang-dung-ao/virtual-smoke-20261025-r1/comparison.json)
  khớp từng byte mã gốc: tạo mức, dùng lại mức cũ, chờ khi chưa ghi
  giờ, ghi giờ, trước/đúng mốc chờ, dọn khi không còn vị thế.
- Đã so 1.500 số trong bảng, byte cho phép, vé đã báo, độ dài mảng,
  giá trị trả có nghĩa và thứ tự lời gọi. Chỉ chạy 204/420 lệnh máy;
  số này không phải tỷ lệ hoàn thành. Chưa kiểm nhiều vị thế, bảng
  đầy, nội dung mảng vé/lỗi mở rộng, số đặc biệt và máy đo quá khứ.
  Bot 3 và việc ghép vào quản lý vị thế vẫn chưa đạt.

## Lượt mở rộng đã kiểm

- [220/220 ca thường](bot-cua-toi-1/bang-chung/kiem-bang-dung-ao/virtual-matrix-20261025-r4/comparison.json)
  khớp mã gốc và nguồn MQL5: hai hướng tính mức, hướng không hợp lệ,
  làm tròn/không gộp phép nhân với cộng, vé lớn/trùng/âm/0, số đặc
  biệt, bảng đầy/thông báo, thu vé/chọn vị thế, mảng thường/đảo và
  mở rộng, thay trạng thái ở lời gọi ngoài, trước/đúng mốc chờ.
  So đủ 1.500 số trong bảng, trạng thái liên quan, toàn mảng vé và
  chữ/kiểu/thứ tự lời gọi; câu trả lời truy vấn/giờ được cấp trong bộ kiểm.
- [Cùng thân kiểm trong máy đo quá khứ MT5](doi-chung-mt5/bang-dung-ao-20261025/engine-virtual-b1-r3/comparison.json)
  cũng khớp 220/220; kết quả, luồng lời gọi, mảng cấp phát thật và
  trạng thái kết thúc bằng nhau từng byte với lượt Script. Bản nguồn
  kiểm biên dịch 0 lỗi/cảnh báo. Lượt trước `engine-virtual-b1-r2`
  mất kết nối máy chủ demo, bị từ chối xác nhận và được giữ nguyên;
  lượt r3 đã xác nhận lại demo, không nới điều kiện để nhận r2.
- [Hai ca lỗi mảng chạy thật](bot-cua-toi-1/bang-chung/kiem-bang-dung-ao/virtual-matrix-20261025-r4/fatal-checks/virtual-faults-20261025-r3/summary.json):
  khi lần mở rộng được cấp kết quả thất bại và phép ghi vượt mảng,
  nguồn MQL5 kết thúc với lỗi mảng; trạng thái và luồng gọi trước lỗi
  khớp mã gốc. Mã thấp `0x1f6` cùng lớp lỗi, **dòng/cột nguồn khác**.
  Chưa đo tình huống máy thật hết bộ nhớ.
- [Bản dùng API MT5 thật](bot-cua-toi-1/bang-chung/bien-dich/b1-virtual-native-api-02/bien-nhan.json)
  biên dịch 0 lỗi/cảnh báo, không thay lời gọi bằng macro; chỉ kiểm
  biên dịch bản này, không gọi các hàm của nó trên tài khoản.
- [Kiểm lại tập lệnh đã chạy](bot-cua-toi-1/bang-chung/kiem-bang-dung-ao/virtual-matrix-20261025-r4/coverage-audit.json):
  409/420 lệnh trong bốn thân hàm đã chụp; không có địa chỉ thừa.
  11 lệnh còn thiếu được [liệt kê nguyên](bot-cua-toi-1/bang-chung/kiem-bang-dung-ao/virtual-matrix-20261025-r4/missing-native.txt):
  sáu lệnh đệm, bốn lệnh của nhánh lỗi đọc mảng, một lệnh dừng sau hàm
  báo lỗi. Không coi số lệnh hoặc số ca là tỷ lệ hoàn thành toàn bot.

[Claude đã rà nguồn độc lập](claude-thuc-hien/virtual-stop-source-review-20261025-r1/review.md),
không thấy lỗi nguồn chắc chắn so với mô tả; có 13 mục thiếu kiểm/xác
minh ở bộ bảy bước cũ. Biên nhận chốt 15 yêu cầu thực tế Opus 5.5/max;
Ultracode được yêu cầu, chưa xác nhận từ bằng chứng chạy. Claude đang
viết thêm công cụ kiểm mối nối bằng chứng; chưa nhận xét công cụ đó đạt.

Còn thiếu: ghép hai hàm quản lý và các nơi gọi, mã lỗi MT5/tài khoản
thật, mọi khả năng cấp phát, nhánh lỗi đọc mảng chưa chạy, khởi động
lại/lưu trạng thái, toàn EA và phép chạy cặp hai bot đầy đủ. Nguồn
MQL5 hiện tại không dùng EX5 gốc để thực hiện luật khi chạy.
