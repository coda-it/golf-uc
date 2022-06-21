
#ifndef H_MAIN_MENU_VIEW
#define H_MAIN_MENU_VIEW

#include "../data/state/state.h"
#include "./view.h"
#include <U8g2lib.h>

class MainMenuView : public AbstractView {
public:
  U8G2 *u8g2;
  AbstractRepository *repository;

  MainMenuView(U8G2 *u8g2, AbstractRepository *repository) {
    this->u8g2 = u8g2;
    this->repository = repository;
  }

  void render(State *state) { this->u8g2->drawStr(0, 10, ">Main menu"); }
};

#endif /* H_MAIN_MENU_VIEW */