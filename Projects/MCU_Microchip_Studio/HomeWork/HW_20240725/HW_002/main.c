/*
 * HW_002.c
 *
 * Created: 2024-07-30 오전 10:39:07
 * Author : lordk
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	DDRA = 0xFF;
	DDRD = 0x00;
	
	PORTA = 0x00;
	
	EIMSK = 0x01;
	EICRA = 0x02;
	
	sei();
	
	while (1) {
		
		
		if(!(PIND & (1 << PIND0))){
			if(!(PIND & (1 << PIND1))) { // 0, 1번 PD 동시 입력 받기.
				PORTA = 0x00;
			}else{
				PORTA = 0b00001111;
			}
		}else if(!(PIND & (1 << PIND1))){
			PORTA = 0b11110000;
		}else if(!(PIND & (1 << PIND2))){
			PORTA = 0b11111011;
			_delay_ms(500);
		}else if(!(PIND & (1 << PIND3))){
			PORTA = 0b11110111;
			_delay_ms(500);
		}else{
			PORTA = 0xFF;
			_delay_ms(500);
			PORTA = 0x00;
			_delay_ms(500);
		}
		
	}
}

ISR(INT1_vect){
	PORTA = ~PORTA;
}