#ifndef BUTTON_HANDLER
#define BUTTON_HANDLER

#include "config.h"


typedef struct
{
	uint8_t previous;
	uint8_t current;
	uint8_t shortpress;
	uint8_t longpress;
} button_t;
extern button_t blinker_middle;
extern button_t blinker_right;
extern button_t blinker_left;

void reset_buttons(void);
void update_buttons(void);


#endif