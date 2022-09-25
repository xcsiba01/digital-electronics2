# Lab 1: YOUR_FIRSTNAME LASTNAME

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_RED, OUTPUT);

    // Infinite loop
    while (1)
    {
        //dot blink
        digitalWrite(LED_RED, HIGH);
        _delay_ms(250);
        digitalWrite(LED_RED, LOW);
        _delay_ms(250);

        //comma blink
        digitalWrite(LED_RED, HIGH);
        _delay_ms(750);
        digitalWrite(LED_RED, LOW);
        _delay_ms(750);
    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure](circuit.PNG)
   
   ![your figure](circuit_2.PNG)
