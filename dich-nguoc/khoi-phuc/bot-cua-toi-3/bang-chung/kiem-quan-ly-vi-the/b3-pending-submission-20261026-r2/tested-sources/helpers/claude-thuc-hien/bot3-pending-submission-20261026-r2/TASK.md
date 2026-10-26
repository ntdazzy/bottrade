# Viết khối đặt lệnh chờ MQL5 theo mô tả đã chốt

Viết `Bot3PendingSubmission.mqh` và `SUMMARY.md` ngay trong thư mục đề xuất này. Chỉ đọc các header hiện hành được nêu dưới đây để dùng đúng giao diện. Codex đã phân tích và chốt chức năng; bạn viết mã từ mô tả. Không đọc EX5, mã máy, mã C trung gian hoặc tự tìm thuật toán. Không sửa nguồn chính, Git hay MT5. Không chạy lệnh hoặc tạo tác tử. Yêu cầu Opus5.5 max và ultracode; Codex kiểm cấu hình thực tế riêng.

Đây là khối trong chương trình MQL5, nhận giá cơ sở đã tính xong và xử lý từ kiểm tiền đến đặt lệnh, thử lại và ghi bảng. Chưa phải toàn bộ chương trình. Không thêm điều kiện, giới hạn số lần thử, kiểm dừng, sửa hành vi lạ hoặc giá trị mặc định.

## Giao diện bắt buộc

Header guard và include các tệp hiện hành trong `bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/`: `Bot3PriceLevels.mqh`, `Bot3Margin.mqh`, `Bot3VolumeValidation.mqh`, `Bot3OrderScan.mqh`, `Bot3TradeSend.mqh`, `Bot3TradeErrors.mqh`. Đường include cùng thư mục.

```mql5
struct Bot3PendingSubmissionSettings
{
   string symbol,comment;
   uchar check_free_margin,omit_real_sl_tp,virtual_expiration;
   int strategy_magic;
   datetime expiration;
   double unit,stop_distance,take_distance;
   double minimum_stop_price,minimum_freeze_price;
   double ask,bid;
};
void Bot3SubmitPendingAfterPrice(const bool buy,const double base_price,
                               const Bot3PendingSubmissionSettings &settings,
                               const double &volumes[],const uint &strategy_index,
                               double &results[][2],uint &error_count,
                               Bot3PendingRequestState &trade,Bot3TradeSendOptions &options);
```

`volumes` có9phần tử và chỉ số hợp lệ0..8. `results` đã có100hàng,2cột. Không thêm nới mảng hoặc kiểm khác. Các đối số tham chiếu vẫn là dữ liệu đang dùng: dịch vụ hoặc hàm con có thể làm chúng thay đổi, vì vậy không chụp toàn bộ struct hoặc giữ lại volume/index sớm. `base_price`, hướng mua/bán và ba giá đã làm tròn bên dưới là giá trị cục bộ giữ nguyên qua các lần thử. Hàm void, kết thúc ở các điểm return được chỉ rõ.

## Thứ tự xử lý

1. Nếu `settings.check_free_margin!=0`: đọc `volumes[strategy_index]` vào biến double TRƯỚC khi sao chép `settings.symbol` vào string cục bộ. Gọi `Bot3MarginGuard(symbol_copy,buy ? ORDER_TYPE_BUY : ORDER_TYPE_SELL,volume_captured)`. False: `Print("Free margin not sufficient for setting order..."); return;`. Cờ0 thì bỏ bước này.
2. Gọi `SymbolInfoInteger(settings.symbol,SYMBOL_DIGITS)` lấy uintdigits lần1. SAU dịch vụ mới đọc `settings.unit`. Giá thô là `settings.unit*(buy ? +0.0 : -0.0)+base_price`, nhân trước cộng sau. Dấu âm của0.0 phía bán phải được giữ; không đơn giản hóa thành base_price vì số không hữu hạn có hành vi khác. `price=Bot3RoundPrice(raw_price,digits1)`.
3. Gọi Digits MỚI lần2; SAU dịch vụ đọc `settings.stop_distance`, cộng `+0.0`, nhân `settings.unit`. Phía mua: `base_price-((settings.stop_distance+0.0)*settings.unit)`; phía bán: `((settings.stop_distance+0.0)*settings.unit)+base_price`. `sl=Bot3RoundPrice(raw_sl,digits2)`.
4. Gọi Digits MỚI lần3; SAU dịch vụ đọc `settings.take_distance` và `settings.unit`. Phía mua: `settings.take_distance*settings.unit+base_price`; phía bán: `base_price-settings.take_distance*settings.unit`. `tp=Bot3RoundPrice(raw_tp,digits3)`. Luôn làm đủ ba lần kể cả khi omit_real_sl_tp!=0.
5. Đọc LẠI `volumes[strategy_index]`, gọi `Bot3ValidateVolume(settings.symbol,volume)`. False thì return.
6. Gọi `Bot3AllowsPendingOrder()`. False thì return.
7. Phía mua: đọc ask một lần vào double cục bộ; kiểm `ask < price-settings.minimum_freeze_price`, không đạt thì return; sau đó kiểm `ask < price-settings.minimum_stop_price`, không đạt thì return. Phía bán đọc bid một lần; kiểm `settings.minimum_freeze_price+price < bid`, sau đó `settings.minimum_stop_price+price < bid`. Giữ nguyên thứ tự toán hạng và điều kiện nghiêm ngặt; NaN không đạt. Không đảo thứ tự hai mức.
8. Chuẩn bị và gọi lần đặt đầu theo quy trình C bên dưới. Giữ bool trả về `accepted` của `Bot3OpenPending`; đây KHÔNG phải số vé.
9. Nếu lần đặt ĐẦU accepted==true: quét hàng0..99. Hàng trống khi cột0 bằng0.0 (NaN không trống). Tại hàng trống đầu tiên ghi cột0=`(double)(uint)accepted` (bằng1.0), cột1=`base_price` (KHÔNG phải price đã làm tròn), rồi kết thúc. Bảng đầy thì kết thúc và không đổi bảng. Không báo lỗi/thử lại trong nhánh này.
10. Nếu lần đầu false: `while(GetLastError()==132) { Sleep(2500); đặt lại theo C; }`. BỎ QUA bool trả về của lần đặt lại. Chỉ `GetLastError()` quyết định tiếp vòng, kể cả lần đặt lại trảtrue nhưng mã vẫn132. Không đặt giới hạn vòng hoặc thêm IsStopped. Các ca kiểm phải cấp dãy lỗi hữu hạn để không treo.
11. Khi ra khỏi vòng ở bước10, LUÔN báo lỗi, kể cả lần đặt lại đã trảtrue. Gọi `string text=Bot3TradeErrorText(GetLastError(),error_count);`. Tạo chuỗi theo thứ tự: `string prefix="error: '"; prefix+=text; string message=prefix; message+="' when setting entry order"; Print(message);`. Không ghi bảng results sau bất kỳ lần thử lại nào. Không reset mã lỗi hoặc error_count.

## C. Mỗi lần đặt, lần đầu và thử lại đều dùng cùng quy trình

- Đọc `settings.expiration` vào datetime cục bộ ĐẦU TIÊN.
- Sau đó mới đọc `settings.omit_real_sl_tp`. Nếu0 dùng sl/tp cục bộ đã tính ở bước3/4; nếu khác0 gửi double0.0/0.0. Giữ ba giá cục bộ ban đầu khi thử lại, không đọc Digits/tính lại.
- Sao chép `settings.comment` vào string cục bộ.
- SAU sao chép comment, đọc LẠI `volumes[strategy_index]` vào double cục bộ.
- SAU đọc volume, sao chép `settings.symbol` vào string cục bộ.
- Gọi `Bot3OpenPending(trade,options,settings.strategy_magic,settings.virtual_expiration,symbol_copy,buy ? ORDER_TYPE_BUY_STOP : ORDER_TYPE_SELL_STOP,volume_captured,price,send_sl,send_tp,comment_copy,expiration_captured)`. Hai kiểu lệnh tương ứng4/5. Magic/virtual_expiration vẫn đọc sau sao chép symbol, dùng options hiện hành; không giữ từ trước.
- Được tách MỘT hàm private thực hiện C để không chép trùng hai lần. Không tạo lớp/callback/kiến trúc mới.

Mã cần ngắn, rõ, đúng kiểu. Không sửa các hàm con đã có hoặc tự thay chúng bằng công thức gần giống. Kiểm tên biến MQL5 tránh từ dành riêng `input`. Chỉ bàn giao mã thật, không hàm rỗng, không TODO thay chức năng. SUMMARY ghi rõ đã viết gì và chưa tự biên dịch/chạy kiểm.
