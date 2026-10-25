# Sáu phần quản lý dừng lỗ thật bot1

`b1-real-six-20261026-r1`:2.290/2.290ca khớp từng bit;
`b1-real-six-check-20261026-r1`:0lỗi/0cảnhbáo.
Mỗi chiều đã so: khoảng giá,kiểm trượt giá,cao/thấp,khóa lời,bộ đếm
và ghi bảng. Sốca theo phần536/400/352/334/358/310.
Hai kết quả cùngSHA:
`e9a2c51bda55a2ee7e9726f83ff00a6e20383e1c9cab9667811e6f9856f8c331`.

Claude viết ba header mới và mở rộng chương trình MQL5/bộca từ
mô tả Codex chốt. Codex nối và rà bộ chạy gốc, biên dịch, chạy và so.
Phiên mở rộng11yêu cầu thật xác nhậnOpus5.5max; Ultracodeđược yêu
cầu nhưng chưa có bằng chứng cấu hình thực tế. Rà độc lập ba header
và phần mở rộng bộ chạy không thấy lỗi cần sửa.

Đã so lại1.246ca cũ theo mãca gốc vì sốthứtự mới thay đổi:
đầu vào giữ nguyên, bản ghi gốc/MQL5 giữ nguyên ngoài sốthứtựca.
Bộ chạy mở rộng cũng chạy riêng1.246ca cũ trước khi ghép bộMQL5mới;
kết quả vẫn cùngSHA601bc...40e6.

Thân báo lỗi/chuỗi chạy thật. Sửa/kiểm đóng được cấp trả lời;
các truy vấnMT5, cấp phát thành công và đổi số nguyên thành chữ
được cấp. Các trường chưa được một khối đọc chỉ là dữ liệu kiểm,
không chứng minh luật ở khối khác. Phạm vi chi tiết trongcomparison.json.

Chưa có vòng quản lý hoặc EA bot1 đầy đủ. Kế tiếp là ghép vòng,
so thứ tự gọi, nhiều vị thế, đổi chế độ và mọi nhánh thoát.
Không lấy2.290ca làm tỷ lệ hoàn thành toàn bot.

Cách lặp: dùngRUNmới với `check-management-real-blocks.py` lần lượt
`prepare RUN`, `mql5 RUN --build b1-real-six-check-20261026-r1`,
`original RUN`, `compare RUN`. MT5riêng phải có bản dựng cùng nguồn;
không ghi đè bằng chứng cũ.
