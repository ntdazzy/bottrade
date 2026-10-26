# Rà soát đặc tả chuẩn bị khoảng cách

`preparation-distance-spec.md` là **NHÁP CHƯA CHẤP NHẬN**.

Lý do: các tên toàn cục trong mã C như `DAT_24fc868e1a8`,
`_DAT_24fc8695834` và `_DAT_24fc867cd90` đã bị ghi thành địa chỉ ngắn
không kiểm tra. Vùng mã chính có base `0x24fc8630000`, nên mọi địa chỉ phải
được tính bằng `int(địa_chỉ_tuyệt_đối) - int(base)` từ đúng tên đầy đủ. Chưa
được giao Claude viết mã theo bản nháp này.

Việc sửa bắt buộc: dùng công cụ `extract-prep-bindings.py` trong cùng thư mục
để lấy toàn bộ tên toàn cục xuất hiện trong thân hàm RVA `0x7550`, tính RVA
tự động, rồi đối chiếu lại kiểu `double/int/long/uchar` và thứ tự gọi SDK.
