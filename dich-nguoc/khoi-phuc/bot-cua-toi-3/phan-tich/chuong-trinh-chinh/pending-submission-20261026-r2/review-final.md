# Review chốt khối đặt lệnh chờ bot3

Ngày 26/10/2026. Đây là review read-only sau khi đã có bản canonical và lượt so r3.

## Bằng chứng đã đọc

- Native main: `RVA 0x20ef0..0x2a1bc`, base `0x17156250000`, SHA `6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920`.
- Nguồn canonical: `Bot3PendingSubmission.mqh`, SHA trong `baseline.json`: `8281cc70202e1b5b112fec0c11d025f70d03a4e01ed7465dfaa0ef005ba07c46`.
- Lượt so: `b3-pending-submission-20261026-r3`.
- Kết quả: `332/332` khớp, 0 lỗi; SHA kết quả gốc và MQL5 cùng là `318d545d8603d3ba7ce11d5979895cdf95b5efdd6afd5f914a193f74195a6087`.
- Biên dịch kiểm khối: `b3-submission-check-20261026-r3`, 0 lỗi/0 cảnh báo.
- Biên dịch giao diện: `b3-submission-api-20261026-r3`, 0 lỗi/0 cảnh báo.

## Nhận xét chính

Không tìm thấy lỗi mới có bằng chứng trong bản canonical. Lượt so đã chạy cả hai chiều mua/bán và các nhóm: thứ tự trả sớm, cờ byte, ô bảng trống, thử lại lỗi 132, đọc dữ liệu lại giữa các bước, ba lần Digits, biên giá nghiêm ngặt, số đặc biệt và chuỗi UTF-16.

Canonical thêm `Bot3SubmissionDifference` để giữ toán tử trừ trái-phải và dấu/payload NaN. 24 ca mới trong `pending_submission_cases.py` gồm NaN có payload và vô cực trong dừng/chốt; các ca này đều nằm trong 332 ca và khớp.

Các lời gọi đã được kiểm theo ABI đã chốt:

- Margin: symbol ở RCX, kiểu ở EDX, volume ở XMM2.
- ValidateVolume: volume ở XMM0; symbol dùng vùng native `0x74958`.
- Send: RCX/EDX/XMM2/XMM3 và các giá trị ngăn xếp theo `native-bindings.json`.

## Đính chính review trước

- Mô tả trước về giá bán có nhầm thanh ghi. Native tại `0x29272` nạp số `-0.0` từ vùng `RVA 0x581f8`; `0x2927c` mới nhân `xmm6` với giá trị unit trong bộ nhớ. Không phải lấy `-0.0` từ XMM9.
- `0x29664` và `0x2998a` chỉ là lệnh nạp địa chỉ hàm gửi. Lệnh gọi thật lần lượt là `0x2966e` và `0x29994`.

## Giới hạn không được che

- `whole_manager_complete=false`, `whole_bot_complete=false`, `full_ea=false`; đây chỉ là lát gọi sau khi đã có giá cơ sở.
- Margin, kiểm volume, giới hạn đặt, gửi lệnh và báo lỗi được cấp trả lời trong bộ kiểm; chưa phải phép chạy trực tiếp mọi thân hàm con với mọi tài khoản/môi trường.
- Bộ kiểm dùng đúng 9 volume và 100 hàng; chưa chứng minh mảng sai kích thước, cấp phát chuỗi thất bại, vòng thử lại vô hạn, toàn bộ vòng đời hoặc tài khoản thật.
- `original-results.bin` và `mql5-results.bin` khớp trong phạm vi 332 ca; điều này không chứng minh toàn bộ EA hay toàn bộ đầu vào có thể xảy ra.
- Biên nhận MetaEditor có `exit_code: 1` nhưng đồng thời ghi rõ `0 errors, 0 warnings`; chỉ dùng dòng kết quả biên dịch và trạng thái kiểm trong hồ sơ, không gọi đây là lỗi mã.

## Kết luận

Trong phạm vi đã kiểm, bản canonical đạt đối chiếu lát gọi `332/332` và biên dịch sạch. Chưa được gọi là hoàn thành toàn bộ bot; giữ đúng các cờ giới hạn nêu trên.
