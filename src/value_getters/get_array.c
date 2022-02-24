/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets an array from a line
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"
#include "json_parser.h"

static int get_nb_elements_others(const char *line)
{
    int is_quote = 0;
    int nb_elements = 0;

    for (int i = 0; line[i] && line[i] != ']'; i++) {
        if (line[i] == '"' && !is_quote)
            is_quote = 1;
        if (line[i] == '"' && is_quote)
            is_quote = 0;
        if (line[i] == ',' && !is_quote)
            nb_elements++;
    }
    nb_elements++;
    return (nb_elements);
}

static int get_nb_elements_object(const char *line)
{
    int level = 0;
    int nb_elements = 0;

    for (int i = 0; line[i] && line[i] != ']'; i++) {
        if (line[i] == '{' && !level)
            nb_elements++;
        if (line[i] == '{')
            level++;
        else if (line[i] == '}')
            level--;
    }
    return (nb_elements);
}

static int get_nb_elements(const char *line, node_t *new_node)
{
    int nb_elements = 0;

    if (new_node->type == 0) {
        write(2, "Error: unexpected type (array in an array)\n", 44);
        return (-1);
    } else if (new_node->type == 1) {
        nb_elements = get_nb_elements_object(line);
    } else {
        nb_elements = get_nb_elements_others(line);
    }
    return (nb_elements);
}

int get_array(const char *line, node_t *new_node, int useless)
{
    int (*getters[5])(const char *, node_t *, int) = {&get_array,
        &get_object, &get_double, &get_int, &get_string};
    int nb_elements = 0;
    int len = 0;

    useless++;
    check_type(&line[1], new_node);
    nb_elements = get_nb_elements(line, new_node);
    if (nb_elements < 0)
        return (-1);
    len = getters[new_node->type](&line[1], new_node, nb_elements);
    if (len < 0)
        return (-1);
    if (line[len] && line[len] != ']') {
        write(2, "Error: expected a ']'\n", 23);
        return (-1);
    }
    new_node->type *= 10;
    return (len + 1);
}
