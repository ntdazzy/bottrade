**Phạm vi:** tôi chỉ đọc mã C trung gian, metadata và 3 tệp host đã kiểm. Chưa biên dịch, chưa chạy, không khẳng định tương đương toàn phần.

## 0. Ba khoảng trống P22 đã đóng nhờ tệp của host
- Cặp hằng làm tròn của 0x3d200 và 0x47f10 là −0.5000001 / +0.5000001 (`doi-chung-mt5/bang-dung-ao-20261024/rounding.json:4-18`). Vậy dùng được `Bot1RoundPrice`/`Bot3RoundPrice` cho hai hàm này.
- 0x482b0 nhận vé ở RDX = RBP, đúng giá trị R9 của lời gọi 0x47f10 ngay trước (`take-profit-call-sites.json:9,15,18` cho mua; `:37,42,46` cho bán).
- 0x482b0 bản gốc (`native-take-nan.json:5-52`):
  - +0, −0, −1 → trả bit +0, không ghi;
  - +1, NaN, +inf → ghi và trả nguyên bit.
  - Khi dựng phải viết `value<=0.0`, không dùng `!(value>0.0)`.

## 1. Thông báo Dispatch(2,7) khi hết ô: C chưa đủ để giải
Vị trí: B1:27184-27188 (0x3d200), B3:32043-32047 (0x47f10), B3:32103-32107 (0x482b0).

**Quy ước gọi (có bằng chứng mã máy):**
- RCX = ngữ cảnh, EDX = mã thao tác, R8D = số đối số.
- R9D = thẻ 0, [rsp+0x20] = giá trị 0.
- Với i ≥ 1: thẻ i ở [rsp+0x18+0x10·i], giá trị i ở [rsp+0x20+0x10·i].
- Bằng chứng: `doi-chung-mt5/gio-mua-he-20261024/bot-1-native-instructions.txt:34-40` (một đối số) và `:83-92` (ba đối số).
- Nghĩa thẻ: 0x520004 int, 0x540005/0x550005 long, 0x560015 ulong, 0x580007 double, 0x590008 con trỏ chuỗi (`cong-cu-cu/ghidra/OverrideMqlDispatchCalls.java:13-24`).

**Đã biết:**
- Mã 2, 7 đối số, thẻ 0 = 0x590008 (B1:27187).
- Thứ tự: ghi W (B1:27185), gọi `PositionsTotal()` (B1:27186), rồi Dispatch. Kết quả PositionsTotal không được dùng ở chỗ nào khác trong C.
- Khối này không có lời gọi tạo chuỗi.

**Chưa biết:** 6 thẻ còn lại, cả 7 giá trị, nội dung chuỗi, ô nào chứa PositionsTotal, có đọc biến toàn cục nào khác không. Lý do:
- Ghidra dùng chữ ký 4 tham số nên bỏ mất các ô ngăn xếp (`bot-cua-toi-13/phan-tich/ghi-chu-cu/dispatch-override-review.md:7`).
- Bản đồ r5 ghi `"strings": []` (`ban-do-bot-1-3/luot-20261023-r5/bot-1.json:10079`).
- Mã 2 chưa được hiệu chuẩn là `Print` (`api-calibration.json:8-16` không có mã 2).

**Host cần đọc đúng các chỗ sau:**
1. Tệp mã:
   - Bot 1: `bot-cua-toi-1/bang-chung/captures/luot-20261023-r1/0000023e5aa10000.bin` (nền 0x23e5aa10000, sha256 e099f124…, `metadata/import.json:11-13`), đoạn RVA 0x3d200–0x3d597.
   - Bot 3: `bot-cua-toi-3/bang-chung/captures/luot-20261023-r1/0000017156250000.bin` (nền 0x17156250000, sha256 7464a1dc…, `import.json:11-13`), đoạn 0x47f10–0x482a7 và 0x482b0–0x484bf.
2. Trong mỗi đoạn, tìm lệnh gọi 0x7ff6846f7da0 (PositionsTotal, `native-labels.tsv:72`). Tiếp sau đó là `mov edx,2; mov r8d,7; mov r9d,0x590008` và lệnh gọi 0x7ff6846d49f0 (Dispatch, `:119`). Ghi lại:
   - 6 dword thẻ ở [rsp+0x28, 0x38, …, 0x78];
   - 7 giá trị ở [rsp+0x20, 0x30, …, 0x80];
   - lệnh nạp từng giá trị (thanh ghi hoặc địa chỉ toàn cục nào).
3. Với giá trị có thẻ 0x590008: đó là địa chỉ bộ mô tả chuỗi (ví dụ 0x23e5aa6cbb8, `refs.tsv:345`). Con trỏ văn bản là qword tại mô tả+4 (`cong-cu/lap-ban-do-bot-1-3.py:204`); văn bản nằm trong `metadata/strings.tsv`.
4. Hiệu chuẩn mã 2 bằng một lời gọi có nguồn đã biết, trên cùng engine.

Chỉ viết `Print(...)` sau khi đọc xong. Khi đó giữ thứ tự: ghi W → PositionsTotal → Print.

## 2. Hàm dọn bảng 0x18790 / 0x20bc0

**Thứ tự và tác dụng (đọc từ C):**
1. Nếu `(int)size<64` thì gọi helper 0x7aa0e0(mảng, 64, 0) (B1:11108-11110). Sau đó đọc PositionsTotal **một lần** (B1:11111). Tổng < 1 thì không gọi PositionGetTicket (B1:11112-11114).
2. Vòng i = 0…tổng−1 (B1:11116-11137):
   - `PositionGetTicket(i)` đổi vị thế đang chọn ở mỗi lần gọi;
   - trả 0 → bỏ qua, không gọi PositionGetInteger (B1:11119-11120);
   - không đọc lại tổng, không lọc theo mã giao dịch hay magic, không khôi phục vị thế đang chọn, không ResetLastError.
3. Lọc bằng `(ulong)PositionGetInteger(2) < 2`, dùng bản trả giá trị (0x7ff6846f7fc0, khác bản Ref 0x7ff6846f80f0: `native-labels.tsv:78,81`). Nếu đọc lỗi, hàm trả 0 nên vé vẫn được nhận.
4. Nới và ghi mảng:
   - mảng đầy (`size<=count`) → helper(mảng, count+64, 0) (B1:11123-11125);
   - kiểm lại `size<=count` → lỗi (B1:11127);
   - chỉ số tính theo bit đảo chiều 0x10 (B1:11128-11131), nhưng mô tả khởi tạo 0x800010055 không bật bit này và không có chỗ ghi khác (B1:14792-14793);
   - mã kiểu 0x55 cùng họ với thẻ long 0x550005, nên phần tử là `long`.
5. Danh sách vé (lời gọi API và nới mảng) vẫn được dựng khi G≠1. G chỉ được kiểm sau vòng (B1:11139; B3:15312).
6. Duyệt dòng:
   - chỉ xét dòng có `0.0<vé`;
   - so `long == (long)vé` trên `count` phần tử đầu;
   - không thấy → xóa cả dòng (B1:11140-11195);
   - bot 3 làm tiếp với dòng B cùng chỉ số (B3:15345-15369).
7. Lỗi chỉ số ≥ kích thước → `runtime_memory_helper_3959a0(ctx, mã)` rồi `int3`, không quay lại.
   - Bot 1: 0x1f1ad9000001f6 (đọc), 0x161ace000001f6 (ghi) (B1:11199-11204).
   - Bot 3: 0x1f1ea8…01f6, 0x1f1ebe…01f6, 0x161e9d…01f6 (B3:15377-15384).
   - Nhánh đọc không thể xảy ra vì count ≤ size. Nhánh ghi chỉ xảy ra khi nới mảng thất bại.
8. Mảng là biến toàn cục: không bao giờ thu nhỏ. Phần đuôi giữ vé cũ nhưng không được đọc. Chỉ giải phóng khi kết thúc chương trình (B1:15299; B3:20949).

**Ranh giới lúc chạy chưa chứng minh:**
- Helper 0x7aa0e0 = `ArrayResize(arr,n,0)`: nhãn ghi `original_source_function_name_known: false` (`bot-cua-toi-13/phan-tich/ky-hieu-v4/native-labels.json:1091-1095`). Cách dùng ở B1:13867-13868 phù hợp, nhưng chưa phải hiệu chuẩn.
- Helper 0x3959a0:
  - không quay lại; mã thấp 0x1f6 nằm đúng ở nhánh chỉ số ≥ kích thước;
  - nửa cao có vẻ là (cột<<16)|dòng nguồn: các dòng liên tiếp 0x2ad5…0x2afd ở B1:6528-6589 — chưa chứng minh;
  - bản MQL5 sẽ tự báo "array out of range" theo dòng/cột của chính nó, nên văn bản lỗi không thể khớp.
- Hết bộ nhớ: chưa biết helper có tự báo lỗi riêng trước nhánh ghi không. Chưa kiểm có gọi OnDeinit sau lỗi nghiêm trọng không.
- PositionGetTicket trả 0, hoặc vị thế đóng giữa vòng làm chỉ số dịch đi: vé còn mở có thể bị bỏ sót và dòng của nó bị xóa. Trạng thái vị thế đang chọn và `_LastError` sau lỗi — chưa kiểm.
- Thuộc tính 2 = POSITION_TYPE: chưa hiệu chuẩn riêng. Phép so vết gọi sẽ lộ ra nếu sai.

## 3. Cờ G và chuyển kiểu
- **Mọi phép thử G đều là `== '\x01'`:** B1:2014, 11139, 17606, 18158, 18712, 19374, 27123, 27161, 27170, 27202, 27231; B3:2114, 15312, 23557, 23613, 24252, 24907, 24962, 25695, 31982, 32020, 32029, 32063, 32090, 32121, 32150. Chỉ có một lần ghi, giá trị 1 (B1:14893; B3:20483).
- **Khi chạy EA:** G luôn bằng 1, nên `bool` hay `uchar` cho kết quả như nhau.
- **Khi kiểm thành phần có nạp hoặc tiêm byte G từ ảnh bộ nhớ gốc** (0, 1, 2, 0xFF):
  - `bool` không giữ được giá trị 2, và mã MQL5 có thể thử `!=0` → khác bản gốc;
  - trình biên dịch không giữ một dạng thử cố định: cờ của bảng D bị thử bằng `==1` (B1:19454) và cả `&1` (B1:19760-19761);
  - vì vậy dùng `uchar guard` và viết đúng `guard==1` ở mọi chỗ.
- **Vé:**
  - Nơi gọi đã đưa vé qua double trước khi truyền: B1:17203 → 17351 → 17352; B3:23046, 23234-23235 (bán: 24594-24595). Vé ≥ 2^53 đã bị làm tròn trước khi tới bảng.
  - Tra và ghi dùng `(double)tham_số`, phép đổi có dấu (B1:27126, 27176, 27205, 27234; B3:32064, 32095, 32124, 32153). Vậy tham số MQL5 là `long`; `ulong` chỉ khác khi vé ≥ 2^63.
  - W so bằng số nguyên 64 bit, không qua double (B1:27184; B3:32043, 32103).
  - Hàm dọn so `(long)vé` (cắt phần lẻ) với vé thật chưa làm tròn (B1:11160-11161; B3:15319, 15347). Vé ≥ 2^53 có thể bị xóa dù còn mở.
- **Dấu thời gian:**
  - ghi `(double)TimeCurrent()` (B1:27236-27237);
  - đọc bằng `(long)` cắt phần lẻ, nên |dấu| < 1 bị coi như 0 (B1:27207-27208);
  - hiệu tính bằng 64 bit (B1:27209-27210); so `(long)(int)D <= hiệu` (B1:27211);
  - D là int32 vì ô ngay sau là biến khác (B1:3738-3739; B3:7324-7325);
  - dấu NaN → LONG_MIN → phép trừ tràn. MQL5 cho `(long)NaN == LONG_MIN` đã được dùng trong `Bot1RoundPrice` và qua các ca "số không hợp lệ" (`PHAN-TICH-BOT-1-3.md:48-49,66-69`). Tràn khi trừ trong MQL5 — chưa kiểm.

## 4. Đề xuất MQL5 đã sửa (chỉ các hàm không còn nhánh chưa rõ)
- Loại 0x3d200, 0x47f10, 0x482b0 vì lệnh in 7 đối số chưa rõ.
- Phần khởi động (B1:14892-14893) và phần xóa bảng (B1:2014-2016) giữ như lần trước, chỉ đổi phép thử sang `guard==1`.

```mql5
// Bot1VirtualStopState.mqh: bounded parts only; not compiled, not compared.
// RVAs 0x18790 (drop closed rows), 0x3d5a0 (delay), 0x3d640 (stamp).
// Excluded: 0x3d200, its 7-argument Dispatch (C 27186-27187) is unresolved.
#ifndef BOT1_VIRTUAL_STOP_STATE_MQH
#define BOT1_VIRTUAL_STOP_STATE_MQH
#define BOT1_VIRTUAL_STOP_ROWS 500
struct Bot1VirtualStopTable
{
   double ticket[BOT1_VIRTUAL_STOP_ROWS]; // RVA 0x62590, stride 24; 0.0 = free
   double level[BOT1_VIRTUAL_STOP_ROWS];  // row +8
   double stamp[BOT1_VIRTUAL_STOP_ROWS];  // row +16, TimeCurrent() as double
   uchar  guard;                          // RVA 0x66410; every native test is ==1
   long   reported_ticket;                // RVA 0x66418; used by 0x3d200 only
};
int Bot1CollectOpenTickets(long &open_tickets[])
{
   if(ArraySize(open_tickets)<64) ArrayResize(open_tickets,64);
   int total=PositionsTotal();
   int count=0;
   for(int i=0;i<total;i++)
   {
      ulong ticket=PositionGetTicket(i);
      if(ticket==0) continue;
      if((ulong)PositionGetInteger(POSITION_TYPE)>=2) continue;
      if(ArraySize(open_tickets)<=count) ArrayResize(open_tickets,count+64);
      open_tickets[count]=(long)ticket;
      count++;
   }
   return count;
}
bool Bot1TicketListed(const long &open_tickets[],const int count,const double row_ticket)
{
   for(int k=0;k<count;k++)
      if(open_tickets[k]==(long)row_ticket) return true;
   return false;
}
void Bot1DropClosedVirtualStops(Bot1VirtualStopTable &table,long &open_tickets[])
{
   int count=Bot1CollectOpenTickets(open_tickets);
   if(table.guard!=1) return;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
   {
      if(!(0.0<table.ticket[row])) continue;
      if(Bot1TicketListed(open_tickets,count,table.ticket[row])) continue;
      table.stamp[row]=0.0;
      table.level[row]=0.0;
      table.ticket[row]=0.0;
   }
}
bool Bot1VirtualStopDelayPassed(const Bot1VirtualStopTable &table,const long ticket,const int delay_seconds)
{
   if(delay_seconds<=0 || table.guard!=1) return false;
   for(int i=0;i<BOT1_VIRTUAL_STOP_ROWS;i++)
   {
      if(table.ticket[i]!=(double)ticket) continue;
      long stamp=(long)table.stamp[i];
      if(stamp==0) return true;
      return delay_seconds<=(long)TimeCurrent()-stamp;
   }
   return false;
}
void Bot1VirtualStopStamp(Bot1VirtualStopTable &table,const long ticket)
{
   if(table.guard!=1) return;
   for(int i=0;i<BOT1_VIRTUAL_STOP_ROWS;i++)
   {
      if(table.ticket[i]!=(double)ticket) continue;
      table.stamp[i]=(double)(long)TimeCurrent();
      return;
   }
}
#endif
```

```mql5
// Bot3VirtualTableState.mqh: Collect/Listed/Delay/Stamp are the Bot1 text with prefix Bot3
// and stop_* fields. Differences: layout and the B rows in the drop loop (C 15345-15369).
struct Bot3VirtualTables
{
   double stop_ticket[500],stop_level[500],stop_stamp[500]; // RVA 0x6d680, stride 24
   double take_ticket[500],take_level[500];                 // RVA 0x70560, stride 16
   uchar  guard;                                            // RVA 0x73450
   long   stop_reported_ticket,take_reported_ticket;        // RVA 0x73458, 0x73460
};
void Bot3DropClosedVirtualRows(Bot3VirtualTables &tables,long &open_tickets[])
{
   int count=Bot3CollectOpenTickets(open_tickets);
   if(tables.guard!=1) return;
   for(int row=0;row<500;row++)
   {
      if(0.0<tables.stop_ticket[row] && !Bot3TicketListed(open_tickets,count,tables.stop_ticket[row]))
      {
         tables.stop_stamp[row]=0.0;
         tables.stop_level[row]=0.0;
         tables.stop_ticket[row]=0.0;
      }
      if(0.0<tables.take_ticket[row] && !Bot3TicketListed(open_tickets,count,tables.take_ticket[row]))
      {
         tables.take_ticket[row]=0.0;
         tables.take_level[row]=0.0;
      }
   }
}
```

`open_tickets` phải là **một mảng `long` toàn cục dùng chung** với lời gọi từ luồng điều phối (B1:9224-9226; B3:12986-12988).

## 5. Còn thiếu
1. Đọc 7 cặp thẻ/giá trị (mục 1) ở cả ba điểm in; sau đó mới dựng 0x3d200, 0x47f10, 0x482b0.
2. Hiệu chuẩn helper 0x7aa0e0, helper 0x3959a0, mã Dispatch 2 và thuộc tính 2.
3. So bit và vết gọi giữa mã gốc và bản MQL5 cho các hàm ở mục 4, gồm cả lời gọi nới mảng, với G = 0, 1, 2, 0xFF.
4. Kiểm trường hợp hết bộ nhớ và vị thế đóng giữa vòng trong bộ mô phỏng.
