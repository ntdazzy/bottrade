# Tiến độ luồng bot 1 — 25/10/2026

Chỉ ghi bot 1; không Git, không sửa bằng chứng cũ hoặc công cụ chung.
Đã đọc AGENTS.md, QUY-TRINH.md và PHAN-CONG-HAI-LUONG-20261025.md.
EX5 gốc được đọc lại và băm đúng `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.

| Phần | Bằng chứng / kết quả | Đang làm / còn thiếu |
|---|---|---|
| Hai hàm quản lý | `management-20261025-r1/analysis.json`, 2.749 + 2.872 lệnh | Đang phân tích lại trực tiếp; chưa có hai hàm MQL5 đầy đủ |
| Đọc vị thế, mức ban đầu, đóng theo nến | `bang-chung/kiem-quan-ly-vi-the/prelude-20261025-r2/comparison.json`: 340/340 ca khớp mã gốc/MQL5; bản `b1-management-prelude-02` 0 lỗi/cảnh báo | Chỉ phần đầu tới ranh giới `0x27c51/0x2b667`; hàm sửa/đóng được cấp kết quả, chưa ghép cả hàm quản lý |
| Bảng 100 vé/giá mở | `bang-chung/kiem-quan-ly-vi-the/cache-20261025-r1/comparison.json`: 266/266 ca khớp toàn 200 số, mức, mốc, cờ và giá trị sao chép; bản `b1-management-cache-01` 0 lỗi/cảnh báo | Nguồn `Bot1ManagementPrelude.mqh`; cần ghép với các nhánh sau |
| Các chế độ dời dừng, giá trị trả | Đã xác nhận nhánh chế độ 2 đi thẳng dừng ảo; cuối nhánh thật đọc lại chế độ | Đang tách lấy mức/kiểm chờ/sửa/ghi giờ ở đầu nhánh ảo; chưa đủ mô tả toàn hai hàm |
| Điều kiện giao dịch và điều phối | Phụ thuộc hai hàm quản lý và phân tích riêng | Chưa có EA đầy đủ; chưa chạy hai bot song song |

## Phân công Claude

Hai hàm `0x271f0/0x2abc0` đã bị Claude từ chối ở
`../danh-gia-claude/bot1-position-management-20261025-r1/receipt.json`:
4/4 yêu cầu thực tế Opus 5.5/max; Ultracode chưa xác nhận chạy.
Codex trực tiếp làm theo ngoại lệ đã được người dùng duyệt. Không gửi lại
phạm vi này dưới tên mới. Chưa mở phiên Claude mới trong luồng này.

Yêu cầu mới về nhiều Claude: chỉ giao các phần thật sự độc lập đã chốt đủ
mô tả và chưa bị từ chối; tối đa 5 phần ban đầu, không tạo việc cho đủ số.
Hiện chưa có phần bổ sung thỏa điều kiện đó. Bộ kiểm bảng dừng ảo do chat
điều phối phụ trách; luồng này không sửa.

## Tệp mới có chủ đích

- `source/MQL5/Include/bot-cua-toi-1/Bot1ManagementPrelude.mqh`.
- `source/MQL5/Scripts/bot-cua-toi-1/Bot1ManagementPreludeCheck.mq5`,
  `Bot1ManagementCacheCheck.mq5`.
- `tests/check-management-prelude.py`, `tests/check-management-cache.py`.
- `phan-tich/dong-vi-the/management-prelude-20261025-r1/contract.md`,
  `cache-contract.md`.
- Bằng chứng mới riêng `bang-chung/kiem-quan-ly-vi-the/` và biên dịch
  `b1-management-prelude-01/02`, `b1-management-cache-01`.
  Lượt biên dịch đầu lỗi tên trùng từ dành riêng MQL5, đã sửa tên;
  giữ nguyên nhật ký và nguồn đã lưu trước sửa. Lượt r1 chỉ có mã gốc,
  lượt r2 mới có phép so đạt.
- Máy thử riêng `.local/mt5-bot1-thread-20261025`; chỉ chạy chương trình
  kiểm với giao dịch và DLL tắt. Không dùng máy thử chung hoặc MT5 chính.
