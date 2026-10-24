# Tóm tắt — sửa dừng lỗ/chốt lời theo vé (bot 1 `0x26d20`, bot 3 `0x32a90`)

Trạng thái thật: **đã phân tích và viết đủ tệp đề xuất; chưa biên dịch,
chưa chạy, chưa so với EX5**. Không có số ca đạt nào. Codex mới đọc bản
đề xuất giữa lượt ([CODEX_REVIEW.md](CODEX_REVIEW.md), hai lỗi tài liệu đã
sửa); chưa có phép kiểm chạy. Phiên này không dùng tác tử phụ/quy trình nền (theo yêu cầu),
không chạy lệnh shell/MT5/git. Mô hình theo thông tin hệ thống của phiên:
`claude-opus-5-5`; mức `max`/`ultracode` không tự kiểm được từ bên trong.

| Phần đã làm | Kết quả và phạm vi | Còn thiếu / bước tiếp |
|---|---|---|
| [analysis.md](analysis.md), [semantics.json](semantics.json) | Viết trước nguồn. Đủ nhánh, lời gọi, đọc/ghi, độ rộng, trả về, chuỗi gốc, bản đồ địa chỉ hai bot, nơi gọi trong C, 9 điểm chưa rõ | Codex đối chiếu lại; chép `semantics.json` vào thư mục phân tích (bộ kiểm cần) |
| `Bot1PositionModify.mqh`, `Bot3PositionModify.mqh` | `bool BotNModifyPosition(state&, options&, ulong ticket, double sl, double tp)`; dùng nguyên cấu trúc/hàm gửi cũ, không gọi kiểm cách khớp | Biên dịch; so bằng bộ kiểm |
| `Bot1PositionModifyCheck.mq5`, `Bot3PositionModifyCheck.mq5` | Giữ nguyên facade `BotNPipelineApi.mqh`; chỉ thay cờ dừng, chọn vé, đọc mã giá, kết quả gửi; chụp trạng thái trước 3 lời gọi dịch vụ và sau gửi; ghi `(int)TRADE_ACTION_SLTP` | Biên dịch 0 lỗi/0 cảnh báo mới được chạy |
| `cong-cu/kiem-sua-vi-the-bot-1-3.py` | 4 chế độ; 1.596 ca/bot dự kiến; mã gốc chạy tới lệnh trả; kiểm 196/196 lệnh đã chạy, ABI, vùng đệm, ghi ngoài vùng, cân bằng bộ nhớ, băm mọi bước, mã terminal trước/sau | Chạy thật để biết kết quả |
| `cong-cu/phan-tich-goi-sua-vi-the-bot-1-3.py` | Bằng chứng lệnh máy phía gọi (U4): nguồn RCX/XMM1/XMM2, cách dùng RAX | Chạy, đọc `caller-sites.json`; cần cho bước ghép nơi gọi |
| Sơ đồ tệp, đoạn danh mục, [integration.json](integration.json) | Đích đề xuất và lệnh chạy | Codex áp tệp |

## Kết luận phân tích chính

- Đối số chứng minh bằng chính lệnh máy: RCX vé 64 bit; XMM1/XMM2 là
  `double` chép nguyên bit; không đọc RDX/R8/R9/XMM0/XMM3/ngăn xếp gọi.
  Mã C ghi sai kiểu (`undefined8`) cho sl/tp.
- Thứ tự gốc: kiểm cờ dừng (dword) → nếu dừng in
  `CTrade::PositionModify` rồi `retcode=10027`, trả 0 → chọn vé (lỗi thì
  trả 0, không đổi gì) → xóa đủ 628 byte → ghi `action=6`, `position`
  **trước** khi đọc mã giá → đọc mã giá → ghi `symbol`, rồi mới đọc mã
  nhận diện → `sl`, `tp` → gửi đầy đủ `0x950`, trả byte thấp.
- Khác hàm đóng: không kiểm cách khớp, không ghi `deviation/type/volume/
  price`, đọc mã giá sau khi xóa.

## Đã tự sửa trong lượt

- Số lệnh hàm: 196 (ban đầu ghi nhầm 197 do đếm dòng trống cuối tệp).
- Hàm gọi bot 1: `0x18aa0` (ban đầu trừ sai thành `0x28aa0`); bản đồ
  `luot-20261025-r1`/`r2` xác nhận `0x18aa0`, `0x271f0`, `0x2abc0`.
  Công cụ phía gọi lấy RVA hàm từ bảng hàm đã kiểm và RVA lời gọi bằng
  địa chỉ trừ gốc mã, rồi so với danh sách nơi gọi của bản đồ r2.
- Hai lỗi trên trùng với `CODEX_REVIEW.md` trong thư mục này; cả hai đã
  sửa ở `analysis.md`, `semantics.json`; không bỏ lệnh nào.

## Điểm Codex cần để ý khi chạy

1. `prepare` cần đã chép nguồn, script và `semantics.json`; thiếu là dừng.
2. Ca `CAST_OR_SLTP_CONSTANT_DIFFERS` nghĩa là `TRADE_ACTION_SLTP` ≠ 6
   trong MetaEditor đang dùng — khi đó phải đo lại hằng, không sửa ca kiểm.
3. Bộ chặn ghi chặt hơn khung cũ: chỉ cho vùng 628 byte. Nếu báo
   `UNEXPECTED_PROGRAM_STATE_WRITE` thì đó là phát hiện về mã gốc, cần đọc.
4. `MODIFY_ABI_STATE_NOT_RESTORED` nêu thanh ghi bị đổi; thanh ghi canh
   chỉ là kiểm phụ của mã gốc, MQL5 không thấy được.
5. Lỗi tại ranh giới in kèm tên trường lệch đầu tiên.

## Lệnh (chưa chạy)

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/phan-tich-goi-sua-vi-the-bot-1-3.py 1 modify-callers-20261025-r1
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/phan-tich-goi-sua-vi-the-bot-1-3.py 3 modify-callers-20261025-r1
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-sua-vi-the-bot-1-3.py prepare 1 modify-20261025-r1
& dich-nguoc/khoi-phuc/cong-cu/bien-dich.ps1 -Bot 1 -Terminal 'dich-nguoc/.local/claude-recovery-20261023/mt5' -Run b1-position-modify-01 -Source 'dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1PositionModifyCheck.mq5'
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-sua-vi-the-bot-1-3.py mql5 1 modify-20261025-r1 --build b1-position-modify-01
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-sua-vi-the-bot-1-3.py original 1 modify-20261025-r1
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-sua-vi-the-bot-1-3.py compare 1 modify-20261025-r1
```

Bot 3: thay `1` bằng `3`, `b1-` bằng `b3-`, `Bot1` bằng `Bot3`. Chạy hai
bot lần lượt vì dùng chung MT5 riêng. Sau `compare` đạt vẫn còn: nơi
gọi, máy đo quá khứ, toàn EA, cài đặt, giao diện, khởi động lại, tài
khoản thật, `_LastError`, lỗi cấp bộ nhớ (U1–U9 trong phân tích).
