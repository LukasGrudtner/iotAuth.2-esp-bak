#ifndef __UDP_CLIENT_H__
#define __UDP_CLIENT_H__

#include <WiFi.h>
#include <WiFiUdp.h>

#include "../../info/wifi.h"

class SocketClient
{
public:
    SocketClient();
    SocketClient(String& address, int port);
    bool connect();
    void send(const char* data);
    void recv(char* buffer);
    bool connected() const;

private:
    WiFiUDP wifi_udp;
    String address;
    int port;
};

#endif