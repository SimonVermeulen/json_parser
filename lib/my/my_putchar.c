/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c, int std)
{
    write(1, &c, std);
}
