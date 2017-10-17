#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= BIT0;  //Declare pin 1.0 as output
    P4DIR |= BIT7;  //Declare pin 2.0 as output


    while(1)
    {
       P1OUT ^= BIT0;   // Toggle P1.0
       P4OUT ^= BIT7;   // Toggle P2.0
       _delay_cycles(200000);
       P4OUT ^= BIT7;
       _delay_cycles(200000);   //LED2 will blink 3x as fast as LED1
       P4OUT ^= BIT7;
       _delay_cycles(200000);
    }
}
