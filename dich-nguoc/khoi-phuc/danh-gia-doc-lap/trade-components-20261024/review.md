# Kiểm nguồn và bộ so phần khớp/chuẩn bị lệnh

Tác tử kiểm độc lập chỉ đọc đã rà hai nguồn `Filling` và
`PendingRequest`, hai chương trình kiểm MQL5 và hai công cụ Python;
đối chiếu cả hai thân hàm gốc và bố cục 35 trường đã đo.

Kết quả: không tìm thấy lỗi đáng kể trong phạm vi đã giao. Nguồn giữ
thứ tự kiểm lần một → lập yêu cầu → kiểm loại và dừng/chốt → kiểm lần
hai → kiểm thời hạn → chuẩn bị ghi chú. Phần mới không gửi lệnh thật.
Hai bộ kết quả chính khớp 3.096 và 1.607 ca mỗi bot. Sau lượt rà này,
mình đã thêm 16 ca riêng cho `NaN` và cờ cho phép đặt dừng/chốt; cả hai bot khớp.

Giới hạn đã nêu: thuộc tính MT5 đang được cấp sẵn, chưa gây lỗi đọc
thực trong MT5; `true` chỉ là sẵn sàng gửi; không chứng minh khớp lệnh,
thử lại, toàn bộ bot hoặc lỗi cấp bộ nhớ. Đây là lượt kiểm tác tử nội
bộ; không ghi thành đánh giá của Claude. Claude đã từ chối P11/P16
trong hai lượt mới và các phản hồi đó được giữ riêng.
