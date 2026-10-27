# Thống kê lịch sử và bảng lãi/lỗ cuối hàm

## Phạm vi đã kiểm

Đã dựng hai hàm `Bot1UpdateClosedStatusPanel` và
`Bot3UpdateClosedStatusPanel` từ thân native của EX5 gốc. Bản kiểm gọi
trực tiếp hàm MQL5 trong MT5 riêng, ghi toàn bộ lời gọi theo thứ tự, rồi
cho thân native đọc đúng các trả lời đó.

| Bot | Thân native | Ca đối chiếu | Lời gọi dịch vụ native | Kết quả |
|---|---:|---:|---:|---:|
| Bot 1 | `0xffb0..0x10f5f` | 222 | 4.855 | 222/222 |
| Bot 3 | `0x16e80..0x17ef2` | 243 | 6.078 | 243/243 |

Nguồn gốc được khóa bằng SHA-256 trong từng `baseline.json` và biên nhận
biên dịch. EX5 gốc không bị sửa.

## Thuật toán đã chốt bằng chứng

- Bot 1 gọi thông tin kiểm thử hai lần theo đúng nhánh; bot 3 gọi một lần.
  Khi cờ hiển thị tắt thì trả về đúng nhánh, kể cả nhánh kiểm thử giữ lại
  số thắng/thua cũ của bot 1.
- Lịch sử được chọn từ thời điểm 0 tới `0x7fffffff`; duyệt vé từ cuối về
  đầu, không loại vé 0 và không khử trùng.
- Mỗi bot chỉ nhận các nhóm mã chiến lược của chính nó: bot 1 có 8 nhóm,
  bot 3 có 15 nhóm. Mã được tính theo hạt giống cộng 1 đến số nhóm, giữ
  phép chuyển số nguyên như native.
- Mỗi vé được lọc theo mã sản phẩm chính xác. Lãi, phí và hoán đổi được
  đọc lại theo đúng số lần native đọc; tổng dùng phép cộng `double`. Vé có
  lãi ròng dương tăng thắng, âm tăng thua, bằng 0 không tăng bộ đếm.
- Sau vòng lặp, ghi thua rồi ghi thắng vào vùng trạng thái; nhãn là
  `Total profits/losses so far: X/Y` và `Total P/L so far: ...`. Số tiền dùng
  `Round(total,2)` rồi định dạng hai chữ số; tên đối tượng và thuộc tính
  giữ nguyên native.

## Giới hạn còn lại

Bằng chứng này xác nhận toàn thân thống kê lịch sử, thứ tự dịch vụ và cách
định dạng chữ. Nó chưa chứng minh ảnh biểu đồ, khởi tạo/thoát, menu, tài
nguyên hay toàn bộ EA chạy như một cặp hoàn chỉnh.

## Chạy lại

```text
python cong-cu/kiem-bang-thong-tin-lich-su-bot-1-3.py prepare N RUN
python cong-cu/kiem-bang-thong-tin-lich-su-bot-1-3.py mql5 N RUN --build BUILD
python cong-cu/kiem-bang-thong-tin-lich-su-bot-1-3.py original N RUN
python cong-cu/kiem-bang-thong-tin-lich-su-bot-1-3.py compare N RUN
```

Mỗi lượt phải dùng tên mới; công cụ từ chối khi nguồn, biên nhận hoặc dữ
liệu đầu vào đã thay đổi.
