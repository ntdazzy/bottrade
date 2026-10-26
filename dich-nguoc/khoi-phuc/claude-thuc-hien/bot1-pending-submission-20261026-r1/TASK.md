# Viết khối đặt lệnh chờ bot1 từ mô tả chức năng

Chỉ viết `Bot1PendingSubmission.mqh` và `SUMMARY.md` trong thư mục đề xuất này. Codex đã chốt chức năng và giao diện dưới đây. Đọc các header bot1 cần dùng; có thể đọc `Bot3PendingSubmission.mqh` hiện hành làm mẫu kiểu viết, nhưng PHẢI giữ khác biệt được nêu. Không đọc các thư mục phân tích hoặc tự tìm thuật toán. Không sửa mã chính/Git/MT5; không dùng shell/tạo tác tử. Opus5.5max và ultracode; cấu hình được kiểm riêng.

Khối này bắt đầu khi đã có giá cơ sở, xử lý đến đặt lệnh/thử lại/ghi bảng. Chưa phải chương trình chính đầy đủ. Không tự thêm điều kiện, giới hạn vòng thử, kiểm dừng hoặc giá trị mặc định.

## Giao diện

Include `Bot1PriceLevels.mqh`, `Bot1Margin.mqh`, `Bot1VolumeValidation.mqh`, `Bot1TradeSend.mqh`, `Bot1TradeErrors.mqh` cùng thư mục. Không include Bot1OrderScan vì khối này kiểm giới hạn trực tiếp.

Struct `Bot1PendingSubmissionSettings` giữ đúng kiểu và tên:
```mql5
string symbol,comment;
uchar check_free_margin,omit_real_sl_tp,virtual_expiration;
int strategy_magic;
datetime expiration;
double unit,stop_distance,take_distance;
double minimum_stop_price,minimum_freeze_price;
double ask,bid;
```

```mql5
void Bot1SubmitPendingAfterPrice(const bool buy,const double base_price,
                               const Bot1PendingSubmissionSettings &settings,
                               const double &volumes[],const uint &strategy_index,
                               double &results[][2],uint &error_count,
                               Bot1PendingRequestState &trade,Bot1TradeSendOptions &options);
```

volumes có8phần tử, strategy_index hợp lệ0..7; bảng results đã có100hàng2cột. Không tự nới mảng/thêm kiểm khác. Đối số tham chiếu vẫn được đọc mới ở các bước quy định; không chụp toàn struct hoặc giữ volume/index từ đầu. Giá cơ sở/hướng và các giá đã tính là giá trị cục bộ giữ qua các lần thử.

Thêm đúng một hàm số học nhỏ `Bot1SubmissionDifference(left,right)` kiểu double với thân: `if(left!=left) return left+0.0; if(right!=right) return right+0.0; return left-right;`. Đây là cách giữ dấu/phần dữ liệu NaN trong phép trừ khi biên dịch; không dùng MathIsValidNumber hoặc đổi phép so.

## Trình tự

1. Nếu check_free_margin!=0: đọc `double volume=volumes[strategy_index]` TRƯỚC sao chép `string symbol=settings.symbol`; gọi `Bot1MarginGuard(symbol,buy ? ORDER_TYPE_BUY : ORDER_TYPE_SELL,volume)`. False: Print chính xác `Free margin not sufficient for setting order...` rồi return. Flag0 bỏ bước.
2. Gọi SymbolInfoInteger(settings.symbol,SYMBOL_DIGITS) lấyuintdigits1; SAU dịch vụ mới đọc unit. `price=Bot1RoundPrice(settings.unit*(buy ? 0.0 : -0.0)+base_price,digits1)`. Giữ phép nhân, thứ tự cộng và dấu0.
3. Gọi Digits MỚI lần2. SAU dịch vụ đọc stop_distance, cộng0.0 rồi nhânunit. Mua: `raw_sl=Bot1SubmissionDifference(base_price,(settings.stop_distance+0.0)*settings.unit)`; bán: `raw_sl=((settings.stop_distance+0.0)*settings.unit)+base_price`. sl=Bot1RoundPrice(raw_sl,digits2).
4. Gọi Digits MỚI lần3. Mua: `raw_tp=settings.take_distance*settings.unit+base_price`; bán: `raw_tp=Bot1SubmissionDifference(base_price,settings.take_distance*settings.unit)`. tp=Bot1RoundPrice(raw_tp,digits3). Luôn tính cả3giá dù omit_real_sl_tp khác0.
5. Đọc LẠI volumes[strategy_index], gọi Bot1ValidateVolume(settings.symbol,volume). False return.
6. Đọc trực tiếp `int limit=(int)AccountInfoInteger(ACCOUNT_LIMIT_ORDERS);`. Chỉ khi limit!=0 gọi OrdersTotal() MỚI; nếu kết quả >=limit thì return. Ép64bit thànhint32 CÓ DẤU trước so, limit0 không gọi OrdersTotal. Không lấy giới hạn từ settings/hàm được cấp bool, không gọi hàm đếm lệnh riêng theo magic/symbol.
7. Mua: chụp ask=settings.ask một lần SAU các dịch vụ. Nếu `!(ask < price-settings.minimum_freeze_price)` return, rồi nếu `!(ask < price-settings.minimum_stop_price)` return. Bán: chụp bid một lần, kiểm lần lượt `settings.minimum_freeze_price+price < bid`, `settings.minimum_stop_price+price < bid`. Giữ thứ tự phép cộng; NaN không đạt.
8. Gọi lần đặt đầu theo quy trình C với first_attempt=true. Bool accepted trả về KHÔNG phải số vé.
9. Nếu lần ĐẦU acceptedtrue: quét100hàng tăng0..99, ôtrống khi cột0==0.0, NaN không trống. Hàng trống đầu: cột0=(double)(uint)accepted tức1.0, cột1=base_price KHÔNG phải price đã làmtròn. Kết thúc. Bảng đầy không đổi bảng, không báo lỗi/thử lại.
10. Nếu lần đầu false: `while(GetLastError()==132) { Sleep(2500); đặt lại theo C với first_attempt=false; }`. BỎ QUA bool từ lần thử lại. Không giới hạn số lần, không IsStopped/ResetLastError/breakontrue. Khi ra khỏi vòng LUÔN báo lỗi bước11 kể cả thử lại trảtrue; không ghi bảng sau thử lại.
11. `string text=Bot1TradeErrorText(GetLastError(),error_count); string prefix="error: '"; prefix+=text; string message=prefix; message+="' when setting entry order"; Print(message);`. Không reset bộ đếm/lỗi.

## C. Mỗi lần gọi đặt

Được tách một hàm nội bộ để không chép trùng. Cần phân biệt thứ tự đọc lần đầu và thử lại (khác bot3):
- LẦN ĐẦU: đọc `uchar omit=settings.omit_real_sl_tp` trước, rồi đọc `datetime expiration=settings.expiration`.
- THỬ LẠI: đọc expiration trước, rồi đọc omit.
- Dùng omitđãchụp để chọn send_sl/send_tp: omit0 dùng sl/tp cục bộ; khác0 dùng0.0/0.0. Không tính lại các giá hoặc gọi Digits khi thử lại.
- Sao chép stringcomment=settings.comment.
- SAU sao chép comment, đọc LẠI volume=volumes[strategy_index].
- SAU đọc volume, sao chép stringsymbol=settings.symbol.
- Gọi `Bot1OpenPending(trade,options,settings.strategy_magic,settings.virtual_expiration,symbol,buy ? ORDER_TYPE_BUY_STOP : ORDER_TYPE_SELL_STOP,volume,price,send_sl,send_tp,comment,expiration)` với magic/virtual_expiration/options còn mới. Hai kiểu4/5.

Giữ mã ngắn, rõ, không hàm rỗng hoặc luật tự thêm. Không sửa các header phụ thuộc. SUMMARY nêu các khác biệt bot1 so với bot3 và chưa tự biên dịch/chạy. Mọi xác nhận hành vi do bên quản lý đối chiếu độc lập.
