**Sokoban Game (C++ với SDL)**
Giới thiệu
Chào mừng đến với Sokoban! Đây là một trò chơi puzzle kinh điển, nơi mục tiêu của người chơi là đẩy các hộp vào vị trí được chỉ định. Nhiệm vụ của bạn là giải quyết các cấp độ khác nhau bằng cách di chuyển nhân vật và các hộp một cách chiến lược.

Sokoban

Cài đặt
Để chơi Sokoban, làm theo các bước sau:

Sao chép kho lưu trữ:

bash
Copy code
git clone https://github.com/22021202-VU-VAN-HUY/Sokoban.git
Ngoài ra, bạn có thể tải xuống kho lưu trữ dưới dạng tệp ZIP và giải nén vào vị trí mong muốn.

Mở thư mục Sokoban:

bash
Copy code
cd sokoban
Cài đặt các phụ thuộc cần thiết. Nếu bạn đã cài đặt C++, bạn có thể sử dụng trình quản lý gói của hệ thống (ví dụ: apt, yum, brew) để cài đặt các thư viện SDL và SDL_image.

Biên dịch và chạy trò chơi:

bash
Copy code
g++ sokoban.cpp -o sokoban -lSDL2 -lSDL2_image
./sokoban
Bây giờ bạn đã sẵn sàng chơi Sokoban!

Hình ảnh trong game
Đây là một số hình ảnh trong trò chơi Sokoban:

Nhân vật và hộp
Đẩy hộp vào vị trí chỉ định.

Vị trí đích
Các vị trí đích để đặt hộp.

Tổ hợp phím
Dưới đây là các tổ hợp phím để điều khiển nhân vật trong trò chơi:

Phím mũi tên lên: Di chuyển lên
Phím mũi tên xuống: Di chuyển xuống
Phím mũi tên trái: Di chuyển sang trái
Phím mũi tên phải: Di chuyển sang phải
Phím R: Chơi lại cấp độ hiện tại
Phím U: Hoàn tác nước đi trước đó
Cách chơi
Mục tiêu của trò chơi là đẩy tất cả các hộp vào vị trí đích. Nhân vật có thể di chuyển lên, xuống, trái và phải, nhưng chỉ có thể đẩy một hộp một lúc. Người chơi cần lên kế hoạch di chuyển một cách chiến lược để tránh bị kẹt hoặc làm kẹt các hộp.

Để hoàn thành một cấp độ, hãy đặt tất cả các hộp vào vị trí đích. Sau khi bạn đã giải quyết một cấp độ, bạn có thể tiếp tục với cấp độ tiếp theo.

Hãy thận trọng với việc đẩy hộp vào các vị trí không thể di chuyển từ đó. Nếu bạn bị kẹt hoặc không thể tiếp tục di chuyển, bạn có thể sử dụng chức năng hoàn tác (phím U) để quay lại nước đi trước đó hoặc chơi lại cấp độ (phím R).

Hãy sắp xếp nước đi của bạn một cách thông minh và tận dụng sự suy nghĩ chiến lược để giải quyết các câu đố trong Sokoban.

Chúc may mắn và hãy thưởng thức trò chơi Sokoban!

Credits
Trò chơi Sokoban được tạo bởi your-username.

License
This project is licensed under the MIT License. See the LICENSE file for details.
