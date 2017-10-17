#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR = BIT0; //Declare PIN 1.0 as output
    P5REN = BIT6; //Set PIN 5.6 as pull-up resistor (normally high)
    P5OUT = BIT6;

    PM5CTL0 &= ~LOCKLPM5;

    while(1)
    {
        if((P5IN & BIT6)!=BIT6) //BIT6 will always stay as 1, if button is pressed P5IN will go to 0, by default it is 1.
        {
            __delay_cycles(220000);
            P1OUT ^= BIT0;                 //This will execute every time the button is pressed
        }
    }
}
