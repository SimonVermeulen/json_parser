/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** handles all the conversions
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"

int handler_convert_base_binary(va_list ap, char *argument, int std)
{
    if (ap && argument == NULL) {
        my_putstr(my_convert_base(va_arg(ap, int), "01"), std);
        return (1);
    } else if (ap && argument[0] == '#') {
        my_putstr("0b", std);
        my_putstr(my_convert_base(va_arg(ap, int), "01"), std);
        return (1);
    } else {
        return (0);
    }
}

int handler_convert_base_octal(va_list ap, char *argument, int std)
{
    if (ap && argument == NULL) {
        my_putstr(my_convert_base(va_arg(ap, int), "01234567"), std);
        return (1);
    } else if (ap && argument[0] == '#') {
        my_putstr("0o", std);
        my_putstr(my_convert_base(va_arg(ap, int), "01234567"), std);
        return (1);
    } else {
        return (0);
    }
}

int handler_convert_base_hexa(va_list ap, char *argument, int std)
{
    if (ap && argument == NULL) {
        my_putstr(my_convert_base(va_arg(ap, int), "0123456789abcdef"), std);
        return (1);
    } else if (ap && argument[0] == '#') {
        my_putstr("0x", std);
        my_putstr(my_convert_base(va_arg(ap, int), "0123456789abcdef"), std);
        return (1);
    } else {
        return (0);
    }
}

int handler_convert_base_maj_hexa(va_list ap, char *argument, int std)
{
    if (ap && argument == NULL) {
        my_putstr(my_convert_base(va_arg(ap, int), "0123456789ABCDEF"), std);
        return (1);
    } else if (ap && argument[0] == '#') {
        my_putstr("0X", std);
        my_putstr(my_convert_base(va_arg(ap, int), "0123456789ABCDEF"), std);
        return (1);
    } else {
        return (0);
    }
}
