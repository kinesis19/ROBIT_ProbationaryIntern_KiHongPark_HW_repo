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


unsigned int irSensorList[6] = {0, }; // IR Sensor의 ADC 값 저장 배열 선언하기.	
unsigned int irSensorListMax[6] = {0, };
unsigned int irSensorListMin[6] = {1023, 1023, 1023, 1023, 1023, 1023};
double irSensorListNormalization[6] = {0, };
	

int main(void) {
	// -----[Register Setting]-----
	DDRA = 0xFF; // LED Port를 Output Mode로 Setting하기.
	DDRF = 0x00; // IR Sensor가 할당되어 있는 PORTF를 Input Mode로 Setting하기.
	
	ADMUX = 0x40;
	ADCSRA = 0x87; // ADC Enable 및 Prescaler를 128로 Setting하기.
	
	sei();
	
	lcdInit();
	lcdClear();
	
	while(1){
		
		int idx = 2; // PF2번부터 ADC 값을 할당하기 위해 idx를 2로 초기화 하기.
		
		// IR Sensor0부터 ~ 5까지의 ADC값 저장하기.
		for(int i = 0; i < 6; i++){
			ADMUX = (ADMUX & 0xF0) | idx;
			ADCSRA |= (1 << ADSC); 
			while(!(ADCSRA & (1 << ADIF)));
			
			irSensorList[i] = ADC;
			
			//lcdNumber(1, 0, irSensorList[i]);
			idx++;
		}
		
		// IR Sensor의 MIN, MAX 할당하기.
		for(int i = 0; i < 6; i++){
			if(irSensorList[i] < irSensorListMin[i]){
				irSensorListMin[i] = irSensorList[i];
			}
			if(irSensorList[i] > irSensorListMax[i]){
				irSensorListMax[i] = irSensorList[i];
			}
		}
		
		
		for(int i = 0; i < 6; i++){
			
			irSensorListNormalization[i] = ((  (double)irSensorList[i] - irSensorListMin[i]) / (irSensorListMax[i] - irSensorListMin[i])) * 100;
			
			lcdNumber(0, 0, irSensorListNormalization[0]); // PF2 - IR2
			lcdNumber(0, 4, irSensorListNormalization[1]); // PF3 - IR1
			lcdNumber(0, 8, irSensorListNormalization[2]); // PF4 - IR0
			lcdNumber(1, 0, irSensorListNormalization[3]); // PF5 - IR5
			lcdNumber(1, 4, irSensorListNormalization[4]); // PF6 - IR4
			lcdNumber(1, 8, irSensorListNormalization[5]); // PF7 - IR3
			
			_delay_ms(500);
			
			lcdClear();
			
		}		
	}
}