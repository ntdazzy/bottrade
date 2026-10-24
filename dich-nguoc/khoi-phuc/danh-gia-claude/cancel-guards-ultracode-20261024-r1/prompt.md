Phân tích một phần nhỏ của bot MT5 do chủ dự án xác nhận sở hữu và
cho phép phục hồi nguồn. Không sửa EX5/khóa dùng, không vượt biện
pháp bảo vệ. Chỉ đọc, không shell, không MT5, không ghi tệp.

Dùng Opus 5.5, effort max; Ultracode đã bật. Lượt này đầu vào rất
nhỏ: tự hoàn tất phần so dưới đây rồi trả kết quả cụ thể trong cùng
lượt. Không kết thúc bằng thông báo đã giao việc hoặc sẽ báo sau.

Đọc đúng các tệp trong dich-nguoc/khoi-phuc/:
- PHAN-TICH-HUY-LENH-CHO-BOT-1-3.md.
- bot-cua-toi-1/phan-tich/huy-lenh-cho/cancel-20261024-r1/native-guards.txt.
- bot-cua-toi-3/phan-tich/huy-lenh-cho/cancel-20261024-r1/native-guards.txt.
Không cần đọc tệp C lớn hoặc cases.json.

Nhiệm vụ: kiểm độc lập bảng bốn điều kiện số trong tài liệu so với
57/59 lệnh máy đã trích. Chốt chính xác nhánh với số thường, ±0,
NaN, ±vô hạn; phân biệt UCOMISD+JAE/JB và CMPNLESD. Chỉ ra tài liệu
có sai gì, kèm RVA. Đặc biệt xem chọn product hay hiệu hai giá và
loại lệnh có bỏ phần 32 bit cao không. Ghi chỗ nào thiếu bằng chứng,
không suy tên trường dữ liệu giá hay khẳng định đã chạy bot.

Trả ngắn bằng tiếng Việt: lỗi thật hoặc chưa thấy lỗi trong phạm vi
đã đọc, kèm giới hạn. Không tạo mã MQL5 trong lượt này.
