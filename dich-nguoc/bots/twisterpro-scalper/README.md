# TwisterPro Scalper

**Chưa xác nhận giống bot gốc 100%.** Đã có bản MQL5 chạy máy thử tại
[source/TwisterProRecovered.mq5](source/TwisterProRecovered.mq5).
Tên 28 tham số giữ từ bản gốc; tên hàm và biến nội bộ là tên phục dựng.

## Đã kiểm

- 400/400 giá trị khởi tạo trên 10 bộ tham số: [kết quả](verification/settings-check/twsettings_v1/comparison.json).
- 800/800 ca của ba bộ lọc so với lệnh máy gốc: [kết quả](verification/filter-check/twfilters_v3/comparison.json).
- Lượt máy thử 4 ngày đầu: 31/31 dòng hoạt động có thời gian trùng nhau:
  [kết quả](verification/behavior-check/version1/comparison.json).
- Bốn bộ thử mở rộng: 533, 169, 183, 123 dòng hoạt động tương ứng đều trùng:
  [kết quả](verification/behavior-check/version2/comparison.json).
  Có chế độ 1/2, hai kiểu sàn, giới hạn lỗ và trì hoãn dời dừng.
- Bản dùng cho bốn lượt trên biên dịch 0 lỗi, 0 cảnh báo. Số trùng này chỉ
  chứng minh các lượt đã chạy, không phải mọi tình huống của bot.

## Trạng thái mã mới nhất

`source/` đã bỏ hàm `OnTester` được suy ra nhầm ở bản thử trước vì nhật ký
bản gốc không có dòng kết quả này. Sửa đổi đó **chưa được biên dịch/chạy
lại** khi người dùng yêu cầu chuyển dự án. Bản đã kiểm được giữ riêng
trong `verification/behavior-check/version2/` và `verification/builds/`.

Hiện bản nguồn chỉ cho chạy máy thử không hiển thị biểu đồ. Còn phải
hoàn thiện phần bảng hiển thị, lịch tin, nhãn lời/lỗ, các nhánh ngoài máy
thử và kiểm các lỗi. Không bật giao dịch tài khoản từ bản này.

## Tiếp tục từ đâu

1. Đọc mã hiện hành và [ghi chú đã kiểm](analysis/reconstruction-notes/core-map.md).
2. Mã trung gian mới nhất: [bản C v5](analysis/TwisterPro-Scalper-annotated-v5.c).
3. Dữ liệu mã gốc: `verification/captures/twisterdata1_09/`; có 76 vùng hàm.
4. Hoàn thiện Twister, so toàn bộ giao dịch/giao diện/phần lịch tin trước.
5. Chỉ sau đó mới làm công cụ dịch các bot còn lại.

## EA gốc

- [Bản EA 9](../../../3-so-ao-luot-nhanh/TwisterPro%20Scalper/TwisterPro%20Scalper.ex5) — mã tệp `C705E2BBBB66D18E31E2A375625DFDEF69243CB73E684AF3A846D6AB33FABE73`.

## Vị trí

- `source/`: bốn tệp MQL5 hiện hành.
- `tests/`: hai công cụ tạo/đối chiếu ca kiểm.
- `verification/`: nhật ký, báo cáo MT5, dữ liệu đã chụp, nguồn/bản biên
  dịch dùng làm bằng chứng. Không sửa nội dung bằng chứng cũ.
- `analysis/`: một bản C hiện hành, cấu hình Ghidra và ghi chú.
