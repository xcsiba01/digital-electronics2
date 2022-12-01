# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.

### Team members

* Josef Kaplan (responsible for code, documentation, schematic)
* Hajnalka Csiba (responsible for code, github repository, flowcharts)

## GitHub repository structure

   ```c
   project_1           // PlatfomIO project
   ├── include         // Included files
   │   └── timer.h
   ├── lib             //Libraries
   │   ├── gpio
   │   │   ├── gpio.c
   │   │   └── gpio.h
   │   ├── lcd
   │   │   ├── lcd.c
   │   │   ├── lcd.h
   │   |   └── lcd_definitions.h
   │   └── uart
   │       ├── uart.c
   │       └── uart.h
   ├── src              // Source file
   │   └── main.c
   ├── test
   │   └── README.md    // Report of this project
   └── platformio.ini   // Project Configuration File
         
   ```

## Hardware description

#### Schematic of the implementation:

![your figure](schema.png)

| **Joystick pin** | **Description** | **Arduino uno pin** |
| :-: | :-: | :-: |
| GND | Power Supply Ground | GND |
| +5V | Positive Power Supply | +5V |
| VRx | ADC channel | A1 (PC1) |
| VRy | ADC channel | A0 (PC0) |
| SW | Push Button | D3 (PD3) |

| **Rotary encoder pin** | **Description** | **Arduino uno pin** |
| :-: | :-: | :-: |
| CLK | Digital Input | D2 (PD2) |
| DT | Analog Input | A2 (PC2) |
| SW | Analog Input (Push Button) | A3 (PC3) |
| + | Positive Power Supply | +5V |
| GND | Power Supply Ground | GND |

| **Digilent PmodCLP LCD pin** | **Signal** | **Description** | **Arduino uno pin** |
| :-: | :-: | :-: | :-: |
| 7 (J1 - Bottom Half) | DB4 | Data Bit 4 | D4 (PD4) |
| 8 (J1 - Bottom Half) | DB5 | Data Bit 5 | D5 (PD5) |
| 9 (J1 - Bottom Half) | DB6 | Data Bit 6 | D6 (PD6) |
| 10 (J1 - Bottom Half) | DB7 | Data Bit 7 | D7 (PD7) |
| 11 (J1 - Bottom Half) | GND | Power Supply Ground | GND |
| 12 (J1 - Bottom Half) | VCC | Positive Power Supply | +5V |
| 1 (J2) | RS | Register Select | D8 (PB0) |
| 2 (J2) | R/W | Read/Write Signal | GND |
| 3 (J2) | E | Read/Write Enable | D9 (PB1) |



## Software description

#### Source file

* [main.c](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/src/main.c)

#### Library `gpio`

* [gpio.c](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/lib/gpio/gpio.c)
* [gpio.h](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/lib/gpio/gpio.h)

#### Library `lcd`

* [lcd.c](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/lib/lcd/lcd.c)
* [lcd.h](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/lib/lcd/lcd.h)
* [lcd_definitions.h](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/lib/lcd/lcd_definitions.h)

#### Library `uart`

* [uart.c](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/lib/uart/uart.c)
* [uart.h](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/lib/uart/uart.h)

#### Library `timer.h`

* [timer.h](https://github.com/xcsiba01/digital-electronics2/blob/main/project_1/include/timer.h)

#### Flowcharts of the algorithms:

![TIMER_OVF_vect]()

![ADC_vect]()

Write descriptive text of your libraries and source files.

## Video

A short video with the practical implementation example of this project is available right [here](https://www.youtube.com/watch?v=BsZNbVuyCBM).

## References

1. [PmodCLP Reference Manual](https://digilent.com/reference/pmod/pmodclp/reference-manual?redirect=1)
2. [Arduino Uno Pinout](https://docs.arduino.cc/retired/boards/arduino-uno-rev3-with-long-pins)
3. [Rotary Encoder](https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/)
4. https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/02-gpio
5. https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/03-interrupts
6. https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/04-lcd
7. https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/05-adc
8. https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/06-uart
