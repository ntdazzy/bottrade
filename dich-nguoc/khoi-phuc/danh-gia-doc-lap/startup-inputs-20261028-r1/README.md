# Đầu vào chuẩn bị ban đầu — bot 1

Đã đọc trực tiếp đầu vào từ EX5 gốc chạy trong máy thử riêng với tám
chiến lược tắt. Kiểm bản EX5 đúng SHA-256, cả tám cờ bằng 0, bảng đã
khởi tạo và chỉ số chuẩn bị vẫn là 0. Bản chụp và báo cáo lần chạy
được giữ tại `init-defaults-20261028-r1`.

Không lấy phần mô phỏng đã bỏ qua các lời gọi tạo đối tượng làm
bằng chứng đầy đủ. Quan sát mới chạy các bước tạo đối tượng của MT5
thật và hoàn tất lần đo quá khứ. Đây là quan sát sau OnInit khi không
gọi các bộ cấu hình giao dịch; chưa phải ảnh chụp mọi đầu ra ngay
trước lần chuẩn bị đầu.

## Kết quả

- 54 trường chuẩn bị đọc được; 41 trường nội bộ, 13 trường gắn với
  cài đặt người dùng.
- Chu kỳ chỉ báo ban đầu 30, dùng khung ngày, tham chiếu 0.0.
- Khoảng dừng/chốt đầu vào 50/100 theo đơn vị nội bộ, chưa nhân đơn
  vị giá; các khoảng khác giữ đúng từng bit
  quan sát được. Không thay bằng bộ cấu hình chiến lược 0.
- Bình luận chuẩn bị tại `0x622d0` là chuỗi rỗng. Bình luận giao dịch
  là một trường khác; không gộp hai trường.
- Hai chuỗi đuôi/mã giá trên vùng nhớ ngoài bản chụp chưa đọc được;
  không điền giá trị suy đoán vào báo cáo.

Nguồn `Bot1InitializeStartupInputs` đặt 41 trường nội bộ và bình luận
chuẩn bị. Nó giữ nguyên 13 trường người dùng cùng mã giá đã có.
Bốn bộ đầu vào kiểm đủ 54 trường mỗi lượt đều khớp; có số âm, số 0
khác dấu, byte 0/1/2/255 và các chế độ số nguyên. Biên dịch 0 lỗi,
0 cảnh báo. Lượt: `b1-startup-inputs-20261028-r1`.

Đây là một cấu hình quan sát gốc. Bốn bộ kiểm là bốn bộ đầu vào của
nguồn, không phải bốn lần chạy gốc hoặc toàn bộ cài đặt của EA.
Tệp ghép 100 `.mqh` tại `b1-all-headers-api-20261028-r22` cũng biên
dịch 0 lỗi, 0 cảnh báo.

Hàm này dành cho lúc nạp trạng thái chương trình, trước chuẩn bị đầu;
không tự gọi lại trước mỗi chiến lược hoặc mỗi OnInit. Việc nối vào
đúng vòng đời còn cần thực hiện khi tạo EA chính.

## Giới hạn còn lại

Chưa phục hồi đầy đủ các đầu ra mặc định của khối khởi tạo tĩnh, các
đối tượng hỗ trợ, trạng thái bộ sinh số và mọi đầu vào dùng chung.
Hàm trên chỉ khởi tạo đầu vào chuẩn bị đã quan sát; chưa là toàn bộ
hàm khởi tạo tĩnh, OnInit hoặc EA. Chưa chạy cặp EA gốc/nguồn đầy đủ.

## Chạy lại

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/chay-chup-bot-1-3.py 1 NEW_CAPTURE --disable-strategies
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/doc-dau-vao-khoi-dong-bot-1.py NEW_CAPTURE
```

`generate CAPTURE_RUN` của `kiem-mac-dinh-dau-vao-bot-1.py` chỉ dùng
khi chưa có nguồn. Sau đó biên dịch `Bot1StartupInputsCheck.mq5`, rồi
chạy `run NEW_TEST --capture CAPTURE_RUN --build BUILD`. Chỉ dùng máy
thử riêng và tên lượt mới, không ghi đè bằng chứng cũ.
