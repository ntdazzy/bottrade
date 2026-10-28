# Nối chọn tần suất với ngữ cảnh khởi động bot 3

`Bot3StartupSelectionContext.mqh` nối đoạn `0x3840..0x3ce6` với
ngữ cảnh đã phục hồi, chạy tới `0x4580`. Địa chỉ tính từ nền
`0x17156250000`; mã kiểm tra toàn đoạn khởi tạo lưu trong biên nhận.

| Phần | Bằng chứng gốc | Cách phục hồi/kiểm | Kết quả/còn thiếu |
|---|---|---|---|
| Giờ đã chỉnh | `0x3840..0x388f`; giờ đông/hè `0x1d7038/0x1d7040` | Nhân 32 bit với 3.600, trừ theo 64 bit; kiểm biên và dữ liệu đổi sau lời gọi | Khớp; cấp kết quả hàm mùa hè |
| Chọn tự động | Tần suất `0x1d6f90`, rủi ro `0x1d7130`, mức lỗ `0x1d7140` | Giữ thứ tự đọc vốn/đổi tiền/mức lỗ; so ngưỡng 810/560/330 | Khớp; cấp kết quả hàm đổi tiền |
| Cờ và hệ số | `0x6d220..0x6d228`, `0x76fa8` | Giữ byte gốc, đủ chế độ và hai bộ hệ số | Khớp; có 9 byte khác nhau để phát hiện đảo vị trí |
| Nối ngữ cảnh | `0x3ce6..0x4580` | Dùng chung trạng thái, so trước mỗi lời gọi và khi kết thúc | Khớp; chưa chạy chuẩn bị đầu |

## Kết quả

- Lượt `b3-startup-selection-context-20261029-r2`: **233/233 ca
  khớp từng byte**, 47 trường và 5 chuỗi.
- 700 lần gọi phần chọn, 2 lần in; 1.049 phép nhân và 117 phép chia
  chạy trên CPU thật. Gồm sát ngưỡng, số không hợp lệ/vô cực, tràn
  số nguyên, cờ 2/255, chế độ thủ công và đọc lại dữ liệu sau hàm con.
- Nguồn kiểm `b3-startup-selection-context-check-20261029-r1` và
  bộ ghép `b3-all-headers-api-20261029-r2`: 0 lỗi, 0 cảnh báo;
  bộ ghép chứa đủ 108 tệp `.mqh`.
- Kiểm độc lập không thấy lỗi trọng yếu trong nguồn. Đã bổ sung
  các ca còn thiếu về thứ tự 9 byte, cờ khác 0 và mức lỗ không hợp lệ.

## Giới hạn

Nguồn dùng các hàm mùa hè/đổi tiền thật. Phép kiểm nối hiện cấp kết
quả hai hàm này để kiểm chính xác phần gọi và trạng thái chung;
chưa xác nhận thân hai hàm trong lần chạy nối. Vùng trả chuỗi được
nạp trước, cấp phát thành công được cấp. Không chạy phần quyền dùng;
gặp các điểm `0xc30`, `0x61a0`, `0x485e0`, `0x55bc0` sẽ dừng.
Chưa có EA hoàn chỉnh hoặc phép so hai bot hoàn chỉnh.

## Chạy lại

`cong-cu/kiem-noi-chon-khoi-dong-bot-3.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Dùng tên lượt
mới và MT5 bot 3 riêng. Giữ nguyên bằng chứng cũ và EX5 gốc.

[Kết quả tổng hợp](verification.json), [danh sách tệp](../startup-selection-context-bot3-20261029-r1-manifest.txt).
