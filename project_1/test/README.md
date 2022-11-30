# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.

## Instructions

The goal of the project is cooperation in pairs, further study of the topic, design of own solutions, implementation, creation of project documentation and presentation of results. The division of roles and tasks within the team is up to their members.

* Students work on a project in the labs during the 10th and 11th weeks of the semester.

* Through the BUT e-learning, students submit a link to the GitHub repository, which contains the complete project in PlatfomIO and a descriptive README file. The submission deadline is the day before the next laboratory, i.e. in 2 weeks.

* The source code for the AVR must be written in C and/or Assembly and must be implementable on Arduino Uno board using toolchains from the semester. No other development tools are allowed.

### Team members

* Member 1 (responsible for xxx)
* Member 2 (responsible for xxx)

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
   ├── src                // Source file
   │   └── main.c
   ├── test
   │   └── README.md    // Report of this project
   └── platformio.ini   // Project Configuration File
         
   ```

## Hardware description

Schematic of the implementation:

![your figure](schema.png)

| **Joystick pin** | **Description** | **Arduino uno pin** |
| :-: | :-: | :-: |
| GND | Power Supply Ground | GND |
| +5V | Positive Power Supply | +5V |
| VRx | ADC channel | PC1 |
| VRy | ADC channel | PC0 |
| SW | Push Button | PD3 |

| **Rotary encoder pin** | **Description** | **Arduino uno pin** |
| :-: | :-: | :-: |
| CLK | Digital Input | PD2 |
| DT | Analog Input | PC2 |
| SW | Analog Input | PC3 |
| + | Positive Power Supply | +5V |
| GND | Power Supply Ground | GND |

| **Digilent Pmod CLP LCD pin** | **Signal** | **Description** | **Arduino uno pin** |
| :-: | :-: | :-: | :-: |
| 7 (J1) | DB4 | Data Bit 4 | PD4 |
| 8 (J1) | DB5 | Data Bit 5 | PD5 |
| 9 (J1) | DB6 | Data Bit 6 | PD6 |
| 10 (J1) | DB7 | Data Bit 7 | PD7 |
| 11 (J1) | GND | Power Supply Ground | GND |
| 12 (J1) | VCC | Positive Power Supply | +5V |
| 1 (J2) | RS | Register Select | PB0 |
| 2 (J2) | R/W | Read/Write Signal | GND |
| 3 (J2) | E | Read/Write Enable | PB1 |



## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. Write your text here.
2. ...
https://digilent.com/reference/pmod/pmodclp/reference-manual?redirect=1
