/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum Led_States{start,init,one,wait1,inc,two,wait2,three,wait3,four,wait4,five,wait5,six,wait6,reset} state;

 unsigned char but1 = 0x00;
//unsigned char but2 = 0x00;
//but1 = PINA & 0x01;
//unsigned char tmp = 0x00;
void fsm(){
	//unsigned char tmp = 0x00;
	but1 = ~PINA & 0x01;
	
	//but1 = ~PINA & 0x01;
	//but2 = ~PINA & 0x02;

	switch(state){
		case start:
		state = init;
		break;

		case init:
		state = one;
		break;

		case one:
		if(but1){
		state = inc;
		}
		else if(!but1){
		state = one;
		}
		break;

		case inc:
		state = wait1;
		break;

		case wait1:
		if(!but1){
		state = one;
		}
		else if (but1){
		state = wait1;
		}
		break;

		default:
		state = start;
			break;
	}
	switch(state){
		case start:
			break;
		case init:
			PORTB = 0x00;
			break;
		case one:
			break;
		case inc:
			PORTB = 0x05;
			break;

		case wait1:
			break;
		default:
			break;
	}
//	PORTB = tmp;
}

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF; // Configure port A's  pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	state = start;
	PORTB = 0x00;
    while (1) {
	fsm();

    }
}
