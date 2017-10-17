# Button Blink

Control the state of the LED using a button on 5 different MSP430 microcontrollers:

* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

Pressing the button on the microcontroller will cause the LED to turn on and off

## Code Configuration

The following code can be used on all of the boards. The only change that is needed to be made is the pin assinments labeled as x's for the LED and y's for the Button

```c
	void main(void)
	{
    		WDTCTL = WDTPW + WDTHOLD;
    		PxDIR = BITx; // Declare Px.x as output
    		PyREN = BITy; // Set Py.y as pull-up resistor (normally high)
    		PyOUT = BITy;

    	while(1)
    	{
        	if((PyIN & BITy)!=BITy) // BIT1 will always stay as 1, if button is pressed 
					// P1IN will go to 0, by default it is 1.
        	{
            		__delay_cycles(220000);
           		 PxOUT ^= BITx;     // This will execute every time the button is pressed
        	}
    	}
	}
```
## Pin Assignments

Depending on which LED is chosen to blink, the following pin assignments will declare the corresponding LED to blink:

```c		
		   LED1		LED2	BUTTON
* MSP430G2553	=> P1.0 	P1.6	P1.3
* MSP430F5529	=> P1.0 	P4.7	P2.1
* MSP430FR2311	=> P1.0 	P2.0	P1.1
* MSP430FR5994	=> P1.0 	P1.1	P5.6
* MSP430FR6989	=> P1.0 	P9.7	P1.1
```

## Code Example

Make LED1 on the MSP430F5529 turn on and off with a button

```c
	void main(void)
	{
    		WDTCTL = WDTPW + WDTHOLD;
    		P1DIR = BIT0; // Declare PIN 1.0 as output
    		P2REN = BIT1; // Set PIN 2.1 as pull-up resistor (normally high)
    		P2OUT = BIT1;

    	while(1)
    	{
        	if((P2IN & BIT1)!=BIT1) // BIT1 will always stay as 1, if button is pressed 
					// P1IN will go to 0, by default it is 1.
        	{
            		__delay_cycles(220000);
           		 P1OUT ^= BIT0;     // This will execute every time the button is pressed
        	}
    	}
	}
```
