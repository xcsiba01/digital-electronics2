/***********************************************************************
 * 
 * Use Analog-to-digital conversion to read push buttons on LCD keypad
 * shield and display it on LCD screen.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions
#include <uart.h>

#define BTN 3
#define BTN_p 3
#define DATA 2
#define CLK 2

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and start ADC conversion every 100 ms.
 *           When AD conversion ends, send converted value to LCD screen.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    uart_init(UART_BAUD_SELECT(9600, F_CPU));
    DDRC &= ~(1<<DATA);
    DDRD &= ~(1<<CLK);
    PORTC &= ~(1<<DATA);
    PORTD &= ~(1<<CLK);

    // Initialize display
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(1, 0); lcd_puts("value:");
    lcd_gotoxy(1, 1); lcd_puts("value:");
    lcd_gotoxy(8, 0); lcd_puts("a");  // Put ADC value in decimal
    lcd_gotoxy(13,0); lcd_puts("b");  // Put ADC value in hexadecimal
    lcd_gotoxy(8, 1); lcd_puts("c");  // Put button name here

    // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVcc with external capacitor at AREF pin"
    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);

    // Select input channel ADC0 (voltage divider pin)
    ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0));
    

    // Enable ADC module
    ADCSRA |= (1<<ADEN);


    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);

    // Set clock prescaler to 128
    ADCSRA |= ((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));


    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Set prescaler to 33 ms and enable overflow interrupt
    TIM1_overflow_33ms();
    TIM1_overflow_interrupt_enable();

    GPIO_mode_input_pullup(&DDRD, BTN);
    GPIO_mode_input_pullup(&DDRC, BTN_p);

    //TIM0_overflow_16ms();
    //TIM1_overflow_interrupt_enable();

    //GPIO_mode_input_pullup(&DDRC, DATA);
    //GPIO_mode_input_pullup(&DDRD, CLK);

    

    //GPIO_mode_input_pullup(&DDRC, DATA);
    //GPIO_mode_input_pullup(&DDRD, CLK);


    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion every 100 ms.
 **********************************************************************/

ISR(TIMER1_OVF_vect)
{
    // Start ADC conversion
    static uint8_t kanal = 0;
    static uint8_t A_curr, B_curr, A_prev, B_prev;
    char string[1];

    if (kanal == 0)
    {
         ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0));
         kanal = 1; 
    }
    else {
        ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) ); ADMUX |= (1<<MUX0); 
        kanal = 0;
    }

    ADCSRA |= (1<<ADSC);


    A_curr = GPIO_read(&PINC, DATA);
    B_curr = GPIO_read(&PIND, CLK);

    if(A_curr == A_prev)
    {
        if(B_curr != B_prev)
        {
            uart_puts("1");
            uart_puts("\r\n");
        }
    }
    else if(B_curr == B_prev)
    {
        if(A_curr != A_prev)
        {
            uart_puts("0");
            uart_puts("\r\n");
        }
    }
    B_prev = B_curr;
    A_prev = A_curr;


}

}


/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display converted value on LCD screen.
 **********************************************************************/

ISR(ADC_vect)
{
    static uint8_t kanal = 0;
    uint16_t value, sw, sw_p;
    char string[4];  // String for converted numbers by itoa()

    // Read converted value
    // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
    
    // Convert "value" to "string" and display it
    if (kanal == 0)
    {
        value = ADC;
        itoa(value, string, 10);
        lcd_gotoxy(8, 0); 
        lcd_puts("    ");
        lcd_gotoxy(8, 0);
        lcd_puts(string);

        itoa(value, string, 16);
        lcd_gotoxy(13, 0); 
        lcd_puts(string);
        kanal = 1;
    }
    
    else if (kanal == 1)
    {
        value = ADC;
        itoa(value, string, 10);
        lcd_gotoxy(8, 1); 
        lcd_puts("    ");
        lcd_gotoxy(8, 1);
        lcd_puts(string); 

        itoa(value, string, 16);
        lcd_gotoxy(13, 1); 
        lcd_puts(string);
        kanal = 0;
    }
    
    sw = GPIO_read(&PIND, BTN);
    itoa(sw, string, 10);
    lcd_gotoxy(0, 0); 
    lcd_puts(string);
    
    sw = GPIO_read(&PIND, BTN);
    itoa(sw, string, 10);
    lcd_gotoxy(0, 0); 
    lcd_puts(string);

    sw_p = GPIO_read(&PINC, BTN_p);
    itoa(sw_p, string, 10);
    lcd_gotoxy(0, 1); 
    lcd_puts(string);


}
