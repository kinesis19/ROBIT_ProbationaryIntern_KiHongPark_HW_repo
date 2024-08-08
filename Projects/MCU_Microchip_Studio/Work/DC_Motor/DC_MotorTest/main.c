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

int main(void) {
	DDRB = 0x6F;  // PB1, PB2 핀을 출력으로 설정하기(OC1A, OC1B).

	TCCR1A = 0xA2; // 0b10100010
	TCCR1B = 0x1A; // 0b00011010
	TCCR1C = 0x00; // 0b00000000

	ICR1 = 399;
	TCNT1 = 0x00;

	sei();

	while (1) {
		
		//1번 모터는 fast pwm 모드로 동작하기.
		PORTB = (PORTB & 0xF0) | 0x05;
		OCR1A = ICR1 * 0.5;
		_delay_ms(500);


		PORTB = (PORTB & 0xF0) | 0x0A;
		OCR1A = ICR1 * 0.5;
		_delay_ms(500);

		//2번 모터는 correct PWM 모드로 동작하기.
		// Phase Correct PWM 모드 설정 (2번 모터)
		//TCCR1A = (TCCR1A & ~(1 << COM1A1)) | (1 << COM1B1);
		//TCCR1B = (TCCR1B & ~(1 << WGM12)) | (1 << WGM13);

		ICR1 = 199;

		// 정회전하기.
		PORTB = (PORTB & 0xF0) | 0x05;
		OCR1B = ICR1 * 0.50;
		_delay_ms(100);

		// 역회전하기.
		//PORTD = (PORTD & 0xF0) | 0x0A;
		//OCR1B = ICR1 * 0.50;
		//_delay_ms(1000);
		
		
		// Resetting: Register
		TCCR1A = 0xA2;
		TCCR1B = 0x1A;
		ICR1 = 399;
	}	
}
