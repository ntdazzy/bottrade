Đây là **đề xuất**, chưa biên dịch và chưa chạy. Tôi không dùng công cụ, không tạo hay sửa tệp nào. Bốn hằng K0..K3 lấy theo số bạn báo; tôi chưa mở `constants.json`. Thân hàm bám theo B1:10649–10750 và B3:3912–4013.

**Tệp gợi ý 1:** `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1AmericanDST.mqh`

```mql5
// AmericanDST() from native RVA 0x17840; constants 7.0/14.0/1.0/31.0 at RVA 0x4ffa0..0x4ffb8.
#ifndef BOT1_AMERICAN_DST_MQH
#define BOT1_AMERICAN_DST_MQH
bool Bot1AmericanDST()
{
   MqlDateTime dt;
   TimeToStruct(TimeCurrent(),dt);
   if(dt.year<1987)
   {
      Print("AmericanDST(): Invalid year.");
      return false;
   }
   int year=dt.year;
   double start_day=0.0;
   double end_day=0.0;
   datetime start_base=0;
   datetime end_base=0;
   if(year<2007)
   {
      start_day=MathMod(year*6-year/4+2,7.0)+1.0;
      end_day=31.0-MathMod(year*5/4+1,7.0);
      string start_text="";
      StringConcatenate(start_text,year,".04.01");
      string end_text="";
      StringConcatenate(end_text,year,".10.01");
      start_base=StringToTime(start_text);
      end_base=StringToTime(end_text);
   }
   else
   {
      int cycle=year*5/4+1;
      start_day=14.0-MathMod(cycle,7.0);
      end_day=7.0-MathMod(cycle,7.0);
      string start_text="";
      StringConcatenate(start_text,year,".03.01");
      string end_text="";
      StringConcatenate(end_text,year,".11.01");
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
         return true;
   }
   return false;
}
#endif
```

**Tệp gợi ý 2:** `dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3AmericanDST.mqh`

```mql5
// AmericanDST() from native RVA 0x7e20; constants 7.0/14.0/1.0/31.0 at RVA 0x57d80..0x57d98.
#ifndef BOT3_AMERICAN_DST_MQH
#define BOT3_AMERICAN_DST_MQH
bool Bot3AmericanDST()
{
   MqlDateTime dt;
   TimeToStruct(TimeCurrent(),dt);
   if(dt.year<1987)
   {
      Print("AmericanDST(): Invalid year.");
      return false;
   }
   int year=dt.year;
   double start_day=0.0;
   double end_day=0.0;
   datetime start_base=0;
   datetime end_base=0;
   if(year<2007)
   {
      start_day=MathMod(year*6-year/4+2,7.0)+1.0;
      end_day=31.0-MathMod(year*5/4+1,7.0);
      string start_text="";
      StringConcatenate(start_text,year,".04.01");
      string end_text="";
      StringConcatenate(end_text,year,".10.01");
      start_base=StringToTime(start_text);
      end_base=StringToTime(end_text);
   }
   else
   {
      int cycle=year*5/4+1;
      start_day=14.0-MathMod(cycle,7.0);
      end_day=7.0-MathMod(cycle,7.0);
      string start_text="";
      StringConcatenate(start_text,year,".03.01");
      string end_text="";
      StringConcatenate(end_text,year,".11.01");
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
         return true;
   }
   return false;
}
#endif
```

## Cách bám mã gốc
- Hai thân hàm giống hệt nhau; chỉ khác tên, include guard và RVA trong chú thích.
- **Số lần gọi `TimeCurrent`:** 1 khi năm < 1987; 2 khi trượt phép so đầu kỳ; 3 khi qua cả hai phép so.
- **Thứ tự lời gọi:**
  1. `TimeToStruct`, rồi 2 lần `MathMod`.
  2. `StringConcatenate` cho s1, rồi s2.
  3. `StringToTime` cho s1, rồi s2.
  4. `TimeToStruct` giờ hiện tại, rồi mốc đầu kỳ.
  5. Nếu qua phép so đầu kỳ: `TimeToStruct` giờ hiện tại, rồi mốc cuối kỳ.
- **Chuỗi khai báo trong từng nhánh**, vì gốc dùng ô nhớ riêng cho mỗi nhánh (`local_a8/b8`, `local_c8/d8`). Gốc hủy hai chuỗi ngay sau hai lần `StringToTime`, trước `TimeCurrent` lần 2 (B1:10729–10733).
- **`=""` thay cho phép gán từ `DAT_23e5aa617e0`** (B1:10701; bot 3 là `DAT_171562a9d20`, B3:3964). Giá trị gốc này chưa giải mã.
- **Chuyển kiểu:** `(int)` cắt phần lẻ, đặt ở chỗ dùng. Phép nhân/trừ 86400 tính bằng int32 rồi mới cộng vào `datetime`, như gốc `(longlong)((int)dVar4*0x15180+-0x15180)` (B1:10737, 10743).
- **So năm 2007:** gốc so không dấu (B1:10691), nhưng tương đương vì năm đã ≥ 1987.
- **So ngày:** so có dấu và chặt cả hai đầu, nên cả ngày S lẫn ngày E đều trả `false`. 7200 giây không đổi kết quả, vì hàm chỉ so `day_of_year`.
- Gán `0`/`0.0` ban đầu cho 4 biến chỉ để tránh cảnh báo biến chưa gán; cả hai nhánh luôn ghi đè.
- K0..K3 khớp giả thuyết cũ, nên bảng mốc ở báo cáo trước giờ là kỳ vọng tĩnh của đề xuất (vd. 2026: S = 08/03, E = 01/11). Bảng này chưa được chạy để xác nhận.

## 5 điểm cần kiểm bằng mã gốc
1. **Mã thao tác 2 có phải `Print` không** (B1:10688, B3:3951). `api-calibration.json` chưa có op 2. Cần hiệu chuẩn bằng một chương trình mẫu gọi `Print` trên cùng engine. Nếu nhãn `MT5_MathMod` cũng chưa có bằng chứng hiệu chuẩn thì kiểm luôn.
2. **Giá trị trả về ở biên.** Chạy hàm gốc (giả lập RVA 0x17840 / 0x7e20, thay `TimeCurrent`) và đề xuất trên cùng mốc:
   - Năm 1986: kỳ vọng in 1 dòng và trả `false`.
   - Năm 1987, 2006, 2007, 2024, 2026, các mốc:
     - S−1 lúc 23:59:59
     - S lúc 00:00, 02:00, 23:59:59
     - S+1 lúc 00:00
     - E−1 lúc 23:59:59
     - E lúc 00:00, 23:59:59
     - E+1 lúc 00:00
3. **Vết lời gọi.** Ghi thứ tự, đối số và kết quả của `TimeCurrent`, `TimeToStruct`, `MathMod`, `StringConcatenate`, `StringToTime`, `Print`. Kỳ vọng ví dụ:
   - Năm 2026: `MathMod(2533.0,7.0)` hai lần; chuỗi `"2026.03.01"` rồi `"2026.11.01"`.
   - Năm 1987: `MathMod(11428.0,7.0)`, `MathMod(2484.0,7.0)`; chuỗi `"1987.04.01"` rồi `"1987.10.01"`.
4. **Mỗi phép so dùng đúng lần đọc giờ.** Cho `TimeCurrent` trả giá trị khác nhau giữa các lần gọi.
   - Ví dụ: lần 1–2 là 2026.10.31 12:00, lần 3 là 2026.11.01 12:00. Đề xuất trả `false`; nếu phép so cuối kỳ dùng giá trị lần 2 thì sẽ thành `true`.
   - Kiểm tương tự để chắc năm được lấy từ lần 1.
5. **Nơi gọi khác nhau giữa hai bot.** Bot 3 gọi hàm trong 0xc30 (B3:1608–1614). Trong C của bot 1 không thấy lời gọi tương ứng (B1:1552–1556). Cần kiểm mã máy 0xc30 của bot 1 trước khi nối hàm vào phần khởi tạo, vì điều này đổi số lần gọi `TimeCurrent` lúc khởi động.

Còn thiếu: biên dịch bằng MetaEditor (0 lỗi, 0 cảnh báo) và so với EX5 gốc. Tới lúc đó, phần `AmericanDST` trong P26 chỉ là "đã dựng đề xuất, chưa kiểm".
