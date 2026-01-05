#ifndef Ws2812
#define Ws2812
#include "config.h"
#include "output_control.h"

extern uint8_t ledpin;
extern uint8_t led_strip[][3];

 
void sendBit(uint8_t bitVal);
void send_reset ();
void send_byte(uint8_t value);
void send_pixel(uint8_t G_val ,uint8_t R_val, uint8_t B_val);
void update_strip(uint8_t strip[][3]);
void fill_color(uint8_t (*strip)[3],uint16_t from , uint16_t to, uint8_t r, uint8_t g, uint8_t b);





#endif