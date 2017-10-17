#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= 0x41;    //Declare pin 1.0 and 1.9 as output

    while(1)
    {
        P1OUT ^= BIT0;   // Toggle P1.0
        P1OUT ^= BIT6;   // Toggle P9.7
        _delay_cycles(200000);
        P1OUT ^= BIT6;
        _delay_cycles(200000);   //LED2 will blink 3x as fast as LED1
        P1OUT ^= BIT6;
        _delay_cycles(200000);
    }
}
