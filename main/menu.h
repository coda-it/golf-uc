
#ifndef H_MENU
#define H_MENU

#include "./views/counter.h"
#include "./views/mainMenu.h"
#include "./virtual/view.h"
#include <U8g2lib.h>
#include <Wire.h>

#define VIEW_NUMBER 2

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, D2, D1);

class Menu {
public:
  AbstractView *views[VIEW_NUMBER];
  AbstractView *selectedView;
  int viewIndex = 0;

  Menu() {
    u8g2.begin();

    this->views[0] = new MainMenuView(&u8g2);
    this->views[1] = new CounterView(&u8g2);

    this->selectedView = views[0];
  }

  void render(int isLeftBtnPressed, int isRightBtnPressed) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);

    if (isLeftBtnPressed) {
      this->viewIndex =
          this->viewIndex == 0 ? VIEW_NUMBER - 1 : this->viewIndex - 1;
    } else if (isRightBtnPressed) {
      this->viewIndex =
          this->viewIndex == VIEW_NUMBER - 1 ? 0 : this->viewIndex + 1;
    }

    this->selectedView = views[this->viewIndex];
    this->selectedView->render(isLeftBtnPressed, isRightBtnPressed);

    u8g2.sendBuffer();
  }
};

#endif /* H_MENU */