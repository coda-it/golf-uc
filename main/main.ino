#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, D2, D1);

int lsState = LOW;
int rsState = LOW;

void setup(void) {
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  u8g2.begin();
}

void loop(void) {
  lsState = digitalRead(D3);
  rsState = digitalRead(D4);

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);

  if (lsState && !rsState) {
    u8g2.drawStr(0, 10, "Left clicked");
  } else if (rsState && !lsState) {
    u8g2.drawStr(0, 10, "Right clicked");
  } else {
    u8g2.drawStr(0, 10, "Main menu");
  }

  u8g2.sendBuffer();
  delay(100);
}