#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= 0x03;    //Declare pin 1.0 and 1.1 as output

    PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode
                                // to activate previously configured port settings

    while(1)
    {
       P1OUT ^= 0x01;   // Toggle P1.0
       P1OUT ^= 0x02;   // Toggle P1.1
       _delay_cycles(200000);
       P1OUT ^= 0x02;
       _delay_cycles(200000);   //LED2 will blink 3x as fast as LED1
       P1OUT ^= 0x02;
       _delay_cycles(200000);
    }
}
