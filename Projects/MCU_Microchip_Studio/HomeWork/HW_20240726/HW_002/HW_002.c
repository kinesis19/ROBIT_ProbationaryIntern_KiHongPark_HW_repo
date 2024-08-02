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
#include <math.h>
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
	
	while(1){
		
		unsigned int adcValue = 0;
		unsigned char channel = 0x00;
		
		ADMUX = 0x40 | channel;
		ADCSRA |= 0x40;
		
		
		while((ADCSRA&0x10) == 0){
			adcValue = ADC;
			/*
			* 전압 구하기.
			* 전압은 실수형으로 구해야 함. -> lcdNumber()는 3번째 파라미터로 정수 Type의 값을 받아 들임.
			* 실수로 구한 값을 문자열로 처리하여 lcdString()로 띄우면 될 것 같음.
			* 실수로 구한 값에 소수점을 파악하여 소수점 이하 n자리까지만 출력 되도록 구해야 할 듯.
			*/
			double adcValueVoltage = (5.0 / 1024) * adcValue; // 실수(double) Type의 voltage 구하기.
			char strVoltage[10] = "";
			int strIdx = 0;
			while (1){
				
				int num = floor(adcValueVoltage); // adcValueVoltage의 소수점 앞 부분.
				
				if(strIdx == 1){ // voltage의 최초값은 : 0V, 최대값은 5V임. 정수 앞 부분은 무조건 한 자리 밖에 못 와서 index의 수동 타겟팅하여 소수점을 표기함.
					strVoltage[strIdx] = 46; // "." 추가하기.
					adcValueVoltage = adcValueVoltage * 10;
					strIdx++;
					continue;
				}else if(strIdx == 4){ // 소수점 올리기.
					strVoltage[strIdx] = 86; // "V" 추가하기.
					break;
				}
				
				// 소수점 앞 부분이 10 이상일 때,
				if(num > 9){
					adcValueVoltage = adcValueVoltage / 10;
				}else{
					strVoltage[strIdx] = num + 48;
					adcValueVoltage = adcValueVoltage - num;
					adcValueVoltage = adcValueVoltage * 10;
					strIdx++;
				}
				
			}
			
			// <2번 기능>
			lcdNumber(1, 0, adcValue); 
			// <3번 기능>
			lcdString(1, 6, strVoltage); // adcVaulue는 네 칸을 확보하므로, 가독성을 위해 한 칸 공백 후 6칸부터 전압을 표시함.
			_delay_ms(100); // lcd 초기화를 진행하여 값의 변화에 따라 lcd에 출력함.
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

