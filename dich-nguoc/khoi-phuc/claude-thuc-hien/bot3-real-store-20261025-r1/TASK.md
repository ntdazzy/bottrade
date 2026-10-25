Viết duy nhất Bot3ManagementRealStore.mqh và SUMMARY.md trong thư mục này. Mục tiêu là ghi một mức dừng thật vào bảng vé đang có. Chỉ theo mô tả, không đọc phân tích lịch sử/tự tìmthuậttoán. Khôngsửanguồnchính/Git/lệnh/tác tửkhác. Codexkiểm/ghép/chạy. Opus5.5max,Ultracodeyêucầu;khôngclaimđãbiêndịch/chạy.
IncludeBot3ManagementPrelude.mqh vàBot3VirtualStops.mqh. Viết:
void Bot3StoreRealStop(const string &symbol,const double initial_stop,const double &current_stop,const double cached_ticket_number,Bot3VirtualStopState &table).
Đầu vào bảngsẵn500hàng rows[500][3],guarduchar; trườngđượcghi duy nhấtrows[row][1]. Khôngtạohàng/đổiôvé/giờ/takerows/guard. Current_stop/table cóthểđổi sauAPI vàkhôngtrùngvùngnhớvớibiếnkhác. initial_stop/cached_ticket_numberlàdoublecốđịnhđãcấpcủabêngọi; KHÔNGđổivéquaulong/long.
1 HỏiSymbolInfoInteger(symbol,SYMBOL_DIGITS),castuint; previous=Bot3RoundPrice(initial_stop,d1).
2 HỏiDIGITS2; SAUAPIđọccurrent_stopmới, current=Round(current_stop,d2).
3 Nếu previous==current(cóthứtự;NaNkhácnhau) thìthoát. Khácnhau/NaNthìhỏiDIGITS3;SAUAPI đọc current_stopmới,current=Round(current_stop,d3).
4 SAUDIGITS3đọcguard; nếuguard!=1thoát. Duyệtrow0..499,so table.rows[row][0]==cached_ticket_number(cóthứtự,NaNkhôngkhớp). Ghiô1ởhàngkhớpĐẦUTIÊN=current,break. Khôngkhớpthìkhôngghi.
Khôngtựghi current_stop,mứcSL/TP,bảngkhác,mode/counter,cờ,Tick,Modify,Close,Stamp. Đây là hàm lưu riêng được bên gọi dùng saukiểmchạmgiá; khônggộphit/đóngvàokhối này.
Mãrõràngtốigiản,khôngNormalizeDouble;SUMMARYnêu3DIGITS/NaN/nhánh/đầura/chưachạy. Cóthểđọcduy nhấtBot3VirtualStops.mqhđểlấykiểu bảngvàBOT3_VIRTUAL_STOP_ROWS.
