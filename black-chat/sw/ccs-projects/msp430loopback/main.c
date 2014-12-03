#include <msp430f2617.h>
#include "VirtualWire.h"
#include <stdint.h>
#define CLOCK_SPEED 8000000
#define CYCLE_TIME 1/CLOCK_SPEED

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;			// Stop watchdog timer


}
