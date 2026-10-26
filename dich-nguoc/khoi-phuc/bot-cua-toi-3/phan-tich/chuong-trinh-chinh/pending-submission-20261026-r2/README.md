# Khối đặt lệnh sau khi đã có giá cơ sở — bot3

Nguồn `Bot3PendingSubmission.mqh` do Claude viết theo mô tả đã chốt.
Codex đọc mã, biên dịch và đối chiếu độc lập: **332/332 ca khớp**,
**0 lỗi/0 cảnh báo**. Chưa có EA đầy đủ hoặc chạy cặp hai EA.

- Gốc: hàm `0x20ef0..0x2a1bc`, SHA
  `6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.
  Vị trí và lệnh gốc nằm trong `native-bindings.json`.
- Thứ tự được dựng: kiểm tiền nếu bật → ba lần đọc số chữ số và làm
  tròn → kiểm khối lượng/giới hạn → so giá → đặt lệnh → ghi bảng hoặc
  thử lại theo mã132 rồi báo lỗi. Giữ nguyên hành vi chỉ ghi bảng khi
  lần đặt đầu thành công; không ghi bảng sau lần thử lại.
- So241giá trị mỗi ca: thứ tự/đối số gọi qua mã kiểm, bộ đếm/lỗi,
  các cài đặt,9khối lượng và đủ200ô bảng. Chạy659vị trí lệnh gốc.
- Kết quả gốc/MQL5 cùng SHA
  `318d545d8603d3ba7ce11d5979895cdf95b5efdd6afd5f914a193f74195a6087`.
  [Phép so](../../../bang-chung/kiem-quan-ly-vi-the/b3-pending-submission-20261026-r3/comparison.json).

Lượt đầu308ca khớp306: hai ca số không hợp lệ bị đổi dấu bởi cách biên
dịch phép trừ trong điều kiện. Giữ kết quả cũ và đối chứng CPU riêng,
không sửa kết quả mong đợi hoặc nới phép so. Claude sửa đúng hai phép
trừ và bổ sung24ca, gồm dấu/phần dữ liệu của số không hợp lệ và tích
vô cực với0. `first-comparison-diagnosis.json` ghi nguyên nhân.

Nguồn sản phẩm và hai Script kiểm/API do Claude viết. Lượt viết đầu đã
kiểm9yêu cầu Opus5.5max; lượt viết bộ kiểm28yêu cầu. Yêu cầu ultracode
đã gửi, chưa có bằng chứng độc lập xác nhận chế độ này lúc chạy.
Lượt sửa phép trừ/bổ sung ca kiểm đã xác nhận14yêu cầu Opus5.5max.

Giới hạn: giá cơ sở được cấp từ đoạn trước; chưa phục hồi đủ các điều
kiện vào lệnh trước nó. Các hàm kiểm tiền/khối lượng/giới hạn/đặt lệnh/
đổi lỗi và dữ liệu MT5 được cấp trả lời; phần làm tròn và thân nơi gọi
chạy thật. Chỉ dùng chỉ số/mảng hợp lệ, cấp phát chuỗi thành công và
dãy thử lại hữu hạn. Chưa kiểm tài khoản thật, mọi lỗi bộ nhớ, vòng đời,
bảng hiển thị hoặc toàn bộ chương trình. Script API chỉ biên dịch.

Lặp lại bằng tên lượt mới, giữ bằng chứng cũ:

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/bot-cua-toi-3/tests/check-pending-submission.py prepare <run>
python -I -B -X utf8 dich-nguoc/khoi-phuc/bot-cua-toi-3/tests/check-pending-submission.py original <run>
python -I -B -X utf8 dich-nguoc/khoi-phuc/bot-cua-toi-3/tests/check-pending-submission.py mql5 <run> --build <build>
python -I -B -X utf8 dich-nguoc/khoi-phuc/bot-cua-toi-3/tests/check-pending-submission.py compare <run>
```

Trước mql5 cần biên dịch `Bot3PendingSubmissionCheck.mq5` bằng
`bien-dich.ps1 -CheckFloatingPointDividers`, dùng MT5 bot3 riêng.
Đang giao hai phiên Claude lập bảng nối toàn bộ nguồn bot1/bot3;
bảng nối chưa được tính là hoàn tất trước khi nhận và kiểm đủ tệp.
