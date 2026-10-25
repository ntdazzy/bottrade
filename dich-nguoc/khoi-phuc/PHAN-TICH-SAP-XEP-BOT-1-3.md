# Sắp xếp hai mảng lịch sử

Codex đã đọc đầy đủ 214 lệnh mỗi bot trước khi giao viết nguồn.
Bot 1 hàm `0x47950`, bot 3 `0x557f0`; đây là hàm phụ của phần tổng
hợp lịch sử, không phải điều kiện giao dịch hay toàn EA.

## Bằng chứng

Tệp gốc đã được kiểm SHA-256 bằng `original_hash` đang có. Lượt mới
`bot-cua-toi-N/phan-tich/sap-xep/sort-20261025-r1/` giữ `analysis.json`,
`native.txt`, `function.c` và `native-pilot.json`. Hai bot có cùng 214
lệnh/cấu trúc nhánh, khác vị trí dữ liệu/hàm và thông tin dòng lỗi.
Mỗi bên đã chạy 16 ca mã gốc với mảng thường/đảo, khóa rất lớn, khóa
trùng, khoảng con và trái>phải; chưa có phép so nguồn MQL5.

| Dữ liệu | Bot 1 | Bot 3 |
|---|---|---|
| Hàm | `0x47950` | `0x557f0` |
| Mô tả mảng khóa | `0x6a2a0` | `0x772e0` |
| Mô tả mảng đi kèm | `0x6a2e0` | `0x77320` |
| Kiểu khóa | unsigned 64 bit (`ulong`), đầu kiểu `0x800010056` | như bot 1 |
| Kiểu đi kèm | signed 64 bit (`long`), đầu kiểu `0x800010055` | như bot 1 |

Trong mô tả mảng: độ dài int32 ở +8, con trỏ ở +28, cờ đảo bit
`0x10` tại +2. Mỗi mảng có cờ đảo riêng, không được tự đổi cờ hoặc
dùng cờ của mảng khóa cho mảng kia. Khi cờ đảo bật, chỉ số logic k
ứng với phần tử vật lý `length-1-k`. Ngôn ngữ MQL5 tự làm điều này.

## Mô tả để viết mã

Chữ ký nguồn: `void BotNHistorySort(ulong &keys[],long &values[],
int left,int right)`. Hai giới hạn là số int32 có dấu. Không thêm
tham số, kiểm dữ liệu để âm thầm thoát, cấp phát, đọc tài khoản,
thay cờ mảng, đổi thuật toán thư viện hoặc ổn định thứ tự khóa trùng.

1. Lần vào đầu tiên luôn tính `middle=(left+right)/2` với phép cộng
   int32 và chia có dấu cắt về 0; kiểm chỉ số middle của mảng khóa.
   Lệnh gốc thực hiện kiểm này ngay cả khi left>right. Với mô tả mảng
   MQL5 hợp lệ, có thể lấy `pivot=keys[middle]` để giữ phép kiểm lỗi.
   Sau đó đặt i=left, j=right. Nếu left>right thì không quét/đổi mảng;
   vẫn giữ phép kiểm middle vừa nêu. Không đặt `if(left>=right)return`
   trước lần lấy pivot vì sai với ca rỗng/ngoài mảng.
2. Khi i<=j: tăng i trong lúc `keys[i]<pivot` bằng so unsigned 64 bit;
   sau đó giảm j trong lúc `keys[j]>pivot` cũng unsigned. Mỗi lần
   truy cập giữ phép kiểm chỉ số của MQL5. Không thêm giới hạn i<=right
   hoặc j>=left vào hai vòng con.
3. Giữ hai khóa đã đọc tại điểm dừng của hai vòng con. Nếu i<=j:
   ghi keys[i]=khóa phải đã đọc, rồi keys[j]=khóa trái đã đọc;
   tiếp theo đổi values[i] và values[j] bằng biến tạm long, ngay cả
   khi i==j. Chỉ sau đó tăng i và giảm j. Nếu i>j không đổi gì.
4. Lặp bước 2 khi i<=j. Khi hết vòng: nếu left<j, gọi đệ quy cùng
   hàm với left,j trước. Sau đó gán left=i. Nếu right<=left thoát;
   nếu chưa thì quay bước 1 trong cùng lần gọi. Giữ nhánh trái đệ
   quy trước nhánh phải chạy vòng lặp; khóa trùng phải giữ thứ tự
   đổi như bản gốc, không chuyển thành kiểu sắp xếp khác.
5. Không thu nhỏ/mở rộng mảng. Mảng khác độ dài hoặc giới hạn xấu có
   thể lỗi giữa chừng, cần so cả dữ liệu đã đổi trước lỗi. Các dòng/
   cột lỗi sinh từ nguồn mới sẽ khác bản gốc; không gọi chúng giống.

Ca gốc đã đo, mảng thường, left=0,right=4:

- Khóa `[18446744073709551615,0,1,9223372036854775808,1]`, đi kèm
  `[11,-22,33,-44,55]` → khóa `[0,1,1,9223372036854775808,18446744073709551615]`,
  đi kèm `[-22,55,33,-44,11]` ở cả hai bot.
- Khóa `[7,7,7,7,7]`, đi kèm `[1,2,3,4,5]` → khóa giữ các số 7,
  đi kèm `[4,5,3,1,2]`. Đây là bằng chứng thứ tự khóa trùng.

## Phép kiểm cần có

So trực tiếp hai mảng vật lý, chiều dài/cờ đảo, thứ tự và trạng thái
trước lỗi với lệnh máy gốc. Ca gồm các chiều dài, khoảng con, phần tử
trùng/tất cả bằng nhau, unsigned vượt LONG_MAX, các số long âm/lớn,
bốn tổ hợp cờ đảo, trái=phải/trái>phải, sai chỉ số và mảng ngắn.
Không dùng việc đã sắp tăng hoặc cùng tập phần tử làm đáp án duy nhất.
Biên dịch nguồn mới sạch, chạy MT5 riêng và cùng máy đo quá khứ khi
cần; kết quả thành phần không phải xác nhận phần lịch sử hay cả bot.
