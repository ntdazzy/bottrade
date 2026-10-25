# Tóm tắt — ứng viên phần đầu quản lý bot 3 (lượt r2)

Trạng thái thật: **chỉ là ứng viên. Chưa biên dịch, chưa chạy kiểm,
chưa so với EX5 gốc; không có số ca đạt.** Chỉ ghi hai tệp trong thư
mục này; nguồn chính `bot-cua-toi-3/source/` không bị sửa. Không chạy
lệnh, Git, MT5; không dùng Workflow hay tác tử phụ.

Logic chỉ lấy từ
[contract r2](../../bot-cua-toi-3/phan-tich/dong-vi-the/management-prelude-20261025-r2/contract.md);
không dùng mô tả r1, không đọc EX5/C/capture. Có đọc chữ ký các helper
có sẵn (`Bot3PriceLevels`, `Bot3PositionModify`, `Bot3PositionClose`,
`Bot3TradeSend`, `Bot3PendingRequest`) và `Bot1ManagementPrelude.mqh`,
chỉ để viết cùng cách với phần bot 1.

## Mô tả r2 → mã

Số dòng là dòng trong [Bot3ManagementPrelude.mqh](Bot3ManagementPrelude.mqh).

| Mục trong r2 | Mã |
|---|---|
| Struct: 5 double, 2 string, 3 long | `Bot3ManagedPosition` :10; trường xếp theo thứ tự đọc |
| Đọc 1: vé ghi vào `last_ticket`; vé 0 trả false, không đổi position/tick | :28–29 |
| Đọc 2: digits → SL(6) → làm tròn; digits → TP(7) → làm tròn | :30–33, `Bot3RoundPrice` có sẵn |
| Đọc 3: sau TP mới đọc `last_ticket` hiện tại → `(double)(long)`; digits → giá mở(4) | :34–36 |
| Đọc 4: thuộc tính 11, 3, 1, 2, 12, 0 đúng thứ tự | :37–42 |
| Đọc 5: tick lỗi in `Tick not ok`, không xóa tick, vẫn lọc | :43 |
| Lọc 6: type thấp int32 == buy?0:1; magic thấp int32 == int cài đặt; enabled==1; chuỗi so bằng `==` của MQL5 | :44–46 |
| Bổ sung dừng: sl==0.0 → đọc digits trước; mua `open-stop*unit`, bán `stop*unit+open`; sửa lần 1 | :54–61 |
| Bổ sung chốt: tp==0.0 → đọc digits; mua `take*unit+open`, bán `open-take*unit`; sửa lần 2 | :62–69 |
| Vé cho sửa/đóng là `(ulong)(long)ticket_number`; bỏ bool sửa; không đọc lại vị thế | :60, :68, :98–99 |
| Khung theo nhóm: 0 nguyên byte; 1 `0?0:15`; 2 `0?0:0x4001`; đọc lại byte ở từng API | `Bot3ManagementCandleTimeframe` :74, gọi ở :89–96 |
| Nến 1: cờ ==1; `iTime(khung, byte shift)`; previous>opened thì thoát nhóm | :88–90 |
| Nến 2: `iTime(khung,0)`; opened>=current thì thoát nhóm | :91–92 |
| Nến 3: close1 rồi open1 (shift 1); mua close1<open1, bán open1<close1 | :93–95 |
| Nến 4: đọc close lần hai; mua close2<giá mở, bán giá mở<close2 | :96–97 |
| Nến 5: `Bot3TryClosePosition` (`0x47d20`) với deviation, `tick.bid`, `tick.ask`, threshold_a/b theo tham chiếu | :98–99 |
| Nến 6: in `closing candle confirmation` sau helper; không thoát phần quản lý | :100 |

Ba sửa đổi của r2 nằm ở: địa chỉ `0x6d29c..0x6d2a2` (chú thích :72–73;
mã nhận tham chiếu), lần `iTime` đầu dùng byte shift truyền vào (:89),
không có vòng ngoài (hàm nhận `index`).

Ngoài r2, nhật ký chạy bot 3 gốc
[`b3-inputs-20261023-r3-options-high.log:165`](../../bot-cua-toi-3/bang-chung/phan-tich-cai-dat/inputs-20261023-r3/options-high/b3-inputs-20261023-r3-options-high.log)
có dòng `closing candle confirmation` ngay sau một lệnh đóng. Chỉ phù
hợp với chuỗi; chưa chứng minh nhánh nào in.

## Cách ghép (chưa viết vòng ngoài)

Với mỗi chỉ số do vòng ngoài gốc cấp: gọi `Bot3ReadManagementPosition`;
nếu true thì `Bot3FillManagementInitialLevels`, rồi
`Bot3CloseManagementCandle` nhóm 0, 1, 2 theo thứ tự, cả ba cùng byte
shift `0x6d29c`. Sau đó là phần giá lưu `Bot3ManagementAnchor` (bắt đầu
`0x33b73`/`0x38194`, đúng ranh giới cuối của phần này), rồi các nhánh
dời dừng. Đối số đã có địa chỉ trong r2: `last_ticket` `0x74838`, tick
`0x74790`, threshold_a/b `0x73ab0`/`0x744a8`. r2 không ghi địa chỉ của
magic, enabled, symbol, unit, khoảng dừng/chốt và deviation.

Bộ kiểm nên chặn ở `Bot3TryClosePosition`, không chặn ở
`Bot3ClosePosition`, để bắt được trường hợp gọi nhầm helper.

## Chỗ Codex cần kiểm hoặc quyết

1. r2 không ghi độ rộng của `enabled` ở bước lọc. Mã dùng `const int &`
   như bot 1. Nếu gốc là byte thì đổi thành `const uchar &`, giữ `==1`.
2. magic/enabled/symbol là tham chiếu, được đọc lúc so, tức sau
   `SymbolInfoTick`. Chỉ có thể khác gốc khi bộ kiểm đổi cài đặt trong
   lời gọi API mà gốc đọc sớm hơn; cần ca riêng nếu muốn chốt.
3. So thời gian bằng `long` có dấu (`(long)iTime`), như bot 1. r2 không
   ghi rõ dấu; nên thêm ca giờ ≥ 2^63.
4. `Bot3ManagementCandleTimeframe` chỉ có nghĩa với nhóm 0/1/2 theo r2;
   số khác sẽ chạy như nhóm 0. Chỉ gọi với 0/1/2.
5. Truyền `tick.bid`/`tick.ask` (thành viên của `const MqlTick &`) vào
   tham chiếu `const double &`: chưa biên dịch nên chưa biết MetaEditor
   có nhận không.
6. Include dùng đường dẫn tương đối: phải đặt tệp cạnh các `.mqh` bot 3
   trong `Include/bot-cua-toi-3/` mới biên dịch được.

## Quan sát ngoài phạm vi (chưa kiểm, không sửa)

[`Bot1ManagementPrelude.mqh:93`](../../bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1ManagementPrelude.mqh)
(và :144, :225) gọi `Bot1ClosePosition` (`0x22c40`, đóng trực tiếp).
[Contract bot 1 :53](../../bot-cua-toi-1/phan-tich/dong-vi-the/management-prelude-20261025-r1/contract.md)
và [branch-map bot 1 :6](../../bot-cua-toi-1/phan-tich/dong-vi-the/management-20261025-r1/branch-map.md)
lại ghi lời gọi đóng là `0x3d010` (hàm kiểm hai ngưỡng). Bộ kiểm r3
[`Bot1ManagementPreludeCheck.mq5:112`](../../bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/prelude-20261025-r3/tested-sources/Bot1ManagementPreludeCheck.mq5)
thay `Bot1ClosePosition` bằng `CheckClose`, nên 340/340 ca không phân
biệt được hai helper. Codex nên đối chiếu lại phần bot 1.

## Còn thiếu

Biên dịch; bộ kiểm chặn ở ranh giới helper; so với đoạn máy gốc theo
danh sách ca của r2 (ba nhóm, shift/cờ 0/1/2/255, vé lớn/âm, chữ Việt,
số đặc biệt, sát ngưỡng, close lần hai khác lần một). Ngoài phần này
còn: vòng ngoài, ghép helper thật, dời dừng thật/ảo, bảng, chế độ, lỗi
bộ nhớ, cài đặt/UI/lưu trạng thái và EA chính. Chưa có cơ sở để nói
phần này hay bot 3 đã đạt.

## Cấu hình phiên

Mô hình theo thông tin hệ thống: `claude-opus-5-5`. Mức `max`/`ultracode`
không tự kiểm được từ bên trong phiên. Lượt này chỉ dùng
Read/Grep/Glob/Write.
