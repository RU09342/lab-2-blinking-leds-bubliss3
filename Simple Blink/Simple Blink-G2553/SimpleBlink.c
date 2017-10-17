#include <msp430g2553.h>  // header file that depends upon your variant

    unsigned int i = 0;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;// Stop watchdog timer

    P1DIR |= 0x01;    //Declare PIN 1.0 as output

for(;;)
{
    P1OUT ^= 0x01;

    for(i=0; i<20000; i++);
    }
}
