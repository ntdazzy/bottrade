# Đặc tả luồng chính Bot 3 — bản r1 (2026-10-26)

## Phạm vi và bằng chứng

- EX5 được dùng trong lượt này có SHA-256 `ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83` (bản ghi trong `preparation-full-20261026-r2/SPEC-r2.md`). Mã C trung gian đối chiếu có SHA-256 `ef8e07ac21522a8a2ab7165db6e77f40885acfc5a044c502ba81e331b826f620`.
- Mốc địa chỉ tuyệt đối dùng trong mã C là `0x17156250000 + RVA`.
- Phạm vi chính: dispatcher `RVA 0x17f00` (`FUN_17156267f00`), chuẩn bị `RVA 0xe0c0` (`FUN_1715625e0c0`), evaluator `RVA 0x20ef0..0x2a1bc`. Chưa coi đây là đặc tả toàn EA.

## Thứ tự dispatcher (RVA 0x17f00)

1. Guard nhịp gọi: đọc `TimeCurrent`; khi bộ đếm thời gian chưa hết thì `return`. Nếu cờ khung nến bật, đọc `iTime(...,shift=1)` và chỉ đi tiếp khi thời gian nến thay đổi. Đây là bằng chứng trực tiếp ở `ma-trung-gian.c`, quanh dòng 9890–9940.
2. Guard trạng thái chạy: nếu cờ trạng thái toàn cục `DAT_171562c44b0 != 1` thì `return`.
3. Guard tài khoản: đọc trạng thái tài khoản; bộ đếm lỗi tăng khi kiểm tra thất bại, và sau hơn 2 lần thì tắt cờ chạy, gọi `Dispatch(...,3,1,0x590008)` rồi `return`.
4. Cập nhật số dư/vốn: đọc `ACCOUNT_BALANCE`/`ACCOUNT_EQUITY` tùy cờ `UseEquity`; cập nhật đỉnh vốn và `ManualBalance` nếu có. Các cờ và ô đầu vào được nối trong `cai-dat-da-kiem.md` (các mục `ManualBalance`, `UseEquity`, `MaxAllowedDD`).
5. Cập nhật trạng thái ngày/giờ và bảng hiển thị. Việc tạo chuỗi ngày dùng `TimeCurrent` rồi `TimeToStruct`; lỗi cấp phát/ghép chuỗi đi nhánh runtime helper, không có giá trị mặc định được chứng minh.
6. Dispatcher gọi phần quản lý và phần vào lệnh theo trạng thái; chi tiết gọi quản lý tại đoạn máy `RVA 0x227c0..0x22875` đã ghi trong `bar-gate-20261026-r1/README.md` và `main-calls-20261026-r1/native-manager-calls.json`.

## Chuẩn bị dữ liệu (RVA 0xe0c0..0xef3f)

Đây là hàm `FUN_1715625e0c0`; đặc tả đầy đủ đã chốt trong `preparation-full-20261026-r2/SPEC-r2.md`. Trình tự bắt buộc:

- Tạo chỉ báo mã `0x53`; kết quả âm → báo lỗi `Dispatch(...,2,2,0x590008)` và trả.
- `CopyBuffer(handle,0,0,100,...)`; chỉ kết quả đúng `0` mới trả ngay. Độ dài `<2` gọi ba nhánh lỗi runtime theo đúng thứ tự.
- Tính `ratio`, `scale`, `lot_scale` bằng `double`; giữ nguyên phép chia và thứ tự đọc. Ghi `strategy_index` sau phần scale/lot.
- Đọc tick, thời gian, point, digits và mức dừng/đóng băng theo từng lần gọi riêng; tạo `bid`, `ask`, `spread`, `unit`.
- Chép các khoảng cách/offset/khung; chuẩn hóa stop, target, trail, gap, độ rộng; tính hạn lệnh bằng số nguyên 32 bit. Cờ hết hạn ảo ghi hạn bằng `0`.
- Lỗi giữ các ô đã ghi trước lỗi; không tự thêm giá trị mặc định.

## Evaluator (RVA 0x20ef0..0x2a1bc)

Bằng chứng máy và mã C xác nhận các nhóm sau, nhưng chưa đủ để chốt công thức chiến lược:

- Đầu vào có cờ `AllowBuyTrades`, `AllowSellTrades`, `EnableNFP_Filter`, `UseMQL5Calendar`, `EnableIR_Filter`, `EnableCPI_Filter`, cùng các khoảng thời gian trước/sau tin. Các địa chỉ và kiểu được nối trong `cai-dat-da-kiem.md`.
- Có lời gọi hàng đợi tại `RVA 0x269f9` → đích `0x3bb10`; payload chưa giải mã.
- Nhánh mua: gọi hàm điểm vào `0x31cd0` tại `RVA 0x27a52`, sau đó gọi chặn lệnh gần mua `0x47380` tại `RVA 0x27a6c`.
- Nhánh bán: gọi `0x32090` tại `RVA 0x28b32`, sau đó chặn lệnh gần bán `0x475e0` tại `RVA 0x28b4c`.
- Có 9 ô chiến lược; cờ `RunStrat1..RunStrat9` được dispatcher đọc tại `0x17f00`. Bảng nối menu → chỉ số nội bộ đã kiểm 7.724/7.724 ca trong `chon-chien-luoc/select-20261024-r2/summary.json`: `[0,1,2,3,5,4,7,8,6]`. Đây chỉ chứng minh thứ tự chọn, chưa chứng minh công thức từng chiến lược.
- Ở đoạn quản lý `RVA 0x22803..0x22866`, mã gọi hàm theo chỉ số, so kết quả cũ/mới, ghi lại kết quả vào mảng 9 ô, rồi gọi tiếp hai hàm `0x82f60` và `0x87590`; nếu một trong hai báo thay đổi thì đi nhánh cập nhật. Bằng chứng này không giải mã tên biến hay nội dung hàm.

## Guard phiên, tin và tài khoản

- Guard nến/thời gian nằm ở dispatcher và được kiểm trực tiếp như trên.
- Guard phiên giao dịch gọi `SymbolInfoSessionTrade`; mã gốc lặp tối đa 9 hoặc 10 phiên và xử lý nhánh SDK thất bại. Địa chỉ gọi nằm trong mã C quanh dòng 13665–14064; điều kiện đầy đủ chưa được đặt tên.
- Guard tin dùng ba nhóm NFP/IR/CPI và các cờ nêu trên; evaluator có đọc các cờ này, nhưng ranh giới “đóng lệnh đang mở / hủy lệnh chờ / chặn vào mới” chưa được tách đủ từ máy gốc.
- Guard tài khoản và giới hạn giảm vốn có đọc trong dispatcher; công thức đầy đủ của `MaxAllowedDD`, `PropFirmMaxDailyDD` chưa được chứng minh ở phạm vi này.

## Trạng thái và kiểu dữ liệu đã xác nhận

- Giá, khoảng cách, khối lượng, spread và tỷ lệ dùng `double` trong mã C; chỉ số chiến lược và bộ đếm dùng số nguyên không dấu hoặc `int` tùy ô, chưa được suy rộng sang MQL5 khi chưa có binding.
- Kết quả chiến lược/điểm vào được lưu theo từng ô trong bảng 9 phần tử; mã gốc giữ giá trị cũ để so trước khi ghi giá trị mới.
- Quản lý vị thế chạy qua router theo khung nến; README bar-gate xác nhận luôn gọi mua rồi bán trước khi ghép kết quả.

## Chưa được chốt

1. Công thức và tham số của 9 chiến lược trong evaluator; chưa có bằng chứng native đủ cho từng nhánh.
2. Kiểu chính xác của mọi ô trạng thái dùng trong `0x20ef0..0x2a1bc` và cấu trúc payload hàng đợi `0x3bb10`.
3. Điều kiện đầy đủ của guard phiên, tin, giới hạn giảm vốn và thứ tự đóng/hủy lệnh trong mọi nhánh lỗi.
4. Nội dung và tác dụng phụ của các hàm đích `0x31cd0`, `0x32090`, `0x47380`, `0x475e0`, `0x3bb10`.
5. Chưa có phép chạy hai EA song song; tài liệu này chỉ là đặc tả từ native/raw, không phải xác nhận phục hồi 100%.

Không được giao viết mã cho các mục chưa chốt ở trên.
