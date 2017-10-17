# Button Blink

Control the state on and LED using a button

* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989



## Code Configuration

The following code can be used on all of the boards. The only change that is needed to be made is the pin assinments labeled as x's.

```c
	int main(void)
	{
    		WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    		PxOUT &= ~BITx;                     // Clear Px.x output latch for a defined power-on state
    		PxDIR |= BITx;                      // Set Px.x to output direction

		PM5CTL0 &= ~LOCKLPM5;		    // Disable the GPIO power-on default high-impedance mode
                                                    // to activate previously configured port settings
						    // Use for FR6989, FR5994, and FR2311 
    		while(1)
    		{
        		PxOUT ^= BITx;              // Toggle Px.x using exclusive-OR
        		__delay_cycles(100000);    // Delay for 100000*(1/MCLK)=0.1s
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

Make LED2 on the MSP430F5529 blink

```c
	int main(void)
	{
    		WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    		P4OUT &= ~BIT7;                     // Clear Px.x output latch for a defined power-on state
    		P4DIR |= BIT7;                      // Set Px.x to output direction

    		while(1)
    		{
        		P4OUT ^= BIT7;              // Toggle Px.x using exclusive-OR
        		__delay_cycles(100000);    // Delay for 100000*(1/MCLK)=0.1s
    		}

	}
```

## LED Blink Rate

The rate at which the LED blinks can simply be modified in the following line of code:

```c
    __delay_cycles(x);    // Delay for x*(1/MCLK) seconds

```
Adjusting the value of x will control the rate of the blink.
* A greater value of x will result in a slower blink rate
* A smaller value of x will result in a faster blink rate
* Using a value of 100000 for x will cause the LED to blink eve 0.1s
