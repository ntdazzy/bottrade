# Sửa đầu vào bộ kiểm gốc

R1 dừng ở ca662, lệnh native RVA0x775 đọc con trỏ cũ trong ô trả chuỗi
của dịch vụ (B1 0x6a43c, B3 0x1d6e3c). Đây là ô tạm của môi trường,
không phải công thức hay bảng chiến lược. Con trỏ trong bản chụp trỏ
đến vùng nhớ không nằm trong bộ dữ liệu đã nạp.

Bộ kiểm hàm lỗi đã công bố `kiem-chuoi-loi-bot-1-3.py` khởi tạo đúng
ô này rỗng ở đầu ca trước khi gọi thân gốc. R2 áp dụng cùng đầu vào
cho ô tạm ở đầu cả đoạn tin, trước mọi hàm con; không đặt lại giữa
các phần và không thay mã gốc. Nguồn MQL5/bộ ghi/các ca giữ nguyên.
R1 và chẩn đoán được giữ để kiểm lại nguyên nhân.
