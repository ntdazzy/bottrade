Đã viết xong toàn bộ tệp trong thư mục được giao. Tôi **chưa biên dịch, chưa chạy, chưa so với EX5**, nên chưa có ca nào được kiểm đạt. Không dùng shell, MT5, git hay tác tử phụ, không ghi ra ngoài thư mục.

## Kết luận phân tích (`analysis.md`, `semantics.json` — viết trước mã)

Chữ ký hàm được chứng minh từ chính lệnh máy của hàm, không dựa vào mã C:
- Vé nằm ở RCX, đủ 64 bit.
- `sl` và `tp` nằm ở XMM1/XMM2, là `double`, được chép nguyên bit.
- Hàm không đọc RDX, R8, R9, XMM0, XMM3 hay đối số trên ngăn xếp.
- Giá trị trả là byte thấp của hàm gửi `0x950`, hoặc 0.
- Mã C ghi sai kiểu sl/tp (là số nguyên); lệnh máy cho thấy là số thực.

Thứ tự xử lý gốc:
1. Kiểm cờ dừng (4 byte). Nếu đang dừng: in `CTrade::PositionModify`, **sau đó** mới ghi mã kết quả 10027, rồi trả 0.
2. Chọn vé. Thất bại thì trả 0 và không đổi gì.
3. Xóa toàn bộ 628 byte vùng lưu, gồm cả phần đệm riêng.
4. Ghi `action=6` và `position` **trước** khi đọc mã giá.
5. Đọc mã giá, ghi `symbol`, rồi mới đọc `magic`.
6. Ghi `sl`, `tp`, rồi gọi hàm gửi đầy đủ.

Khác với hàm đóng: không kiểm cách khớp lệnh, không ghi `deviation`, `type`, `volume`, `price`. Có 9 điểm chưa rõ (U1–U9), ví dụ: giá trị hằng `TRADE_ACTION_SLTP` trong MQL5, lệnh máy ở phía hàm gọi, hành vi MT5 thật, lỗi cấp bộ nhớ.

## Tệp đề xuất (thư mục `files/`)

- **`Bot1PositionModify.mqh` / `Bot3PositionModify.mqh`:** `bool BotNModifyPosition(state&, options&, ulong ticket, double sl, double tp)`. Dùng nguyên `BotNPendingRequestState`, `BotNTradeSendOptions`, `BotNSendTrade`.
- **`BotNPositionModifyCheck.mq5`:** giữ nguyên `BotNPipelineApi.mqh`. Chỉ giả lập các truy vấn ngoài và kết quả gửi. Chụp trạng thái trước 3 lời gọi dịch vụ và sau khi gửi, có 7 kịch bản đổi dữ liệu tại các điểm đó.
- **`kiem-sua-vi-the-bot-1-3.py`:** đủ 4 chế độ, dự kiến 1.596 ca mỗi bot.
  - Mã gốc chạy tới lệnh trả về; phải chạy đủ 196/196 lệnh.
  - Kiểm thêm phía mã gốc: thanh ghi được khôi phục, phần đệm bị xóa, không ghi ngoài vùng lưu, số lần cấp/giải phóng bộ nhớ cân bằng.
  - Kiểm mã băm ở mọi bước; số lỗi/cảnh báo biên dịch bằng null bị coi là lỗi; mã băm terminal trước/sau; không ghi đè lượt cũ.
- **`phan-tich-goi-sua-vi-the-bot-1-3.py`:** công cụ thu bằng chứng lệnh máy phía hàm gọi (U4), chỉ đọc bản chụp.
- Tài liệu sơ đồ tệp, đoạn đăng ký vào `BOT-1-3.md`, `SUMMARY.md` và `integration.json` (ghi đích đề xuất và lệnh chạy).

## Lỗi đã sửa trong lượt

Hai lỗi này trùng với `CODEX_REVIEW.md`:
- Mỗi hàm có 196 lệnh, không phải 197.
- Hàm gọi của bot 1 là `0x18aa0`, không phải `0x28aa0`. Bản đồ r1/r2 xác nhận.

Ngoài ra, công cụ phía gọi giờ lần theo cả địa chỉ hàm được nạp sẵn vào thanh ghi giữ giá trị từ trước.

## Cần chú ý khi chạy

- `prepare` sẽ dừng nếu chưa chép nguồn, script và `semantics.json` vào đúng chỗ.
- Lỗi `CAST_OR_SLTP_CONSTANT_DIFFERS` nghĩa là `TRADE_ACTION_SLTP` ≠ 6 trong MetaEditor đang dùng. Khi đó cần đo lại hằng, không sửa ca kiểm.
- Bộ chặn ghi chặt hơn khung cũ, chỉ cho ghi vùng 628 byte. Nếu nó báo lỗi thì đó là phát hiện về mã gốc, cần đọc kỹ.

Lệnh chạy cụ thể nằm trong `SUMMARY.md`. Kể cả khi so khớp đạt, vẫn chưa kiểm hàm gọi, toàn EA, cài đặt, giao diện, khởi động lại hay tài khoản thật.