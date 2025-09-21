#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <string>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = nullptr);
    void connectToServer();
    ~NetworkManager();

private:
    SOCKET client_fd;
};

#endif // NETWORKMANAGER_H
