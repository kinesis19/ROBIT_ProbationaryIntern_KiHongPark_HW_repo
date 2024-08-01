/*
 * HW_002.c
 *
 * Created: 2024-08-01 오후 2:50:31
 * Author : lordk
 * SRS:
 * 모든 SRS(명세서)는 과제보고서와 작업일지(개인)에 기록함.
 * 1. 가변 저항 값에 따라 LED를 이동시킨다.
 * 2. ADC값을 LCD에 띄우기.
 * 3. ADC값을 계산해서 현재 가변저항의 전압 값을 LCD에 표시.
 * 4. 이름 이니셜 표기할 것.
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include "LCD_Text.h"
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void){
	DDRA = 0xFF;
	
	DDRF = 0x00;
	ADMUX = 0x40;
	ADCSRA = 0x87;
	SREG = 0x80;
	
	lcdInit();
	lcdClear();
	
	int cnt = 0xFF;
	
	while(1){
		
		//unsigned int adcValue = 0;
		//unsigned char channel = 0x00;
		//
		//ADMUX = 0x40 | channel;
		//ADCSRA |= 0x40;
		//
		//while(ADCSRA&0x10 == 0){
			//adcValue = ADC;
			////lcdNumber(1, 0, adcValue);
		//}
		//
		//lcdString(0, 0, "19th_KH");
		//lcdNumber(1, 0, adcValue);
		//
		//_delay_ms(100);
		//
		//
		
		
	}
	
}

