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
void Motor_Adjusting_Center(void); // 중심 조정하는 함수.

unsigned int irSensorList[6] = {0, }; // IR Sensor의 ADC 값 저장 배열 선언하기.
unsigned int irSensorListMax[6] = {0, };
unsigned int irSensorListMin[6] = {1023, 1023, 1023, 1023, 1023, 1023};
double irSensorListNormalization[6] = {0, };
unsigned int stageFlag = 0; // 현재 stage를 나타내는 변수임. (1 ~ 10)
bool isStart = false;
int modeSelect = 0;

// -----[Stage 관련 Variables]-----
bool isFirstMove = false; // 출발점에서 움직였을 때의 처리를 위한 변수. false: 초기 주행 처리, true: 초기 주행 처리 감지X
unsigned int stage2Cnt = 0; // stage2 예외처리 위한 변수(Motor Control 관련)

unsigned int moveForwardCnt = 0; // 직진 이동 cnt.
unsigned int turnRightCnt = 0; // 우회전 이동 cnt. // IR2, IR3, IR4, IR5 감지 시.


int main(void) {

	Initializing();
	stageFlag = 1;
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
	
	lcdNumber(0, 0, irSensorListNormalization[0]); // PF2 - IR2
	lcdNumber(0, 4, irSensorListNormalization[1]); // PF3 - IR1
	lcdNumber(0, 8, irSensorListNormalization[2]); // PF4 - IR0
	lcdNumber(1, 0, irSensorListNormalization[3]); // PF5 - IR5
	lcdNumber(1, 4, irSensorListNormalization[4]); // PF6 - IR4
	lcdNumber(1, 8, irSensorListNormalization[5]); // PF7 - IR3
	//
	//_delay_ms(10);
	//lcdClear();
}
// 완성된 모드 기능
void Motor_Control_Mode1(void){
	
}

// 주행 실험 모드
void Motor_Control_Mode2(void){
		
}


void Motor_Control_Mode3(void){
	// -----[stage 선행 예외처리]-----
	// stage-1: 출발부터 ~ stage-2: 8자 이전까지
	if(stageFlag == 1 && isFirstMove == false){
		unsigned int cnt = 0;
		// stage-1: 시작 지점 상태일 때,
		for(int i = 0; i < 6; i++){
			if(irSensorListNormalization[i] == 0){
				cnt++;
			}
		}
		if(cnt == 5){
			isFirstMove = true;
			Motor_Moving_Forward();
		}
	}else if(stageFlag == 2){ // stage-2: 8자부터 ~ stage-3: 바코드 이전까지
		// 예외 처리 1: 아래 'O'에서 위에 'O'로 가기 위한 예외 처리.
		if(turnRightCnt == 1){
			PORTA = 0b11111110;
			Motor_Turning_Left();
			stage2Cnt = 1;
		}
		
		// 예외처리 2: 'ㅅ'자 위 꼭짓점에서 아래로 회전하는 예외처리.
		if(((irSensorListNormalization[3] < 50 && irSensorListNormalization[5] < 50) || (irSensorListNormalization[4] < 50 && irSensorListNormalization[5] < 50))){
			if(stageFlag == 2){
				PORTA = 0b11111000;
				Motor_Turning_Right();
			}
		}
	}
	
	/* 직진 주행으로 stage-2를 감지했었는데, 그게 stage-2 예외처리를 방해하는 문제로 판단 됨.
	*
	*/
	// -----[주행 기능]-----
		
	// -----[메인 주행 기능]-----
	if((irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && !(irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
		Motor_Turning_Right();
		PORTA = 0b11111100;
	}else if(!(irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && (irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
		Motor_Turning_Left();
		PORTA = 0b00111111;
	}
	
	/* 직진 감지해서 stage 처리하면 절대 안 됨.
	*
	*/
	
	// -----[직진 주행 기능(직진, 직진 중 우회전, 직진 중 좌회전]-----
	if((irSensorListNormalization[0] < 50 && irSensorListNormalization[5] < 50)){ // 직진 감지
		if((irSensorListNormalization[3] < 50 && irSensorListNormalization[4] < 50) && isFirstMove == true){ // 직진 중 우회전 감지
			PORTA = 0b11110000;
			Motor_Turning_Right();		
			
			if(stageFlag == 1){
				turnRightCnt = 1;
			}else if(stageFlag == 2){
				turnRightCnt = 2;
				Motor_Turning_Left();
			}
		}else if((irSensorListNormalization[1] < 50 && irSensorListNormalization[2] < 50)){ // 직진 중 좌회전 감지
			PORTA = 0b00001111;
			Motor_Turning_Left();
		}else{ // 직진 처리
			PORTA = 0x00;
			Motor_Moving_Forward();	
			if(stageFlag == 1 && turnRightCnt == 1){ // 8자 바로 이전에 stageFlag를 2로 설정하기.
				stageFlag = 2;
			}else if(stageFlag == 2){
				
			}
		}
	}
	
}

// IR Sensor Normalization Value 찾기 모드.
void Motor_Control_Mode4(void){
	
	
	lcdNumber(0, 0, stageFlag);
	lcdNumber(0, 4, stage2Cnt);
	lcdNumber(1, 0, turnRightCnt);
	//lcdNumber(0, 0, irSensorListNormalization[0]); // PF2 - IR2
	//lcdNumber(0, 4, irSensorListNormalization[1]); // PF3 - IR1
	//lcdNumber(0, 8, irSensorListNormalization[2]); // PF4 - IR0
	//lcdNumber(1, 0, irSensorListNormalization[3]); // PF5 - IR5
	//lcdNumber(1, 4, irSensorListNormalization[4]); // PF6 - IR4
	//lcdNumber(1, 8, irSensorListNormalization[5]); // PF7 - IR3
	
	lcdClear();
	
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