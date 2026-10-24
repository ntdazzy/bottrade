# Đối chiếu nhận xét Claude

Đã xác minh lỗi số đối số: nhánh opcode 2 từng chỉ so
`actual == expected[:count]`, nên một đối số trùng đầu có thể qua dù
bản ghi MQL5 có hai đối số. Đây là lỗi của bộ kiểm, không phải bằng
chứng nguồn phục hồi khác bot gốc.

Đã sửa kiểm số lượng trước khi so đủ đối số. Ca cấp 0/1/3 đối số với
bản ghi đòi 2 đều bị từ chối; 2 đối số đúng vẫn qua. Sau sửa, lượt
`pipeline-20261024-r3` vẫn khớp 818/818 mỗi bot; cùng thân trong máy
đo quá khứ `engine-bN-r5` cũng khớp. Nguồn bot không thay đổi.

Đã bổ sung mã băm của `kiem-khoi-luong-bot-1-3.py`, các phần Python/
DLL của Unicorn/capstone dùng trong vùng chạy riêng. Đã kiểm công cụ
chuẩn bị/chạy gốc cùng mã băm và sinh lại đầu vào trùng từng byte.
Các lượt cũ được giữ, kèm bản nguồn công cụ lúc đã chạy.

Những trường lấy từ chuỗi định dạng đo trong MQL5 không được gọi là
bằng chứng định dạng độc lập của thuật toán. Số bản ghi chỉ là kiểm
đủ luồng; dữ liệu chưa thể bị ghi được bảo vệ bằng vùng cấm ghi.
Lượt gửi thứ nhất xóa vùng 0x5a chỉ chứng minh trực tiếp lần đầu;
không suy từ đó mọi lần cấp bộ nhớ/lỗi CPU đều được kiểm.

Claude tự đọc phần hẹp này, không chạy MT5/tính lại mã băm. Các
khẳng định về 818 ca và hiện trạng nguồn do agent chính tự kiểm lại.
Chưa có bằng chứng toàn EA, nơi giao dịch, mọi cài đặt hoặc hiển thị.
