/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** main file for json_parsing
*/

#include <stdlib.h>
#include "json_parser.h"
#include "my.h"

int main(int ac, char **av)
{
    char **buffer = NULL;

    if (ac < 2)
        return (84);
    buffer = get_line_array(av[1]);
    for (int i = 0; buffer[i]; i++) {
        printf("%s\n", buffer[i]);
    }
    //if (buffer)
      //  get_data(buffer);
}
