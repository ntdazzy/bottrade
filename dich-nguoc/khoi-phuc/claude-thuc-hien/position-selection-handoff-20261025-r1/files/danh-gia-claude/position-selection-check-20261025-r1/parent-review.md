# Đối chiếu lại nhận xét Claude về bộ kiểm r1

Claude chỉ đọc bản r1 đóng băng trong
`position-selection-20261025-r1/tested-sources` và báo cáo ở
`response.md`. Nhật ký ghi 20 yêu cầu đều dùng `claude-opus-5-5`, mức
`max` ([biên nhận](receipt.json)); phiên nối tiếp lượt phân tích quét
trước. Có yêu cầu Ultracode nhưng không có quy trình Ultracode chạy
xong (`ultracode_workflow_completed:false`). Báo cáo không đánh giá
r2/r3; kết quả r2/r3 dưới đây lấy từ biên nhận riêng.

## L1 — kịch bản 5 không tác động phép so nào

- Đúng với r1 và r2. Công cụ r1 dòng 56–57 đặt `11/XAUUSD` ở chỉ số 0,
  `12/Renamed` ở chỉ số 1. Vòng quét đi 2 → 1 → 0 nên kiểm đóng chỉ
  được gọi ở chỉ số 0, vòng cuối; thay đổi sau đó không còn phép so nào.
  R2 giữ nguyên bộ ca này.
- R3 giữ nguyên các ca cũ, thêm hai ca id 4.598/4.599 (mua/bán) với
  `12/Renamed` ở chỉ số 0 và `11/XAUUSD` ở chỉ số 1. Vòng quét gặp 11
  trước và gọi kiểm đóng; sau đó mã cơ sở thành -1, chuỗi mục tiêu
  thành `Renamed`. Mã gốc vẫn dùng mã đã chụp và đọc lại chuỗi, nên
  vị thế 12 cũng khớp: hai lần kiểm đóng, hai lần đóng, hai lần gửi
  ở cả hai bot, khớp MQL5
  ([biên nhận hai ca](../../danh-gia-doc-lap/chon-vi-the-dong-20261025/post-helper-change-r3.json)).
- Hai bản sai Claude nêu đã được dựng riêng cho mỗi bot: (a) tính lại
  `accepted[]` sau kiểm đóng; (b) giữ chuỗi từ lần so đầu. Mã gốc từ
  chối đủ 8/8 ca: bản (b) thiếu các lời gọi tiếp theo
  (`EXTRA_NATIVE_API 18`), bản (a) đọc mã thay vì chuỗi
  (`API_ORDER_DIFFERS (21, 23)`)
  ([tóm tắt](../../danh-gia-doc-lap/chon-vi-the-dong-20261025/post-helper-r2/summary.json)).
  Băm header sản xuất ghi trong tóm tắt bằng băm nguồn r3 đã kiểm;
  bản sai chỉ nằm trong thư mục kiểm và MT5 riêng.
- `post-helper-r1` dừng trước khi mở MT5 vì chưa có nguồn r3 đóng băng;
  không có kết quả từ lượt đó.
- Chưa chạy hai bản sai trên 4.598 ca cũ. Nhận định "vẫn qua đủ 4.598
  ca" là phân tích của Claude, chưa có biên nhận chạy. Việc bản sai chỉ
  gọi kiểm đóng một lần được tổng kiểm mới đọc lại từ kết quả MQL5 của
  bản sai; chưa coi là đã xác nhận trước khi tổng kiểm đó chạy đạt.

## L2 — bộ đọc dữ liệu kiểm r1 không kiểm hết tệp

- Đúng với công cụ r1: hàm `fixtures` (dòng 109–145) không kiểm đã đọc
  hết tệp. Thử lại cho thấy tệp thiếu 2 hoặc 4 byte cuối vẫn được nhận
  ([trước sửa](../../danh-gia-doc-lap/chon-vi-the-dong-20261025/parser-eof-r1.json)).
- R2 thêm `FIXTURE_BYTES_NOT_EXACT` và kiểm ngăn xếp khi kiểm đóng trả
  về (`HELPER_STACK_NOT_RESTORED`). Chín tệp cắt cụt mỗi bot bị từ
  chối; 36 kiểu dữ liệu sai bị từ chối
  ([sau sửa](../../danh-gia-doc-lap/chon-vi-the-dong-20261025/parser-eof-r2.json)).
  R3 giữ hai kiểm này.
- Nguồn MQL5 và bản biên dịch `bN-position-selection-01` giống nhau ở
  r1–r3; chỉ công cụ kiểm thay đổi.

## Kết quả các lượt

| Lượt | Mã gốc = MQL5 | Máy đo quá khứ |
|---|---|---|
| r1 | 4.598/4.598 | 4.598/4.598 |
| r2 | 4.598/4.598 | 4.598/4.598 |
| r3 | 4.600/4.600 | 4.600/4.600 |

Số liệu lấy từ `comparison.json` của từng lượt trong
`bot-cua-toi-N/bang-chung/kiem-chon-vi-the-dong/` và
`doi-chung-mt5/chon-vi-the-dong-20261025/engine-position-selection-bN-rK/`.
Đã đọc biên nhận máy đo r3 của cả hai bot (0 lỗi) và nhật ký có
`POSITIONSELECTION_NATIVE_CHECK_EXIT:0`. Tổng kiểm mới
`KIEM-CHUNG-CHON-VI-THE-DONG-BOT-1-3-R2.json` phải chạy đạt trước khi
dùng các số r3 làm kết luận chính thức. Claude không đọc các biên nhận
máy đo; lúc đọc, Claude ghi chưa có lượt máy thử.

## Các nhận xét khác vẫn giữ

- Mô hình chọn vị thế chỉ có ở phía kiểm; mã gốc chép `selected` từ
  dữ liệu ghi nên trường này không phải bằng chứng. Chưa đo hành vi
  thật của `PositionGetTicket(total)` và `_LastError`.
- Trả lời trong phần kiểm đóng không phụ thuộc vị thế đang quét và
  được phát lại y hệt mỗi lần; ca nhiều lần kiểm đóng luôn đi cùng nhánh.
- Hai bot dùng chung một `cases.bin` (r3: `dca69b34…`).
- Bản đóng băng không tự chạy lại được vì thiếu công cụ cha; công cụ
  cha chỉ được ghim bằng băm trong `original-run.json`.
- Mã gốc không ghi mã cơ sở/chuỗi/vé chỉ được thấy trong các nhánh đã
  chạy (nhờ chặn ghi); chưa phải chứng minh cho mọi nhánh EX5.
- Chưa làm các tăng cường tùy chọn: giới hạn số lần đọc mã theo bot
  (8/15), chuỗi cùng độ dài khác ký tự cuối, nhiều lần kiểm đóng với
  trả lời khác nhau, kiểm các thanh ghi phải giữ khi kiểm đóng trả về.

## Giới hạn

Truy vấn/kết quả gửi được cấp; chưa có tài khoản/nơi khớp thật, mã lỗi
MT5 thật, toàn EA, mọi cài đặt, bảng hiển thị, khởi động lại/trạng thái
lưu hoặc lỗi cấp bộ nhớ. Cân bằng cấp/giải phóng chưa chứng minh mọi
phép dùng bộ nhớ hợp lệ. Bốn bản sai chỉ cho thấy bộ ca bắt được hai
lỗi này. Không quy đổi 4.600 ca thành phần trăm hoàn thành toàn bot.
