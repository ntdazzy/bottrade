# Tiến độ riêng bot 3 — 25/10/2026

## Kết quả mới có bằng chứng

- Đã đọc quy tắc và quy trình trước khi sửa. SHA-256 EX5 gốc đã kiểm
  trực tiếp, khớp `ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`.
- Chốt năm hàm từ 530 lệnh máy tại
  `phan-tich/dong-vi-the/virtual-stops-20261025-r1/specification.md`.
- Đã ghép `source/MQL5/Include/bot-cua-toi-3/Bot3VirtualStops.mqh`:
  thu vé/dọn cả hai bảng, lấy/tạo dừng và chốt ảo, kiểm chờ, ghi giờ.
  Giữ nhánh NaN của chốt và thứ tự dọn dừng→chốt tại từng hàng.
- Biên dịch `b3-virtual-matrix-01`: 0 lỗi, 0 cảnh báo.
- `bang-chung/kiem-bang-dung-ao/virtual-matrix-20261025-r1/comparison.json`:
  **291/291 ca thường khớp**, gồm kết quả trả, 2.500 số double của
  hai bảng, cờ, hai vé đã báo, thông tin cài đặt, mảng vé đầy đủ và
  thứ tự/đối số lời gọi. Dữ liệu vị thế/giờ được cấp trong bộ kiểm.
- Hai ca lỗi mảng: **2/2 khớp loại lỗi và trạng thái** tại
  `.../fatal-checks/virtual-faults-20261025-r1/summary.json`.
  Kết quả thất bại đổi kích thước được cấp; chưa chứng minh hết RAM
  thực. Vị trí dòng/cột nguồn khác nhau và không tuyên bố giống nhau.
- Máy đo quá khứ riêng: **291/291 khớp** tại
  `bang-chung/kiem-bang-dung-ao-may-thu/engine-virtual-b3-r2/comparison.json`.
  Máy thử đúng SHA `5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb`,
  có báo cáo và xác nhận tài khoản demo. 263.023 lần cập nhật giá;
  đây là số lần chạy vỏ kiểm, không phải số ca mới hoặc giao dịch.
- Lượt máy thử `engine-virtual-b3-r1` chưa đạt xác nhận do thiếu báo cáo
  sau khi tự gỡ ở lần cập nhật giá đầu; giữ nguyên bằng chứng thất bại.
  Vỏ kiểm r2 chạy hết khoảng dữ liệu và tạo thư mục reports, không hạ
  điều kiện xác nhận. Nguồn năm hàm không đổi.

## Năm phiên Claude đã chạy đồng thời

Cả năm đã kết thúc, hiện **0 phiên còn chạy**. Hai phiên viết mã,
ba phiên từ chối. Không giao lại phần bị từ chối dưới tên khác.

| Phần | PID | Phiên | Kết quả |
|---|---|---|---|
| Dọn hai bảng | 17228 | `8a3eba89-5b38-46eb-b8d8-cd1d52f0f2fe` | Từ chối; Codex trực tiếp làm |
| Dừng ảo | 1392 | `7c976294-4c1b-41b1-8f66-b5d6e1328878` | Đã viết; Codex kiểm và ghép |
| Chốt ảo | 22668 | `40632b56-b5b1-4e21-aa41-5f88c650449f` | Từ chối; Codex trực tiếp làm |
| Kiểm chờ/ghi giờ | 16300 | `a145875e-1c94-42a0-8e35-5ac3fdca19fc` | Đã viết; Codex kiểm và ghép |
| Bộ kiểm | 19268 | `486468aa-0200-4c03-a8bc-11a61eee9bf1` | Từ chối; Codex trực tiếp làm |

Đã kiểm `api-request` từng phiên: `claude-opus-5-5`, effort `max`.
Đã yêu cầu ultracode; chưa xác nhận hoạt động. Bằng chứng PID/phiên,
prompt, cấu hình thực tế và mã tệp đầu ra: `claude-dispatch.json`,
`claude-results.json` cùng thư mục mô tả. Đề xuất giữ tại
`claude-thuc-hien/bot3-virtual-{clean,stop,take,time,checks}-20261025-r1/`.

## Tệp đã viết

- Nguồn: `Bot3VirtualStops.mqh`.
- Chương trình kiểm: `Bot3VirtualStopsCheck.mq5`.
- Công cụ riêng trong `tests/`: `kiem-bang-dung-ao-day-du-bot-3.py`,
  `kiem-loi-bang-dung-ao-bot-3.py`, `kiem-bang-dung-ao-may-thu-bot-3.py`.
- Mô tả năm hàm, năm prompt, biên nhận giao/nhận Claude và tiến độ này.
- Bản xuất hai hàm quản lý tại
  `phan-tich/dong-vi-the/management-20261025-r1/`: 6.753 lệnh, hai hàm
  `0x32f60`/`0x37590`; mới xuất và đang đọc, chưa có nguồn quản lý.

## Đang làm và còn thiếu

- Đọc kỹ hai hàm quản lý, chốt công thức/kiểu số/điều kiện/thứ tự rồi
  ghép các hàm sửa/đóng/gửi đã kiểm; không viết lại các hàm nền.
- Chưa có EA đầy đủ, chưa chạy cặp toàn bot, chưa so trạng thái tài
  khoản/lỗi thật, khởi động lại, tất cả cài đặt/hiển thị/tài nguyên.
  **Không có tỷ lệ hoàn thành toàn bot đáng tin cậy.**
- Phần bảng ảo chưa ghép vào quản lý và chưa kiểm vòng đời toàn EA.
- Đề xuất cập nhật bảng chung P22: bot 3 đã có nguồn/291 ca thường,
  hai ca lỗi mảng và máy đo quá khứ cùng phiên bản; giữ rõ giới hạn trên.
- Chỉ dùng `dich-nguoc/.local/mt5-bot3-thread-20261025`. Không sửa bot 1,
  công cụ/bảng chung, MT5 chính, EX5 gốc hoặc khóa/giới hạn.
- Không Git commit/push/stage/reset. Chat điều phối kiểm tập tệp và Git.

## Kết thúc lượt kiểm bảng ảo

- Kiểm lại mới nhất: nguồn hiện hành trùng bản biên dịch và bản đã kiểm;
  kết quả gốc/MQL5/máy đo quá khứ trùng nguyên byte. Biên nhận tại
  `phan-tich/dong-vi-the/virtual-stops-20261025-r1/final-verification.json`.
- Đã bỏ đúng năm tệp chờ rỗng do lượt này tạo trong đề xuất bị từ chối;
  giữ ghi chú và phản hồi Claude. Có `cleanup-receipt.json` để nối với
  mã tệp trước khi bỏ trong `claude-results.json`.
- Quản lý: đã xác nhận trực tiếp 10 chỗ gọi hàm sửa ở mỗi hàm (20 tổng),
  giữ lệnh quanh mỗi chỗ và đọc hai cặp hằng làm tròn ±0.5000001.
  Xem `management-20261025-r1/initial-findings.json`. Đây chưa phải
  mô tả đầy đủ; chưa viết nhánh quản lý khi vòng lặp/chế độ chưa chốt.

## Lượt tiếp: lời gọi MT5 thật và quản lý

- Đã thêm `Bot3VirtualStopsApiCompile.mq5`: include trực tiếp, không
  macro, input `RunApiCalls` buộc trình biên dịch đọc cả năm thân hàm.
  Chỉ biên dịch, không chạy. `b3-virtual-native-api-01`: 0 lỗi/cảnh báo.
- Đã dựng hai đoạn lấy giá lưu 100×2 trong hàm quản lý; mô tả tại
  `management-20261025-r1/anchor-specification.md`. Nhánh NaN của cờ
  khoảng cách giữ theo `jbe`; hai hằng cộng là số âm 0. Lượt
  `anchor-20261025-r1` khớp 190/190 ca mã gốc/MQL5, biên dịch
  `b3-management-anchor-02` 0 lỗi/0 cảnh báo. Đây vẫn chỉ là hai
  đoạn trong hàm quản lý, chưa phải hai hàm quản lý hoàn chỉnh.
