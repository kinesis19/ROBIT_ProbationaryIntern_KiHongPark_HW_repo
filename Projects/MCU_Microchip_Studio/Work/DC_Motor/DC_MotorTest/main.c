/*
 * DC_MotorTest.c
 *
 * Created: 2024-08-07 오후 3:45:12
 * Author : lordk
 */ 
//
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD_Text.h"

void Initializing(void);

int main(void) {

	Initializing();
	
	while (1) {
		
	}	
}

void Initializing(void){
	// -----[Declare Register]-----
	DDRB = 0x6F;  // PB1, PB2 핀을 출력으로 설정하기(OC1A, OC1B).
	
	EIMSK = 0b00001111;
	EICRA = 0b10101010;
	
	TCCR1A = 0xA2; // 0b10100010
	TCCR1B = 0x1A; // 0b00011010
	TCCR1C = 0x00; // 0b00000000
	
	ICR1 = 399;
	TCNT1 = 0x00;
	
	sei();
	
	lcdInit();
	lcdClear();
}


// -----[Switch Interrupt Control]-----
// -----[Moving: Forward]-----
ISR(INT0_vect){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 1;
	OCR1B = ICR1 * 1;
	
	lcdClear();
	lcdString(0, 0, "Moving Foward!");
}

// -----[Moving: Back]-----
ISR(INT1_vect){
	PORTB = (PORTB & 0xF0) | 0x0A;
	OCR1A = ICR1 * 1;
	OCR1B = ICR1 * 1;
	
	lcdClear();
	lcdString(0, 0, "Moving Back!");
}


// -----[Turning: Left]-----
ISR(INT2_vect){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 1;
	OCR1B = ICR1 * 0;
	
	lcdClear();
	lcdString(0, 0, "Turning Left!");
}

// -----[Turning: Right]-----
ISR(INT3_vect){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0;
	OCR1B = ICR1 * 1;
	
	lcdClear();
	lcdString(0, 0, "Turning Right!!");
}