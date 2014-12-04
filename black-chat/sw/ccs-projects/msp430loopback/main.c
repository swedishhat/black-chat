#include <msp430f2617.h>
#include "VirtualWire.h"
#include <stdint.h>

char outgoing[28];

char incoming[28];

uint8_t ack[1] = { 6 };

uint8_t ready_to_tx = false;

void clock_setup();

void usci_uart_setup();

void read_line(char* str);

void send_line(char* str);

uint8_t get_length(char* str);

void null_terminate(char* str, uint8_t length);

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;			// Stop watchdog timer

	//P5DIR |= BIT1;

	clock_setup();

	usci_uart_setup();

	vw_setup(1000);

	vw_set_ptt_inverted(true);

	__bis_SR_register(GIE);

	vw_rx_start();

	while(1) {
		if( vw_have_message() ) {
			vw_rx_stop();
			__delay_cycles(100000);
			vw_send(ack,1);
			uint8_t length = 27;
			vw_get_message(incoming, &length);
			null_terminate(incoming, length);
			send_line(incoming);
			vw_rx_start();
		} else if( ready_to_tx == true ) {
			vw_rx_stop();
			ready_to_tx = false;
			uint16_t length = get_length(outgoing);
			do {
				vw_rx_stop();
				vw_send(outgoing, length);
				vw_wait_tx();
				vw_rx_start();
			} while( !vw_wait_rx_max(400) );
			vw_get_message(incoming, &length);
			vw_rx_start();
		}
	}
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void) {
	//__bis_SR_register(GIE);

	char* pstr = outgoing;

	do {
		while( !(IFG2&UCA0RXIFG) );
		*pstr = UCA0RXBUF;
	} while( *pstr++ != '\n' );

	*pstr = '\0';

	ready_to_tx = true;
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
	IE2 |= UCA0RXIE;
}

void read_line(char* str) {
	char* pstr = str;

	while( !(IFG2&UCA0RXIFG) );
	do {
		while( !(IFG2&UCA0RXIFG) );
		*pstr = UCA0RXBUF;
	} while( *pstr++ != '\n' );

	*pstr = '\0';
}

void send_line(char* str) {
	char* pstr = str;

	while( *pstr != '\0' ) {
		while( !(IFG2&UCA0TXIFG) );
		UCA0TXBUF = *pstr++;
	}
}

uint8_t get_length(char* str) {
	char* pstr = str;
	uint8_t length = 0;

	while( *pstr++ != '\0' )
		++length;

	return length;
}

void null_terminate(char* str, uint8_t length) {
	char* ptr = str + length;
	*ptr = '\0';
}
