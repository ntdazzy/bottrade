# Toàn bộ bước tính khối lượng: bản nguồn gọi MT5 trực tiếp

| Phần gốc | Bot 1 | Bot 3 |
|---|---|---|
| Thân tính khối lượng | `34780..3621b` | `3f900..41771` |
| Theo dõi rút tiền | `173f0..17839` | `1fd00..20149` |
| Đổi sang USD | `36220..3bfd5` | `8300..e0b5` |
| Đổi từ USD | Không gọi ở bước này | `41780`, nguồn `Bot3StrategyContextAmount` đã so riêng |
| Mảng khối lượng/chỉ số | `66a80` / `678f4` | `73ac0` / `74934` |

Mã kiểm và toàn bộ lệnh gốc nằm trong `native-evidence.json` và các
bản liệt kê cùng thư mục. Codex đọc bản gốc trước khi viết, không dùng
bản C trung gian làm bằng chứng duy nhất.

`BotNPrepareVolumeRuntime` nhận đúng khoảng dừng lỗ/số nhân, tên mã,
đuôi mã, cài đặt và các ô trạng thái. Chỉ số mảng được truyền bằng tham
chiếu: lấy ô ban đầu trước đọc tick value; đọc lại chỉ số khi ghi cuối.
Không đổi chữ ký sang nhận một bản sao để làm bộ kiểm dễ biên dịch.

1. Luôn đọc vốn tài khoản (37), ghi vốn hiệu lực; nếu chọn vốn hiện tại
   thì đọc thêm (40) và ghi lại. Gọi thân rút tiền trước chọn vốn cao nhất.
2. Rút tiền giữ cờ bật, kiểm MQL_TESTER, ba lần đọc giờ, chọn và quét
   lịch sử. Giữ thứ tự cập nhật thời điểm, ghi biến lưu và khôi phục
   khoảng lịch sử. Khi đặt lại vốn cao nhất, đọc đủ ba chuỗi
   DoubleToString với 2 số lẻ theo thứ tự: vốn mới, vốn cũ, tiền rút.
   Print có sáu đối số chuỗi: `Withdrawal of `, tiền rút,
   ` detected - OnlyUp highest balance reset from `, vốn cũ, ` to `, vốn mới.
3. So vốn cao nhất bằng phép so có thứ tự; NaN không khiến tự chọn hoặc
   ghi vốn cao nhất. Vốn nhập tay >0 được ưu tiên; ±0 được thay bằng0.01.
4. Lấy khối lượng cũ theo chỉ số hiện tại, rồi luôn đọc thuộc tính26.
   Các chế độ giữ công thức, nhóm phép nhân/chia và phép làm tròn gốc.
   Mỗi nhánh trong một chế độ gọi thuộc tính36 ba lần và xét ba IF
   độc lập (.1/.01/.001); không gộp thành một lần đọc hoặc else-if.
   Bot1 chế độ1..998 còn đọc mới thuộc tính26 khi nhánh được chọn;
   chế độ3 vẫn đi tiếp sang phần riêng sau chế độ rủi ro1..998.
5. Chế độ999 chỉ đổi tiền khi tick value >0. Bot1 gặp 0/số âm/NaN sẽ
   báo đúng chuỗi và đổi chế độ thành9999; bot3 bỏ nhánh, không tự
   thêm thông báo/đổi chế độ. Bot3 chế độ1234 giữ nhánh chia trọng số,
   thay loss0 bằng9999999999 và nhánh tần suất riêng.
6. Đổi sang USD: đọc lại tiền tài khoản cho từng điều kiện; thứ tự
   EUR,GBP,AUD,JPY/YEN,CHF,CZK,HKD,RUB,CNH,CNY,SGD rồi các tiền số.
   Hai nhánh CNH/CNY độc lập, có dự phòng USDCNY+đuôi. Nếu lần đọc giá
   đầu dương thì lần đọc thứ hai được dùng trực tiếp, kể cả0 (phải dừng
   do phép chia), không kiểm lại >0 để nuốt lỗi. Cuối hàm MathRound.
   Đổi ngược của bot3 dùng thân đã so của StrategyContextAmount.
7. Nhân hệ số khối lượng. So mức tối thiểu bằng lần đọc34 thứ nhất;
   khi nhỏ hơn, lấy lại34 để gán. Bot1 thêm sàn start_lots. Sau giới hạn
   max_lots, đọc34 lại và nếu cần đọc mới34 để đưa vào cảnh báo.
   Bản gốc dùng MAXSD(start,lots), MINSD(max,lots): toán hạng thứ hai
   được giữ khi một toán hạng làNaN. Dùng phép so `start>lots` và
   `max<lots`, không đảo điều kiện <= vì sẽ làm mất NaN.
8. Đọc35, nếu nhỏ hơn thì đọc35 lần hai để xét !=0; cần cảnh báo thì
   đọc35 lần ba để định dạng, in đúng toàn chuỗi, rồi đọc35 lần bốn
   để lấy giới hạn dùng thật. Không thay bằng một ảnh chụp thuộc tính.
9. Riêng cuối hàm mới dùng chuỗi else-if đọc36: chọn .1/.01/.001;
   floor(lots*power)/power, làm tròn rồi ghi đúng chỉ số mới nhất.
   Bước khác giữ toàn bộ mảng cũ. Mọi chia0 xảy ra thật trong nguồn,
   không returnfalse thay cho dừng lỗi gốc.

## Phép kiểm

Bộ mới chạy nguyên thân khối lượng/rút tiền/đổi tiền gốc. Chỉ cấp trả
lời dịch vụ MT5, cấp phát thành công và chuỗi số do MT5 riêng đo thật.
Nguồn MQL5 gọi trực tiếp các hàm dựng lại; bộ kiểm thay dịch vụ để cấp
cùng dữ liệu. So từng byte toàn bộ thứ tự, đối số, giá trị trả, chuỗi
UTF16, trạng thái trước từng dịch vụ và cuối hàm; so đủ8/9ô mảng.
Có thay dữ liệu tối thiểu/tối đa/bước giữa lần đọc và thay chỉ số mảng.

Ca lỗi chạy riêng, bật kiểm chia0; kiểm nhật ký mới, mã ca, dừng thật,
không có trạng thái thành công và toàn bộ chuỗi dịch vụ/trạng thái đã
đi qua trước lỗi. Trạng thái thay đổi sau dịch vụ cuối tới ngay điểm
lỗi không được Script bị dừng xuất ra; chưa chứng minh phần đó.

Chưa nối toàn bộ người gọi đánh giá/EA. Không dùng số ca đạt để tuyên
bố toàn bot đạt100%, không coi đây là chạy song song hai EA hoàn chỉnh.
