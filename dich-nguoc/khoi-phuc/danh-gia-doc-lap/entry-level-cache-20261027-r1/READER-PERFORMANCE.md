# Đọc băng lớn không chép lặp

Ca79 có13.670.524byte. Chạy riêng bộ đọc cũ:11,047giây; dùng vùng đọc
chung:0,611giây. Cả hai chạy tới đúng điểm ra, đọc đủ cùng số byte,
không khác đối số/trạng thái. Khi hai bot chạy cùng lúc, bộ cũ có thể
chạm giới hạn15giây trong một ca vì chép lặp phần băng còn lại.

R4 giữ giới hạn chạy, mọi phép so và kiểm cận theo số byte còn lại.
Chỉ thay cách lưu vùng đọc bằngmemoryview, vẫn chép phần dữ liệu nhỏ
khi thực sự dùng; không chép lại hàngMBtrước từng dịch vụ. Đo trong
reader-performance.json. Nguồn bot/bộ ghi/các ca không thay đổi.
