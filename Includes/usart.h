//USART header file for the Bluetooth Module HC-06 

#ifndef USART_H
#define USART_H

//USART Setup Values 
#define F_CPU 8000000UL 
#define BAUD_RATE 9600 
#define BAUD_PRESCALE ((F_CPU / (BAUD_RATE * 16UL)) - 1) 

#define UCSRB UCSR0B
#define RXEN RXEN0 
#define TXEN TXEN0 
#define UCSRB UCSR0B 

//#include <avr/io.h> 
#include <util/delay.h>

void usart_init() {
	
	//Turn on the reception circuitry 
	//Use 8-bit character sizes - URSEL bit set to select the UCRSC register 
	//Turn on the receiver and transmitter 
	UCSRB |= (1 << RXEN) | (1 << TXEN); 
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
	
	//LOad lower 8-bits of the baud rate value into the low byte
	UBRR0L = BAUD_PRESCALE; 
	
	//load upper 8-bits of the baud rate value into the high byte 
	UBRR0H = (BAUD_PRESCALE >> 8); 
}

//Functionality - as long as USART is ready to send data, it sets it to UDR 
unsigned usart_data_transmit(unsigned char data) {
	while (!(UCSR0A & (1 << UDRE0))) 
	; 
	UDR0 = data; 
	_delay_ms(1); 
}

//Functionality - return the received data the USART has 
unsigned usart_data_receive() {
	while (!(UCSR0A & (1 << RXC0)) ) 
	;
	return UDR0; 
}

void usart_string_transmit(char * string) {
	while (*string) {
		usart_data_transmit(*string++); 
	}
}

char *usart_string_receive(char *receive_string, unsigned char terminating_character) {
	unsigned char temp=0x00; 
	for (unsigned char i=0;;i++) {
		*(receive_string+i)=usart_data_receive(); 
		if(*(receive_string+i)==terminating_character) 
			break; 
		else 
		temp++; 
	}
	*(receive_string+temp)='\0'; 
	return receive_string; 
}
#endif 