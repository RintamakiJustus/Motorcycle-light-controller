/*
 * button_handler.c
 *
 * Created: 29.11.2025 13.50.57
 *  Author: Justus
 */ 
#include "button_handler.h"
#include "config.h"
button_t blinker_middle = {0,0,0,0};
button_t blinker_right ={0,0,0,0};
button_t blinker_left = {0,0,0,0};

void reset_buttons(void){
	  blinker_middle.shortpress = 0;
	  blinker_middle.longpress  = 0;

	  blinker_right.shortpress  = 0;
	  blinker_right.longpress   = 0;

	  blinker_left.shortpress   = 0;
	  blinker_left.longpress    = 0;
}
void update_buttons(void){
	cli();
	
	blinker_middle = (button_t){0,0,0,0};
	blinker_right = (button_t){0,0,0,0};
	blinker_left = (button_t){0,0,0,0};
	
	uint16_t middle_b_time = 0;
	uint8_t button_inputs = PORTA.IN; // Read PORTA register
	_delay_ms(20);
	if (PORTA.IN == button_inputs)
	{
		uint16_t PressTime = millis();
		if (!(button_inputs & B_right))
		{
			blinker_right.current = 1;	
		}
		if (!(button_inputs & B_left))
		{
			blinker_left.current = 1;	
		}
		
		uint16_t start = millis();
		while (!(PORTA.IN & middle_button)){    // Wait for Button press to stop
			if (millis() - start > 1000)		// Stop waiting if time over 2s
			{
				break;
			}
		}
		middle_b_time = millis() - PressTime; // Capture time of depress
		if (middle_b_time < 50){
			return;
		}
		else if (middle_b_time < 600)
		{
		blinker_middle.shortpress = 1;
		}
		else if (middle_b_time >= 600 )
		{
		blinker_middle.longpress = 1;
		}
	}
	sei();
}