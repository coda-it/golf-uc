#ifndef H_STATE
#define H_STATE

class State {
public:
  int leftButton;
  int rightButton;
  int exitButton;
  int enterButton;
  unsigned int points[16] = {0};
  int level = 0;

  State(int lB, int rB, int exB, int enB) {
    this->updateInputs(lB, rB, exB, enB);
  }

  void updateInputs(int lB, int rB, int exB, int enB) {
    this->leftButton = lB;
    this->rightButton = rB;
    this->exitButton = exB;
    this->enterButton = enB;
  }
};

#endif /* H_STATE */