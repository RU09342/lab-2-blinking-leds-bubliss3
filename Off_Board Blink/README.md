# Off Board Blink

Making an on board LED blink on a MSP430G2553 can be a good starting point, but what if we could take the G2553 chip off the development board and use it on a breadboard to blink 2 LEDs. To accomplish this task you will need:

* Proper Power being supplied to the processor
* Proper Reset Circuitry
* Proper Bypass and Bulk Capacitors as needed

Be advised that you can easily damage or destroy one of the pins on the MSP430 by applying the wrong voltage or attempting to draw too much current from it. Really check your design before you power up to ensure you do not need request another processor.

## Programming the G2553

Before we can remove the G2553 from the launchpad we much first program it to run the code we want. We will use simple code that blinks two LEDs. 

```c
	int main(void)
	{
    		WDTCTL = WDTPW | WDTHOLD;// Stop watchdog timer

    		P1DIR |= 0x41; // Set P1.0 and P1.6 to output direction
    		P1OUT |= 0x01;

		for(;;)
		{
   			P1OUT ^= 0x01;  // Toggle P1.0 using exclusive-OR
   			P1OUT ^= 0x40;	// Toggle P1.6 using exclusive-OR

   			_delay_cycles(200000); //Control the rate at which the LEDs blink
		}
	}
```
## Implementation

After the code has been compiled onto the G2553 the chip can be placed on a breadboard. To wire up the G2553 chip:

* A 3.3V source was connected to Pin 1 (DVCC)
* LED1 was connected to Pin 2 of the chip in series with a 1k resistor
* LED2 was connected to Pin 14 of the chip in series with a 1k resistor
* Pin 16 (RESET) was connected to power using a 1K to stop the chip from reseting
* A bypass capacitor of 0.1 uF was hooked up from Pin 1 (DVCC) to GND

![alt text](https://github.com/RU09342/lab-2-blinking-leds-bubliss3/blob/master/msp430G2553.png)

## Breadboard Demonstration

![alt text](https://github.com/RU09342/lab-2-blinking-leds-bubliss3/blob/master/Off_Board%20Blink/ezgif.com-video-to-gif.gif)

## LED Blink Rate

The rate at which the LEDs blink can simply be modified in the following line of code:

```c
    __delay_cycles(x);

```
Adjusting the value of x will control the rate of the blink.
* A greater value of x will result in a slower blink rate
* A smaller value of x will result in a faster blink rate