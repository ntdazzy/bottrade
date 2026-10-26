# Sửa phép trừ giữ nguyên số không hợp lệ và bổ sung ca kiểm

Chỉ viết bản mới `Bot3PendingSubmission.mqh`, `pending_submission_cases.py`, `SUMMARY.md` trong thư mục đề xuất này. Đọc header và Python hiện hành ở source/tests bot3, đọc TASK r2 của khối nếu cần. Không sửa nguồn chính/Git/MT5, không dùng shell hoặc tự tìm thuật toán. Opus5.5max, ultracode; cấu hình thực tế được kiểm riêng.

Kết quả chạy độc lập:308ca khớp306, còn2ca sai CHÍNH XÁC dấu NaN khi tính `base_price-product` trong biểu thức điều kiện. Khi base_price=100.005,unit=.125, BUY stop_distance=NaN0x7ff8000000000000 hoặc SELL take_distance cùngNaN: giá trị yêu cầu làNaNdương, mã mới gửiNaNâm. Các trường và sốlần/thứtựgọi còn lại khớp. Máy biên dịch có thể đổi phép trừ trong điều kiện thành đổi dấu rồi cộng. Phép trừ số thực cần giữ kết quả đã chốt bên dưới, KHÔNG đổi cách so hoặc che sai lệch trong bộ kiểm.

1. Thêm một hàm nhỏ nội bộ `double Bot3SubmissionDifference(const double left,const double right)` có thân CHÍNH XÁC:
   `if(left!=left) return left+0.0; if(right!=right) return right+0.0; return left-right;`
   Hai nhánh đầu giữNaN/bitdấu và làmNaN báo lỗi thànhNaN yên lặng theo phép cộng0; không dùng MathIsValidNumber vì nó loại cả vôcực. Không thêm union/kiếntrúc/giới hạn. Có thể xem Bot3QueueDifference hiện hành để xác nhận cùng cách làm; không cần include cả PendingQueue.
2. Trong raw_sl phía BUY thay `base_price-((settings.stop_distance+0.0)*settings.unit)` bằng `Bot3SubmissionDifference(base_price,(settings.stop_distance+0.0)*settings.unit)`.
3. Trong raw_tp phía SELL thay `base_price-settings.take_distance*settings.unit` bằng `Bot3SubmissionDifference(base_price,settings.take_distance*settings.unit)`.
4. Giữ nguyên toàn bộ phần còn lại, chữ ký public, thứ tự đọc/gọi, cách thử lại/ghi bảng, dấu0 và sốlầnDigits. Không sửa phép tính thường hoặc các header phụ thuộc.
5. Python: chép nguyên pending_submission_cases.py hiện hành. Trong cases(), SAU tất cả308ca hiện tại nhưng trước return, thêm cho MỖI buy0/1 và MỖI field stop_distance/take_distance:
   - Với bốn giá trị tạo từbits64 `0x7ff8000000000123,0xfff8000000000456,0x7ff0000000000789,0xfff0000000000abc`: c=base(buy), chỉ đổi field, add với group `nan-payload-and-subtraction`. Dùng struct.unpack từ struct.pack Q, không tính kết quả mongđợi.
   - Với distance=+inf/-inf vàunit=0.0: c=base(buy), đổi field vàunit, add với group `invalid-product-and-subtraction`.
   Tổng thêm24ca, thành332ca; giữ nguyên308idđầu. Không sửa mã encode/RESULT hoặc cấu trúc kết quả. Không thêm kết quả mongđợi/chuẩn hóaNaN vào bộkiểm.

Mã sảnphẩm và ca kiểm đều cần giữ đầy đủ nội dung để Codex so diff/biên dịch/chạy độc lập. SUMMARY nêu đúng thayđổi và chưa tự chạy. Không kết luận đã đạt từ việc đọc mã.
