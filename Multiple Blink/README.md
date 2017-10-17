# Multiple Blink

Making multiple LEDs blink at different rates on 5 different MSP430 microcontrollers:

* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

The following code will make LED2 blink 3x faster than LED1

## Code Configuration

The following code can be used on all of the boards. The only change that is needed to be made is the pin assignments labeled as x's for LED1 and y's for LED2

```c
	int main(void)
	{
    		WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    		PxDIR |= BITx;  //Declare LED1 Px.x as output
    		PyDIR |= BITy;  //Declare LED2 Py.y as output

		PM5CTL0 &= ~LOCKLPM5;		    // Disable the GPIO power-on default high-impedance mode
                                                    // to activate previously configured port settings
						    // Use for FR6989, FR5994, and FR2311
    		while(1)
    		{
       			PxOUT ^= BITx;   // Toggle Px.x (LED1)
       			PyOUT ^= BITy;   // Toggle Py.y	(LED2)
       			_delay_cycles(200000);
       			PyOUT ^= BITy;
       			_delay_cycles(200000);   //LED2 will blink 3x as fast as LED1
       			PyOUT ^= BITy;
       			_delay_cycles(200000);
    		}
	}
```
## Pin Assignments

Depending on which LED is chosen to blink, the following pin assignments will declare the corresponding LED to blink:

```c		
		   LED1		LED2
* MSP430G2553	=> P1.0 	P1.6
* MSP430F5529	=> P1.0 	P4.7
* MSP430FR2311	=> P1.0 	P2.0
* MSP430FR5994	=> P1.0 	P1.1
* MSP430FR6989	=> P1.0 	P9.7
```

## Code Example

Make LED2 on the MSP430F5529 blink 3x faster than LED1 

```c
	int main(void)
	{
    		WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    		P1DIR |= BIT0;  //Declare pin 1.0 as output
    		P4DIR |= BIT7;  //Declare pin 4.7 as output


    		while(1)
    		{
       			P1OUT ^= BIT0;   // Toggle P1.0
       			P4OUT ^= BIT7;   // Toggle P4.7
       			_delay_cycles(200000);
       			P4OUT ^= BIT7;
       			_delay_cycles(200000);   //LED2 will blink 3x as fast as LED1
       			P4OUT ^= BIT7;
       			_delay_cycles(200000);
    		}
	}
```

## LED Blink Rate

The rate at which the LED blinks can simply be modified in the following line of code:

```c
    __delay_cycles(x);

```
Adjusting the value of x will control the rate of the blink.
* A greater value of x will result in a slower blink rate
* A smaller value of x will result in a faster blink rate
