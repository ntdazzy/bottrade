# Kiểm độc lập bảng nối r2 (26/10/2026)

## Phạm vi và cách kiểm

Đã đọc `AGENTS.md` và `dich-nguoc/khoi-phuc/tai-lieu-cu/QUY-TRINH.md` trước khi kiểm. Chỉ đọc các `integration-map.json`, `INTEGRATION.md`, `SUMMARY.md` (bot 3), rồi đối chiếu trực tiếp cây nguồn hiện hành dưới `dich-nguoc/khoi-phuc/bot-cua-toi-{1,3}/source/MQL5`. Không sửa nguồn, không đọc/ghi EX5, không chạy MT5.

Đếm bằng tìm kiếm có quy tắc trên 44/51 tệp `.mqh`; kiểm lại mọi đường dẫn mô-đun, dòng bắt đầu hàm và dòng gọi trong JSON.

## Kết quả đếm

| Bot | Header thực tế | Header JSON | Hàm định nghĩa thực tế/JSON | Struct thực tế/JSON | Lời gọi trực tiếp thực tế/JSON | Script (mq5 + mqh) thực tế/JSON |
|---|---:|---:|---:|---:|---:|---:|
| 1 | 44/44 | 97/97 | 97/97 | 20/20 | 218/218 | 48/48 |
| 3 | 51/51 | 99/99 | 99/99 | 23/23 | 240/240 | 54/54 |

Mọi đường dẫn mô-đun trong hai JSON đều tồn tại. Mọi dòng bắt đầu hàm và dòng `direct_calls` đều nằm trong tệp tương ứng và tên hàm khớp khi đọc quanh dòng đó. Đây xác nhận tính đúng của bản chụp chữ ký/vị trí; không xác nhận thuật toán giống EX5.

## Đối chiếu nối chương trình

- Bot 1: `INTEGRATION.md` ghi 151 liên kết đã có mã; JSON có 218 vị trí gọi (gồm cả gọi nội bộ). Các số này không mâu thuẫn vì khác phạm vi đếm. 44 header chỉ nằm trong `Include`; không có `Experts`, `input/sinput`, `OnInit/OnTick/OnDeinit/OnTimer`. Danh sách 21 hàm đầu chuỗi chưa có nơi gọi và M01–M37 còn thiếu phù hợp với mã nguồn hiện hành. `SUMMARY.md` không có trong thư mục bot 1; vì vậy không thể kiểm phần tóm tắt bị thiếu.
- Bot 3: `INTEGRATION.md`/`SUMMARY.md` ghi 123 liên kết khác tệp, 240 lời gọi trực tiếp, 20 hàm đầu chuỗi chưa có nơi gọi và 62 mục thiếu. Đối chiếu nguồn xác nhận 51 header, 99 hàm, 23 struct và 240 lời gọi; không có `Experts`, `input/sinput` hay sự kiện vòng đời trong Include. Các mục ML-01..ML-69 và giới hạn `whole_bot_complete:false` phù hợp với bằng chứng đọc được.
- Cả hai bảng đều ghi đúng cảnh báo: có header và liên kết giữa header không có nghĩa đã nối EA; chưa có bằng chứng biên dịch, chạy song song hoặc so EX5. Vì vậy không được gọi là EA đầy đủ hay hoàn thành 100%.

## Điểm cần lưu ý / giới hạn

1. Các số dòng của bot 3 được JSON ghi rõ: chỉ `Bot3PendingSubmission.mqh` được đọc lại ở r2; 50 header khác kế thừa r1. Tôi xác nhận dòng hiện tại theo JSON nhưng chưa băm/so từng header với r1.
2. Đếm hàm dùng mẫu khai báo kiểu trả về và đếm lời gọi cùng tiền tố; không thay thế trình biên dịch MQL5. Macro, gọi gián tiếp, lời gọi qua con trỏ hoặc nhánh khi chạy có thể không xuất hiện trong đếm này.
3. Chưa có bằng chứng chủ sở hữu giá trị đầu vào, thứ tự gọi từ chương trình chính, hiển thị, lưu/khôi phục trạng thái, xử lý thoát/lỗi đầy đủ. Các bảng đã ghi các thiếu hụt này; không được tự điền.
4. Hai bản đồ và nguồn đều là bản phục dựng; chưa có phép so sánh hành vi với EX5 gốc trong lượt kiểm này.

## Lệnh kiểm có thể lặp lại

```powershell
Get-ChildItem dich-nguoc/khoi-phuc/bot-cua-toi-{1,3}/source/MQL5/Include/bot-cua-toi-{1,3} -Filter *.mqh
rg -n '^\s*(s?input)\b|\bOn(Init|Tick|Deinit|Timer)\s*\(' dich-nguoc/khoi-phuc/bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1 dich-nguoc/khoi-phuc/bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3
```
