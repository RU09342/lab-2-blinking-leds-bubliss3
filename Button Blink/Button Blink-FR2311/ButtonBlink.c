#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR = BIT0; //Declare PIN 1.0 as output
    P1REN = BIT1; //Set PIN 1.1 as pull-up resistor (normally high)
    P1OUT = BIT1;

    PM5CTL0 &= ~LOCKLPM5;

    while(1)
    {
        if((P1IN & BIT1)!=BIT1) //BIT1 will always stay as 1, if button is pressed P1IN will go to 0, by default it is 1.
        {
            __delay_cycles(220000);
            P1OUT ^= BIT0;                 //This will execute every time the button is pressed
        }
    }
}
