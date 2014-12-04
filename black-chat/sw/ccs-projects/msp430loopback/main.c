#include <msp430f2617.h>
#include "VirtualWire.h"
#include <stdint.h>
#define CLOCK_SPEED 1000000
#define CYCLE_TIME (1/CLOCK_SPEED)

char str[128];

void clock_setup();

void usci_uart_setup();

void read_line();

void send_line();

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;			// Stop watchdog timer

	clock_setup();

	usci_uart_setup();

	P5DIR |= BIT1;
	P5OUT &= ~BIT1;

	while(1) {
		read_line();
		send_line();
	}
}

void clock_setup() {
	BCSCTL1 |= XTS + DIVA_2;                    // Activate XT high freq xtal
	BCSCTL3 |= LFXT1S_2;               // 3 – 16MHz crystal or resonator

	uint16_t i;

	do {
		IFG1 &= ~OFIFG;                         // Clear OSCFault flag
		for (i = 0xFF; i > 0; i--);             // Time for flag to set
	} while (IFG1 & OFIFG);                     // OSCFault flag still set?

	BCSCTL2 |= SELM_3;                        // MCLK = XT HF XTAL (safe)
}

void usci_uart_setup() {
	P3SEL = 0x30;
	UCA0CTL1 |= UCSWRST;
	UCA0CTL1 |= UCSSEL_1;
	UCA0BR0 = 26;
	UCA0MCTL |= UCBRF_1 + UCOS16;
	UCA0CTL1 &= ~UCSWRST;
}

void read_line() {
	char* pstr = str;

	while( !(IFG2&UCA0RXIFG) );
	do {
		while( !(IFG2&UCA0RXIFG) );
		*pstr = UCA0RXBUF;
	} while( *pstr++ != '\n' );

	*pstr = '\0';
}

void send_line() {
	char* pstr = str;

	while( *pstr != '\0' ) {
		while( !(IFG2&UCA0TXIFG) );
		UCA0TXBUF = *pstr++;
	}
}
