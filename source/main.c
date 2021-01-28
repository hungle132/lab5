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

enum Led_States{start,init,one,wait1,inc,two,wait2,inc2,three,inc3,wait3,four,inc4,wait4,five,inc5,wait5,six,inc6,wait6,reset} state;

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
		state = two;
		}
		else if (but1){
		state = wait1;
		}
		break;
		



		case two:
		if(but1){
		state = inc2;
		}
		else if(!but1){
		state = two;
		}
		break;

		case inc2:
		state = wait2;
		break;

		case wait2:
		if(!but1){
		state = three;
		}
		else if (but1){
		state = wait2;
		}
		break;



		

		case three:
		if(but1){
		state = inc3;
		}
		else if(!but1){
		state = three;
		}
		break;

		case inc3:
		state = wait3;
		break;

		case wait3:
		if(!but1){
		state = three;
		}
		else if (but1){
		state = wait4;
		}
		break;

		


		


		case four:
		if(but1){
		state = inc4;
		}
		else if(!but1){
		state = four;
		}
		break;

		case inc4:
		state = wait4;
		break;

		case wait4:
		if(!but1){
		state = four;
		}
		else if (but1){
		state = wait4;
		}
		break;

/*

		case five:
		if(but1){
		state = inc5;
		}
		else if(!but1){
		state = five;
		}
		break;

		case inc5:
		state = wait5;
		break;

		case wait5:
		if(!but1){
		state = six;
		}
		else if (but1){
		state = wait5;
		}
		break;



		case six:
		if(but1){
		state = inc6;
		}
		else if(!but1){
		state = six;
		}
		break;

		case inc6:
		state = wait6;
		break;

		case wait6:
		if(!but1){
		state = six;
		}
		else if (but1){
		state = wait6;
		}
		break;



		*/






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
			PORTB = 0x01;
			break;

		case wait1:
			break;




		case two:
			break;
		case inc2:
			PORTB = 0x02;
			break;

		case wait2:
			break;


		case three:
			break;
		case inc3:
			PORTB = 0x04;
			break;

		case wait3:
			break;

		

		case four:
			break;
		case inc4:
			PORTB = 0x8;
			break;

		case wait4:
			break;
		
/*

		case five:
			break;
		case inc5:
			PORTB = 0x30;
			break;

		case wait5:
			break;


		case six:
			break;
		case inc6:
			PORTB = 0x31;
			break;

		case wait6:
			break;
*/

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
