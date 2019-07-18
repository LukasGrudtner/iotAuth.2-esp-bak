#ifndef __UDP_SOCKET_H__
#define __UDP_SOCKET_H__

#include <WiFi.h>
#include <WiFiUdp.h>

#include "info/wifi.h"

class UDPSocket
{
public:
    UDPSocket();
    UDPSocket(unsigned short port);
    UDPSocket(String& address, unsigned short port);
    String recv();
    void send(const char* data);
    bool connected();
    void begin();

private:
    WiFiUDP udp;
    String address;
    unsigned short port;
    WiFiServer wifiServer;
};

#endif