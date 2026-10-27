# Nhánh dự phòng NFP — phần phân tích cho bước ghép tiếp

Đã đối chiếu raw1b7ae..1bdfd/23e0b..24437 và nguồn hiện hành
AmericanDST/PositionSelection/PendingDistanceCancel. Chưa viết hoặc
xác nhận toàn nhánh dự phòng này đạt.

- Gọi AmericanDST trước. Giá trịfalse chọn bù3600giây, true chọn0.
  Sau đó gọi helper lấy năm: TimeCurrent(MqlDateTime&) rồi đọc trường
  năm; helper tháng gọi lạiTimeCurrent rồi đọc tháng, không thay bằng
  TimeToStruct(TimeCurrent()) vì khác thứ tự dịch vụ.
- Năm<=2026: quét300mốc (bot1RVA68330,bot3RVA75360). Với từng mốc gọi
  TimeToStruct để so năm với helper năm đọc mới; khớp năm mới gọi lại
  TimeToStruct để so tháng với helper tháng đọc mới. Tìm được thì
  ghi thời điểmNFP=TimeTradeServer()+bù+mốc-UTCRef.
- Cửa sổ chặn của nhánh này so UTCRef với mốc+bù±phút32bit. Không cộng
  thêm TimeTradeServer vào hai đầu cửa sổ. Không khớp cả300 thì mốc
  cục bộ0; giữ thời điểmNFPcũ, nhưng vẫn kiểm cửa sổ từ mốc0 và bù.
- Năm>2026: chỉ xét khi ngày trong lịch đã lưu<=7 và thứ trong tuần=5;
  bot1lịch đã lưu ở67790 (ngày67798,thứ677a8),bot3ở747d0
  (ngày747d8,thứ747e8). Đây không phải điều kiện tháng=5.
- Tạo chuỗi bằng IntegerToString(năm)+IntegerToString(tháng)+
  IntegerToString(ngày)+" "+IntegerToString(1230), với độ rộng0,
  ký tự bùSPACE. Không tự thêm dấu chấm, dấu hai chấm hoặc thêm số0.
  Probe chạy nguyên phần nối chuỗi của hai bot đã thấy `202711 1230`
  ởStringToTime cho ngày1/1/2027. Probe dừng trước phân tích chuỗi,
  chưa chứng minhStringToTime trả thời điểm gì hoặc hành động tiếp.
- Nhánh>2026 không ghi lại ô thời điểmNFP như nhánh tìm được trong
  bảng300; chỉ lấy thời điểm cục bộ doStringToTime để xét UTCRef.
- Trong cửa sổ: nếu bật hủy thì gọi quét/hủy mua rồi bán; sau đó nếu
  bật đóng thì gọi lọc/đóng mua rồi bán; chỉ in khi cờ chặn cũ0, rồi
  ghi cờ1. Ngoài cửa sổ ghi0; khi điều kiện năm>2026/ngày/thứ không
  cho xét thì không tự xóa cờ cũ.

Bảng có240mốc khác0 và60ô0 ở cả hai bản chụp. Đã đối chiếu độc lập
240giá trị với phép gán trong hàm khởi tạo, mã SHA của300ô giống nhau.
Đây là bằng chứng dữ liệu, chưa chứng minh toàn thứ tự khởi tạo/mọi
đường cập nhậtUTCRef. Xem nfp-history-evidence.json và hai probeJSON.

Cần ghép nguyên nhánh gọi lịch trực tuyến/bảng dự phòng/chọn tin cùng
các thân hủy/đóng đã có, so tác dụng phụ và mọi đường ra. Không biến
nhánh có chuỗi lạ thành quy tắc thứSáu dễ viết hơn.
