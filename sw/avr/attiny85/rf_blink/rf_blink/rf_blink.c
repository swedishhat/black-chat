/*
 * rf_blink.c
 *
 * Created: 10/23/2014 11:41:08 PM
 *  Author: Jimbo
 */
 
/* Macro function to declare an output pin */
#define out(x)			_out(x)
#define _out(bit,port)	DDR##port |= (1 << bit)

/* Macro function to declare an input pin */
#define in(x)			_in(x)
#define _in(bit,port)	DDR##port &= ~(1 << bit)

/* Macro function to set an output pin high */
#define on(x)			_on(x)
#define _on(bit,port)	PORT##port |= (1 << bit)

/* Macro function to set an output pin low */
#define off(x)			_off(x)
#define _off(bit,port)	PORT##port &= ~(1 << bit)

/* Macro function to toggle an output pin */
#define flip(x)			_flip(x)
#define _flip(bit,port)	PORT##port ^= (1 << bit)

/* Macro function to set internal pullup resistor of input pin (same as "on" macro)*/
#define pullup(x)		_on(x)

/* Macro function to get state of input pin */
#define get(x)			_get(x)
#define _get(bit,port)	(PIN##port & (1 << bit))

#define F_CPU 8000000UL

//#include "macros.h"
#include <avr/io.h>
#include <util/delay.h>

void tick(char ticks){
	while (ticks>0){
		_delay_us(100);
		ticks--;
	}
}

void pulse(char ticks){
	PORTB=0x3F;
	tick(ticks);
	PORTB=0;
	tick(ticks);
}

void send_sync(){
	char i;
	for (i=0;i<10;i++){
		pulse(1);
		pulse(2);
		pulse(3);
	}
	pulse(3);
}

void send_lose(){
	char i;
	for (i=0;i<5;i++){
		pulse(3);
	}
}

void sendByte(int val){
	// TODO - make faster by only sending needed bytes
	char i;
	for (i=0;i<8;i++){
		if ((val>>i)&1){pulse(2);}
		else{pulse(1);}
	}
}

void send(int val){
	sendByte(val);  // regular
	sendByte(~val); // inverted
	pulse(3);
}

int main (void){
	
	DDRB = 0x3F;
	int i;

	while(1) {
		send_sync();
		for (i=0;i<200;i++){
			send(i);
		}
		send_lose();
	}
	
}