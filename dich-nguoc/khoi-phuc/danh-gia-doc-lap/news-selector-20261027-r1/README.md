# Kết quả phục hồi chọn tin

Mỗi bot **961/961ca khớp**, gồm946ca kiểm lại hàm số học sau sửa phép
nhân phút32bit. Nguồn gọi MT5 trực tiếp và bộ kiểm đều0lỗi/0cảnh báo.
Đã so cả nhãn, thứ tự đọc giờ và các ô bị đổi trong dịch vụ.

Đã phát hiện nguồn cũ dùng phép nhân64bit và sửa theo raw; không đổi
hành vi gốc để né tràn. Nguồn cũ được lưu riêng để tra bằng chứng.
[Đặc tả](SPEC.md), [kết quả/mã kiểm](verification.json).

Đã phân tích thêm nhánhNFPdựphòng, chốt bằng probe chuỗi `202711 1230`
và dữ liệu300ô; [phần còn phải ghép](NFP-FALLBACK-ANALYSIS.md).
Chưa có toàn evaluator hoặcEA hoàn chỉnh.
