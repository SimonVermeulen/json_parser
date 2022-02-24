/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets a double from the given line
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "linked_list.h"
#include "json_parser.h"

//Gets a single double from the current line
static int get_nb(const char *line, int index, double *result)
{
    int len = 0;

    for (; line[len] && is_number(line[len]) || line[len] == '.'; len++);
    result[index] = atof(line);
    return (len);
}

//Fills a double array from the current line
static int get_double_array(const char *line, int nb_elements, double *result)
{
    int len = 0;

    for (int i = 0; i < nb_elements; i++) {
        len += get_nb(&line[len], i, result);
        if (line[len] && line[len] != ',' && i != nb_elements - 1) {
            write(2, "Error: expected a ','\n", 23);
            return (-1);
        } else if (i != nb_elements - 1) {
            len++;
        }
    }
    return (len);
}

//Gets a double from line and sets it to new_node
int get_double(const char *line, node_t *new_node, int nb_elements)
{
    int len = 0;
    double *result = NULL;

    new_node->len = (nb_elements == 0) ? 1 : nb_elements;
    if (nb_elements == 0)
        result = malloc(sizeof(double));
    else
        result = malloc(sizeof(double) * (nb_elements));
    if (!result)
        return (-1);
    if (nb_elements == 0)
        len = get_nb(line, 0, result);
    else
        len = get_double_array(line, nb_elements, result);
    if (len < 0)
        return (-1);
    new_node->value = result;
    return (len);
}
