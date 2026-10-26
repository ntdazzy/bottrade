# SUMMARY – bảng nối nguồn bot 3, r2 (2026-10-26)

## Phạm vi đã đọc lại
- `Include/bot-cua-toi-3/Bot3PendingSubmission.mqh`: đọc toàn văn đầu phiên và đọc lại trước khi ghi JSON; hai lần giống nhau (112 dòng, `#endif` L112).
- `Scripts/bot-cua-toi-3/Bot3PendingSubmissionCheck.mq5` và `Bot3PendingSubmissionApiCompile.mq5`: đọc toàn văn đầu phiên; trước khi ghi tìm lại dòng include/macro/gọi và đọc L124-139 của `Check`. Nội dung như lần đọc r1.
- `TASK.md` của thư mục r2.
- Nền: 3 tệp r1, đọc JSON theo từng đoạn để chép lại. Không sửa tệp nào của r1.
- 50 header còn lại không đọc lại. Căn cứ coi là không đổi:
  - thứ tự thời gian sửa của 51 header và 54 Script giống lần liệt kê cuối của r1;
  - số dòng khớp `Bot3[A-Za-z]+\(` của từng tệp bằng r1; tổng 339 = 336 − 12 + 15 (chỉ PendingSubmission đổi);
  - dòng `#endif` của từng tệp bằng r1.

  Đây không phải phép so mã băm.
- Tìm kiếm toàn cây Include: `SubmissionDifference`, `SendPendingEntry`, `SubmitPendingAfterPrice` không có nơi gọi nào ngoài tệp của chúng. Chỉ có Script gọi `Bot3SubmitPendingAfterPrice`: `Check` L299 và `ApiCompile` L16.

## Thay đổi r1 → r2
- **Khối `Bot3PendingSubmission.mqh`** (trong `modules`):
  - Trạng thái `main_source_added_during_session` đổi thành `main_source_merged`.
  - Ghi rõ: header đã ghép và đã gọi hàm của 6 header include, nhưng **chưa nối chương trình chính** (chưa có EA; ML-16).
  - Thêm `Bot3SubmissionDifference` L21-26.
  - Dòng hàm đổi: `SendPendingEntry` L21→L28, `SubmitPendingAfterPrice` L36→L43.
  - `direct_calls` từ 10 lên 12. SL lệnh buy (L64) và TP lệnh sell (L69) đi qua `SubmissionDifference`.
  - Cập nhật `call_order`, `reads`, `writes`, `notes`, `product_callers`, `test_scripts`, `unresolved`.
- **Dòng dẫn tới khối này từ khối khác:**

  | Khối | r1 | r2 |
  |---|---|---|
  | TradeErrors | L98 | L105 |
  | TradeSend | L32 | L39 |
  | OrderScan | L86, chú thích L80, `AllowsPendingOrder` L66 | L93, L87, L73 |
  | Margin | L46 | L53 |
  | VolumeValidation | L65 | L72 |

  PendingQueue thêm ghi chú: thân hàm giống `SubmissionDifference` nhưng khác tên.
- **`pending_proposals` → `proposal_history`** (`superseded_history`). Không dùng bản đề xuất thay cho nguồn chính.
- **`test_scripts`:** hai Script PendingSubmission bỏ `added_during_session`, thêm `reread_r2` và ghi chú (macro L14-22, thân thật của `RoundPrice`/`SubmissionDifference`, lần gọi thứ năm L134).
- **`confirmed_links`:** CL-021..CL-026 đổi dòng thành L39; L53; L62/66/70; L72; L73; L105. Vẫn 123 mục; lời gọi `SubmissionDifference` cùng tệp nên không thêm mục.
- **`missing_links`:**
  - ML-16 đổi dòng thành L43 và ghi rõ phần thiếu.
  - Thêm ML-17 (`linked_in_header_only`): MarginGuard, ValidateVolume, AllowsPendingOrder, SubmissionDifference, SendPendingEntry và OpenPending đã có nơi gọi, nhưng chỉ bên trong chuỗi chưa có đầu gọi.
  - ML-40, ML-42, ML-44, ML-66 đổi dòng.
  - Vẫn giữ thiếu: nơi gọi `SubmitPendingAfterPrice`, nguồn `base_price`, cài đặt, chủ thể giữ trạng thái ở chương trình chính.
- **`struct_overlaps`:** SO-04 đổi dòng thành L45.
- **`program_groups`:** G5 đổi dòng thành L74-85; G6 thêm `SubmissionDifference` và ML-17; G8 thêm dòng vòng thử lại.
- **`next_implementation_parts`:** giữ NP-01..NP-03, thêm ghi chú r2. Không thêm phần mới vì nơi gọi, thứ tự tick, cài đặt và chủ thể trạng thái chưa có căn cứ.
- **Khóa mới:** `revision`, `based_on`, `totals`, `integration_status`, `changes_from_r1`.

## Số liệu r2 (đếm từ tệp thực tế)

| Mục | Số |
|---|---|
| Header | 51 |
| Hàm | 99 (r1: 98) |
| Struct | 23 |
| Define ngoài include guard | 1 |
| Vị trí gọi | 240 (r1: 238) |
| Liên kết khác tệp | 123 |
| Liên kết trạng thái | 12 |
| Mục `missing_links` | 62 (r1: 61) |
| Mục `struct_overlaps` | 31 |
| Script | 54 (43 runtime_check, 8 compile_only, 1 storage_check, 1 runtime_calibration, 1 test_helper_header) |
| Hàm chưa có nơi gọi trong mã sản phẩm | 20 (gom thành ML-01..ML-16) |

Kiểm JSON bằng tìm kiếm:
- Số mục khớp: 51 khối `product_header`, 99 mục hàm `Bot3`, 240 mục `direct_calls`, 54 Script, 123 CL, 62 ML.
- Không còn chỗ giữ chỗ. Không thấy phẩy thừa hay thiếu, escape sai, dấu nháy lạc.
- Đủ khóa cấp ngoài: `bot`, `modules`, `confirmed_links`, `missing_links`, `next_implementation_parts`, `whole_bot_complete: false`.

## Giới hạn, chưa kiểm
- Không biên dịch, không chạy, không so với EX5 gốc. Không công bố logic đã khớp.
- Không xác minh kết quả kiểm riêng của bên quản lý cho khối PendingSubmission. Trạng thái "đã ghép" lấy từ giao việc và vị trí tệp trong cây Include.
- Không dùng shell, nên không tính SHA-256. JSON chưa qua trình phân tích JSON, chỉ kiểm bằng tìm kiếm.
- Dòng của 50 header không đọc lại lấy từ r1. Bản đề xuất cũ không đọc lại; `proposal_history` lấy từ lần đọc r1.
- Không đọc, theo giới hạn phạm vi:
  - thư mục phân tích, EX5, bộ kiểm Python, tệp `.bin`, tệp `.local`;
  - `tai-lieu-cu/QUY-TRINH.md`;
  - `TASK.md`/`SUMMARY.md` của thư mục đề xuất, thư mục `bot3-pending-check-20261026-r2`.
- Cấu hình: thông tin hệ thống ghi mô hình `claude-opus-5-5`; mức `max` và `ultracode` không tự kiểm được trong phiên. Không tạo tác tử.
- Chỉ ghi 3 tệp trong thư mục r2: `integration-map.json`, `INTEGRATION.md`, `SUMMARY.md`. Không đưa số phần trăm hoàn thành.
