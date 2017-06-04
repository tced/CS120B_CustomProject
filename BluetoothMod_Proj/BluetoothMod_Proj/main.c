/*
 * BluetoothMod_Proj.c
 *
 * Created: 6/3/2017 2:20:14 PM
 * Author : Tiffany
 */ 


#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for all AVR microcontrollers*/

#define	F_CPU	8000000
/*Defines a macro for the delay.h header file. F_CPU is the microcontroller frequency value for the delay.h header file. Default value of F_CPU in delay.h header file is 1000000(1MHz)*/

#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

#include "hc06.h"
/*Includes hc06.h header file which defines different functions for HC-06 Bluetooth Module. HC-06 header file version is 1.1*/


int main(void)
{
	_delay_ms(500);
	_delay_ms(500);
	/*Delay of 1s*/
	
	usart_init();
	/*USART initialization*/
	
	hc_06_bluetooth_transmit_string("ABLab Solutions");
	/*Transmits a string to Bluetooth Module*/

	hc_06_bluetooth_transmit_byte(0x0d);
	/*Transmits Carriage return to Bluetooth Module*/
	
	hc_06_bluetooth_transmit_byte(0x0a);
	/*Transmits New Line to Bluetooth Module for new line*/

	hc_06_bluetooth_transmit_string("Bluetooth has transmitted");
	/*Transmits a string to Bluetooth Module*/

	hc_06_bluetooth_transmit_byte(0x0d);
	/*Transmits Carriage return to Bluetooth Module*/
	
	hc_06_bluetooth_transmit_byte(0x0a);
	/*Transmits New Line to Bluetooth Module for new line*/
}
/*End of program*/

