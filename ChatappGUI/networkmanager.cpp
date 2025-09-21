#include "networkmanager.h"
#include <QDebug>
#include <string>

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent)
{
    // Initialize Winsock and create the socket.
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        qDebug() << "WSAStartup failed!";
        return;
    }

    client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_fd == INVALID_SOCKET) {
        qDebug() << "Socket creation failed: " << WSAGetLastError();
        WSACleanup();
        return;
    }
}

void NetworkManager::connectToServer()
{
    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // The fix is here: we explicitly call the global 'connect' function.
    if (::connect(client_fd, (sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        qDebug() << "Connection failed: " << WSAGetLastError();
        closesocket(client_fd);
        WSACleanup();
        return;
    }

    qDebug() << "Connected to the server.";

    const char *hello = "Hello from the GUI client!";
    send(client_fd, hello, strlen(hello), 0);
    qDebug() << "Message sent.";
}

NetworkManager::~NetworkManager()
{
    closesocket(client_fd);
    WSACleanup();
}
