# Bản đồ nhánh quản lý bot 3 — lượt 20261025-r1

Đây là bản đồ lời gọi và ranh giới tĩnh; chưa phải nguồn EA và chưa chứng minh toàn hàm. Địa chỉ đã trừ đầu mã `0x17156250000`.

## 0x32f60 — dòng C 22943..24294
- Tổng lệnh: 3346; gọi đã map: `Bot3PositionModify` 0x32a90: 0x33630, 0x33700, 0x34035, 0x344a8, 0x3485f, 0x34ea7, 0x3535c, 0x357c0, 0x35b29, 0x35f7e, `Bot3PositionCloseGuard` 0x47d20: 0x33818, 0x339ad, 0x33b42, 0x372fe, `Bot3VirtualStopLevel` 0x47f10: 0x33de1, 0x35d8e, `Bot3TradeErrors` 0x3ee80: 0x3405c, 0x34939, 0x34a2e, 0x34ed1, 0x35383, 0x357e3, `Bot3VirtualTakeLevel` 0x482b0: 0x35db5, `Bot3VirtualStopDelayPassed` 0x484c0: 0x35e08, `Bot3VirtualStopStamp` 0x48560: 0x35f8d
- Các gọi API runtime còn phải nối bằng bảng API; không suy ra từ tên biến C.
- Không có phần nào trong bảng này được gọi là đã ghép EA.

## 0x37590 — dòng C 24295..25735
- Tổng lệnh: 3407; gọi đã map: `Bot3PositionModify` 0x32a90: 0x37c6d, 0x37d41, 0x38678, 0x389e1, 0x38d80, 0x392eb, 0x396e6, 0x39a44, 0x39db9, 0x3a209, `Bot3PositionCloseGuard` 0x47d20: 0x37e55, 0x37fdc, 0x38163, 0x3b862, `Bot3VirtualStopLevel` 0x47f10: 0x38407, 0x3a01e, `Bot3TradeErrors` 0x3ee80: 0x3869b, 0x38e63, 0x38f62, 0x39315, 0x3970d, 0x39a67, `string_helper` 0x4a0: 0x386fa, 0x38736, 0x38fc1, 0x38ffd, `string_helper` 0x5c0: 0x38ee7, 0x3939a, 0x39791, 0x39aee, `Bot3VirtualTakeLevel` 0x482b0: 0x3a045, `Bot3VirtualStopDelayPassed` 0x484c0: 0x3a094, `Bot3VirtualStopStamp` 0x48560: 0x3a218, `string_helper` 0x60: 0x3b40b, 0x3b476, 0x3b5e9, 0x3b786
- Các gọi API runtime còn phải nối bằng bảng API; không suy ra từ tên biến C.
- Không có phần nào trong bảng này được gọi là đã ghép EA.
