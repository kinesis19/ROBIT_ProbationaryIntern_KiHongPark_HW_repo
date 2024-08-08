/*
 * IRSensor_Test.c
 *
 * Created: 2024-08-08 오후 4:47:43
 * Author : lordk
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include "LCD_Text.h"

int main(void) {
	
	lcdInit();
	lcdClear();
	
    while (1) {
		lcdString(0, 0, "aa");
		_delay_ms(100);
    }
}

