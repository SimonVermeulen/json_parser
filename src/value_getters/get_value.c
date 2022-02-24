/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets the value of a given line
*/

#include <stdlib.h>
#include <unistd.h>
#include "json_parser.h"
#include "linked_list.h"
#include "my.h"

//Sets the value in the new_node
int get_value(const char *buffer, int index, node_t *tmp)
{
    int (*getters[5])(const char *, node_t *, int nb_elements) = {&get_array,
        &get_object, &get_double, &get_int, &get_string};

    check_type(&buffer[index], tmp);
    if (tmp->type < 0) {
        write(2, "Error: invalid type\n", 21);
        return (-1);
    }
    index += getters[tmp->type](&buffer[index], tmp, 0);
    if (index < 0)
        return (-1);
    if ((buffer[index] && buffer[index] != ',' &&
        buffer[index + 1] && buffer[index + 1] != '}') &&
        (buffer[index] != '}')) {
        write(2, "Error: expected a ','\n", 23);
        return (-1);
    }
    index += (buffer[index] && buffer[index] == '}') ? 0 : 1;
    return (index);
}
