/*
 * HW_002.c
 *
 * Created: 2024-08-04 오후 8:48:38
 * Author : lordk
 *  SRS:
 * 모든 SRS(명세서)는 과제보고서와 작업일지(개인)에 기록함.
 * 1. 가변저항 값 LCD 첫번째 줄에 표시.
 * 2. 가변저항 값 PC에 전송.
 * 3. PC에서 전송 받은 값에 따라 LED 켜기.
 * 4. PC에서 전송 받은 값 LCD 두 번째 줄에 표시.
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include "LCD_Text.h"

int main(void) {
	
    while (1) {
		
    }
}

