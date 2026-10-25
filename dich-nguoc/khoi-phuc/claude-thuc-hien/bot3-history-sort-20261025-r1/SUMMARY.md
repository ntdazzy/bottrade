# Tóm tắt — hàm sắp xếp lịch sử bot 3 (`0x557f0`)

Trạng thái thật: **đã viết `Bot3HistorySort.mqh`; chưa biên dịch, chưa
chạy, chưa so với lệnh máy gốc.** Chưa có ca kiểm nào đạt. Đây chỉ là
hàm phụ của phần tổng hợp lịch sử, không phải phần lịch sử hay toàn bot
(`whole_bot_complete=false`).

Phiên này chỉ dùng Read/Grep/Glob/Write; không chạy lệnh/MT5/git, không
dùng tác tử phụ hay Workflow (phiên không có công cụ này và TASK cũng
không cho). Chỉ ghi trong thư mục TASK. Mô hình theo thông tin hệ thống
của phiên: `claude-opus-5-5`, ultracode bật; mức `max` không tự kiểm được
từ bên trong. Codex cần tự kiểm cấu hình của lượt.

| Phần đã làm | Kết quả và phạm vi | Còn thiếu / bước tiếp |
|---|---|---|
| [Bot3HistorySort.mqh](Bot3HistorySort.mqh) | `void Bot3HistorySort(ulong &keys[],long &values[],int left,int right)`, 34 dòng, không phụ thuộc tệp khác | Chép vào `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/` (đúng đường include của bộ kiểm); biên dịch 0 lỗi/0 cảnh báo |
| Soát mô tả với bằng chứng Codex (chỉ đọc) | `function.c` và danh sách lệnh trong `analysis.json` bot 3 khớp mô tả; không thấy mâu thuẫn | — |
| Dò tay 16 ca của `native-pilot.json` bot 3 | Kết quả tính tay trùng cả 16 ca (khóa và đi kèm, 4 tổ hợp cờ). **Không phải chạy thật** | Chạy bộ kiểm so với mã gốc |

## Mô tả → mã

| Bước mô tả | Dòng | Ghi chú |
|---|---|---|
| 1. middle, pivot, i/j | 10–11 | `keys[(left+right)/2]`: cộng/chia int32, đọc pivot **trước** kiểm `i<=j` nên vẫn kiểm chỉ số middle khi left>right; không có `if(left>=right)return` |
| 2. Hai vòng con | 14–17 | So `ulong` (unsigned); không thêm giới hạn `i<=right`/`j>=left` |
| 3. Đổi chỗ | 18–27 | Giữ hai khóa tại điểm dừng (`left_key`, `right_key`), không đọc lại; ghi `keys[i]` rồi `keys[j]`; đổi `values` bằng biến `long`, kể cả khi i==j; sau đó mới `i++`, `j--` |
| 4. Đệ quy trái, vòng phải | 12, 29–32 | `left<j` thì gọi `(left,j)` trước; `left=i`; `right<=left` thì thoát, nếu không quay bước 1 |
| 5. Không đổi mảng | toàn tệp | Không ArraySort/ArrayResize/ArraySetAsSeries/kiểm đầu vào; cờ đảo riêng của mỗi mảng do MQL5 tự xử lý |

## Đối chiếu đã đọc (bot 3, `analysis.json`)

- `0x55831`–`0x5584b`: `lea/shr/add/sar` (chia có dấu cắt về 0), rồi
  `movsxd`+`jae` kiểm middle; xảy ra trước `cmp ecx,edx` ở `0x5586c`.
- `0x55907` `jae` (dừng khi khóa >= pivot), `0x55987` `jbe` (dừng khi
  khóa <= pivot): cả hai unsigned.
- `0x559df` ghi `keys[i]`=khóa phải, `0x55a28` ghi `keys[j]`=khóa trái;
  `0x55a39`/`0x55a5b` kiểm i rồi j của `values` trước lần ghi `values`
  đầu tiên ở `0x55a7a`. `inc/dec` ở `0x55ab0`/`0x55ab3` chỉ là thanh ghi;
  ô ghi cuối `0x55ab5` vẫn dùng j cũ, cùng nghĩa với dòng 24–26.
- `0x55873`–`0x55881`: đệ quy khi j>left; `0x55820`–`0x5582b`: left=i,
  i>=right thì trả.

## Chuỗi đổi chỗ dò tay (chỉ số logic, để dò lỗi khi so)

- Khóa lớn, cờ khóa thường: (0,4) (2,2) | đệ quy (0,1): (0,1) | (3,3).
  Ra khóa `[0,1,1,2^63,2^64-1]`, đi kèm `[-22,55,33,-44,11]`.
- Khóa lớn, cờ khóa đảo: (0,3) (1,2) | đệ quy (0,1): (0,0) | (2,3) | (3,3).
- Khóa trùng `7`: (0,4) (1,3) (2,2) | đệ quy (0,1): (0,1) | (3,4).
  Ra đi kèm `[4,5,3,1,2]`.
- Khoảng con 1..3: cờ khóa thường (1,3) (2,2); cờ khóa đảo chỉ (2,2).
- left=2, right=0: chỉ đọc middle=1, không đổi.

## Điểm Codex cần để ý

1. Bản gốc dùng hai mảng toàn cục (mô tả `0x772e0`/`0x77320`), chỉ nhận
   left/right qua ECX/EDX. Nguồn mới nhận hai mảng tham chiếu theo chữ
   ký đã chốt, đệ quy truyền lại đúng hai mảng đó. Nơi gọi phải truyền
   đúng hai mảng tương ứng; phần này chưa ghép.
2. Lỗi ngoài mảng: MQL5 dừng chương trình. Thứ tự ghi trước lỗi theo
   gốc (khóa i, khóa j, rồi kiểm i/j của `values` trước khi ghi
   `values`); dòng/cột lỗi chắc chắn khác bản gốc.
3. Giữ `(left+right)/2` với int32; không đổi thành `left+(right-left)/2`
   vì sẽ khác khi tràn số.
4. Nếu EA/script có biến toàn cục tên `keys`, `values`, `left`, `right`,
   `pivot`, `value`, MQL5 có thể cảnh báo che biến toàn cục. Chưa biên
   dịch nên chưa biết.
5. Ca lỗi (middle/i/j ngoài mảng, `values` ngắn hơn) chưa có bằng chứng
   chạy gốc trong lượt `sort-20261025-r1`; cần chạy riêng.
