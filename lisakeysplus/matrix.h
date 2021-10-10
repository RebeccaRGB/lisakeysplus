#ifndef MATRIX_H
#define MATRIX_H

#define MTX_STATE_SIZE    10
#define MTX_BUFFER_SIZE   16
#define MTX_DEBOUNCE_TIME 10

void matrix_init();
void matrix_read(char * state);
char matrix_read_packet();

#endif