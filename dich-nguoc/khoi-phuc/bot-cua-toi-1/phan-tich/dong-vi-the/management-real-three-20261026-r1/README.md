# Ba khối thật bot1 đã đối chiếu

Lượt `b1-real-three-20261026-r3`:1.246/1.246ca khớp từng bit:
dời dừng theo khoảng giá536,kiểm trượt giá400,ghi bảng310.
`b1-real-three-check-20261026-r1`:0lỗi/0cảnhbáo.
Hai kết quả cùngSHA
`601bc09bc66ed6d1cd5b1e538fea6ce371a5c9acdb67695ad125bd55045240e6`.

Mã ba chức năng, bộ ca và chương trình MQL5 doClaude viết.
Codex kiểm, ghép và viết bộ chạy lệnh máy gốc để so độc lập.
Phiên tạo bộca ghi nhầm thư mục bị giới hạn quyền chặn; Claude trả
đủ mã trong câu đáp. Codex lưu nguyên phần mã, có biên nhận riêng.
Không mở rộng quyền hoặc gửi lại dưới một yêu cầu khác.

So giá dừng/chốt, cờ thay đổi, dữ liệu sau dịch vụ, bộ đếm lỗi,
thứ tự/đối số lời gọi và toàn1.500ô bảng qua băm. Thân chuyển mã lỗi,
ghép chuỗi và in thật chạy; sửa/kiểm đóng được cấp trả lời.
Dữ liệu dịch vụ/thay đổi dữ liệu do dịch vụ gây ra đều được cấp.
Các trường mà một khối không đọc chỉ chứng minh trạng thái bộ kiểm,
không chứng minh thuật toán của khối khác. Chi tiết trongphépsoJSON.

Giữ nguyên hai lượt lỗi:
- r1: bộ đo Codex lấy nhầm gốc địa chỉ cho bước đổi số thành chữ,
  do mãid4 được dùng cho cả truy vấn vị thế và truy vấn mã giá.
- r2: bộ đo đọc nhầm ô chuỗi6a43c thành bộ đếm lỗi. Thân gốc tại
  336d9/33731 và công cụ kiểm lỗi cũ xác nhận bộ đếm là6744c.
  Chỉ128ca có gọi báo lỗi bị lệch; không sửa thuật toán sản phẩm.

Các nguồn đã thử và bằng chứng cũ được giữ riêng. Rà độc lập cấu
trúc bộ kiểm không thấy lỗi mới sau khi chốt XMM10=0 và giới hạn.
Chưa có vòng quản lý bot1 hoặc EA đầy đủ.

Kế tiếp: so ba phần cao/thấp,khóa lời,bộ đếm vừa ghép nguồn;
biên dịchAPI `b1-real-six-api-20261026-r1`0/0 mới kiểm kiểu/đối số,
không phải đã chạy. Sau đó ghép và so hai thân quản lý từ đầu đến cuối.

Cách lặp từ gốc dự án, dùngRUNmới: `check-management-real-blocks.py`
lần lượt `prepare RUN`, `mql5 RUN --build b1-real-three-check-20261026-r1`,
`original RUN`, `compare RUN`. MT5 riêng phải có bản dựng cùng nguồn.
Không ghi đè bằng chứng cũ; nguồn phải khớp mã kiểm trong biên nhận.
