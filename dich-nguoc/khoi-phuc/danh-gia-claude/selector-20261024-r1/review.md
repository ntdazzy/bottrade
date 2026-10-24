## Kết luận

Tôi so hai tệp `.mqh` với danh sách lệnh máy đã chụp. **Không thấy sai** về thứ tự cờ, ngưỡng, dấu so hay hệ số ở cả hai bot. Phần còn thiếu nằm ở ba chỗ: phép kiểm chưa đủ mạnh, cách ghép vào EA chưa được ghi và kiểm, và vài chỗ tài liệu chưa khớp. Tôi chỉ đọc tệp, không chạy lệnh nào, nên chưa tự tính SHA-256 hiện tại của hai `.mqh`.

## Bot 1 — `Bot1StrategySelection.mqh`

**Đúng**
- A→H ứng với bit 0→7 (`dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1StrategySelection.mqh:28-35`). Khớp với `dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/bat-tat-chien-luoc/enable-20261023-r3/gates.json:3-122`: đầu vào ở `0x6a580+8n`, `profile_index=n`, tên đúng bảng cài đặt (`dich-nguoc/khoi-phuc/bot-cua-toi-1/phan-tich/cai-dat-20261023/cai-dat-da-kiem.md:23-30`).
- Dấu so: gốc dùng `cmp byte ptr [rax],0` rồi `je`, tức khác 0 là bật, đúng như `if(bool)`. Cổng không có ngưỡng hay hệ số.
- Trong cổng không ghi bộ nhớ: trước `je` chỉ có lệnh nạp/đổi thanh ghi (ví dụ cổng B ở `gates.json:30-35`). Tôi kiểm theo từng toán hạng. Công cụ gốc chỉ kiểm tên lệnh (`dich-nguoc/khoi-phuc/cong-cu/phan-tich-bat-tat-bot-1.py:69`), không theo dõi việc ghi.

**Chưa đủ**
1. Phép kiểm MQL5 256/256 gần như tự chứng minh. `cases.bin` và `mql5-results.bin` có **cùng SHA-256** (`dich-nguoc/khoi-phuc/bot-cua-toi-1/bang-chung/kiem-chon-chien-luoc/strategy-20261024-r1/comparison.json:7-8`). Lý do: kết quả mong đợi chính là `mask` đầu vào (`dich-nguoc/khoi-phuc/cong-cu/kiem-chon-chien-luoc-bot-1-3.py:29`, `:157`), không phải `original_selected_profiles`. Phép kiểm chỉ bắt được lỗi đảo bit. Việc tên cờ ứng đúng chỉ số chỉ dựa vào `gates.json`, và công cụ không kiểm điều này.
2. Mặt nạ làm mất thứ tự chạy xen kẽ. Bản gốc kiểm cổng n rồi chạy ngay khối tham số n; cờ tắt thì nhảy thẳng tới cổng n+1 (`disabled_rva` bằng `start_rva` của cổng sau). `0x10f60` là luồng điều phối (`dich-nguoc/khoi-phuc/ban-do-bot-1-3/luot-20261023-r5/bot-1.md:31`). Khi ghép phải giữ thứ tự A→H và không chạy khối tham số của chiến lược đang tắt. Phần này chưa có phép kiểm.

## Bot 3 — `Bot3StrategySelection.mqh`

Đối chiếu với `dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/chon-chien-luoc/select-20261023-r1/initialization-instructions.txt`. Đoạn `controller` có cùng ý nghĩa.

| Mục | Gốc (dòng listing) | MQL5 |
|---|---|---|
| Vào nhánh tự chọn | `cmp eax,5` + `cmp [Risk],0x4d2` (`:4-8`) | `:35` ✓ |
| Công thức | `movsd [MaxAllowedDD]` → `divsd` 100 → `mulsd` số dư đã đổi (`:17-22`) | `:37` ✓ |
| Cờ → ngưỡng → chế độ | `0x75353`→810→3, `0x75352`→560→2, `0x75351`→330→1; cờ tắt thì `xorpd` = +0.0 (`:19-36`, `:60-65`, `:78-83`, `:152-157`) | `:38-40` dùng bit 4/2/1 ✓ |
| Dấu so | `ucomisd` + `ja`/`jbe`: phải lớn hơn hẳn; NaN không lên chế độ | `>` ✓ |
| Cờ chế độ 0–4 | Chỉ số được bật: chế độ 1: 3,5; chế độ 2: 3,4,5,7; chế độ 3: thêm 8; chế độ 4: thêm 6. Không ghi chỉ số 0–2 | `:47-51` ✓ |
| Hệ số | `sete cl`: khi `UseVariableValues=false` lấy giá trị thứ hai (`:172-177`) | `:52-56` ✓ |
| Chọn thủ công | Chép 9 byte theo thứ tự `0,1,2,3,5,4,7,8,6` (`:98-134`); địa chỉ đúng RunStrat1..9 (`dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/cai-dat-20261023/cai-dat-da-kiem.md:84-92`); không đổi hệ số | `:61-65` ✓ |
| Giá trị ngoài bảng | Ghi chế độ trước, rồi `cmp eax,6; ja` so không dấu (`:42-45`) | `:44`, `:58`, `:67`: đúng với mọi số nguyên, không chỉ -1 và 7 ✓ |

**Chưa đủ**
1. **Lời gọi ngoài phạm vi:** bản gốc chỉ đọc số dư (`edx=0x25`) và gọi `0x8300` khi Frequency=5 và Risk=1234 (`:9-16`). MQL5 lại luôn nhận sẵn `converted_balance` (`dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3StrategySelection.mqh:11`). Khi ghép, chỉ được đổi tiền trong đúng nhánh này. Tác dụng phụ của `0x8300` chưa được kiểm.
2. **Ba cờ ngưỡng** là phần tử 1–3 của mảng 5 byte `0x75350..54`. Mã trung gian chỉ thấy gán `=1` (`dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/luot-20261023-data/ma-trung-gian-day-du.c:20420-20424`), chưa kiểm trên mã máy. Có hai cách đánh bit khác nhau cho cùng mảng này:
   - `Bot3Volume.mqh:96` gọi nó là `enabled_mask`, bit k = byte k.
   - `Bot3StrategySelection.mqh:38-40` dùng bit k = byte k+1.
   - Thêm nữa, `enabled_mask` ở `Bot3StrategySelection.mqh:23` lại là cờ chiến lược `0x6d220`.

   Khi ghép rất dễ lệch một bit.
3. **Lỗ hổng công cụ:** hook `visit` chỉ đăng ký trong khoảng [start, end-1] (`dich-nguoc/khoi-phuc/cong-cu/phan-tich-chon-chien-luoc-bot-3.py:176`), nên lỗi `UNDECLARED_NATIVE_CALL_OR_JUMP` (`:139-141`) không bao giờ xảy ra được. Lượt này vẫn không sót, vì listing chỉ có hai `call` và đã đi qua đủ 176/172 lệnh. Nhưng thực tế chỉ có việc theo dõi ghi (`:144-148`) là hoạt động.
4. **"30 ca thứ tự tính phần trăm"** (`phan-tich-chon-chien-luoc-bot-3.py:75-78`) không phân biệt được thứ tự làm tròn: các ngân sách đều xa ngưỡng và phép kiểm chỉ so chế độ. Bằng chứng về thứ tự là listing, nên `dich-nguoc/khoi-phuc/PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md:85-86` nói hơi quá.
5. **Hằng số:** công cụ chỉ đọc trực tiếp 4 cặp hệ số đầu (`phan-tich-chon-chien-luoc-bot-3.py:108-110`). Cặp hệ số của chế độ 4, các ngưỡng 810/560/330 và số 100 chỉ được chốt qua hành vi ở các ca sát ngưỡng.
6. **Cách so MQL5:** công cụ so với `hypothesis`, không với `original`, và không kiểm `matched` (`kiem-chon-chien-luoc-bot-1-3.py:51`). Lượt này vẫn tương đương vì `results.jsonl` có 7.724 `"matched": true` và không có ca sai. Tuy nhiên 7.724 ca thực chất là 2 lần × 3.862 đầu vào giống hệt nhau.
7. **`initial_mode` không có tác dụng:** gán ở `:31` rồi luôn bị ghi đè ở `:67`. Người gọi phải truyền đúng cờ và hệ số đang lưu vào các trường `initial_*`, nếu không phần "giữ nguyên" sẽ sai.
8. **Bảng trong báo cáo** `PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md:45-51` dùng số RunStrat ("4, 5" nghĩa là chỉ số 3 và 5). Câu ngay trước lại nói "chỉ số 3–8", nên dễ đọc nhầm.

## Bằng chứng và giới hạn

- Trường `source_sha256` trong hai `comparison.json` là mã của kết quả gốc, không phải mã của `.mqh`. Mã `.mqh` đã biên dịch nằm ở `bien-nhan.json:21` của mỗi bot. `binary_sha256` khớp `script_sha256` trong `mql5-run.json` ở cả hai bot.
- `PHAN-TICH-BAT-TAT-BOT-1.md:4` và `PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md:4` vẫn ghi "chưa viết MQL5", tức đã cũ.
- Lần kiểm này chưa xác nhận `.mqh` hiện tại trùng với bản đã biên dịch, chưa kiểm `0x8300`, khối tham số của bot 1, việc ghép vào EA hay quản lý lệnh khi chiến lược tắt. Đây chỉ là kiểm phần chọn chiến lược, không phải bằng chứng hoàn thành toàn bot.