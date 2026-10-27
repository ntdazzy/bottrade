# Nối đầu đánh giá qua bổ sung dừng/chốt vị thế

Bot1 và bot3 đều **1.172/1.172 ca khớp**, so nguyên tệp kết quả theo từng
byte, rồi đọc lại cấu trúc từng ca để kiểm đủ dữ liệu. Bốn bản dựng API/
bộ kiểm của lượt r2 đều 0 lỗi/0 cảnh báo. Đây chưa phải EA hoàn chỉnh.

Đã nối chạy liên tục phần đầu đánh giá → vòng quét bổ sung mức dừng/chốt
→ thân sửa vị thế26d20/32a90 → thân gửi950 → dọn chuỗi cuối vòng. Không
đặt lại thanh ghi/ngăn xếp giữa hai phần và không cấp sẵn giá trị trả của
hàm sửa/gửi. Đầu vào trước entry và câu trả lời dịch vụ MT5 được cung cấp.
Bot1 đi thêm505 lệnh máy khác nhau sau phần đầu; bot3 đi506; trong đó
266 lệnh thuộc hai thân sửa/gửi, theo các ca đã chọn.

So mọi đối số gọi sửa, thứ tự/đối số dịch vụ, đủ35trường công khai của
yêu cầu/kết quả/kiểm,4chuỗi UTF-16 đầy đủ và cờ NULL,5trường trạng thái
gửi. Chụp trước lời gọi sửa, trước/sau dịch vụ gửi và khi hết vòng. Có
nhiều vị thế, vé64bit, mã có dấu, loại bất thường, mất1/2mức, chữ số âm/
lớn, lỗi chọn/gửi, chương trình dừng, gửi hai cách và thay cài đặt tại
ranh giới dịch vụ. Không phát lệnh thật lên tài khoản.

Lượt r1 có **36/1.172 ca lệch mỗi bot**: phép trừ được bộ biên dịch đổi
thành đổi dấu rồi cộng, làm đổi dấu NaN. Bản r2 dùng hàm trừ giữ dấu và
phần dữ liệu của NaN như SUBSD gốc. Các nguồn r1 đã giữ riêng theo SHA
trong `failed-r1-sources/`; không sửa bằng chứng cũ hoặc nới phép so.

Giới hạn: bot3 dùng cờ người gọi0 để bỏ bước dọn lệnh chờ đứng trước;
lượt này chưa chứng minh bước đó. Chế độ ghi thông báo của hàm gửi bằng0;
các nhánh định dạng có phép so riêng, chưa nối trong lượt này. Cấp phát
thành công, dữ liệu truy vấn/chọn/gửi được cấp. Chưa chứng minh môi trường
giao dịch thật, lỗi cấp bộ nhớ, nhánh quản lý sau vòng, ngữ cảnh thanh ghi
đến đó hoặc toàn bộ cài đặt/hiển thị/EA.

[Đặc tả](SPEC.md), [mã kiểm lệnh gốc](native-evidence.json),
[bộ so](../../cong-cu/kiem-bo-sung-muc-dung-bot-1-3.py),
[kết quả bot1](../../bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/b1-eval-stops-20261027-r2/comparison.json),
[kết quả bot3](../../bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/b3-eval-stops-20261027-r2/comparison.json).
