#ifndef output_control
#define output_control

#include "config.h"
#include "Ws2812.h"

uint16_t RTC_VAL; // Real time counter in milliseconds

extern uint8_t ledpin;
extern uint8_t led_strip[][3];
extern uint8_t (*strip)[3] ;

extern uint8_t limiter;
extern uint8_t highbeam ; // 0 = daytime, 1 = night/dark,
extern int8_t PWM_pros ; // % Off duty cycle on for ledbar
extern uint8_t light_value ; // White light brightness 0 - 255

extern uint8_t battery_voltage ; // Voltage in int, ex. 12.5 --> 12

extern float_t engine_temperature ;

extern uint8_t currentmode ;
void blinker(uint8_t side);
void setup_control(void);
void set_ledbar(int8_t value);
void read_voltage(void);
void read_temperature (void);
void wakeup_effect(void);
void update_highbeam(void);
uint16_t millis(void);
void wait_ms(uint16_t ms);
void rgb_effect(void);
#endif