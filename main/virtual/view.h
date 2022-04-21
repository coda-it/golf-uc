#ifndef H_VIEW
#define H_VIEW

#include <U8g2lib.h>

class AbstractView {
public:
  U8G2 *u8g2;

  virtual void render(int isLeftBtnPressed, int isRightBtnPressed) = 0;
};

#endif /* H_VIEW */