# Bot1ManagementRealCounter — tóm tắt đề xuất

## Kết quả
- Đã viết `Bot1ManagementRealCounter.mqh` (87 dòng) theo đặc tả Codex trong `TASK.md` cùng thư mục.
- **Chưa biên dịch, chưa chạy, chưa có ca kiểm.** Chưa có bằng chứng chạy; phần đối chiếu dưới đây chỉ là so mã với đặc tả.
- Tệp chỉ biên dịch được khi đặt cạnh các header Bot1 (`#include "Bot1ManagementPrelude.mqh"` là đường dẫn tương đối).

## Phạm vi đã đọc / không làm
- Chỉ đọc `TASK.md` và header Bot1 hiện hành trong
  `dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`:
  `Bot1ManagementPrelude.mqh`, `Bot1PositionModify.mqh`, `Bot1PriceLevels.mqh`,
  `Bot1TradeSend.mqh`, `Bot1PendingRequest.mqh`, `Bot1ManagementRealDistance.mqh`,
  `Bot1ManagementRealSlippage.mqh`, `Bot1ManagementRealTimed.mqh`, `Bot1ManagementRealStore.mqh`.
- Không đọc EX5, mã máy, tài liệu phân tích; không tự tìm thuật toán.
- Không sửa nguồn chính, Git, MT5; không chạy lệnh; không tạo tác tử.

## Giao diện
Hai hàm `void`, cùng 17 tham số theo đúng thứ tự đặc tả:

```
(const string &symbol,const uchar &enabled,const double &reference_setting,
 const int &minimum_steps,const double &step_distance,const double &unit,
 const double &copied_step,const double selected_anchor,const double &gap,
 const double &freeze,int &counter,Bot1ManagedPosition &position,MqlTick &tick,
 bool &changed,Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
 const ulong ticket)
```

- `Bot1AdvanceRealCounterBuyStop`: dòng 7–46. `Bot1AdvanceRealCounterSellStop`: dòng 48–86.
- Header guard `BOT1_MANAGEMENT_REAL_COUNTER_MQH` (dòng 3–4, 87); chỉ include `Bot1ManagementPrelude.mqh` (dòng 5).

## Đối chiếu đặc tả → dòng mã

| Bước đặc tả | MUA | BÁN |
|---|---|---|
| `if(changed) return;` | 16 | 57 |
| `if(enabled!=1) return;` | 17 | 58 |
| `counter=(int)((uint)counter+1);` | 19 | 60 |
| 1. `quote`, `u`, `product` và hai cổng giá | 21–25 | 62–66 |
| 2. Cổng neo khi `reference_setting!=0.0` | 27–31 | 68–72 |
| 3. `counter<minimum_steps` | 32 | 73 |
| 4. DIGITS1, rồi `candidate` và cổng | 34–36 | 75–77 |
| 5. `counter=0`, rồi DIGITS2 | 38–39 | 79–80 |
| 6. `new_sl`, ghi `position.sl` | 41–42 | 81–82 |
| 7. Modify bỏ qua kết quả, rồi `changed=true` | 44–45 | 84–85 |

Chi tiết đã giữ:
- Bước 1–3 không gọi DIGITS/POINT. Cổng neo dùng lại `quote` và `u` của bước 1, không đọc lại `unit`.
- Bước 4 đọc lại `step_distance`, `unit`, `position.sl` sau DIGITS1; bước 6 đọc lại sau DIGITS2.
- MUA: `candidate` là `step_distance*unit+position.sl`, `new_sl` là `position.sl+step_distance*unit`
  (thứ tự khác nhau như đặc tả). BÁN: cả hai là `position.sl-step_distance*unit`.
- Counter đã tăng được giữ khi trả về sớm. `counter=0` ghi một lần, trước DIGITS2; không ghi lại sau đó.
- Mọi cổng viết `if(!(a<b)) return;`. Riêng cổng neo dùng `reference_setting!=0.0`.
- Không có: NormalizeDouble, epsilon, kiểm `new_sl`, cổng gap sau khi ghi sl, Print,
  GetLastError/ResetLastError, đóng lệnh, khối lượng, lấy tick mới, sửa TP, bảng, mode.

## Điểm Codex cần kiểm khi biên dịch/chạy
1. `reference_setting` = NaN phải vào cổng neo; +0.0 và -0.0 phải bỏ qua. Mã dựa vào so sánh
   IEEE của MQL5 (`NaN!=0.0` là true); chưa kiểm bằng chạy.
2. Tràn counter: `INT_MAX` → `INT_MIN`, `-1` → `0`.
3. Dịch vụ giả đổi `unit`, `step_distance`, `position.sl`, `counter` trong DIGITS1/DIGITS2:
   giá trị mới phải được dùng hoặc giữ đúng bước.
4. Modify trả false: `changed` vẫn thành true, tệp này không in lỗi. `Bot1ModifyPosition` và
   `Bot1SendTrade` hiện hành vẫn có thể tự in (IsStopped, `log_level`); đó là hành vi của hàm phụ trợ.
5. NaN ở từng toán hạng cổng phải làm hàm trả về trước khi ghi sl.

## Cấu hình phiên
- Theo thông tin hệ thống của phiên: mô hình Claude Opus 5.5 (`claude-opus-5-5`); phiên báo Ultracode bật.
  Mức `max` được yêu cầu nhưng Claude không tự kiểm được mức nỗ lực thực tế từ bên trong phiên.
- Không dùng Workflow hay tác tử con: nhiệm vụ cấm tạo tác tử (phiên này cũng không có công cụ Workflow).
