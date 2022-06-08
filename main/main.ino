#include "./models/state.h"
#include "constants.h"
#include "menu.h"
#include <Arduino.h>
#include <EEPROM.h>

int leftButton = LOW;
int rightButton = LOW;
int exitButton = LOW;
int enterButton = LOW;
Menu *menu;
State *state;

void setup(void) {
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D8, INPUT);

  EEPROM.begin(512);

  menu = new Menu();
  state = new State(leftButton, rightButton, exitButton, enterButton);

  int addressIndex = 0;
  for (int i = 0; i < HOLES; i++) {
    state->points[i] =
        (EEPROM.read(addressIndex) << 8) + EEPROM.read(addressIndex + 1);
    addressIndex += 2;
  }
}

void loop(void) {
  leftButton = digitalRead(D6);
  rightButton = digitalRead(D7);
  exitButton = digitalRead(D8);
  enterButton = digitalRead(D5);

  state->updateInputs(leftButton, rightButton, exitButton, enterButton);
  menu->render(state);

  delay(100);
}