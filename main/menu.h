
#ifndef H_MENU
#define H_MENU

#include <U8g2lib.h>
#include <Wire.h>
#include "./data/repositories/repository.h"
#include "./data/repositories/eeprom.h"
#include "./data/state/state.h"
#include "./views/counter.h"
#include "./views/mainMenu.h"
#include "./views/view.h"

#define VIEW_NUMBER 2
#define LEVEL_NUMBER 3

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, D2, D1);

class Menu {
public:
  AbstractView *views[VIEW_NUMBER];
  AbstractView *selectedView;
  int viewIndex = 0;

  Menu() {
    u8g2.begin();
    EepromRepository *eepromRepository = new EepromRepository();

    this->views[0] = new MainMenuView(&u8g2, eepromRepository);
    this->views[1] = new CounterView(&u8g2, eepromRepository);

    this->selectedView = views[0];
  }

  void render(State *state) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);

    if (state->level == 0) {
      if (state->leftButton) {
        this->viewIndex =
            this->viewIndex == 0 ? VIEW_NUMBER - 1 : this->viewIndex - 1;
      } else if (state->rightButton) {
        this->viewIndex =
            this->viewIndex == VIEW_NUMBER - 1 ? 0 : this->viewIndex + 1;
      }
    }

    if (state->exitButton) {
        state->level = 
          state->level == 0 ? LEVEL_NUMBER - 1 : state->level - 1;
    } else if (state->enterButton) {
        state->level = 
          state->level == LEVEL_NUMBER - 1 ? 0 : state->level + 1;
    }

    this->selectedView = views[this->viewIndex];
    this->selectedView->render(state);

    u8g2.sendBuffer();
  }
};

#endif /* H_MENU */