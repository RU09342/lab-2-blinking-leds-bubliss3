# Off Board Blink

Making an on board LED blink on a MSP430G2553 can be a good starting point, but what if we could take the G2553 chip off the development board and use it on a breadboard to blink 2 LEDs. To accomplish this task you will need:

* Proper Power being supplied to the processor
* Proper Reset Circuitry
* Proper Bypass and Bulk Capacitors as needed

Be advised that you can easily damage or destroy one of the pins on the MSP430 by applying the wrong voltage or attempting to draw too much current from it. Really check your design before you power up to ensure you do not need request another processor.

## Programming the G2553


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
## Breadboard Demonstration

![alt text](lab-2-blinking-leds-bubliss3/Off_Board Blink/ezgif.com-video-to-gif.gif)

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