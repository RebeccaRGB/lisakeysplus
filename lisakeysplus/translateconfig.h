#ifndef TRANSLATECONFIG_H
#define TRANSLATECONFIG_H

// ItsyBitsy 32u4 D13
#define TR_LED_DDR  DDRC
#define TR_LED_PORT PORTC
#define TR_LED_PIN  PINC
#define TR_LED_MASK (1<<7)

#define MTX_CAPS_LOCK   0x0A
#define MTX_LEFT_SHIFT  0x0B
#define MTX_RIGHT_SHIFT 0x2C

#endif