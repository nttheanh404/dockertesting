// #include <iostream>
// #include <thread>
// #include <vector>
// #include <atomic>
// #include <cstring>
// #ifdef _WIN32
// #include <winsock2.h>
// #pragma comment(lib, "ws2_32.lib")
// #else
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <unistd.h>
// #endif

// std::atomic<bool> running(true);

// void handle_client(int client_sock) {
//     std::cout << "connected!" << std::endl;
//     char buffer[1024];
//     while (true) {
//         int bytes = recv(client_sock, buffer, sizeof(buffer), 0);
//         if (bytes <= 0) break;  // client disconnect
//     }
// #ifdef _WIN32
//     closesocket(client_sock);
// #else
//     close(client_sock);
// #endif
// }

// int main() {
// #ifdef _WIN32
//     WSADATA wsa;
//     WSAStartup(MAKEWORD(2,2), &wsa);
// #endif

//     int server_sock = socket(AF_INET, SOCK_STREAM, 0);
//     if (server_sock < 0) {
//         std::cerr << "Cannot create socket\n";
//         return 1;
//     }

//     sockaddr_in server_addr{};
//     server_addr.sin_family = AF_INET;
//     server_addr.sin_addr.s_addr = INADDR_ANY;
//     server_addr.sin_port = htons(6881);

//     int opt = 1;
//     setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR,
//                (char*)&opt, sizeof(opt));

//     if (bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
//         std::cerr << "Bind failed\n";
//         return 1;
//     }

//     if (listen(server_sock, 10) < 0) {
//         std::cerr << "Listen failed\n";
//         return 1;
//     }

//     std::cout << "Tracker listening on port 6881\n";

//     while (running) {
//         sockaddr_in client_addr{};
//         socklen_t addr_len = sizeof(client_addr);
//         int client_sock = accept(server_sock, (sockaddr*)&client_addr, &addr_len);
//         if (client_sock >= 0) {
//             std::thread(handle_client, client_sock).detach();
//         }
//     }

// #ifdef _WIN32
//     closesocket(server_sock);
//     WSACleanup();
// #else
//     close(server_sock);
// #endif

//     return 0;
// }
#include <httplib.h>
#include <iostream>

int main() {
    httplib::Server svr;

    // endpoint ping
    svr.Get("/ping", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("connected!", "text/plain");
        std::cout << "Peer pinged tracker!" << std::endl;
    });

    std::cout << "HTTP tracker listening on port 6881" << std::endl;
    svr.listen("0.0.0.0", 80); // lắng nghe tất cả interface
}

