#include <Arduino.h>

#include "socket/udp/client/udp_client.h"
#include "socket/udp/server/udp_server.h"

SocketServer server;
SocketClient client;

char data[100];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String address = "192.168.0.112";

  server = SocketServer(8080);
  server.start();

  // client = Client(address, 8080);
  // client.connect();
}

void loop() {
  // put your main code here, to run repeatedly:
  // client.send("hello");
  server.recv(data);
  sleep(1);
}