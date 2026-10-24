# Chọn cách khớp lệnh — bot 1 và 3

Kết quả: nguồn MQL5 đã khớp **3.096/3.096 ca mỗi bot**, cả giá trị trả,
4 trường trạng thái và thứ tự/đối số đọc dữ liệu/thông báo. Hai bản
biên dịch `b1-filling-01`, `b3-filling-01` đều 0 lỗi, 0 cảnh báo.

Phân tích trước khi dựng nguồn: đã đọc đủ thân hàm bot 1 `0x231c0`
(C 15542–15689) và bot 3 `0x2e8f0` (C 21231–21378). Hai hàm có cùng
nhánh, khác địa chỉ biến. [Bot 1](bot-cua-toi-1/bang-chung/kiem-kieu-khop-lenh/filling-20261024-r1/comparison.json),
[bot 3](bot-cua-toi-3/bang-chung/kiem-kieu-khop-lenh/filling-20261024-r1/comparison.json).

| Nhánh theo thứ tự | Hành vi gốc | Dòng C bot 1 |
|---|---|---|
| Đọc cách thực hiện | `SymbolInfoInteger(symbol,33)`, lấy 32 bit thấp; giá trị 0/1 trả đúng ngay, không đổi trạng thái | 15562–15565 |
| Cách còn lại | Đọc cờ cho phép khớp, thuộc tính 50 | 15566 |
| Cách 2, yêu cầu chờ (hành động 5) | Trả đúng, giữ nguyên cách khớp | 15567–15569 |
| Cách 2, yêu cầu khác | Ưu tiên cờ 1 → cách 0; rồi cờ 2 → cách 1. Ghi cả lựa chọn chung và trường yêu cầu. Không có cả hai → mã 10030, trả sai | 15570–15583 |
| Cách khác, lựa chọn chung 2 | Ghi cách khớp yêu cầu bằng 2, trả đúng | 15586–15590 |
| Lựa chọn chung 0/1, yêu cầu chờ | Đọc thuộc tính 49 qua dạng có cờ thành công; khi đọc lỗi dùng cờ 0. Nếu mã giá truyền vào không có con trỏ chuỗi thì dùng mã biểu đồ. Thời hạn 0/1/2/3 thử cờ 1/2/4/8; kiểu khác in đúng thông báo. Không hợp lệ thì đổi thời hạn thành 1 | 15592–15630, 15639–15676 |
| Yêu cầu chờ, loại 2/3/4/5 | Sau bước thời hạn trên, ghi cách khớp yêu cầu bằng 2 rồi trả đúng, không cần cờ khớp tương ứng | 15631, 15678 |
| Lựa chọn chung 0/1, phần còn lại | Cần cờ khớp 1/2 tương ứng; có thì ghi cách khớp yêu cầu bằng lựa chọn chung, trả đúng; thiếu thì mã 10030, trả sai | 15633–15637, 15680–15681 |
| Lựa chọn chung khác | Mã 10011, trả sai | 15683–15685 |

Giữ nguyên những điểm dễ bỏ sót:

- Cách thực hiện ngoài 0/1/2 vẫn đi vào nhánh còn lại; không tự từ chối.
- Khi trả sớm, không tự xóa mã kết quả cũ, cách khớp hoặc thời hạn cũ.
- Kiểu khớp chung có thể đổi ở nhánh cách thực hiện 2.
- Thông báo đọc từ chuỗi gốc: `CTrade::ExpirationCheck: Unknown expiration type`.
- Hàm chỉ dùng byte thấp của giá trị trả. Hai hàm sao chép/hủy chuỗi
  gốc vẫn phải chạy trong phép so. Tên hàm dựng lại không phải tên nguồn gốc.

Phép kiểm đã chạy: 840 ca cách thực hiện/lựa chọn khớp, 1.920 ca loại
lệnh chờ/thời hạn, 96 ca mã giá/lỗi đọc và 240 ca số nguyên rộng.
Hàm gốc và hai hàm sao chép/hủy chuỗi chạy nguyên lệnh. Bộ kiểm chặn
mọi lần ghi biến chung ngoài 4 trường đã xác định; dữ liệu từ MT5
được cấp sẵn. Không gọi hàm gửi lệnh. Lỗi cấp bộ nhớ và cách nguồn
biên dịch nối trực tiếp các lời gọi MT5 còn phải kiểm trong phần ghép.
