/*
 * HW_002.c
 *
 * Created: 2024-07-30 오전 10:39:07
 * Author : lordk
 * SRS:
 * 모든 SRS(명세서)는 과제보고서와 작업일지(개인)에 기록함.
 * 1. 0.5s 마다 모든 LED 깜빡이기. _delay_ms() 함수를 사용할 것.
 * [No Ext Interrupt]
 * 2. SW1이 눌리면 4~7 LED 켜기
 * 3. SW2이 눌리면 0~3 LED 켜기
 * 4. 둘 다 눌리면 모두 켜기
 * [Ext Interrupt]
 * 5. INT3 발생시 LED 좌측 이동
 * 6. INT4 발생시 LED 좌측 이동
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	DDRA = 0xFF;
	DDRD = 0x00;
	
	PORTA = 0x00;
	
	EIMSK = 0b00001100;
	EICRA = 0b10100000;
	
	sei();
	
	while (1) {
		
		// 스위치 0번 입력 시,
		if(!(PIND & (1 << PIND0))){
			if(!(PIND & (1 << PIND1))) { // <기능4> : 스위치 0번, 1번 동시에 입력 받을 시,
				/* AVR에서 동시 입력은 없음.
				* 항상 우선으로 입력 받는 키가 있음.
				* 우선키 -> 후발키 순으로 입력 받음(회로 원리)
				* 즉, 0번과 1번을 동시에 입력하는 기능은 Unity Engine이나 Android Studio 같은 SW 개발 엔진에만 있고,
				* AVR 개발을 위한 Microchip(Atmel) Studio에서는 회로 원리에 의해 첫 번째 입력 받은 값이 흐르고 
				* -> 그 뒤에 입력 받은 값이 흐른다는 것을 알게 됨.
				* 이번 케이스에서는 PD0과 PD1의 동시 입력을 원하는데, PD0이 PD1보다 우선으로 입력 받게 설정되어 있으므로
				* PD0의 세부 조건으로 PD1이 입력 받았을 때를 감지하여 동시 입력 처리를 진행해 주면 됨.
				*/
				PORTA = 0x00;
			}else{ // <기능2> : 스위치 0번 단독 입력 시,
				PORTA = 0b00001111;
			}
		}else if(!(PIND & (1 << PIND1))){ // <기능3> : 스위치 1번 단독 입력 시,
			PORTA = 0b11110000;
		}else{ // <기능1> : 깜빡임 반복하기.
			PORTA = 0xFF;
			_delay_ms(500);
			PORTA = 0x00;
			_delay_ms(500);
		}
		
	}
}

// <기능5> : LED 좌측으로 이동하기.
ISR(INT2_vect){
	PORTA = 0b11111110;
	_delay_ms(100);
	PORTA = 0b11111101;
	_delay_ms(100);
	PORTA = 0b11111011;
	_delay_ms(100);
	PORTA = 0b11110111;
	_delay_ms(100);
	PORTA = 0b11101111;
	_delay_ms(100);
	PORTA = 0b11011111;
	_delay_ms(100);
	PORTA = 0b10111111;
	_delay_ms(100);
	PORTA = 0b01111111;
	_delay_ms(100);
}

// <기능6> : LED 우측으로 이동하기.
ISR(INT3_vect){
	PORTA = 0b01111111;
	_delay_ms(100);
	PORTA = 0b10111111;
	_delay_ms(100);
	PORTA = 0b11011111;
	_delay_ms(100);
	PORTA = 0b11101111;
	_delay_ms(100);
	PORTA = 0b11110111;
	_delay_ms(100);
	PORTA = 0b11111011;
	_delay_ms(100);
	PORTA = 0b11111101;
	_delay_ms(100);
	PORTA = 0b11111110;
	_delay_ms(100);
}