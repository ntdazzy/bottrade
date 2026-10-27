# Bản đồ phân tích và danh sách chống bỏ sót — bot 1 và 3

Trạng thái: **đang phân tích, chưa xác nhận đã hiểu toàn bộ EX5**.
Quy tắc hiện hành nằm ở [AGENTS.md](../../AGENTS.md). Mọi phần chưa rõ
phải được phân tích tiếp trước khi viết luật tương ứng.

## Đầu vào và độ bao phủ hiện biết

| Nội dung | Bot 1 | Bot 3 |
|---|---|---|
| Tên gốc | Gold Trade Pro MT5 | The Gold Reaper MT5 |
| SHA-256 EX5 chuẩn | `a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922` | `ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83` |
| Hàm trong bảng mã chụp | 84 | 82 |
| Hàm đã được liệt kê từng dòng | 84/84 | 82/82 |
| Dòng đầu vào đã quan sát | 72: 64 cài đặt, 8 tiêu đề | 80: 71 cài đặt, 9 tiêu đề |
| Đã nối vị trí lưu và kiểm mặc định | 72/72 dòng; 648/648 lần so | 80/80 dòng; 720/720 lần so |
| Nơi gọi nội bộ chưa có trong bảng được quét | 0 | 0 |
| Địa chỉ gọi ngoài trực tiếp chưa có nhãn trong lần quét | 0, đã đối chứng thêm 10 | 0, đã đối chứng thêm 9 |

Hàm phụ sắp xếp lịch sử đã có nguồn riêng cho cả hai bot: bot 1
`0x47950`, bot 3 `0x557f0`. Lượt `history-sort-20261025-r1` chạy
512 ca thường mỗi bot, khớp 512/512 từng byte giữa mã gốc và MQL5,
biên dịch 0 lỗi/0 cảnh báo. Đây chỉ là hàm phụ; chưa chứng minh toàn
bộ phần lịch sử hoặc EA.

Danh sách đầy đủ từng hàm và từng dòng cài đặt:

- [Bot 1](ban-do-bot-1-3/luot-20261025-r5/bot-1.md), [dữ liệu chi tiết](ban-do-bot-1-3/luot-20261025-r5/bot-1.json).
- [Bot 3](ban-do-bot-1-3/luot-20261025-r5/bot-3.md), [dữ liệu chi tiết](ban-do-bot-1-3/luot-20261025-r5/bot-3.json).
- [Biên nhận lập danh sách](ban-do-bot-1-3/luot-20261025-r5/summary.json).

Mỗi hàm có vị trí gốc, dòng C, các hàm gọi/được gọi, lời gọi MT5, mã
điều phối, chuỗi liên quan, biến dùng chung, nguồn dựng lại và bằng
chứng kiểm thành phần nếu có. Các mô tả chỉ nói phần đã thấy trong mã.
Chưa xem số hàm này là toàn bộ mã có thể chạy của EX5; lời gọi qua bảng
hoặc nhánh chưa chạy còn phải kiểm riêng.

Đã đối chiếu thêm [toàn bộ dòng cài đặt đã thấy](PHAN-TICH-CAI-DAT-BOT-1-3.md)
trong 18 lượt chạy riêng. Tên/thứ tự trong nhật ký, vị trí lưu và mặc
định đã chốt. Lượt mới đã đọc trực tiếp 152 nhãn nhìn thấy và nối đủ
28 lựa chọn của bảy menu; còn kiểu khai báo/phạm vi và tác dụng đầy đủ. Hai
đoạn [chọn chiến lược bot 3](PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md) đã
khớp 7.724 ca phân tích với mã gốc; nguồn MQL5 mới cũng khớp đủ 7.724
ca. [Tám nhánh bật/tắt bot 1](PHAN-TICH-BAT-TAT-BOT-1.md) đã khớp đủ
256 tổ hợp, qua 2.048 lần kiểm nhánh; nguồn MQL5 mới khớp 256 ca.
[Báo cáo nguồn mới](PHAN-TICH-CHON-CHIEN-LUOC-MQL5-BOT-1-3.md).
Đã viết MQL5 nạp vốn/tên lưu/mốc thời gian, khớp 616 ca mỗi bot;
[phạm vi menu và khởi động mới](PHAN-TICH-MENU-VA-KHOI-TAO-BOT-1-3.md).

## Danh sách các phần phải phân tích và phục hồi

Vị trí trong bảng là số tính từ đầu vùng mã của mỗi bot. Chi tiết dòng
và lời gọi tra ở hai danh sách trên. “Đã so phần” có nghĩa đã có một
phép đối chiếu trong phạm vi cụ thể; không đánh dấu hoàn tất cả hàng.

| Mã | Phần bắt buộc | Bằng chứng gốc, bot 1 / bot 3 | Tình trạng và phần phải chốt |
|---|---|---|---|
| P01 | Đúng EX5, dữ liệu và cấu hình | Mã SHA-256, bản chụp, nhật ký gốc | Đã có; cần giữ đúng bản chuẩn ở mọi lượt kiểm |
| P02 | Tất cả đầu vào và nhóm cài đặt | 72/80 dòng, 18 bản chụp và ảnh cửa sổ mới | Đã nối vị trí/mặc định, đọc nhãn nhìn thấy và 28 lựa chọn/7 menu; còn kiểu khai báo/phạm vi, ký tự nhãn ẩn và tác dụng toàn bộ |
| P03 | Khởi tạo, sự kiện và dừng | `0xc30`, `0x20a00`, `0x1f5e0`, `0x22750` / `0xc30`, `0x2bb80`, `0x2a800`, `0x2dd30` | Đã dựng/so phần nạp vốn 616 ca mỗi bot; cần nối chắc chắn sự kiện MT5, chỉ báo, thứ tự còn lại và lỗi khởi tạo |
| P04 | Chọn/bật/tắt chiến lược | `0x10f60` / `0xc30`, `0x17f00`; bảng 8/9 chiến lược | Đã dựng nguồn chọn cờ/chế độ; bot 1 khớp 256 ca, bot 3 khớp 7.724 ca. Còn ghép vào EA, nguồn trạng thái/cờ thực tế và quản lý vị thế khi chiến lược tắt |
| P05 | Tham số cơ bản và điều chỉnh theo giá | `0x7500` / `0xe0c0` | Bot3 đã viết khối chuẩn bị và biên dịch0/0, so1.016/1.016ca thường/76giá trị từ cả thân gốc; dữ liệu dịch vụ được cấp; thêm18/18ca chia0 khớp lớp lỗi/dừng khi biên dịchbậtkiểmchia0, chưa so đủ trạng thái trước lỗi; còn lỗi/chỉ báo/tick/lịch và nơi gọi EA; [phạm vi](PHAN-TICH-CHUAN-BI-BOT-3.md). Bot1 đã dựng thân chuẩn bị `0x7500..0x831d`: 1.060/1.060 ca, 87 giá trị và thứ tự gọi; có lỗi chỉ báo/lấy giá, mảng khác nhau, NaN/vô cực. Thêm 12/12 ca khớp loại lỗi dừng chia 0/mảng ngắn, chưa so đủ trạng thái trước lỗi. Còn nối đầu vào và nơi gọi EA; [phạm vi](bot-cua-toi-1/phan-tich/chuong-trinh-chinh/preparation-complete-20261026-r1/SPEC-r2.md) |
| P06 | Điều chỉnh thêm và tạo biến thiên | Các nhánh trong `0x10f60` / `0x17f00`, `Randomization`, `Adjust*` | Bot1 đã viết khối 8 cấu hình; **432/432 ca MQL5/native khớp**, gồm NaN/vô cực, 7 mẫu, hạt giống và 4 ô điều chỉnh. Bot3 đã viết khối 31 trường, 11 mẫu và đúng thứ tự biểu thức; **2.106/2.106 ca gốc/MQL5 khớp** sau khi tách `native_6d2e4` khỏi `management_timeframe` (`0x6d324`), mã kiểm `07e41752...`; Đã so nối nạp cấu hình→chuẩn bị trong cùng bộ nhớ native: bot 1 có 432/432 ca (119 giá trị), bot 3 có 2.106/2.106 ca (124 giá trị). Lượt ghép ba bước mới đã chạy liên tục qua ghi chú/mã/đổi tiền và lời gọi chuẩn bị thật: bot 1 khớp 432/432 ca/127 giá trị, bot 3 khớp 2.106/2.106 ca/132 giá trị, thêm chuỗi UTF-16 đầy đủ và thứ tự dịch vụ. Bot 3 nối đúng hai trường cùng byte `1d6f28`. Đầu vào trước điểm đầu/dịch vụ vẫn được cấp; chưa chạy phần đánh giá, toàn bộ điều phối hoặc EA; [đặc tả](danh-gia-doc-lap/strategy-setup-20261027-r1/SPEC.md) |
| P07 | Dữ liệu thị trường và nến mới | `0xc30`, `0x18aa0` / `0xc30`, `0x20ef0`; `iTime`, `Bars`, tick | Cần thiếu dữ liệu, đổi nến, đổi ngày và nhiều khung nến |
| P08 | Tìm đỉnh/đáy làm mức giá | `0x32890`, `0x32ac0` / `0x3e040`, `0x3e270` | Đã so hai hàm; còn ghép đúng nơi gọi |
| P09 | Xác nhận mức chưa bị phá | `0x265a0`, `0x26960` / `0x31cd0`, `0x32090` | Đã so phần; còn điều kiện cấp tham số từ toàn bộ chiến lược |
| P10 | Chặn lệnh chờ gần mức dự kiến | `0x3c670`, `0x3c8d0` / `0x47380`, `0x475e0` | Đã so phần; còn ghép cùng giá đặt cuối cùng |
| P11 | Toàn bộ điều kiện cho phép vào | `0x18aa0` / `0x20ef0` | Bot1 đã dựng điều phối quản lý theo lần nhận giá/nến mới và đếm hai chiều:1.536/1.536ca, hai thân quản lý được cấp kết quả; [phạm vi](bot-cua-toi-1/phan-tich/chuong-trinh-chinh/management-router-20261026-r1/README.md). Bot3 đã dựng đoạn đổi nến gọi đủ hai chiều quản lý:384/384ca, thân quản lý được cấp kết quả trong lượt này; [phạm vi](bot-cua-toi-3/phan-tich/chuong-trinh-chinh/bar-gate-20261026-r1/README.md). Bot 3 thêm phần đầu đánh giá `20ef0..211ea/216e5`: 432/432 ca, 17 giá trị và chuỗi UTF-16/NULL, khớp thứ tự đọc thời gian/chọn mã/thông tin MQL; [phạm vi](bot-cua-toi-3/phan-tich/chuong-trinh-chinh/evaluator-prelude-20261027-r1/VERIFIED-HEAD.md). Bot 3 đã nối đầu đánh giá qua thông báo/kiểm phiên và cập nhật giá/lịch đến `212ff`: **1.594/1.594 ca**, so31giá trị và toàn bộ đối số/chuỗi/thứ tự dịch vụ; mã gốc chạy liên tục, dữ liệu dịch vụ được cấp; [phạm vi](bot-cua-toi-3/phan-tich/chuong-trinh-chinh/evaluation-prelude-complete-20261027-r1/README.md). Bot 1 đã so phần tương ứng `18aa0..18eb1`: **1.594/1.594 ca**, so30giá trị và đầy đủ dịch vụ/chuỗi; không có cờ người gọi DL của bot 3; [phạm vi](bot-cua-toi-1/phan-tich/chuong-trinh-chinh/evaluation-prelude-complete-20261027-r1/README.md). Đã nối đầu đánh giá qua vòng bổ sung mức dừng/chốt và thân sửa/gửi thật: **1.172/1.172 ca mỗi bot**, so đủ35trường/4chuỗi tại ranh giới và khi ra; bot3DL0 bỏ dọn lệnh chờ, dịch vụ được cấp; [phạm vi](danh-gia-doc-lap/evaluation-stops-20261027-r1/README.md). Bot3 đã nối bước dọn lệnh chờ trước bổ sung mức: **339/339 ca**, nguyên các thân xóa/sửa/gửi, đủ200ô bảng/35trường/4chuỗi; dịch vụ được cấp; [phạm vi](bot-cua-toi-3/phan-tich/chuong-trinh-chinh/evaluation-order-cleanup-20261027-r1/README.md). Còn ngữ cảnh nối sang quản lý, bảng nhánh đầy đủ cho từng chiến lược/chiều và EA |
| P12 | Tính khối lượng và các chế độ rủi ro | `0x34780` / `0x3f900` | Đã dựng thân gọi MT5 trực tiếp, nối rút tiền/đổi tiền thật: bot1 **1.003/1.003 ca**, bot3 **1.039/1.039 ca**, đủ thứ tự đọc lại/chuỗi thông báo/trạng thái trước dịch vụ và toàn mảng; thêm5/6ca chia0 dừng đúng và chuỗi dịch vụ trước lỗi khớp. Bốn bản biên dịch0/0. Giữ NaN đúng MAXSD/MINSD và đọc lại chỉ số mảng khi ghi. Còn ghép các giá trị/ngữ cảnh từ chương trình chính, trạng thái sát lỗi sau dịch vụ cuối và EA; [phạm vi](danh-gia-doc-lap/volume-runtime-20261027-r1/SPEC.md) |
| P13 | Đổi tiền tài khoản và cặp giá | `0x36220`, `0x47d20` / `0x8300`, `0x41780` | Đã so công thức hai chiều khi tên tiền được cấp. Đã dựng riêng đoạn ghi chú/mã nhận diện/đổi tiền trước chuẩn bị: bot 1 khớp 760/760 ca, bot 3 khớp 1.818/1.818 ca, gồm thứ tự đọc lại tiền tài khoản, JPY/YEN chung điều kiện, CHF lặp của bot 1 và đổi tiền hai lần của bot 3. Thêm 2/3 ca chia 0 dừng đúng loại lỗi, chưa so đủ trạng thái trước lỗi. Còn nạp đuôi mã lúc khởi tạo và nối toàn bộ đường gọi; [bot 1](bot-cua-toi-1/phan-tich/chuong-trinh-chinh/strategy-context-20261027-r1/SPEC.md), [bot 3](bot-cua-toi-3/phan-tich/chuong-trinh-chinh/strategy-context-20261027-r1/SPEC.md) |
| P14 | Vốn cao nhất, rút tiền và lưu trạng thái | `0x173f0`, `0xc30` / `0x1fd00`, `0xc30` | Đã so cập nhật/ghi-đọc, tên mục và nạp lại trong đoạn khởi tạo; còn ghép toàn bộ, mã lỗi/thông báo và kiểm cùng tài khoản |
| P15 | Kiểm khối lượng hợp lệ và ký quỹ | `0x3bfe0`, `0x3cb30`, `0x457d0` / `0x46ca0`, `0x47840`, `0x53670` | Đã so kiểm ký quỹ và dựng kiểm khối lượng hợp lệ: 1.834 ca mỗi bot, gồm 27 lần dừng vì chia 0 thật. Còn ghép EA, lỗi dữ liệu thực và đuôi số thông báo; [bằng chứng](PHAN-TICH-KHOI-LUONG-HOP-LE-BOT-1-3.md) |
| P16 | Tạo/gửi yêu cầu giao dịch | `0x950`, `0x2e6d0`, `0x32dd0` / `0x950`, `0x3bb10`, `0x3e580` | Đã dựng chọn cách khớp (3.096 ca), chuẩn bị (1.607 ca), gửi/thông báo (1.201 ca), ghép tạo yêu cầu qua gửi (1.687 ca), hàng đợi/thử lại (374 ca). Đã so chung hàng đợi→tạo→gửi→thông báo 818 ca mỗi bot, cả chương trình MQL5 và máy đo quá khứ. Bot1 thêm đoạn sau giá cơ sở đến đặt lệnh:416/416ca, mã gốc/MQL5 cùng mã kiểm `06b446ad...`; Bot3 thêm đoạn tương ứng 332/332ca, mã kiểm `318d545d...`. Thuộc tính/kết quả/lỗi gửi được cấp; còn nơi giao dịch và ghép EA; [phạm vi](PHAN-TICH-CHUOI-DAT-LENH-BOT-1-3.md). |
| P17 | Quét, nhận dạng và đếm lệnh/vị thế | Các hàm nhóm `0x2f5c0..0x32ce0` / `0x3ca00..0x3e490`, bot 3 `0x47330` | Đã dựng năm hàm đếm/dọn bảng/giới hạn: bot 1 khớp 307 ca, bot 3 215 ca cả chương trình MQL5 và máy đo quá khứ. Đã dựng thêm quét/hủy mua-bán2f5c0/2f7e0 và3ca00/3cc20: **698/698ca mỗi bot** qua nguyên thân hủy/gửi, giữ thời điểm chụp giá/đọc khoảng cách và các ô đổi giữa dịch vụ, nguồn/bộ kiểm0/0; [phạm vi mới](danh-gia-doc-lap/pending-distance-20261027-r1/SPEC.md). Còn trạng thái chọn/tài khoản thực, nơi gọi và các hàm còn lại; [phạm vi](PHAN-TICH-QUET-LENH-BOT-1-3.md) |
| P18 | Sửa/hủy lệnh chờ và vùng cấm sửa | `0x30320`, `0x34150`, `0x32110`, `0x325b0` / `0x32450`, `0x3d650`, `0x3da90`, `0x3dd60` | Đã dựng hủy một vé (964 ca), ghép hai hàm chọn vé mua/bán qua hủy/gửi và dọn bảng/thông báo (2.522 ca mỗi bot); khớp mã gốc/MQL5/máy đo quá khứ. Truy vấn/kết quả gửi được cấp. Bot3 đã dựng vòng tạo lại lệnh sau thay đổi khối lượng22a59..235f7: **278/278ca**, các thân xóa/mở/gửi nguyên,200ô bảng/35trường/4chuỗi và dịch vụ; đầu ra tính khối lượng được cấp, còn cổng/quản lý phía trước; [phạm vi](bot-cua-toi-3/phan-tich/chuong-trinh-chinh/pending-resize-20261027-r1/README.md). Bot1 đã dựng vòng tương ứng1a817..1b317: **278/278ca**, nguyên các thân xóa34150/mở32dd0/gửi950,8ô khối lượng và200ô bảng; [phạm vi](bot-cua-toi-1/phan-tich/chuong-trinh-chinh/pending-resize-20261027-r1/README.md). Cổng vốn đã được so riêng: **973/973ca thường +6/6ca chia0 mỗi bot**, giữ đúng bot1 ghi mốc và bot3 không ghi; [phạm vi](danh-gia-doc-lap/resize-balance-gate-20261027-r1/README.md). Đã nối liên tục cổng→khối lượng/rút tiền/đổi tiền→tạo lại lệnh qua các thân xóa/mở/gửi: **316/316ca mỗi bot +2/2ca chia0 mỗi bot**, giữ chung chỉ số/mảng, mốc vốn và toàn bộ trạng thái; không cấp sẵn đầu ra khối lượng, hai bản nguồn/bộ kiểm0/0; [phạm vi ghép](danh-gia-doc-lap/resize-flow-20261027-r1/SPEC.md). Còn phía trước/sau chuỗi, toàn bộ sửa lệnh, dữ liệu/trạng thái chọn tài khoản thực, lỗi cấp bộ nhớ, nơi gọi và toàn EA; [phạm vi](PHAN-TICH-HUY-LENH-CHO-BOT-1-3.md) |
| P19 | Hết hạn thật và tự quản lý hết hạn | Tham số ở `0x7500` / `0xe0c0`, nơi dùng trong chiến lược | Đã so cách tính thời hạn; chưa toàn bộ việc hủy khi đến hạn |
| P20 | Dừng lỗ/chốt lời sau khớp | `0x271f0`, `0x2abc0`, hàm sửa `0x26d20` / `0x32f60`, `0x37590`, hàm sửa `0x32a90` | Đã dựng hàm sửa dừng lỗ/chốt lời theo vé: 1.596 ca mỗi bot khớp mã gốc/MQL5/máy đo quá khứ (83 dừng, 33 chọn vé thất bại, 1.480 gửi; 196/196 lệnh máy); tổng kiểm từ chối 22 kiểu dữ liệu sai. Bot 1 đã kiểm thêm lát đầu quản lý: 340 ca đọc/lọc, 266 ca bảng 100 vé/giá mở, 924 ca bắt đầu dừng ảo; cả ba khớp và biên dịch sạch. Bot 3 đã kiểm hai lát bảng giá mở: 190/190 ca; thêm 636/636 ca phần đầu đọc/lọc, dừng/chốt và ba nhóm nến, có đối chứng CPU cho hai NaN; [phạm vi mới](PHAN-TICH-QUAN-LY-BOT-3-20261025.md). Các số này chưa phải hai hàm quản lý hoàn chỉnh; còn các nơi gọi cần ghép toàn luồng, nhánh dời dừng còn lại, giá trị truyền vào, cả hai chiều, đặt sau khớp và kết quả tài khoản thật; [phạm vi](PHAN-TICH-SUA-VI-THE-BOT-1-3.md) |
| P21 | Dời dừng lỗ/chốt lời, hòa vốn, phục hồi theo thời gian | Cùng hai hàm quản lý vị thế và các UseHL/AdjustTrail | Bot1 đã sửa vé đầu0 với cờ bắt buộc:352/352ca mỗi ngữ cảnhfalse/true và352/352chuỗi nơi gọi thật; đã chốt hàm ngữ cảnh cờ nhánh nến mới bằng **3.628/3.628ca** chạy liên tục từ đầu evaluator tới test vé0 trong thân quản lý, gồm16vị trí ngăn xếp và byte vào0/70; còn nối trạng thái nguồn và chứng minh mọi đường từ hàm điều phối; [phạm vi](bot-cua-toi-1/phan-tich/chuong-trinh-chinh/first-zero-caller-20261027-r1/README.md). Bot 1 giữ bộ 924 ca ba nhánh ảo/bước đầu và 36 ca ghép kiểm đóng thật; thêm 1.260/1.260 ca kết thúc nhánh ảo, gồm cờ có sẵn, cao/thấp, khóa/bộ đếm, bảng 1.500 ô với vé ở đầu/giữa/cuối/trùng/không khớp. Bot 3 có 560/560 ca ba nhánh ảo, 424/424 cập nhật chốt, 1.304/1.304 cao/thấp và khóa/bộ đếm, 296/296 lưu hai bảng; các hàm đóng được chặn trong các bộ mới. Nhánh dừng thật theo thời gian bot 1 và bot 3 đạt 492/492 ca mỗi bot phần tính/gọi sửa, chặn khối báo lỗi. Bot 1 đã so ba khối dời dừng theo khoảng giá/kiểm trượt giá/ghi bảng do Claude viết:1.246/1.246ca, có thân báo lỗi, còn chặn sửa/đóng. Cả sáu phần thật gồm cao/thấp/khóa lời/bộ đếm đã khớp2.290/2.290ca, biên dịch0/0; Bot1 đã ghép vòng quản lý mua/bán, biên dịch0/0 và so352/352ca từ đầu đến trả về, có nhiều vị thế/đổi chế độ; đã chạy thêm thân hàm bảng/sửa/kiểm đóng/đóng/chọn khớp/gửi trong cùng352/352ca và so29trường, dữ liệu MT5/kết quả gửi vẫn được cấp, chưa nối EA; [vòng mới](PHAN-TICH-GHEP-QUAN-LY-BOT-1.md). [bằng chứng](bot-cua-toi-1/phan-tich/dong-vi-the/management-real-six-20261026-r1/README.md). Bot 3 thêm 994/994 ca chốt lời thật mua/bán, chặn sửa/đóng/báo lỗi; [phạm vi mới](PHAN-TICH-NHANH-THAT-BOT-1-3.md). Bot 3 thêm 2.290/2.290 ca sáu khối thật, gồm thân báo lỗi; đã ghép nguồn toàn quản lý, biên dịch0/0 và so364/364 ca cả hai parent từ đầu đến trả về, gồm nhiều vị thế/đổi mode/lỗi; bốn hàm bảng và toàn bộ hàm sửa/kiểm đóng/đóng/chọn khớp/gửi đã chạy thân thật364/364ca, so31trường, dịch vụ MT5 vẫn được cấp dữ liệu, chưa ghép EA; [phạm vi mới](PHAN-TICH-GHEP-QUAN-LY-BOT-3.md). Còn ghép toàn chuỗi, nhánh thật khác, nơi gọi, lỗi và toàn EA; [phạm vi mới](PHAN-TICH-KET-THUC-AO-BOT-1-3.md) |
| P22 | Dừng/chốt ảo và chờ chuyển thành lệnh thật | `0x3d200`, `0x3d5a0`, `0x3d640`, dọn `0x18790` / `0x47f10`, `0x482b0`, `0x484c0`, `0x48560` | Bot 1 có nguồn bốn hàm: 220/220 ca thường khớp mã gốc/MQL5/máy đo quá khứ và hai ca lỗi mảng chạy thật khớp trạng thái; biên dịch 0 lỗi/cảnh báo. Bot 3 có nguồn năm hàm: 291/291 ca thường khớp cả ba cách chạy, hai ca lỗi mảng khớp loại lỗi/trạng thái, biên dịch 0/0; xem bot-cua-toi-3/phan-tich/dong-vi-the/virtual-stops-20261025-r1/final-verification.json. Đã ghép thêm đầu nhánh ảo bot 3: 272/272 ca khớp native/MQL5 với hàm con được cấp trả lời; cùng 424 ca cập nhật chốt tạo bộ 696/696. Còn ghép hàm con thật, mọi khả năng cấp phát, lỗi tài khoản thật, khởi động lại và toàn EA; [phạm vi](PHAN-TICH-QUAN-LY-BOT-3-20261025.md) |
| P23 | Đóng vị thế và xóa theo bộ lọc | `0x2fa00`, `0x2fce0`, `0x3d010`, `0x22c40` / `0x3ce40`, `0x3d220`, `0x47d20`, `0x2e370` | Đã ghép quét mua/bán qua kiểm điều kiện, đóng, chọn cách khớp, gửi và thông báo: lượt r3 khớp 4.600 ca mỗi bot (2.300 mỗi chiều) ở mã gốc/MQL5/máy đo quá khứ, gồm trạng thái trước/sau dịch vụ và hai ca đổi dữ liệu sau lần kiểm đóng đầu; bốn bản sai cố ý bị từ chối. Đã nối hai ô giá với vùng dữ liệu giá gần nhất. Còn nơi/thời điểm gọi, mọi đường nạp/ghi giá/ngưỡng, mọi tổ hợp cách khớp, trạng thái chọn/mã lỗi tài khoản thật, lỗi cấp bộ nhớ và toàn EA; [phạm vi](PHAN-TICH-CHON-VI-THE-DONG-BOT-1-3.md) |
| P24 | Giới hạn lỗ ngày/tổng và vốn | `0x10f60`, `0x18aa0`, `0x1efa0` / `0x17f00`, `0x20ef0`, `0x2a1c0` | Cần phép tổng hợp, thời điểm đặt lại và hành động khi chạm giới hạn |
| P25 | Giờ giao dịch, thứ Sáu và phiên của nơi giao dịch | Hàm chiến lược, các hàm giờ, chuỗi `[SESSIONS]` | Đã ghép tin→đóng cuối tuần qua thân đóng/hủy/gửi thật: **406/406ca mỗi bot**, so15.361/15.736lần gọi dịch vụ, đủ thứ tự đặt cờ khác nhau B1/B3; nguồn/bộ kiểm0/0. Đã ghép thêm nhánh lưu/hủy khi chênh lệch cao: **640/640ca mỗi bot**, so18.434/18.809dịch vụ và500ô bảng, nguồn/bộ kiểm0/0; [phạm vi](danh-gia-doc-lap/high-spread-20261027-r1/SPEC.md). Đã ghép thêm đặt lại lệnh từ bảng qua mở/chọn khớp/gửi/thử lại/báo lỗi: **801/801ca mỗi bot**, so19.260/19.635dịch vụ, nguồn/bộ kiểm0/0; [phạm vi](danh-gia-doc-lap/spread-restore-20261027-r1/SPEC.md). Đã ghép thêm đếm/xóa khi vượt số lệnh chờ: **989/989ca mỗi bot**, so20.220/20.595dịch vụ, nguồn/bộ kiểm0/0; [phạm vi](danh-gia-doc-lap/news-orders-20261027-r1/SPEC.md). Đã ghép cổng vào/timestamp/mức trên-dưới: **1.128/1.128ca mỗi bot**, so22.551/22.926dịch vụ, giữ đọc lại symbol/giá/phạm vi và chỉ số, nguồn/bộ kiểm0/0; [phạm vi](danh-gia-doc-lap/entry-level-cache-20261027-r1/SPEC.md). Còn phát sinh lệnh/thống kê cùng nến/hiển thị và toànEA; [phạm vi](danh-gia-doc-lap/news-friday-20261027-r1/SPEC.md). Còn các mốc/đổi ngày/lịch phiên ngoài phạm vi này |
| P26 | Giờ UTC và đổi giờ theo mùa | `0x17840`, `0x17d20` / `0x7e20`, `0x20150` | Đã so cả nguồn có hàm kiểm và bản biên dịch gọi MT5 trực tiếp, 4.737 ca mỗi bot khớp kết quả/thứ tự gọi; [bằng chứng và giới hạn](PHAN-TICH-GIO-MUA-HE-BOT-1-3.md). Còn giờ sát biên năm xa, các kiểu lỗi, thứ tự khởi tạo và ghép EA; UTC/HTTP/nhập tay vẫn còn |
| P27 | NFP, lãi suất và CPI | Nhóm `0x61b0..0x7310` / `0x6ad0..0x7c30`, chuỗi lỗi/lịch | Phép kiểm số học cũ1.620ca chưa phủ tràn phút32bit. Đã sửa độ rộng phép nhân và dựng toàn selector với nhãn/đọc giờ thật: **961/961ca mỗi bot**, gồm946ca kiểm lại hàm số học; đủ tác dụng phụ giữa dịch vụ và0lỗi/0cảnh báo; [phạm vi mới](danh-gia-doc-lap/news-selector-20261027-r1/SPEC.md). Đã dựng tìm lịch NFP61b0/6ad0: **1.916/1.916ca mỗi bot +8/8ca mảng thiếu mỗi bot**, so mã lỗi và dịch vụ, cả4tổ hợp cờ mảng; mã dự phòng/thứ tự giữ nguyên, dữ liệu lịch được cấp, nguồn/bộ kiểm0/0; [phạm vi NFP](danh-gia-doc-lap/nfp-calendar-20261027-r1/SPEC.md). Đã ghép nguyên nhánhNFPgồm lịch/bảng dự phòng/giờ/hủy chờ/đóng/gửi: **107/107tình huống mỗi bot**, so3.723lần gọi dịch vụ,42lần gửi và17lần thân đóng mỗi bot; trạng thái dùng chung, không đặt lại giữa hàm, mã/bộ kiểm0/0; [phạm vi ghép NFP](danh-gia-doc-lap/nfp-filter-20261027-r1/SPEC.md). Đã dựng thêm lấy lịch IR/CPI: **490/490ca +16/16ca lỗi mảng mỗi bot**, đúng điều kiệnCPIvà nhánh5401chỉ có ởIR, dữ liệu/mã lỗi dịch vụ được cấp, nguồn/bộ kiểm0/0; [phạm vi](danh-gia-doc-lap/remaining-news-calendars-20261027-r1/SPEC.md). Đã ghép NFP→IR→CPI→chọn lịch với trạng thái dùng chung: **133/133ca mỗi bot**, so**10.243lần gọi dịch vụ mỗi bot**, mã trực tiếp/bộ kiểm0/0; [phạm vi ghép](danh-gia-doc-lap/news-pipeline-20261027-r1/SPEC.md). Còn trực tuyến, lỗi cấp phát, khởi tạo đầy đủ và toàn chương trình chính; [phạm vi](PHAN-TICH-CHAN-TIN-BOT-1-3.md) |
| P28 | Lịch sử/tệp dữ liệu tin | Bot 3 có chuỗi `newshist.csv`, `news.csv` tại phần khởi tạo/hủy | Cần xác định đường đọc thật, nhánh có sử dụng và dữ liệu đi kèm; chưa khẳng định tính năng đang bật |
| P29 | Bảng thông tin, nhãn và thao tác biểu đồ | `0x8320`, `0xe1b0`, `0xffb0`, `0x45b70`, `0x47740` / `0xef40`, `0x14fa0`, `0x16e80`, `0x53a10`, `0x555e0` | Cần từng đối tượng, nội dung, màu/cỡ chữ, vị trí và hành vi hiển thị khi đo lại quá khứ |
| P30 | Điều kiện tài khoản/dùng chương trình và HTTP phụ | `0x5880`, `0x3d6c0`, `0x4d260` / `0x61a0`, `0x485e0`, `0x55bc0` | Cần phân biệt điều kiện giao dịch với kiểm quyền dùng; không sửa để vượt khóa/giới hạn |
| P31 | Thông báo, mã lỗi, thử lại và bộ nhớ | Hàm gửi/định dạng, các hàm phụ trợ đầu bảng | Đã dựng/so thông báo gửi (1.201 ca), hàm đổi mã lỗi/tăng đếm (5.826 ca), thử lại hàng đợi (374 ca), chuỗi ghép đầy đủ (818 ca mỗi bot). Còn thông báo/thử lại ở các phần khác, lỗi cấp bộ nhớ/CPU và dọn khi dừng; [chuỗi ghép và giới hạn](PHAN-TICH-CHUOI-DAT-LENH-BOT-1-3.md) |
| P32 | Cài đặt và tài nguyên nguyên bản | EX5 gốc, 72/80 dòng đã nối và đọc trên cửa sổ, bảy menu đã mở | Còn kiểu khai báo/phạm vi nhập, ký tự nhãn bị ẩn, hình/tài nguyên và bảng thông tin khi bot chạy |
| P33 | So toàn bộ và bàn giao | Các bằng chứng thành phần hiện có | Chưa có EA chính; cần nguồn hoàn chỉnh, EX5 đúng nguồn, cùng dữ liệu và so từng hoạt động/thiết lập |

## Điều kiện để bắt đầu từng phần và để chốt toàn bộ

Trước khi viết một phần, phải đi từ hàng tương ứng đến toàn bộ các hàm
và nhánh liên quan, chỉ rõ đầu vào/đầu ra, điều kiện kích hoạt, thứ tự
và trường hợp lỗi. Chỗ chưa chốt được vẫn nằm trong danh sách, không
được thay bằng luật dễ viết hơn. Bảng này phải cập nhật cùng mã nguồn.

Trước bàn giao, phải kiểm toàn bộ các dòng cài đặt: tên, nhóm, kiểu,
thứ tự, giá trị mặc định, các lựa chọn và tác dụng thật. Phải kiểm cả
bảng hiển thị, trạng thái sau khởi động lại và lỗi; cùng tổng lời/lỗ
không đủ. Mã trung gian C không được gọi là nguồn MQL5 gốc.

Các lượt mới đã có Claude Opus 5.5 `max` kiểm phần chọn chiến lược,
phân tích giờ theo mùa và bảng dừng ảo; kết quả và kết luận sau đối
chiếu được lưu ở `danh-gia-claude/`. Không dùng lời nhận xét thay cho
phép so với mã gốc. Lượt mới bật thêm `ultracode` cho phần khó;
[biên nhận cấu hình](danh-gia-claude/cau-hinh-20261024/receipt.json).
Lượt kiểm phương pháp cài đặt bị Claude từ chối với nhãn `[cyber]`;
[biên nhận](../.local/bot1-3-inputs-20261023/claude-method-review/run.json).
Không dùng phản hồi này làm xác nhận độc lập.

Lượt giao khối điều phối bot 1 `0x10f60` mới cũng bị Claude từ chối
với nhãn `[cyber]`, chưa có tệp triển khai hoặc đánh giá:
[biên nhận](danh-gia-claude/bot1-coordinator-20261025-r1/receipt.json).
Không đổi cách hỏi hoặc đổi phiên để vượt chặn; phần này vẫn chưa đạt.

Lượt giao hai hàm quản lý vị thế bot 1 `0x271f0` / `0x2abc0` cũng
bị Claude từ chối trong phản hồi cuối; không có phân tích hoặc mã mới:
[biên nhận](danh-gia-claude/bot1-position-management-20261025-r1/receipt.json).
Claude nêu nghi ngờ quyền sở hữu và nói không nhận khôi phục bot 1/3;
đây là nhận định của Claude, không phải kết luận đã được Codex xác minh.
Đã tách trước đủ hai thân hàm, 5.621 lệnh máy; chưa xem là đã phân tích
hoàn tất hoặc kiểm đúng hành vi. Ngày 25/10/2026, người dùng xác nhận
Codex trực tiếp làm phần Claude từ chối; Claude làm các phần còn nhận.
Codex tiếp tục phân tích hai hàm quản lý trước khi viết nguồn tương ứng.
Các lát đã đủ mô tả được ghi riêng và kiểm độc lập trong
`bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/`; không dùng chúng để
gọi hai hàm quản lý hoàn chỉnh.

Hai lượt P11/P16 mới bị Claude từ chối sau khi nối lại phiên đã dừng;
không có phân tích độc lập từ hai lượt này. Đã lưu phản hồi ở
`danh-gia-claude/p11-bot1-ultracode-20261024-r2/` và
`danh-gia-claude/order-request-ultracode-20261024-r2/`; không yêu cầu
đổi cách hỏi để vượt chặn. Phép so mới do mình thực hiện trực tiếp.

## Các điểm phân tích còn mở

- Đã nối địa chỉ gọi ngoài trực tiếp còn thiếu bằng nguồn đối chứng.
  Các mã điều phối và lời gọi gián tiếp vẫn phải kiểm; hết địa chỉ trực
  tiếp chưa có nhãn không có nghĩa đã hiểu toàn bộ lời gọi.
- Chưa có bằng chứng đủ cho mọi sự kiện và nhánh ngoài điều kiện chụp.
- Các `.set` hiện có không được dùng thay cho mặc định của tác giả.
- Kiểm thử riêng thành phần không chứng minh menu, toàn bộ chiến lược,
  tất cả tài nguyên hoặc toàn bộ EX5 đã được phục hồi.

Đã dùng lại phép đối chứng có mã nguồn trên đúng bản máy MT5 để nối thêm lời chờ và các mã gọi tạo ATR/đối tượng/ghép chuỗi. [Bằng chứng](ban-do-bot-1-3/luot-20261023-r3/api-calibration.json).

Công cụ: `cong-cu/lap-ban-do-bot-1-3.py`. Lượt `r5` thêm đối chứng lời
gọi, bằng chứng menu và phần nạp vốn đã dựng; giữ các lượt cũ. Lượt `r2` chỉ quét những địa
chỉ thực sự được gọi, đã loại các phép ép con trỏ `0/1` bị lượt `r1`
đếm nhầm là địa chỉ hàm. Lượt `r3` sửa mô tả các hàm tin theo chuỗi và lời gọi thực tế, thêm bằng chứng đối chứng API. Các lượt được giữ để kiểm lại cách lập danh sách.

Lượt `luot-20261024-r6` nối thêm nguồn và bằng chứng giờ theo
mùa, khối lượng hợp lệ, chọn cách khớp và chuẩn bị yêu cầu. Đã sửa mô
tả `0x2e6d0/0x3bb10`: đó là xử lý hàng đợi 100 lệnh chờ, không phải
chỉ tạo trường yêu cầu. Mã thao tác 2 đã nối với `Print` bằng chương
trình có nguồn. Các lượt cũ giữ nguyên, không sửa lại bằng chứng.

Lượt `luot-20261024-r7` nối thêm hàm gửi, bốn hàm thông báo
và chuỗi ghép tạo yêu cầu qua gửi. Đã sửa tên mô tả: bảng hàng đợi
ghi kết quả 0/1 thay vì vé; hàm `0x26060/0x31790` đổi loại lệnh,
`0x26360/0x31a90` định dạng giá, `0x336d0/0x3ee80` đổi mã lỗi.

Lượt `luot-20261024-r8` nối thêm nguồn/bằng chứng hàng đợi 100 lệnh,
thử lại và nội dung mã lỗi. Lượt `luot-20261024-r9` nối thêm
phép so chung hàng đợi→tạo→gửi→thông báo cho chín hàm của mỗi bot.
Còn kết quả nơi giao dịch, toàn EA và các giới hạn CPU/bộ nhớ;
không đánh dấu hai hàng P16/P31 hoặc toàn bộ bot là hoàn tất.

Lượt `luot-20261024-r10` nối thêm năm hàm quét/đếm/dọn bảng/
giới hạn và phép so chuỗi đặt lệnh r3 đã sửa kiểm số đối số thông báo
theo nhận xét Claude. Phần hủy đang ở bước phân tích; chưa có EA đầy đủ.

Lượt `luot-20261025-r3`: công cụ chỉ đổi bằng chứng của bốn
hàm quét/chọn vị thế sang lượt `position-selection-20261025-r3` (4.600
ca mỗi bot) và máy đo quá khứ `engine-position-selection-bN-r3`. Các
lượt cũ, gồm `luot-20261025-r1/r2`, giữ nguyên.

Lượt hiện hành `luot-20261025-r4`: công cụ nối bằng chứng hàm sửa vị
thế `0x26d20` / `0x32a90` (lượt `position-modify-20261025-r1`, máy đo
quá khứ `engine-modify-bN-r1`, nơi gọi `modify-callers-20261025-r1` và
[tổng kiểm](KIEM-CHUNG-SUA-VI-THE-BOT-1-3.json)), đổi mô tả vai trò của
hàm này. Các lượt cũ, gồm `luot-20261025-r1/r2/r3`, giữ nguyên.
