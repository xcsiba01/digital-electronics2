
/* Includes ----------------------------------------------------------*/
#include "Arduino.h"

static int start = 500;  //0.5ms, pulse width for 0 degrees
static int end = 2500;   //2.5 ms, pulse width for 180 degrees
static int step = 10;    
static int counter = 0;

/*Main function--------------------------------------------------------*/
int main()
{

    pinMode(9, OUTPUT);    //servo motor 1, arduino uno pin 9
    pinMode(10, OUTPUT);   //servo motor 2, arduino uno pin 10

    TCCR1A=0;   //reset the register
    TCCR1B=0;   //reset the register
    TCNT1=0;
    TCCR1A |= ((1<<COM1A1) | (1<<COM1B1) | (1<<WGM11)); TCCR1A &= ~((1<<COM1A0) | (1<<COM1B0) | (1<<WGM10));
    TCCR1B |= ((1<<WGM13) | (1<<CS11)); TCCR1B &= ~((1<<ICNC1) | (1<<ICES1) | (1<<WGM12) | (1<<CS12) | (1<<CS10));  //prescaler is 8
    ICR1=20000; //20ms, TOP

    // Infinite loop for controlling two servo motors
    while (true)
    {
            for(counter = start; counter <end; counter+=step){
            OCR1A = counter;
            OCR1B = counter;
            delayMicroseconds(12000);
            }
            for(counter = end; counter >start; counter-=step){
            OCR1A = counter;
            OCR1B = counter;
            delayMicroseconds(12000);
            }     
    }

}
