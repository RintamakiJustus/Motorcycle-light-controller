#include "Ws2812.h"

 void sendBit(uint8_t bitVal) {
	if (bitVal) {
		PORTA.OUTSET = ledpin;   // HIGH
		__asm__ __volatile__(
		"nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n"
		"nop\nnop\nnop\nnop\nnop\nnop\n" );  // 14 nop ~0.70us
		PORTA.OUTCLR = ledpin;   // LOW
		__asm__ __volatile__(
		"nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n" ); //12 nop ~0.60us
		} else {
		PORTA.OUTSET = ledpin;   // HIGH
		__asm__ __volatile__(
		"nop\nnop\nnop\nnop\nnop\nnop\n" ); //6 nop ~0.30us
		PORTA.OUTCLR = ledpin;   // LOW
		__asm__ __volatile__(
		"nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\n" ); //18 nop ~0.90us
	}
}




void send_reset ()
{
	PORTA.OUTCLR = ledpin; // set to 0
	_delay_us(100);
	
}

void send_byte(uint8_t value)
{
	for(int i = 7; i>=0; i--){
		
		if (value & (1<<i)) // if value at index (lowest to highest, MSB first) is 1 (logical AND 1)
		{
			sendBit(1);
		}
		else {
			sendBit(0);
		}
	}
}
void send_pixel(uint8_t G_val ,uint8_t R_val, uint8_t B_val){ // Function to send one pixel's data
	send_byte(G_val);
	send_byte(R_val);
	send_byte(B_val);
	
}

void update_strip(uint8_t strip[][3])
{
	cli(); //disable interruptions
	for (uint8_t i = 0; i < front_light_led_num; i++) {
		send_pixel(strip[i][0], strip[i][1], strip[i][2]);
	}
	send_reset();
	sei(); //enable interruptions
}

void fill_color(uint8_t (*strip)[3],uint16_t from , uint16_t to, uint8_t r, uint8_t g, uint8_t b) {
	for (uint16_t i = from; i < to; i++) {
		led_strip[i][0] = g;
		led_strip[i][1] = r;
		led_strip[i][2] = b;
	}
}