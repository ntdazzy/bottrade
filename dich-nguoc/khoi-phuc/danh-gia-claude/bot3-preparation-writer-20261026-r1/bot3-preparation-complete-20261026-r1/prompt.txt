# Viết khối chuẩn bị cài đặt MQL5 bot3

Viết `Bot3Preparation.mqh` và `SUMMARY.md` vào CHÍNH thư mục đề xuất này. Codex đã phân tích và chốt chức năng dưới đây, bạn viết theo mô tả. Không đọc EX5/mã máy/thư mục phân tích hoặc tự tìm thuật toán. Không dùng SPEC nháp preparation-full-r1/r2. Chỉ đọc `Bot3EntryProfiles.mqh`, `Bot3DistanceSettings.mqh` hiện hành để dùng tên trường/tham khảo kiểu; không gọi Bot3PrepareDistances thay cho quy trình này vì sẽ mất thứ tự đọc dữ liệu, các trường và trạng thái trước lỗi. Không sửa nguồn chính/Git/MT5, không chạy lệnh/tạo tác tử. Yêu cầu Opus5.5max, ultracode; Codex kiểm cấu hình riêng. Nếu không ghi được, trả đủ nội dung, không đổi nơi ghi.

Ngữ cảnh: đây là một hàm chuẩn bị trước khi xét một chiến lược MQL5. Nó nhận tham số đã nạp của chiến lược, đọc chỉ báo/thị trường rồi ghi đủ cài đặt đang dùng. Không tạo EA/bảng lựa chọn/tham số đầu vào mặc định, không thêm lệnh giao dịch hoặc quy tắc tự nghĩ. Tên `native_*` dưới đây là trường chưa xác định tên nghiệp vụ: giữ kiểu và giá trị, không đoán ý nghĩa.

## Giao diện và kiểu

Header guard, include `Bot3EntryProfiles.mqh`. Hai struct và một hàm public:

```mql5
void Bot3PrepareStrategy(const uint strategy_index,
                        const Bot3PreparationInputs &input,
                        Bot3PreparationState &state);
```

Hàm void, trả sớm khi mô tả yêu cầu; không đổi lỗi runtime thành bool/status im lặng. Không ZeroMemory/reset cả state: giữ những trường chưa đến lượt ghi. Cấu hình input& đọc mới sau mỗi dịch vụ; không chụp cả struct đầu hàm. strategy_index đã chụp tại bên gọi, không kiểm/thay nó. Không có kiểm cấp phép trong hàm này và không thay kiểm cấp phép ngoài hàm.

Inputs gồm:

- `string symbol, comment; int indicator_timeframe, indicator_period; double reference; uchar variable_distances, adjust_lots; Bot3EntryProfile entry;`
- Các trường đầu vào ở bảng chép bên dưới, với đúng kiểu cột đầu. Các cờ phải uchar, không bool để giữ byte nguyên; entry là struct hiện hành có int entry_frame/older_width/recent_width/last_shift và double gap_points.
- Các trường dùng trong tính toán: `double max_spread,buy_offset,sell_offset,nearby_radius,stop_distance,target_distance,trail_distance,trail_start,trail_limit,trail_step,native_6d368,native_6d370,trigger_distance,locked_distance,aux_offset,min_change; int expiration_hours,aux_older,aux_recent; uchar feature_flag,freeze_buffer_flag,aux_hour1,aux_scan50;`

State gồm:

- `int indicator_handle; double indicator_values[]; uint strategy_index; MqlTick tick; MqlDateTime calendar; double scale,lot_scale,point,unit,spread; string comment;`
- Mọi trường cột output trong bảng chép và bảng cuối, đúng kiểu output. Không tạo lại input symbol trong state. Có trường chung được nói tên trong tính toán chính là trường output của bảng, không tạo bản sao thứ hai.
- `double stop_min_price,freeze_min_price; uint expiration_seconds; long expiration;`

## A. Chỉ báo và tỷ lệ

1. Đọc indicator_timeframe rồi indicator_period vào int cục bộ trước dịch vụ. `state.indicator_handle=iATR(input.symbol,(ENUM_TIMEFRAMES)frame,period)`. Nếu handle<0: `Print("The creation of iATR has failed: Runtime error =",GetLastError());` rồi return. Không đọc trường khác/không xóa buffer/state.
2. `int copied=CopyBuffer(state.indicator_handle,0,0,100,state.indicator_values);` Nếu copied==0 return ngay, KHÔNG dùng <=0. ArraySetAsSeries(state.indicator_values,true) sau đó. Array là dynamic double đúng kiểu; giữ nội dung/độ dài CopyBuffer để lại khi nó trả âm.
3. Nếu ArraySize(indicator_values)<2, phải gây lỗi chỉ mục ở đọc ô1, trước khi thay scale/lot/index/giá. Có thể viết trong nhánh đó `state.scale=state.indicator_values[1]; return;`: khi mảng ngắn, đọc phát lỗi trước khi ghi state.scale, return không tới. Không thay bằng thông báo/false hay tự nới mảng. Với mảng đủ2ô KHÔNG đọc phần tử double nào; chỉ báo ở đây không tham gia công thức số.
4. ratio=1.0. Chỉ khi input.reference>=1000.0 (so có thứ tự, NaN không vào) gọi `double sample=iOpen(input.symbol,PERIOD_D1,1)`. Sau dịch vụ đọc reference MỚI, `ratio=sample/reference`. Không chặn/đổi reference0, phép chia phải gây lỗi runtime tự nhiên tại đây; đến lỗi chưa ghi scale.
5. `state.scale=input.variable_distances!=0 ? ratio : 1.0;` Sau ghi scale, local lot=1.0; nếu input.adjust_lots!=0 thì lot=1.0/state.scale (chia0 gây lỗi runtime, chưa ghi lot_scale). Ghi state.lot_scale=lot trước khi xét scale==0; nếu state.scale==0 thì state.scale=1.0. NaN không bằng0 nên không thay. Không lấy lot sau khi đã sửa scale0.

## B. Giá và đơn vị

6. state.strategy_index=strategy_index. Gọi SymbolInfoTick(input.symbol,state.tick) một lần; nếu false thì Print("Tick not ok") và VẪN tiếp tục, giữ phần tick mà dịch vụ đã để lại. Không tạo tick mới hay xóa giá cũ.
7. TimeCurrent(state.calendar) một lần, bỏ thời gian trả về, giữ MqlDateTime dịch vụ ghi.
8. Gọi `double point=SymbolInfoDouble(input.symbol,SYMBOL_POINT)`; ghi state.point=point rồi state.unit=point.
9. Nếu lần SymbolInfoInteger(input.symbol,SYMBOL_DIGITS) đầu==3, KHÔNG gọi lần thứ hai và ghi unit=state.point*10.0. Nếu lần đầu khác3, gọi Digits lần2; nếu lần2==5 ghi unit=state.point*10.0. Sau đó LUÔN gọi Digits một lần nữa để so==1, nếu đúng unit=state.point/10.0. Các phép nhân/chia đọc state.point mới sau dịch vụ, không dùng point cục bộ cũ.
10. state.spread=state.tick.ask-state.tick.bid. Sau ghi spread, gọi Digits thêm một lần và bỏ kết quả. KHÔNG gọi Tick lần thứ hai tại đây.

## C. Chép tham số đang dùng theo đúng thứ tự

Chụp `const double scale=state.scale` SAU lần Digits bỏ kết quả và trước bảng này. Dùng scale này cho tất cả dấu `*scale` bên dưới, kể cả locked đảo thứ tự toán hạng. Không gọi các hàm tải bảng chiến lược trong hàm; input đã được bên gọi nạp.

| Kiểu input | input field / biểu thức | Kiểu output | state field |
|---|---|---|---|
| uchar | feature_flag | uchar | feature_flag |
| double | max_spread*scale | double | max_spread |
| uchar | (uint)freeze_buffer_flag*2 | int | freeze_buffer |
| double | native_6d250 | double | native_6d4e0 |
| uchar | native_6d258 | int | native_6d4e8 |
| double | native_6d260 | double | native_6d4f0 |
| double | native_6d268 | double | native_6d4f8 |
| double | native_6d270 | double | native_6d500 |
| uchar | native_6d278 | uchar | native_6d508 |
| int | native_1d6fa8 | int | native_6d50c |
| uchar | native_1d6fc0 | uchar | native_6d510 |
| uchar | virtual_expiration | uchar | virtual_expiration |
| uchar | virtual_stops==0 ? 1 : 2 | int | mode |
| int | native_1d6fe8 | int | native_6d518 |
| uchar | native_1d7178 | uchar | native_6d51c |
| uchar | native_6d2a3 | int | native_6d520 |
| int | entry.entry_frame | int | entry_frame |
| int | entry.older_width | int | older_width |
| int | entry.recent_width | int | recent_width |
| int | entry.last_shift | int | last_shift |
| double | entry.gap_points*scale | double | gap_points |
| double | buy_offset*scale | double | buy_offset |
| double | sell_offset*scale | double | sell_offset |
| int | native_6d2e0 | int | native_6d550 |
| double | nearby_radius*scale | double | nearby_radius |
| int | expiration_hours | int | expiration_hours |
| int | management_timeframe | int | management_timeframe |
| double | stop_distance*scale | double | stop_distance |
| double | target_distance*scale | double | target_distance |
| double | trail_distance*scale | double | trail_distance |
| double | trail_start*scale | double | trail_start |
| double | native_6d368*scale | double | native_6d378 |
| double | native_6d370*scale | double | native_6d380 |
| double | trail_limit*scale | double | trail_limit |
| double | trail_step*scale | double | trail_step |
| - | 0 | uchar | native_6d5c8 |
| double | trigger_distance*scale | double | trigger_distance |
| double | scale*locked_distance | double | locked_distance |
| - | +0.0 | double | native_6d5f0 |
| uchar | aux_hour1!=0 ? (int)PERIOD_H1 : 0 | int | aux_frame |
| uchar | aux_scan50!=0 ? 50 : 0 | int | aux_scan |
| int | aux_older | int | aux_older |
| int | aux_recent | int | aux_recent |
| double | aux_offset | double | aux_offset |
| - | 0 | uchar | native_6d5dc |
| - | +0.0 | double | native_6d5e8 |
| uchar | native_6d3f8 | int | native_6d608 |
| - | 0 | uchar | native_6d5f8 |
| double | native_6d3f0 | double | native_6d600 |
| double | min_change | double | min_change |

11. Sau bảng, gán state.comment=input.comment một lần (không StringFormat/chuẩn hóa/chuyển thành số). Sau gán chuỗi, chụp `const double candidate=state.min_change*state.unit` TRƯỚC bảng cuối dưới; không tính lại candidate sau dịch vụ.

| Kiểu input | input / biểu thức | Kiểu output | state field |
|---|---|---|---|
| double | native_6d408 | double | native_6d618 |
| double | native_1d7138 | double | native_6d620 |
| double | native_6d410 | double | native_6d628 |
| int | native_1d7130 | int | native_6d630 |
| double | native_6d418 | double | native_6d638 |
| uchar | native_6d420!=0 ? 600 : 0 | int | native_6d640 |

## D. Giới hạn giá và chuẩn hóa

12. Gọi SymbolInfoDouble(symbol,SYMBOL_POINT) một lần và so candidate<giá trị vừa trả. Nếu đúng: gọi POINT lần nữa, lấy point của LẦN NÀY chia state.unit đọc MỚI và ghi state.min_change. Nếu unit0 phải để phép chia phát lỗi trước khi ghi; đừng tự đổi thành0/false. Không ghi lại state.point từ hai lần này.
13. Gọi SymbolInfoInteger(symbol,SYMBOL_TRADE_STOPS_LEVEL), giữ full long kết quả. Sau đó gọi SymbolInfoDouble(symbol,SYMBOL_POINT), ghi state.stop_min_price=(double)longStops*pointVừaTrả. Tương tự gọi FREEZE_LEVEL rồi POINT một lần mới, ghi state.freeze_min_price. Không dùng point đã lưu trước đó hay gộp hai lần đọc POINT. Tên mã luôn input.symbol đọc mới.
14. Chụp local stop=state.stop_distance; nếu stop<=0 thì ghi state.stop_distance=1.0 và localstop=1.0. Tiếp đó làm tương tự target. Nếu state.trigger_distance<state.locked_distance, ghi locked_distance=trigger_distance+0.1. NaN so có thứ tự: không điều kiện trên đúng khi bất kỳ toán hạng NaN.
15. Chụp const unit=state.unit; const freeze_units=state.freeze_min_price/unit. unit0 để phép chia phát lỗi runtime trước các ghi ở bước này. Nếu (double)state.freeze_buffer<freeze_units thì ghi freeze_buffer=(int)freeze_units; chuyển int cắt phần lẻ đúng kiểuint32, không MathRound.
16. Nếu trail_distance!=0 và trail_distance<freeze_units thì nâng lênfreeze_units. SAU đó nếu trail_distance!=0 và trail_distance<state.stop_min_price/unit thì nâng lênstate.stop_min_price/unit. Không đổi thành max vô điều kiện (trail0 phải giữ0; NaN so!=0 rồi < như quy tắc).
17. Giữ nhánh hiện có dù trường vừa được đặt0: nếu state.native_6d5e8>0 thì nâng state.native_6d5f0 lần lượt theo freeze_units và state.stop_min_price/unit khi nó nhỏ hơn. Không tự bỏ nhánh.
18. const twice_stop=(state.stop_min_price+state.stop_min_price)/unit. Nếu twice_stop>localstop thì ghi stop_distance=twice_stop; nếu localtarget<twice_stop thì ghi target_distance=twice_stop. Nếu twice_stop>gap_points thì ghi gap_points=twice_stop. Các phép so có thứ tự; không dùng MathMax để đổi hành vi NaN.
19. older_width<1 thì ghi1; recent_width<1 thì ghi1; gap_points<0.1 thì ghi0.1, đúng thứ tự.
20. state.expiration_seconds=(uint)state.expiration_hours*(uint)3600, phép nhân tràn32bit. local longexpiry=0. Nếu state.expiration_hours>=1: gọi TimeCurrent() KHÔNG tham số một lần, rồi cộng `(long)state.expiration_seconds` ĐỌC MỚI SAU dịch vụ vào thời gian vừa trả. Cuối cùng ghi state.expiration=state.virtual_expiration==0 ? expiry : 0 (đọc cờ đã chép trong state, không đọc lại input). Return void.

## Giữ nguyên lỗi và giới hạn

MQL5 tự dừng khi chỉ mục sai/chia0; phải để lỗi xảy ra đúng trước/sau các ghi như trên. Không cần tái tạo số dòng mã gốc nhưng không nuốt lỗi. Không thêm GetLastError trừ nhánh handle âm đã nêu, không IndicatorRelease/reset/hủy handle, không kiểm copied<100 hoặc iOpen0, không dùng giá ATR/bảng khác để điền trống. Các hằng1.0/1000.0/10.0/0.1 đã được Codex đọc trực tiếp từ bằng chứng gốc.

SUMMARY liệt kê đủ output/các nhánh giữ lại và ghi đúng chưa biên dịch/chưa đối chiếu. Codex tự kiểm, biên dịch và so bằng chứng gốc trước khi ghép. Không gọi khối hoặc bot hoàn tất chỉ vì đã viết mã.
