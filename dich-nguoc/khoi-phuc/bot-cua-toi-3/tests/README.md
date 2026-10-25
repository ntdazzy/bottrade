# Bộ kiểm riêng bot 3

Chạy từ gốc dự án. Chỉ dùng MT5 tại
`dich-nguoc/.local/mt5-bot3-thread-20261025`; không gửi lệnh giao dịch.
Không ghi đè lượt cũ; dùng tên lượt mới nếu chạy lại.

## Bảng dừng/chốt ảo

```powershell
$test='dich-nguoc/khoi-phuc/bot-cua-toi-3/tests'
python -I -B -X utf8 "$test/kiem-bang-dung-ao-day-du-bot-3.py" prepare NEW_RUN
& 'dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1' -Bot 3 -Terminal 'dich-nguoc/.local/mt5-bot3-thread-20261025' -Run NEW_BUILD -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3VirtualStopsCheck.mq5'
python -I -B -X utf8 "$test/kiem-bang-dung-ao-day-du-bot-3.py" mql5 NEW_RUN --build NEW_BUILD
python -I -B -X utf8 "$test/kiem-bang-dung-ao-day-du-bot-3.py" original NEW_RUN
python -I -B -X utf8 "$test/kiem-bang-dung-ao-day-du-bot-3.py" compare NEW_RUN
python -I -B -X utf8 "$test/kiem-loi-bang-dung-ao-bot-3.py" NEW_RUN --build NEW_BUILD --check-run NEW_FAULT_RUN
python -I -B -X utf8 "$test/kiem-bang-dung-ao-may-thu-bot-3.py" NEW_RUN NEW_ENGINE_RUN --build NEW_BUILD
```

Đầu vào: 293 ca (291 thường, hai ca lỗi mảng), nguồn MQL5 và đúng bản
chụp mã gốc đã có SHA-256. Kết quả lưu riêng tại
`bang-chung/kiem-bang-dung-ao/` và `bang-chung/kiem-bang-dung-ao-may-thu/`.
Đầu ra so nguyên byte hai bảng, kết quả trả, cài đặt, mảng vé, thứ tự
và đối số gọi. Dịch vụ thời gian/vị thế được cấp; tác dụng đổi dài
mảng lấy thực tế từ MQL5, được ràng buộc đầu vào khi chạy mã gốc.

Nếu mã/công cụ đổi, tên lượt trùng, thiếu kết quả, dữ liệu khác hoặc
máy thử không được xác nhận thì công cụ dừng bằng lỗi. Lượt máy đo
quá khứ còn yêu cầu đúng tài khoản demo đã lưu, báo cáo và nhật ký.
Hai ca lỗi mảng so loại lỗi/trạng thái; chưa chứng minh hết RAM thật.
Đây là kiểm từng phần, không phải kiểm hai EA đầy đủ.

## Kiểm cả vòng quản lý

`check-position-management-flow.py` dùng `manager_flow_cases.py`; thứ tự:
`prepare RUN` → biên dịch Bot3PositionManagementFlowCheck.mq5 bằng
`cong-cu/bien-dich.ps1` → `mql5 RUN --build BUILD` → `original RUN`
→ `compare RUN`. Chạy MQL5 trước để đo riêng kiểu đổi số thực thành chữ.
Nguồn/công cụ/đầu vào phải giữ đúng mã kiểm tra từng lượt. Không ghi đè.
Lượt hiện hành manager-flow-claude-20261025-r1:364/364, bản dựng
b3-position-management-flow-03:0/0. Hai parent gốc chạy từ đầu tới
trả về; sáu hàm con và dịch vụ được cấp trả lời. Chưa phải hai EA.

Từ lượt manager-tables-20261025-r2, thêm `--table-children` ở mọi bước
để chạy bốn hàm bảng thật. MQL5 nhận ExecuteTableChildren=true.
Kết quả version2 dài156byte, thêm6trường con; chế độ cũ vẫn120byte.
Sửa/kiểm đóng còn được cấp trả lời. Chưa phải EA hoặc máy giao dịch thật.
