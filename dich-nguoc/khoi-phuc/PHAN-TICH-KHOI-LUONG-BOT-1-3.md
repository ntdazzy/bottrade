# Bot 1 và 3 — khối lượng và đổi tiền tệ

Ngày kiểm: 23/10/2026. Đã dựng và ghép phần đổi tiền tệ với phần tính
khối lượng. **Chưa phải bot hoàn chỉnh để giao dịch.**

Cập nhật sau: đã dựng riêng bước cập nhật vốn sau khi rút tiền và kiểm
ghi/đọc qua hai lần mở MT5; xem [kết quả](PHAN-TICH-RUT-TIEN-BOT-1-3.md).

| Phần đã kiểm | Bot 1 | Bot 3 |
|---|---:|---:|
| Tính khối lượng, kết quả đổi tiền được cấp sẵn | 1.464/1.464 | 1.576/1.576 |
| Hai chiều đổi tiền tệ | 1.530/1.530 | 1.530/1.530 |
| Ghép đổi tiền tệ rồi tính khối lượng | 783/783 | 966/966 |
| Ca lỗi chia cho 0 trong phép kiểm ghép, cùng từ chối kết quả | 35 | 84 |
| Biên dịch phần ghép hiện hành | 0 lỗi, 0 cảnh báo | 0 lỗi, 0 cảnh báo |

Các phép kiểm chỉ dùng dữ liệu cấp sẵn trong MT5 riêng; không gửi lệnh.
Kết quả khớp gồm khối lượng, mức vốn dùng để tính, vốn cao nhất đã ghi
nhận, chế độ tính, các trường thay đổi và số thông báo tương ứng.

## Mã và bằng chứng

| Nội dung | Bot 1 | Bot 3 |
|---|---|---|
| Tính khối lượng | [Bot1Volume.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1Volume.mqh) | [Bot3Volume.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3Volume.mqh) |
| Đổi tiền tệ | [Bot1Currency.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1Currency.mqh) | [Bot3Currency.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3Currency.mqh) |
| Ghép hai phần | [Bot1AccountVolume.mqh](bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1AccountVolume.mqh) | [Bot3AccountVolume.mqh](bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3AccountVolume.mqh) |
| Kết quả phần ghép | [comparison.json](bot-cua-toi-1/bang-chung/kiem-khoi-luong-ghep/account-volume-20261023-r1/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-khoi-luong-ghep/account-volume-20261023-r1/comparison.json) |
| Đổi tiền tệ riêng | [comparison.json](bot-cua-toi-1/bang-chung/kiem-doi-tien/currency-20261023-r1/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-doi-tien/currency-20261023-r2/comparison.json) |
| Khối lượng riêng | [comparison.json](bot-cua-toi-1/bang-chung/kiem-khoi-luong/volume-20261023-r1/comparison.json) | [comparison.json](bot-cua-toi-3/bang-chung/kiem-khoi-luong/volume-20261023-r1/comparison.json) |
| Biên nhận bản ghép | [b1-account-volume-01](bot-cua-toi-1/bang-chung/bien-dich/b1-account-volume-01/bien-nhan.json) | [b3-account-volume-01](bot-cua-toi-3/bang-chung/bien-dich/b3-account-volume-01/bien-nhan.json) |

Hàm gốc, tính từ đầu vùng mã đã chụp:

| Hàm | Bot 1 | Bot 3 |
|---|---|---|
| Chuẩn bị khối lượng | `0x34780` | `0x3f900` |
| Đổi sang USD | `0x36220` | `0x8300` |
| Đổi từ USD | `0x47d20` | `0x41780` |

## Hành vi đã giữ

- Chọn số dư hoặc vốn hiện tại gồm lãi/lỗ đang mở theo tham số. Giữ mức
  vốn cao nhất khi bật lựa chọn tương ứng. Mức vốn nhập tay dương thay
  mức dùng để tính; giá trị 0 được đổi thành 0,01 ở bước chuẩn bị.
- Giữ riêng cách tính của từng bot theo chế độ, khoảng dừng lỗ, mức
  rủi ro, khối lượng ban đầu và giới hạn của từng chiến lược.
- Bot 3 có cách chia mức lỗ cho phép theo trọng số và theo nhóm chiến
  lược được bật. Đã so các nhóm, nhóm tắt và mẫu số bằng 0.
- Giữ thứ tự nhân hệ số, nâng theo mức tối thiểu, chặn theo mức tối đa
  và làm tròn. Bot 1 có thêm bước nâng theo khối lượng ban đầu; bot 3
  không có bước đó ở vị trí tương ứng.
- Giữ cả hành vi lạ: hàm gốc chỉ ghi khối lượng mới khi bước khối lượng
  bằng 0,1; 0,01 hoặc 0,001. Các bước khác giữ phần tử khối lượng cũ.
- Đổi tiền theo giá đóng cửa ngày trước, giữ đuôi mã giao dịch và các
  lần đọc giá lặp lại. Chiều sang USD làm tròn về số nguyên; chiều ngược
  giữ số lẻ. Tên tiền tệ phải khớp một trong các dạng mà mã gốc xét.
- Giữ khác biệt giữa hai bot ở CHF và CZK. Không tự sửa các nhánh tiền
  tệ chưa được bản gốc hỗ trợ.

## Cách đối chiếu và giới hạn

Phép kiểm ghép chạy nguyên hàm khối lượng và các hàm đổi tiền tệ gốc.
Không còn cấp sẵn kết quả đổi tiền ở ranh giới hai phần trong phép kiểm
ghép. Dữ liệu tài khoản, giá và việc cấp bộ nhớ chuỗi thành công được
cấp sẵn; các phép tính và nhánh gốc vẫn chạy.

So từng bit các kết quả số. Với việc đọc giá đổi tiền, so số lần và mã
kiểm tra thứ tự mã giao dịch/khung/nến/giá; dấu vết phía gốc được lưu trong
`native-traces.json`. Chưa so số lần đọc tên tiền tệ hoặc nội dung thông
báo. Phần định dạng thông báo trong phép kiểm gốc được cấp chuỗi rỗng.

Khi mã gốc báo lỗi chia cho 0, bản dựng trả `false`; chỉ so việc từ chối
kết quả. Không so các ô nhớ đã ghi dở trước lỗi. Các số thực của lượt
này là hữu hạn; chưa kiểm mọi số không hợp lệ hoặc hết bộ nhớ.

Phần tự hạ vốn cao nhất sau khi rút tiền đang tắt trong phép kiểm. Bên
gọi vẫn phải khôi phục phần đọc lịch sử rút tiền và việc lưu trạng thái
vào MT5. Chưa ghép kiểm số tiền ký quỹ cần có, lệnh đang mở hoặc đặt lệnh.

## Chênh lệch đã sửa

Lần đầu viết phần đổi tiền bot 3 giống bot 1, có 45 ca lệch. Dấu vết
cho thấy bot 3 đọc cặp CHF một lượt, còn bot 1 có hai lượt; bot 3 có
nhánh đổi ngược CZK mà bot 1 không có. Đã sửa riêng `Bot3Currency.mqh`
và chạy lại MQL5: 1.530/1.530 ca khớp.

Lượt bot 3 `currency-20261023-r2` dùng lại kết quả mã gốc của `r1` vì
đầu vào và mã gốc không đổi; có `original-reuse.json` ghi nguồn và mã
kiểm tra. Phép kiểm ghép sau đó chạy mã gốc mới cho cả hai bot.

## Việc tiếp theo

Khôi phục phần lịch sử rút tiền/lưu trạng thái, kiểm ký quỹ, quản lý
lệnh, chọn chiến lược và các bộ lọc. Sau khi ghép đủ mới so toàn bộ bot
trên cùng dữ liệu. Không có kết luận giống toàn bộ bot 100% từ lượt này.

Công cụ và lệnh chạy: [cong-cu/BOT-1-3.md](cong-cu/BOT-1-3.md).

## Phần giao Claude

Đã dùng [quy trình Claude](C:/Users/NTD/.agents/skills/gstack-claude/SKILL.md)
để gửi nhiệm vụ nhỏ, chỉ đọc/nhận xét mã:

| Lượt | Phạm vi | Kết quả |
|---|---|---|
| [Lượt đầu](../.local/bot1-3-volume-20261023/claude-volume-review/run.json) | Kiểm hai tệp tính khối lượng và phép kiểm liên quan | Hết 300 giây, chưa có phản hồi |
| [Lượt thu nhỏ](../.local/bot1-3-volume-20261023/claude-volume-small/run.json) | Chỉ một hàm `Bot1PrepareVolume`, mã được gửi sẵn | Hết 240 giây, chưa có phản hồi |

Claude Code báo đã đăng nhập hợp lệ. Chưa xác định nguyên nhân không
trả lời. Không có nhận xét của Claude để tính thành bằng chứng kiểm tra;
các kết quả ở trên là phép đối chiếu do tôi thực hiện.
