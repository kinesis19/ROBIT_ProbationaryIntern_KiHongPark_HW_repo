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
#include <stdbool.h>

#include "LCD_Text.h"

void Initializing(void);
void Detecting(void);
void Motor_Control(void);
void Motor_Moving_Forward(void);
void Motor_Moving_Backward(void);
void Motor_Turning_Left(void);
void Motor_Turning_Right(void);

unsigned int irSensorList[6] = {0, }; // IR Sensor의 ADC 값 저장 배열 선언하기.
unsigned int irSensorListMax[6] = {0, };
unsigned int irSensorListMin[6] = {1023, 1023, 1023, 1023, 1023, 1023};
double irSensorListNormalization[6] = {0, };
bool isStart = false;

int main(void) {

	Initializing();
	
	while (1) {
		if(isStart == true){
			// Detecting: IR Sensor.
			Detecting();
			Motor_Control();
			lcdClear();
		}
	}
}

ISR(INT0_vect){
	isStart = true;
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
		
		//_delay_ms(100);		
	}
}

void Motor_Control(void){
	
	unsigned int cnt = 0;
	for(int i = 0; i < 6; i++){
		if(irSensorListNormalization[i] == 0){
			cnt++;
		}
	}
	if(cnt == 5){
		Motor_Moving_Forward();
	}else{
		if((irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && !(irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
			Motor_Turning_Right();
			}else if(!(irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && (irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
			Motor_Turning_Left();
		}
	}
	
}

void Motor_Moving_Forward(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0.75;
}

void Motor_Moving_Backward(void){
	PORTB = (PORTB & 0xF0) | 0x0A;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0.75;
}

void Motor_Turning_Left(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0;
}

void Motor_Turning_Right(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0;
	OCR1B = ICR1 * 0.75;
}