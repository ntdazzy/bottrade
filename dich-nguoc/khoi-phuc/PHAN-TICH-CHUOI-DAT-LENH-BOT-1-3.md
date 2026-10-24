# So chung hàng đợi → tạo yêu cầu → gửi

Phân tích trước khi thêm bộ kiểm: bản gốc vẫn giữ hai SHA-256 đã ghi
trong bản đồ. Đã đọc các hàm hàng đợi, tạo yêu cầu, kiểm cách khớp,
gửi, thông báo và mã lỗi; hai agent chỉ đọc đã rà cách nối.

| Điểm theo dõi | Bot 1, RVA | Bot 3, RVA |
|---|---|---|
| Bắt đầu hàng đợi | `0x2e6d0` | `0x3bb10` |
| Vào hàm tạo lệnh thật | `0x32dd0` | `0x3e580` |
| Quay về hàng đợi: mua đầu/mua lại/bán đầu/bán lại | `0x2e936/0x2eaff/0x2ef9b/0x2f17f` | `0x3bd76/0x3bf3f/0x3c3db/0x3c5bf` |
| Hàm gửi vẫn chạy | `0x950` | `0x950` |

Tại đầu hàm tạo lệnh, kiểm đủ đối số thật: mã giá ở RCX, loại ở EDX,
khối lượng/giá ở XMM2/XMM3, dừng/chốt/ghi chú/hết hạn ở ngăn xếp
+40/+48/+56/+64. Ghi lại địa chỉ quay về và RSP. Chỉ nhận là đã trả
về khi cả địa chỉ và RSP+8 khớp; không dừng ở mọi lệnh `ret`.
Không gán sẵn kết quả của hàm tạo lệnh hoặc nhảy qua thân hàm.

Bộ kiểm chỉ cấp các dịch vụ MT5 bên ngoài: thuộc tính, dừng chương
trình, gửi/gửi không chờ, định dạng, in, chờ và bộ nhớ đã giới hạn.
Kết quả cùng lỗi của gửi được cấp ở lời gọi gửi thật; thay dữ liệu
của hàng đợi chỉ sau khi hàm tạo lệnh đã trả. Các nhánh trong hàm gốc
phải tự quyết định có tới lời gọi gửi và trả đúng/sai.

Ghi trước/sau mỗi lần tạo lệnh: 35 trường yêu cầu/kết quả/kiểm, số
nhận diện, cách khớp và đủ bốn chuỗi theo UTF-16. Kiểm vùng lưu gốc
628 byte: nhánh dừng chỉ đổi mã kết quả; nhánh thường xóa 364 byte
riêng. Không so địa chỉ chuỗi hoặc byte đệm của MQL5.

Cuối mỗi ca còn so đủ 500 số của hai bảng, dữ liệu dùng chung, cờ,
bộ đếm, lỗi và toàn bộ thứ tự/đối số dịch vụ. Dùng luồng sự kiện MT5
riêng với mã 1..9; mã 10/11/12 chỉ là điểm quan sát và chuỗi đổi số.
Không trộn với mã sự kiện của bảng kết quả hàng đợi.

Mã kiểm gốc đã khớp từng phần không thay cho phép so chung này.

Đã so chung ở lượt `pipeline-20261024-r2`: **818/818 ca mỗi bot**.
Biên dịch `b1-pending-pipeline-02` và `b3-pending-pipeline-02` đều
0 lỗi, 0 cảnh báo. Chạy thêm cùng thân chương trình kiểm trong máy
đo lại quá khứ, dùng đúng bộ máy MT5 đã chụp gốc: vẫn **818/818 mỗi
bot**. Tệp kết quả của mã gốc, chương trình MQL5 và máy đo quá khứ
trùng từng byte; tệp lời gọi/định dạng cũng trùng giữa hai cách chạy.

| Bằng chứng | Bot 1 | Bot 3 |
|---|---|---|
| So mã gốc với MQL5 | [818 ca](bot-cua-toi-1/bang-chung/kiem-chuoi-dat-lenh/pipeline-20261024-r2/comparison.json) | [818 ca](bot-cua-toi-3/bang-chung/kiem-chuoi-dat-lenh/pipeline-20261024-r2/comparison.json) |
| Chạy trong máy đo quá khứ | [818 ca](doi-chung-mt5/chuoi-dat-lenh-20261024/engine-b1-r4/comparison.json) | [818 ca](doi-chung-mt5/chuoi-dat-lenh-20261024/engine-b3-r4/comparison.json) |

Đã ràng từng giá trị thuộc tính và đúng/sai khi đọc với dữ liệu ca
kiểm; không chỉ lấy điều MT5 ghi ra rồi cấp lại cho hai phía. Kiểm
cả chế độ gửi, kết quả gửi, thứ tự lần thử và mã lỗi được cấp. Trường
`accepted` đầu vào chỉ là giá trị đầu của chuỗi trả lời, không tính
thành một chế độ độc lập. Thử sửa sai sáu loại dữ liệu cấp vào đều
bị bộ kiểm từ chối ở cả hai bot.

Bộ kiểm mới giữ dấu kiểm mã nguồn, bản biên dịch, bố cục trường,
bảng hàm, bản chụp mã/dữ liệu và bằng chứng phép tính. Bản chuẩn bị
ca và bản chạy gốc có mã riêng được giữ trong `tested-sources/`.
[Kiểm chứng tổng hợp](KIEM-CHUNG-CHUOI-DAT-LENH-BOT-1-3.json).

Bản dành cho máy đo quá khứ chỉ đổi điểm vào, đường tệp đầu vào và
đường nạp tệp hỗ trợ; thân kiểm và nguồn phục hồi giữ nguyên. Lời
gửi thường/gửi không chờ vẫn được thay bằng hàm kiểm, không gửi lệnh
tới tài khoản. Hai lượt lỗi đường tệp/đường nạp khi chuẩn bị bộ kiểm
được giữ riêng, không tính là đạt.

Các ca bao gồm 374 ca hàng đợi cũ, cờ/dừng, cách khớp lần đầu/lần
hai, quyền đặt lệnh, hết hạn, mã giá rỗng/có dấu, đọc thuộc tính thất
bại, ghi thông báo và kết quả gửi. Vẫn là tập hữu hạn: chưa có bằng
chứng toàn EA/nơi giao dịch, mọi cài đặt/hiển thị/khởi động lại hoặc
lỗi cấp bộ nhớ/CPU. **Không xác nhận toàn bộ P16/P31 hoặc bot đạt 100%.**

Hai agent đã rà chỉ đọc: một kiểm cách chạy thân hàm gốc và an toàn
của bản máy đo quá khứ; một chỉ ra chỗ cần ràng dữ liệu cấp vào. Đã
sửa và kiểm lại các điểm trên. Claude được giao đánh giá độc lập
qua `pipeline-check-ultracode-20261024-r1`. Phản hồi lần đầu chỉ
thông báo đã giao năm tác tử; nhật ký phụ kết thúc bằng dòng bị
ngắt, chưa có nhận xét thực tế. Đã kiểm được Opus 5.5 `max` ở cả
phiên chính và năm tác tử, nhưng **chưa có xác nhận của Claude**.
Đã nối lại phiên bằng yêu cầu nhỏ hơn ở
`pipeline-check-ultracode-20261024-r2`, bắt buộc trả đánh giá cụ thể;
[biên nhận lần đầu](danh-gia-claude/pipeline-check-ultracode-20261024-r1/receipt.json).
