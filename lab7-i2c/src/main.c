/***********************************************************************
 * 
 * The I2C (TWI) bus scanner tests all addresses and detects chips and
 * modules that are connected to the SDA and SCL signals.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1, send one I2C (TWI) address every 33 ms,
 *           and test all combinations. Send information about scanning
 *           process to UART.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize I2C (TWI)
    twi_init();

    // Initialize USART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));

    // Configure 16-bit Timer/Counter1 to test one I2C address
    // Set prescaler to 33 ms and enable interrupt
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    uart_puts("Scan I2C bus for devices:\r\n");

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
 * Purpose:  Test one I2C Slave address from the range 8 to 119.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    static uint8_t sla = 87;  // I2C Slave address     92
    uint8_t ack;             // ACK response from Slave
    char string[3];          // String for converting numbers by itoa()
    uint8_t data;          
    
    // Declaration of "air" variable with structure "Air_parameters_structure"
      struct Air_parameters_structure {
      uint8_t humid_int;  //0x00
      uint8_t humid_dec;  //0x01
      uint8_t temp_int;   //0x02
      uint8_t temp_dec;   //0x03
      uint8_t checksum;   //0x04
    } air;

          struct Clock_parameters_structure {
      uint8_t sec;     //0x00
      uint8_t min;     //0x01
      uint8_t hour;    //0x02
    } clock;
     
    ack = twi_start(sla, TWI_WRITE);
    twi_write(0x00);
    twi_stop();

    ack = twi_start(sla, TWI_READ);
    clock.sec = twi_read_nack();  // Store one byte to structured variable
    twi_stop();
    uart_puts("Seconds: ");
    itoa(clock.sec, string, 10);
    uart_puts(string);
    uart_puts("\r\n");


    ack = twi_start(sla, TWI_WRITE);
    twi_write(0x01);
    twi_stop();

    ack = twi_start(sla, TWI_READ);
    clock.min = twi_read_nack();  // Store one byte to structured variable
    twi_stop();
    uart_puts("Minutes: ");
    itoa(clock.min, string, 10);
    uart_puts(string);
    uart_puts("\r\n");


    ack = twi_start(sla, TWI_WRITE);
    twi_write(0x02);
    twi_stop();

    ack = twi_start(sla, TWI_READ);
    clock.hour = twi_read_nack();  // Store one byte to structured variable
    twi_stop();
    uart_puts("Hours: ");
    itoa(clock.hour, string, 10);
    uart_puts(string);
    uart_puts("\r\n");

    /*
    // Start communication, transmit I2C Slave address, get result,
    // and Stop communication
    ack = twi_start(sla, TWI_WRITE);
    twi_write(0x00);
    twi_stop();

    ack = twi_start(sla, TWI_READ);
    air.humid_int = twi_read_nack();  // Store one byte to structured variable
    twi_stop();
    uart_puts("Humidity: ");
    itoa(air.humid_int, string, 10);
    uart_puts(string);
    uart_puts(".");

    ack = twi_start(sla, TWI_WRITE);
    twi_write(0x01);
    twi_stop();

    ack = twi_start(sla, TWI_READ);
    air.humid_dec = twi_read_nack();  // Store one byte to structured variable
    twi_stop();
    itoa(air.humid_dec, string, 10);
    uart_puts(string);
    uart_puts("\r\n");



    ack = twi_start(sla, TWI_WRITE);
    twi_write(0x02);
    twi_stop();

    ack = twi_start(sla, TWI_READ);
    air.temp_int = twi_read_nack();  // Store one byte to structured variable
    twi_stop();
    uart_puts("Temperature: ");
    itoa(air.temp_int, string, 10);
    uart_puts(string);
    uart_puts(".");
     
    ack = twi_start(sla, TWI_WRITE);
    twi_write(0x03);
    twi_stop();

    ack = twi_start(sla, TWI_READ);
    air.temp_dec = twi_read_nack();  // Store one byte to structured variable
    twi_stop();
    itoa(air.temp_dec, string, 10);
    uart_puts(string);
    uart_puts("\r\n");
    
    
    ack = twi_start(sla, TWI_WRITE);
    twi_write(0x04);
    twi_stop();

    ack = twi_start(sla, TWI_READ);
    air.checksum = twi_read_nack();  // Store one byte to structured variable
    twi_stop();
    uart_puts("Checksum: ");
    itoa(air.checksum, string, 10);
    uart_puts(string);
    uart_puts("\r\n");
    */
    /*
    ack = twi_start(sla, TWI_WRITE);
    twi_stop();

    if(ack==0)

    {
      itoa(sla, string, 10);
      uart_puts("Device adress is: ");
      uart_puts(string);
      uart_puts("\r\n");
    }
    
    sla++;

    if (sla > 119)
     {
      sla=8;
      uart_puts("\r\nRepeating scan...\r\n");
     }*/

    // Test ACK/NACK value obtained from I2C bus and send info to UART
    
}