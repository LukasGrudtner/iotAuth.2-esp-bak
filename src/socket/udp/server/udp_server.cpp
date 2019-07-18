#include "udp_server.h"

SocketServer::SocketServer()
{

}

SocketServer::SocketServer(unsigned short port)
{
    this->port = port;

    wifi_server = WiFiServer(port);
}

void SocketServer::start()
{
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    delay(2000);

    while (!connected())
    {
        delay(100);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected!");
    Serial.print("Host: ");
    Serial.println(WiFi.localIP());

    wifi_server.begin();
}

void SocketServer::recv(char *buffer)
{
    String received = "";

    WiFiClient client = wifi_server.available();

    if (client)
    {
        while (client.connected())
        {
            while (client.available() > 0)
            {
                received = client.readString();

                Serial.println(received);
                memcpy(buffer, received.c_str(), received.length());
            }

            delay(10);
        }
        client.stop();
    }

    Serial.println(received);
}

bool SocketServer::connected() const
{
    return WiFi.status() == WL_CONNECTED;
}