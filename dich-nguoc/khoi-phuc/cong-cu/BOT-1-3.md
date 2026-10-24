# Công cụ phân tích bot 1 và 3

Chạy từ thư mục dự án. Mỗi lượt dùng tên mới để giữ bằng chứng cũ.

## Hàng đợi và nội dung lỗi

- `kiem-chuoi-loi-bot-1-3.py MODE BOT RUN [--build BUILD]`: dùng
  `analyze` trước khi viết nguồn, rồi `prepare` → biên dịch
  `BotNTradeErrorsCheck.mq5` → `mql5` → `original` → `compare`.
  Lượt `errors-20261024-r3`, bản `bN-trade-errors-02`: 5.826 ca.
  Kiểm cả miền mã -1..4207, kiểu số đã đối chứng, tăng đếm trước chép
  và nối mã kiểm tra nguồn/biên dịch/chạy. Chuỗi cũ chỉ kiểm ở mã gốc.
- `kiem-hang-doi-bot-1-3.py MODE BOT RUN [--build BUILD]`: theo thứ
  tự `prepare` → biên dịch `BotNPendingQueueCheck.mq5` → `mql5` →
  `original` → `compare`. Lượt `queue-20261024-r3`, bản
  `bN-pending-queue-03`: 374 ca. So đủ hai bảng, dữ liệu và lời gọi;
  kết quả tạo lệnh/chờ/in được cấp sẵn. Không giao dịch.
- `kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --queue-run RUN --build BUILD`:
  chạy cùng nguồn và thân bộ kiểm trong máy đo quá khứ. Chỉ đổi sự
  kiện chạy và tên tệp đầu vào; các lời gọi gửi/chờ vẫn được thay.
  Lượt `engine-b1-r3`, `engine-b3-r3` đều khớp 374 ca, 0 lỗi/cảnh báo.
- `do-phep-tru-mt5.py NEW_RUN [--probe queue-native-r2]`: đo 25 cặp
  số bằng thư viện có nguồn đã chụp, gồm các dạng `NaN`; ghi từng bit
  bằng số nguyên. Lượt `arithmetic-runtime-r2` đo thêm cộng/nhân.
- `kiem-chung-hang-doi-bot-1-3.py NEW_JSON`: kiểm lại nguồn, bằng
  chứng và bản biên dịch của hai phần; chạy lại mã máy hàng đợi với
  các công cụ hiện hành để kiểm thêm sự phụ thuộc. Không mở MT5.

Chạy lần lượt các lệnh cần MT5 riêng. Không ghi đè lượt cũ. Nguồn
hàng đợi gọi hàm thật; phần thay lời gọi chỉ có trong chương trình
kiểm. [Giới hạn](../PHAN-TICH-HANG-DOI-BOT-1-3.md).

## Gửi lệnh, thông báo và ghép tạo yêu cầu

- `kiem-gui-lenh-bot-1-3.py MODE BOT RUN [--build BUILD]`: hàm gửi
  `0x950` cùng các hàm thông báo yêu cầu/kết quả/loại/giá.
  Biên dịch `BotNTradeSendCheck.mq5`; lượt đạt `send-20261024-r3`,
  `bN-trade-send-03`, 1.201 ca mỗi bot.
- `kiem-ghep-dat-lenh-cho-bot-1-3.py MODE BOT RUN [--build BUILD]`:
  chạy liên tục hàm tạo yêu cầu qua gửi/thông báo đến khi trả về,
  không dừng trước hàm gửi. Biên dịch `BotNOpenPendingCheck.mq5`;
  lượt đạt `open-pending-20261024-r1`, `bN-open-pending-01`, 1.687 ca.
- `kiem-chung-gui-lenh-bot-1-3.py NEW_JSON`: kiểm lại mã tệp bằng
  chứng, nguồn hiện hành, biên nhận biên dịch, sơ đồ trường và kiểm
  bổ sung vùng lưu; tạo biên nhận mới trong `khoi-phuc`, không mở MT5.

Với hai công cụ đầu, `MODE` theo thứ tự `prepare` → biên dịch →
`mql5` → `original` → `compare`. Bước `mql5` bắt buộc chỉ đúng biên
nhận bằng `--build`. Chạy lần lượt hai bot vì dùng chung MT5 riêng.
Các hàm gửi trong chương trình kiểm được thay bằng kết quả định sẵn;
không gửi lệnh. Việc định dạng số/chuỗi dùng MT5 thật, mã gốc phải gọi
đúng đối số, kiểu và thứ tự đã đo. Nguồn giao dịch chính dùng lời gọi
MT5 trực tiếp; không mang hàm thay thế của bộ kiểm vào nguồn chính.

Công cụ ghép có thêm `audit BOT RUN`: chạy lại mã gốc với kiểm toàn
bộ 628 byte lưu trong lớp và kiểm lại sơ đồ; so với kết quả cũ rồi
ghi `native-storage-audit.json` mới. Không ghi đè kết quả cũ và chưa
so byte đệm riêng của MQL5. [Phạm vi](../PHAN-TICH-GUI-LENH-BOT-1-3.md).

| Công cụ | Đầu vào và kết quả |
|---|---|
| `chay-chup-bot-1-3.py BOT RUN` | Chạy EX5 gốc trong MT5 riêng, chụp mã/dữ liệu, lưu nhật ký. Chỉ dùng tài khoản demo đã được phép. Dừng nếu lượt máy thử chưa hoàn tất; bản chụp có kết quả riêng. |
| `chup-bot-1-3.py --bot BOT --pid PID --out NEW_PATH ...` | Gọi bộ đọc đã có, vẫn kiểm đúng tiến trình máy thử riêng và đường dẫn đầu ra. |
| `tao-ho-so-ma-chup.py BOT CAPTURE ENGINE_JSON OUT` | Kiểm mã tệp, đọc bảng hàm và chuỗi có tiêu đề hợp lệ, chuẩn bị dữ liệu Ghidra. |
| `xuat-ma-day-du.ps1 -Metadata PATH -Ghidra PATH -Java PATH` | Nạp mã, dữ liệu và các nhãn MT5 đã đo; xuất C trung gian. |
| `xuat-ma-chup.ps1 -Bot BOT -Run NAME -Ghidra PATH -Java PATH` | Đọc nhanh bản chụp cũ. Dữ liệu cũ thiếu hằng nên kết quả kém hơn lượt mới. |
| `ghidra/ExportOneFunction.java ADDRESS OUTPUT TIMEOUT` | Xuất riêng một hàm khó từ dự án Ghidra đã có. |
| `kiem-muc-gia-bot-1-3.py MODE BOT RUN` | Tạo ca kiểm, chạy đoạn mã gốc, chạy MQL5 và so kết quả hai hàm mức giá. |
| `kiem-gia-vao-bot-1-3.py MODE BOT RUN` | Kiểm lệnh chờ gần, mức giá chưa bị phá và bảng tham số gốc. Cùng bốn chế độ ở dưới; dùng script `BotNEntryLevelsCheck.mq5`. |
| `kiem-tham-so-goc-bot-1-3.py --bot BOT` | Chạy các đoạn gán tham số trong mã máy, đối chiếu 6 giá trị mỗi chiến lược; không chạy toàn bộ chiến lược. Không ghi đè kết quả đã có. |

`MODE` lần lượt là `prepare`, `original`, `mql5`, `compare`.
Biên dịch script trước bước `mql5` bằng `bien-dich.ps1 -Bot BOT -Terminal MT5
-Run NAME -Source SCRIPT_PATH`. Ví dụ bot 1:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-muc-gia-bot-1-3.py prepare 1 gia-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-muc-gia-bot-1-3.py original 1 gia-moi
& dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1 -Bot 1 -Terminal 'dich-nguoc/.local/claude-recovery-20261023/mt5' -Run b1-gia-moi -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1PriceLevelsCheck.mq5'
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-muc-gia-bot-1-3.py mql5 1 gia-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-muc-gia-bot-1-3.py compare 1 gia-moi
```

Nếu thư mục `MQL5/Files/bot1-price-levels` hoặc `bot3-price-levels` còn
tệp của lượt trước, công cụ dừng để tránh ghi đè. Sau khi xác nhận bản
sao trong `bang-chung/kiem-muc-gia/RUN/` đầy đủ, chỉ dọn hai tệp
`cases.bin`, `mql5-results.bin` và thư mục riêng của bộ kiểm rồi chạy lại.

Ghidra không nhận đường dẫn dự án có thành phần bắt đầu bằng dấu chấm,
nên dự án làm việc nằm tại `khoi-phuc/tam-bot1-3-20261023/`.

`ExportEx5Code.java` được thêm đối số thứ tư để đặt thời gian xử lý mỗi
hàm; mặc định cũ 20 giây được giữ nguyên. Lượt mới dùng 120 giây, hàm
riêng của bot 3 dùng 300 giây.

Các lượt máy thử dài ban đầu chưa kết thúc bình thường. Bộ chạy đã được
bổ sung kiểm tra báo cáo hoàn tất và dọn đúng tiến trình được ghi nhận;
phần bổ sung này mới kiểm cú pháp, chưa chạy lại lượt máy thử dài.

Phạm vi kết luận: [PHAN-TICH-BOT-1-3.md](../PHAN-TICH-BOT-1-3.md).

## Bộ kiểm phần vào lệnh

Nguồn chính: `BotNEntryLevels.mqh`, `BotNEntryProfiles.mqh` (thay N bằng
1 hoặc 3). Biên dịch `BotNEntryLevelsCheck.mq5` trước bước `mql5`.
Tên lượt mới tạo thư mục riêng dưới `MQL5/Files/botN-entry-levels/RUN/`,
nên có thể giữ lại dữ liệu các lượt trước.

Script yêu cầu `CheckRun` rõ ràng; nếu thiếu thì dừng trước khi ghi tệp.
Công cụ truyền tên lượt qua `ScriptParameters` trong thư mục
`MQL5/Presets`, theo [hướng dẫn khởi động của MT5](https://www.metatrader5.com/en/terminal/help/start_advanced/start).

Lượt mới nhất đã kiểm: `entry-20261023-r3`, bản biên dịch
`b1-entry-levels-04` và `b3-entry-levels-04`. Script trả mã hoàn tất rõ
ràng qua `int OnStart()`; công cụ từ chối kết quả nếu MT5 thoát khác 0.

Các dòng không có trường dữ liệu trong `noi-tham-so-muc-gia.json` là lời
gọi khởi tạo, không tính thành bảng chiến lược. `kiem-tham-so-goc.json`
chỉ ghi những bảng đã chạy đoạn gán và so khớp.

## Bộ kiểm điều chỉnh khoảng cách

Nguồn: `BotNDistanceSettings.mqh`, `BotNBaseDistances.mqh`; chương trình
kiểm là `BotNDistanceSettingsCheck.mq5`. Bảng cơ bản dùng khi phần điều
chỉnh thêm và ngẫu nhiên bằng 0. Phạm vi: [báo cáo](../PHAN-TICH-DIEU-CHINH-BOT-1-3.md).

Hai công cụ mới:

- `kiem-bang-khoang-cach-bot-1-3.py BOT RUN`: chạy các đoạn gán trong mã
  máy, lấy bảng cơ bản; dừng nếu đọc thanh ghi chưa xác định hoặc ghi đè
  bằng chứng. Bảng bot 1 gồm hai chế độ dời dừng lỗ.
- `kiem-dieu-chinh-bot-1-3.py MODE BOT RUN`: tạo ca, chạy nguyên hàm
  chuẩn bị gốc, chạy MQL5, rồi so các giá trị đã liệt kê và bảng cơ bản.

Chạy theo thứ tự, mỗi lượt dùng tên mới:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-bang-khoang-cach-bot-1-3.py 1 settings-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-dieu-chinh-bot-1-3.py prepare 1 settings-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-dieu-chinh-bot-1-3.py original 1 settings-moi
& dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1 -Bot 1 -Terminal 'dich-nguoc/.local/claude-recovery-20261023/mt5' -Run b1-settings-moi -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1DistanceSettingsCheck.mq5'
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-dieu-chinh-bot-1-3.py mql5 1 settings-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-dieu-chinh-bot-1-3.py compare 1 settings-moi
```

Thay các số bot/tên nguồn tương ứng để kiểm bot 3. Chạy lần lượt hai
chương trình MQL5 vì dùng chung MT5 riêng. Trước khi biên dịch, kiểm
đường dẫn đích vẫn nằm trong MT5 riêng và không phải đường dẫn liên kết.

Lượt hiện hành: `settings-20261023-r2`; biên dịch
`b1-distance-settings-02`, `b3-distance-settings-02`. Lượt `r1` giữ lại
để đối chiếu bước đầu. Hai lượt đều chạy mã gốc và MQL5; không dùng lại
kết quả gốc giữa hai bộ ca khác nhau.

## Bộ kiểm khối lượng và đổi tiền tệ

| Công cụ | Phạm vi |
|---|---|
| `kiem-khoi-luong-bot-1-3.py MODE BOT RUN` | Hàm khối lượng; kết quả đổi tiền được cấp sẵn. |
| `kiem-doi-tien-bot-1-3.py MODE BOT RUN` | Hai chiều đổi tiền; so kết quả và mã kiểm tra thứ tự đọc giá. |
| `kiem-khoi-luong-ghep-bot-1-3.py MODE BOT RUN` | Hàm khối lượng cùng các hàm đổi tiền gốc; không cấp sẵn kết quả đổi tiền. |

`MODE` vẫn theo thứ tự `prepare`, `original`, `mql5`, `compare`.
Biên dịch chương trình kiểm tương ứng trước bước `mql5`:

- `BotNVolumeCheck.mq5` cho khối lượng riêng.
- `BotNCurrencyCheck.mq5` cho đổi tiền riêng.
- `BotNAccountVolumeCheck.mq5` cho phần ghép.

Lượt ghép hiện hành là `account-volume-20261023-r1`, biên dịch
`b1-account-volume-01` và `b3-account-volume-01`. Ví dụ bot 1:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-khoi-luong-ghep-bot-1-3.py prepare 1 account-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-khoi-luong-ghep-bot-1-3.py original 1 account-moi
& dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1 -Bot 1 -Terminal 'dich-nguoc/.local/claude-recovery-20261023/mt5' -Run b1-account-moi -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1AccountVolumeCheck.mq5'
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-khoi-luong-ghep-bot-1-3.py mql5 1 account-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-khoi-luong-ghep-bot-1-3.py compare 1 account-moi
```

Phần ghép đang tắt bước đọc lịch sử rút tiền; chưa kiểm ký quỹ hoặc đặt
lệnh. [Báo cáo đầy đủ](../PHAN-TICH-KHOI-LUONG-BOT-1-3.md) ghi rõ các giới hạn.

## Bộ kiểm cập nhật vốn sau khi rút tiền

- `kiem-rut-tien-bot-1-3.py MODE BOT RUN`: so trạng thái và mã kiểm tra
  thứ tự đọc thời gian/lịch sử/ghi dữ liệu với hàm gốc.
- `kiem-luu-trang-thai-bot-1-3.py BOT RUN`: ghi hai giá trị bằng hàm đã
  dựng, đóng MT5 riêng, mở lại để đọc; dọn đúng hai mục tạm vừa tạo.

Biên dịch `BotNWithdrawalCheck.mq5` trước bước `mql5` của công cụ đầu.
Biên dịch `BotNWithdrawalStorageCheck.mq5` trước công cụ thứ hai.
`MODE` vẫn là `prepare`, `original`, `mql5`, `compare`; mỗi lượt tên mới.

Lượt đối chiếu hiện hành: `withdrawal-20261023-r1`, biên dịch
`b1-withdrawal-02` và `b3-withdrawal-01`. Lượt lưu thật:
`storage-20261023-r1`, biên dịch `b1-withdrawal-storage-01` và
`b3-withdrawal-storage-01`. Chạy lần lượt vì dùng chung MT5 riêng.

Nguồn kiểm lưu thật chỉ cấp lịch sử mẫu; việc ghi/đọc trạng thái dùng
hàm thật của MT5. Tên mục có tiền tố riêng theo bot và tên lượt, tối đa
40 ký tự cho tên lượt; dừng nếu tên đã tồn tại trước pha ghi.
[Báo cáo](../PHAN-TICH-RUT-TIEN-BOT-1-3.md) ghi rõ phần chưa ghép vào EA.

## Bản đồ trước khi viết tiếp

Đọc [AGENTS.md](../../../AGENTS.md) và [bản đồ toàn bộ](../BAN-DO-TOAN-BO-BOT-1-3.md)
trước khi viết thêm phần giao dịch. Công cụ `lap-ban-do-bot-1-3.py NEW_DIR`
liệt kê mọi hàm trong bảng đã chụp, toàn bộ dòng cài đặt đã quan sát,
lời gọi, chuỗi, chỗ chưa rõ và liên kết bằng chứng. Thư mục đích phải
mới và nằm trong `khoi-phuc`; không sửa EX5 hoặc mã trung gian.

Lượt hiện hành: `ban-do-bot-1-3/luot-20261024-r8/`. Danh sách không tự
khẳng định toàn bộ EX5 đã được phân tích hoặc mọi cài đặt đã được nối.

## Hai bộ kiểm đã hoàn tất trước khi chuyển sang rà bản đồ

- `kiem-luong-von-day-du-bot-1-3.py MODE BOT RUN`: chạy luồng vốn gốc
  cùng phần rút tiền/đổi tiền; so thêm trạng thái số trước lỗi chia 0.
  Biên dịch `BotNAccountStateVolumeCheck.mq5` trước bước `mql5`.
- `kiem-ky-quy-bot-1-3.py MODE BOT RUN`: hai hàm kiểm tiền ký quỹ và bộ
  chặn vốn. Biên dịch `BotNMarginCheck.mq5` trước bước `mql5`.

`MODE` là `prepare`, `original`, `mql5`, `compare`; dùng tên lượt mới.
Lượt vốn: `state-volume-20261023-r1`, bản biên dịch `bN-state-volume-01`.
Lượt ký quỹ: `margin-20261023-r2`, bản biên dịch `bN-margin-02`.
[Phạm vi và giới hạn](../PHAN-TICH-LUONG-VON-VA-KY-QUY-BOT-1-3.md).

## Phân tích toàn bộ cài đặt đã thấy

`phan-tich-cai-dat-bot-1-3.py MODE BOT RUN [--case CASE]`:

- `prepare`: tạo kế hoạch vị trí lưu cần kiểm và 7 ca ban đầu.
- `extend`: thêm 2 ca đổi giá trị chế độ vào tệp riêng, không sửa kế hoạch cũ.
- `capture --case CASE`: chạy EX5 gốc trong máy thử demo riêng, đọc
  mã/dữ liệu và so chuỗi, chờ nhật ký rồi dừng đúng tiến trình đã ghi nhận.
- `compare`: đọc đủ các bản chụp, nhật ký cuối và đầu vào yêu cầu để so
  từng mục. Từ chối thiếu ca hoặc ghi đè kết quả có sẵn.
- `audit --case CASE`: chỉ dùng khi đã có bản chụp và nhật ký đầy đủ
  nhưng bước dọn báo tiến trình đã thoát. Kiểm lại bằng chứng, không
  suy ra mã thoát cũ; máy thử riêng phải đang tắt.

Ví dụ tạo lượt mới và thu một ca:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/phan-tich-cai-dat-bot-1-3.py prepare 1 inputs-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/phan-tich-cai-dat-bot-1-3.py extend 1 inputs-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/phan-tich-cai-dat-bot-1-3.py capture 1 inputs-moi --case defaults
```

Thu tiếp `bits-0` đến `bits-5`, `options-low`, `options-high`, lần lượt
vì dùng chung máy thử. Sau đủ 9 ca mới chạy `compare`. Kết quả nằm ở
`bot-cua-toi-N/bang-chung/phan-tich-cai-dat/RUN/`. Không dùng đây làm
phép so giao dịch; chỉ chốt cách lưu/giá trị và thứ tự trong nhật ký.
Lượt hiện hành: bot 1 `inputs-20261023-r2`, bot 3 `inputs-20261023-r3`.
[Danh sách và giới hạn](../PHAN-TICH-CAI-DAT-BOT-1-3.md).

## Phân tích đoạn chọn chiến lược bot 3

`phan-tich-chon-chien-luoc-bot-3.py NEW_RUN` chạy hai đoạn chọn gốc
trong bộ mô phỏng, không mở MT5 hoặc sửa EX5. Kết quả ở
`bot-cua-toi-3/phan-tich/chon-chien-luoc/NEW_RUN/`: lệnh gốc, từng ca
và tóm tắt có mã kiểm tra. Cấp sẵn số dư/kết quả đổi tiền; dừng nếu
ghi ngoài vùng trạng thái đã biết. Không phải phép so với MQL5.

Lượt hiện hành: `select-20261023-r1`, 7.724/7.724 ca khớp; gồm đủ 512
tổ hợp thủ công ở cả hai đoạn. [Phạm vi](../PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md).

## Bộ kiểm nguồn chọn chiến lược MQL5

`kiem-chon-chien-luoc-bot-1-3.py MODE BOT RUN` dùng lại đúng các ca gốc
đã kiểm để so nguồn mới. `Bot1StrategySelection.mqh` khớp 256 ca; có thể
chạy `Bot1StrategySelectionCheck.mq5`. `Bot3StrategySelection.mqh` khớp
7.724 ca; có thể chạy `Bot3StrategySelectionCheck.mq5`.

Ví dụ:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-chon-chien-luoc-bot-1-3.py prepare 1 strategy-moi
& dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1 -Bot 1 -Terminal 'dich-nguoc/.local/claude-recovery-20261023/mt5' -Run b1-strategy-moi -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1StrategySelectionCheck.mq5'
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-chon-chien-luoc-bot-1-3.py mql5 1 strategy-moi --build b1-strategy-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-chon-chien-luoc-bot-1-3.py compare 1 strategy-moi
```

Đổi `1` và tên nguồn tương ứng để kiểm bot 3. Bộ kiểm chỉ so cờ, chế độ
và hệ số của phần chọn; không chứng minh toàn bộ EA. Lượt hiện hành là
`strategy-20261024-r2`, bản dựng `b1-strategy-selection-02` và
`b3-strategy-selection-02`. Kết quả mong đợi lấy thẳng từ kết quả mã gốc
đã có mã băm và cờ kiểm đạt; không lấy từ bảng luật phân tích.

## Phân tích tám nhánh bật/tắt bot 1

`phan-tich-bat-tat-bot-1.py NEW_RUN` tìm các nhánh từ bảng tham số đã
kiểm và vị trí cài đặt đã nối, rồi chạy đủ 256 tổ hợp. Theo dõi từng
lệnh để dừng trước khi vào thân chiến lược hoặc nhảy sang chiến lược
sau; không mở MT5 hay gọi hàm giao dịch. Kết quả ở
`bot-cua-toi-1/phan-tich/bat-tat-chien-luoc/NEW_RUN/`.

Lượt hiện hành: `enable-20261023-r3`, 2.048 lần kiểm nhánh khớp.
Lượt r2 giữ bằng chứng lỗi điểm dừng, không dùng làm kết quả đạt.
[Phạm vi](../PHAN-TICH-BAT-TAT-BOT-1.md).

Kiểm lại ngày 24/10 sau đánh giá Claude: `enable-20261024-r1` thêm chặn
mọi lần ghi bộ nhớ trong cổng; `select-20261024-r2` theo dõi cả lệnh
nhảy ra ngoài đoạn, chỉ cho qua hai lời gọi được cấp sẵn. Cả hai cho
tệp kết quả giống từng byte với lượt cũ: 2.048 nhánh và 7.724 ca khớp.

## Bộ kiểm khối lượng hợp lệ

`kiem-khoi-luong-hop-le-bot-1-3.py MODE BOT RUN [--build BUILD] [--case ID]`:

- `prepare`: kiểm SHA-256 EX5 chuẩn, tạo đầu vào và tệp mô tả số dạng
  hex để giữ đúng cả `NaN`/vô hạn trong JSON hợp lệ.
- `original`: chạy nguyên hàm gốc, ghi kết quả, thứ tự đọc dữ liệu,
  tiền tố/tham số thông báo; giữ riêng lỗi chia 0, không đổi lỗi thành
  kết quả từ chối.
- `mql5 --build BUILD`: kiểm nguồn/EX5 theo biên nhận, chạy các ca gốc
  trả kết quả bình thường trong MT5 riêng.
- `faults --build BUILD`: chạy từng ca gây chia 0 qua từng lần mở MT5.
  Kiểm nhật ký lỗi, số byte kết quả còn dang dở và các lần đọc trước lỗi.
  Dùng `--case ID` để chọn một ca. Lượt lỗi chưa đạt không được dùng lại.
- `compare`: so cả ca bình thường và ca lỗi; thiếu một ca lỗi cũng
  không cho kết luận đạt.

Biên dịch `BotNVolumeValidationCheck.mq5` trước bước `mql5`/`faults`.
Lượt hiện hành: `volume-validation-20261024-r5`, bản dựng
`b1-volume-validation-04` và `b3-volume-validation-04`. Lượt r5 dùng lại
đúng kết quả gốc r3 vì đầu vào giống từng byte; có biên nhận riêng.
[Phạm vi và các lượt chưa đạt](../PHAN-TICH-KHOI-LUONG-HOP-LE-BOT-1-3.md).

## Kiểm chọn cách khớp lệnh

`kiem-kieu-khop-lenh-bot-1-3.py MODE BOT RUN [--build BUILD]`, với
`MODE`: `prepare`, `original`, `mql5`, `compare`. Đầu vào ở
`bot-cua-toi-N/bang-chung/kiem-kieu-khop-lenh/RUN/`. `mql5` bắt buộc
biên dịch `BotNFillingCheck.mq5` trước và truyền đúng `--build`.
Lượt `filling-20261024-r1`, hai bản `b1-filling-01`, `b3-filling-01`
khớp 3.096 ca mỗi bot. Chỉ cấp dữ liệu thuộc tính mã giá, không gửi
lệnh; chặn mọi lần ghi biến chung ngoài 4 trường đã biết.
[Phạm vi](../PHAN-TICH-KIEU-KHOP-LENH-BOT-1-3.md).

## Kiểm bước chuẩn bị yêu cầu lệnh chờ

`kiem-tao-yeu-cau-cho-bot-1-3.py MODE BOT RUN [--build BUILD]`, với
`MODE`: `prepare`, `original`, `mql5`, `compare`. Biên dịch nguồn kiểm
`BotNPendingRequestCheck.mq5`, rồi truyền biên nhận qua `--build`.
Đầu ra ở `bot-cua-toi-N/bang-chung/kiem-tao-yeu-cau-cho/RUN/`.
Lượt `pending-20261024-r2`, bản `bN-pending-request-01`: 1.607 ca mỗi
bot khớp. Lượt `pending-protection-20261024-r1`: 16 ca bổ sung khớp.

Bộ kiểm chặn mã gốc ngay trước hàm gửi `0x950`, kiểm đủ 35 trường đã
đo bằng nguồn biết trước, số nhận diện/cách khớp và thứ tự lời gọi.
`true` chỉ nghĩa là tới bước gửi; không hề gửi lệnh trong lượt này.
Lượt bot 1 `pending-20261024-r1` lỗi khởi tạo bố cục trong lớp, giữ
bằng chứng riêng, không dùng làm kết quả đạt.

`kiem-thu-tu-truong-lenh.py <thư mục lượt đối chứng>` đọc bản chụp đã
kiểm mã băm, đối chiếu đủ 35 giá trị đánh dấu và ghi `trade-layout.json`.
Lượt trong lớp: `doi-chung-mt5/thu-tu-truong-lenh-class-20261024/layout-class-r1`.
Các biến đứng riêng có khoảng đệm khác, không được dùng nhầm khoảng
cách giữa chúng cho trường trong lớp.

## So chung chuỗi đặt lệnh

`kiem-chuoi-dat-lenh-bot-1-3.py MODE BOT RUN [--build BUILD]` chạy
hàng đợi cùng thân tạo yêu cầu, chọn cách khớp, gửi và thông báo gốc.
Thứ tự: `prepare` → biên dịch `BotNPendingPipelineCheck.mq5` →
`mql5` → `original` → `compare`. Dùng tên lượt/bản biên dịch mới;
hai lần chạy MQL5 thực hiện lần lượt trong MT5 riêng. Đầu ra ở
`bot-cua-toi-N/bang-chung/kiem-chuoi-dat-lenh/RUN/`.

`kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN
--build BUILD --pipeline` chạy lại đúng thân kiểm trong máy đo quá
khứ. Bản thử chỉ đổi sự kiện, đường đầu vào và đường nạp tệp hỗ trợ.
Không gửi lệnh thật. Đầu ra ở
`doi-chung-mt5/chuoi-dat-lenh-20261024/NEW_RUN/`. Bỏ `--pipeline`
thì giữ cách kiểm hàng đợi riêng trước đây với `--queue-run`.

Lượt đạt `pipeline-20261024-r2`, bản biên dịch
`b1-pending-pipeline-02`/`b3-pending-pipeline-02`, máy đo quá khứ
`engine-b1-r4`/`engine-b3-r4`: 818 ca mỗi bot khớp từng byte.
`kiem-chung-chuoi-dat-lenh-bot-1-3.py NEW_JSON` kiểm lại bằng chứng,
nguồn hiện hành và sáu kiểu dữ liệu cấp sai phải bị từ chối; không
chạy MT5. `NEW_JSON` phải mới và ở trong `khoi-phuc`.
[Phạm vi](../PHAN-TICH-CHUOI-DAT-LENH-BOT-1-3.md): dữ liệu dịch vụ
MT5 được cấp, chưa phải phép so nơi giao dịch hoặc toàn EA.

## Giao một phần phân tích cho Claude

`chay-claude-phan-tich.ps1 -Prompt <tệp trong dự án> -Run <tên mới>`
mở một phiên Claude Opus 5.5 Max, bật Ultracode, chỉ cho đọc tệp.
Nội dung được truyền qua tệp, không ghép vào câu lệnh. Chạy ẩn và trả
mã tiến trình; kết quả ở `.local/claude-parallel-YYYYMMDD/RUN/`.
`-Resume <mã phiên>` nối lại lịch sử; chỉ dùng khi tiến trình cũ đã
dừng. `-WaitForExit` giữ lệnh chờ để công cụ có thể theo dõi đúng phiên.
Không có phản hồi thì chưa có đánh giá. Ultracode được yêu cầu bật
không có nghĩa đã sinh tác tử phụ; phải kiểm kết quả và quyền thực tế.

## Bộ kiểm giờ theo mùa

`kiem-gio-mua-he-bot-1-3.py MODE BOT RUN [--build BUILD]` kiểm nguyên
hàm `AmericanDST` của hai bot. Thứ tự bắt buộc: tạo ca → biên dịch →
chạy MQL5 → chạy mã gốc → so kết quả.

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-gio-mua-he-bot-1-3.py prepare 1 dst-moi
& dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1 -Bot 1 -Terminal 'dich-nguoc/.local/claude-recovery-20261023/mt5' -Run b1-dst-moi -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1AmericanDSTCheck.mq5'
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-gio-mua-he-bot-1-3.py mql5 1 dst-moi --build b1-dst-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-gio-mua-he-bot-1-3.py original 1 dst-moi
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-gio-mua-he-bot-1-3.py compare 1 dst-moi
```

Đổi `1` và tên nguồn để kiểm bot 3. Chỉ chạy MT5 riêng, tắt giao dịch.
Đầu ra ở `bot-cua-toi-N/bang-chung/kiem-gio-mua-he/RUN/`.
Đồng hồ và các lỗi giả định được cấp sẵn. Các kết quả phép chia dư,
đổi ngày và ghép chuỗi được đo thật trên MT5 rồi cấp vào hàm gốc;
mỗi lời gọi phải đúng đối số và thứ tự. Mã gốc chạy cả hai hàm sao
chép/hủy chuỗi, dừng nếu nhảy ra ngoài các hàm/ranh giới đã xác định.

Lượt `dst-20261024-r1`, bản dựng `b1-american-dst-01` và
`b3-american-dst-01`: 4.737 ca mỗi bot khớp kết quả và toàn bộ dấu vết
lời gọi. Không chứng minh lỗi đổi ngày đầu tiên với vùng chưa khởi
tạo, lỗi cấp bộ nhớ hoặc toàn bộ P26. [Phạm vi](../PHAN-TICH-GIO-MUA-HE-BOT-1-3.md).

`kiem-ma-bien-dich-gio-mua-he.py BOT RUN PROBE_RUN` dùng bản chụp thư
viện có nguồn để chạy lệnh máy của nguồn giờ theo mùa gọi MT5 trực
tiếp, không có các hàm thay thế của chương trình kiểm. Dùng lại đầu
vào và kết quả API đã đo từ lượt `RUN`; so đủ kết quả và dấu vết.
Không mở MT5 hoặc gọi giao dịch. Chỉ bỏ thông báo đánh dấu đầu hàm
của chương trình đối chứng. Hai lượt `dst-20261024-r1` đã khớp đủ
4.737 ca mỗi bot; giới hạn đầu vào/lỗi của lượt đó vẫn giữ nguyên.

## Đối chứng lời gọi MT5 và phân tích nạp vốn

- `doi-chung-loi-goi-bo-sung.py NEW_RUN`: biên dịch thư viện có nguồn
  trong `doi-chung-mt5/api-bo-sung-20261023/source/`, chỉ nạp qua hàm
  `Anchor`, chụp mã rồi nối các địa chỉ còn thiếu. Chạy máy thử riêng
  trên demo đã được phép; không thực thi các hàm xóa/lịch tin/hộp thoại.
  Lượt đạt: `api-extra-r2`. Thư mục lượt cũ không bị ghi đè.
  Có thể truyền `--area <thư mục trong doi-chung-mt5>` có bộ nguồn
  `source/RecoveryApiLibrary.mq5` và `source/RecoveryApiDriver.mq5`;
  chép cả tệp `.mqh` cạnh chúng. Giữ nguyên nguồn/bằng chứng cũ.
- `phan-tich-khoi-tao-von-bot-1-3.py BOT NEW_RUN`: chạy riêng đoạn nạp
  vốn trong mã gốc, so với bảng luật phân tích; không mở MT5. Cấp dữ
  liệu cho tài khoản/kho lưu/đồng hồ và phép đổi số thành chuỗi; các
  lệnh ghép chuỗi gốc vẫn chạy. Lượt `init-state-20261023-r1`, 616 ca mỗi bot.
- `kiem-khoi-tao-von-bot-1-3.py MODE BOT RUN [--build BUILD]`: dùng lại
  đúng 616 đầu vào/kết quả gốc đã ghi, chạy MQL5 và so giá trị, đúng tên
  lưu, mốc giờ và thứ tự gọi. `MODE` là `prepare`, `mql5`, `compare`.

Biên dịch `BotNAccountInitializationCheck.mq5` sau `prepare`, trước
`mql5`. Bước `mql5` bắt buộc truyền `--build` đúng biên nhận; dừng nếu
nguồn/EX5 khác bản đã biên dịch. Hai bot chạy lần lượt trong MT5 riêng.
Lượt đạt: `init-state-check-20261023-r1`, biên dịch `b1-initial-state-02`
và `b3-initial-state-01`. Kho lưu được thay bằng dữ liệu kiểm, không
ghi/xóa mục thật. [Giới hạn](../PHAN-TICH-MENU-VA-KHOI-TAO-BOT-1-3.md).

Ví dụ dựng lại danh sách mới, có bằng chứng menu và lời gọi bổ sung:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/lap-ban-do-bot-1-3.py dich-nguoc/khoi-phuc/ban-do-bot-1-3/luot-moi --extra-calibration dich-nguoc/khoi-phuc/doi-chung-mt5/api-bo-sung-20261023/api-extra-r2/calibration.json --menu-evidence dich-nguoc/khoi-phuc/menu-bot-1-3/luot-20261023-r1/verified-menu.json
```

Menu được kiểm bằng kỹ năng điều khiển ứng dụng, không dùng mã tự bấm
Windows. Thư mục `menu-bot-1-3/luot-20261023-r1/` giữ ảnh/cây cửa sổ,
tệp `Defaults` do MT5 xuất và các tệp số đã nạp để đọc tên hiển thị.
