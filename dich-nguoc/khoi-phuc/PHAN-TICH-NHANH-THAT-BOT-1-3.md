# Nhánh quản lý mức dừng/chốt thật — ngày 25/10/2026

Đã có thêm hai kết quả kiểm từng phần. Chưa có EA chính hoàn chỉnh,
chưa chạy cặp hai bot đầy đủ và chưa có phần trăm toàn bot đủ cơ sở.

| Phần | Nguồn | Kết quả hiện hành |
|---|---|---|
| Bot 1: dừng lỗ theo thời gian, mua/bán | Bot1ManagementRealTimed.mqh | b1-real-timed-20261025-r10: **492/492 khớp từng bit**; b1-real-timed-check-01 biên dịch0lỗi/0cảnhbáo |
| Bot 3: dời chốt lời thật, mua/bán | Bot3ManagementRealTake.mqh | real-take-20261025-r1: **994/994 khớp từng bit**; b3-real-take-check-01 biên dịch0/0 |
| Bot 1: dùng khai báo API thật | Bot1ManagementRealApiCompile.mq5 | b1-real-api-check-01 biên dịch0/0; chỉ biên dịch, không chạy |
| Bot 3: thời gian, khoảng giá, chốt thật, trượt giá, cao/thấp và hàm bao cuối ảo | Bot3ManagementRealApiCompile.mq5 | b3-management-real-api-04 biên dịch0/0; chỉ biên dịch, không chạy |

## Bằng chứng

- Bot1: [xác nhận](bot-cua-toi-1/phan-tich/dong-vi-the/management-real-timed-20261025-r1/final-verification.json),
  [phép so](bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/b1-real-timed-20261025-r10/comparison.json).
  239 vị trí lệnh máy đã chạy; hai kết quả cùng SHA
  a18e1f3ee7e684fb9806cdd037d122d0df9af52a7c9e7f1b5c7fbe30ca2defdb.
- Bot3: [xác nhận](bot-cua-toi-3/phan-tich/dong-vi-the/management-real-take-20261025-r1/final-verification.json),
  [phép so](bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/real-take-20261025-r1/comparison.json).
  370 vị trí lệnh máy đã chạy; hai kết quả cùng SHA
  9fa9199d9c59814b51021358c8baa836e0349e0515329cff61313b0705785c83.
- Mỗi lượt giữ nguồn đã kiểm, mã kiểm tra, dữ liệu đầu vào, bản dựng,
  thứ tự/đối số lời gọi và kết quả; bảng so ghi rõ phạm vi.

## Điều đã giữ và giới hạn

- Thời gian cộng tràn64bit có dấu, vé64bit, làm tròn theo từng lần hỏi,
  âm0/NaN, cập nhật giá/cài đặt sau dịch vụ và thời điểm ghi mức mới.
- Giữ mức đã gán ngay cả khi cổng cuối không đạt; không tự sửa hành vi này.
- Bot3 giữ BID ở nhánh bán, ngoặc point+TP, cờ có sẵn, nhân0với khối
  lượng, nhánh khối lượng tối thiểu và thứ tự sửa→báo lỗi→đặt cờ.
- Sửa lệnh và khối tạo/in báo lỗi được cấp trả lời tại ranh giới.
  Bot3 còn chặn hàm kiểm đóng: vé lấy từ lời gọi gốc; các đối số đóng
  khác được kiểm chuyển tiếp ở MQL5 với dữ liệu được cấp, chưa chạy
  hàm đóng gốc trong bộ này. Không gọi đây là giao dịch hoặc toàn quản lý.
- Hai NaN dùng mẫu đo CPU Windows khi cần, các lệnh khác chạy trong
  Unicorn; không phải chạy toàn bộ bot gốc trực tiếp trên CPU/MT5.

Claude viết nguyên hai thân chốt lời và hai tệp bộ kiểm bot3 từ mô tả
chức năng do Codex chốt. Codex phân tích gốc, kiểm độc lập và ghép.
Bot1 theo ngoại lệ đã được duyệt: Codex chuyển tên từ hai thân thời gian
Claude đã viết sau khi tự so công thức và thứ tự của bot1. Không giao lại
phạm vi đã bị từ chối dưới tên khác.

Bộ kiểm bot1 lượt r8 bị gọi trùng một điểm chặn, tạo285 ca lệch; Codex
sửa đúng bộ kiểm, giữ tệp lỗi. r9 khớp492; sau rà độc lập bổ sung đủ mã
kiểm tra phụ thuộc, r10 vẫn khớp492. Không sửa thuật toán để làm xanh bộ kiểm.

## Còn thiếu

Các nhánh thật còn lại và ghép toàn chuỗi quản lý; điều phối/vào lệnh,
toàn bộ cài đặt, bảng hiển thị, lưu/khôi phục trạng thái, lỗi và chạy
song song hai EA đầy đủ. Nhóm khoảng giá mới có bằng chứng biên dịch.
Claude đã giao thêm điều chỉnh trượt giá/cao-thấp; đã rà và biên dịch sạch, chưa so hành vi nên chưa tính là đạt.

Công cụ đọc đúng vị trí gốc và quy tắc chạy lại ở [danh mục](cong-cu/README.md).

Đợt mới [6/6 phiên giao mã](danh-gia-claude/real-management-20261025-r2/acceptance.json),
82 yêu cầu thực tế đều Opus5.5/max; Ultracode chưa có bằng chứng xác nhận riêng.
Cả sáu phiên đã kết thúc. Nhận xét/biên dịch không thay phép so gốc/MQL5.
