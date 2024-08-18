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
int IRSensorCheckerAllWhite(void); // 모든 IR Sensor가 검은색인지 판별하여 return하는 함수.


unsigned int irSensorList[6] = {0, }; // IR Sensor의 ADC 값 저장 배열 선언하기.
unsigned int irSensorListMax[6] = {0, };
unsigned int irSensorListMin[6] = {1023, 1023, 1023, 1023, 1023, 1023};
double irSensorListNormalization[6] = {0, };
unsigned int stageFlag = 0; // 현재 stage를 나타내는 변수임. (1 ~ 10)
bool isStart = false;
int modeSelect = 0;

unsigned int psdSnesorList[2] = {0, };

// -----[Stage 관련 Variables]-----
unsigned int systemMode = 0; // 현재 mode를 나타냄. 0 : 초기 mode / 1 : 바코드 통과 및 Map2(stage-4 이전의 검정 구간 및 흰색 선)에 도착
unsigned int nowStage = 0;
bool isAbleTurnLeft = true;


// -----[Stage1 관련 Variables]-----
bool isStage1Start = false;

// -----[Stage3 관련 Variables]-----
bool isStage3Clear = false;


// -----[Stage4 관련 Variables]-----
bool isStage4Clear = false;


// -----[Stage5 관련 Variables]-----
bool isStage5Clear = false;

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
			}else if(modeSelect == 4){
				Motor_Moving_Stop();
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
	_delay_ms(1000);
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
	// -----[Map1일 때]-----
	if(systemMode == 0){
		if(irSensorListNormalization[0] < 50 && irSensorListNormalization[2] < 50){
			// -----[Stage3 to Stage4 Exception Handling ('ㄱ'자, Map 변경 처리)]-----
			if(psdSnesorList[1] > 200){ // stage-4의 벽이 가까이 있을 때
				Motor_Moving_Stop();
				_delay_ms(1000);
				Motor_Moving_Forward();
				_delay_ms(100);
				Motor_Turning_Left();
				_delay_ms(3000);
				Motor_Moving_Forward();
				_delay_ms(1500);
				systemMode = 1;
			}	
		}
		// -----[기본 주행 모드]-----
		if(irSensorListNormalization[0] > 50){
			PORTA = 0b11111100;
			Motor_Turning_Right();
		}else if(irSensorListNormalization[0] < 50){
			PORTA = 0b00111111;
			Motor_Turning_Left();
		}
	}else if(systemMode == 1){ // -----[Map2일 때]-----
		
		if(isStage4Clear == false){
			// -----[Stage4 Feature (벽 감지하기)]-----
			if(psdSnesorList[1] > 450){
				PORTA = 0b00001111;
				Motor_Turning_Left();
			}else if(psdSnesorList[1] < 450){
				PORTA = 0b11110000;
				Motor_Turning_Right();
			}
			// -----[Stage4 Exception Handling]-----
			// stage4에서 벽 감지하여 이동 중, 기다란 흰 막대를 만났을 때
			// Map2에서 흰색 : 20 이상, 검정 : 20 미만
			
			// Case #1: 전체 센서가 감지하기
			if(((irSensorListNormalization[2] > 20 && irSensorListNormalization[1] > 20) && (irSensorListNormalization[0] > 20 && irSensorListNormalization[5] > 20)) && (irSensorListNormalization[4] > 20 && irSensorListNormalization[3] > 20)){
				isStage4Clear = true;
			}
		}else if(isStage4Clear == true){
			
			// Case #2: 단일 센서가 감지하기
			if(irSensorListNormalization[0] > 20){
				Motor_Turning_Left();
			}else if(irSensorListNormalization[0] < 20){
				Motor_Turning_Right();
			}
			//if(irSensorListNormalization[0] > 20 && irSensorListNormalization[1] > 20){
				//PORTA = 0b00011111;
				//Motor_Turning_Left();
				//_delay_ms(1000);
			//}
			//if(irSensorListNormalization[0] > 20){
				//PORTA = 0x00;
				//Motor_Moving_Stop();
				//_delay_ms(1000);
				//Motor_Moving_Forward();
				//_delay_ms(1000);
			//}
		}
		
	}
	
}

// 주행 실험 모드
void Motor_Control_Mode2(void){
	
}


void Motor_Control_Mode3(void){
	
}

// IR Sensor Normalization Value 찾기 모드.
void Motor_Control_Mode4(void){
	
	// 로봇 위에서 봤을 때 기준 왼쪽부터 (IR0, IR1, IR2, IR3, IR4, IR5)
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
	OCR1A = ICR1 * 0.9;
	OCR1B = ICR1 * 0.875;
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
	//OCR1A = ICR1 * 0.75;
	//OCR1B = ICR1 * 0;
	OCR1A = ICR1 * 0.9;
	OCR1B = ICR1 * 0;
	
	//PORTA = 0b00111111;
}

void Motor_Turning_Right(void){
	PORTB = (PORTB & 0xF0) | 0x05;
	//OCR1A = ICR1 * 0;
	//OCR1B = ICR1 * 0.75;
	OCR1A = ICR1 * 0;
	OCR1B = ICR1 * 0.9;
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


int IRSensorCheckerAllWhite(void){
	
	if(((irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && (irSensorListNormalization[0] > 50 && irSensorListNormalization[5] > 50)) && (irSensorListNormalization[4] > 50 && irSensorListNormalization[3] > 50)){
		return 1;
	}else{
		return 0;
	}
}