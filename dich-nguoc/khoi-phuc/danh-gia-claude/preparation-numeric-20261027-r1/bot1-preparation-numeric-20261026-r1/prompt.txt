# Viết khối chuẩn bị số liệu chiến lược bot 1

Chỉ ghi các tệp đề xuất trong thư mục này. Không sửa nguồn chính, Git, MT5
hoặc thư mục khác; không dùng shell và không tạo tác tử. Viết MQL5 rõ ràng,
ngắn, biên dịch được. Đây là khối chức năng độc lập nhận dữ liệu dịch vụ từ
bên gọi; không viết EA chính, không đặt lệnh và không đọc mã máy.

## Giao diện cần viết

Tạo `Bot1PreparationNumeric.mqh` với các kiểu và hàm:

```mql5
struct Bot1PreparationMarket
{
   double indicator_values[]; // đã có đúng số phần tử do bên gọi cấp
   bool indicator_copy_ok;
   bool tick_ok;
   MqlTick tick;
   long now;
   double point;
   int digits;
   long stops_level;
   long freeze_level;
};
struct Bot1PreparationNumericState
{
   uint strategy_index;
   double scale,lot_scale,unit,spread;
   double stop_min_price,freeze_min_price;
   uint expiration_seconds;
   long expiration;
   Bot1Distances distances;
};
bool Bot1PrepareNumeric(const uint strategy_index,
                        const Bot1DistanceInputs &inputs,
                        const Bot1PreparationMarket &market,
                        Bot1PreparationNumericState &state);
```

Include `Bot1DistanceSettings.mqh`; không gọi `SymbolInfo*`, `CopyBuffer`,
`TimeCurrent`, dịch vụ giao dịch hoặc `Print` trong hàm. Không tự đổi các
trường ngoài `Bot1Distances`.

## Thứ tự và công thức phải giữ

1. Nếu `indicator_copy_ok` là false trả false. Nếu mảng có ít hơn 2 phần tử
   thì thực hiện truy cập phần tử thứ 2 như MQL5 thật để giữ lỗi chỉ số; không
   thay bằng giá trị mặc định.
2. `scale` bắt đầu bằng 1.0. Nếu `inputs.reference <= 0.0` hoặc là NaN,
   giữ 1.0. Nếu dương, lấy `indicator_values[0] / reference` theo đúng thứ
   tự. Nếu `inputs.use_variable` false, ghi scale=1.0. Nếu `scale==0.0`,
   thay bằng 1.0. `lot_scale = adjust_lots ? 1.0/scale : 1.0`; phép chia 0
   phải giữ lỗi biên dịch/chạy của MQL5, không che lỗi.
3. Ghi `strategy_index`, tick/time/point/unit/spread theo thứ tự: unit=point;
   digits 3 hoặc 5 → point*10; digits 1 → point/10; spread=ask-bid.
4. Chép profile `inputs` sang `state.distances` theo đúng thứ tự của
   `Bot1PrepareDistances`, nhân các khoảng giá bằng scale; giữ nguyên kiểu,
   số nguyên và cờ. Không làm tròn trong khối này.
5. Ghi broker limits: `stop_min_price=stops_level*point`,
   `freeze_min_price=freeze_level*point`.
6. Giữ đúng các nhánh chuẩn hóa của bot 1: stop/target không dương → 1.0;
   locked/trigger của `Bot1Distances` hiện đã là 0; trail và gap so với
   freeze/stop theo phép so sánh có NaN; older/recent tối thiểu 1; gap tối
   thiểu 0.1. Không thay `ucomisd/jbe/jnp` bằng kiểm số hữu hạn.
7. `expiration_seconds=(uint)expiration_hours * (uint)0xe10`; nếu giờ <1
   thì expiration=0, nếu không thì `now+seconds`; cờ
   `inputs.virtual_expiration` làm expiration=0. Giữ tràn uint32.

Các phép cộng/nhân/trừ với double phải giữ toán hạng và nhóm ngoặc như trên;
không dùng hàm làm sạch NaN, không tối ưu biểu thức. Không thêm luật giao dịch.

## Bộ kiểm cần viết

Tạo `Bot1PreparationNumericApiCompile.mq5` chỉ include header và biên dịch
với `InvokeFunctions=false`. Tạo `Bot1PreparationNumericCheck.mq5` và
`numeric_preparation_cases.py` theo mẫu các bộ kiểm hiện hành: đầu vào chứa
index, profile, indicator[2], point/digits, bid/ask, stops/freeze, now và
cờ; đầu ra ghi raw bits của toàn bộ `Bot1PreparationNumericState`.
Không tạo expected trong MQL5/Python; bên quản lý sẽ lấy expected từ native.

SUMMARY.md phải ghi rõ đây là lát số liệu độc lập, chưa phải EA, và chưa có
phép so với bản chính cho tới khi bên quản lý chạy.
