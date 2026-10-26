# Review mã Bot3PendingSubmission r2

Ngày 26/10/2026. Phạm vi: đọc mã Claude, đối chiếu TASK r2, `native-bindings.json` và công cụ `check-pending-submission.py`. Không sửa mã.

## Bằng chứng gốc

- Native main: `RVA 0x20ef0..0x2a1bc`, SHA-256 `6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.
- Công cụ gốc có các điểm ABI đã chốt:
  - Margin: `RCX=symbol`, `EDX=type`, `XMM2=volume` tại native `0x2812a`/`0x29219`.
  - Kiểm volume: `XMM0=volume`, symbol lấy từ vùng `0x74958` tại native `0x28384`/`0x2947f`.
  - Gửi lệnh: `RCX/EDX/XMM2/XMM3`, các giá trị trên ngăn xếp tại native `0x29664`/`0x2998a`.
- Bộ kiểm gốc đã có 308 bộ dữ liệu và các ca thay đổi dữ liệu giữa các bước. Chưa có kết quả so MQL5 trong hồ sơ đọc được.

## Kết quả kiểm mã

### Không thấy lỗi đã được chứng minh

- `Bot3MarginGuard` ở dòng 46 nhận đúng thứ tự mã symbol, kiểu lệnh, volume theo giao diện MQL5 hiện hành. Volume được đọc ở dòng 44 trước khi sao chép symbol ở dòng 45.
- `Bot3ValidateVolume` ở dòng 65 dùng đúng giao diện header hiện hành (`symbol`, `double volume`). Phần thân hàm đọc symbol và volume theo giao diện MQL5; việc native chỉ truyền volume ở ABI máy được xử lý bên trong hàm con, không phải lời gọi máy trực tiếp của tệp này.
- `Bot3OpenPending` ở dòng 32–34 dùng đúng thứ tự hàm con hiện hành: magic, cờ hết hạn ảo, symbol, kiểu 4/5, volume, giá, dừng lỗ, chốt lời, ghi chú, hết hạn. Hàm con chuyển tiếp đúng ABI send đã chốt.
- Dòng 26–31 giữ đúng thứ tự đọc `expiration` → cờ bỏ dừng/chốt → `comment` → volume → symbol. Hàm thử lại gọi lại cùng hàm phụ, nên không chụp sớm các đối số tham chiếu.
- Dòng 53–63 có ba lần đọc Digits độc lập và giữ dấu `-0.0` ở phía bán.
- Dòng 93–97 bỏ qua kết quả bool của lần thử lại; chỉ mã lỗi hiện tại quyết định vòng lặp.
- Dòng 83–90 quét 100 hàng, chỉ coi cột 0 bằng 0.0 là ô trống; không ghi bảng sau thử lại.

### Điểm cần giữ giới hạn, chưa gọi là đạt

1. **Chưa có phép biên dịch hoặc so MQL5.** `SUMMARY.md` xác nhận mã chưa biên dịch/chạy. Vì vậy chưa có bằng chứng mã nguồn tạo đúng ABI thực tế của trình biên dịch, nhất là các đối số `double` XMM và các ô ngăn xếp của `Bot3OpenPending`.
2. **Kiểm gốc không phải kiểm mã Claude.** `Original` chỉ chạy native main với các hàm con được cấp trả lời; nó chưa chứng minh mã trong `Bot3PendingSubmission.mqh` khớp. Cần chạy `check-pending-submission.py mql5` rồi `compare` sau khi có bản biên dịch.
3. **Kiểu `uint digits`.** Dòng 53, 56, 60 ép kết quả `SymbolInfoInteger` sang `uint`. Đây là đúng theo TASK, nhưng chỉ phép biên dịch và ca `digits` âm/ngoài khoảng mới xác nhận được hành vi MQL5 cụ thể; không tự coi là lỗi.
4. **Tên symbol ở kiểm volume.** Native lấy symbol từ vùng `0x74958`, còn mã truyền `settings.symbol`. TASK yêu cầu đúng cách gọi này; đây là điểm cần phép so có ca thay đổi symbol giữa các bước, không đủ bằng chứng để kết luận sai mã.

## Kết luận

Trong phạm vi đọc mã và ABI đã chốt, **chưa tìm thấy lỗi cụ thể có bằng chứng** về thứ tự, kiểu số, hay lời gọi. Mã chưa được xác nhận đạt vì thiếu biên dịch và so MQL5; trạng thái phải giữ `whole_manager_complete=false`, `full_ea=false`, `whole_bot_complete=false`.

## Lệnh kiểm lại khi được phép biên dịch

```powershell
python -I -B dich-nguoc/khoi-phuc/bot-cua-toi-3/tests/check-pending-submission.py original <run>
python -I -B dich-nguoc/khoi-phuc/bot-cua-toi-3/tests/check-pending-submission.py mql5 <run> --build <build>
python -I -B dich-nguoc/khoi-phuc/bot-cua-toi-3/tests/check-pending-submission.py compare <run>
```
