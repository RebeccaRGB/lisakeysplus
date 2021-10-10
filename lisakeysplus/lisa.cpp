#include <Arduino.h>
#include <util/delay.h>
#include "lisaconfig.h"
#include "lisa.h"

static char layoutID;
static char keyBuffer[LK_BUFFER_SIZE];
static char keyBufStart;
static char keyBufEnd;

void lk_init(char layout) {
  LK_DATA_DDR  &=~ LK_DATA_MASK; // input
  LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  layoutID = layout;
  keyBuffer[0] = LK_INIT;
  keyBuffer[1] = layout;
  keyBufStart = 0;
  keyBufEnd = 2;
}

void lk_write(char packet) {
  keyBuffer[keyBufEnd] = packet;
  keyBufEnd++;
  keyBufEnd &= (LK_BUFFER_SIZE - 1);
  if (keyBufEnd == keyBufStart) {
    // Buffer overflow. Ignore input.
    keyBufEnd--;
    keyBufEnd &= (LK_BUFFER_SIZE - 1);
  }
}

void lk_delay(unsigned long ms) {
  unsigned long time = millis();
  while ((millis() - time) < ms) {
    lk_flush();
  }
}

// Nominally 12?, 16, 16, 32, 16, but have to be adjusted
// to compensate for time taken by the microcontroller.
// These have been adjusted to work with a real Lisa.
#define LK_PACKET_OUT_DELAY 10
#define LK_PACKET_OUT_START 15
#define LK_PACKET_OUT_SHORT 15
#define LK_PACKET_OUT_LONG  30
#define LK_PACKET_OUT_STOP  15

void lk_flush() {
  // Wait for start of sync signal.
  unsigned long time = micros();
  while (LK_DATA_PIN & LK_DATA_MASK) {
    if ((micros() - time) > 4096) {
      // If start of sync doesn't come, try later.
      return;
    }
  }

  // Wait for end of sync signal.
  time = micros();
  while (!(LK_DATA_PIN & LK_DATA_MASK));
  if ((micros() - time) > 128) {
    // If too long to be a sync signal, reset.
    keyBuffer[0] = LK_INIT;
    keyBuffer[1] = layoutID;
    keyBufStart = 0;
    keyBufEnd = 2;
    return;
  }

  // If no output, don't respond.
  if (keyBufStart == keyBufEnd) return;

  noInterrupts();

  // Write data packet.
  char packet = keyBuffer[keyBufStart];
  keyBufStart++;
  keyBufStart &= (LK_BUFFER_SIZE - 1);
  _delay_us(LK_PACKET_OUT_DELAY);

  // start bit
  LK_DATA_DDR  |=  LK_DATA_MASK; // output
  LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  _delay_us(LK_PACKET_OUT_START);

  // bit 4
  if (packet & 0x10) LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  else               LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_SHORT);

  // bit 5
  if (packet & 0x20) LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  else               LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_SHORT);

  // bit 6
  if (packet & 0x40) LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  else               LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_SHORT);

  // bit 7
  if (packet & 0x80) LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  else               LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_LONG);

  // bit 0
  if (packet & 0x01) LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  else               LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_SHORT);

  // bit 1
  if (packet & 0x02) LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  else               LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_SHORT);

  // bit 2
  if (packet & 0x04) LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  else               LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_SHORT);

  // bit 3
  if (packet & 0x08) LK_DATA_PORT &=~ LK_DATA_MASK; // pull down
  else               LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_SHORT);

  // stop bit
  LK_DATA_DDR  &=~ LK_DATA_MASK; // input
  LK_DATA_PORT |=  LK_DATA_MASK; // pull up
  _delay_us(LK_PACKET_OUT_STOP);

  interrupts();
}

const char * lk_layout_name(char id) {
  if (id == LK_LAYOUT_US) return "US";
  if (id == LK_LAYOUT_UK) return "UK";
  if (id == LK_LAYOUT_DE) return "DE";
  if (id == LK_LAYOUT_FR) return "FR";
  return "???";
}

const char * lk_key_name(char key) {
  switch (key & 0x7F) {
    case 0x20: return "N Clear";
    case 0x21: return "N -";
    case 0x22: return "N +";
    case 0x23: return "N *";
    case 0x24: return "N 7";
    case 0x25: return "N 8";
    case 0x26: return "N 9";
    case 0x27: return "N /";
    case 0x28: return "N 4";
    case 0x29: return "N 5";
    case 0x2A: return "N 6";
    case 0x2B: return "N ,";
    case 0x2C: return "N .";
    case 0x2D: return "N 2";
    case 0x2E: return "N 3";
    case 0x2F: return "N Enter";
    case 0x40: return "-";
    case 0x41: return "=";
    case 0x42: return "\\";
    case 0x43: return "<>";
    case 0x44: return "P";
    case 0x45: return "Backspace";
    case 0x46: return "Enter";
    case 0x47: return "???";
    case 0x48: return "Return";
    case 0x49: return "N 0";
    case 0x4A: return "???";
    case 0x4B: return "???";
    case 0x4C: return "/";
    case 0x4D: return "N 1";
    case 0x4E: return "R Option";
    case 0x4F: return "???";
    case 0x50: return "9";
    case 0x51: return "0";
    case 0x52: return "U";
    case 0x53: return "I";
    case 0x54: return "J";
    case 0x55: return "K";
    case 0x56: return "[";
    case 0x57: return "]";
    case 0x58: return "M";
    case 0x59: return "L";
    case 0x5A: return ";";
    case 0x5B: return "\"";
    case 0x5C: return "Space";
    case 0x5D: return ",";
    case 0x5E: return ".";
    case 0x5F: return "O";
    case 0x60: return "E";
    case 0x61: return "6";
    case 0x62: return "7";
    case 0x63: return "8";
    case 0x64: return "5";
    case 0x65: return "R";
    case 0x66: return "T";
    case 0x67: return "Y";
    case 0x68: return "~";
    case 0x69: return "F";
    case 0x6A: return "G";
    case 0x6B: return "H";
    case 0x6C: return "V";
    case 0x6D: return "C";
    case 0x6E: return "B";
    case 0x6F: return "N";
    case 0x70: return "A";
    case 0x71: return "2";
    case 0x72: return "3";
    case 0x73: return "4";
    case 0x74: return "1";
    case 0x75: return "Q";
    case 0x76: return "S";
    case 0x77: return "W";
    case 0x78: return "Tab";
    case 0x79: return "Z";
    case 0x7A: return "X";
    case 0x7B: return "D";
    case 0x7C: return "L Option";
    case 0x7D: return "Caps Lock";
    case 0x7E: return "Shift";
    case 0x7F: return "Apple";
    default: return "???";
  }
}