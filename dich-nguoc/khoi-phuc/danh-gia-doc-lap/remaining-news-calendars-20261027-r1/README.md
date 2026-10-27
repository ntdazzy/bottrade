# Kết quả phục hồi lịch lãi suất/CPI

Mỗi bot **490/490ca thường và16/16ca lỗi mảng khớp**. Nguồn gọiMT5
trực tiếp và bộ kiểm đều0lỗi/0cảnh báo. Có kiểm mảng xuôi/ngược,
mã sự kiện dự phòng, mã lỗi5401và thông báo.

Giữ đúng khác biệt: lãi suất có nhánh5401, CPIkhông có. CPIcần đủ
điều kiện nhóm tên và loại dữ liệu; không lấyORcả4từ khóa.
Mã lỗi/dữ liệu lịch được cấp trong bộ kiểm, không gọi là đã đo lỗi
mạng thật. Còn ghép điều phối IR/CPI với luồng tin và toànEA.
[Đặc tả](SPEC.md), [kết quả](verification.json).
