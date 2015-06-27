#include <msp430f2617.h>
#include "VirtualWire.h"
#include <stdint.h>
#define cycletime 0.000001L

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;			// Stop watchdog timer

	//P1DIR |= BIT0;						// Set P1.0 to output direction
	//TA0CCTL0 = CCIE;                    // CCR0 interrupt enabled
	//TA0CTL = TASSEL_2 + MC_1 + TACLR + TAIE + ID_3;    // SMCLK/8, upmode
	//TA0CCR0 =  0xffff;  					// 12.5 Hz
	vw_setup(1000);
	//vw_rx_start();
	//P1DIR |= BIT4;

	uint8_t count = 1;

	while(1) {
		char msg[7] = {'h','e','l','l','o',' ','#'};

		msg[6] = count;
		vw_send((uint8_t *)msg, 7);
		vw_wait_tx(); // Wait until the whole message is gone
		__delay_cycles(3/cycletime);
		count = count + 1;
	}

	/*while(1)
	{
	    uint8_t buf[VW_MAX_MESSAGE_LEN];
	    uint8_t buflen = VW_MAX_MESSAGE_LEN;

	    if (vw_get_message(buf, &buflen)) // Non-blocking
	    {
		//int i;

	        P1OUT |= BIT4; // Flash a light to show received good message
	        __delay_cycles(1/cycletime);
		// Message with a good checksum received, dump it.
		//Serial.print("Got: ");

		//for (i = 0; i < buflen; i++)
		//{
		//    Serial.print(buf[i], HEX);
		//    Serial.print(' ');
		//}
		//Serial.println();
	        P1OUT &= ~BIT4;
	    }
	}*/
}
