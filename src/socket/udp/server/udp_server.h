#ifndef __UDP_SERVER_H__
#define __UDP_SERVER_H__

#include <WiFi.h>
#include <WiFiUdp.h>

#include "../../info/wifi.h"

class SocketServer
{
public:
    SocketServer();
    SocketServer(unsigned short port);
    void start();
    bool wifi_connect();
    void recv(char *buffer);

    bool connected() const;

private:
    WiFiUDP wifi_udp;
    String address;
    unsigned short port;
    WiFiServer wifi_server;
};

#endif