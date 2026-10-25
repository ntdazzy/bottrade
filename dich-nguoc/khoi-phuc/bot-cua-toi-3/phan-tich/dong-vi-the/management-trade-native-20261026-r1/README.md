# So vòng quản lý cùng các hàm sửa và đóng

`manager-all-children-20261026-r2`:364/364ca khớp31trường;
`b3-management-trade-check-20261026-r1`:0lỗi/0cảnhbáo.
Hai thân quản lý chạy từ đầu đến trả về, cùng bốn hàm bảng và năm
hàm sửa/kiểm đóng/đóng/chọn kiểu khớp/gửi. Hai kết quả cùngSHA:
`5e4b26e789d16fca0a27f0922f093aecedb279d4465acd3b186ac55861fedb5d`.

Đã chạy6038vị trí lệnh thân cha,119vị trí hàm bảng,605vị trí hàm
giao dịch. Số lần gọi sửa488,kiểmđóng98,đóng88,chọnkhớp88,gửi524.
So giá trị, thứ tự lời gọi, toàn bảng qua băm, trạng thái chọn vị thế,
vé đã báo,35trường dữ liệu yêu cầu/kết quả/kiểm và cấu hình gửi.
Chỉ quan sát đầu các hàm con; không cấp kết quả thay thân hàm.

Dịch vụ MT5, trả lời gửi lệnh, cấp phát thành công và một số đổi số
thành chữ được cấp riêng. Bộca dùng cờdừng0,inchi tiết0,kiểugiao dịch2,
cờkhớp1. Chưa kiểm mọi cấu hình, lỗi hết bộ nhớ hoặc đầy bảng.
Đây chưa phải EA đầy đủ hoặc phép chạy cặp hai EA trên dữ liệu giá.

Lượt r1 dừng tại ca28 vì bộ kiểm dùng sai số của giá bán hỏi từ
MT5. Bộ đo API cũ xác nhận ASK=4; Codex sửa bộ kiểm đọc số này và
khóa mã bằng chứng. Không sửa thuật toán sản phẩm để làm khớp.
Giữ nguyên r1 và nguồn đã thử.

Hai chế độ cũ đã kiểm lại với mã bộ chạy mới:
`manager-native-legacy-20261026-r1`364/364,cùngSHAfc6a...f31b;
`manager-native-tables-20261026-r1`364/364,cùngSHA5701...4478.
Rà độc lập bộ nối mới không thấy lỗi cần sửa.

Cách lặp từ gốc dự án: dùng tênRUN mới ở cả bốn bước
`check-position-management-flow.py prepare RUN --trade-children`,
`mql5 RUN --trade-children --build b3-management-trade-check-20261026-r1`,
`original RUN --trade-children`, `compare RUN --trade-children`.
Trước bước MQL5 phải có bản dựng cùng nguồn trong MT5 kiểm thử riêng.
Không ghi đè lượt cũ. `contract.md` và `native-bindings.json` ghi
đầy đủ giao diện/bằng chứng. Kế tiếp cần nối bước chuẩn bị và nơi gọi.
