#include <Arduino.h>

#include "socket/udp_socket.h"

SocketServer server;
SocketClient client;

UDPSocket socket;

char data[100];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String address = "192.168.0.115";

  socket = UDPSocket(address, 8080);
  socket.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  socket.send("hello");
  // String received = socket.recv();
  // Serial.println(received);
  sleep(1);
}