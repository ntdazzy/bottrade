> BẢN NHÁP CHƯA ĐƯỢC CHẤP NHẬN. Xem REVIEW.md trước khi dùng.

# Bot 1 — bộ đếm thật và lưu mức dừng

## Bằng chứng và vị trí

- Bộ đếm mua: RVA `0x293da..0x2964e`.
- Bộ đếm bán: RVA `0x2cb18..0x2cd92`.
- Lưu mức dừng mua: RVA `0x2964e..0x2988b`.
- Lưu mức dừng bán: RVA `0x2cd92..0x2cfcb`.
- Cả hai thân đều gọi sửa vị thế tại `0x26d20`; đây là bộ đếm thật, không phải bộ đếm của nhánh ảo.

## Biến đã xác định từ bước chuẩn bị

`counterEnabled` = RVA `0x62508`; `counterGate` = `0x62510`; `counterLimit` = `0x62518`; `counterStep` = `0x62520`; `counterValue` (trạng thái dùng chung) = `0x663f0`; `candidate` = `0x62580`; `unit` = `0x66d98`; `point` = `0x7a448`; `stopMin` = `0x66a70`; `freezeMin` = `0x67468`; giá mua/bán = `0x67758/0x67760`. Việc gán tên này dựa trên mã khởi tạo trong `ma-trung-gian.c` và các lệnh đọc/ghi tương ứng.

## Bộ đếm mua

1. Chỉ vào khối khi cờ thay đổi của các khối trước đang tắt. Nếu `counterEnabled == 1`, tăng `counterValue` đúng một lần.
2. Cổng giá: `bid > candidate + counterStep*u + stopMin` và `bid < upperBound - freezeMin`.
3. Cổng phụ: nếu `counterGate == 0` và không phải NaN thì bỏ qua điều kiện phụ; nếu khác 0, yêu cầu `previousReference + u*previousGate < bid`. Sau đó yêu cầu `counterLimit <= counterValue`.
4. Khi đủ cổng, đọc `DIGITS`, tính `newStop = round(candidate + counterStep*u)`. Nếu `newStop < candidate`, đặt `counterValue=0`, gọi `Modify(ticket,newStop,tp)` và đi tới phần kết thúc. Nếu chưa đủ, giữ bộ đếm và đi tiếp.

## Bộ đếm bán

1. Tăng `counterValue` cùng vị trí tương ứng, dùng `ask` và hướng ngược lại.
2. Cổng tương ứng là `ask < candidate - counterStep*u - stopMin`, `ask > lowerBound + freezeMin`, cùng điều kiện `counterLimit <= counterValue`.
3. Tính `newStop = round(candidate - counterStep*u)`; khi mức mới hợp lệ thì đặt bộ đếm về 0 và gọi `Modify`. Vị trí giá neo bán phải là giá đã cất ở `xmm12`, được khôi phục vào `xmm15` trước khi tính.

## Khối lưu

1. Ghi `candidate` vào ô trạng thái dùng chung tại RVA `0x62580` sau khi tất cả nhánh đã chọn xong. Nếu hướng mua, chỉ ghi khi candidate nhỏ hơn giá mua; hướng bán chỉ ghi khi candidate lớn hơn giá bán.
2. Đọc lại giá tham chiếu chuẩn hóa bằng cùng chuỗi `DIGITS` và công thức cắt số nguyên của gốc. Nếu giá mới khác giá trước, hoặc một trong hai là NaN, và cờ bảng lưu `0x66410 == 1`, quét bảng bắt đầu tại RVA `0x64470` theo bước 0x18 byte.
3. Mỗi dòng so khóa kép (giá trị nhận dạng ở ô đầu) bằng `ucomisd`; khi khớp, ghi mức dừng vào ô kế tiếp (độ lệch +8 byte). Không tạo dòng mới trong khối này nếu mã gốc không tìm thấy khóa.
4. Nếu chế độ quản lý bằng `0x6241c == 2`, quay lại nhánh thời gian/ảo theo đúng địa chỉ nhảy gốc; không tự trả về sớm ở khối lưu.

## Lỗi, làm tròn và đầu ra

- Mọi phép tính mức mới đều hỏi `SYMBOL_DIGITS` ngay trước chuỗi làm tròn; giữ nguyên xử lý giá âm và NaN.
- Lời gọi sửa trả lỗi không xóa cờ đã thay đổi; bộ đếm đã đặt về 0 trước lời gọi thì vẫn là 0.
- Khối lưu không đóng lệnh. Đóng lệnh chỉ xuất hiện ở các lời gọi khác đã được ghi trong bản đồ nhánh.

## Chưa đủ bằng chứng

Ý nghĩa giao diện của `upperBound/lowerBound`, `previousReference` và cờ bảng được xác định ở mức địa chỉ và phép so, nhưng chưa có chuỗi đầu vào chắc chắn. Không được suy ra tên cài đặt từ bot 3. Cần bộ ca chạy gốc để kiểm từng nhánh sát ngưỡng, NaN, bộ đếm chưa đủ/đủ và khóa không tìm thấy.
