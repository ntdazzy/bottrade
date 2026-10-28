# Ba vị trí lưu đã đọc từ mã gốc — bot 2

Đọc tĩnh hàm `0xe250..0x100a2`, nền `0x253f2620000`; không chạy
mã gốc, MT5 hoặc quyền dùng. Mã kiểm tra thân hàm:
`3f8d827aa47cba3eef205a8961027ce4b3103f718191a34e6701a4df5065e175`.

| Vị trí | Bằng chứng đọc | Vai trò quan sát được | Tên cài đặt ứng viên |
|---|---|---|---|
| `0x68528` | `0xe2ff`: so 1 byte với 0 | Bật/tắt cập nhật bảng | `ShowInfoPanel` |
| `0x68530` | `0xe330`: đọc 1 byte; so với 0 khi thông tin chế độ trả 1 | Cho cập nhật bảng trong chế độ kiểm thử | `UpdateInfoTesting` |
| `0x68600` | `0xe3da`: đọc 4 byte; cộng 1..8 tại `0xe3dc..0xe423` | Mã nhận diện cơ sở dùng lọc lệnh của 8 chiến lược | `ST1_MagicNumber` |

RVA được tính bằng địa chỉ tuyệt đối trừ toàn bộ địa chỉ nền,
không lấy đuôi địa chỉ. Ví dụ `0x253f2688600-0x253f2620000=0x68600`.

**Chưa xác nhận trực tiếp tên cài đặt với vị trí lưu** bằng cách
đổi từng đầu vào của bản gốc. Vì vậy tên trong bảng chỉ là ứng viên
theo chức năng; không sửa `type/default/rva` của danh sách 70 dòng.
Độ rộng đọc cũng chưa chứng minh kiểu khai báo MQL5.

`InfoPanelSizeAdjust` và `SetFontSize` còn chưa rõ. Không gán tên
chỉ vì gặp số 1.0 hoặc 0 trong vùng dữ liệu.

[Lệnh máy và địa chỉ đầy đủ](observed-uses.json),
[danh sách cài đặt](../inputs-bot2-20261029-r1/README.md).
