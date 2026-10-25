> BẢN NHÁP CHƯA ĐƯỢC CHẤP NHẬN. Xem REVIEW.md trước khi dùng.

# Bot 1 — khối giá cao/thấp thật

## Phạm vi và bằng chứng

- Bản gốc: EX5 SHA-256 `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
- Mã bắt đầu: `0x23e5aa10000`; thân mua `0x28aed..0x28f72`, thân bán `0x2c36e..0x2c7b4` (RVA đã trừ mã bắt đầu).
- Các lệnh gọi đọc giá/điểm được giữ đúng thứ tự trong `analysis.json`. Hai thân đều đi qua các hàm đọc `SYMBOL_DIGITS`/`SYMBOL_POINT`/giá rồi mới làm tròn.

## Giao diện đã chốt

Đầu vào là phía mua/bán, mã lệnh hiện tại, đơn vị giá `u` (RVA `0x66d98`), điểm tối thiểu `point` (RVA `0x7a448`), mức dừng tối thiểu `stopMin` (RVA `0x66a70`), mức đóng băng `freezeMin` (RVA `0x67468`), giá mua `bid` (RVA `0x67758`), giá bán `ask` (RVA `0x67760`), mức dừng tạm hiện tại `candidate` (RVA `0x62580`) và các cài đặt vùng cao/thấp (RVA `0x624dc..0x624f0`). Kết quả là cờ đã thay đổi và có thể là mức dừng mới. Không tự đóng lệnh trong khối này.

## Thứ tự xử lý mua

1. Nếu số nến/phạm vi phụ `0x624e4` không dương, hoặc cờ dữ liệu phụ trong vùng cục bộ tắt, bỏ qua và đi tiếp.
2. Đọc mức cao/thấp phụ theo chỉ số khung hiện tại `0x678f4`; đọc `SYMBOL_DIGITS` rồi làm tròn từng mức theo công thức gốc:
   `round(x) = trunc((x - (x>=0 ? 0 : 1)) * scale[digits]) / scale[digits] + (x>=0 ? 0 : 1)`;
   nếu `digits>10` dùng ô 11. Đây là chuỗi lệnh `cvttsd2si → cvtsi2sd → divsd → addsd`, không được thay bằng hàm làm tròn khác.
3. Cổng khoảng cách đầu tiên giữ đúng so sánh chặt: mức tham chiếu sau khi trừ điểm phải lớn hơn `stopMin`; giá mua phải lớn hơn mức dừng cộng khoảng cách cấu hình và khoảng đệm. Nếu sai, đi tiếp khối kế.
4. Nếu cổng qua, tính mức dừng mới bằng giá mua trừ khoảng cách (nhân `u`), làm tròn, rồi gọi `Modify` tại RVA `0x26d20` với vé, mức mới và mức chốt lời hiện tại. Cờ thay đổi được bật trước khi gọi; nếu sửa lỗi thì luồng lỗi gốc được giữ nguyên.
5. Khi không sửa mức, các nhánh tùy chọn vẫn được xét theo thứ tự: vùng phụ, giới hạn khoảng cách và vùng cao/thấp. Không được gộp các nhánh thành một điều kiện ngắn hơn vì thứ tự đọc giá và số lần làm tròn là một phần hành vi.

## Thứ tự xử lý bán

Thân bán có cùng cấu trúc nhưng đổi hướng: dùng `ask`, mức cao/thấp được so theo phía bán, và mức dừng mới là `ask + khoảng_cách*u`. Mọi so sánh vẫn là so sánh chặt; nhánh `jbe` trong mã máy tương đương “không đạt thì đi tiếp”. Thân bán giữ mức neo đã chọn trong `xmm15`; giá neo bán được cất vào `xmm12` tại RVA `0x2c390`, khôi phục tại `0x2c4bb` và `0x2c796` trước khi chuyển sang khối đếm thật. Không được đặt tên tham số này là “mức đã lưu” nếu chưa truyền đúng giá trị neo đã chọn.

## NaN, làm tròn và tác dụng phụ

- So sánh số thực của mã gốc dùng `ucomisd`; nhánh “khác hoặc NaN” được viết dạng `(a != b) || NaN(a) || NaN(b)`. Không thay bằng phép so sánh C++ mặc định.
- Giá được làm tròn sau khi đọc `DIGITS`, không làm tròn trước phép nhân với `u`.
- Khối này chỉ sửa mức dừng khi đã qua đủ cổng; không tự tăng bộ đếm và không tự ghi bảng lưu. Việc ghi bảng nằm ở khối lưu bên dưới.

## Chưa chốt được

Tên người dùng chính xác của từng ô `0x624dc..0x624f0` chưa có bằng chứng chuỗi trong snapshot. Khi viết MQL5, dùng tên theo chức năng đã được xác nhận hoặc giữ tên RVA trong tài liệu; không tự gán tên dựa vào bot 3.
