# Ghép quản lý vị thế bot3 — các cạnh đã chốt trước viết

EX5 ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83,
base17156250000; hai hàm32f60/37590 trong management-20261025-r1/analysis.json.
Đây là bản mô tả luồng và mã ghép. Đã so parent 364 ca với hàm con
được cấp trả lời, chưa phải phép so đủ hàm con hoặc EA; xem ../management-flow-20261025-r1/.

- Vòng ngoài gọiPositionsTotal trước, total<1 trảfalse. Sau lời gọi đầu mới chép
  byte1d6fa0 sangSP3f/SP37 (3308f/376b9), dùng cùngbyte cho mọi vị thế.
  Byte1d6fa0 là input UseHL_TrailingSL, đã xác minh ở cai-dat-da-kiem.json
  dòng603. Chưa nối nạp input/điều phối EA; xem settings-origin.json của lượtflow.
- Duyệt xuôiindex0, đọc ticket/đủ thuộc tính/tick rồi lọc, điền dừng/chốt ban đầu,
  chạy ba nhóm đóng nến. Đóng nến không làm thoát manager hoặc tự đặt cờ.
- Anchor33b73..33d76/38194..3839c: chépstep6d600→74428 trướcDIGITS, giữ vélong
  đã chuẩn hóa, vé double sau chuẩn hóa, rawlevelXMM15 và selectedanchorSP78/SP88.
  CờgapSP5c/SP54 lấy từ rawlevel/open/limit6d4e0. Không trộn raw với selected.
- Cổng đóng sớm33d76/3839c: unit*(stop_distance+0), open và offset6d650;
  buy open-product-offset>bid; sell ask>product+open+offset. Nếu đạt:
  Tick→PositionGetDouble(VOLUME) bỏ kết quả→đọc globalticket74838→TryClose.
- Mode6d514==2 vàoảo35d65/39ff5; mode khác vào thật33dc9/383ef.
  Thật vẫn gọiStopLevel47f10, ghiP6d670 rồi kiểm strict:level>bid / ask>level.
  InitialrealstopXMM9 lấy từkết quảStopLevel, không phải SL vị thế.
- Thật theo thứtự: thời gian→khoảng giá→chốt thật→trượt giá→cao/thấp→khóa→counter.
  Cao/thấp thật cần byte đãchép đầu hàm; cao/thấp ảo không có cổngbyte này.
  Counter tự bỏ khi đãchanged, không căn cứ chỉ việcSL có giá trị khác.
- 35b30/39dc0: so strictSL>bid / ask>SL; ghiP=SL trước đi đường đóng.
  Khônghit thìStoreRealStop. SauStore đọc mode MỚI tại35d52/39fe2 hoặc
  36844/3aa3d; ==2 mới rơi sangảo, giữcờchanged; khác2 kếtthúc vịthế.
- Ảo:Start→Timed→Distance→Take→Slippage→FinishHighLow/LockCounter/Hit/Store.
  Sauđuôiảo36f5f/3b14f chỉgộpcờvà đi hậu vòng; khôngđọclạimode/lặpảo.
- ĐườngTryClose372ef/3b853 dọn rồi RET TOÀNMANAGER (373ac/3b90d), trảtrue
  dùhelpercon không đóngđược. Không tăngindex ở đườngnày.
- Đườngthường gộpcờ, dọnvịthế,tăngindex rồiPositionsTotal lại trước vòngsau.

Thôngbáohit đọc trực tiếp5ded0/5df08/5df48: Closing with virtual SL;
Virtual_SL: ; Last Bid: ở mua, Last Ask: ở bán (5e368, tham chiếu3b55e/3b6fb).
Bản mô tả ban đầu đã nhầm nhãn bán; phép so toàn vòng r1 phát hiện 2 ca.
Bằng chứng sửa: ../management-flow-20261025-r1/real-hit-label-correction.json.
Đọcmức sauPrint1, đọcbid/ask sauPrint2, Tick sauPrint3, rồi TryClose.
Nguồn đãbiếtkiểu doublecast0x58 quaP_DoubleText; xem
doi-chung-mt5/cast-double-20261025/double-cast-native-r1/double-cast-contract.json.

Một bảnđồ đọc C ban đầu từng đảo tên thật/ảo và gọi đườngđóng lànext;
Codex đã loại các kết luận đó và đối chiếu lệnhmáy trước chốt TASK.md.
Đặc tả giaoClaude được giữ trongclaude-thuc-hien/bot3-manager-complete-20261025-r1/.
Mã ghép nhậnsettings/shared do bên gọi cấp. C đã nối caller20ef0 và
inputUseHL/EnableVirtualSLTP; còn kiểm lệnh máy của caller và ghép/kiểm
nguồn các giá trị khác cùng sự kiện chươngtrìnhchính, không coi đã xongEA.
