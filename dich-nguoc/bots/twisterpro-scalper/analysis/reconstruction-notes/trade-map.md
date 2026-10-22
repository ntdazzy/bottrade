# Phần giao dịch chưa hoàn thành

Các mô tả thuật toán trong bản nháp trước chưa được kiểm đủ và đã được rút bỏ để tránh dùng nhầm. Chưa có phần MQL5 gửi/sửa/xóa lệnh đã được đối chiếu với bot gốc.

Nguồn để tiếp tục: `decompiled/TwisterPro-Scalper-annotated-v5.c`, mã máy trong `captures/twisterdata1_09`, bảng tên enum trong `enum-probe-v1/enum-values.json`.

Các điểm cần đọc tiếp:

- RVA0x8970: luồng xử lý giá.
- RVA0xadc0: duyệt/xử lý lệnh chờ.
- RVA0x16270 và0x169f0: các đường tính/giới hạn khối lượng, được gọi từ đường đặt lệnh.
- RVA0xca60 và0xd280: hai đường đặt lệnh chờ.
- RVA0xdd50,0xe3c0,0xe830: xử lý sau giao dịch và các lần thử cập nhật tiếp.
- RVA0x18150: kiểm giá dừng/chốt trước sửa.

Cần đối chiếu từng phép tính và kiểu tham số bằng mã máy; đặc biệt không gọi tham số giá là khối lượng, không nhầm `SYMBOL_TRADE_STOPS_LEVEL=31` với `SYMBOL_TRADE_FREEZE_LEVEL=32`. Tên chức năng trên chỉ mô tả hướng đọc, chưa phải tên hàm tác giả.
