#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= BIT0;    //Declare pin 1.0 as output
    P9DIR |= BIT7;    //Declare pin 9.7 as output

    PM5CTL0 &= ~LOCKLPM5;

    while(1)
    {
       P1OUT ^= BIT0;   // Toggle P1.0
       P9OUT ^= BIT7;   // Toggle P9.7
       _delay_cycles(200000);
       P9OUT ^= BIT7;
       _delay_cycles(200000);   //LED2 will blink 3x as fast as LED1
       P9OUT ^= BIT7;
       _delay_cycles(200000);
    }
}
