
#ifndef H_SETTINGS_VIEW
#define H_SETTINGS_VIEW

#include "../datasources/server.h"
#include "../datasources/wifi.h"
#include "../state/state.h"
#include "./abstract.h"
#include <ESP8266WiFi.h>
#include <U8g2lib.h>

class SettingsView : public AbstractView {
public:
  U8G2 *u8g2;
  AbstractRepository *repository;
  WifiDataSource *wifi;
  ServerDataSource *server;
  int status;
  std::string ssid = "A";
  std::string password = "A";

  SettingsView(U8G2 *u8g2, AbstractRepository *repository) {
    this->u8g2 = u8g2;
    this->repository = repository;
  }

  void render(State *state) {
    const int ssidLength = this->ssid.length();
    std::string network =
        "Network: " +
        (ssidLength >= 2 ? this->ssid.substr(0, ssidLength - 1) : "") + "[" +
        this->ssid[ssidLength - 1] + "]";

    const int passwordLength = this->password.length();
    std::string password =
        "Password: " +
        (passwordLength >= 2 ? this->password.substr(0, passwordLength - 1)
                             : "") +
        "[" + this->password[passwordLength - 1] + "]";

    std::string connectionStatus = this->status == WL_CONNECTED ? "Yes" : "No";
    std::string connection = "Is connected: " + connectionStatus;

    std::string content[4] = {"Settings", network, password, connection};

    if (state->level == 0) {
      content[0] = ">" + content[0];
    } else if (state->level == 1) {
      if (state->rightButton) {
        this->ssid.push_back('A');
      }
      if (state->leftButton) {
        this->ssid[this->ssid.length() - 1]++;
      }

      content[1] = ">" + content[1];
    } else if (state->level == 2) {
      if (state->rightButton) {
        this->password.push_back('A');
      }
      if (state->leftButton) {
        this->password[this->password.length() - 1]++;
      }

      content[2] = ">" + content[2];
    } else if (state->level == 3) {
      if (state->rightButton) {
        this->status =
            this->wifi->connect(this->ssid.c_str(), this->password.c_str());
      }

      content[3] = ">" + content[3];
    }

    for (size_t i = 0; i < 4; i++) {
      this->u8g2->drawStr(0, 10 + (i + 1) * 10, content[i].c_str());
    }
  }
};

#endif /* H_SETTINGS_VIEW */