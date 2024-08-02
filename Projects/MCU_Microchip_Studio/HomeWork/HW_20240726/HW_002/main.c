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
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD_Text.h"

int main(void){
	DDRA = 0xFF;
	DDRF = 0x00;
	
	PORTA = 0xFF;
	
	ADMUX = 0x40;
	ADCSRA = 0x87;
	//SREG = 0x80; // -> 에러 남.
	sei(); // SREG 대신 sei() 함수 사용함.
	
	lcdInit();
	lcdClear();
	
	int cnt = 0xFF;
	
	while(1){
		
		unsigned int adcValue = 0;
		unsigned char channel = 0x00;
		
		ADMUX = 0x40 | channel;
		ADCSRA |= 0x40;
		
		
		while((ADCSRA&0x10) == 0){
			adcValue = ADC;
			int adcValueVoltage = (5 / 1024) * adcValue;
			// <2번 기능>
			lcdNumber(1, 0, adcValue); 
			// <3번 기능>
			lcdNumber(1, 6, adcValueVoltage); // adcVaulue는 네 칸을 확보하므로, 가독성을 위해 한 칸 공백 후 6칸부터 전압을 표시함.
			_delay_ms(100); // lcd 초기화를 진행하여 값의 변화에 따라 ldc에 출력함.
			lcdClear();
			
			// <1번 기능>
			if(adcValue < (1023 / 8) * 1){
				PORTA = 0b11111110;
			}else if(adcValue < (1023 / 8) * 2){
				PORTA = 0b11111101;
			}else if(adcValue < (1023 / 8) * 3){
				PORTA = 0b11111011;
			}else if(adcValue < (1023 / 8) * 4){
				PORTA = 0b11110111;
			}else if(adcValue < (1023 / 8) * 5){
				PORTA = 0b11101111;
			}else if(adcValue < (1023 / 8) * 6){
				PORTA = 0b11011111;
			}else if(adcValue < (1023 / 8) * 7){
				PORTA = 0b10111111;
			}else if(adcValue < (1023 / 8) * 8){
				PORTA = 0b01111111;
			}
			
			
		}
		
		lcdString(0, 0, "19th_KH");
		
		_delay_ms(50);
	}
	
}

