/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** creates and deletes list
*/

#include <stdlib.h>
#include "linked_list.h"

//Returns a pointer to an empty list with no name
list_t *create_empty_list(void)
{
    list_t *new_list = NULL;

    new_list = malloc(sizeof(list_t));
    if (!new_list)
        return (NULL);
    new_list->nb_elements = 0;
    new_list->name = NULL;
    new_list->head = NULL;

    return (new_list);
}

//Destroys the whole list
void delete_list(list_t *list)
{
    node_t *current = list->head->prev;
    node_t *tmp = NULL;

    while (current != list->head) {
        tmp = current->prev;
        delete_node(current);
        current = tmp;
    }
    delete_node(list->head);
    free(list->name);
    free(list);
}
