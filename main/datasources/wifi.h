#ifndef H_WIFI
#define H_WIFI

#include <ESP8266WiFi.h>

class WifiDataSource {
private:
  WiFiClient client;

public:
  WifiDataSource() {}

  int connect() {
    char *ssid = "";
    char *pass = "";

    WiFi.begin(ssid, pass);
    WiFi.mode(WIFI_STA);

    int retries = 200;
    while (WiFi.status() != WL_CONNECTED && retries > 0) {
      delay(500);
      retries--;
    }

    return WiFi.status();
  }
};

#endif /* H_WIFI */