# SUMMARY: vé đầu bằng 0 trong quản lý vị thế bot1

Thư mục: `dich-nguoc/khoi-phuc/claude-thuc-hien/bot1-first-zero-ticket-20261026-r1/`
Trạng thái: bản đề xuất theo đặc tả Codex. Chưa ghép, chưa biên dịch, chưa chạy.

## Nguồn đã đọc

Chỉ đọc 3 tệp hiện hành trong
`dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`:

- `Bot1PositionManagement.mqh` (279 dòng)
- `Bot1ManagementRouter.mqh` (104 dòng)
- `Bot1ManagementPrelude.mqh` (268 dòng): chỉ để giữ giao diện; không sửa.

Không đọc EX5, mã máy, tài liệu phân tích, `TASK.md`, script kiểm hay bên gọi khác.
Phiên chạy ở gốc kho; thư mục này được nhận ra qua tên bằng Glob.

## Tệp đã ghi

- `Bot1PositionManagement.mqh` (287 dòng)
- `Bot1ManagementRouter.mqh` (109 dòng)
- `SUMMARY.md`

Số dòng mới trong hai bảng dưới đã đối chiếu bằng Grep trên tệp mới.

## `Bot1PositionManagement.mqh`

| Cũ | Mới | Thay đổi |
|---|---|---|
| — | 70 | Thêm chú thích: vé 0 ở index 0 gán `changed` bằng cờ, vẫn trả `false`. |
| 74 | 75 | `bool &changed)` → `bool &changed,const bool first_zero_ticket_changed)` |
| — | 80 | Thêm `{` cho nhánh đọc vị thế trả `false`. |
| — | 81–82 | Chú thích: helper ghi vé trước, trả ngay khi vé 0; vé khác 0 bị lọc không đụng `changed`. |
| — | 83–84 | `if(index==0 && shared.last_ticket==0)` / `changed=first_zero_ticket_changed;` |
| 79 | 85 | `return false;` giữ nguyên. |
| — | 86 | Thêm `}`. |
| — | 261 | Chú thích: cờ không có mặc định, bên gọi chọn mỗi lần gọi. |
| 257 | 265 | `const ulong &deviation)` → `const ulong &deviation,const bool first_zero_ticket_changed)` |
| 269 | 277 | `eligible,changed))` → `eligible,changed,first_zero_ticket_changed))` |

Dòng giữ nguyên chữ (chỉ dời số): cũ 1–69 = mới 1–69; 70–73 = 71–74;
75–78 = 76–79; 80–253 = 87–260; 254–256 = 262–264; 258–268 = 266–276;
270–279 = 278–287.

Vì vậy giữ nguyên: mọi đối số cũ, hai struct, mọi lời gọi con và thứ tự gọi,
`changed=false` đầu mỗi vòng, `total`, `eligible`, `index`,
`any_changed=any_changed || changed`, `return true` ngay khi helper trả `true`,
và toàn bộ phần sau khi đọc vị thế thành công.

## `Bot1ManagementRouter.mqh`

| Cũ | Mới | Thay đổi |
|---|---|---|
| — | 54 | Chú thích tham số mới. |
| 62 | 63–64 | `...,const ulong &deviation)` → `...,const ulong &deviation,` và dòng mới `const bool bar_first_zero_ticket_changed)` |
| — | 84 | Chú thích: BUY và SELL nến mới nhận cùng giá trị cờ của lần gọi router. |
| 83 | 86 | BUY nến mới: `deviation);` → `deviation,bar_first_zero_ticket_changed);` |
| 85 | 88 | SELL nến mới: `options,deviation);` → `options,deviation,bar_first_zero_ticket_changed);` |
| — | 94 | Chú thích: hai lời gọi từng lần nhận giá truyền `true`. |
| 95 | 99–100 | BUY từng lần nhận giá: xuống dòng trước `deviation` để không quá 100 cột, thêm `true`. |
| 101 | 106 | SELL từng lần nhận giá: `deviation);` → `deviation,true);` |

Dòng giữ nguyên chữ: cũ 1–53 = mới 1–53 (gồm `Bot1CountManagementPositions`,
dòng 7–49); 54–61 = 55–62; 63–81 = 65–83; 82 = 85; 84 = 87; 86–90 = 89–93;
91–94 = 95–98; 96–100 = 101–105; 102–104 = 107–109.

Vì vậy giữ nguyên: nhánh cờ cấp phép, điều kiện chọn nhánh, hai lần `iTime` và
ghi `last_times`, BUY trước SELL, SELL vẫn chạy khi BUY trả `true`, đếm trước mỗi
lần quản lý, điều kiện `count>0`, giá trị trả `buy_changed || sell_changed`.

## Hành vi suy từ mã (chưa chạy)

- Cờ `false`: kết quả như nguồn hiện hành.
- Cờ `true` và `PositionGetTicket(0)` trả 0: `changed=true`, helper trả `false`,
  vòng chạy tiếp; `any_changed` thành `true` nên lượt trả `true` dù các vị thế
  sau không đổi. Vị thế sau đi vào đường đóng thì vẫn `return true` ngay như cũ.
- Vé khác 0 bị lọc: `shared.last_ticket!=0`, `changed` không bị đụng.
- Vé 0 ở index lớn hơn 0: không đổi.
- Không gọi `PositionGetTicket` thêm, không dùng `position.ticket_number`.
  Điều kiện đọc `shared.last_ticket` do `Bot1ReadManagementPosition` vừa ghi
  trong cùng lần gọi, không phải giá trị cũ của hàm đếm.

## Bên gọi cần cập nhật trước khi biên dịch

Hai chữ ký mới không có giá trị mặc định, nên mọi bên gọi cũ sẽ lỗi biên dịch
cho đến khi thêm đối số:

- `Bot1RoutePositionManagement(...)`: thêm `bar_first_zero_ticket_changed`.
- `Bot1ManagePositions(...)` gọi trực tiếp ngoài router: thêm `first_zero_ticket_changed`.

Tôi không tìm bên gọi vì chỉ được đọc 3 tệp. Giá trị cờ nhánh nến mới, chương
trình chính và bộ kiểm mới do Codex chốt. Chưa coi là đã sửa hoàn chỉnh.

## Chưa kiểm

- Chưa biên dịch bằng MetaEditor (không được chạy lệnh).
- Chưa chạy MT5; chưa có ca kiểm vé 0 ở index 0; chưa so với EX5 gốc.
- Chưa chọn hay kiểm giá trị cờ nhánh nến mới ở chương trình chính.
- Dòng giữ nguyên được chép từ bản đọc nguồn, chưa so bằng công cụ diff; kiểu
  xuống dòng (CRLF/LF) của nguồn chưa kiểm. Nên diff trước khi ghép.
- Cấu hình phiên: mô hình `claude-opus-5-5` theo thông tin môi trường; ultracode
  bật theo thông báo hệ thống; mức `max` không tự kiểm được. Không tạo tác tử
  con, theo yêu cầu.
