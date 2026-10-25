# Sửa mô tả bước đóng sớm

Bước5 củaTASK.md ghi nhầm `SymbolInfoDouble(symbol,SYMBOL_VOLUME)`.
Lời gọi đúng là `PositionGetDouble(POSITION_VOLUME)`, bỏ kết quả.
Thứ tự phải là `SymbolInfoTick` → `PositionGetDouble(POSITION_VOLUME)`
→ đọc `shared.last_ticket` → `Bot1TryClosePosition` → trảtrue.

Codex xác nhận lại bằng mã gốc: functions.c dòng306..310 (mua),
1416..1420 (bán), dịch vụPositionGetDouble id3. Không có truy vấn
SymbolInfoDouble ở bước này. Đây là lỗi trong mô tả Codex, không
phải thay đổi hành vi sản phẩm.

Giữ nguyênTASK ban đầu và câu giao đã lưu để truy vết; bản ghép phải
áp dụng sửa này. Chưa có phép so toàn vòng tại thời điểm ghi sửa.
