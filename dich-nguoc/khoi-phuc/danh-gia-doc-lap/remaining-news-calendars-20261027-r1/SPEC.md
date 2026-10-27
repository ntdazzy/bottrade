# Lịch lãi suất/CPI — đặc tả đã kiểm từ thân gốc

Các hàm: bot1lãi suất6600..6a83,CPI6a90..7306; bot3lãi suất6f20..73a3,
CPI73b0..7c26. Mã SHAđầy đủ tại native-bindings.json; đã chạy52probe
nguyên hàm với dữ liệu dịch vụ được cấp, ghi trongnative-name-timeout-probes.json.
Nguồn hiện hành là Bot1/3ReleaseCalendars.mqh; phép so490ca thường
mỗi bot và16ca lỗi mảng mỗi bot đã khớp, chạy lỗi riêng trong MT5.
MQL5 production gọi dịch vụ thật; chỉ Scriptkiểm dùng trả lời/mã lỗi được cấp.

Lãi suất gọi CalendarEventByCountry("US",events). Tìm chuỗi phân biệt
hoa/thường `Fed Interest Rate Decision` ở bất kỳ vị trí. Dùng mã đầu
khớp, mã0hoặc không tìm thấy dùng0x3212255e. Sau gọi lịch sử, nếu mã
lỗi hiện tại==5401thì inđúng `Calendar timeout error. Try shortening the date range.`
và trả0, kể cả lịch sử trả số lượng dương. Không ResetLastError trước
kiểm này; mã lỗi5401cũ còn nguyên cũng làm nhánh đó xảy ra.

CPI gọi CalendarEventByCurrency("USD",events), mã dự phòng0x3211d735.
Điều kiện đúng là:

`(contains("Consumer Price Index") || contains("CPI ")) && (contains("(YoY)") || !contains("ex Food"))`

Không được viếtORcả4chuỗi. Probeđã thấy `CPI ex Food (MoM)` dùng mã
dự phòng nhưng `CPI ex Food (YoY)` lấy mã sự kiện123; tên chỉcóYoY/
exFoodcũng không khớp. Giữ thứ tựStringFindvà tác dụng phụ mã lỗi.
CPI KHÔNGcó nhánh5401hoặc thông báo tương tựlãi suất: với mã lỗi5401
và dữ liệu lịch sử dương, nó vẫn chọn thời điểm. Đã kiểm bằng thân gốc.

Cả hai lấyTimeTradeServer, from=now-86400,to=now+5961600; lấy mốc nhỏ
nhất>from sau khi dịch vụ trả. Chỉ tra lịch sử khi danh sách sự kiện
trả>0; vẫn tra bằngmãdựphòngkhi khôngthấy tên/mãkhớp0. Mảng xuôi/
ngược và lỗi mảng thiếu có thân xử lý gốc, cần so khi viết nguồn.
Chưa thử lỗi cấp phát hoặc lịch trực tuyến.

## Cách kiểm mã lỗi

MT5 không có hàm công khai để ghi tùy ý một mã lỗi chuẩn5401. Bộ kiểm
vì vậy cấp trạng thái lỗi terminal tại ranh giới CalendarValueHistory,
qua hàm đọc lỗi thay thế trong Script; nguồn production vẫn dùng
GetLastErrorthật. StringFindtrả giá trị và mã lỗi đo từ hàm MT5thật,
trạng thái lỗi được giữ khi không có lỗi mới. ResetLastErrorcủa bộ
kiểm cũng được nối với trạng thái đó. Không gọi việc này là đã tạo
hoặc đo một timeout mạng thật.

Đã so thời điểm trả, mã lỗi cuối, chính xác loại dịch vụ(countrykhác
currency), mã sự kiện, khoảng hỏi, thứ tự dịch vụ và thông báo. Có
mảng xuôi/ngược, trả số lượng không phù hợp, cờ lỗi5401cũ và lỗi được
cấp sau lần hỏi lịch sử. Phép kiểm lỗi mảng chạy từng ca trongMT5riêng,
kiểm nhật ký mới/đúng mã ca và chuỗi dịch vụ trước dừng.

Các mã kiểu mảng16bit ngoài vùng chụp được cấp như phép kiểmNFP;
stride128/cờ/mảng được giữ đúng. Lỗi cấp phát, lịch trực tuyến,
người gọi IR/CPI và toànEA vẫn chưa được chứng minh.
