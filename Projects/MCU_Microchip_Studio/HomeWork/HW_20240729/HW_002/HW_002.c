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
#include <stdio.h>
#include "LCD_Text.h"

void Initializing_Register(void);
unsigned char Uart_Getch(void);
void Uart_Putch(unsigned char PutData);
void Uart_PutNum(unsigned int PutData);

int main(void) {
	
	int cntOutput = 0;
	
	Initializing_Register();
	
    while (1) {
				
		unsigned int adcValue = 0;
	    unsigned char channel = 0x00;
		
		ADMUX = 0x40 | channel;
		ADCSRA |= 0x40;
		
		while((ADCSRA&0x10) == 0) {
			adcValue = ADC;
		}
		
		// LCD: Show
		lcdClear();
		lcdString(0, 0, "ADC Value : ");
		lcdNumber(0, 12, adcValue);
		
		// UART Communication: to PC
		Uart_Putch('A');
		Uart_Putch('D');
		Uart_Putch('C');
		Uart_Putch(':');
		Uart_PutNum(adcValue);
		
		if(cntOutput == 20){
			Uart_Putch('\r'); // MS-DOS에서 개행은 캐리지 리턴 진행 후 -> 개행을 진행함.
			Uart_Putch('\n');
			cntOutput = 0;
		}else{
			Uart_Putch(' ');
			cntOutput++;
		}
		
		_delay_ms(500);
				
    }
}
void Initializing_Register(void){
	
	DDRA = 0xFF;
	DDRF = 0x00;
	DDRB = 0xFF;
	
	PORTA = 0xFF;
	PORTB = 0x00;
	
	ADMUX = 0x40;
	ADCSRA = 0x87;
	
	UBRR0L = 103;
	UBRR0H = 0;
	UCSR0A = 0x20;
	UCSR0B = 0x98;
	UCSR0C = 0x06;
	
	DDRE = 0x02;
	
	sei();
	
	lcdInit();
	lcdClear();
}


unsigned char Uart_Getch(void){
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void Uart_Putch(unsigned char PutData){
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = PutData;
}

void Uart_PutNum(unsigned int PutData){
	
	// 버퍼 확보하기.
    char bufferNum[10]; 
	
	// 숫자를 문자열로 변환하기.
    snprintf(bufferNum, sizeof(bufferNum), "%u", PutData); 
	
    // 숫자가 저장된 문자열 배열 bufferNum에 NULL 값이 없을 때까지 반복하기.
    for (char *ptr = bufferNum; *ptr != '\0'; ptr++) { 
        Uart_Putch(*ptr);
    }
}
