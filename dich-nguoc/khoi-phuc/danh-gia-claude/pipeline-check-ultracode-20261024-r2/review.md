**Kết luận:** Tôi tìm thấy 1 lỗi thật trong `Original.call`, nằm ở phép kiểm chứ không phải ở bot. Cả ba điểm bạn hỏi đều đạt trong phần tôi đã đọc: api51 chỉ quan sát, cách bắt lời trả về bằng địa chỉ cộng RSP đúng, và kết quả/trạng thái không bị chép vào native.

## Lỗi: phép kiểm không so số đối số của `Print` trong hàm tạo lệnh

- Ở `dich-nguoc/khoi-phuc/cong-cu/kiem-chuoi-dat-lenh-bot-1-3.py:311-312`, phép kiểm lấy số đối số từ R8 của native rồi so với `expected[:count]`. Số đối số mà MQL5 ghi vào fixture (`:126-129`) không bao giờ được so.
- **Ảnh hưởng:** nếu native in ít đối số hơn MQL5, phép kiểm vẫn qua, tức là có thể khớp giả. MQL5 dùng `Print` 2 đối số ở `Bot1PendingRequest.mqh:38` và `Bot3PendingRequest.mqh:38`. Ngược lại, native in nhiều đối số hơn thì vẫn bị bắt.
- **Nhánh này có chạy trong r2:** nhóm `zero-expiration` (`:54-56`) với virtual ∈ {1,2,255} và cờ ∈ {0,4,8}, nhân 2 hướng, là 18 ca mỗi bot. Với 18 ca này, r2 chưa chứng minh native truyền đủ 2 đối số.
- Chưa có bằng chứng r2 có sai khác thật. Vấn đề là phép kiểm yếu hơn mô tả "toàn bộ thứ tự/đối số".
- **Cách kiểm:**
  1. Với opcode 2, thêm điều kiện `count==len(expected)` (opcode 13 đã ép `count==2`).
  2. Chạy lại original và compare sang một lượt mới. Nếu native đúng thì vẫn khớp 818/818.
  3. Thêm một ca kiểm âm: bản ghi `(7,(a,b))` với native truyền 1 đối số và cùng chuỗi đầu phải bị từ chối. Mã hiện tại cho qua.

## Ba điểm được hỏi

1. **api51 chỉ quan sát**
   - Điểm vào hàm tạo lệnh chỉ được gắn hook, không bị ghi `ret`: chỉ địa chỉ 48 và 49 bị ghi `\xc3` (`kiem-hang-doi-bot-1-3.py:136-138`).
   - `:231` đổi điểm đó từ 50 sang 51. Nhánh api50 cũ, vốn trả sẵn RAX rồi nhảy về (`kiem-hang-doi-bot-1-3.py:208-218`), không còn địa chỉ nào dùng.
   - Đoạn `:274-285` chỉ đọc thanh ghi và bộ nhớ, so trạng thái trước (Event 10), lưu khung rồi `return`. Không có `reg_write` hay `mem_write`, không đổi RIP/RSP, không gọi `patch`.
   - `pending.Original` (có lệnh dừng ở 0x950, `kiem-tao-yeu-cau-cho-bot-1-3.py:91-98`) không nằm trong chuỗi kế thừa. Chỉ hàm đọc `state_bytes` được gọi (`:234`).
   - Hàm tạo lệnh, kiểm cách khớp, gửi và thông báo đều chạy thật: chúng nằm trong vùng được phép (`:227-230`), và mọi lệnh nhảy ra ngoài vùng đều bị chặn (`kiem-gui-lenh-bot-1-3.py:194-195`).

2. **Địa chỉ trả về và RSP**
   - Lúc vào hàm: đích trả về lấy từ [RSP], phải thuộc tập `RETURNS` (`:276-277`), và được lưu cùng RSP (`:284`).
   - Chỉ nhận là đã trả về khi đúng địa chỉ đó và RSP bằng RSP lúc vào cộng 8 (`:255`). Lệnh `ret` của hàm con quay về một địa chỉ trong hàm con nên không thể khớp cả hai điều kiện.
   - Gọi lồng thì báo lỗi (`:275`). Hàm không trả về thì báo lỗi ở cuối ca (`:321`).
   - EAX được so đủ 32 bit (`:256-257`). Cách này chỉ có thể gây báo lỗi giả, không gây khớp giả.

3. **Không chép kết quả hay trạng thái vào native**
   - Event 11 (`:256-258`) và Event 10 (`:282`) chỉ dùng để so. Không có lệnh ghi nào dùng các giá trị này.
   - Native chỉ nhận dịch vụ MT5:
     - kết quả gửi lấy từ cases.bin (`:283`, `kiem-gui-lenh-bot-1-3.py:246`);
     - cờ gửi (`kiem-gui-lenh-bot-1-3.py:249`), được đối chiếu ở `:290` và `:171-172`;
     - giá trị thuộc tính, được đối chiếu với cases.bin ở `:175-189`;
     - chuỗi định dạng và chuỗi đổi số.

**Chuỗi kế thừa đã xác nhận:** bộ kiểm chuỗi → hàng đợi (`kiem-hang-doi-bot-1-3.py:127`) → lỗi (`kiem-chuoi-loi-bot-1-3.py:89`) → gửi (`kiem-gui-lenh-bot-1-3.py:179`) → `kiem-gia-vao` → `kiem-muc-gia`. API lạ thì báo lỗi (`kiem-chuoi-loi-bot-1-3.py:110`).

## Điểm yếu nhỏ (không gây khớp giả)

- Hai trường cuối không phải bằng chứng độc lập:
  - `print_hash` lấy từ chuỗi MQL5 ghi (`kiem-gui-lenh-bot-1-3.py:277`).
  - `position` luôn bằng số bản ghi (`:321-322`).
- `magic` và `virtual` cuối ca được chép từ đầu vào (`kiem-hang-doi-bot-1-3.py:257`). Nếu native ghi vào đó thì write_guard sẽ chặn.
- `:290` so giá trị trả lời thô, còn `:171` chuẩn hóa về bool. Hai chỗ chỉ lệch nhau khi trả lời khác 0/1.
- `:289` và `:294` đọc bản ghi mà không kiểm biên. Chương trình vẫn dừng, nhưng báo IndexError thay vì lỗi rõ tên.
- Phép kiểm 364 byte đã xóa (`:263-264`) chỉ có ý nghĩa ở lần gọi đầu mỗi ca, vì 0x5a chỉ được ghi một lần (`:243`).
- Chuỗi bằng chứng còn hở:
  - `dependencies()` (`:193`) chưa ghi `kiem-khoi-luong-bot-1-3.py`, tệp được nạp qua `kiem-khoi-luong-hop-le-bot-1-3.py:27`. Thư viện Unicorn/capstone cũng chưa được ghi.
  - baseline r2 ghi mã tool `f2585036…`, còn original-run ghi `3aef5a46…`. Mã trong baseline không được kiểm ở đâu, và không có bước sinh lại cases.bin để chứng minh `cases()` hiện tại tạo đúng tệp `b6bd5334…`.

## Bằng chứng r2 và giới hạn

- Cả hai bot khớp 818/818, `fixture_input_contract_checked_cases` = 818. Tệp kết quả và fixture của hai bot giống hệt nhau, vì các tệp này không chứa byte riêng của từng bot.
- Tôi chỉ đọc mã: không chạy gì và không tính lại SHA hiện hành.
- Tôi chưa đọc lại `.mq5` của r2; hash của tệp này đã đổi.
- Đây chưa phải EA hoàn chỉnh. Kết quả gửi, thuộc tính và lỗi đều được cấp sẵn; nơi giao dịch chưa được kiểm.
- Năm tác tử phụ của lượt trước không trả kết quả, nên vẫn là chưa có đánh giá. Lượt này tôi tự làm trực tiếp trên Opus 5.5, effort max, không giao cho tác tử phụ.