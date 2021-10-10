#include <Arduino.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "matrixconfig.h"
#include "matrix.h"
#include "translateconfig.h"
#include "translate.h"
#include "lisaconfig.h"
#include "lisa.h"

void setup() {
  matrix_init();
  translate_init();
  lk_init(LK_LAYOUT_US);
#ifdef LK_DEBUG
  Serial.begin(9600);
#endif
}

void loop() {
  char packet = matrix_read_packet();
  if (packet != -1) {
    packet = translate_packet(packet);
    if (packet != 0) {
      lk_write(packet);
#ifdef LK_DEBUG
      Serial.print(packet & 0xFF, HEX);
      Serial.print(" ");
      Serial.println(lk_key_name(packet));
#endif
    }
  }
  lk_flush();
}
