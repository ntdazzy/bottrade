Viết Bot1ManagementRealStore.mqh và SUMMARY.md vào DUY NHẤT thư mục đề xuất này. Opus5.5max, Ultracode được yêu cầu. Đây là phần ghi mức dừng của chức năng quản lý vị thế MQL5; Codex đã chốt hành vi dưới đây. Chỉ đọc headers để dùng đúng kiểu. Không tự tìm thuật toán hoặc đọc phân tích/mã máy/EX5. Không sửa nguồn chính/Git/MT5/chạy lệnh/tạo tác tử. Codex sẽ kiểm, ghép và so với bằng chứng.

Giao diện:
void Bot1StoreRealStop(const string &symbol,const double initial_stop,const double &current_stop,
                      const double cached_ticket_number,Bot1VirtualStopState &table)
Header guard, include Bot1ManagementPrelude.mqh và Bot1VirtualStops.mqh như kiểu dự án. Có thể đọc source/MQL5/Include/bot-cua-toi-1 trongbot-cua-toi-1, gồm Bot1RoundPrice, Bot1VirtualStopState vàBOT1_VIRTUAL_STOP_ROWS. Không viết lại helper khác.

Hành vi chính xác:
1.uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);previous=Bot1RoundPrice(initial_stop,digits).
2.Gọi SymbolInfoInteger DIGITS lần2; SAU lời gọi mới đọc current_stop để current=Bot1RoundPrice(current_stop,digits2).
3.Nếu previous==current thì return. Đây là so sánh thường: NaNkhôngbằng; không dùng epsilon, không so bit hoặc chuẩn hóaNaN.
4.Nếu khác, gọi DIGITS lần3. SAU lời gọi mới đọc current_stop, current=Bot1RoundPrice(current_stop,digits3).
5.SAU cả3lần đọc/round mới đọc table.guard; khác1 thì return.
6.Duyệt row0..BOT1_VIRTUAL_STOP_ROWS-1 theo thứ tự. Nếu table.rows[row][0]==cached_ticket_number (so thường, NaNkhôngkhớp), ghi đúng current vào table.rows[row][1] rồi break. Chỉ dòng KHỚP ĐẦU TIÊN. Không tạo dòng, không ghi cộtkhác, không đổi guard, không ghi ticketcảnhbáo, không gọi dịch vụ khác.

initial_stop và cached_ticket_number là giá trị đã chụp (byvalue); current_stop/table/symbol tham chiếu còn có thể đổi sau lời gọi DIGITS, không chụp sớm. Không kiểmchếđộ/đónglệnh/ghi current_stop trong hàm; đó là việc bên gọi. Không thêmđiềukiện giá hay tốiưu gọiDIGITS. Mãngắn,rõ,khôngTODO/hàmrỗng. SUMMARY nêu đúng chưa biên dịch/chạy nếu chưa. Không tuyên bố100%.
