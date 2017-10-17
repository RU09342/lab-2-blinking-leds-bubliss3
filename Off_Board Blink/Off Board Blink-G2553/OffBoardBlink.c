#include <msp430g2553.h>  // header file that depends upon your variant

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;// Stop watchdog timer

    P1DIR |= 0x41;
    P1OUT |= 0x01;

for(;;)
{
   P1OUT ^= 0x01;
   P1OUT ^= 0x40;

   _delay_cycles(200000);
}
}
