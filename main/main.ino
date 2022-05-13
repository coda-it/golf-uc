#include "./models/state.h";
#include "menu.h";
#include <Arduino.h>

int leftButton = LOW;
int rightButton = LOW;
int exitButton = LOW;
int enterButton = LOW;
Menu *menu;

void setup(void) {
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);

  menu = new Menu();
}

void loop(void) {
  leftButton = digitalRead(D6);
  rightButton = digitalRead(D7);
  exitButton = digitalRead(D8);
  enterButton = digitalRead(D5);

  State *state = new State(leftButton, rightButton, exitButton, enterButton);

  menu->render(state);

  delay(100);
}