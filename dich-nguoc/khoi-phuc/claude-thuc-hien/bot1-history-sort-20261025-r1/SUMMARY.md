# Bot1HistorySort — tóm tắt

## Trạng thái

| Mục | Kết quả |
|---|---|
| Nguồn | Đã viết `Bot1HistorySort.mqh` trong thư mục TASK này |
| Biên dịch | **Chưa** biên dịch (lượt này không được chạy lệnh/MT5) |
| So với mã gốc | **Chưa** chạy ca nào; chưa có bằng chứng đạt |
| Phạm vi | Chỉ hàm phụ `0x47950`; không phải phần lịch sử hay toàn bot (`whole_bot_complete=false`) |

Chỉ dựa vào `dich-nguoc/khoi-phuc/PHAN-TICH-SAP-XEP-BOT-1-3.md`, AGENTS.md,
`tai-lieu-cu/QUY-TRINH.md` và TASK.md. Không đọc EX5, mã C hay bản chụp;
không ghi ngoài thư mục này. Kiểu viết theo các header bot 1 hiện có.

Khi ghép: chép vào `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1HistorySort.mqh`,
nạp bằng `#include <bot-cua-toi-1/Bot1HistorySort.mqh>`. Tệp không nạp tệp khác.

## Đối chiếu mô tả → mã

| Bước mô tả | Dòng | Cách giữ |
|---|---|---|
| Chữ ký | 4 | Đúng `void Bot1HistorySort(ulong &keys[],long &values[],int left,int right)` |
| 1. middle, đọc pivot trước | 8 | `keys[(left+right)/2]`: cộng int, chia int cắt về 0; đọc cả khi left>right; không có `return` sớm |
| 1. i=left, j=right; left>right không quét/đổi | 9–11 | `while(i<=j)` không chạy khi left>right |
| 2. tăng i rồi mới giảm j, so unsigned | 13–16 | `pivot`, `left_key`, `right_key` đều `ulong`; không thêm giới hạn i<=right hay j>=left |
| 3. giữ hai khóa đọc ở điểm dừng; ghi keys[i] rồi keys[j] | 19–20 | Dùng đúng giá trị đọc ở điểm dừng, không đọc lại |
| 3. đổi values bằng biến tạm long, cả khi i==j | 21–23 | `long saved_value` |
| 3. sau đó mới i++, j-- | 24–25 | |
| 4. đệ quy (left,j) trước | 28 | Chỉ khi `left<j` |
| 4. left=i; right<=left thì thoát, không thì quay bước 1 | 29–31 | `do ... while(left<right)` |
| 5. không đổi kích thước, cấp phát hay cờ đảo | — | Không gọi ArrayResize/ArraySort/ArraySetAsSeries/ArrayGetAsSeries; MQL5 tự đổi chỉ số theo cờ riêng của từng mảng |

## Dò tay hai ca gốc trong mô tả

Dò theo văn bản nguồn, left=0, right=4. Đây **không** phải phép chạy, không tính là đạt.

| Ca | Kết quả gốc đã đo | Dò tay nguồn mới |
|---|---|---|
| Khóa `[18446744073709551615,0,1,9223372036854775808,1]`, đi kèm `[11,-22,33,-44,55]` | khóa `[0,1,1,9223372036854775808,18446744073709551615]`, đi kèm `[-22,55,33,-44,11]` | Giống. (0,4) pivot 1: đổi 0↔4, 2↔2; gọi (0,1) pivot 1: đổi 0↔1; lặp (3,4) pivot 2^63: đổi 3↔3 |
| Khóa `[7,7,7,7,7]`, đi kèm `[1,2,3,4,5]` | đi kèm `[4,5,3,1,2]` | Giống. (0,4): đổi 0↔4, 1↔3, 2↔2; gọi (0,1): đổi 0↔1; lặp (3,4): đổi 3↔4 |

## Điểm Codex cần kiểm (chưa có bằng chứng)

1. Biên dịch 0 lỗi, 0 cảnh báo.
2. Bộ ca thường theo mục "Phép kiểm cần có" của mô tả, gồm bốn tổ hợp
   cờ đảo; so trực tiếp mảng vật lý với mã gốc chạy.
3. Ca lỗi, so cả dữ liệu đã đổi trước lỗi:
   - rỗng `(0,-1)`: middle=0 nên lỗi ngay ở lần đọc pivot;
   - `values` ngắn hơn: theo thứ tự mã, `keys[i]`, `keys[j]` ghi xong rồi
     mới đọc `values[i]`, `values[j]`; hai lần đọc này đều trước lần ghi
     `values` đầu tiên, nên khi lỗi thì `values` chưa đổi. Đây là suy từ mã, chưa chạy;
   - chỉ số âm/ngoài mảng; tổng `left+right` vượt int32 (giả định phép
     cộng int của MQL5 quay vòng như int32, chưa kiểm).

   Dòng/cột trong thông báo lỗi sẽ khác bản gốc; không gọi là giống.
4. Độ sâu đệ quy: giữ đúng cấu trúc gốc (luôn đệ quy phần trái), nên dữ
   liệu xấu có thể gọi sâu tới cỡ số phần tử. Khung gọi của bản biên dịch
   mới có thể khác bản gốc, nên ngưỡng tràn ngăn xếp có thể khác; chưa kiểm.

## Câu hỏi về mô tả

Không thấy điểm mâu thuẫn giữa mô tả, TASK và hai ca gốc. Chưa có câu hỏi.

## Cấu hình lượt

Phiên báo mô hình `claude-opus-5-5`; mức suy nghĩ thực tế không tự kiểm
được từ trong phiên. Phiên báo bật Ultracode nhưng không có công cụ
Workflow, và TASK chỉ cho Read/Grep/Glob/Edit/Write, nên làm trực tiếp.
