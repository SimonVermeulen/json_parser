/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** adds and deletes elements in a list_t
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"

static int check_error(list_t *list, int is_delete)
{
    if (!list) {
        write(2, "The given list is not initialized or allocated\n", 48);
        return (1);
    }

    if (is_delete && list->nb_elements == 0) {
        write(2, "The list is empty", 18);
        return (1);
    }

    return (0);
}

//Adds an element at the end of the list
int push_element(list_t *list, node_t *data)
{
    node_t *tmp = NULL;

    if (check_error(list, 0))
        return (-1);
    list->nb_elements++;
    if (list->nb_elements == 0) {
        list->head = data;
        data->next = data->prev = data;
        return (0);
    }
    tmp = list->head->prev;
    data->prev = tmp;
    tmp->next = data;
    data->next = list->head;
    return (1);
}

//Adds an element at the beggining of the list
int unshift_element(list_t *list, node_t *data)
{
    node_t *tmp = NULL;

    if (check_error(list, 0))
        return (-1);
    list->nb_elements++;
    if (list->nb_elements == 0) {
        list->head = data;
        data->next = data->prev = data;
        return (0);
    }
    tmp = list->head;
    data->next = tmp;
    data->prev = tmp->prev;
    tmp->prev = data;
    return (1);
}

//Delete the last element of the list
int pop_element(list_t *list)
{
    node_t *tmp = NULL;

    if (check_error(list, 1))
        return (-1);
    list->nb_elements--;
    if (list->nb_elements > 1) {
        tmp = list->head->prev->prev;
        tmp->next = list->head;
    }
    delete_node(list->head->prev);
    if (tmp)
        list->head->prev = tmp;
    return (1);
}

//Delete the first element of the list
int shift_element(list_t *list)
{
    node_t *tmp = NULL;

    if (check_error(list, 1))
        return (-1);
    list->nb_elements--;
    if (list->nb_elements > 1) {
        tmp = list->head->next;
        tmp->prev = list->head->prev;
    }
    delete_node(list->head);
    if (tmp)
        list->head = tmp;
    return (1);
}
