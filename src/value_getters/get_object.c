/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets object from a given line
*/

#include <unistd.h>
#include <stdlib.h>
#include "json_parser.h"
#include "linked_list.h"

static int get_line_infos(const char *line, node_t *tmp,
    int len)
{
    len = get_key(line, len, tmp);
    if (len < 0)
        return (-1);
    len = get_value(line, len, tmp);
    if (len < 0)
        return (-1);
    return (len);
}

static int get_single_object(const char *line, node_t *new_node)
{
    node_t *tmp = NULL;
    list_t *list = NULL;
    int len = 1;

    if (line[0] && line[0] != '{') {
        write(2, "Error: expected a '{'\n", 23);
        return (-1);
    }
    list = create_empty_list();
    if (!list)
        return (-1);
    for (; line[len] && line[len] != '}';) {
        tmp = create_newnode(list->nb_elements);
        len = get_line_infos(line, tmp, len);
        if (len < 0)
            return (-1);
        push_element(list, tmp);
    }
    new_node->value = list;
    return (len);
}

static int get_object_array(const char *line, node_t *new_node,
    int nb_elements, list_t **list_array)
{
    int len = 0;

    for (int i = 0; i < nb_elements; i++) {
        len += get_single_object(&line[len], new_node);
        if (len < 0)
            return (-1);
        list_array[i] = (list_t *)new_node->value;
        if (line[len] && line[len] != '}') {
            write(2, "Error: expected a '}'\n", 23);
            return (-1);
        }
        len++;
        if (line[len] && line[len] != ',' && i != nb_elements - 1) {
            write(2, "Error: expected a ','\n", 23);
            return (-1);
        }
        len++;
    }
    return (len);
}

int get_object(const char *line, node_t *new_node, int nb_elements)
{
    int len = 0;
    list_t **list_array = NULL;

    new_node->len = (nb_elements == 0) ? 1 : nb_elements;
    if (nb_elements == 0) {
        len = get_single_object(line, new_node);
    } else {
        list_array = malloc(sizeof(list_t *) * (nb_elements + 1));
        len = get_object_array(&line[0], new_node, nb_elements, list_array);
        list_array[nb_elements] = NULL;
        new_node->value = list_array;
    }
    return (len);
}
