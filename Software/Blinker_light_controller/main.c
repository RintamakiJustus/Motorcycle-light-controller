/*
 * main.c
 *
 * Created: 9/15/2025 4:49:18 PM
 *  Author: Justus
 */ 
#include "config.h"
#include "Ws2812.h"
#include "output_control.h"
#include "button_handler.h"

/////// GLOBAL VARIABLES




//////////////////////////////////////////////////////////////////////////
					// STATES:
					// 1 = Park
					// 2 = Drive
					// 3 = Party
					// 4 = Info
					 
uint8_t state = 1;	
	
					
uint8_t ledpin = frontlight_data;

uint8_t led_strip[front_light_led_num][3];
uint8_t (*strip)[3] = led_strip;

uint8_t limiter = 1;
uint8_t highbeam = 0; // 0 = daytime, 1 = night/dark,
int8_t PWM_pros = 0; // % Off duty cycle on for ledbar
uint8_t light_value = 100; // White light brightness 0 - 255

uint8_t battery_voltage = 0; // Voltage in int, ex. 12.5 --> 12

float_t engine_temperature = 0;

uint8_t buttonflag = 0; // Flag for any button input

	
void blink_code(uint8_t num);

int setup(void){
	reset_buttons();
	limiter = 1;
	setup_control();
	
	sei(); // enable interruptions
	return 1;
}

void state_machine(){
	switch (state)
	{
		case 1 : // Park
		fill_color(led_strip,0, front_light_led_num-1, light_value,light_value,light_value); // white
		update_strip(led_strip);
		set_ledbar(10);
		
		break;
		
		case 2 : // Drive
		fill_color(led_strip,0, front_light_led_num-1, light_value,light_value,light_value);
		update_strip(led_strip);
		
		if (highbeam)
		{
			set_ledbar(80);
			
		}
		else {
			set_ledbar(20);
		}
		if (blinker_left.current)
		{
			blinker(Left);
		}
		else if (blinker_right.current)
		{
			blinker(Right);
		}
		else if (blinker_middle.shortpress)
		{
			if (highbeam) // Switch High beam Off and On
			{
				highbeam = 0;
			}
			else {
				highbeam = 1;
			}
		}
		
		break;
		
		case 3 : // Party
		
		set_ledbar(3);
		rgb_effect();
		update_strip(led_strip);
		break;
		
		case 4 : // Info
		fill_color(led_strip,0, front_light_led_num-1, 255,0,255);
		set_ledbar(0);
		update_strip(led_strip);
		if (blinker_middle.longpress)
		{
			blink_code(battery_voltage);
			_delay_ms(1000);
			_delay_ms(1000);
			
		}
		break;
		
		
	}
}



void update_mode(){
	if (blinker_left.current && blinker_middle.longpress)
	{
		state++;
		
	}
	if (state > mode_number)
	{
		state = 1;
	}
	
}

void blink_code(uint8_t num){
	PORTB.OUTCLR = PB2;
	set_ledbar(0);
	for (uint8_t i = 0; i<num;i++ )
	{
		PORTB.OUTCLR = PB2;
		wait_ms(500);
		PORTB.OUTSET = PB2;
		wait_ms(500);
	}
}
	

ISR(PORTA_PORT_vect){
	PORTA.INTFLAGS = 0xff; // Reset interrupt flags
	buttonflag = 1;
}


int main(void)
{
	setup();
	
	_delay_ms(200);
	
	wakeup_effect();
	fill_color(led_strip,0, front_light_led_num, 0,0,0); //Off
	
	update_buttons();
	
	if (blinker_middle.longpress) {
		limiter = 0;
		PORTB.OUTCLR = PB2; // Main map on
	}
	else {
		PORTB.OUTSET = PB2;
	}
	
    while(1)
    {
		
	
		update_mode();
		update_highbeam();
		read_voltage();
		
		state_machine();
		reset_buttons();
		if (buttonflag)
		{
			update_buttons();
			buttonflag = 0;
		}
		wait_ms(10);
	}
}