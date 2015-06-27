/***** Configure IO *****/
#define configure_as_input(port, bit)		{DDR ## port &= ~(1 << bit);}
#define configure_as_output(port, bit)		{bit ## _DDR |= (1 << bit);}

#define pullup_on(bit)                      {bit ## _PORT |= (1 << bit);}
#define pullup_off(bit)                     {bit ## _PORT &= ~(1 << bit);}

#define disable_digital_input(channel)      {DIDR0 |= (1 << channel);}
#define enable_digital_input(channel)       {DIDR0 &= ~(1 << channel);}

#define enable_pin_change_interrupt(pin)    {pin ## _PCMSK |= (1 << pin ## _PCINT);}
#define disable_pin_change_interrupt(pin)   {pin ## _PCMSK &= ~(1<< pin ## _PCINT);}


/***** Manipulate Outputs *****/
#define set_high(bit)                       {bit ## _PORT |= (1 << bit);}
#define set_low(bit)                        {bit ## _PORT &= ~(1 << bit);}
#define toggle(bit)                         {bit ## _PORT ^= (1 << bit);}

/***** Test Inputs *****/
#define is_high(bit)                        (bit ## _PIN & (1 << bit))
#define is_low(bit)                         (! (bit ## _PIN & (1 << bit)))



/***** IO *****/
#define REED_CONTACT                PA0
#define REED_CONTACT_PORT           PORTA
#define REED_CONTACT_DDR            DDRA
#define REED_CONTACT_PIN            PINA
#define REED_CONTACT_PCMSK          PCMSK0
#define REED_CONTACT_PCINT          PCINT0


#define SWITCH                      PA1
#define SWITCH_PORT                 PORTA
#define SWITCH_DDR                  DDRA
#define SWITCH_PIN                  PINA
#define SWITCH_PCMSK                PCMSK0
#define SWITCH_PCINT                PCINT1


#define POT_ENABLE                  PA2
#define POT_ENABLE_PORT             PORTA
#define POT_ENABLE_DDR              DDRA
#define POT_ENABLE_PIN              PINA


#define POT_SIGNAL                  PA3
#define POT_SIGNAL_PORT             PORTA
#define POT_SIGNAL_DDR              DDRA
#define POT_SIGNAL_PIN              PINA


#define ISR_TEMP                    PB0
#define ISR_TEMP_PORT               PORTB
#define ISR_TEMP_DDR                DDRB
#define ISR_TEMP_PIN                PINB


#define PWM_OUT                     PB2
#define PWM_OUT_PORT                PORTB
#define PWM_OUT_DDR                 DDRB
#define PWM_OUT_PIN                 PINB

/*
// Allows for stuff like this:

// REED_CONTACT - Digital Input
enable_digital_input (REED_CONTACT);
enable_pin_change_interrupt (REED_CONTACT);

// SWITCH - Digital Input
enable_digital_input (SWITCH);
enable_pin_change_interrupt (SWITCH);

// POT_ENABLE - Digital Output
configure_as_output (POT_ENABLE);
set_low (POT_ENABLE);
enable_digital_input (POT_ENABLE);

// POT_SIGNAL - Analog Input
pullup_off (POT_SIGNAL);

// ISR_TEMP - DIGITAL OUTPUT
configure_as_output (ISR_TEMP);
set_low (ISR_TEMP);

// PWM_OUT - Digital Output
configure_as_output (PWM_OUT);
set_low (PWM_OUT);

if (is_high (REED_CONTACT) || is_low (SWITCH))
{
	do_something();
}


*/