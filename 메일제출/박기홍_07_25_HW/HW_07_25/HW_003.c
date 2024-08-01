/*
 * HW_003.c
 *
 * Created: 2024-07-31 오전 10:28:26
 * Author : lordk
 * SRS:
 * 모든 SRS(명세서)는 과제보고서와 작업일지(개인)에 기록함.
 * 1. 0.1s 마다 LED 2진 카운터
 * [Ext Interrupt]
 * 2. INT0 발생시 LED 3개씩 우측 이동 X 2
 * 3. INT1 발생시 LED 3개씩 좌측 이동 X 2
 * 4. INT2 발생시 LED1개 좌측 이동 후 우측 이동
 * 5. INT3 발생시 2진 카운터 초기화
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


// 전역 변수 선언하기 (interrupt와 main에서 공유하기 위함).
unsigned int cnt = 0xFF;

int main(void){
	// 레지스터 선언하기.
	DDRA = 0xFF;
	PORTA = 0xFF;
	
	
	EIMSK = 0b00001111;
	EICRA = 0b10101010;
	
	sei();
	
    while (1) {
		PORTA = cnt;
		cnt--;
		
		if(cnt < 0){ // Active-Low : 0000 0000 (led가 모두 켜졌을 떄,)
			cnt = 0xFF; // 1111 1111(led 모두 끄기)
			PORTA = 0xFF;
			_delay_ms(100);
		}
		
		_delay_ms(100);
		
    }
}

// <기능2>
ISR(INT0_vect){
	
	PORTA = 0b11111000;
	_delay_ms(500);
	PORTA = 0b11110001;
	_delay_ms(500);
	PORTA = 0b11100011;
	_delay_ms(500);
	PORTA = 0b11000111;
	_delay_ms(500);
	PORTA = 0b10001111;
	_delay_ms(500);
	PORTA = 0b00011111;
	_delay_ms(500);
	PORTA = 0b00111110;
	_delay_ms(500);
	PORTA = 0b01111100;
	_delay_ms(500);
	PORTA = 0b11111000;
	_delay_ms(500);
	PORTA = 0b11110001;
	_delay_ms(500);
	PORTA = 0b11100011;
	_delay_ms(500);
	
}


// <기능3> : INT1 발생시 LED 3개씩 좌측 이동 X 2
ISR(INT1_vect){
	PORTA = 0b00011111;
	_delay_ms(500);
	PORTA = 0b10001111;
	_delay_ms(500);
	PORTA = 0b11000111;
	_delay_ms(500);
	PORTA = 0b11100011;
	_delay_ms(500);
	PORTA = 0b11110001;
	_delay_ms(500);
	PORTA = 0b11111000;
	_delay_ms(500);
	PORTA = 0b01111100;
	_delay_ms(500);
	PORTA = 0b00111110;
	_delay_ms(500);
	PORTA = 0b00011111;
	_delay_ms(500);
	PORTA = 0b10001111;
	_delay_ms(500);
	PORTA = 0b11000111;
	_delay_ms(500);
}

// <기능4> : INT2 발생시 LED1개 좌측 이동 후 우측 이동
ISR(INT2_vect){
	
	int tempPORTA = PORTA;
	
	// 우측 이동하기.
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
	
	// 좌측 이동하기.

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

// <기능 5> : 2진 카운터 초기화 하기.
ISR(INT3_vect){
	cnt = 0xFF; // 1111 1111(led 모두 끄기)
	unsigned int cnt = 0xFF; // 1111 1111(led 모두 끄기)
	PORTA = 0xFF;
	_delay_ms(100);
}