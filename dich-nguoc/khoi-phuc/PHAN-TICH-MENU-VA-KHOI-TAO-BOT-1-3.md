# Menu và nạp vốn khi khởi động — bot 1 và 3

Ngày 23/10/2026. Đã đọc cửa sổ cài đặt trong MT5 riêng và viết phần
nạp vốn sang MQL5. **Chưa có EA hoàn chỉnh, chưa đạt 100%.**

| Phần đã kiểm | Bot 1 | Bot 3 |
|---|---|---|
| Mặc định xuất trực tiếp từ MT5 | 72/72 dòng khớp phép đọc gốc trước đó | 80/80 dòng khớp |
| Nhãn nhìn thấy và thứ tự | 72 dòng | 80 dòng |
| Menu đã mở, nối số với tên | 3 menu, 11 lựa chọn | 4 menu, 17 lựa chọn |
| Địa chỉ gọi trực tiếp còn thiếu đã nối | 10/10 | 9/9 |
| MQL5 nạp vốn so với đoạn gốc | **616/616 ca khớp** | **616/616 ca khớp** |
| Biên dịch chương trình kiểm nạp vốn | 0 lỗi, 0 cảnh báo | 0 lỗi, 0 cảnh báo |

[Bản đồ r5](ban-do-bot-1-3/luot-20261023-r5/summary.json),
[bằng chứng menu](menu-bot-1-3/luot-20261023-r1/verified-menu.json),
[kiểm lại kết quả](KIEM-CHUNG-MENU-VA-KHOI-TAO-BOT-1-3.json).

## Các menu đã đọc

Đã chọn đúng EX5 chuẩn trong phần cài đặt máy thử, dùng `Defaults`, đọc
từng trang, mở từng menu. Để nối số với tên, nạp tệp chỉ thay giá trị
đang kiểm rồi đọc nhãn; **không bấm chạy máy thử** trong lượt đọc menu.

| Mục | Số lưu → tên hiển thị, đúng thứ tự menu |
|---|---|
| `BacktestSpeed`, cả hai bot | `1` → `normal`; `2` → `fast`; `3` → `ultra fast` |
| `FakeOutFilter`, cả hai bot | `0` → `OFF`; `1` → `Low`; `2` → `Medium`; `3` → `High` |
| `Risk`, bot 1 | `0` → `use StartLots`; `9999` → `use lotsizeStep`; `999` → `use Manual RiskPerTrade`; `3` → `use Max Risk Per Strategy` |
| `Risk`, bot 3 | `0` → `use StartLots`; `1234` → `Max Allowed Total Drawdown`; `3` → `Max Risk Per Strategy` |
| `TradeFrequency`, bot 3 | `0` → `extreme conservative`; `1` → `conservative`; `2` → `moderate`; `3` → `Intense`; `4` → `Extreme (high risk!)`; `5` → `Auto (based on balance and risk)`; `6` → `Manual strategy selection` |

Mặc định tốc độ là 1; bộ lọc là 1 ở bot 1, 2 ở bot 3; cách khối lượng
là 0 ở bot 1, 1234 ở bot 3; tần suất bot 3 là 5. Tệp MT5 xuất khớp đủ
152 dòng với phép đọc trước, kể cả dấu cách cuối cảnh báo của bot 3.

Mỗi lựa chọn trong JSON có tệp số và ảnh nhãn; mỗi dòng có ảnh trang.
Chỉ xác nhận nhãn nhìn thấy. Còn kiểu khai báo chính xác, tên kiểu do
tác giả đặt, ký tự bị ẩn/cuối nhãn dài, mọi phạm vi nhập và tác dụng
toàn bộ. Dòng thời gian dời dừng lỗ chỉ thấy đến `Seconds before the
real SL is pulled up to the virtual SL (0 =`; không tự bổ sung chữ.

## Lời gọi MT5 đã nối thêm

Chương trình có nguồn xuất 18 hàm nhỏ gắn tên riêng. Chỉ gọi `Anchor`
để nạp thư viện rồi đọc mã. Không thực thi các hàm xóa đối tượng/trạng
thái, hộp thông báo hoặc lịch tin. Hai nguồn kiểm biên dịch sạch; lượt
demo kết thúc bình thường và có báo cáo.

| Vị trí từ đầu máy MT5 | Lời gọi đối chứng |
|---|---|
| `0x380260` | `CalendarEventByCountry` |
| `0x3802f0` | `CalendarEventByCurrency` |
| `0x380440` | `CalendarValueHistoryByEvent` |
| `0x7b16a0` | `MessageBox` |
| `0x7b2230` | `TesterStatistics` |
| `0x7bdbe0` | `GlobalVariableGet` |
| `0x7bdc90` | `GlobalVariableSet` |
| `0x7bdda0` | `GlobalVariableCheck` |
| `0x7c4d40` | `ObjectsDeleteAll`, bản không lọc tiền tố |
| `0xacc3a0` | Hàm phụ bên trong thao tác `StringToLower` |

[Bằng chứng](doi-chung-mt5/api-bo-sung-20261023/api-extra-r2/calibration.json)
dùng đúng máy thử SHA-256 `5033d9d4…`. Đã nối hết địa chỉ trực tiếp còn
thiếu trong lần quét; chưa chứng minh mọi lời gọi gián tiếp hoặc tính năng.

Cuối hàm dừng bot 1, dòng C 14737 gọi `ObjectsDeleteAll(0,-1,-1)`:
xóa đối tượng trên biểu đồ hiện tại. Lượt này chỉ đọc, không thực thi
lệnh xóa. Ý nghĩa tham số: [tài liệu MT5](https://www.mql5.com/en/docs/objects/objectdeleteall).

## Nguồn nạp vốn và phép so

- [Bot1AccountInitialization.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1AccountInitialization.mqh).
- [Bot3AccountInitialization.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3AccountInitialization.mqh).

Đã phân tích trước đoạn `0x126c..0x1941` ở bot 1 và `0x1279..0x193f`
ở bot 3, cuối không tính. Nguồn giữ thứ tự:

1. Đọc số dư, rồi vốn gồm lời/lỗ đang mở nếu `UseEquity` bật.
2. Tạo `HighestBalance` nối số tài khoản. Nếu đặt lại, ghi 0 rồi chờ
   5.000 mili giây; đọc mục lưu, chọn vốn cao nhất theo phép so gốc và ghi lại.
3. Tạo `LastBalanceOp` nối số tài khoản, luôn kiểm mục đã có. Nếu không
   đặt lại và có mục thì nạp mốc cũ; còn lại lấy giờ hiện tại. Ghi lại mốc.
4. Sau cùng mới áp dụng `ManualBalance` khi lớn hơn 0.

Hai tên không thêm tên bot, mã giao dịch hay dấu phân cách. Không tự
đổi để tránh trùng. Cần kiểm tiếp khi ghép hai bot vào cùng tài khoản.

616 ca mỗi bot gồm ba số tài khoản (có số 64 bit lớn), đặt lại/bật vốn
gồm lời lỗ, mục lưu có/không có, vốn thấp/bằng/cao, vốn nhập tay và số
không hữu hạn. So cả hai giá trị vốn, **đúng chuỗi tên lưu**, mốc giờ
và thứ tự đọc/ghi/kiểm/chờ. MQL5 dùng hàm đổi số/chuỗi thật; tài khoản,
đồng hồ và kho lưu được cấp riêng, không ghi trạng thái thật của MT5.

| Bot | Kết quả MQL5 | Biên dịch |
|---|---|---|
| 1 | [616/616](bot-cua-toi-1/bang-chung/kiem-khoi-tao-von/init-state-check-20261023-r1/comparison.json) | `b1-initial-state-02` |
| 3 | [616/616](bot-cua-toi-3/bang-chung/kiem-khoi-tao-von/init-state-check-20261023-r1/comparison.json) | `b3-initial-state-01` |

Còn nội dung/định dạng thông báo, mã lỗi còn lưu, thiếu bộ nhớ, toàn bộ
hàm khởi tạo và ghép vào EA chính. Phép lưu thật qua hai lần mở MT5 ở
lượt trước có phạm vi riêng, không thay cho kiểm ghép toàn bộ.

## Lỗi đã sửa, bằng chứng giữ lại

- `api-extra-r1` bị bước kiểm nhật ký từ chối vì dòng `Anchor` có ở cả
  nhật ký máy thử và bản chuyển tiếp. Đã cho phép lặp đúng tên `Anchor`,
  vẫn chặn tên khác; chạy lại r2.
- Biên dịch đầu bot 1 lỗi tại dòng 80 vì biến tên `input` trùng từ khóa
  MQL5. Đổi thành `input_file`; nguồn lỗi/nhật ký giữ ở `b1-initial-state-01`.
  Hàm nạp vốn không đổi.
- Sau khi người dùng mở màn hình, đã đọc được menu. MT5 riêng được trả
  mặc định và đóng; không sửa MT5 chính.

Tiếp tục chốt kiểu/phạm vi nhập, khởi tạo chỉ báo/sự kiện và điều kiện
giao dịch. Danh sách 33 phần vẫn mở; số ca trên không phải tỷ lệ hoàn thành.
