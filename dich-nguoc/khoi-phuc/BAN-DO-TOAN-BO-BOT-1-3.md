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

Danh sách đầy đủ từng hàm và từng dòng cài đặt:

- [Bot 1](ban-do-bot-1-3/luot-20261023-r5/bot-1.md), [dữ liệu chi tiết](ban-do-bot-1-3/luot-20261023-r5/bot-1.json).
- [Bot 3](ban-do-bot-1-3/luot-20261023-r5/bot-3.md), [dữ liệu chi tiết](ban-do-bot-1-3/luot-20261023-r5/bot-3.json).
- [Biên nhận lập danh sách](ban-do-bot-1-3/luot-20261023-r5/summary.json).

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
khớp 7.724 ca phân tích với mã gốc; chưa có MQL5 mới cho phần này.
[Tám nhánh bật/tắt bot 1](PHAN-TICH-BAT-TAT-BOT-1.md) cũng đã khớp
đủ 256 tổ hợp, qua 2.048 lần kiểm nhánh.
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
| P04 | Chọn/bật/tắt chiến lược | `0x10f60` / `0xc30`, `0x17f00`; bảng 8/9 chiến lược | Đã so bảng cơ bản; bot 1 đã so tám nhánh qua đủ 256 tổ hợp, bot 3 đã so riêng hai đoạn chọn với 512 tổ hợp thủ công và các ngưỡng tự chọn. Còn ghép MQL5, nguồn trạng thái/cờ và quản lý vị thế khi chiến lược tắt |
| P05 | Tham số cơ bản và điều chỉnh theo giá | `0x7500` / `0xe0c0` | Đã so phần tính khoảng cách; đã nối lời tạo ATR, chưa phục hồi đủ việc đọc và xử lý lỗi chỉ báo |
| P06 | Điều chỉnh thêm và tạo biến thiên | Các nhánh trong `0x10f60` / `0x17f00`, `Randomization`, `Adjust*` | Cần công thức, thứ tự sinh số và trạng thái qua các lần chạy |
| P07 | Dữ liệu thị trường và nến mới | `0xc30`, `0x18aa0` / `0xc30`, `0x20ef0`; `iTime`, `Bars`, tick | Cần thiếu dữ liệu, đổi nến, đổi ngày và nhiều khung nến |
| P08 | Tìm đỉnh/đáy làm mức giá | `0x32890`, `0x32ac0` / `0x3e040`, `0x3e270` | Đã so hai hàm; còn ghép đúng nơi gọi |
| P09 | Xác nhận mức chưa bị phá | `0x265a0`, `0x26960` / `0x31cd0`, `0x32090` | Đã so phần; còn điều kiện cấp tham số từ toàn bộ chiến lược |
| P10 | Chặn lệnh chờ gần mức dự kiến | `0x3c670`, `0x3c8d0` / `0x47380`, `0x475e0` | Đã so phần; còn ghép cùng giá đặt cuối cùng |
| P11 | Toàn bộ điều kiện cho phép vào | `0x18aa0` / `0x20ef0` | Cần bảng nhánh đầy đủ cho từng chiến lược và từng chiều |
| P12 | Tính khối lượng và các chế độ rủi ro | `0x34780` / `0x3f900` | Đã so phần; các giá trị cấp từ chương trình chính chưa đủ |
| P13 | Đổi tiền tài khoản và cặp giá | `0x36220`, `0x47d20` / `0x8300`, `0x41780` | Đã so hai chiều và ghép; còn nạp đuôi mã lúc khởi tạo |
| P14 | Vốn cao nhất, rút tiền và lưu trạng thái | `0x173f0`, `0xc30` / `0x1fd00`, `0xc30` | Đã so cập nhật/ghi-đọc, tên mục và nạp lại trong đoạn khởi tạo; còn ghép toàn bộ, mã lỗi/thông báo và kiểm cùng tài khoản |
| P15 | Kiểm khối lượng hợp lệ và ký quỹ | `0x3bfe0`, `0x3cb30`, `0x457d0` / `0x46ca0`, `0x47840`, `0x53670` | Đã so kiểm ký quỹ; hàm kiểm bước/min/max còn phải dựng |
| P16 | Tạo/gửi yêu cầu giao dịch | `0x950`, `0x2e6d0`, `0x32dd0` / `0x950`, `0x3bb10`, `0x3e580` | Cần đủ trường yêu cầu, loại lệnh, cách khớp, kết quả, đồng bộ/bất đồng bộ |
| P17 | Quét, nhận dạng và đếm lệnh/vị thế | Các hàm nhóm `0x2f5c0..0x32ce0` / `0x3ca00..0x3e490` | Cần nhận dạng chiến lược/mã giao dịch, thứ tự, vé 0 và giới hạn số lệnh |
| P18 | Sửa/hủy lệnh chờ và vùng cấm sửa | `0x30320`, `0x34150` / `0x32450`, `0x3d650` | Cần điều kiện giá, chọn lệnh, trường yêu cầu và xử lý thất bại |
| P19 | Hết hạn thật và tự quản lý hết hạn | Tham số ở `0x7500` / `0xe0c0`, nơi dùng trong chiến lược | Đã so cách tính thời hạn; chưa toàn bộ việc hủy khi đến hạn |
| P20 | Dừng lỗ/chốt lời sau khớp | `0x271f0`, `0x2abc0` / `0x32f60`, `0x37590` | Cần cả hai chiều, đặt sau khớp và kết quả sửa |
| P21 | Dời dừng lỗ/chốt lời, hòa vốn, phục hồi theo thời gian | Cùng hai hàm quản lý vị thế và các `UseHL*`, `AdjustTrail*` | Cần từng chế độ, giá kích hoạt, giới hạn và thử lại |
| P22 | Dừng/chốt ảo và chờ chuyển thành lệnh thật | `0x3d200`, `0x3d5a0`, `0x3d640` / `0x47f10`, `0x482b0`, `0x484c0`, `0x48560` | Cần các bảng theo vé, đầy bảng, vé đã đóng và khởi động lại |
| P23 | Đóng vị thế và xóa theo bộ lọc | `0x3d010`, các hàm quét / `0x47d20`, các hàm quét | Cần mã giá, khoảng cấm sửa/đóng, cả hai chiều và lỗi |
| P24 | Giới hạn lỗ ngày/tổng và vốn | `0x10f60`, `0x18aa0`, `0x1efa0` / `0x17f00`, `0x20ef0`, `0x2a1c0` | Cần phép tổng hợp, thời điểm đặt lại và hành động khi chạm giới hạn |
| P25 | Giờ giao dịch, thứ Sáu và phiên của nơi giao dịch | Hàm chiến lược, các hàm giờ, chuỗi `[SESSIONS]` | Cần các mốc, đổi ngày, lịch phiên và trường hợp không có phiên |
| P26 | Giờ UTC và đổi giờ theo mùa | `0x17840`, `0x17d20` / `0x7e20`, `0x20150` | Cần tự nhận giờ qua HTTP, phương án thay thế, giá trị nhập tay và lỗi |
| P27 | NFP, lãi suất và CPI | Nhóm `0x61b0..0x7310` / `0x6ad0..0x7c30`, chuỗi lỗi/lịch | Cần lịch MT5, lịch có sẵn thay thế, khoảng chặn, hủy/đóng và dữ liệu thiếu |
| P28 | Lịch sử/tệp dữ liệu tin | Bot 3 có chuỗi `newshist.csv`, `news.csv` tại phần khởi tạo/hủy | Cần xác định đường đọc thật, nhánh có sử dụng và dữ liệu đi kèm; chưa khẳng định tính năng đang bật |
| P29 | Bảng thông tin, nhãn và thao tác biểu đồ | `0x8320`, `0xe1b0`, `0xffb0`, `0x45b70`, `0x47740` / `0xef40`, `0x14fa0`, `0x16e80`, `0x53a10`, `0x555e0` | Cần từng đối tượng, nội dung, màu/cỡ chữ, vị trí và hành vi hiển thị khi đo lại quá khứ |
| P30 | Điều kiện tài khoản/dùng chương trình và HTTP phụ | `0x5880`, `0x3d6c0`, `0x4d260` / `0x61a0`, `0x485e0`, `0x55bc0` | Cần phân biệt điều kiện giao dịch với kiểm quyền dùng; không sửa để vượt khóa/giới hạn |
| P31 | Thông báo, mã lỗi, thử lại và bộ nhớ | Hàm gửi/định dạng, các hàm phụ trợ đầu bảng | Cần đủ mã lỗi, thử lại, dữ liệu thiếu và dọn khi dừng; phép kiểm cũ có loại nội dung thông báo khỏi phạm vi |
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

Có thể nhờ Claude kiểm độc lập một phần của bảng. Chưa có đánh giá
Claude thành công ở các lượt trước, nên không dùng làm dấu xác nhận.
Các đánh giá mới, nếu có, phải lưu kèm và kiểm lại với chứng cứ gốc.
Lượt kiểm phương pháp cài đặt bị Claude từ chối với nhãn `[cyber]`;
[biên nhận](../.local/bot1-3-inputs-20261023/claude-method-review/run.json).
Không dùng phản hồi này làm xác nhận độc lập.

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
