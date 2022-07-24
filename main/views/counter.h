
#ifndef H_COUNTER_VIEW
#define H_COUNTER_VIEW

#include "../state/state.h"
#include "./abstract.h"
#include <U8g2lib.h>
#include <string>

class CounterView : public AbstractView {
private:
  int hole = 0;

public:
  U8G2 *u8g2;
  AbstractRepository *repository;

  CounterView(U8G2 *u8g2, AbstractRepository *repository) {
    this->u8g2 = u8g2;
    this->repository = repository;
  }

  void render(State *state) {
    std::string content[3] = {
        "Counter", "Hole " + std::to_string(this->hole) + "",
        "Hits " + std::to_string(state->points[this->hole]) + ""};

    if (state->level == 0) {
      content[0] = ">" + content[0];
    } else if (state->level == 1) {
      if (state->leftButton) {
        this->hole -= 1;
      } else if (state->rightButton) {
        this->hole += 1;
      }

      content[1] = ">" + content[1];
    } else if (state->level == 2) {
      if (state->leftButton && state->rightButton) {
        state->points[this->hole] = 0;
        this->repository->set(state->points);
      } else if (state->leftButton) {
        state->points[this->hole] -= 1;
        this->repository->set(state->points);
      } else if (state->rightButton) {
        state->points[this->hole] += 1;
        this->repository->set(state->points);
      }

      content[2] = ">" + content[2];
    }

    for (size_t i = 0; i < 3; i++) {
      this->u8g2->drawStr(0, 10 + (i + 1) * 10, content[i].c_str());
    }
  }
};

#endif /* H_COUNTER_VIEW */