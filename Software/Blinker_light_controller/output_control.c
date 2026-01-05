/*
 * output_control.c
 *
 * Created: 28.11.2025 17.04.21
 *  Author: Justus
 */ 

#include "output_control.h"
#include "Ws2812.h"
#include "config.h"
 // Remember RGB position
uint8_t Red = 100;
uint8_t Green = 255;
uint8_t Blue = 30;

void wait_ms(uint16_t ms){
	uint16_t oldtime = millis();
	while (millis() - oldtime < ms );
}


void setup_control()
	{
		_PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0x00); // Master clock to 20 MHz
		
		_delay_ms(1000); // wait for inputs to stabilize (debouncing caps)
		
		PORTA.DIRSET = frontlight_data;		// Set main data pin to output
		PORTB.DIRSET =  ledbar_pwm;	 // Set led bar output
		
		PORTA.OUTCLR = frontlight_data;	 // Set data pin to 0
		PORTB.OUTCLR = ledbar_pwm;	// Set led bar pin to 0
		
		PORTA.DIRCLR = B_left;	 //	blinker buttons to inputs, HW debounce
		PORTA.PIN1CTRL |= PORT_ISC_BOTHEDGES_gc; // Both edge interruption
		PORTA.DIRCLR = B_right;
		PORTA.PIN2CTRL |= PORT_ISC_BOTHEDGES_gc; // Both edge interruption
		PORTA.DIRCLR = middle_button;
		PORTA.PIN3CTRL |= PORT_ISC_FALLING_gc; // Falling edge interruption
		
		PORTA.DIRCLR = SW1_pin;	// Pins to input
		PORTA.DIRCLR = SW2_pin;
		PORTA.PIN4CTRL = PORT_PULLUPEN_bm;
		PORTA.PIN5CTRL = PORT_PULLUPEN_bm; // Pull up resistors to switches (sw1 & sw2)
		
		PORTB.DIRSET = PB2;		// PCB led and axillary pin to output (Switch map)
		PORTB.OUTSET = PB2;	    // PULL HIGH
		//////////////////////////////////////////////////////////////////////////
		// Thermistor voltage measurement setup
		PORTA.DIRCLR = thermistorpin; // Thermistor pin to input
		PORTA.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc; //  Disable digital buffer
		
		ADC0.CTRLA = ADC_RESSEL_10BIT_gc; // set 10 bit resolution
		ADC0.CTRLC |= ADC_SAMPCAP_bm | ADC_REFSEL1_bm ; // Enable sample capacitor and select VDD reference
		ADC0.CTRLA |= ADC_ENABLE_bm; // AND enable ADC
		
		//////////////////////////////////////////////////////////////////////////
		// Led bar PWM counter setup TCA0
		PORTB.DIRSET = ledbar_pwm; // Output
		TCA0.SINGLE.CTRLB = TCA_SINGLE_WGMODE_SINGLESLOPE_gc| TCA_SINGLE_CMP0_bm; //PWM state, AND enable
		
		TCA0.SINGLE.PER = 7999; // 16 bit
		TCA0.SINGLE.CMP0 = 0; // Duty cycle
		
		TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV16_gc; // Prescaler 16x
		TCA0.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm; // Start counter
		PORTB.OUTSET = PB2; // Limitermap ON
		
		//////////////////////////////////////////////////////////////////////////
		// Set real time counter to count milliseconds, for millis() -function
		
		while(RTC.STATUS & RTC_CTRLABUSY_bm ); // wait to write (no busy flag)
		RTC.CLKSEL = RTC_CLKSEL_INT1K_gc; // Select internal 1kHz clock
		RTC.CTRLA = RTC_PRESCALER_DIV1_gc | RTC_RTCEN_bm; // 1x prescale and enable RTC
		RTC.CNT = 0; // Reset counter
		
}

void set_ledbar(int8_t value)
{
	if (value > 100) value = 100; // Make sure value not over 100%

	if (value > PWM_pros) {
		// Fade up
		for (uint8_t i = PWM_pros; i <= value; i++) {
			TCA0.SINGLE.CMP0 = i * 80;   // 0...8000
			_delay_ms(2);
		}
	}
	else if (value < PWM_pros) {
		// Fade down
		for (uint8_t i = PWM_pros; i >= value; i--) {
			TCA0.SINGLE.CMP0 = i * 80;
			_delay_ms(20);
			if (i == 0) break;
		}
	}

	PWM_pros = value; // Save value
}
void read_voltage(void){
	uint16_t adc_sum = 0;
	float_t voltage = 0;
	float_t avg = 0;
	
	ADC0.MUXPOS = 0x0B; // Select input AIN 11 for ADC0
	
	for (uint8_t i = 0; i<10 ; i++) {
		ADC0.COMMAND = ADC_STCONV_bm; // Start conversion
		while (!(ADC0.INTFLAGS & ADC_RESRDY_bm)); // Wait for value
		ADC0.INTFLAGS |= ADC_RESRDY_bm; // Clear ready flag
		adc_sum += ADC0.RES;
	}
	avg = adc_sum / 10.0f;
	voltage = (avg/1023)*5*4.3;
	battery_voltage = (int)voltage;
}

void read_temperature (void){
	uint16_t adc_sum = 0;
	ADC0.MUXPOS = 0x07; // AIN7
	
	for (uint8_t i = 0; i<10 ; i++) {
		ADC0.COMMAND = ADC_STCONV_bm; // Start conversion
		while (!(ADC0.INTFLAGS & ADC_RESRDY_bm)); // Wait for value
		adc_sum += ADC0.RES;
	}
	float_t avg = adc_sum / 10;
	
	
	
	
}

void wakeup_effect(void){
	fill_color(led_strip,0,front_light_led_num,0,0,0); // Clear Strip
	for (uint8_t i = 0; i < 10 ; i++ )
	{
		fill_color(led_strip, left_start_idx, i, 15,33,161); // Yamaha blue left side
		fill_color(led_strip, front_light_led_num-i-1 ,front_light_led_num,15,33,161); // Yamaha blue right side
		update_strip(led_strip);
		wait_ms(150);
	}
	
}

void update_highbeam(void){
	
	if (highbeam == 0 ) // daylight
	{
		light_value = 200;
		
		
	}
	
	if (highbeam == 1) //night
	{
		light_value = 50;
		
		
	}
	
}

void blinker(uint8_t side){
	if (side == Left)
	{
		
		fill_color(led_strip,left_start_idx,left_end_idx,255,165,0); // Blinker side to orange
		fill_color(led_strip,right_start_idx,right_end_idx,light_value,light_value,light_value); // other side to White
		update_strip(led_strip);
		
		wait_ms(blinktime);
		
		fill_color(led_strip,0, front_light_led_num, light_value,light_value,light_value); // All white
		update_strip(led_strip);
		
		wait_ms(blinktime);
		
	}
	else {
		fill_color(led_strip,right_start_idx,right_end_idx,255,165,0); // Blinker side to orange
		fill_color(led_strip,left_start_idx,left_end_idx,light_value,light_value,light_value); // other side to White
		update_strip(led_strip);
		
		wait_ms(blinktime);
		fill_color(led_strip,0, front_light_led_num, light_value,light_value,light_value); // All white
		update_strip(led_strip);
		
		wait_ms(blinktime);
	}
	
}

uint16_t millis(){	// Returns 1kHz RTC value = 1 ms
	return RTC.CNT;
}

void rgb_effect(void){
	
	for (uint8_t i = 0; i < front_light_led_num; i++)
	{
		fill_color(led_strip, i, i+1, Red, Green, Blue);
		Red = Red - 5;
		Green = Green + 3;
		Blue = Blue + 1;
		update_strip(led_strip);
		wait_ms(50);
		
	}
}