/*
** EPITECH PROJECT, 2021
** C Pool Day 08
** File description:
** recreate my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *s)
{
    char *s2 = NULL;
    int len = my_strlen(s);

    s2 = malloc(sizeof(char) * (len + 1));
    if (!s2)
        return (NULL);
    for (len = 0; s[len]; len++)
        s2[len] = s[len];
    s2[len] = '\0';
    return (s2);
}
