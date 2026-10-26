# Kiểm nối bot 3: nạp cấu hình → chuẩn bị

Ngày 26/10/2026. Đọc `AGENTS.md` và `QUY-TRINH.md` trước khi kiểm.

## Phát hiện

`Bot3PrepareStrategy` đọc khung quản lý từ ô gốc `0x6d324` tại lệnh native
RVA `0xe759`; bộ kiểm chuẩn bị hiện hành cũng đi theo đường
`inputs.management_timeframe → state.management_timeframe`.

Bản nạp cấu hình trước đây gán `inputs.management_timeframe` từ bảng của ô
`0x6d2e4` (`5,99,99,...`) và chỉ giữ bảng `0x6d324` trong state phụ. Cách
đó sẽ sai khi ghép thật dù hai bộ kiểm rời nhau đều xanh.

## Sửa đã làm

- Thêm `inputs.native_6d2e4` làm trường riêng.
- Gán `inputs.management_timeframe` từ bảng `native_6d324`
  (`1,1,1,5,1,1,1,1,1`).
- Gán `inputs.native_6d2e4` từ bảng ô `0x6d2e4`
  (`5,1,1,2,3,5,5,20,3`).
- Bộ kiểm runtime ghi và so cả hai trường; lượt r6 đạt **2.106/2.106**,
  mã kiểm `07e41752...`.

Chưa có caller ghép thật từ nạp cấu hình sang chuẩn bị hoặc EA; vì vậy đây là
kiểm hợp đồng trường, chưa phải xác nhận toàn bot.
