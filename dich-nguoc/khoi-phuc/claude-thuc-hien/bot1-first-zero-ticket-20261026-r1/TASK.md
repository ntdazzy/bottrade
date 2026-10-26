# Sửa trường hợp vé đầu bằng0 trong quản lý vị thế bot1

Viết hai header đầy đủ `Bot1PositionManagement.mqh`, `Bot1ManagementRouter.mqh` và `SUMMARY.md` vào CHÍNH thư mục đề xuất này. Chỉ đọc hai header hiện hành và Bot1ManagementPrelude.mqh để giữ giao diện; không đọc EX5/mã máy/phân tích. Không sửa nguồn chính, Git/MT5, chạy lệnh hoặc tạo tác tử. Opus5.5max, ultracode được yêu cầu; Codex kiểm riêng. Đây là bản đề xuất cho lỗi đã được Codex xác minh bằng chạy gốc, chưa được ghép đến khi kiểm đủ các bên gọi.

Ngữ cảnh và bằng chứng do Codex chốt: kết quả của một lượt quản lý còn phụ thuộc một cờ bên gọi cung cấp khi PositionGetTicket của VỊ THẾ ĐẦU TIÊN trả0. Cờfalse cho kết quả hiện hành; cờtrue làm lượt được tính là đã thay đổi kể cả các vị thế sau không thay đổi. Bỏ qua việc đọc thêm dữ liệu vị thế0 như hiện tại. Không sửa các công thức giao dịch hoặc cho rằng vé0 tự động là đã thay đổi ở mọi ngữ cảnh.

Giao diện mới phải yêu cầu tường minh `const bool first_zero_ticket_changed` làm THAM SỐ CUỐI của cả:

- `Bot1ManagePositions(...)` (sau deviation);
- helper nội bộ `Bot1ManageOnePosition(...)` (sau bool& changed).

Không có giá trị mặc định. Bên gọi phải chọn cờ từ ngữ cảnh đã được chốt, không âm thầm chofalse.

Trong ManagePositions: giữ changed=false đầu mỗi vòng, total/eligibility/index/any_changed hiện tại. Truyền cờ mới vào ManageOnePosition; nếu helper trảtrue thì vẫn returntrue ngay như hiện tại. Cộng changed vào any_changed như cũ. Không thay thứ tự SDK hoặc đặt any_changed=true trước khi có vé0 đầu.

Trong ManageOnePosition, chỉ sửa nhánh Bot1ReadManagementPosition trảfalse:

```mql5
if(!Bot1ReadManagementPosition(/* đúng các đối số hiện hành */))
{
   if(index==0 && shared.last_ticket==0)
      changed=first_zero_ticket_changed;
   return false;
}
```

Đây là dạng mô tả, thay đối số bằng mã thật. Không gọi GetTicket lần nữa. Lý do dùng shared.last_ticket trong nhánh này: helper ghi đúng kết quả Ticket ngay đầu; với vé0 nó trảfalse ngay và không gọi SDK khác. Khi vé khác0 mà bị lọc, cờ changed vẫnfalse. Không dùng ticket_number double chưa được gán để phân biệt. Sau helper thành công, giữ toàn bộ phần còn lại nguyên như nguồn hiện hành. true của cờ chỉ có tác dụng ở nhánh vé0 đầu, không đổi kết quả trả của helper thànhtrue vì helpertrue đang mang nghĩa thoát sớm toàn lượt.

Router: thêm tham số cuối bắt buộc `const bool bar_first_zero_ticket_changed` vào Bot1RoutePositionManagement, không có mặc định. Giữ nhánh cờ cấp phép nguyên, không sửa/ép cờ, không thêm lời gọi. Trong nhánh nến mới, truyền bar_first_zero_ticket_changed vào CẢ BUY và SELL, cùng giá trị được chụp bởi tham số bool bên gọi. Trong nhánh từng lần nhận giá, truyền literaltrue vào CẢ BUY và SELL khi count>0. Giá trịtrue của nhánh này đã được Codex chốt từ đường gọi thực tế; không bỏ việc đếm, không gọi SELL sớm hay bỏ SELL khi BUYtrue. Hàm đếm giữ nguyên từng dòng.

Giữ tất cả các đối số cũ, cấu trúc settings/shared, công thức, điều kiện và thứ tự gọi. Không thêm trường vào state, không mô phỏng thanh ghi, không sửa Prelude, không sửa script kiểm hoặc dùng ngữ cảnh chưa rõ để tự chọn cờ nhánh nến mới. Phần chương trình chính cung cấp cờ bar và bộ kiểm mới do Codex chốt riêng; ghi rõ các bên gọi cũ cần cập nhật tham số trước khi biên dịch, chưa được coi là đã sửa hoàn chỉnh.

SUMMARY nêu chính xác những dòng thay và việc chưa kiểm. Nếu ghi không được thì trả đầy đủ nội dung, không đổi nơi ghi.
