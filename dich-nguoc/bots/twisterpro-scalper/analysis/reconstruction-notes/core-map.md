# Phần điều kiện đã kiểm lại ngày 21/10/2026

Bản diễn giải ban đầu đã được thay bằng nội dung dưới đây vì có chỗ nhầm khung thời gian với số thứ tự nến và nhầm ý nghĩa bộ lọc. Chỉ dùng mã và bằng chứng đã kiểm làm căn cứ.

- RVA 0xc080: chọn hướng. Bản MQL5 ở `reconstructed/TwisterFilters.mqh`, hàm `TwisterRecoveredTrend`. Trả 1 cho mua, -1 cho bán, 0 khi không đạt; khi tắt bộ lọc trả 1. Kiểm đủ kích thước bốn mảng trước khi so. Đã so 320 ca với lệnh máy gốc.
- RVA 0xba40: đọc nến đã đóng, số thứ tự1. Tham số15 là khung M15, không phải nến thứ15. Lưu mở/cao/thấp/đóng vào RVA0x225e8/0x225f0/0x225f8/0x22600.
- RVA 0xc690: kiểm hướng thân nến, biên độ theo point, tỷ lệ thân và tỷ lệ râu. Ngưỡng rất nhỏ là0.0001. Bản MQL5: `TwisterRecoveredCandle`; đã so320ca.
- RVA 0xc880: dùng thao tác6 của hàm sao dữ liệu, đã đối chứng là `CopyTickVolume`. Với cấu hình đã khởi tạo, yêu cầu3nến từ nến đã đóng1. So khối lượng nến1 với phần nguyên của khối lượng nến2 nhân0.62; khi sao thiếu3nến thì hàm gốc trả đạt. Bản MQL5: `TwisterRecoveredVolume`; đã so160ca, gồm lỗi/thiếu dữ liệu và giá trị sát ngưỡng.

Bằng chứng chung: `filter-check/twfilters_v3/comparison.json` và `api-probe-v6/copy-volume-operation-evidence.json`. Các ca này dùng đầu vào cấp sẵn trong bộ mô phỏng CPU và so với MQL5 chạy máy thử, chưa so toàn bộ hai bot.

Các hàm tìm đỉnh/đáy và đặt lệnh chưa được chuyển thành MQL5 đã kiểm. Đọc trực tiếp bản C v5 và mã máy khi làm tiếp; không dùng các suy luận từ bản nháp cũ.
