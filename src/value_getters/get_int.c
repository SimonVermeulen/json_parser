/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets an int from the given line
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "linked_list.h"
#include "json_parser.h"

//Gets a single int from the current line
static int get_nb(const char *line, int index, int *array)
{
    int len = 0;

    for (; line[len] && is_number(line[len]); len++);
    array[index] = atoi(line);
    return (len);
}

//Fills an int array from the current line
static int get_int_array(const char *line, int nb_elements, int *array)
{
    int len = 0;

    for (int i = 0; i < nb_elements; i++) {
        len += get_nb(&line[len], i, array);
        if (line[len] && line[len] != ',' && i != nb_elements - 1) {
            write(2, "Error: expected a ','\n", 23);
            return (-1);
        } else if (i != nb_elements - 1) {
            len++;
        }
    }
    return (len);
}

//Gets an int from line and sets it to new_node
int get_int(const char *line, node_t *new_node, int nb_elements)
{
    int len = 0;
    int *result = NULL;

    new_node->len = (nb_elements == 0) ? 1 : nb_elements;
    if (nb_elements == 0)
        result = malloc(sizeof(int));
    else
        result = malloc(sizeof(int) * (nb_elements));
    if (!result)
        return (-1);
    if (nb_elements == 0)
        len = get_nb(line, 0, result);
    else
        len = get_int_array(line, nb_elements, result) + 1;
    if (len < 0)
        return (-1);
    new_node->value = result;
    return (len);
}
