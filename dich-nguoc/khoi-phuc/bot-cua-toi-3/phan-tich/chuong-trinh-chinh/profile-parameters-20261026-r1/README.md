# Bot 3 — nạp cấu hình chạy và điều chỉnh số

Ngày kiểm: 26/10/2026. Khối này nằm trong phần điều phối cấu hình trước
đọc mã giao dịch, chuẩn bị chỉ báo và đánh giá chiến lược. Nó chưa phải EA.

## Bằng chứng gốc

- Thân native được chạy từ bản EX5 bot 3 đã kiểm SHA-256.
- Phần kiểm bắt đầu và kết thúc theo các vị trí trong
  `expressions-positive/native-profiles.json`; mỗi chỉ số 0..8 có điểm dừng
  riêng trước khi gọi phần khác.
- Bộ CPU riêng chỉ xử lý các phép hai NaN theo lệnh SSE2 đo được; không sửa
  byte EX5.

## Hành vi đã chốt

- Nạp 9 bảng cấu hình. Mỗi bảng ghi 25 trường khoảng giá/cấu hình và 6
  trường số nguyên phụ: chu kỳ chỉ báo, khung chỉ báo, `native_6d2e0`, khung
  quản lý, `native_6d324`, `native_6d3c0`.
- Hạt giống 32-bit ở `0x1d6e78`. Chỉ khi `randomization > 0.0` mới sinh đúng
  11 mẫu theo thứ tự:
  `seed = seed * 214013 + 2531011` lấy phần thấp 32-bit,
  `word = (seed >> 16) & 32767`.
- Mỗi mẫu dùng đúng hằng `1/32768 = 0.000030517578125` và giữ nhóm ngoặc,
  thứ tự toán hạng, NaN và số 0 có dấu như cây biểu thức đã lưu.
- Số âm, `-0`, `0` và NaN ở `randomization` không sinh mẫu, giữ nguyên hạt
  giống; vô cực dương vẫn đi nhánh dương theo phép so native.
- Các trường ngoài danh sách 31 trường không bị đổi. Các giá trị `99` và số
  nguyên `5` ở bảng phụ được giữ nguyên.

## Nguồn dựng lại

- `source/MQL5/Include/bot-cua-toi-3/Bot3RuntimeProfile.mqh`
- `source/MQL5/Scripts/bot-cua-toi-3/Bot3RuntimeProfileCheck.mq5`
- `source/MQL5/Scripts/bot-cua-toi-3/Bot3RuntimeProfileApiCompile.mq5`
- `tests/runtime_profile_cases.py`
- `tests/check-runtime-profile.py`

## Kết quả đối chiếu

Lượt `b3-runtime-profile-20261026-r3` chạy **2.106 ca** trên thân gốc và
MQL5, gồm seed 0/1/2/MAX, số âm/âm không dấu/0/số rất nhỏ/số dương/NaN/
vô cực và sáu điều chỉnh. Kết quả: **2.106 khớp, 0 lệch**, mã kiểm hai tệp
`759a57f91f6b00e724d6f34c8224886bf61c7be2fe21b94655a87e9d2b91251e`.
Mã MQL5 biên dịch **0 lỗi, 0 cảnh báo** với kiểm chia số 0 bật.

## Giới hạn

Chưa có nơi gọi từ EA chính, khởi tạo hạt giống, chọn chiến lược, mã giao
dịch, chuẩn bị chỉ báo hoặc trạng thái khởi động lại. Vì vậy không gọi khối
này là hoàn thành bot 3 và chưa chạy cặp hai EA đầy đủ.
