/*
** EPITECH PROJECT, 2021
** C Pool Day 04
** File description:
** displays a given string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str, int std)
{
    int i = 0;

    for (; str[i]; i++)
        my_putchar(str[i], std);
    return (i);
}
