#include <Arduino.h>
#include <util/delay.h>
#include "matrixconfig.h"
#include "matrix.h"

void matrix_init() {
  // Anodes are pulled high and read as inputs.
  MTX_ANODE_A_DDR  &=~ MTX_ANODE_A_MASK;
  MTX_ANODE_A_PORT |=  MTX_ANODE_A_MASK;
  MTX_ANODE_B_DDR  &=~ MTX_ANODE_B_MASK;
  MTX_ANODE_B_PORT |=  MTX_ANODE_B_MASK;
  MTX_ANODE_C_DDR  &=~ MTX_ANODE_C_MASK;
  MTX_ANODE_C_PORT |=  MTX_ANODE_C_MASK;
  MTX_ANODE_D_DDR  &=~ MTX_ANODE_D_MASK;
  MTX_ANODE_D_PORT |=  MTX_ANODE_D_MASK;
  MTX_ANODE_E_DDR  &=~ MTX_ANODE_E_MASK;
  MTX_ANODE_E_PORT |=  MTX_ANODE_E_MASK;
  MTX_ANODE_F_DDR  &=~ MTX_ANODE_F_MASK;
  MTX_ANODE_F_PORT |=  MTX_ANODE_F_MASK;
  MTX_ANODE_G_DDR  &=~ MTX_ANODE_G_MASK;
  MTX_ANODE_G_PORT |=  MTX_ANODE_G_MASK;
  MTX_ANODE_H_DDR  &=~ MTX_ANODE_H_MASK;
  MTX_ANODE_H_PORT |=  MTX_ANODE_H_MASK;
  MTX_ANODE_J_DDR  &=~ MTX_ANODE_J_MASK;
  MTX_ANODE_J_PORT |=  MTX_ANODE_J_MASK;
  MTX_ANODE_K_DDR  &=~ MTX_ANODE_K_MASK;
  MTX_ANODE_K_PORT |=  MTX_ANODE_K_MASK;
  // Cathodes are normally high but pulled low when probing.
  MTX_CATHODE_1_DDR  |= MTX_CATHODE_1_MASK;
  MTX_CATHODE_1_PORT |= MTX_CATHODE_1_MASK;
  MTX_CATHODE_2_DDR  |= MTX_CATHODE_2_MASK;
  MTX_CATHODE_2_PORT |= MTX_CATHODE_2_MASK;
  MTX_CATHODE_3_DDR  |= MTX_CATHODE_3_MASK;
  MTX_CATHODE_3_PORT |= MTX_CATHODE_3_MASK;
  MTX_CATHODE_4_DDR  |= MTX_CATHODE_4_MASK;
  MTX_CATHODE_4_PORT |= MTX_CATHODE_4_MASK;
  MTX_CATHODE_5_DDR  |= MTX_CATHODE_5_MASK;
  MTX_CATHODE_5_PORT |= MTX_CATHODE_5_MASK;
  MTX_CATHODE_6_DDR  |= MTX_CATHODE_6_MASK;
  MTX_CATHODE_6_PORT |= MTX_CATHODE_6_MASK;
  MTX_CATHODE_7_DDR  |= MTX_CATHODE_7_MASK;
  MTX_CATHODE_7_PORT |= MTX_CATHODE_7_MASK;
  MTX_CATHODE_8_DDR  |= MTX_CATHODE_8_MASK;
  MTX_CATHODE_8_PORT |= MTX_CATHODE_8_MASK;
}

void matrix_read(char * state) {
  state[0] = 0;
  state[1] = 0;
  state[2] = 0;
  state[3] = 0;
  state[4] = 0;
  state[5] = 0;
  state[6] = 0;
  state[7] = 0;
  state[8] = 0;
  state[9] = 0;

  MTX_CATHODE_1_PORT &=~ MTX_CATHODE_1_MASK;
  _delay_us(16);
  if (!(MTX_ANODE_A_PIN & MTX_ANODE_A_MASK)) state[0] |= 0x01;
  if (!(MTX_ANODE_B_PIN & MTX_ANODE_B_MASK)) state[1] |= 0x01;
  if (!(MTX_ANODE_C_PIN & MTX_ANODE_C_MASK)) state[2] |= 0x01;
  if (!(MTX_ANODE_D_PIN & MTX_ANODE_D_MASK)) state[3] |= 0x01;
  if (!(MTX_ANODE_E_PIN & MTX_ANODE_E_MASK)) state[4] |= 0x01;
  if (!(MTX_ANODE_F_PIN & MTX_ANODE_F_MASK)) state[5] |= 0x01;
  if (!(MTX_ANODE_G_PIN & MTX_ANODE_G_MASK)) state[6] |= 0x01;
  if (!(MTX_ANODE_H_PIN & MTX_ANODE_H_MASK)) state[7] |= 0x01;
  if (!(MTX_ANODE_J_PIN & MTX_ANODE_J_MASK)) state[8] |= 0x01;
  if (!(MTX_ANODE_K_PIN & MTX_ANODE_K_MASK)) state[9] |= 0x01;
  MTX_CATHODE_1_PORT |=  MTX_CATHODE_1_MASK;

  MTX_CATHODE_2_PORT &=~ MTX_CATHODE_2_MASK;
  _delay_us(16);
  if (!(MTX_ANODE_A_PIN & MTX_ANODE_A_MASK)) state[0] |= 0x02;
  if (!(MTX_ANODE_B_PIN & MTX_ANODE_B_MASK)) state[1] |= 0x02;
  if (!(MTX_ANODE_C_PIN & MTX_ANODE_C_MASK)) state[2] |= 0x02;
  if (!(MTX_ANODE_D_PIN & MTX_ANODE_D_MASK)) state[3] |= 0x02;
  if (!(MTX_ANODE_E_PIN & MTX_ANODE_E_MASK)) state[4] |= 0x02;
  if (!(MTX_ANODE_F_PIN & MTX_ANODE_F_MASK)) state[5] |= 0x02;
  if (!(MTX_ANODE_G_PIN & MTX_ANODE_G_MASK)) state[6] |= 0x02;
  if (!(MTX_ANODE_H_PIN & MTX_ANODE_H_MASK)) state[7] |= 0x02;
  if (!(MTX_ANODE_J_PIN & MTX_ANODE_J_MASK)) state[8] |= 0x02;
  if (!(MTX_ANODE_K_PIN & MTX_ANODE_K_MASK)) state[9] |= 0x02;
  MTX_CATHODE_2_PORT |=  MTX_CATHODE_2_MASK;

  MTX_CATHODE_3_PORT &=~ MTX_CATHODE_3_MASK;
  _delay_us(16);
  if (!(MTX_ANODE_A_PIN & MTX_ANODE_A_MASK)) state[0] |= 0x04;
  if (!(MTX_ANODE_B_PIN & MTX_ANODE_B_MASK)) state[1] |= 0x04;
  if (!(MTX_ANODE_C_PIN & MTX_ANODE_C_MASK)) state[2] |= 0x04;
  if (!(MTX_ANODE_D_PIN & MTX_ANODE_D_MASK)) state[3] |= 0x04;
  if (!(MTX_ANODE_E_PIN & MTX_ANODE_E_MASK)) state[4] |= 0x04;
  if (!(MTX_ANODE_F_PIN & MTX_ANODE_F_MASK)) state[5] |= 0x04;
  if (!(MTX_ANODE_G_PIN & MTX_ANODE_G_MASK)) state[6] |= 0x04;
  if (!(MTX_ANODE_H_PIN & MTX_ANODE_H_MASK)) state[7] |= 0x04;
  if (!(MTX_ANODE_J_PIN & MTX_ANODE_J_MASK)) state[8] |= 0x04;
  if (!(MTX_ANODE_K_PIN & MTX_ANODE_K_MASK)) state[9] |= 0x04;
  MTX_CATHODE_3_PORT |=  MTX_CATHODE_3_MASK;

  MTX_CATHODE_4_PORT &=~ MTX_CATHODE_4_MASK;
  _delay_us(16);
  if (!(MTX_ANODE_A_PIN & MTX_ANODE_A_MASK)) state[0] |= 0x08;
  if (!(MTX_ANODE_B_PIN & MTX_ANODE_B_MASK)) state[1] |= 0x08;
  if (!(MTX_ANODE_C_PIN & MTX_ANODE_C_MASK)) state[2] |= 0x08;
  if (!(MTX_ANODE_D_PIN & MTX_ANODE_D_MASK)) state[3] |= 0x08;
  if (!(MTX_ANODE_E_PIN & MTX_ANODE_E_MASK)) state[4] |= 0x08;
  if (!(MTX_ANODE_F_PIN & MTX_ANODE_F_MASK)) state[5] |= 0x08;
  if (!(MTX_ANODE_G_PIN & MTX_ANODE_G_MASK)) state[6] |= 0x08;
  if (!(MTX_ANODE_H_PIN & MTX_ANODE_H_MASK)) state[7] |= 0x08;
  if (!(MTX_ANODE_J_PIN & MTX_ANODE_J_MASK)) state[8] |= 0x08;
  if (!(MTX_ANODE_K_PIN & MTX_ANODE_K_MASK)) state[9] |= 0x08;
  MTX_CATHODE_4_PORT |=  MTX_CATHODE_4_MASK;

  MTX_CATHODE_5_PORT &=~ MTX_CATHODE_5_MASK;
  _delay_us(16);
  if (!(MTX_ANODE_A_PIN & MTX_ANODE_A_MASK)) state[0] |= 0x10;
  if (!(MTX_ANODE_B_PIN & MTX_ANODE_B_MASK)) state[1] |= 0x10;
  if (!(MTX_ANODE_C_PIN & MTX_ANODE_C_MASK)) state[2] |= 0x10;
  if (!(MTX_ANODE_D_PIN & MTX_ANODE_D_MASK)) state[3] |= 0x10;
  if (!(MTX_ANODE_E_PIN & MTX_ANODE_E_MASK)) state[4] |= 0x10;
  if (!(MTX_ANODE_F_PIN & MTX_ANODE_F_MASK)) state[5] |= 0x10;
  if (!(MTX_ANODE_G_PIN & MTX_ANODE_G_MASK)) state[6] |= 0x10;
  if (!(MTX_ANODE_H_PIN & MTX_ANODE_H_MASK)) state[7] |= 0x10;
  if (!(MTX_ANODE_J_PIN & MTX_ANODE_J_MASK)) state[8] |= 0x10;
  if (!(MTX_ANODE_K_PIN & MTX_ANODE_K_MASK)) state[9] |= 0x10;
  MTX_CATHODE_5_PORT |=  MTX_CATHODE_5_MASK;

  MTX_CATHODE_6_PORT &=~ MTX_CATHODE_6_MASK;
  _delay_us(16);
  if (!(MTX_ANODE_A_PIN & MTX_ANODE_A_MASK)) state[0] |= 0x20;
  if (!(MTX_ANODE_B_PIN & MTX_ANODE_B_MASK)) state[1] |= 0x20;
  if (!(MTX_ANODE_C_PIN & MTX_ANODE_C_MASK)) state[2] |= 0x20;
  if (!(MTX_ANODE_D_PIN & MTX_ANODE_D_MASK)) state[3] |= 0x20;
  if (!(MTX_ANODE_E_PIN & MTX_ANODE_E_MASK)) state[4] |= 0x20;
  if (!(MTX_ANODE_F_PIN & MTX_ANODE_F_MASK)) state[5] |= 0x20;
  if (!(MTX_ANODE_G_PIN & MTX_ANODE_G_MASK)) state[6] |= 0x20;
  if (!(MTX_ANODE_H_PIN & MTX_ANODE_H_MASK)) state[7] |= 0x20;
  if (!(MTX_ANODE_J_PIN & MTX_ANODE_J_MASK)) state[8] |= 0x20;
  if (!(MTX_ANODE_K_PIN & MTX_ANODE_K_MASK)) state[9] |= 0x20;
  MTX_CATHODE_6_PORT |=  MTX_CATHODE_6_MASK;

  MTX_CATHODE_7_PORT &=~ MTX_CATHODE_7_MASK;
  _delay_us(16);
  if (!(MTX_ANODE_A_PIN & MTX_ANODE_A_MASK)) state[0] |= 0x40;
  if (!(MTX_ANODE_B_PIN & MTX_ANODE_B_MASK)) state[1] |= 0x40;
  if (!(MTX_ANODE_C_PIN & MTX_ANODE_C_MASK)) state[2] |= 0x40;
  if (!(MTX_ANODE_D_PIN & MTX_ANODE_D_MASK)) state[3] |= 0x40;
  if (!(MTX_ANODE_E_PIN & MTX_ANODE_E_MASK)) state[4] |= 0x40;
  if (!(MTX_ANODE_F_PIN & MTX_ANODE_F_MASK)) state[5] |= 0x40;
  if (!(MTX_ANODE_G_PIN & MTX_ANODE_G_MASK)) state[6] |= 0x40;
  if (!(MTX_ANODE_H_PIN & MTX_ANODE_H_MASK)) state[7] |= 0x40;
  if (!(MTX_ANODE_J_PIN & MTX_ANODE_J_MASK)) state[8] |= 0x40;
  if (!(MTX_ANODE_K_PIN & MTX_ANODE_K_MASK)) state[9] |= 0x40;
  MTX_CATHODE_7_PORT |=  MTX_CATHODE_7_MASK;

  MTX_CATHODE_8_PORT &=~ MTX_CATHODE_8_MASK;
  _delay_us(16);
  if (!(MTX_ANODE_A_PIN & MTX_ANODE_A_MASK)) state[0] |= 0x80;
  if (!(MTX_ANODE_B_PIN & MTX_ANODE_B_MASK)) state[1] |= 0x80;
  if (!(MTX_ANODE_C_PIN & MTX_ANODE_C_MASK)) state[2] |= 0x80;
  if (!(MTX_ANODE_D_PIN & MTX_ANODE_D_MASK)) state[3] |= 0x80;
  if (!(MTX_ANODE_E_PIN & MTX_ANODE_E_MASK)) state[4] |= 0x80;
  if (!(MTX_ANODE_F_PIN & MTX_ANODE_F_MASK)) state[5] |= 0x80;
  if (!(MTX_ANODE_G_PIN & MTX_ANODE_G_MASK)) state[6] |= 0x80;
  if (!(MTX_ANODE_H_PIN & MTX_ANODE_H_MASK)) state[7] |= 0x80;
  if (!(MTX_ANODE_J_PIN & MTX_ANODE_J_MASK)) state[8] |= 0x80;
  if (!(MTX_ANODE_K_PIN & MTX_ANODE_K_MASK)) state[9] |= 0x80;
  MTX_CATHODE_8_PORT |=  MTX_CATHODE_8_MASK;
}

static char lastState[MTX_STATE_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static char packetBuffer[MTX_BUFFER_SIZE];
static char packetBufStart = 0;
static char packetBufEnd = 0;

static void matrix_write_packet(char packet) {
  packetBuffer[packetBufEnd] = packet;
  packetBufEnd++;
  packetBufEnd &= (MTX_BUFFER_SIZE - 1);
  if (packetBufEnd == packetBufStart) {
    // Buffer overflow. Ignore input.
    packetBufEnd--;
    packetBufEnd &= (MTX_BUFFER_SIZE - 1);
  }
}

char matrix_read_packet() {
  char nextState[MTX_STATE_SIZE];
  char released[MTX_STATE_SIZE];
  char pressed[MTX_STATE_SIZE];
  char changed = 0;
  char packet;
  char i, m;

  matrix_read(nextState);
  for (i = 0; i < MTX_STATE_SIZE; i++) {
    released[i] = lastState[i] &~ nextState[i];
    pressed[i] = nextState[i] &~ lastState[i];
    changed |= released[i] | pressed[i];
    lastState[i] = nextState[i];
  }

  for (packet = 0, i = 0; i < MTX_STATE_SIZE; i++) {
    for (m = 1; m != 0; m <<= 1, packet++) {
      if (released[i] & m) matrix_write_packet(packet | 0x80);
      if (pressed[i] & m) matrix_write_packet(packet);
    }
  }

  if (changed) delay(MTX_DEBOUNCE_TIME);

  if (packetBufStart == packetBufEnd) return -1;
  packet = packetBuffer[packetBufStart];
  packetBufStart++;
  packetBufStart &= (MTX_BUFFER_SIZE - 1);
  return packet;
}