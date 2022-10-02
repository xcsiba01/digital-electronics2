<a name="preparation"></a>

## Preparation tasks (done before the lab at home)

1. Fill in the following table and enter the number of bits and numeric range for the selected data types defined by C.

   | **Data type** | **Number of bits** | **Range** | **Description** |
   | :-: | :-: | :-: | :-- |
   | `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
   | `int8_t`   | 8 | -128 to 127 | 8-bit integer |
   | `uint16_t` | 16 | 0 to 65 535 | Unsigned 16-bit integer |
   | `int16_t`  | 16 | -32768 to 32767 | 16-bit integer |
   | `float`    | 32 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
   | `void`     | 0 | 0 | Won't return any value |

2. Any function in C contains a declaration (function prototype), a definition (block of code, body of the function); each declared function can be executed (called). Study [this article](https://www.programiz.com/c-programming/c-user-defined-functions) and complete the missing sections in the following user defined function declaration, definition, and call.

```c
#include <avr/io.h>

// Function declaration (prototype)
uint16_t calculate(uint8_t, uint8_t);

int main(void)
{
    uint8_t a = 210;
    uint8_t b = 15;
    uint16_t c;

    // Function call
    c = calculate(a, b);

    // Infinite loop
    while (1) ;

    // Will never reach this
    return 0;
}

// Function definition (body)
uint16_t calculate(uint8_t x, uint8_t y)
{
    uint16_t result;    // result = x^2 + 2xy + y^2
    result = x*x + 2*x*y + y*y;
    return result;
}
```

<a name="part1"></a>
