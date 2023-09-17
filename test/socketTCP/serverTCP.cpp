#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <arpa/inet.h>

void receiveMessages(int clientSocket) {
    char buffer[1024];
    memset(buffer, '\0', sizeof(buffer));

    while (true) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) {
            std::cout << "Kết nối đã đóng." << std::endl;
            break;
        }

        std::cout << "Tin nhắn từ máy khách: " << buffer << std::endl;
        memset(buffer, '\0', sizeof(buffer));
    }
}

int main() {
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size = sizeof(serverAddr);

    // Tạo socket
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Thiết lập thông tin địa chỉ máy chủ
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Kết nối socket đến cổng và địa chỉ máy chủ
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    std::cout << "Máy chủ đang lắng nghe..." << std::endl;

    // Chấp nhận kết nối từ máy khách
    newSocket = accept(serverSocket, (struct sockaddr*)&serverAddr, &addr_size);

    // Tạo luồng để nhận tin nhắn từ máy khách
    std::thread receiveThread(receiveMessages, newSocket);
    receiveThread.detach(); // Tách luồng để chạy độc lập

    while (true) {
        std::string message;
        std::cout << "Nhập tin nhắn: ";
        std::getline(std::cin, message);

        if (message == "exit") {
            break;
        }

        send(newSocket, message.c_str(), message.length(), 0);
    }

    // Đóng kết nối và kết thúc
    close(newSocket);
    close(serverSocket);

    return 0;
}
