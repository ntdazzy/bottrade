# bot-cua-toi-3

Đã nối thêm bước dọn lệnh chờ giữa đầu đánh giá và bổ sung dừng/chốt:
**339/339 ca khớp**, gồm đầy đủ200ô bảng, đối số/chuỗi dịch vụ và
trạng thái yêu cầu. Các thân xóa/sửa/gửi chạy thật, câu trả lời MT5
được cấp; hai bản dựng đều0lỗi/0cảnh báo. Còn quản lý phía sau và EA đầy đủ.
[Phạm vi và bằng chứng](phan-tich/chuong-trinh-chinh/evaluation-order-cleanup-20261027-r1/README.md).

Đã nối đầu đánh giá qua vòng bổ sung dừng lỗ/chốt lời, thân sửa vị thế và
thân gửi: **1.172/1.172 ca khớp**, bốn thời điểm chụp đủ trường yêu cầu/
kết quả và chuỗi; biên dịch **0 lỗi/0 cảnh báo**. Cờ người gọi0 bỏ bước
dọn lệnh chờ trong lượt này; thân sửa/gửi chạy thật, dịch vụ được cấp.
Còn ghép bước dọn lệnh chờ, quản lý tiếp theo và toàn EA.
[Phạm vi và bằng chứng](../danh-gia-doc-lap/evaluation-stops-20261027-r1/README.md).

Đã viết tiếp từ đầu đánh giá qua giờ giao dịch, thông báo, cập nhật giá
và lịch hiện tại: **1.594/1.594 ca khớp**, gồm 31 giá trị và toàn bộ
thứ tự/đối số/chuỗi dịch vụ. Giữ đúng điều chỉnh giờ kết thúc gần nửa đêm,
nhánh không tìm thấy phiên đầu và tối đa 10 phiên. Hai bản dựng đều
**0 lỗi/0 cảnh báo**. Dữ liệu dịch vụ được cấp; chưa quét lệnh/vị thế,
chưa có EA đầy đủ. [Phạm vi và bằng chứng](phan-tich/chuong-trinh-chinh/evaluation-prelude-complete-20261027-r1/README.md).

Đã viết phần đầu đánh giá chiến lược: đọc thời gian, chọn chuỗi tên mã
và chọn nhánh tiếp theo. **432/432 ca khớp**, gồm 17 giá trị, chuỗi đầy đủ,
NULL/chuỗi rỗng và dịch vụ đổi ngày giờ báo lỗi. Biên dịch 0 lỗi/cảnh báo;
còn giao dịch và phần đánh giá phía sau; nhánh giờ giao dịch đã được so
trong lượt 1.594 ca ở trên.
[Nguồn và giới hạn](phan-tich/chuong-trinh-chinh/evaluator-prelude-20261027-r1/VERIFIED-HEAD.md).

Đã ghép nạp cấu hình → ghi chú/mã/đổi tiền → chuẩn bị: **2.106/2.106 ca khớp**,
so **132 giá trị và toàn bộ ghi chú lệnh**. Đã nối đúng cờ dùng chung
`1d6f28`, giữ hai lần đổi tiền và giá trị tham chiếu khi bật điều chỉnh khoảng cách.
Ba thân gốc chạy liên tục; biên dịch 0 lỗi/0 cảnh báo. Chưa có EA đầy đủ.
[Đặc tả và giới hạn](../danh-gia-doc-lap/strategy-setup-20261027-r1/SPEC.md).

Đã thêm phần ghi chú, mã nhận diện và đổi tiền trước khi chuẩn bị:
**1.818/1.818 ca khớp**, giữ cả nhánh đổi tiền hai lần và sửa Reference;
thêm **3/3 ca** chia 0 dừng đúng loại lỗi. Biên dịch 0 lỗi/0 cảnh báo.
Đây là đoạn đã so riêng, chưa ghép toàn bộ chương trình chính.
[Nguồn, bằng chứng và giới hạn](phan-tich/chuong-trinh-chinh/strategy-context-20261027-r1/SPEC.md).

Đã so nối nạp cấu hình với chuẩn bị dữ liệu: **2.106/2.106 ca khớp**, so
124 giá trị và đối số chỉ báo. Hai thân gốc dùng cùng bộ nhớ; tên mã/comment/
vốn vẫn được cấp, chưa nối EA chính.
[Bằng chứng và giới hạn](phan-tich/chuong-trinh-chinh/profile-preparation-20261027-r1/README.md).

Đã thêm khối nạp 9 cấu hình chạy ở trước bước chuẩn bị: **2.106/2.106 ca
khớp** mã gốc và MQL5, gồm hạt giống 32-bit, số dương/âm/NaN/vô cực,
6 điều chỉnh và kiểm không đổi các trường ngoài phạm vi; biên dịch **0 lỗi,
0 cảnh báo**. Kết quả hai bên cùng mã kiểm
`07e4175232b4be31eed89a3730243aa7032a0afe05805af854f5f34ad2c06925`.
Bộ kiểm mới tách đúng ô `0x6d2e4` khỏi `management_timeframe` tại `0x6d324`;
không còn dùng nhầm hai trường khi nối sang bước chuẩn bị.
Đây vẫn là một khối độc lập, chưa được gọi từ EA chính và chưa chứng minh
toàn bot. [Đặc tả và phép kiểm](phan-tich/chuong-trinh-chinh/profile-parameters-20261026-r1/README.md).

Mới thêm đoạn đặt lệnh sau khi đã có giá cơ sở: **332/332 ca khớp**,
biên dịch **0 lỗi/0 cảnh báo**, giữ đúng thử lại và ghi bảng. Claude
viết mã/bộ kiểm, Codex so với bản gốc. Chưa ghép toàn EA.
[Phạm vi](../PHAN-TICH-DAT-LENH-TRONG-MAIN-BOT-3.md).

Mới thêm khối chuẩn bị cài đặt chiến lược: **1.016/1.016 ca thường khớp**,
so76giá trị, biên dịch **0 lỗi/0 cảnh báo**. Còn các nhánh lỗi, dữ liệu
đầy đủ và ghép EA. [Phạm vi](../PHAN-TICH-CHUAN-BI-BOT-3.md).
Đã so thêm18/18ca chia0: khớp loại lỗi và dừng, chưa so mọi trạng thái
trước lỗi. Biên dịch với `-CheckFloatingPointDividers` để giữ cách dừng
của bản gốc;1.016ca thường vẫn khớp, chưa là EA hoàn chỉnh.


Đã kiểm cả vòng quản lý mua/bán thật/ảo: **364/364 ca khớp**,
biên dịch **0 lỗi, 0 cảnh báo**. Có nhiều vị thế, đổi chế độ giữa vòng,
lấy giá thất bại, sửa/đóng lỗi, vé64bit và bộ đếm tràn.
Bốn hàm mức dừng/chốt/chờ/ghi giờ đã chạy thân thật;
sửa và kiểm đóng vẫn được cấp trả lời;
**chưa ghép đủ EA hoặc chạy hai bot hoàn chỉnh**.
[Phạm vi mới và phần còn thiếu](../PHAN-TICH-GHEP-QUAN-LY-BOT-3.md).

Mới kiểm dời chốt lời thật mua/bán: **994/994 ca khớp**,
biên dịch **0 lỗi, 0 cảnh báo**. Claude viết hai thân hàm và bộ kiểm;
Codex đối chiếu, giữ nguyên thân rồi ghép. Hàm sửa/đóng và khối báo lỗi
được cấp trả lời; chưa phải toàn quản lý hoặc EA.
[Phạm vi mới](../PHAN-TICH-NHANH-THAT-BOT-1-3.md).

Mới thêm phần cuối nhánh ảo: **1.304/1.304 ca** cao/thấp, khóa/bộ đếm
và **296/296 ca** lưu hai bảng khớp; nhóm dời dừng thật theo thời gian
khớp **492/492 ca** phần tính/gọi sửa. Tất cả biên dịch sạch. Phần báo
lỗi và hàm sửa được cấp trả lời trong bộ 492; chưa phải toàn bot.
[Phạm vi mới](../PHAN-TICH-KET-THUC-AO-BOT-1-3.md).

Mới thêm xử lý khởi đầu mức dừng/chốt ảo và cập nhật chốt ảo:
**696/696 ca khớp** mã máy gốc/MQL5; biên dịch **0 lỗi, 0 cảnh báo**.
Các hàm con được cấp kết quả tại ranh giới gọi. Còn phần cuối nhánh
ảo, nhánh thật, vòng ngoài và EA chính; chưa chạy cặp hai bot đầy đủ.
[Phạm vi và bằng chứng](../PHAN-TICH-QUAN-LY-BOT-3-20261025.md).

Đã dựng năm hàm bảng dừng/chốt ảo: 291/291 ca thường khớp mã gốc,
MQL5 và máy đo quá khứ riêng; hai ca lỗi mảng khớp loại lỗi/trạng thái.
Biên dịch 0 lỗi/cảnh báo. So cả 2.500 số trong hai bảng, mảng vé và
thứ tự lời gọi; dữ liệu vị thế/giờ được cấp. Chưa ghép quản lý hoặc
EA đầy đủ, chưa kiểm vòng đời và lỗi tài khoản thật.
[Tiến độ, nguồn và bằng chứng](TIEN-DO-LUONG-20261025.md).

Đã dựng hàm sửa dừng lỗ/chốt lời vị thế theo vé `0x32a90`: kiểm
chương trình dừng, chọn vé, tạo yêu cầu sửa rồi gửi/thông báo.
1.596/1.596 ca khớp mã gốc/MQL5/máy đo quá khứ (83 ca dừng, 33 ca chọn
vé thất bại, 1.480 ca gửi), chạy đủ 196/196 lệnh máy; biên dịch 0 lỗi/
cảnh báo. Truy vấn/kết quả gửi được cấp. Còn 21 nơi gọi và giá trị
truyền vào, tài khoản/mã lỗi thật, cài đặt, hiển thị, khởi động lại,
lỗi cấp bộ nhớ và toàn EA; [phạm vi](../PHAN-TICH-SUA-VI-THE-BOT-1-3.md).

Đã ghép quét/chọn vị thế mua/bán qua toàn bộ phần đóng/gửi/thông báo:
lượt r3 khớp 4.600/4.600 ca mã gốc/MQL5/máy đo quá khứ (2.300 ca mỗi
chiều), gồm số 32/64 bit, chuỗi trống, trạng thái tại các lần đọc dữ
liệu và hai ca đổi dữ liệu sau lần kiểm đóng đầu. Biên dịch 0 lỗi/cảnh
báo. Còn nơi gọi, trạng thái tài khoản/mã lỗi thật, cài đặt, hiển thị,
khởi động lại, lỗi cấp bộ nhớ và toàn EA;
[phạm vi](../PHAN-TICH-CHON-VI-THE-DONG-BOT-1-3.md).

Đã dựng hai hàm kiểm điều kiện/đóng vị thế qua chọn cách khớp, gửi
và thông báo: 2.589/2.589 ca khớp mã gốc/MQL5/máy đo quá khứ, gồm
trạng thái và thứ tự đọc dữ liệu. Biên dịch 0 lỗi/cảnh báo. Còn nguồn
giá trị dùng chung, nơi gọi và toàn EA; [phạm vi](../PHAN-TICH-DONG-VI-THE-BOT-1-3.md).

Đã ghép chọn lệnh mua/bán cần hủy → hủy/gửi → dọn bảng → thông báo:
2.522/2.522 ca khớp mã gốc/MQL5/máy đo quá khứ; biên dịch 0 lỗi/cảnh
báo. Chưa ghép toàn EA hoặc kiểm tài khoản thực. [Phạm vi](../PHAN-TICH-HUY-LENH-CHO-BOT-1-3.md).

Đã dựng hủy một lệnh chờ: 964/964 ca khớp mã gốc, chương trình MQL5
và máy đo quá khứ; biên dịch 0 lỗi/cảnh báo. Phép ghép chọn lệnh mới
được nêu phía trên; còn toàn EA. [Bằng chứng](../PHAN-TICH-HUY-LENH-CHO-BOT-1-3.md).

Đã dựng dọn bảng 100 hàng và kiểm giới hạn lệnh: 215/215 ca khớp cả
chương trình MQL5 và máy đo quá khứ; biên dịch 0 lỗi/cảnh báo.
[Phạm vi và phần còn thiếu](../PHAN-TICH-QUET-LENH-BOT-1-3.md).

Đã so chung hàng đợi → tạo yêu cầu → kiểm cách khớp → gửi → thông báo:
818/818 ca khớp trong chương trình MQL5 và máy đo quá khứ. Biên dịch
0 lỗi/cảnh báo. Thuộc tính/kết quả gửi/lỗi được cấp trong bộ kiểm;
chưa có EA đầy đủ. [Bằng chứng](../PHAN-TICH-CHUOI-DAT-LENH-BOT-1-3.md).

Đã dựng hàng đợi/thử lại: 374 ca khớp trong script và máy đo quá khứ;
nội dung mã lỗi: 5.826 ca khớp. Biên dịch 0 lỗi/cảnh báo.
[Phạm vi](../PHAN-TICH-HANG-DOI-BOT-1-3.md). Phép so chung mới được
nêu phía trên; chưa có EA đầy đủ.

Đã dựng hàm gửi/thông báo: 1.201 ca khớp; ghép với tạo yêu cầu:
1.687 ca khớp. Biên dịch 0 lỗi/cảnh báo. Kết quả gửi được cấp trong
bộ kiểm; phép so riêng này chưa ghép hàng đợi. Phép ghép mới đã nêu
phía trên; nơi giao dịch thật và toàn EA vẫn chưa kiểm.
[Bằng chứng](../PHAN-TICH-GUI-LENH-BOT-1-3.md).

Đã dựng chọn cách khớp lệnh: 3.096 ca khớp; chuẩn bị yêu cầu lệnh chờ:
1.607 ca và 16 ca bổ sung khớp. Chưa gửi lệnh trong phần này.
[Bằng chứng](../PHAN-TICH-TAO-YEU-CAU-CHO-BOT-1-3.md).

Đã dựng giờ theo mùa: 4.737/4.737 ca khớp kết quả và thứ tự gọi;
biên dịch 0 lỗi/cảnh báo. [Giới hạn](../PHAN-TICH-GIO-MUA-HE-BOT-1-3.md).
Chưa có EA chính hoàn chỉnh.

Đã dựng kiểm khối lượng hợp lệ: 1.834/1.834 ca khớp, gồm 27 ca dừng vì
chia 0 chạy thật trong MT5 riêng. [Phạm vi](../PHAN-TICH-KHOI-LUONG-HOP-LE-BOT-1-3.md).

Luồng mới bắt buộc: [phân tích toàn bộ trước khi viết tiếp](../BAN-DO-TOAN-BO-BOT-1-3.md).
Bản đồ có đủ 82 hàm trong bản chụp. Đã nối 80 dòng cài đặt với vị trí
lưu và mặc định: 720/720 lần đối chiếu khớp. Đã đọc trực tiếp nhãn nhìn
thấy và bốn menu/17 lựa chọn. Còn kiểu/phạm vi, tác dụng đầy đủ và tài nguyên.
[Bảng cài đặt](../PHAN-TICH-CAI-DAT-BOT-1-3.md).

Đã dựng phần nạp vốn/tên lưu/mốc thời gian, 616/616 ca khớp mã gốc;
biên dịch 0 lỗi, 0 cảnh báo. [Menu và khởi động](../PHAN-TICH-MENU-VA-KHOI-TAO-BOT-1-3.md).

Hai đoạn chọn chiến lược khớp 7.724 ca phân tích với mã gốc, gồm đủ 512
tổ hợp bật/tắt thủ công. Nguồn `Bot3StrategySelection.mqh` khớp lại
7.724/7.724 ca; [báo cáo nguồn mới](../PHAN-TICH-CHON-CHIEN-LUOC-MQL5-BOT-1-3.md).
[Kết quả mã gốc](../PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md).

Phần vốn vừa ghép khớp 1.883/1.883 ca; kiểm ký quỹ khớp 1.141/1.141 ca.
[Bằng chứng](../PHAN-TICH-LUONG-VON-VA-KY-QUY-BOT-1-3.md).

Chưa có EA MQL5 hoàn chỉnh. Đã xuất 82 hàm từ bảng mã mới và dựng lại
hai hàm mức giá; 1.104/1.104 ca so với đoạn mã gốc trùng kết quả.

Lượt tiếp đã thêm xác nhận mức giá, lọc lệnh chờ gần và bảng tham số gốc
của 9 chiến lược: 1.096/1.096 ca mới và 54/54 giá trị khớp.
Xem [kết quả phần mới](../PHAN-TICH-VAO-LENH-BOT-1-3.md).

Lượt mới nhất thêm tính khoảng cách/thời hạn và bảng cơ bản của từng
chiến lược: 1.034/1.034 ca, 9/9 bảng khớp; biên dịch 0 lỗi, 0 cảnh báo.
Xem [phạm vi và nguồn mới](../PHAN-TICH-DIEU-CHINH-BOT-1-3.md).

Đã ghép thêm đổi tiền tệ với tính khối lượng: 966/966 ca khớp; phần đổi
tiền riêng khớp 1.530/1.530 ca. [Bằng chứng và giới hạn](../PHAN-TICH-KHOI-LUONG-BOT-1-3.md).

Đã dựng cập nhật vốn sau khi rút tiền: 915/915 ca khớp; ghi/đọc qua hai
lần mở MT5 riêng đạt. [Kết quả mới](../PHAN-TICH-RUT-TIEN-BOT-1-3.md).

- [Phân tích và giới hạn](../PHAN-TICH-BOT-1-3.md)
- [Nguồn mức giá](source/MQL5/Include/bot-cua-toi-3/Bot3PriceLevels.mqh)
- [Bộ kiểm MQL5](source/MQL5/Scripts/bot-cua-toi-3/Bot3PriceLevelsCheck.mq5)
- [Mã C trung gian hiện hành](phan-tich/luot-20261023-data/ma-trung-gian-day-du.c)
- [Danh sách hàm](phan-tich/luot-20261023-data/danh-sach-ham.json)
- [Kết quả kiểm](bang-chung/kiem-muc-gia/gia-20261023-r1/comparison.json)

Hàm `0xc30` được xuất riêng sau lần quá thời gian và ghép vào bản C đầy
đủ. Tệp gốc, phần bổ sung và mã kiểm tra đều được giữ trong thư mục phân tích.

Đã dựng hàm sắp xếp hai mảng lịch sử `Bot3HistorySort.mqh` tại `0x557f0`.
Lượt `history-sort-20261025-r1` khớp 512/512 ca thường với mã gốc,
biên dịch 0 lỗi/0 cảnh báo. Ca lỗi, nơi gọi, phần tổng hợp lịch sử,
khởi động lại và toàn EA chưa kiểm.

Đã ghép phần đầu quản lý vị thế và ba nhánh dời dừng ảo do Claude viết.
Phần đầu khớp 636/636 ca sau đối chứng phép tính NaN trên CPU; ba nhánh
khớp 560/560 ca, biên dịch 0 lỗi/0 cảnh báo. Đây là kiểm từng phần,
hàm sửa/kiểm đóng còn được chặn ở ranh giới, chưa có EA hoàn chỉnh.
[Bằng chứng và giới hạn](../PHAN-TICH-QUAN-LY-BOT-3-20261025.md).
