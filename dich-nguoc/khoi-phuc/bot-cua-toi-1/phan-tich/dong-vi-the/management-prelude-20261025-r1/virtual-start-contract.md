# Đầu nhánh dừng ảo: lấy mức, đóng, sửa và ghi giờ

Mô tả trước nguồn; không thay thế phần dời dừng còn lại.
Mua `0x2988b..0x29a67`, bán `0x2cfcb..0x2d1b6`.

1. Gọi hàm lấy/tạo mức ảo `0x3d200`: hướng 1 mua/2 bán, giá mở,
   khoảng dừng `0x62498`, vé long đã đi qua chuyển đổi double.
   Giữ kết quả ban đầu riêng và ghi vào double dùng chung `0x62580`.
2. Mua khi giá bán <= mức ban đầu; bán khi mức ban đầu <= giá mua:
   đọc giá gần nhất lại (bỏ giá trị đúng/sai), gọi hàm đóng `0x3d010`
   với vé địa phương; thoát khỏi quản lý vị thế này. NaN không thỏa.
   Không đọc lại vé dùng chung cho nhánh này.
3. Nếu chưa đóng, gọi `0x3d5a0` kiểm chờ. Sai thì đi đến ranh giới
   tiếp theo, không hỏi số chữ số/điểm và không ghi giờ.
4. Đúng thì hỏi số chữ số và làm tròn mức dùng chung hiện tại. Sau đó
   hỏi điểm giá qua `SymbolInfoDouble(SYMBOL_POINT=16)`.
5. Mua cần dừng hiện tại + điểm < mức làm tròn; bán cần mức làm tròn
   < dừng hiện tại − điểm. Phải giữ dấu <, không đổi thành <=.
6. Khi đạt: hỏi lại số chữ số, đọc lại mức dùng chung và làm tròn;
   cập nhật dừng địa phương; gọi `0x26d20` sửa dừng/chốt rồi gọi
   `0x3d640` ghi giờ. **Vẫn ghi giờ khi hàm sửa trả false**; không
   thêm điều kiện thành công. Giữ đúng thứ tự lời gọi và lần đọc lại.

Khi ghép, dùng bốn hàm bảng ảo hiện có; không chép lại hoặc sửa nguồn
do chat điều phối đang kiểm. Phép so riêng sẽ cấp kết quả các hàm con
đã kiểm để đo chính nhánh mới, ghi rõ giới hạn. Không gọi đây là toàn
bộ nhánh ảo hoặc toàn bộ hai hàm quản lý.

Lưu ý phép đo: thanh ghi XMM8 tại cuối đoạn đã bị dùng làm số tạm
`dừng + điểm` (mua) hoặc `dừng − điểm` (bán). Không dùng thanh ghi này
làm mức dừng cuối. Đo mức dừng đã truyền vào lời gọi sửa, hoặc mức
ban đầu nếu không có lời gọi; đồng thời so đầy đủ thứ tự/đối số lời
gọi. Lượt `virtual-start-20261025-r1` lỗi bộ đọc ở đây (100/364 ca),
không phải bằng chứng nguồn sai. Giữ nguyên lượt lỗi, chạy r2 sau sửa.
