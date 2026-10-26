# Vé đầu bằng 0 và thanh ghi R12

Ngày 26/10/2026, rà soát bộ kiểm `check-position-management-flow.py`
phát hiện đầu vào R12 của ca vé đầu bằng 0 khác đường gọi thật từ bộ điều
phối.

## Bằng chứng mã gốc

- Mua: `0x2738d` gọi `PositionGetTicket`; khi kết quả là 0, `0x27395`
  nhảy tới `0x27357`. Lệnh `0x27357` đọc `r12b`; `0x27365` đặt cờ tích
  lũy khi R12 khác 0. Lệnh gán R12 địa chỉ dịch vụ chỉ nằm ở `0x273be`,
  sau nhánh vé bằng 0.
- Bán tương ứng: `0x2ad5b` → `0x2ad63` → `0x2ad25` và `0x2ad33`. Lệnh
  gán R12 nằm ở `0x2ad8c`, cũng sau nhánh vé bằng 0.
- Caller bộ điều phối đặt R12 thành `0x7ff6846f7fc0` tại `0x1a1ef`, rồi
  gọi hai parent tại `0x1a434` và `0x1a5ed`. Thanh ghi R12 được giữ qua
  lời gọi theo quy ước gọi hàm.

## Kết luận

Bộ oracle cũ xoá toàn bộ thanh ghi và không đặt lại R12 trước entry
parent. Vì vậy ca vé đầu 0 dùng R12=0, trái với đường gọi bộ điều phối có
R12b khác 0. Chưa thể coi ca này đã đối chiếu đúng. Cần chạy lại với R12
được cấp từ caller hoặc chạy router và parent nối tiếp trong cùng mô phỏng.

Không thay đổi EX5 hoặc mã nguồn bot trong lượt này.

## Đường nến mới

Đường nến mới vào `0x1a245` từ ba nhánh: `0x1a172`, `0x1a185` và
`0x1a1a3`. Các nhánh này đều đi tới lời gọi parent mua `0x1a2cd`, sau đó
parent bán `0x1a2db`. Lệnh `0x1a1ef` đặt R12 thành địa chỉ dịch vụ chỉ nằm
trên đường đếm vị thế sau `0x1a1d8`; đường nến mới đi vòng qua lệnh đó.

`trace-newbar-r12.py` dùng Capstone và byte gốc để lần ngược R12. Kết quả
`newbar-r12-definitions.json` có nhiều nguồn tới hai lời gọi: địa chỉ dữ
liệu, địa chỉ trên ngăn xếp, độ dài chuỗi, số 0 và giá trị tăng dần. Vì vậy
chưa có một byte thấp R12 cố định cho đường nến mới. Không được dùng giá
trị dịch vụ từ đường từng lần nhận giá làm giá trị mặc định cho nhánh này.


## Đã chạy kiểm đầu vào ngữ cảnh

Codex đã chạy4ca có vé đầu0 (4/6/92/94), cả mua/bán và một/ba vị thế,
với bốn giá trị R12đầu0/1/địa chỉ dịch vụ đếm hai chiều. Không sửa byte
mã gốc. `register-probe.json` ghi kết quả: seed0 trả0 và khớp MQL cũ;
ba seed khác0 trả1, khác MQL cũ duy nhất trường `returned`.

Hai ca92/94 có vị thế sau hợp lệ, nên vòng đếm bên gọi có thể cho phép
vào quản lý. Đây là sai khác cần sửa, không chỉ là giới hạn chưa chạy.
Các352ca cũ vẫn đúng trong ngữ cảnh seed0 đã ghi; chúng chưa chứng minh
ngữ cảnh từ chương trình gọi thật.

Đã giao Claude đề xuất API bắt buộc cung cấp cờ cho vé0 đầu; nhánh theo
từng lần nhận giá cấp true, nhánh nến mới nhận cờ được chụp ở bên gọi.
Chưa ghép đề xuất hoặc gọi là đã sửa. Còn cập nhật các bên gọi/bộ kiểm,
so ngữ cảnh đủ hai giá trị và chốt nguồn cờ trong toàn chương trình chính.


## Bản sửa đã được kiểm trong phạm vi rõ ràng

Đã ghép mã Claude viết: cờ ngữ cảnh vé0 đầu là tham số bool bắt buộc,
không có mặc định. Nhánh theo từng lần nhận giá cấp true; nhánh nến mới
nhận cờ tường minh từ bên gọi, chưa tự chọn khi chương trình chính chưa
đủ bằng chứng.

Ba lượt riêng đều352/352khớp: ngữ cảnhfalse giữ SHAe21198...15764, true
SHAbd40f1...bddf1, và chuỗi nơi gọi→quản lý→hàm bảng/sửa/đóng/gửi thật
SHAadcc5d...ba5de. Hai ngữ cảnh riêng chỉ khác trường trả về ở8ca vé đầu0:
4/5/6/7/92/93/94/95. Các trường khác không đổi.

Hai lượt router riêng đều1.536/1.536ca, cờfalse vàtrue, giữ SHA d106dd...
f18a. Tất cả chương trình kiểm và mẫu API thật biên dịch0lỗi/0cảnhbáo.
Rà độc lập chưa thấy lỗi trong phạm vi sửa.

Chuỗi nơi gọi mới chỉ chạy cờtick1/override0, dữ liệu dịch vụ được cấp.
Không chứng minh đã chốt cờ nhánh nến mới từ toàn main, mọi lỗi tài khoản
hoặc EA đầy đủ. Hồ sơ352ca cũ giữ nguyên; xem verification-summary.json
và các lượt mới khi dùng API có tham số cờ bắt buộc.
