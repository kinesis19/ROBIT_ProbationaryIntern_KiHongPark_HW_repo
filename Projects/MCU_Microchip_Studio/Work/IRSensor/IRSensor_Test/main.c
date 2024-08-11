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

unsigned int irSensorList[6] = {0, }; // IR Sensor의 ADC 값 저장 배열 선언하기.

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
			ADMUX = (ADMUX & 0xF0) | idx; // ADMUX = (0x00 & 0xF0) | idx => idx가 2일 때, ADMUX = 0x00 | 2 = ADMUX = 0b00000000 | 0b00000010 => ADMUX = 0b00000010이 됨.
			ADCSRA |= (1 << ADSC); // ADCSRA |= 0x40; -> (1 << ADSC)에서 ADSC는 Index6번째 비트를 담당함. 1 << ADSC) = 1 << 6 = 0b01000000.
			
			while(ADCSRA & (1 << ADIF)); // ADC가 return 될 때 까지 대기하기. Info) ADC 변환이 진행되면 ADSC는 1, 변환이 완료되면 0이 return되면서 while문을 탈출함.
			
			irSensorList[i] = ADC;
			
			//char label[4];
			//sprintf(label, "IR%d", i); // label에 몇 번째 IR Sensor인지 형식에 맞춰 저장하기.
			//lcdString(0, 0, label);
			//lcdNumber(1, 0, irSensorList[i]);
			//_delay_ms(500);
			lcdClear();
			
			idx++;
		}
		
		lcdNumber(0, 0, irSensorList[1]); // PF2
		lcdNumber(0, 4, irSensorList[2]); // PF3
		lcdNumber(0, 8, irSensorList[3]); // PF4
		lcdNumber(1, 0, irSensorList[4]); // PF5
		lcdNumber(1, 4, irSensorList[5]); // PF6
		lcdNumber(1, 8, irSensorList[0]); // PF7
		_delay_ms(100);
		
		
		// 저장된 IR Sensor0부터 ~ 5까지의 ADC값 출력하기
		//for(int j = 0; j < 6; j++){
			//char label[4];
			//sprintf(label, "IR%d", j); // label에 몇 번째 IR Sensor인지 형식에 맞춰 저장하기.
			//lcdString(0, 0, label);
			//lcdNumber(1, 0, irSensorList[j]);
			//_delay_ms(500);
			//lcdClear();
		//}
		
	}
}