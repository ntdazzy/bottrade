# Quản lý bot 3 — kết quả kiểm từng phần 25/10/2026

Đã ghép mã Claude vào hai tệp nguồn:
Bot3ManagementPrelude.mqh và Bot3ManagementVirtual.mqh.
Nguồn này chưa phải hai hàm quản lý đầy đủ hoặc EA.

| Phần | Bằng chứng mới | Kết quả |
|---|---|---|
| Đọc/lọc vị thế, dừng/chốt đầu, ba nhóm đóng theo nến | prelude-cpu-20261025-r1 | 636/636 khớp toàn bản ghi và thứ tự gọi; 519/519 + 522/522 lệnh trong ranh giới đã chạy |
| Dời dừng ảo theo thời gian | virtual-20261025-r1, nhóm 1 | 156/156 khớp |
| Dời dừng ảo theo khoảng giá | virtual-20261025-r1, nhóm 2 | 220/220 khớp |
| Kiểm trượt giá khi dời dừng ảo | virtual-20261025-r1, nhóm 3 | 184/184 khớp |
| Biên dịch | b3-management-prelude-02, b3-management-virtual-01 | 0 lỗi, 0 cảnh báo |

Các lượt ở bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/.
Giới hạn nguồn và công thức ở hai thư mục phân tích
management-prelude-20261025-r2 và management-virtual-20261025-r1.
EX5 gốc vẫn đúng SHA-256
ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83.

## Sai khác của bộ mô phỏng đã được đo

Lượt prelude-20261025-r1 có 626/636 ca khớp. Mười ca lệch đều có
nhiều giá trị không phải số (NaN) mang mẫu bit khác nhau.

Công cụ check-nan-cpu.py chạy cùng phép tính nhỏ trên CPU Windows và
Unicorn: 363 tổ hợp, 24 khác biệt. Claude rà lại bộ tạo ca, cách đọc,
ghi và thứ tự phép tính; báo cáo ở
claude-thuc-hien/bot3-nan-review-20261025-r1/REVIEW.md.

Claude sửa bộ kiểm để tính trên CPU tại đúng tám vị trí có hai NaN.
Lượt mới kiểm lại đủ 363 mẫu CPU, dùng CPU cho 20 lần thực hiện trong
12 ca của bộ 636. Mọi lệnh còn lại vẫn qua Unicorn; không đổi byte mã gốc.
Đây không phải lần chạy toàn EX5 trên CPU. Không so cờ trạng thái
MXCSR của các phép được chuyển sang CPU; đoạn đã kiểm không đọc cờ đó.

Sau sửa bộ so, 636/636 ca khớp, gồm cả 12/12 ca nhiều NaN. Công thức
MQL5 đã giữ nguyên; chỉ sửa ghi chú đầu tệp để phản ánh phạm vi.
Các bằng chứng cũ được giữ nguyên. Chi tiết ở comparison.json và
original-run.json của prelude-cpu-20261025-r1.

## Phân công và kiểm độc lập

Đợt này giao tám việc cho tám phiên Claude Opus 5.5, tối đa năm phiên
cùng chạy. Nhật ký xác nhận 189 yêu cầu thực tế đều dùng mức max.
Ultracode được yêu cầu; chưa có bằng chứng xác nhận chạy thực tế.

Bảy phiên giao kết quả. Phiên viết bộ kiểm dừng ảo bị phía Claude chặn
với nhãn cyber, chưa giao mã. Codex trực tiếp viết bộ này theo ngoại lệ
người dùng đã duyệt. Không gửi lại phạm vi bị chặn bằng cách đổi câu hỏi.
Biên nhận đúng trạng thái: danh-gia-claude/management-parallel-20261025-r3/
và final-receipt.json của bot3-management-virtual-check-20261025-r1.
Snapshot receipt.json trước đó phân loại nhầm phản hồi lỗi thành đang chờ;
final-receipt.json ghi rõ đính chính, không sửa snapshot cũ.

Codex đã đọc lại nguồn, giữ nguyên ba thân hàm Claude khi ghép, rồi chạy
các phép so trên. Rà độc lập không thấy lỗi chức năng có cơ sở trong phạm vi này.

## Còn thiếu

- Bắt đầu nhánh dừng/chốt ảo của bot 3, các nhánh dừng thật, mức cao/thấp,
  khóa lời, bộ đếm và ghi bảng.
- Vòng ngoài, thời điểm/nơi gọi, nhiều vị thế, các đường lỗi cấp bộ nhớ.
- Ghép hàm con thật: các bộ kiểm trên chặn hàm sửa và kiểm đóng ở ranh giới.
- Cài đặt, bảng hiển thị, lưu trạng thái, khởi động lại và EA chính.
- Chạy bản gốc và bản dựng lại song song trong hai MT5 riêng khi đã có EA.

Bộ 560 chỉ dùng chỉ số mảng hợp lệ. Mỗi bộ so dùng câu trả lời dịch vụ
được cấp để kiểm thuật toán trong ranh giới. Chưa kiểm tài khoản/khớp lệnh
thật hoặc toàn bộ bot; không dùng số ca làm tỷ lệ hoàn thành toàn bot.
