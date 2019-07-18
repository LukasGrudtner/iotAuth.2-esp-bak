#include "udp_client.h"

SocketClient::SocketClient()
{

}

SocketClient::SocketClient(String& address, int port)
{
    this->address = address;
    this->port = port;

    WiFi.mode(WIFI_STA);
}

bool SocketClient::connect()
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

    return true;
}

void SocketClient::send(const char *data)
{
    if (connected())
    {
        wifi_udp.beginPacket(address.c_str(), port);
        wifi_udp.println(data);
        wifi_udp.endPacket();
    }
    else
    {
        Serial.println("Failure! WiFi not connected!");
    }
    
}

void SocketClient::recv(char *buffer)
{
    String data = "";
    if (wifi_udp.parsePacket() > 0)
    {
        while (wifi_udp.available() > 0)
        {
            data += wifi_udp.read();
        }
    }

    Serial.println(data);
}

bool SocketClient::connected() const
{
    return WiFi.status() == WL_CONNECTED;
}