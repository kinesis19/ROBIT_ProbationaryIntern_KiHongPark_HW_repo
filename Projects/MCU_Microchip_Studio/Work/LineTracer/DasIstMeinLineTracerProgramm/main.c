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
	// stage1 : 출발 및 S자 구간.
	if(stageFlag == 1){
		PORTA = 0b11111110;
		unsigned int cnt = 0;
		unsigned int cnt2 = 0;
		// 최초 start
		for(int i = 0; i < 6; i++){
			if(irSensorListNormalization[i] == 0){
				cnt++;
			}
		}
		if(cnt == 5){
			Motor_Moving_Forward();
		}		
		// 모두 흰색 일 때
		for(int i = 0; i < 6; i++){
			if(irSensorListNormalization[i] > 50){
				cnt2++;
			}
		}
		if(cnt2 == 5){
			stageFlag = 2;
			Motor_Moving_Forward();
			PORTA = 0x00;
			return;
		}
		
		
		if(!(irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && (irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
			Motor_Turning_Left();
		}
		
		if((irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && !(irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
			Motor_Turning_Right();
		}
	}else if(stageFlag == 2){
		PORTA = 0b11111101;
		unsigned int cnt = 0;
		// 모두 검은색 일 때
		for(int i = 0; i < 6; i++){
			if(irSensorListNormalization[i] < 50){
				cnt++;
			}
		}
		if(cnt == 0){
			Motor_Turning_Left();
		}
		
		if(!(irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && (irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
			Motor_Turning_Left();
		}
		
		if((irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && !(irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
			Motor_Turning_Right();
		}
		
	}
	
}

// 주행 실험 모드
void Motor_Control_Mode2(void){
	
	// stage-1
	if(stageFlag == 1){
		unsigned int cnt = 0;
		for(int i = 0; i < 6; i++){
			if(irSensorListNormalization[i] == 0){
				cnt++;
			}
		}
		if(cnt == 5){
			Motor_Moving_Forward();
		}
	}else if(stageFlag == 2){
		if(irSensorListNormalization[3] < 50 && irSensorListNormalization[4] < 50){
			Motor_Turning_Left();
		}
	}
	
	
	// 공통 기능
	// 직진 주행
	if((irSensorListNormalization[0] < 50 && irSensorListNormalization[5] < 50)){
		if((irSensorListNormalization[3] < 50 && irSensorListNormalization[4] < 50)){
			PORTA = 0b11110000;
			Motor_Turning_Right();
		}else if((irSensorListNormalization[1] < 50 && irSensorListNormalization[2] < 50)){
			PORTA = 0b00001111;
			Motor_Turning_Left();
		}else{
			PORTA = 0x00;
			Motor_Moving_Forward();	
			if(stageFlag == 1){
				stageFlag = 2;
			}
		}
	}
	PORTA = 0xFF;
		
	// 보조 주행
	if((irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && !(irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
		Motor_Turning_Right();
	}else if(!(irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && (irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
		Motor_Turning_Left();
	}
	
}


void Motor_Control_Mode3(void){
	
	unsigned int cnt = 0;
	for(int i = 0; i < 6; i++){
		if(irSensorListNormalization[i] == 0){
			cnt++;
		}
	} 
	if(cnt == 5){
		Motor_Moving_Forward();
	}else{
		
		// 직진 주행
		if((irSensorListNormalization[0] < 50 && irSensorListNormalization[5] < 50)){
			if((irSensorListNormalization[3] < 50 && irSensorListNormalization[4] < 50)){
				PORTA = 0b11110000;
				Motor_Turning_Right();
			}else if((irSensorListNormalization[1] < 50 && irSensorListNormalization[2] < 50)){
				PORTA = 0b00001111;
				Motor_Turning_Left();
			}else{
				PORTA = 0x00;
				Motor_Moving_Forward();	
			}
		}
		PORTA = 0xFF;
		
		// 보조 주행
		if((irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && !(irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
			Motor_Turning_Right();
		}else if(!(irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && (irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
			Motor_Turning_Left();
		}
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
	
	_delay_ms(500);
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

//void Motor_Adjusting_Center(void){
	//
	//while(1){
		//if((irSensorListNormalization[0] < 50 && irSensorListNormalization[5] < 50) && !((irSensorListNormalization[1] < 50 && irSensorListNormalization[2] < 50) && (irSensorListNormalization[3] < 50 && irSensorListNormalization[4] < 50))){
			//break;
		//}else{
			//if((irSensorListNormalization[2] < 50 && irSensorListNormalization[1] < 50) && !(irSensorListNormalization[3] > 50 && irSensorListNormalization[4] > 50)){
				//Motor_Turning_Left();
			//}else if(!(irSensorListNormalization[2] > 50 && irSensorListNormalization[1] > 50) && (irSensorListNormalization[3] < 50 && irSensorListNormalization[4] < 50)){
				//Motor_Turning_Right();
			//}
		//}
	//}
	//
//}