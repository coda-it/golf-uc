
#ifndef H_SETTINGS_VIEW
#define H_SETTINGS_VIEW

#include "../datasources/wifi.h"
#include "../state/state.h"
#include "./abstract.h"
#include <U8g2lib.h>

class SettingsView : public AbstractView {
public:
  U8G2 *u8g2;
  AbstractRepository *repository;
  WifiDataSource *wifi;
  int status;

  SettingsView(U8G2 *u8g2, AbstractRepository *repository) {
    this->u8g2 = u8g2;
    this->repository = repository;
  }

  void render(State *state) {
    std::string content[3] = {"Settings",
                              "connect = " + std::to_string(this->status)};

    if (state->level == 0) {
      content[0] = ">" + content[0];
    } else if (state->level == 1) {
      if (state->rightButton) {
        this->status = this->wifi->connect();
      }

      content[1] = ">" + content[1];
    }

    for (size_t i = 0; i < 2; i++) {
      this->u8g2->drawStr(0, 10 + (i + 1) * 10, content[i].c_str());
    }
  }
};

#endif /* H_SETTINGS_VIEW */