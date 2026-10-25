# Tóm tắt rà nguồn bảng dừng ảo bot 1

Đã nhận và làm phần rà nguồn này. Chỉ ghi `review.md` và tệp này; không
sửa nguồn, bằng chứng hay tài liệu chung. Không chạy lệnh, MT5, git
hay tác tử khác.

## Kết quả

- Không thấy lỗi nguồn chắc chắn trong `Bot1VirtualStops.mqh` so với
  hợp đồng `analysis.md`: byte cho phép, vé/chữ số có dấu, thứ tự gọi
  ngoài, khớp hàng đầu, bỏ qua vé 0/âm/NaN, biên thời gian chờ và bảy
  đối số thông báo đều khớp chữ hợp đồng.
- Bốn điểm còn chưa xác minh vì hợp đồng chưa nói rõ hoặc phụ thuộc
  trình biên dịch: đọc lại byte sau lời gọi ngoài (F5), `-0.0`/NaN ở cột
  vé (F6), đổi kiểu/tràn của dấu giờ (F7), mảng đảo chỉ số (F8).
- Thiếu kiểm quan trọng nhất (mức Trung bình):
  - F1: bước 1 là lần lấy mức đã lưu, nên công thức hướng 2 chưa chạy.
  - F2: mức 99.0 là số nguyên, nên số chữ số và phép làm tròn chưa
    được phân biệt.
  - F3: không có vị thế nào, nên vòng thu vé và vòng so vé chưa chạy.
  - F4: nhánh bảng đầy/thông báo chưa chạy.
  - F9: nguồn chưa được biên dịch với API MT5 thật, chỉ qua macro.
- Công cụ so (mức Thấp, F10–F12): `compare` không so băm kết quả đã ghi
  với tệp, không đọc lại tệp trạng thái, `comparison.json` thiếu danh
  tính và độ bao phủ. Băm terminal trước/sau không bắt buộc bằng nhau.
  Số `executed` chưa giao với danh sách lệnh.
- 7/7 và 204/420 lệnh chỉ là chuỗi khởi đầu; không phải độ bao phủ đầy đủ.

Mỗi phát hiện trong `review.md` có dòng nguồn, lý do và phép kiểm tiếp
để phân biệt.

## Ghi chú trung thực

- Ngoài danh sách, đã mở một phần hai mô-đun Python mà công cụ so nhập
  vào; không dùng chúng làm căn cứ cho phát hiện nào.
- Môi trường báo mô hình `claude-opus-5-5`; mức `max`/Ultracode không
  hiển thị cho Claude, cần lấy từ nhật ký yêu cầu.
- Không xác nhận P22, bảng dừng ảo hoặc toàn bot đạt; không có tỷ lệ
  hoàn thành.
