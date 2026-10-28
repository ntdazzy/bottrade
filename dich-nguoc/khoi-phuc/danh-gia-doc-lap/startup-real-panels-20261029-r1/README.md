# Ba thân hàm bảng thật trong luồng khởi động bot 1

Đã đưa nguyên thân tạo bảng `0x8320`, cập nhật lệnh mở `0xe1b0`
và cập nhật lịch sử `0xffb0` vào phép chạy liên tục từ `0xd60` đến
`0x5658`. Các thân lịch, tìm mức giá và kiểm lệnh gần của lượt trước
vẫn chạy thật. Nguồn bot không đổi trong lượt này.

## Kết quả

- `b1-startup-real-panels-20261028-r3`: **42/42 ca khớp**, 248 giá trị,
  1.800 ô bảng, 900 ô lịch, 57.592 lời gọi và 16.417 phép số học CPU.
- Không còn lời đáp thay thân cho ba hàm bảng. 41 ca bật bảng đều
  tạo 45 đối tượng: tổng 1.845 lần tạo, 19.929 lần đặt thuộc tính số
  và 3.583 lần đặt chữ. Kiểm cả tên, nội dung và thứ tự gọi.
- 80 lần đọc tổng vị thế trong phần lệnh mở, 40 lần chọn lịch sử
  trong phần đã đóng. So giữ chung vé lệnh, tổng thắng/thua, vốn,
  khối lượng và thông tin tin tức.
- Kiểm cờ hiển thị, các chế độ rủi ro, cỡ chữ/tỷ lệ, vị thế không
  khớp mã/mã giá/loại, vé 0, tổng lời/lỗ, chọn lịch sử thất bại và
  lỗi dịch vụ biểu đồ.
- `b1-startup-real-panels-check-20261028-r2`: 0 lỗi, 0 cảnh báo.
  Codex kiểm độc lập không phát hiện lỗi trọng yếu trong phạm vi.

## Chi tiết đã sửa trong bộ kiểm

Gói tạo đối tượng gốc ghi nhãn kiểu và hai đối số nguyên bằng lệnh
32 bit tại `0x844f..0x8488`. Khi ghép liên tục, phần 32 bit cao của
ô ngăn xếp còn dữ liệu cũ. Bộ kiểm r1 đọc nhầm cả 64 bit nên báo
khác; bản hiện hành đọc đúng độ rộng gốc. Không xóa ngăn xếp giữa
các hàm để che khác biệt và không sửa mã bot.

`SetUserError` của phần thống kê lệnh mở được đo thật rồi đưa vào
trạng thái lỗi chung, tránh bị lỗi dịch vụ giả lập trước đó che mất.

## Ranh giới và giới hạn

Phép kiểm bắt đầu **sau** cổng quyền dùng. Nếu chạy chạm `0xc30`,
`0x5880`, `0x3d6c0` hoặc `0x4d260`, bộ chạy dừng lỗi ngay. Không
cấp tài khoản, cờ kiểm thử, trạng thái cho phép hay phản hồi HTTP
giả lập cho mã kiểm quyền. Cờ kiểm thử dùng ở đây chỉ kiểm nhánh
hiển thị của các hàm bảng, không quyết định quyền chạy chương trình.

Giá/lệnh, lịch, tài khoản phục vụ tính toán vốn, nơi lưu và dịch vụ
biểu đồ dùng dữ liệu thử. Không gửi lệnh giao dịch. Chưa so ảnh bảng
vẽ thật, trạng thái tại mọi lỗi, khởi tạo trước cổng, sự kiện/cài
đặt đầy đủ hoặc chạy cặp hai EA. Chưa hoàn thành bot hay ba bot.

Tên lượt giữ ngày bắt đầu 28/10; hồ sơ này lập ngày 29/10/2026.

## Chạy lại

`cong-cu/kiem-noi-bang-that-khoi-dong-bot-1.py`: `generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 riêng, giữ bằng chứng cũ.

[Kết quả tổng hợp](verification.json), [danh sách tệp](manifest.txt).
