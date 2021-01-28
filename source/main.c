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

enum Led_States{start,init,one,wait1,two,wait2,three,wait3,four,wait4,five,wait5,six,wait6,reset} states;

 unsigned char but1 = 0x00;
//unsigned char but2 = 0x00;
//but1 = PINA & 0x01;
void fsm(){
	but1 = ~PINA & 0x01;
	//but1 = ~PINA & 0x01;
	//but2 = ~PINA & 0x02;

	switch(states){
		case start:

		states = init;
		case init:

		states = one;
		break;

		case one:
		if (!but1){
		states = one;
		}
		else
		states = one;
		break;

		case wait1:
		//if (!but1)
		//states = wait1;
		 states = two;
		break;

		case two:
		if(but1){
		states = wait2;
		}
		else
		states = two;

		break;

		case wait2:
		if (but1){
		states = wait2;
		}
		else
		states = three;
		break;

		case three:
		if(but1)
		states = wait3;
		else
		states = three;
		break;

		case wait3:
		if(!but1)
		states = wait3;
		else
		states = four;
		break;

		case four:
		if(but1){
		states = wait4;
					}
		else
		states = four;
		break;

		case wait4:
		if(!but1){
		states = wait4;
		}
		states = five;
		break;

		case five:
		if(but1){
		states = wait5;
		}
		else
		states = five;
		break;
		case wait5:
		if(!but1){
		states = wait5;
		}
		else 
		states = six;
		break;

		case six:
		if (but1){
		states = wait6;
		}
		else{
		states = six;
		}
		break;
		case wait6:
		if(!but1){

		states = reset;
		}
		else{
		states = wait6;
		}
		break;
		case reset:
		if (but1)
		states = init;
		else
		states = reset;
		break;
	}
	switch(states){
		case start:
			PORTB = 0;
			break;
		case init:
			PORTB = 0x00;
		break;
		case one:
			PORTB = 0x01;
		break;
		case wait1:
			//PORTB = 0x01;
		break;
		case two:
		break;
		case wait2:
		//	PORTB = 0x03;
		break;
		case three:
		break;
		case wait3:
			PORTB = 0x07;
			break;
		case four:
			break;
		case wait4:
			PORTB = 0x15;
			break;
		case five:
			break;

		case wait5:
			PORTB = 0x1F;
			break;
		case six:
			break;
		case wait6:
			PORTB = 0x63;
			break;
		case reset:
			break;
	}
	

	

}

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF; // Configure port A's  pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	states = init;
	PORTB = 0x00;
    while (1) {
	fsm();
    }
    return 1;
}
