Tôi đã phân tích xong: thân hàm của bot 1 và bot 3 giống nhau từng lệnh, chỉ khác địa chỉ. **Còn thiếu giá trị 4 hằng số thực (`double`)** mà hàm dùng, nên chưa đủ bằng chứng để đưa mã MQL5 hoàn chỉnh. Bốn hằng này chỉ có trong tệp `.bin`. Công cụ Read không đọc được tệp nhị phân và tôi không dùng Bash theo yêu cầu. Tôi chưa tự tính lại SHA-256 và không sửa hay chạy gì.

Tên hàm gốc gần như chắc là `AmericanDST`, lấy từ chuỗi báo lỗi của chính hàm.

## Nguồn đã đọc
| Viết tắt | Tệp | Dòng |
|---|---|---|
| B1 | `dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/luot-20261023-data-v2/ma-trung-gian.c` | 10649–10750 (RVA 0x17840–0x17d17) |
| B3 | `dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c` | 3912–4013 (RVA 0x7e20–0x82f7) |
| B1-cũ | `bot-cua-toi-1/phan-tich/ban-ex5-05/ma-trung-gian.c` | 6565–6672 (bản này hiện đủ tham số các lời gọi `MT5_Dispatch`) |
| B3-c2 | `bot-cua-toi-3/phan-tich/luot-20261023-c2/ma-trung-gian.c` | 1976–2044 (đủ tham số) |

- Mã thao tác 372 (0x174) là `StringConcatenate`, theo `ban-do-bot-1-3/luot-20261023-r5/api-calibration.json:14`.
- Mã thao tác 2 chưa được hiệu chuẩn (`bot-1.json:3367-3369`). Hành vi của nó trong nhật ký gốc khớp với `Print`.

## Đầu vào và đầu ra
- Hàm không có tham số. Thời gian duy nhất nó đọc là `TimeCurrent()` (giờ máy chủ), gọi tối đa 3 lần. Hàm không dùng `TimeGMT`, `TimeLocal` hay `TimeTradeServer`.
- Hàm trả 0 hoặc 1. Mọi nơi gọi chỉ thử byte thấp (`== '\0'`), nên kiểu trả về là `bool`.
- Nơi gọi:
  - **Bot 1:**
    - 0x10f60 (B1:8350): đúng → dùng `Broker_GMT_OFFSET_Summer`, sai → dùng `Broker_GMT_OFFSET_Winter` (B1:8354, 8371).
    - 0x18aa0 (B1:12759, 12942, 13042): đúng → lệch 0 giây, sai → lệch 3600 giây.
  - **Bot 3:**
    - 0xc30 (B3:1608–1614): `DAT_171562c5358 = TimeCurrent() − (đúng ? Summer : Winter)×3600`.
    - 0x17f00 (B3:12051) và 0x20ef0 (B3:16921, 17150, 17338): dùng giống bot 1.

## Thuật toán (B1, số dòng B3 tương ứng)
1. `TimeToStruct(TimeCurrent(), dt)` (10684–10685). `local_98[0]` là `dt.year`, `local_7c` (lệch +0x1C) là `dt.day_of_year`, đếm từ 0.
2. **Nhánh lỗi:** nếu `(int)year < 1987` (0x7c3), hàm in `"AmericanDST(): Invalid year."` rồi trả `false` (10687–10688, 10749).
   - Chuỗi lấy từ tham số ở B1-cũ:6604. Địa chỉ 0x…6cbb8 trỏ tới `strings.tsv:795` (bot 3: `strings.tsv:1019`).
   - Nếu `TimeCurrent()` trả 0 (năm 1970) thì cũng rơi vào nhánh này.
3. **Năm 1987–2006** (`year < 2007`, 0x7d7; dòng 10691–10706):
   - `S = MathMod((double)(6*year − year/4 + 2), K0) + K2`
   - `E = K3 − MathMod((double)(year*5/4 + 1), K0)`
   - Chuỗi ngày gốc: `StringConcatenate(s1, year, ".04.01")` và `StringConcatenate(s2, year, ".10.01")` (B1-cũ:6618–6624, 6648–6649).
4. **Năm ≥ 2007** (10709–10726):
   - `d = (double)(year*5/4 + 1)`. Phép chia nguyên cắt về 0, bằng thủ thuật `+3` / `>>2`.
   - `S = K1 − MathMod(d, K0)`
   - `E = K0 − MathMod(d, K0)`
   - Chuỗi ngày gốc: `".03.01"` và `".11.01"` (B1-cũ:6640–6646).
5. **Kiểu số:** `year` là `int` 32 bit. Các biểu thức nguyên được tính bằng `int` rồi mới đổi sang `double`. `S` và `E` là `double`.
6. Hàm gọi `StringToTime(s1)` rồi `StringToTime(s2)`, sau đó giải phóng s2 rồi s1 (10729–10732).
7. **So đầu kỳ** (10733–10738):
   - Gọi `TimeCurrent()` lần 2 để lấy `today`.
   - `startDoy = day_of_year(tS + 7200 + ((int)S*86400 − 86400))`. `(int)` là cắt phần lẻ; phép nhân tính bằng `int` rồi mới cộng vào `datetime`.
   - Điều kiện: `startDoy < today` (so **chặt**).
8. **So cuối kỳ** (10739–10745):
   - Gọi `TimeCurrent()` lần 3, rồi tính `endDoy` theo cùng cách với `tE` và `E`.
   - Điều kiện: `today < endDoy` (so **chặt**). Nếu đạt thì trả `true`; mọi trường hợp khác trả `false`.

**Ý nghĩa:** hàm trả đúng khi và chỉ khi `doy(ngày S) < doy(hôm nay) < doy(ngày E)`.
- Mốc 02:00 (7200 giây) có được cộng vào nhưng **không có tác dụng**, vì hàm chỉ so `day_of_year`.
- Cả ngày S và cả ngày E đều trả `false`.
- Không có giới hạn năm trên.
- Năm dùng để dựng chuỗi lấy từ lần gọi `TimeCurrent()` thứ 1; ngày đem so lấy từ lần 2 và lần 3.

**Trạng thái bị ghi:** chỉ có biến cục bộ — `dt` và 4 chuỗi (`local_a8/b8` cho nhánh cũ, `local_c8/d8` cho nhánh mới).
- Không có lệnh ghi biến toàn cục nào trong 10676–10749.
- `FUN_105c0` được gọi với `param_3 = 0`, nên chỉ chép tham chiếu (B1:429–449). Đường lỗi cấp phát (B1:454–457) không chạy tới từ hàm này.
- Hàm không kiểm giá trị trả về của `TimeToStruct`, `StringToTime` và `StringConcatenate`.
- Giá trị gán ban đầu cho 4 chuỗi (`DAT_…617e0`) chưa giải mã, nhưng bị `StringConcatenate` ghi đè nên không ảnh hưởng kết quả.

## Bốn hằng chưa chốt
| Hằng | Vai trò | Bot 1 (offset trong `.bin`) | Bot 3 (offset trong `.bin`) |
|---|---|---|---|
| K0 | Số chia của cả 4 lần `MathMod`; số bị trừ khi tính E (năm ≥ 2007) | `DAT_23e5aa5ffa0` (+0xFA0) | `DAT_171562a7d80` (+0xD80) |
| K1 | Số bị trừ khi tính S (năm ≥ 2007) | +0xFA8 | +0xD88 |
| K2 | Cộng vào S (1987–2006) | +0xFB0 | +0xD90 |
| K3 | Số bị trừ khi tính E (1987–2006) | +0xFB8 | +0xD98 |

Tệp chứa hằng:
- Bot 1: `bot-cua-toi-1/bang-chung/captures/luot-20261023-r1/0000023e5aa5f000-program-data.bin`
- Bot 3: `bot-cua-toi-3/bang-chung/captures/luot-20261023-r1/00000171562a7000-program-data.bin`

Lệnh chỉ đọc để bạn tự chạy (bot 3: đổi đường dẫn và đổi `0xFA0` thành `0xD80`):
```powershell
$p='dich-nguoc\khoi-phuc\bot-cua-toi-1\bang-chung\captures\luot-20261023-r1\0000023e5aa5f000-program-data.bin'
Get-FileHash $p -Algorithm SHA256
$b=[IO.File]::ReadAllBytes($p); 0..3 | % { [BitConverter]::ToDouble($b, 0xFA0 + 8*$_) }
```
Giả thuyết: K0..K3 = 7, 14, 1, 31. Giả thuyết này dựa trên hiểu biết ngoài mã, **chưa kiểm**. Chỉ dùng khi 32 byte đọc ra khớp đúng:
`00 00 00 00 00 00 1C 40 | 00 00 00 00 00 00 2C 40 | 00 00 00 00 00 00 F0 3F | 00 00 00 00 00 00 3F 40`.

## So sánh hai bot
| Mục | Kết quả |
|---|---|
| Thân hàm | Giống từng lệnh. Cùng hằng số trong lệnh (1987, 2007, 6, 5, `>>2`, 7200, 86400), cùng mã thao tác 2/372, cùng kích thước 0x4d7 |
| Chuỗi | Trùng nhau: bot 1 `strings.tsv:795–799`, bot 3 `strings.tsv:1019–1023`. Thứ tự tham số giống nhau (B1-cũ:6618–6649 so với B3-c2:1991–2022) |
| 4 hằng `double` | Khác địa chỉ, **chưa biết giá trị**. Phải đọc riêng cho từng bot |
| Nơi gọi | **Có khác:** bot 3 gọi thêm hàm này trong 0xc30 (B3:1608). Ở vị trí tương ứng, 0xc30 của bot 1 không gọi (B1:1552–1556; `danh-sach-ham.json:202–219`). Kết luận này dựa trên bản C hiện có |

Hai chuỗi `".03.31 01:00"` và `".10.31 02:00"` đứng ngay sau trong bảng chuỗi nhưng **không** thuộc hàm này. Nơi dùng chúng chưa tìm ra, cần một mục riêng trong bảng theo dõi.

## Khung MQL5 (chưa hoàn chỉnh, chờ 4 hằng)
Khung này cố ý không biên dịch được cho tới khi điền 4 hằng.
```mql5
// AmericanDST: bot 1 RVA 0x17840, bot 3 RVA 0x7e20.
#define AMERICAN_DST_K0 /* double +0xFA0 (bot 1) | +0xD80 (bot 3) */
#define AMERICAN_DST_K1 /* +0xFA8 | +0xD88 */
#define AMERICAN_DST_K2 /* +0xFB0 | +0xD90 */
#define AMERICAN_DST_K3 /* +0xFB8 | +0xD98 */

bool AmericanDST()
{
   MqlDateTime dt;
   TimeToStruct(TimeCurrent(),dt);
   if(dt.year<1987)
   {
      Print("AmericanDST(): Invalid year.");
      return(false);
   }
   double start_day;
   double end_day;
   datetime start_base;
   datetime end_base;
   if(dt.year<2007)
   {
      start_day=MathMod(dt.year*6-dt.year/4+2,AMERICAN_DST_K0)+AMERICAN_DST_K2;
      end_day=AMERICAN_DST_K3-MathMod(dt.year*5/4+1,AMERICAN_DST_K0);
      string start_text="";
      StringConcatenate(start_text,dt.year,".04.01");
      string end_text="";
      StringConcatenate(end_text,dt.year,".10.01");
      start_base=StringToTime(start_text);
      end_base=StringToTime(end_text);
   }
   else
   {
      double cycle=dt.year*5/4+1;
      start_day=AMERICAN_DST_K1-MathMod(cycle,AMERICAN_DST_K0);
      end_day=AMERICAN_DST_K0-MathMod(cycle,AMERICAN_DST_K0);
      string start_text="";
      StringConcatenate(start_text,dt.year,".03.01");
      string end_text="";
      StringConcatenate(end_text,dt.year,".11.01");
      start_base=StringToTime(start_text);
      end_base=StringToTime(end_text);
   }
   TimeToStruct(TimeCurrent(),dt);
   int today=dt.day_of_year;
   TimeToStruct(start_base+7200+((int)start_day*86400-86400),dt);
   if(dt.day_of_year<today)
   {
      TimeToStruct(TimeCurrent(),dt);
      today=dt.day_of_year;
      TimeToStruct(end_base+7200+((int)end_day*86400-86400),dt);
      if(today<dt.day_of_year)
         return(true);
   }
   return(false);
}
```

## Ca kiểm mốc trước / bằng / sau
**Ca chắc chắn, không phụ thuộc 4 hằng:**
- Năm 1986 (hoặc `TimeCurrent()` = 0): in `"AmericanDST(): Invalid year."`, trả `false`, chỉ gọi `TimeCurrent()` 1 lần.

**Sau khi đọc được 4 hằng:**
- Với mỗi năm, tính S và E.
- Kiểm các thời điểm:
  - S−1 lúc 23:59:59 → F
  - S lúc 00:00, 02:00 và 23:59:59 → F
  - S+1 lúc 00:00 → T
  - E−1 lúc 23:59:59 → T
  - E lúc 00:00 và 23:59:59 → F
  - E+1 → F
- Các năm nên kiểm: 1987, 2006 (luật cũ); 2007, 2024 (năm nhuận), 2026 (luật mới).

Nếu giả thuyết 7/14/1/31 đúng, mốc ngày (dd/mm) và kết quả mong đợi là:

| Năm | S (doy) | E (doy) | Trước S | Bằng S | Sau S | Trước E | Bằng E | Sau E |
|---|---|---|---|---|---|---|---|---|
| 1987 | 05/04 (94) | 25/10 (297) | 04/04 F | F | 06/04 T | 24/10 T | F | 26/10 F |
| 2006 | 02/04 (91) | 29/10 (301) | 01/04 F | F | 03/04 T | 28/10 T | F | 30/10 F |
| 2007 | 11/03 (69) | 04/11 (307) | 10/03 F | F | 12/03 T | 03/11 T | F | 05/11 F |
| 2024 | 10/03 (69) | 03/11 (307) | 09/03 F | F | 11/03 T | 02/11 T | F | 04/11 F |
| 2026 | 08/03 (66) | 01/11 (304) | 07/03 F | F | 09/03 T | 31/10 T | F | 02/11 F |

## Cần quan sát thêm
1. **Bắt buộc:** 32 byte hằng của từng bot (lệnh ở trên).
2. **Chạy hàm gốc tại đúng các mốc**, theo một trong hai cách:
   - Giả lập RVA 0x17840 / 0x7e20 với `TimeCurrent` bị thay giá trị. Cách này phủ được cả 1986–2007. Phải giả lập thêm `TimeToStruct`, `StringToTime`, `MathMod` và Dispatch 372/2, và ghi rõ là API giả lập.
   - Dùng MT5 riêng để kiểm thử, với symbol tự tạo có tick đúng ngày biên (các ngày S/E có thể không có tick nếu dùng dữ liệu thường). Quan sát lúc nhật ký in `DST_US on/off`. Cách này đi qua nhánh AutoGMT: yêu cầu HTTP sẽ thất bại với lỗi 4014 như trong nhật ký cũ. Nếu không muốn chạm đường HTTP thì dùng cách giả lập.

## Giới hạn của bằng chứng
- Nhật ký gốc của cả hai bot chỉ có một mốc: "DST_US on" lúc 2026.09.29 00:00:02 (`b1-inputs-20261023-r2-defaults.log:110`, `b3-inputs-20261023-r3-defaults.log:118`).
  - Mốc này khớp với việc hàm trả đúng, nhưng chưa chứng minh được biên.
  - Chuỗi on/off gắn với nhánh nào cũng chưa chắc, vì tham số của lệnh in tại B1:8387 bị ẩn trong bản C.