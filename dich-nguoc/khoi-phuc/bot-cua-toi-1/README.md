Đã ghép `Bot1NewsFilterPipeline.mqh`: NFP → lãi suất → CPI → chọn lịch,
chung trạng thái và hủy/đóng/gửi. **133/133 tình huống khớp**,
so **10.243 lần gọi dịch vụ** và trạng thái trước mỗi lần/cuối đoạn.
Nguồn trực tiếp/bộ kiểm biên dịch 0 lỗi/0 cảnh báo. Chỉ phần tin;
chưa là EA đầy đủ. [Phạm vi](../danh-gia-doc-lap/news-pipeline-20261027-r1/SPEC.md).

Đã dựng `Bot1ReleaseCalendars.mqh` lấy lịch lãi suất/CPI theo đúng
điều kiện gốc: **490/490ca thường +16/16ca lỗi mảng khớp** mỗi bot,
đủ mảng xuôi/ngược, mã dự phòng, lỗi5401và thông báo. Hai bản biên dịch0/0.
Còn ghép người gọi IR/CPI vào luồng tin; NFPđã có nguồn ghép riêng.
[Phạm vi](../danh-gia-doc-lap/remaining-news-calendars-20261027-r1/SPEC.md).

Đã ghép nguyên nhánh NFP trong `Bot1NfpFilter.mqh`: lịch kinh tế,
lịch dự phòng, kiểm giờ, hủy lệnh chờ và đóng vị thế qua gửi yêu cầu.
**107/107tình huống khớp**, so3.723lần gọi dịch vụ và trạng thái trước
mỗi lần/cuối nhánh; đã đi qua42lần gửi và17lần thân đóng vị thế.
Mã/bộ kiểm trực tiếp biên dịch0lỗi/0cảnh báo. Dữ liệu dịch vụ được cấp;
chưa là toànEA. [Phạm vi ghép](../danh-gia-doc-lap/nfp-filter-20261027-r1/SPEC.md).

Đã dựng `Bot1NewsSelector.mqh` chọn thời điểm và nhãn tin theo đúng
thứ tự đọc giờ máy chủ: **961/961ca khớp**, gồm946ca kiểm lại hàm số
cũ sau sửa phép nhân phút32bit. Đã so nhãn rỗng/NFP/Interest rates/CPI,
trạng thái đổi giữa lần đọc và tràn số. Nguồn trực tiếp/bộ kiểm0/0.
Nhánh NFP dự phòng đã có bằng chứng thêm về chuỗi ngày; chưa ghép hết.
[Phạm vi](../danh-gia-doc-lap/news-selector-20261027-r1/SPEC.md).

Đã dựng `Bot1PendingDistanceCancel.mqh` cho hai chiều hủy lệnh chờ
khi đủ khoảng cách: **698/698 ca khớp** (349ca mỗi chiều), chạy nguyên
thân hủy/gửi. Có ca thay giá/khoảng cách/vé giữa lần đọc; giữ giá tham
chiếu trước đọc giá lệnh và khoảng cách mới sau đó. Hai bản biên dịch0/0.
Còn nối điều kiện giờ tin/đóng vị thế trong evaluator.
[Phạm vi](../danh-gia-doc-lap/pending-distance-20261027-r1/SPEC.md).

Đã dựng `Bot1NfpCalendar.mqh` tìm lịch NFP thật theo hàm gốc:
**1.916/1.916 ca thường +8/8 ca mảng thiếu khớp**; có cả mảng đọc
xuôi/ngược, mã dự phòng, thứ tự dịch vụ và mã lỗi cuối. Nguồn trực tiếp
và bộ kiểm biên dịch0/0. Dữ liệu lịch được cấp; còn nối nhánh hủy/đóng
và lịch trực tuyến. [Phạm vi](../danh-gia-doc-lap/nfp-calendar-20261027-r1/SPEC.md).

Đã ghép `Bot1EvaluationResizeFlow.mqh`: cổng vốn → toàn bước tính
khối lượng/rút tiền/đổi tiền → tạo lại lệnh chờ qua xóa/mở/gửi thật.
**316/316 ca thường +2/2 ca chia0 khớp**; giữ chung chỉ số/mảng,
không đặt lại trạng thái giữa các phần. Bản nguồn trực tiếp và bộ kiểm
đều biên dịch0lỗi/0cảnh báo. Còn nối phía trước/sau và toànEA.
[Phạm vi](../danh-gia-doc-lap/resize-flow-20261027-r1/SPEC.md).

Đã phục hồi thêm toàn bước tính khối lượng `Bot1VolumeRuntime.mqh`:
**1003/1003 ca thường** khớp từng byte, **5/5 ca chia 0** dừng đúng,
so cả đọc lại dữ liệu, thứ tự/chuỗi thông báo, ghi vốn và toàn mảng khối lượng.
Nguồn gọi MT5 trực tiếp và bộ kiểm đều biên dịch 0 lỗi/0 cảnh báo.
Còn nối vào toàn bộ hàm đánh giá/EA; trạng thái ngay điểm lỗi sau
lần đọc dịch vụ cuối chưa được xuất đủ. [Phạm vi](../danh-gia-doc-lap/volume-runtime-20261027-r1/SPEC.md).

# bot-cua-toi-1

Đã dựng cổng thay đổi vốn trước bước tính khối lượng/tạo lại lệnh:
**973/973 ca thường,6/6 ca chia0 khớp**, biên dịch0lỗi/0cảnh báo.
Giữ đúng ghi mốc vốn trước lời gọi kế của bot1. Chưa nối bước tính
khối lượng với cổng này hoặc toànEA.
[Phạm vi](../danh-gia-doc-lap/resize-balance-gate-20261027-r1/README.md).

Đã viết vòng tạo lại lệnh chờ sau thay đổi khối lượng: **278/278 ca
khớp**, đủ200ô bảng,35trường/4chuỗi và dịch vụ/thông báo/chờ. Chạy
nguyên các thân xóa/mở/gửi của bot1 riêng; đầu vào sau tính khối lượng
và dịch vụ được cấp. Biên dịch0lỗi/0cảnh báo; còn cổng trước vòng và EA.
[Phạm vi và bằng chứng](phan-tich/chuong-trinh-chinh/pending-resize-20261027-r1/README.md).

Đã chốt cờ nhánh vé đầu0 ở cạnh quản lý khi đổi nến:
**3.628/3.628 ca khớp**, biên dịch0lỗi/0cảnh báo. Chạy liên tục từ
đầu đánh giá tới đúng nhánh trong thân quản lý thật, giữ nguyên cờ
bản quyền. Ngày/phiên/tổng vị thế/ngăn xếp và byte vào được cấp;
chưa nối mọi đường hàm điều phối hoặc toàn bộ vòng quản lý.
[Công thức, nguồn và giới hạn](phan-tich/chuong-trinh-chinh/first-zero-caller-20261027-r1/README.md).

Đã nối đầu đánh giá qua vòng bổ sung dừng lỗ/chốt lời, thân sửa vị thế và
thân gửi: **1.172/1.172 ca khớp**, bốn thời điểm chụp đủ trường yêu cầu/
kết quả và chuỗi; biên dịch **0 lỗi/0 cảnh báo**. Thân hàm con chạy thật,
dịch vụ được cấp; chưa nối phần quản lý tiếp theo hoặc toàn EA.
[Phạm vi và bằng chứng](../danh-gia-doc-lap/evaluation-stops-20261027-r1/README.md).

Đã viết phần đầu đánh giá qua giờ giao dịch, thông báo và cập nhật giá/
lịch hiện tại: **1.594/1.594 ca khớp**, gồm 30 giá trị và toàn bộ dịch vụ,
đối số, chuỗi UTF-16/NULL theo thứ tự. Hai bản dựng đều **0 lỗi/0 cảnh báo**.
Đối chứng chạy nguyên mã bot 1, không lấy kết quả bot 3 làm mẫu. Dịch vụ
được cấp; còn phần quét lệnh/vị thế, ngữ cảnh nối tiếp và toàn bộ EA.
[Nguồn, bằng chứng và giới hạn](phan-tich/chuong-trinh-chinh/evaluation-prelude-complete-20261027-r1/README.md).

Đã ghép nạp cấu hình → ghi chú/mã/đổi tiền → chuẩn bị: **432/432 ca khớp**,
so **127 giá trị và toàn bộ ghi chú lệnh**. Ba thân gốc chạy liên tục,
kiểm cả chỉ số và chỗ quay về của lời gọi chuẩn bị; không đặt lại ở giữa.
Biên dịch 0 lỗi/0 cảnh báo. Chưa nối bước này với đánh giá trong EA đầy đủ.
[Đặc tả và giới hạn](../danh-gia-doc-lap/strategy-setup-20261027-r1/SPEC.md).

Đã thêm phần ghi chú, mã nhận diện và đổi tiền trước khi chuẩn bị:
**760/760 ca khớp**, gồm chuỗi đầy đủ và thứ tự đọc thông tin; thêm
**2/2 ca** chia 0 dừng đúng loại lỗi. Biên dịch 0 lỗi/0 cảnh báo.
Đây là đoạn đã so riêng, chưa ghép toàn bộ chương trình chính.
[Nguồn, bằng chứng và giới hạn](phan-tich/chuong-trinh-chinh/strategy-context-20261027-r1/SPEC.md).

Đã nối nạp cấu hình với chuẩn bị dữ liệu: **432/432 ca khớp**, so 119 giá
trị và đối số chỉ báo. Đã bổ sung đủ sáu ô phụ còn thiếu để truyền sang bước
chuẩn bị; tên mã/comment/vốn vẫn được cấp, chưa nối EA chính.
[Bằng chứng và giới hạn](phan-tich/chuong-trinh-chinh/profile-preparation-20261027-r1/README.md).

Đã thêm đoạn sau khi có giá cơ sở đến đặt lệnh chờ: **416/416 ca khớp**
giữa mã gốc và MQL5, biên dịch **0 lỗi/0 cảnh báo**. Đoạn này vẫn nhận giá
và dịch vụ từ phần trước, chưa phải EA đầy đủ.
[Bằng chứng](phan-tich/chuong-trinh-chinh/pending-submission-20261026-r1/README.md).

Đã dựng thân chuẩn bị tại `0x7500..0x831d`: **1.060/1.060 ca khớp** 87 giá
trị và thứ tự gọi, gồm lỗi chỉ báo/lấy giá, NaN và vô cực. Thêm **12/12 ca**
khớp loại lỗi dừng vì chia 0 hoặc thiếu phần tử; chưa so đủ trạng thái trước
lỗi. Biên dịch 0 lỗi/cảnh báo; còn nối EA và kiểm toàn bộ.
[Nguồn, bằng chứng và giới hạn](phan-tich/chuong-trinh-chinh/preparation-complete-20261026-r1/SPEC-r2.md).

Đã viết khối nạp 8 cấu hình và điều chỉnh khoảng giá: **432/432 ca native/MQL5
khớp từng bit**, gồm hai chế độ HL, hạt giống 32-bit, số NaN/vô cực và bốn ô
điều chỉnh; biên dịch **0 lỗi, 0 cảnh báo**. [Đặc tả và phép kiểm](phan-tich/chuong-trinh-chinh/profile-parameters-20261026-r1/README.md).
Lượt 27/10 đã kiểm lại tiền nạp và đủ 127 byte của 22 trường ở mọi cấu hình;
bộ dò dừng ngay nếu còn thanh ghi chưa xác định. Kết quả mới vẫn 432/432,
mã kiểm `6dc91e38...`; chưa nối phần nạp này vào EA.

Vòng quản lý mua/bán đã ghép cùng các hàm bảng/sửa/đóng/gửi và khớp
**352/352 ca**, biên dịch **0 lỗi/0 cảnh báo**. Dữ liệu và kết quả gửi
của MT5 được cấp trong bộ kiểm; **chưa có EA đầy đủ**.
[Phạm vi mới](../PHAN-TICH-GHEP-QUAN-LY-BOT-1.md).

Mới kiểm dừng lỗ thật theo thời gian mua/bán: **492/492 ca khớp**,
biên dịch **0 lỗi, 0 cảnh báo**. Hàm sửa và khối báo lỗi được cấp trả lời;
chưa phải toàn quản lý hoặc EA.
[Phạm vi mới](../PHAN-TICH-NHANH-THAT-BOT-1-3.md).

Mới thêm phần cuối quản lý mức ảo: **1.260/1.260 ca khớp**, gồm cờ có sẵn,
bộ đếm và đủ 1.500 ô bảng với vé ở đầu/giữa/cuối, trùng hoặc không khớp.
Biên dịch **0 lỗi, 0 cảnh báo**. Hàm đóng được chặn ở ranh giới;
chưa phải toàn quản lý hoặc EA. [Phạm vi](../PHAN-TICH-KET-THUC-AO-BOT-1-3.md).

Đã viết bốn hàm bảng dừng ảo: 220/220 ca khớp mã gốc/MQL5/máy đo
quá khứ, thêm hai ca lỗi mảng chạy thật khớp trạng thái trước lỗi.
Biên dịch 0 lỗi/cảnh báo, gồm bản dùng API MT5 thật chỉ biên dịch.
Còn nhánh lỗi chưa chạy, dòng/cột báo lỗi khác, khởi động lại và
ghép quản lý vị thế/toàn EA;
[phạm vi và bước còn thiếu](../PHAN-TICH-BANG-DUNG-AO-BOT-1-3.md).

Đã dựng hàm sửa dừng lỗ/chốt lời vị thế theo vé `0x26d20`: kiểm
chương trình dừng, chọn vé, tạo yêu cầu sửa rồi gửi/thông báo.
1.596/1.596 ca khớp mã gốc/MQL5/máy đo quá khứ (83 ca dừng, 33 ca chọn
vé thất bại, 1.480 ca gửi), chạy đủ 196/196 lệnh máy; biên dịch 0 lỗi/
cảnh báo. Truy vấn/kết quả gửi được cấp. Còn 19 nơi gọi và giá trị
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

Đã dựng hai hàm đếm lệnh và dọn bảng 100 hàng: 307/307 ca khớp cả
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
Bản đồ có đủ 84 hàm trong bản chụp. Đã nối 72 dòng cài đặt với vị trí
lưu và mặc định: 648/648 lần đối chiếu khớp. Đã đọc trực tiếp nhãn nhìn
thấy và ba menu/11 lựa chọn. Còn kiểu/phạm vi, tác dụng đầy đủ và tài nguyên.
[Bảng cài đặt](../PHAN-TICH-CAI-DAT-BOT-1-3.md).

Đã dựng phần nạp vốn/tên lưu/mốc thời gian, 616/616 ca khớp mã gốc;
biên dịch 0 lỗi, 0 cảnh báo. [Menu và khởi động](../PHAN-TICH-MENU-VA-KHOI-TAO-BOT-1-3.md).

Đã kiểm đủ 256 cách bật/tắt tám chiến lược, 2.048 lần kiểm nhánh gốc
đều khớp. Nguồn `Bot1StrategySelection.mqh` khớp lại 256/256 ca;
[báo cáo nguồn mới](../PHAN-TICH-CHON-CHIEN-LUOC-MQL5-BOT-1-3.md).
[Kết quả mã gốc](../PHAN-TICH-BAT-TAT-BOT-1.md).

Phần vốn vừa ghép khớp 1.700/1.700 ca; kiểm ký quỹ khớp 1.141/1.141 ca.
[Bằng chứng](../PHAN-TICH-LUONG-VON-VA-KY-QUY-BOT-1-3.md).

Chưa có EA MQL5 hoàn chỉnh. Đã xuất 84 hàm từ bảng mã mới và dựng lại
hai hàm mức giá; 1.104/1.104 ca so với đoạn mã gốc trùng kết quả.

Lượt tiếp đã thêm xác nhận mức giá, lọc lệnh chờ gần và bảng tham số gốc
của 8 chiến lược: 1.096/1.096 ca mới và 48/48 giá trị khớp.
Xem [kết quả phần mới](../PHAN-TICH-VAO-LENH-BOT-1-3.md).

Lượt mới nhất thêm tính khoảng cách/thời hạn và bảng cơ bản của từng
chiến lược: 1.050/1.050 ca, 16/16 bảng khớp; biên dịch 0 lỗi, 0 cảnh báo.
Xem [phạm vi và nguồn mới](../PHAN-TICH-DIEU-CHINH-BOT-1-3.md).

Đã ghép thêm đổi tiền tệ với tính khối lượng: 783/783 ca khớp; phần đổi
tiền riêng khớp 1.530/1.530 ca. [Bằng chứng và giới hạn](../PHAN-TICH-KHOI-LUONG-BOT-1-3.md).

Đã dựng cập nhật vốn sau khi rút tiền: 915/915 ca khớp; ghi/đọc qua hai
lần mở MT5 riêng đạt. [Kết quả mới](../PHAN-TICH-RUT-TIEN-BOT-1-3.md).

- [Phân tích và giới hạn](../PHAN-TICH-BOT-1-3.md)
- [Nguồn mức giá](source/MQL5/Include/bot-cua-toi-1/Bot1PriceLevels.mqh)
- [Bộ kiểm MQL5](source/MQL5/Scripts/bot-cua-toi-1/Bot1PriceLevelsCheck.mq5)
- [Mã C trung gian hiện hành](phan-tich/luot-20261023-data-v2/ma-trung-gian.c)
- [Danh sách hàm](phan-tich/luot-20261023-data-v2/danh-sach-ham.json)
- [Kết quả kiểm](bang-chung/kiem-muc-gia/gia-20261023-r1/comparison.json)

Thư mục `phan-tich/ban-ex5-05/` là bằng chứng cũ, được giữ nguyên.

Đã dựng hàm sắp xếp hai mảng lịch sử `Bot1HistorySort.mqh` tại `0x47950`.
Lượt `history-sort-20261025-r1` khớp 512/512 ca thường với mã gốc,
biên dịch 0 lỗi/0 cảnh báo. Ca lỗi, nơi gọi, phần tổng hợp lịch sử,
khởi động lại và toàn EA chưa kiểm.

Các đoạn đầu của quản lý vị thế cũng đã được kiểm riêng:
340 ca đọc/lọc và đóng theo nến, 266 ca bảng 100 vé/giá mở, 924 ca
nhánh bắt đầu dừng ảo; cả ba lượt khớp mã gốc/MQL5, biên dịch 0 lỗi/
0 cảnh báo. Đây chưa phải hai hàm quản lý đầy đủ; các nhánh dời dừng
còn lại, nơi gọi, điều phối và toàn EA vẫn mở.

Trong 924 ca dừng ảo có 364 ca đầu nhánh, 156 ca theo thời gian,
220 ca theo khoảng cách và 184 ca kiểm trượt giá. Các ca này dùng
dịch vụ con giả lập ở ranh giới lời gọi; chưa chứng minh giao dịch thật.

Đã sửa ba nơi gọi đóng sang hàm kiểm điều kiện như gốc. Kiểm lại nguồn
hiện hành: 340/340, 266/266 và 924/924 ca khớp; thêm 36/36 ca chạy
hàm kiểm đóng thật từ ba nơi gọi, luôn chặn trước gửi lệnh.
[Bằng chứng và giới hạn](../PHAN-TICH-GHEP-KIEM-DONG-QUAN-LY-BOT-1.md).
