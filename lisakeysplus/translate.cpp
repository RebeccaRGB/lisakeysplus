#include <Arduino.h>
#include <avr/pgmspace.h>
#include "translateconfig.h"
#include "translate.h"

static const char translation_table[] PROGMEM = {
  0x46, 0x5C, 0x7F, 0x7C, 0x4D, 0x28, 0x24, 0x20, // Anode A:  Entr Spce Appl LOpt N1   N4   N7   Clr
  0x68, 0x78, 0x7D, 0x7E, 0x2F, 0x2B, 0x27, 0x23, // Anode B:  `~   Tab  Caps LShf NEnt N,   N/   N*
  0x74, 0x75, 0x70, 0x79, 0x2E, 0x2A, 0x26, 0x22, // Anode C:  1    Q    A    Z    N3   N6   N9   N+
  0x71, 0x77, 0x76, 0x7A, 0x2D, 0x29, 0x25, 0x21, // Anode D:  2    W    S    X    N2   N5   N8   N-
  0x72, 0x60, 0x7B, 0x6D, 0x2C, 0x49, 0x42, 0x45, // Anode E:  3    E    D    C    N.   N0   \|   Bksp
  0x73, 0x65, 0x69, 0x6C, 0x7E, 0x48, 0x57, 0x41, // Anode F:  4    R    F    V    RShf Ret  ]}   +=
  0x64, 0x66, 0x6A, 0x6E, 0x4E, 0x5B, 0x56, 0x40, // Anode G:  5    T    G    B    ROpt '"   [{   -_
  0x61, 0x67, 0x6B, 0x6F, 0x4C, 0x5A, 0x44, 0x51, // Anode H:  6    Y    H    N    /?   ;:   P    0
  0x62, 0x52, 0x54, 0x58, 0x5E, 0x59, 0x5F, 0x50, // Anode J:  7    U    J    M    .>   L    O    9
  0x63, 0x53, 0x55, 0x5D,                         // Anode K:  8    I    K    ,<
};

static char caps_lock;
static char left_shift;
static char right_shift;

void translate_init() {
  TR_LED_DDR  |=  TR_LED_MASK;
  TR_LED_PORT &=~ TR_LED_MASK;
  caps_lock = 0;
  left_shift = 0;
  right_shift = 0; 
}

char translate_packet(char packet) {
  char released = packet & 0x80;
  packet &= 0x7F;

  // Emulate the Lisa's latching caps lock key.
  if (packet == MTX_CAPS_LOCK) {
    switch (caps_lock) {
      case 0:
        if (released) return 0;
        TR_LED_PORT |=  TR_LED_MASK;
        caps_lock = 1;
        break;
      case 1:
        if (released) caps_lock = 2;
        return 0;
      case 2:
        if (!released) caps_lock = 3;
        return 0;
      case 3:
        if (!released) return 0;
        TR_LED_PORT &=~ TR_LED_MASK;
        caps_lock = 0;
        break;
    }
  }

  // Emulate the Lisa's coupled shift keys.
  if (packet == MTX_LEFT_SHIFT || packet == MTX_RIGHT_SHIFT) {
    char last_shift = left_shift || right_shift;
    if (packet == MTX_LEFT_SHIFT) left_shift = !released;
    if (packet == MTX_RIGHT_SHIFT) right_shift = !released;
    char next_shift = left_shift || right_shift;
    if (next_shift == last_shift) return 0;
  }

  packet = pgm_read_byte(&translation_table[packet]);
  if (!released) packet |= 0x80;
  return packet;
}