#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= 0x01;  //Declare pin 1.0 as output
    P2DIR |= 0x01;  //Declare pin 2.0 as output

    PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode
                                // to activate previously configured port settings

    while(1)
    {
       P1OUT ^= 0x01;   // Toggle P1.0
       P2OUT ^= 0x01;   // Toggle P2.0
       _delay_cycles(200000);
       P2OUT ^= 0x01;
       _delay_cycles(200000);   //LED2 will blink 3x as fast as LED1
       P2OUT ^= 0x01;
       _delay_cycles(200000);
    }
}
