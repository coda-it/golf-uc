#include "menu.h";
#include <Arduino.h>

int lsState = LOW;
int rsState = LOW;
Menu *menu;

void setup(void) {
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);

  menu = new Menu();
}

void loop(void) {
  lsState = digitalRead(D6);
  rsState = digitalRead(D7);

  menu->render(lsState, rsState);

  delay(100);
}