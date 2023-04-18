#ifndef H_SERVER_DATASOURCE
#define H_SERVER_DATASOURCE

#include <ESP8266Wifi.h>

int HTTP_PORT = 80;
String HTTP_METHOD = "GET";
char HOST_NAME[] = "example.phpoc.com";
String PATH_NAME = "";

class ServerDataSource {
  WiFiClient server;

public:
  ServerDataSource() {}

  int sync() {
    if (this->server.connect(HOST_NAME, HTTP_PORT)) {
      this->server.println(HTTP_METHOD + " " + PATH_NAME + " HTTP/1.1");
      this->server.println("Host: " + String(HOST_NAME));
      this->server.println("Connection: close");
      this->server.println();
    }
  }
};

#endif /* H_SERVER_DATASOURCE */