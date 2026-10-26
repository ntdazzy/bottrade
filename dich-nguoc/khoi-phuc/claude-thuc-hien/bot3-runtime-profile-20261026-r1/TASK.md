# Viết khối nạp tham số chiến lược có điều chỉnh và sinh số

Chỉ viết `Bot3RuntimeProfile.mqh`, `SUMMARY.md` trong thư mục đề xuất này. Đọc functional-constants.json cạnh TASK, cùng Bot3Preparation.mqh/Bot3BaseDistances.mqh/EntryProfiles/DistanceSettings hiện hành để dùng kiểu và bảng đã có. Codex đã chốt công thức/thứ tự phép tính dưới đây. Không đọc thư mục phân tích hoặc tự tìm thuật toán, không sửa nguồn chính/Git/MT5, không shell/tạo tác tử. Opus5.5max, ultracode; cấu hình được kiểm riêng.

Chức năng: nạp31giá trị của một trong9chiến lược, có6điều chỉnh khoảng giá và điều chỉnh ngẫu nhiên. Không đọc thị trường, không đặt lệnh, không đổi mã giao dịch/khối lượng/symbol/comment, không gọi bước chuẩn bị hoặc chương trình chính. Không đặt lại seed mặc định. Các phần ngoài mô tả để nguyên.

## Giao diện

Include Bot3Preparation.mqh và Bot3BaseDistances.mqh cùng thư mục. Header guard.

```mql5
struct Bot3ProfileAdjustments
{
   double randomization;
   double price_delta,stop_delta,target_delta,trail_delta,aux_delta,lock_delta;
};
struct Bot3ProfileRuntimeState
{
   uint random_seed;
   int native_6d324;
   int native_6d3c0;
};
void Bot3LoadRuntimeProfile(const uint index,const Bot3ProfileAdjustments &adjustments,
                           Bot3PreparationInputs &inputs,Bot3ProfileRuntimeState &state);
```

index do bên gọi cấp hợp lệ0..8; không tự tạo luật cho chỉ số ngoài miền. Chỉ ghi các trường được nêu. Đặc biệt giữ nguyên symbol/comment/reference, các cờ chung và mọi trường inputs khác; không ZeroMemory toàn inputs/state.

Lấy bảng cơ bản đã có bằng `Bot3DistanceInputs base; Bot3LoadBaseDistances((int)index,base);`. Miền hợp lệ bảo đảm hàm trảtrue và các trường sử dụng đã được ghi. Không chụp hoặc đọc các trường base chưa được gán. Không dùng Bot3PrepareDistances vì đây là bước nạp trước khi chuẩn bị.

## Phép số thực cần giữ đúng

Thêm ba hàm nhỏ nội bộ Sum/Product/Difference với tiền tố Bot3Profile. Cả ba có `if(left!=left) return left+0.0; if(right!=right) return right+0.0;`, sau đó trả phép +/*/- tương ứng. Không dùng MathIsValidNumber hoặc chuẩn hóa NaN/dấu0. Chúng giữ toán hạng và ngăn đổi cách ghép phép tính khi biên dịch. Mọi phép cộng/nhân/trừ bên dưới dùng các hàm này với đúng toán hạng và nhóm ngoặc, không khai triển/rút gọn biểu thức.

Chỉ sinh số khi `adjustments.randomization>0.0` có thứ tự; 0,-0,số âm và NaN đều KHÔNG sinh số. Giữ nguyên seed trong nhánh không sinh số. Không dùng MathRand/MathSrand hoặc hàm ngẫu nhiên nền tảng.

Với nhánh sinh số: bắt đầu từ seeduint32 được cấp; lấy đúng11mẫu theo thứ tự bằng công thức:
`seed=(uint)(seed*(uint)214013+(uint)2531011); word=(seed>>16)&32767;`.
Mỗi term[n] (n1..11) là `Product(Product((double)word,Sum(randomization,randomization)),0.000030517578125)`. Hằng này CHÍNH XÁC1/32768, không phải1/32767. `neg=Difference(0.0,randomization)`. Ghi lại state.random_seed bằng trạng thái sau11mẫu. Có thể dùng seed cục bộ để giữ phần nạp thuần số; không có dịch vụ hoặc điểm dừng lỗi trong miền chỉ số đã nêu. Không sinh dư mẫu kể cả mẫu được dùng không theo thứ tự.

## Trường chép cố định

- `inputs.entry=base.entry`; `nearby_radius,expiration_hours,trail_step,aux_hour1,aux_scan50,aux_older,aux_recent,aux_offset` từ base. Flags aux chuyển bool→uchar0/1.
- `inputs.indicator_period,indicator_timeframe,native_6d2e0,management_timeframe` và `state.native_6d324,native_6d3c0` lấy đúng hàng extra trong JSON. Có thể viết6mảngint9phần tử. Giữ nguyên các số99 và native_6d324=5 của chỉ số3, không đổi về bool hoặc sửa vì thấy lạ.
- Các khoảng giá sau tính đúng bảng dưới, không chép rồi ghi đè các trường không cần.

Ký hiệu: B là đúng trường của base, P/S/T/TR/A/L là price_delta/stop_delta/target_delta/trail_delta/aux_delta/lock_delta. `D[n]=Sum(term[n],neg)` chỉ có ở nhánh sinh số.

| Trường inputs | Không sinh số | Có sinh số |
|---|---|---|
| buy_offset | Sum(B,P) | Sum(Sum(B,P),D1) |
| sell_offset | Sum(Sum(P,B),0.0) | Sum(Sum(P,B),D2) |
| stop_distance | Sum(S,B) | Sum(Sum(S,B),D3) |
| target_distance | Sum(T,B) | Chỉ số2/3:Sum(Sum(T,B),D4); các chỉ số khác:Sum(D4,Sum(T,B)) |
| trail_distance | Sum(TR,B) | Sum(D5,Sum(TR,B)) |
| trail_start | B | Sum(D6,B) |
| trail_limit | B | Sum(D7,B) |
| native_6d368 | Sum(A,B) | Sum(D9,Sum(A,B)) — dùng mẫu9 |
| native_6d370 | B | Sum(D8,B) — dùng mẫu8 |
| trigger_distance | B | Sum(D10,B) |
| locked_distance | Chỉ số2/7:Sum(Sum(B,L),0.0); còn lại:Sum(Sum(L,B),0.0) | Chỉ số2/7:Sum(Sum(B,L),D11); còn lại:Sum(Sum(L,B),D11) |

Các nhánh thứ tự target/locked có trong functional-constants.json dưới dạng cây biểu thức; giữ chính xác. Không gộp các phép cộng vì sẽ mất thứ tự và cách truyền NaN. `entry.gap_points`,nearby_radius,trail_step,aux_offset không có điều chỉnh ngẫu nhiên.

JSON chứa bảng cơ bản để đối chiếu bảng đã có; không tạo bảng thứ hai nếu dùng được Bot3LoadBaseDistances. Phần positive_expressions/nonpositive_or_nan_expressions dùng `base`, `v`, `term`, `neg`, `k`(doublebitslittleendian) để chỉ thứ tự đã chốt; không cần viết bộ thông dịch cây biểu thức trong mã sản phẩm.

Mã cần rõ, ngắn, đủ chức năng. Không thêm lớp/luật giao dịch, không đổi các header phụ thuộc. SUMMARY nêu31trường, miền chỉ số và chưa tự biên dịch/chạy; chưa gọi là hoàn thành toàn chiến lược hoặc EA.
