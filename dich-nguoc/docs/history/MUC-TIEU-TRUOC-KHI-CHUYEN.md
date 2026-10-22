# Mục tiêu người dùng đã chốt

Ngày 20/10/2026, người dùng yêu cầu:

1. Làm hoàn chỉnh **một bot trước**, rồi mới áp dụng quy trình cho các bot còn lại.
2. Người dùng đã chọn nghĩa của “100%”: **bản MQL5 đầy đủ, hoạt động giống bot gốc**.
3. Bổ sung mới nhất: ưu tiên giống mã nguồn gốc tối đa, gồm tên biến/tham số/hàm nếu còn dữ liệu để khôi phục. Tên tự đặt hoặc chưa biết phải được đánh dấu; không coi tên suy ra là tên gốc.
4. Sau khi một bot đã hoàn chỉnh và được kiểm chứng, đóng quy trình thành công cụ dùng lại nếu làm được, nhằm tiết kiệm quota cho các bot tiếp theo. Không coi các công cụ chụp/xuất C hiện tại là bộ dịch MQ5 hoàn chỉnh.

Bot đang tập trung: **TwisterPro Scalper**.

- Nguồn: `../mt5-btc-recovery/TwisterPro Scalper.ex5`.
- SHA-256: `C705E2BBBB66D18E31E2A375625DFDEF69243CB73E684AF3A846D6AB33FABE73`.
- Đã có ba phần MQL5 trong `reconstructed/`, chưa có bot MQL5 hoàn chỉnh.
  Xem `reconstructed/TINH-TRANG.md`; không gọi các tệp C là kết quả hoàn chỉnh.
- Chưa mở lại lượt xử lý các bot khác khi bot này chưa được kiểm chứng.

## Kết quả có thật

### Bổ sung ngày 21/10/2026

- Khi chốt lượt này đã dừng hết máy thử riêng, đặt Login=0 và xóa bộ nhớ đệm tài khoản trong bản riêng. Xem `runtime-cleanup-20261021.json`. Muốn chạy tiếp phải chuẩn bị lại cấu hình demo cục bộ như phần môi trường; không dùng bản MT5 đang giao dịch.

- `TwisterInputs.mqh` giữ 28 tên tham số đã đọc; tên kiểu danh sách gốc chưa biết.
- `TwisterSettings.mqh`: 400/400 giá trị khớp 10 bộ đầu vào trên bản gốc,
  gồm giới hạn dưới/trên, hai chế độ, hai kiểu sàn, dừng ngắn và sửa mức dừng/chốt.
  Bằng chứng: `settings-check/twsettings_v1/comparison.json`.
- `TwisterFilters.mqh`: 800/800 ca khớp ba hàm mã máy gốc (RVA0xc080,
  0xc690,0xc880) trong môi trường mô phỏng CPU có dữ liệu đầu vào cấp sẵn.
  Bằng chứng: `filter-check/twfilters_v3/comparison.json`. Không coi đây là
  so toàn bộ bot gốc trong MT5. Bản v2 thất bại khi công cụ kiểm đọc nhầm
  kích thước tham số; lỗi đã ghi riêng và sửa trước v3.
- Cả hai chương trình kiểm MQL5 đã biên dịch0lỗi/0cảnhbáo và chạy xong
  máy thử riêng. Kết quả bộ lọc v1 đã được thay bằng v3 cho mã hiện tại.
- Các bản chụp cũ có thể ở giữa bước khởi tạo. Khi kiểm trạng thái ban
  đầu phải dùng `-ReadyByteRva 0x22590` cùng `-IncludeProgramData`;
  `captures/twisterready1_09` và các bản trong `settings-check/cases.json`
  đã chờ cờ bằng1. Không dùng trạng thái chưa khởi tạo để khẳng định sai logic.
- Máy thử có lượt khởi động hơn25giây. Công cụ đã chờ tối đa55giây và
  báo lỗi rõ nếu không chụp được; 5 lượt lỗi cũ giữ riêng, không tính đạt.
- Đã đối chiếu202hàm có nguồn trong `api-probe-v6`; thao tác6 của hàm
  sao dữ liệu là `CopyTickVolume`, thao tác8 là `CopyRealVolume`.
- Bản C mới nhất: `decompiled/TwisterPro-Scalper-annotated-v5.c`, xuất76hàm.
  Có83lời gọi được bổ sung kiểu tham số và40vị trí trạng thái được đặt kiểu.
  Không coi83là mọi lời gọi. Bốn lời gọi thiếu đã kiểm lại bằng mã máy;
  `dispatch-additional-four.json`, `dispatch-v5-init-verification.json`.
- Công cụ kiểm lặp lại: `check-twister-settings.py`, `check-twister-filters.py`.
  Chưa phải bộ dịch tự động. Tên nội bộ mới đều là tên phân tích.

### Bằng chứng các lượt trước

- Chương trình đối chứng `Ex5ReadProbe.mq5` được biên dịch bằng `scripts/build.ps1`, đạt 0 lỗi, 0 cảnh báo.
- Đã đọc đúng phép tính `value * 1357911 + 2468022` từ mã đang chạy và bản C do Ghidra xuất.
- Nguồn/bản EX5 đối chứng còn khớp bản ghi biên dịch: `control-fresh-check.json`.
- Đã lấy 110.592 byte mã của Twister và xuất 70 hàm dạng C:
  `decompiled/TwisterPro-Scalper.c`.
- Chưa xác nhận đúng toàn bộ hoạt động của Twister.
- Lượt chụp `captures/twister01/` có mã; `captures/re2ro1_09/` có thêm sơ đồ vùng nhớ.
- Vùng dữ liệu tiếp giáp mã Twister dài 86.016 byte, có quyền đọc/ghi; thử chỉ lấy vùng chỉ đọc không thu thêm được dữ liệu. Các bản chụp đầu chưa chứa vùng này.
- Bổ sung: `captures/twisterdata1_09/` đã lấy đúng vùng dữ liệu 86.016 byte cùng vùng mã, có địa chỉ nền và mã kiểm tra máy thử trong `twisterdata1_09-result.json`. Chưa chạy đối chiếu hành vi.
- Đã tìm 28 tên tham số gốc từ nhật ký (`twister-inputs-from-log.json`), cùng đường dẫn nguồn `Experts\TwisterPro_v3_3.mq5` và bốn tệp Include chuẩn trong dữ liệu.
- Đã kiểm 75 bản ghi hàm Windows x64 tại vị trí `0x64e8`: các vị trí xử lý ngăn xếp khớp ranh giới lệnh thật. Có thêm một hàm ngắn tại `0xa30`; tổng 76 vùng hàm. Xem `unwind-verification-v2.json`. Giữ bản kiểm đầu bị sai ở trường hợp hàm không cần mở khung ngăn xếp.
- So với bảng đã kiểm, bản C 70 hàm trước bỏ sót 8 điểm bắt đầu và đặt thêm 2 điểm bên trong vùng khác. Chưa coi việc xuất C không báo lỗi là chứng minh đầy đủ.
- Đã nhận dạng 177 chuỗi có độ dài/địa chỉ/ký tự kết thúc khớp và 181 vị trí tham chiếu; metadata ở `twister-meta-v2/`. Tên nhãn phân tích không phải tên biến tác giả.
- Mã C còn tham chiếu dữ liệu ngoài vùng đã lấy và các địa chỉ chức năng MT5 chưa được đặt tên.

## Lượt hàng loạt đã dừng

- Đã chụp vùng mã của cả 17 tệp, nhưng chỉ có 15 tệp hoàn tất bước xuất C khi người dùng đổi thứ tự làm.
- Ghidra `AllBots` đã được dừng theo yêu cầu; xem `scope-single-bot.json`.
- Tệp C không có `.summary.json` đi kèm có thể đang dở; không dùng làm kết quả đã hoàn thành.
- Giữ các bản thô làm bằng chứng, không tiếp tục xử lý các bot khác lúc này.

## Việc cần giải quyết trên Twister

1. Lấy và phân loại dữ liệu thuộc đúng vùng cấp bộ nhớ của bot; tránh đọc bộ nhớ ngoài phạm vi cần thiết.
2. Xác định các chức năng MT5 được gọi bằng chương trình đối chứng có mã nguồn đã biết.
3. Đối chiếu tham số, dữ liệu, nhánh xử lý và vòng đời bot; phần nào chưa xác định phải ghi rõ.
4. Chỉ viết lại MQL5 từ phần đã có bằng chứng; không tự chọn điều kiện vào/thoát hoặc ngưỡng.
5. Biên dịch bản khôi phục và so lệnh, thời điểm, giá, khối lượng, dừng lỗ, chốt lời và các thay đổi lệnh với bot gốc trên cùng dữ liệu/tham số.
6. Báo rõ phạm vi đã kiểm. Không dùng số hàm đã xuất hoặc vài ca trùng nhau để khẳng định toàn bộ bot đúng 100%.

## Môi trường và công cụ

- MT5 riêng: `terminal/`. Mọi chế độ máy thử giữ `Enabled=0`, `AllowLiveTrading=0`, `AllowDllImport=0`; không dùng máy thử trên mạng.
- Bản không có cấu hình tài khoản đã bị MT5 từ chối. Sau đó đã dùng tạm bộ nhớ đệm cấu hình demo của máy thử nguồn; sau lượt hàng loạt đã xóa `terminal/config/accounts.dat` và đặt lại `Login=0`. Đã chuẩn bị lại cấu hình demo này cho lượt chỉ làm Twister; cần dọn khi kết thúc nghiên cứu.
- Muốn chạy lại phải chuẩn bị lại cấu hình demo trong bản riêng, không bật bot ở biểu đồ hoặc sửa bản MT5 đang chạy của người dùng.
- Máy thử nguồn được đọc từ `C:/Users/NTD/Documents/Codex/2026-10-20/l-n-m-ng-d-t/work/bot-tests/mt5-market`.
- `run_market.py` là bản sao nguyên của công cụ có sẵn, nhật ký ở `market-logs/`.
- `scripts/inspect-ex5-running-code.py` kiểm đúng đường dẫn tiến trình trước khi đọc; hai ca từ chối tiến trình/nơi ghi sai đã đạt.
- `scripts/run-market-ex5-capture.ps1` chụp theo danh mục `capture-jobs.json`, ngắt đúng máy thử riêng sau khi chụp. Twister là chỉ mục **9**.
- Capstone 5.0.9 ở `analysis-libs/`.
- Ghidra 12.1.4 và JDK 21.0.12.1 ở `tools/`, có biên nhận kiểm mã tải về.
- Các tệp Java trong `ghidra-scripts/` nhập đúng địa chỉ mã và xuất C; chưa khôi phục tên/hợp đồng gọi MT5.

## Bảo toàn tệp

- Cả 17 tệp EX5 gốc vẫn đúng mã kiểm tra.
- `KET-QUA-3-TUAN.md` đã khác lần chụp danh mục của lượt trước; công việc dịch ngược không sửa tệp đó, không khôi phục đè lên nó.
- Phần có trước trong `scripts/TOOLS.md` giữ nguyên; chỉ thêm mục công cụ dịch ngược.
- Không gửi Telegram hoặc đánh giá lợi nhuận từ các lượt máy thử bị ngắt để lấy mã.
