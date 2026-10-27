# Dữ liệu chung giữa quản lý và tạo lệnh

Đã sửa để hai phần có thể dùng cùng giá, vé lệnh, bảng mức, khối lượng,
chỉ số và đếm lỗi. Chín thiết lập trùng địa chỉ cũng nhận trực tiếp cùng
giá trị, gồm mã sản phẩm, mã nhận diện, đơn vị giá, mức dừng/chốt, khoảng
cách, số nến và bước. Không chép toàn bảng tại ranh giới hai phần.

| Phép so với bản gốc | Bot1 | Bot3 |
|---|---:|---:|
| Quản lý với 16 giá trị/nhóm dữ liệu ngoài; các ô cũ cố ý đặt sai | 352/352 | 364/364 |
| Kiểm lại từ sau quản lý tới hết tạo lệnh, năm chế độ khối lượng | 296/296 | 392/392 |
| Kiểm lại toàn nhánh NFP, gồm hủy/đóng/gửi thật trong bộ kiểm | 107/107 | 107/107 |

Lượt quản lý cuối: `bN-manager-fields-20261027-r3`.
Các lượt kiểm lại: `bN-active-flow-20261027-r4`, `bN-nfp-shared-20261027-r1`.
Mười bản nguồn kiểm/cách gọi dịch vụ thật biên dịch **0 lỗi, 0 cảnh báo**.
Trong hai lượt quản lý, các thân bảng dừng, sửa/đóng/chọn cách khớp/gửi của
bản gốc chạy thật; không thay kết quả hàm con bằng số cố định.

`BotNNfpExecution.tick.bid/ask` thay cho hai ô giá riêng. Manager có giao
diện `Fields` nhận dữ liệu ngoài; giao diện cũ chỉ chuyển tiếp các trường
cũ. Bot3 nhận cả bảng mức và bước ngoài trong hàm chuẩn bị mốc. Các hàm
kết thúc dừng ảo cũng đọc hai thiết lập ngoài đúng thời điểm.

Bộ kiểm không chỉ so hai cách gọi trên cùng nguồn mới: nó chạy nguyên
thân máy gốc, so thứ tự/lời gọi MT5 và kết quả. Dữ liệu trả từ MT5, số
chuyển thành chữ và cấp phát thành công vẫn được cấp theo phạm vi đã
ghi. Lượt quản lý dùng cờ dừng=0, ghi thông báo gửi=0, chế độ khớp=2;
chưa phủ mọi lỗi cấp phát/bảng đầy. Cờ đầu vào đặc biệt bot1 được cấp
false trong lượt quản lý này, chưa chạy bộ điều phối quản lý.

**Chưa phải ghép toàn phần đánh giá hoặc EA.** Còn nối đầu đánh giá,
bổ sung dừng/chốt, hai bộ điều phối quản lý, rồi mới tới phần sau đã có.
Khởi tạo/thoát, menu/tài nguyên, thống kê lịch sử và chạy cặp toàn bot
vẫn phải kiểm riêng. Không sửa EX5 gốc, khóa dùng chương trình hoặc MT5 chính.

## Chạy lại quản lý

Chọn RUN/BUILD mới. Không ghi đè dữ liệu cũ.

1. `kiem-quan-ly-trang-thai-chung.py generate N`
2. Biên dịch `BotNPositionManagementFieldsCheck.mq5` trong MT5 riêng
   bằng `cong-cu/bien-dich.ps1`, bật `-CheckFloatingPointDividers`.
3. `kiem-quan-ly-trang-thai-chung.py prepare N RUN`
4. `kiem-quan-ly-trang-thai-chung.py mql5 N RUN --build BUILD`
5. `kiem-quan-ly-trang-thai-chung.py original N RUN`
6. `kiem-quan-ly-trang-thai-chung.py compare N RUN`

Lượt r1 bị dừng vì công cụ cũ ghi tên chương trình khởi chạy cố định,
không gọi chương trình Fields mới; chưa có kết quả kiểm đạt. Công cụ mới
đã ghi đúng tên/thư mục riêng. Lượt r2 kiểm bảy trường trạng thái, r3
kiểm thêm chín thiết lập. Các bản chụp `tested-sources` của lượt cũ và
`manager-fields-tool-r2.py.txt` giữ lại nội dung trước khi mở rộng.
