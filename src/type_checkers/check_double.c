/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** checks if the current line contains a double
*/

#include "json_parser.h"

int check_double(const char *line)
{
    int i = 0;
    int dot = 0;
    int len = 0;
    int stop = 0;

    if (line[0] && line[0] == '-')
        i++;
    for (; line[i] && (line[i] != ',' && line[i] != '\n') && !stop; i++) {
        if (line[i] == '.')
            dot++;
        else if (!is_number(line[i]))
            stop = 1;
        else
            len++;
    }
    if (dot != 1 || len < 1)
        return (-1);
    return (1);
}
