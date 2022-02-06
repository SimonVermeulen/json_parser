/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** main file for json_parsing
*/

#include <stdlib.h>
#include <unistd.h>
#include "json_parser.h"
#include "linked_list.h"
#include "my.h"

//creates and gets the infos of a node from a line
static node_t *get_node(char *line, int line_index)
{
    node_t *new_node = NULL;
    int index = 0;

    new_node = malloc(sizeof(node_t));
    if (!new_node)
        return (NULL);
    index = set_key(line, new_node, line_index);
    set_value(&line[index], new_node, line_index);

    return (new_node);
}

//gets the whole data from a json file in a linked_list
list_t *get_data(char **buffer)
{
    list_t *list = NULL;
    node_t *tmp = NULL;

    for (int i = 0; buffer[i]; i++) {
        if (is_emptyline(buffer[i])) {
            tmp = get_node(buffer[i], i);
            my_printf(1, "key = %s\n", tmp->key);
            switch (tmp->type)
            {
            case 0:
                my_printf(1, "char == %c\n", *(char *)tmp->value);
                break;
            case 1:
                my_printf(1, "string == %s\n", (char *)tmp->value);
                break;
            case 2:
                my_printf(1, "int == %d\n", *(int *)tmp->value);
                break;
            case 3:
                printf("float == %f\n", *(double *)tmp->value);
                break;
            }
            printf("\n");
            free(tmp->key);
            free(tmp);
        }
    }
    return (NULL);
}

/*
    - [ : array 1
    - { : object 2
    - [{ : array of objects 3
    - " strings ou char 4 5
    - number without . : int 6
    - number with . : float 7
*/
