/*
 * IRSensor_Test.c
 *
 * Created: 2024-08-08 오후 4:47:43
 * Author : lordk
 * Solution :
 * 기존 나의 풀이 방법 : IR Sensor로부터 직접 값을 입력 받아 비교하기 -> 안 됨.
 * IR Sensor는 ADC 값과 연관 되어 있다는 사실을 알게 됨.
 * 1. IR Sensor의 ADC값을 받아와 작동 시키기.
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include "LCD_Text.h"

void Detecting(void);

int main(void) {
	
	DDRA = 0xFF;
	DDRF = 0x00; // Input Mode.
	
	ADMUX = 0x40;
	ADCSRA = 0x87;
	
	sei();
	
	lcdInit();
	lcdClear();
	
	while(1){
		
		unsigned int adcValue = 0;
		unsigned char channel = 0x00;
		
		ADMUX = 0x40 | channel;
		ADCSRA |= 0x40;
		
		while((ADCSRA&0x10) == 0){ // ADC의 Interrupt가 없을 때,
			adcValue = ADC;
			
			// <2번 기능>
			lcdNumber(1, 0, adcValue);	
		}
		
		_delay_ms(50);
		
		lcdClear();
	}
		
	
}