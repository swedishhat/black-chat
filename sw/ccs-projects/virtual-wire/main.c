#include <msp430.h>
#include "VirtualWire.h"
#include <stdint.h>
#define cycletime 0.000000125L

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;			// Stop watchdog timer
	  UCSCTL3 = SELREF_2;                       // Set DCO FLL reference = REFO
	  UCSCTL4 |= SELA_2;                        // Set ACLK = REFO
	  UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx

	  // Loop until XT1,XT2 & DCO stabilizes - In this case only DCO has to stabilize
	  do
	  {
	    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);
	                                            // Clear XT2,XT1,DCO fault flags
	    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
	  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

	  __bis_SR_register(SCG0);                  // Disable the FLL control loop
	  UCSCTL1 = DCORSEL_5;                      // Select DCO range 16MHz operation
	  UCSCTL2 |= 249;                           // Set DCO Multiplier for 8MHz
	                                            // (N + 1) * FLLRef = Fdco
	                                            // (249 + 1) * 32768 = 8MHz
	  __bic_SR_register(SCG0);                  // Enable the FLL control loop

	  // Worst-case settling time for the DCO when the DCO range bits have been
	  // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
	  // UG for optimization.
	  // 32 x 32 x 8 MHz / 32,768 Hz = 250000 = MCLK cycles for DCO to settle
	  __delay_cycles(250000);

	//P1DIR |= BIT0;						// Set P1.0 to output direction
	//TA0CCTL0 = CCIE;                    // CCR0 interrupt enabled
	//TA0CTL = TASSEL_2 + MC_1 + TACLR + TAIE + ID_3;    // SMCLK/8, upmode
	//TA0CCR0 =  0xffff;  					// 12.5 Hz
	vw_setup(1000);
	vw_rx_start();
	P1DIR |= BIT4;

	/*uint8_t count = 1;

	while(1) {
		char msg[7] = {'h','e','l','l','o',' ','#'};

		msg[6] = count;
		vw_send((uint8_t *)msg, 7);
		vw_wait_tx(); // Wait until the whole message is gone
		__delay_cycles(5/cycletime);
		count = count + 1;
	}*/

	while(1)
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
	}
}
