# Viết công cụ kiểm bằng chứng bảng dừng ảo bot 1

Đây vẫn là dự án khôi phục mã nguồn bot giao dịch của người dùng, cùng
bối cảnh đã nêu ở lượt rà nguồn. Phạm vi giao lần này là viết công cụ
kiểm chất lượng cho mã MQL5 mới và các tệp kết quả do dự án tạo ra.
Không giao lại phần quản lý vị thế/điều khiển hay phần bạn đã từ chối.
Không đọc EX5, bản chụp bộ nhớ hoặc mã C dịch từ EX5; không thay khóa,
giới hạn hay tệp gốc. Hãy viết mã thật cho phần này, không chỉ nêu đề xuất.

Đọc `AGENTS.md` trước. Chỉ ghi trong thư mục chứa TASK.md này:

- `kiem-chung-bang-dung-ao-bot-1.py`: công cụ Python độc lập dùng thư
  viện chuẩn; sau khi Codex rà sẽ ghép vào `cong-cu/`.
- `review-followup.md`: đối chiếu F1–F13 của lần rà trước với bằng
  chứng hiện có, mục chưa kiểm ghi rõ. Không sửa bằng chứng lịch sử.
- `SUMMARY.md`: tệp đã viết, lệnh Codex cần chạy, giới hạn còn lại.

Không chạy lệnh/MT5, không dùng công cụ ngoài Read/Grep/Glob/Edit/Write,
không sửa nguồn chính hoặc bằng chứng cũ. Không gọi kỹ năng lồng nhau.
Codex sẽ tự chạy chương trình, tạo/sửa dữ liệu thử và kiểm độc lập.

## Đầu vào để đọc

Trong `dich-nguoc/khoi-phuc/`:

- `claude-thuc-hien/virtual-stop-source-review-20261025-r1/review.md`.
- Nguồn mới `bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/`
  `Bot1VirtualStops.mqh`, `Bot1PriceLevels.mqh`; các Script mới
  `Bot1VirtualStopsCheck.mq5`, `Bot1VirtualStopsApiCompile.mq5`.
- Công cụ mới `cong-cu/kiem-bang-dung-ao-day-du-bot-1.py`,
  `kiem-loi-bang-dung-ao-bot-1.py`, `kiem-hang-doi-trong-may-thu.py`.
  Chỉ đọc mô tả đầu vào, bộ đọc kết quả, việc lưu bằng chứng và tạo
  mã kiểm trong MT5; không cần đọc hay thực hiện phần chạy lệnh gốc.
- Công cụ đã có `cong-cu/kiem-chung-sua-vi-the-bot-1-3.py` để tham
  khảo cách kiểm biên nhận, kiểu JSON, băm tệp, dữ liệu hỏng và nguồn
  trong máy thử. Giữ giải pháp nhỏ, không dựng bộ khung chung.
- Kết quả đã chạy `bot-cua-toi-1/bang-chung/kiem-bang-dung-ao/`
  `virtual-matrix-20261025-r3/`: baseline.json, cases.json,
  mql5-run.json, original-run.json, comparison.json, tested-sources/.
  Cùng thư mục `fatal-checks/virtual-faults-20261025-r2/summary.json`,
  case-211 và case-212: execution.json, verification.json,
  runtime-lines.txt. Các tệp .bin ở đây là dữ liệu kiểm do dự án tạo,
  không phải EX5. Có thể đọc cấu trúc từ bộ đọc nguồn mới.
- Bản biên dịch `bot-cua-toi-1/bang-chung/bien-dich/`
  `b1-virtual-matrix-03/bien-nhan.json` và
  `b1-virtual-native-api-02/bien-nhan.json`.
- Kết quả cùng máy đo quá khứ `doi-chung-mt5/bang-dung-ao-20261025/`
  `engine-virtual-b1-r1/`: comparison.json, build.json,
  VirtualStopsEngineCheck.mq5, tester-check-tool.py.

Codex đang chạy lượt r4 với chín ca bổ sung; công cụ nhận tên lượt qua
tham số, không ghi cứng số ca hay tên r3. Bản nguồn MQL5 và bản dựng 03
giữ nguyên. Khi r4 có kết quả, Codex sẽ chạy chương trình của bạn trên
r4 cùng lượt lỗi và lượt máy đo quá khứ tương ứng.

## Yêu cầu chương trình

1. Cách gọi khi ở `cong-cu/`:
   `python kiem-chung-bang-dung-ao-bot-1.py --matrix-run NAME --fault-run NAME --engine-run NAME --build NAME --api-build NAME --output NAME`
   Tên lượt chỉ nhận `[a-z0-9-]{1,40}`, output là tên JSON mới trong
   thư mục gốc `khoi-phuc`; không ghi đè. Xuất JSON rõ phạm vi, lỗi đầu
   tiên, mã kiểm SHA-256, số ca khớp; `whole_bot_complete` luôn false.
   Không sửa bất cứ bằng chứng đầu vào nào, không khởi chạy EX5/MT5.
2. Kiểm lại mối nối: mã nguồn hiện hành ↔ bản chốt tested-sources ↔
   biên nhận biên dịch; băm công cụ + phụ thuộc + EX5 gốc đã ghi phải
   nhất quán giữa baseline và các báo cáo. Không cần mở EX5 gốc.
   Bản dựng phải đúng target, errors/warnings kiểu int thật bằng 0
   (từ chối bool và float), băm MetaEditor đúng, băm binary nhất quán
   với biên nhận (chỉ băm EX5 của nguồn mới, không phân tích nó).
   Kiểm riêng bản biên dịch dùng API MT5 thật, target đúng và nguồn
   không thay API bằng macro; không nói đã chạy bản API này.
3. So lại mã kiểm thật của mọi tệp kết quả đã được các báo cáo dẫn
   tới; kiểm status đúng cặp (0, số ca thường). Bắt buộc terminal trước
   và sau như nhau, thống nhất với lượt máy thử. Kiểm kiểu JSON chặt
   cho các trường quyết định; không nhận false/0.0 là số đếm 0.
4. So lại đầu vào cases.json và cases.bin bằng encoder độc lập nhỏ,
   kiểm đủ khóa/kiểu/range/id duy nhất/liên tiếp, phân biệt ca lỗi và
   ca thường. Từ chối bản ghi thừa/thiếu/trùng hoặc byte thừa/cắt cụt.
   Đọc độc lập kết quả hai phía: magic/version/số ca/id/loại và chiều
   dài biến đổi; so đủ giá trị trả về, trạng thái và mảng. Không chỉ
   tin comparison.json. Không dùng bản thân mã MQL5 làm đáp án.
5. Đọc độc lập luồng lời gọi theo phiên bản 2 từ mã Script mới; kiểm
   cấu trúc, thứ tự id, kiểu, độ dài/range và hết tệp chính xác. Có thể
   dùng lại bộ đọc hiện có sau khi kiểm băm, nhưng phần chốt số bản
   ghi/EOF và so kết quả phải không chỉ tin báo cáo cũ.
6. Máy đo quá khứ: băm/nguồn runner phải khớp phép đổi Script hiện
   hành sang OnTick đúng như công cụ tạo; biên dịch 0 lỗi/cảnh báo,
   đúng mã nguồn và chương trình chạy, xác nhận demo trong bằng
   chứng. So kết quả, các lời gọi và status với lượt Script bằng byte.
7. Lỗi mảng: đủ đúng các ca fatal của cases.json, log xác nhận đúng
   ca và lỗi `array out of range`, kết thúc 4294967295/-1, không kết
   quả thường; kiểm snapshot/luồng lời gọi và các băm. Ghi rõ mã lỗi
   gốc 0x1f6 cùng lớp lỗi nhưng dòng/cột nguồn khác. Không tuyên bố
   đã kiểm thiếu bộ nhớ vật lý hay mọi cách cấp phát.
8. Có kiểm tự thân nhỏ trên dữ liệu trong bộ nhớ để chứng minh bộ
   đọc từ chối cắt cụt/byte thừa/id sai/count sai và kiểu JSON sai,
   liệt kê số trường hợp được từ chối; không sửa chứng cứ cũ. Nếu
   cần kiểm toàn chương trình bằng thay băm/tệp thì hướng dẫn Codex
   sao chép vào thư mục tạm, không sinh thêm bộ khung phức tạp.
9. Độ bao phủ: chỉ ghi số đã có bằng chứng trong original-run và
   summary ca lỗi. Không tự gọi hàm đã hoàn chỉnh 100% chỉ vì đủ số
   ca. Báo thiếu phép đo lỗi/khởi động/lưu trạng thái/tài khoản thật
   và EA chính; không dùng số ca làm tỷ lệ hoàn thành bot.

Nếu trường bằng chứng chưa tồn tại hoặc mô tả chưa đủ, ghi lỗi rõ,
không tự điền kết quả. Hãy triển khai theo những tệp thật đã đọc;
giữ mã rõ, kiểm đủ nhưng tránh kiểm trùng không cần thiết.
