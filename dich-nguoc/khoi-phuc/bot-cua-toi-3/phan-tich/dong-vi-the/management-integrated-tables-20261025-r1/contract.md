# Nối các hàm bảng ảo vào vòng quản lý

Dùng lại bộ kiểm vòng quản lý hiện có, bật --table-children ở mọi bước.
MQL5 nhận input ExecuteTableChildren=true. Đầu vào vẫn version1,84byte/ca.
StopLevel47f10,TakeLevel482b0,Delay484c0,Stamp48560 phải chạy thân gốc và
hàm MQL5 thật, không cấp kết quả của chúng. Ghi sự kiện đầu hàm20/21/23
như trước;Delay dùng26,ticket,seconds,0,0 vì kết quả không còn được cấp.
Thời gian và truy vấn MT5 vẫn được cấp đúng bản mô tả đầu vào cũ.
Modify32a90 và TryClose47d20 vẫn nhận trả lời; chưa so toàn EA.

Bổ sung sự kiện Print7 đối số:24băm4chuỗi theo thứ tự;25slots,positions,
ticket. Kiểm kiểu từng đối số theo bộ kiểm bảng ảo đã có, không tự định
nghĩa thông báo mới. Lượt này bảng có tối đa3vé; không chứng minh mọi
nhánh đầy bảng/cấp phát. Phần bảng có bộ kiểm291ca riêng trước đó.

Kết quả khi bật cóversion2,156byte/ca:120byte cũ rồiqqiiQi gồm
reported_ticket,reported_take_ticket,open_tickets_size,series_flag,
băm toàn mảng vé vật lý vàselected_index. Mảng vé khởi tạo rỗng;
hai vé đã cảnh báo bằng0 nhưZeroMemory của MQL5. Mọi trạng thái con
được so sau khi cả vòng cha trả về. Không sửa thân thuật toán để kiểm.

Khóa mã của5hàm bảng từvirtual-stops-20261025-r1/analysis.json, gồm cả
DropClosed20bc0. Ghi riêng lệnh nào thực sự chạy và số lần đầu hàm,
không lấy danh sách đã nạp làm bằng chứng tất cả nhánh đã chạy.
Giữ nguyên các lượt cũ, không ghi đè dữ liệu hoặc EX5 gốc.
