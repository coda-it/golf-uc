
#ifndef H_COUNTER_VIEW
#define H_COUNTER_VIEW

#include "../models/state.h";
#include "../virtual/view.h"
#include <U8g2lib.h>

class CounterView : public AbstractView {
public:
  U8G2 *u8g2;

  CounterView(U8G2 *u8g2) { this->u8g2 = u8g2; }

  void render(State *state) { this->u8g2->drawStr(0, 10, "Counter"); }
};

#endif /* H_COUNTER_VIEW */