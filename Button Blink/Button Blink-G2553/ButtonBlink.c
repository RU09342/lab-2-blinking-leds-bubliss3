#include <msp430g2553.h>

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR = BIT0; //Declare PIN 1.0 as output
    P1REN = BIT3; //Set PIN 1.3 as pull-up resistor (normally high)
    P1OUT = BIT3;
    while(1)
    {
        if((P1IN & BIT3)!=BIT3) //BIT3 will always stay as 1, if button is pressed P1IN will go to 0, by default it is 1.
        {
            __delay_cycles(220000);
            P1OUT ^= BIT0;                 //This will execute every time the button is pressed
        }
    }
}
