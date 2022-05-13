#ifndef H_STATE
#define H_STATE

class State {
public:
  int leftButton;
  int rightButton;
  int exitButton;
  int enterButton;

  State(int lB, int rB, int exB, int enB) {
    leftButton = lB;
    rightButton = rB;
    exitButton = exB;
    enterButton = enB;
  }
};

#endif /* H_STATE */