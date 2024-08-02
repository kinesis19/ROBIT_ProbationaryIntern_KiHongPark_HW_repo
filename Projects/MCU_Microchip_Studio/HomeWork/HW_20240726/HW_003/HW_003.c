/*
 * HW_003.c
 *
 * Created: 2024-08-02 오후 12:58:44
 * Author : lordk
 * SRS:
 * 모든 SRS(명세서)는 과제보고서와 작업일지(개인)에 기록함.
 * • 덧셈, 뺄셈, 곱셈, 나눗셈이 가능한 계산기 만들어 값을 LCD에 띄운다. (ex. A + B = C의 형태)
 * ※ ‘A + B = C’ 의 값은 LCD의 1번째 줄에 다 띄울 수 있도록 한다.
 * 1. 첫번째 스위치를 누를 때마다 A의 값이 1씩 오른다. (초기값 A = 1)
 * 2. 두번째 스위치를 누를 때마다 산술 연산자가 바뀐다. (순서는 ‘+’ ‘-‘ ‘*’ ‘/’ 순)
 * 3. 세번째 스위치를 누를 때마다 B의 값이 1씩 오른다. (초기값 B = 1)
 * 4. 네번째 스위치를 누르면 연산을 하여 값을 LCD에 띄운다
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "LCD_Text.h"


int main(void) {
	
	// 레지스터 선언하기
	DDRD = 0x00; // 입력모드
	
	EIMSK = 0b00001111;
	EICRA = 0xFF; // 0b11111111와 동일함.
	
	// 변수 선언하기
	unsigned int numA = 1, numB = 1, numC = 0;
	unsigned int operator = 0;
	
	sei();
	
	lcdInit();	
	lcdClear();
	
	
    while (1) {
		if(!(PIND & (1 << PIND0))) {
			numA++;
			
			lcdString(0, 0, "NUM1");
			lcdNumber(1, 0, numA);
			
			_delay_ms(10000);
			
		}else if(!(PIND & (1 << PIND1))) {
			if(operator < 3){
				operator++;
			}else{
				operator--;
			}		
		
		}else if(!(PIND & (1 << PIND2))) {
			numB++;
			lcdString(0, 0, "NUM2");
			lcdNumber(1, 0, numB);
			
			_delay_ms(10000);
		}else if(!(PIND & (1 << PIND3))) {
			
			//char resultLine[16] = "";
			//char tempStr1[16] = "";
			//char tempStr2[16] = "";
			//char tempStr3[16] = "";
			//char tempStr4[16] = "";
			//char tempStr5[16] = "";
			//
			//if(operator == 0){
				//numC = numA + numB;
				//
				//sprintf(tempStr1, "%d", numA);
				//strcpy(tempStr2, "+");
				//sprintf(tempStr3, "%d", numB);
				//strcpy(tempStr4, "=");
				//sprintf(tempStr5, "%d", numC);
				//strcat(resultLine, tempStr1);
				//strcat(resultLine, tempStr2);
				//strcat(resultLine, tempStr3);
				//strcat(resultLine, tempStr4);
				//strcat(resultLine, tempStr5);
				//
			//}else if(operator == 1){
				//numC = numA - numB;
			//}else if(operator == 2){
				//numC = numA * numB;
			//}else if(operator == 3){
				//numC = numA / numB;
			//}
			
			//lcdString(0, 0, resultLine);
			lcdString(0, 0, "HEEEEEEEY!");
			lcdNumber(1, 0, numA);
		}
		
    }
	
}