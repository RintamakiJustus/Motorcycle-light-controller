/*
 * config.h
 *
 * Created: 29.9.2025 19.47.51
 *  Author: Justus
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#define F_CPU 20000000

#include <xc.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include "output_control.h"
#include "Ws2812.h"

#define blinktime 400 // MS
#define calfactor 1.09; //Calibration factor for voltage measurement

#define front_light_led_num 20  // number of leds in strip
#define left_start_idx 0		// Left side index's
#define left_end_idx 9
#define right_start_idx 9		// Right side index's
#define right_end_idx 19
#define mode_number 4			// Number of different Modes


#define Left 1					// Made-up boolean expressions for directions
#define Right 0

#define frontlight_data PIN6_bm // PORTA
#define ledbar_pwm PIN0_bm    // PORTB
#define voltage_pin PIN1_bm // PORTB 


#define B_left PIN1_bm // PORTA, Blinker switch left
#define B_right PIN2_bm // PORTA, Blinker switch right
#define middle_button PIN3_bm  // PORTA, middle button
#define SW1_pin PIN5_bm // PORTA, switch 1
#define SW2_pin PIN4_bm // PORTA, switch 2

//Auxillary outputs

#define sft_DATA PIN2_bm // PORTB, +led sft data
#define thermistorpin PIN7_bm // PORTA, 100k Pull-up
#define sft_CLK PIN3_bm // PORTB 


#endif /* CONFIG_H_ */