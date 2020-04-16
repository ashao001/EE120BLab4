/*	Author: ashao001
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

enum States {Start, Press, Hold, Off, On} state;
void Tick() {
	unsigned char button = PINA & 0x01;
	switch(state) { // Transitions
    		case Start:    
			state = Press;
			break;
    		case Press:    
			if(button){
				state = Hold;

			}
			else{
				state = Press;
		
			}
			break;
		
    		case Hold:    
			if(!button){
				state = Off;
 
			}
			else{
				state = Hold;
			}
			break;
		
		case Off:
			if(button){
				state = On;
			}
			else{
				state = Off;
			}
			break;
		
		case On:                                                                                                                                                                                                                  if(!button){
                                state = Press;                                                                                                                                                                                                }
                        else{
                                state = On;                                                                                                                                                                                               }
                        break;
    		default:    
			state = Start; 
			break;
    }; // Transitions

	switch(state) { // State actions
       		case Start:    
			break;
    		case Press:    
			PORTB = 0x01; 
			break;	
    		case Hold:    
			PORTB = 0x02;
			break;
		case Off:
			PORTB = 0x02;
			break;
		case On:
			PORTB = 0x01;
			break;
    		default:    
			break;
       }; // State actions
}

int main(void) {
    /* Insert DDR and PORT initializations */
	state = Start;
    /* Insert your solution below */
    while (1) {
	PORTB = 0x00;
	Tick();
    }
    return 1;
}
