/*
 * DasIstMeinLineTracerProgramm.c
 *
 * Created: 2024-08-11 오후 8:47:59
 * Author : lordk
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <util/delay.h>

#include "LCD_Text.h"

void Initializing(void);
void Detecting(void);
void Motor_Control(void);
void Motor_Moving_Forward(void);
void Motor_Moving_Backward(void);
void Motor_Turning_Left(void);
void Motor_Turning_Right(void);

unsigned int irSensorList[6] = {0, }; // IR Sensor의 ADC 값 저장 배열 선언하기.

int main(void) {

	Initializing();
	
	while (1) {
		// Detecting: IR Sensor.
		Detecting();	
		Motor_Control();
		_delay_ms(100);
		lcdClear();
	}
}

void Initializing(void){
	// -----[Declare Register]-----
	DDRB = 0x6F;  // PB1, PB2 핀을 출력으로 설정하기(OC1A, OC1B).
	
	EIMSK = 0b00001111;
	EICRA = 0b10101010;
	
	TCCR1A = 0xA2; // 0b10100010
	TCCR1B = 0x1A; // 0b00011010
	TCCR1C = 0x00; // 0b00000000
	
	ICR1 = 399;
	TCNT1 = 0x00;
	
	ADMUX = 0x40;
	ADCSRA = 0x87; // ADC Enable 및 Prescaler를 128로 Setting하기.
	
	sei();
	
	lcdInit();
	lcdClear();
}

void Detecting(void){
	int idx = 2; // PF2번부터 ADC 값을 할당하기 위해 idx를 2로 초기화 하기.
	
	// IR Sensor0부터 ~ 5까지의 ADC값 저장하기.
	for(int i = 0; i < 6; i++){
		ADMUX = (ADMUX & 0xF0) | idx; // ADMUX = (0x00 & 0xF0) | idx => idx가 2일 때, ADMUX = 0x00 | 2 = ADMUX = 0b00000000 | 0b00000010 => ADMUX = 0b00000010이 됨.
		ADCSRA |= (1 << ADSC); // ADCSRA |= 0x40; -> (1 << ADSC)에서 ADSC는 Index6번째 비트를 담당함. 1 << ADSC) = 1 << 6 = 0b01000000.
		
		while(ADCSRA & (1 << ADSC)); // ADC가 return 될 때 까지 대기하기. Info) ADC 변환이 진행되면 ADSC는 1, 변환이 완료되면 0이 return되면서 while문을 탈출함.
		
		irSensorList[i] = ADC;
				
		idx++;
	}
	
	lcdNumber(0, 0, irSensorList[0]);
	lcdNumber(0, 4, irSensorList[1]);
	lcdNumber(0, 8, irSensorList[2]);
	lcdNumber(1, 0, irSensorList[3]);
	lcdNumber(1, 4, irSensorList[4]);
	lcdNumber(1, 8, irSensorList[5]);
}

void Motor_Control(void){
	// 가중치 : +30
	if(((irSensorList[0] < 162 && irSensorList[5] < 178) && (irSensorList[1] < 300 && irSensorList[2] < 284)) && (irSensorList[3] < 150 && irSensorList[4] < 144)){
		Motor_Moving_Forward();
	}else if(irSensorList[0] > 265){ // 가중치 : -30
		Motor_Turning_Right();
	}else if(irSensorList[5] > 218){ // 가중치 : -30
		Motor_Turning_Left();
	}
	
}

void Motor_Moving_Forward(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0.75;
	_delay_ms(500);
}

void Motor_Moving_Backward(void){
	PORTB = (PORTB & 0xF0) | 0x0A;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0.75;
	_delay_ms(500);
}

void Motor_Turning_Left(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0;
	_delay_ms(500);
}

void Motor_Turning_Right(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0;
	OCR1B = ICR1 * 0.75;
	_delay_ms(500);
}