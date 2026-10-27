# Dữ liệu dùng chung trước khi nối toàn phần đánh giá

Mục tiêu là dùng đúng một nơi giữ dữ liệu ở các phần đã phục hồi, không
chép mảng/trạng thái tại ranh giới quản lý → bảng → tin → tạo lệnh.
Chưa đổi thuật toán hay thứ tự lời gọi.

## Bằng chứng gốc

| Giá trị | B1 | B3 |
|---|---|---|
| MqlTick / bid / ask | 67750 / 67758 / 67760 | 74790 / 74798 / 747a0 |
| Bảng quản lý 100×2, cũng là kết quả lệnh chờ | 65dd0 | 72e10 |
| Giá trị bước đã chép, cũng là active_step | 673e8 | 74428 |
| Mảng khối lượng / chỉ số hiện hành | 66a80 / 678f4 | 73ac0 / 74934 |
| Vé cuối / đếm lỗi | 677f8 / 6744c | 74838 / 7448c |

Địa chỉ đọc/ghi được kiểm trong `check-position-management-flow.py`,
`check-management-cache.py`, `check-management-anchor.py` và các phép so
vòng tạo lệnh. Bảng nguồn có ghi địa chỉ ở từng trường/hàm. Trước sửa đã
kiểm lại SHA-256 hai EX5: a3b0de...e922 và ee063d...fb83, trùng bản chuẩn.

## Nối giá

Trong `BotNNfpExecution`, thay hai double `reference_a,reference_b` bằng
`MqlTick tick`. Giữ `threshold_a,gap` riêng. Đổi đúng các cách truy cập
`execution.reference_a/b` và `Execution.reference_a/b` sang `.tick.bid/ask`
ở nguồn hiện hành, nguồn kiểm và ba bộ tạo còn ghi những tên này.
Không đổi tên tham số độc lập `reference_a/b` của các hàm đóng lệnh;
không sửa mã trung gian, tài liệu hoặc bằng chứng cũ.
Nhờ đó bước lấy giá đầu đánh giá và quản lý có thể nhận `execution.tick`
thật; tin và tạo lệnh đọc đúng các ô bid/ask của cùng đối tượng.

## Nối trạng thái quản lý

Thêm giao diện `Fields` cho `BotNManageOnePosition` và `BotNManagePositions`.
Thân thuật toán chỉ có một bản. Các đối số thêm ở cuối:

`double &copied_step,double &cache[][2],const double &volumes[],
const uint &strategy_index,uint &error_count,ulong &last_ticket,MqlTick &tick`.

Bot1 thay trong thân: `shared.copied_step/cache/volumes/strategy_index/
error_count/last_ticket/tick` bằng đúng các đối số trên. Các trường riêng
table/open_tickets/current_stop/counter vẫn thuộc shared. Hai giao diện cũ
giữ nguyên và chỉ chuyển chính các thành viên cũ của shared vào Fields.
Fields quản lý vòng phải gọi Fields quản lý từng vị thế với cùng tham chiếu.

Bot3 dùng `shared.anchor.step_reference` cho copied_step và `shared.anchor.rows`
cho cache. Thêm `Bot3PrepareManagementAnchorFields` nhận hai đối số thêm
`double &rows[][2],double &step_reference`; thân không chép mảng và không
đọc/ghi state.rows/state.step_reference. Giao diện cũ chỉ chuyển hai trường
cũ vào hàm Fields. Các giá trị ticket/level/gap_passed/reference còn lại
vẫn thuộc anchor. ManagerFields gọi AnchorFields bằng cache/copied_step.

## Nối các cấu hình trùng địa chỉ

Nối thêm vào cuối hai giao diện ManagerFields chín tham chiếu const:
`const string &symbol,const int &magic,const double &unit,
const double &stop_distance,const double &take_distance,const double &gap,
const double &freeze,const int &high_low_enabled,const double &step_reference`.
Thân Fields thay đúng các cách đọc settings.symbol/magic/unit/stop_distance/
take_distance/gap/freeze/finish.high_low_enabled/finish.step_reference bằng
đối số tương ứng. Wrapper cũ chuyển chính các trường cũ vào, không chép.
Manager vòng chuyển cả chín tham chiếu sang Manager từng vị thế.

| Cấu hình dùng chung | B1 | B3 |
|---|---|---|
| symbol / magic / unit | 67918 / 6246c / 66d98 | 74958 / 6d564 / 73dd8 |
| stop_distance / take_distance | 62498 / 624a0 | 6d588 / 6d590 |
| gap / freeze | 66a70 / 67468 | 73ab0 / 744a8 |
| high_low_enabled / step_reference | 624e4 / 62510 | 6d5d4 / 6d600 |

Căn cứ: DOUBLE_CFG/INT_CFG trong hai `check-position-management-flow.py`,
CFG/LOOP trong phép kiểm tạo mức giá/vòng lệnh. Hai trường cuối cũng là
level-cache older và loop-settings step_reference; không để bản chụp cũ.

Trong phần kết thúc dừng ảo, thêm biến thể Fields và giữ wrapper cũ cho:
- `AdvanceVirtualHighLow`: thêm cuối `const int &high_low_enabled`, thay
  settings.high_low_enabled trong thân bằng đối số này.
- `AdvanceVirtualBreakEvenCounter`: thêm cuối `const double &step_reference`,
  thay settings.step_reference trong thân bằng đối số này.
- `FinishVirtualManagement`: thêm cuối cả hai theo thứ tự trên, gọi hai
  biến thể Fields phía trên với đúng tham chiếu. ManagerOneFields gọi
  FinishVirtualManagementFields với hai đối số ngoài này.

Các tham số, thứ tự, điều kiện, công thức, hiệu ứng và vòng lặp khác giữ
nguyên. Không thay kiểu khớp lệnh. Hai bộ điều phối quản lý sẽ tiếp tục từ
các giao diện này; chưa gọi đây là đã ghép toàn evaluator hoặc EA.

## Kiểm

Biên dịch nguồn gọi thật và bộ kiểm manager. Chạy lại quản lý theo cả hai
giao diện, so native với các thân bảng/giao dịch khi bộ kiểm hỗ trợ.
Chạy lại đoạn ghép sau quản lý (năm chế độ khối lượng) để chứng minh cách
giữ giá mới không đổi lời gọi, kết quả hoặc trạng thái đã được kiểm.
Không dùng việc biên dịch được thay cho đối chiếu vận hành.
