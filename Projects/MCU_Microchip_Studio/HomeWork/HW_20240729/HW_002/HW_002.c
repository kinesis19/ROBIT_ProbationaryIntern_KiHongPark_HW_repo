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
#include "LCD_Text.h"

//unsigned char data, receive;
//
//ISR(USART0_RX_vect){
	//receive = 1;
	//data = UDR0;
//}
//
//
//ISR(USART0_UDRE_vect){
	//if(receive == 1){
		//UDR0 = '_';
		//while((UCSR0A&0x20) == 0);
		//UDR0 = 'o';
		//while((UCSR0A&0x20 == 0));
		//UDR0 = 'k';
		//
		//receive = 0;
	//}
	//UCSR0B = 0x98;
//}


int main(void) {
	
	DDRA = 0xFF;
	DDRF = 0x00;
	DDRB = 0xFF;
	
	PORTA = 0xFF;
	PORTB = 0x00;
	
	ADMUX = 0x40;
	ADCSRA = 0x87;
	
	//UCSR0A = 0x00;
	//UCSR0B = 0x98;
	//UCSR0C = 0x06;
	//UBRR0H = 0x00;
	//UBRR0L = 0xCF;
	
	
	sei();
	
	lcdInit();
	lcdClear();
	
    while (1) {
		
		//if(data == 'y'){
			//PORTB = 0xFF;
			//UCSR0B = 0xB8;
		//}
		//if(data = 'n'){
			//PORTB = 0x00;
			//UCSR0B = 0xB8;
		//}
		
		unsigned int adcValue = 0;
	    unsigned char channel = 0x00;
		
		ADMUX = 0x40 | channel;
		ADCSRA |= 0x40;
		
		while((ADCSRA&0x10) == 0) {
			adcValue = ADC;
			
		}
		
		lcdClear();
		lcdString(0, 0, "ADC Value : ");
		lcdNumber(0, 12, adcValue);
		_delay_ms(100);
		
    }
}
