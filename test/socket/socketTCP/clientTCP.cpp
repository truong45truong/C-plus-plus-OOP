#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>

void receiveMessages(int clientSocket) {
    char buffer[1024];
    memset(buffer, '\0', sizeof(buffer));

    while (true) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) {
            std::cout << "Kết nối đã đóng." << std::endl;
            break;
        }

        std::cout << "Tin nhắn từ máy chủ: " << buffer << std::endl;
        memset(buffer, '\0', sizeof(buffer));
    }
}

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;

    // Tạo socket
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Thiết lập thông tin địa chỉ máy chủ
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Kết nối đến máy chủ
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // Tạo luồng để nhận tin nhắn từ máy chủ
    std::thread receiveThread(receiveMessages, clientSocket);
    receiveThread.detach(); // Tách luồng để chạy độc lập

    while (true) {
        std::string message;
        std::cout << "Nhập tin nhắn: ";
        std::getline(std::cin, message);

        if (message == "exit") {
            break;
        }

        send(clientSocket, message.c_str(), message.length(), 0);
    }

    // Đóng kết nối và kết thúc
    close(clientSocket);

    return 0;
}
