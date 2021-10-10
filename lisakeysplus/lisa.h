#ifndef LISA_H
#define LISA_H

#define LK_INIT         0x80
#define LK_LAYOUT_FR    0xAD
#define LK_LAYOUT_DE    0xAE
#define LK_LAYOUT_UK    0xAF
#define LK_LAYOUT_US    0xBF
#define LK_FAIL         0xFF

#define LK_BUFFER_SIZE  16

void lk_init(char layout);
void lk_write(char packet);
void lk_delay(unsigned long ms);
void lk_flush();

const char * lk_layout_name(char id);
const char * lk_key_name(char key);

#endif