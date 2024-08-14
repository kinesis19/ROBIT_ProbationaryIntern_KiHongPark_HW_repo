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
void Motor_Control_Mode1(void); // Basic 주행 모드.
void Motor_Control_Mode2(void); // 
void Motor_Control_Mode3(void); //
void Motor_Control_Mode4(void); //
void Motor_Moving_Forward(void);
void Motor_Moving_Backward(void);
void Motor_Turning_Left(void);
void Motor_Turning_Right(void);
void Motor_Moving_Stop(void);
void Motor_Adjusting_Center(void); // 중심 조정하는 함수.
int IRSensorCheckerAllBlack(void); // 모든 IR Sensor가 검은색인지 판별하여 return하는 함수.


unsigned int irSensorList[6] = {0, }; // IR Sensor의 ADC 값 저장 배열 선언하기.
unsigned int irSensorListMax[6] = {0, };
unsigned int irSensorListMin[6] = {1023, 1023, 1023, 1023, 1023, 1023};
double irSensorListNormalization[6] = {0, };
unsigned int stageFlag = 0; // 현재 stage를 나타내는 변수임. (1 ~ 10)
bool isStart = false;
int modeSelect = 0;

unsigned int psdSnesorList[2] = {0, };

// -----[Stage 관련 Variables]-----
int nowStageLevel = 0; // 현재 Stage Value를 나타냄.
int systemMode = 0; // 현재 mode를 나타냄. 0 : 초기 mode / 1 : 바코드 통과 및 Map2(stage-4 이전의 검정 구간 및 흰색 선)에 도착
bool isStage4End = false;
bool isBarCodeOn = false;


int main(void) {

	Initializing();
	stageFlag = 1;
	systemMode = 0;
	while (1) {
		if(isStart == true){
			// Detecting: IR Sensor.
			Detecting();
			if(modeSelect == 1){
				Motor_Control_Mode1();
			}else if(modeSelect == 2){
				Motor_Control_Mode2();
			}else if(modeSelect == 3){
				Motor_Control_Mode3();
			}else if(modeSelect == 4){
				Motor_Control_Mode4();
			}
		}
	}
}

ISR(INT0_vect){
	isStart = true;
	modeSelect = 1;
}


ISR(INT1_vect){
	isStart = true;
	modeSelect = 2;
}

ISR(INT2_vect){
	isStart = true;
	modeSelect = 3;
}

ISR(INT3_vect){
	isStart = true;
	modeSelect = 4;
}

void Initializing(void){
	// -----[Declare Register]-----
	DDRA = 0xFF;
	DDRB = 0x6F;  // PB1, PB2 핀을 출력으로 설정하기(OC1A, OC1B).
	
	PORTA = 0xFF;
	
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
	
	// PSD ADC값 저장하기.
	for(int i = 0; i < 2; i++){
		ADMUX = (ADMUX & 0xF0) | i;
		ADCSRA |= (1 << ADSC);
		
		while(!(ADCSRA & (1 << ADIF)));
		psdSnesorList[i] = ADC;
	}
	
	
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
	}
	
	//lcdNumber(0, 0, irSensorListNormalization[0]); // PF2 - IR2
	//lcdNumber(0, 4, irSensorListNormalization[1]); // PF3 - IR1
	//lcdNumber(0, 8, irSensorListNormalization[2]); // PF4 - IR0 // 가장 왼쪽 IR
	//lcdNumber(1, 0, irSensorListNormalization[3]); // PF5 - IR5 // 가장 오른쪽 IR
	//lcdNumber(1, 4, irSensorListNormalization[4]); // PF6 - IR4
	//lcdNumber(1, 8, irSensorListNormalization[5]); // PF7 - IR3
}
// 완성된 모드 기능
void Motor_Control_Mode1(void){
	
}

// 주행 실험 모드
void Motor_Control_Mode2(void){
	
}


void Motor_Control_Mode3(void){
	
	if(systemMode == 0){
		// -----[주행 기능]-----
		// -----[메인 주행 기능]-----
		if(irSensorListNormalization[3] < 50){
			Motor_Turning_Left();
			PORTA = 0b00111111;
		}else if(irSensorListNormalization[3] > 50){
			PORTA = 0b11111100;
			Motor_Turning_Right();
		}
		
		// -----[바코드 예외처리]-----
		if(irSensorListNormalization[0] < 50){ // IR2가 검은색에 가까울  때
			PORTA = 0b01111111;
			Motor_Turning_Left();
		}
		// 바코드에서 마지막 전체 흰 줄
		if(irSensorListNormalization[1] < 50 && irSensorListNormalization[2] < 50){
			PORTA = 0b01111111;
			for(int i = 0; i < 6; i++){
				PORTA = 0b10101010;
				Motor_Turning_Left();
				if((psdSnesorList[0] < 70 && 250 < psdSnesorList[1]) && IRSensorCheckerAllBlack() == 1){
					systemMode = 1;
				}
			}
		}
	}else if(systemMode == 1){
		Motor_Moving_Forward();
	}
	
}

// IR Sensor Normalization Value 찾기 모드.
void Motor_Control_Mode4(void){
	
	lcdNumber(0, 0, irSensorListNormalization[0]); // PF2 - IR2
	lcdNumber(0, 4, irSensorListNormalization[1]); // PF3 - IR1
	lcdNumber(0, 8, irSensorListNormalization[2]); // PF4 - IR0
	lcdNumber(1, 0, irSensorListNormalization[3]); // PF5 - IR5
	lcdNumber(1, 4, irSensorListNormalization[4]); // PF6 - IR4
	lcdNumber(1, 8, irSensorListNormalization[5]); // PF7 - IR3
	
	// PSD
	lcdNumber(0, 12, psdSnesorList[0]);
	lcdNumber(1, 12, psdSnesorList[1]);
	
	_delay_ms(100);
	
	lcdClear();
	
}

void Motor_Moving_Forward(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0.75;
	//PORTA = 0b00000000;
}

void Motor_Moving_Backward(void){
	PORTB = (PORTB & 0xF0) | 0x0A;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0.75;
	//PORTA = 0b11111111;
}

void Motor_Turning_Left(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0.75;
	OCR1B = ICR1 * 0;
	//PORTA = 0b00111111;
}

void Motor_Turning_Right(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0;
	OCR1B = ICR1 * 0.75;
	//PORTA = 0b11111100;
}

void Motor_Moving_Stop(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	OCR1A = ICR1 * 0;
	OCR1B = ICR1 * 0;
	//PORTA = 0b01011010;
}

int IRSensorCheckerAllBlack(void){
	
	if(((irSensorListNormalization[2] < 50 && irSensorListNormalization[1] < 50) && (irSensorListNormalization[0] < 50 && irSensorListNormalization[5] < 50)) && (irSensorListNormalization[4] < 50 && irSensorListNormalization[3] < 50)){
		return 1;
	}else{
		return 0;
	}
}