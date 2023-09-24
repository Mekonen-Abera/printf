#include "main.h"

/********************** Print Unsigned Number ********************/
/**
 * print_unsigned - The functions Prints an unsigned number
 * @types: The lists of an arguments
 * @buffer: Buffer array
 * @flags: active flags specifier
 * @width: get widths
 * @precision: Precision specifier
 * @size: Size specification
 * By @Mekonen-Abera & @gebre-a
 * Return: Number of unsigned to be printed
 */

int print_unsigned(va_list types, char buffer[],
                   int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = convert_size_unsgnd(num, size);
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';
    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }
    i++;
    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************ Print Unsigned Number in Octal  ************/
/**
 * print_octal - The function Prints an unsigned number in octal form
 * @types: Lists of an arguments
 * @buffer: Buffer to be printed
 * @flags:  Calculates flags
 * @width: get widths
 * @precision: Precision specifier
 * @size: Size specifications
 * By @Mekonen-Abera & @gebre-a
 * Return: The Number of unsigned in octal to be printed
 */

int print_octal(va_list types, char buffer[],
                int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);
    num = convert_size_unsgnd(num, size);
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }
    if (flags & F_HASH && init_num != 0)
        buffer[i--] = '0';

    i++;

    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** Print Unsigned Number in Lower Hexadecimal notation *************/
/**
 * print_hexadecimal - The functions Prints an unsigned number in Hex
 * @types: Lists of an arguments
 * @buffer: Buffer array to be printed
 * @flags: specifies active flags
 * @width: get widths
 * @precision: Precision specifications
 * @size: Size specifiers
 * By @Mekonen-Abera & @gebre-a
 * Return: Unsigned Number in lower Hex to be printed
 */

int print_hexadecimal(va_list types, char buffer[],
                      int flags, int width, int precision, int size)
{
    return (print_hexa(types, "0123456789abcdef", buffer,
                       flags, 'x', width, precision, size));
}

/************ Print Unsigned Number in Upper Hexadecimal *************/
/**
 * print_hexa_upper - Functions that Prints an unsigned number in upper hexadecimal
 * @types: Lists of an arguments
 * @buffer: Buffer
 * @flags: active flags calculations
 * @width: get widths
 * @precision: Precision specifier
 * @size: Size specifications
 * By @Mekonen-Abera & @gebre-a
 * Return: Unsigned Number in upper Hex to be printed
 */

int print_hexa_upper(va_list types, char buffer[],
                     int flags, int width, int precision, int size)
{
    return (print_hexa(types, "0123456789ABCDEF", buffer,
                       flags, 'X', width, precision, size));
}

/************** Print Hex Number in Upper or lower **************/
/**
 * print_hexa -Functions that Prints a hexadecimal number in both lower or upper
 * @types: The Lists of an arguments
 * @map_to: Array of values to map the numbers
 * @buffer: Buffer array to handle printed numbers
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get widths
 * @precision: Precision specification
 * @size: Size specifiers
 * @size: Size specifications
 * By @Mekonen-Abera & @gebre-a
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
               int flags, char flag_ch, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);
    num = convert_size_unsgnd(num, size);
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';
    while (num > 0)
    {
        buffer[i--] = map_to[num % 16];
        num /= 16;
    }
    if (flags & F_HASH && init_num != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }
    i++;
    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
