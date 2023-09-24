#include "main.h"
/**
 * is_printable - Evaluates if a character is printable
 * @c: Character to be evaluated
 * Done by @Mekonen-Abera & gebre-a
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
    if (c >= 32 && c < 127)
        return (1);
    return (0);
}
/**
 * append_hexa_code - Append ascii in hexadecimal
 * @buffer: An array of characters
 * @i: index at which to start appending
 * @ascii_code: ASCII Code
 * Done by @Mekonen-Abera & gebre-a
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
    char map_to[] = "0123456789ABCDEF";
    if (ascii_code < 0)
        ascii_code *= -1;
    buffer[i++] = '\\';
    buffer[i++] = 'x';
    buffer[i++] = map_to[ascii_code / 16];
    buffer[i] = map_to[ascii_code % 16];
    return (3);
}
/**
 * is_digit - Verifies if a character is a digit
 * @c: Character to be evaluated
 * Done by @Mekonen-Abera & gebre-a
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Done by @Mekonen-Abera & gebre-a
 * Return: Casted value of numbers
 */
long int convert_size_number(long int num, int size)
{
    if (size == S_LONG)
        return (num);
    else if (size == S_SHORT)
        return ((short)num);
    return ((int)num);
}
/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Done by @Mekonen-Abera & gebre-a
 * Return: Casted value of numbers
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
    if (size == S_LONG)
        return (num);
    else if (size == S_SHORT)
        return ((unsigned short)num);
    return ((unsigned int)num);
}