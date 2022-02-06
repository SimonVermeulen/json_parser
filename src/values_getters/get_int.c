/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets an int from the given line
*/

#include <stdlib.h>
#include "linked_list.h"
#include "my.h"

static int get_size(const char *line)
{
    int size = 0;

    for (; line[size] && line[size] != ','; size++);
    return (size);
}

static int get_result(const char *line, int size)
{
    int result = 0;
    int j = 0;

    for (int i = size - 1; i > -1; i--, j++)
        result += (line[j] - 48) * my_compute_power_rec(10, i);
    return (result);
}

//Gets an int from line and sets it to new_node
void get_int(const char *line, node_t *new_node)
{
    int *result = NULL;
    int size = 0;
    int sign = 0;

    result = malloc(sizeof(int));
    if (!result) {
        new_node->value = NULL;
        return;
    }
    if (line[0] == '-') {
        sign = 1;
        size = get_size(&line[1]);
        *result = get_result(&line[1], size);
    } else {
        size = get_size(line);
        *result = get_result(line, size);
    }
    *result = (sign) ? -(*result) : *result;
    new_node->value = result;
}
