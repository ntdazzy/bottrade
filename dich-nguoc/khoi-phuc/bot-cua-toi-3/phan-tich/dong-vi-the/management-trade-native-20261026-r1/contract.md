# So vòng quản lý có đủ các hàm con giao dịch

Cờ --trade-children tự bật --table-children. Nhánh3 của MQL5 phải bật
ExecuteTradeChildren=true vàExecuteTableChildren=true. Mọi bước cùng cờ,
khóa mã gốc/nguồn/bằng chứng/bố cục dữ liệu, không ghi đè lượt cũ.

Bốn hàm bảng vàModify32a90/TryClose47d20/Close2e370/Filling2e8f0/Send950
chạy thân thật. Chỉ quan sát đầu hàm, không ghiRAX/XMM/RIP/RSP để cấp kết quả.
IsStopped được cấp0 ở1d6e14; classrequest/result/check bắt đầu0 tại744f0
với các vùng0/240/436; KHÔNG xóa vtable/context tại744d0. Magic0,preferred0,
deviation0123456789abcdef,async0,log0,margin0 đúng MQL5.

SelectByTicket vàSend chỉ cấp dịch vụ theoTASK.md của phiênClaude
bot3-management-trade-check-20261025-r1. Select giữ lựa chọn cũ khi không
khớp. Sendbăm35trường trước/sau, trả acceptedtheoSLTP/DEAL, cấp đủresult
và chỉ xóa vị thế ở đúng thời điểm đã mô tả. Không gửi lệnh thật.

Định dạng đầu ra3:192byte/ca gồm156byte cũ+4Q(request,result,check,metadata)
vàint32sendcount. Metadata gồm magic,preferred,deviation,async,log,margin.
Băm theo từng trường/bit/chuỗiUTF16+NULLflag, không băm pointer hoặc padding.
Giá trị mong đợi phải lấy từ thân mã gốc; MQL5 chỉ cấp định dạng số như trước.

Bộca hiện dùngIsStoppedfalse,log0,marketexecution2,FOKflag1. Chưa kiểm
mọi lỗi cấp phát/đầy bảng/mọi nhánh in của phép ghép; không coi là EA.
