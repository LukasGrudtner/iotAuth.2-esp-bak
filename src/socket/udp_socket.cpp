#include "udp_socket.h"

UDPSocket::UDPSocket()
{

}

UDPSocket::UDPSocket(unsigned short port)
{
    this->port = port;
    wifiServer = WiFiServer(port);
}

UDPSocket::UDPSocket(String& address, unsigned short port)
{
    this->address = address;
    this->port = port;
    wifiServer = WiFiServer(port);
}

void UDPSocket::begin()
{
    WiFi.mode(WIFI_STA);
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

    
    wifiServer.begin();
}

bool UDPSocket::connected()
{
    return WiFi.status() == WL_CONNECTED;
}

void UDPSocket::send(const char* data)
{
    if (connected())
    {
        udp.beginPacket(address.c_str(), port);
        udp.println(data);
        udp.endPacket();
    }
    else
    {
        Serial.println("Failure! WiFi not connected!");
    }
}

String UDPSocket::recv()
{
    
    String received = "";
    WiFiClient client = wifiServer.available();

    if (client)
    {
        while (client.connected())
        {
            while (client.available() > 0)
            {
                received = client.readString();
                Serial.println(received);

                // if (received != "")
                // {
                //     client.stop();
                //     Serial.println(received);
                //     return received;
                // }
            }
            delay(10);
            
        }
        client.stop();
    }
    return received;
}