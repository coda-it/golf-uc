#ifndef H_VIEW
#define H_VIEW

#include "../repositories/abstract.h";
#include "../state/state.h";
#include <U8g2lib.h>

class AbstractView {
public:
  U8G2 *u8g2;
  AbstractRepository *repository;

  virtual void render(State *state) = 0;
};

#endif /* H_VIEW */