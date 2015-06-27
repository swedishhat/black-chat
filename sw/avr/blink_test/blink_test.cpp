#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x08;

    while (1) {
        PORTB = 0x00; 
        _delay_ms(500);
        PORTB = 0x08; 
        _delay_ms(500);
    }
}
