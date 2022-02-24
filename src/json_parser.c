/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** main file for json_parsing
*/

#include <stdlib.h>
#include <stdio.h>
#include "json_parser.h"
#include "my.h"

static void print_list(list_t *list)
{
    node_t *current = list->head;
    double *darray = NULL;
    int *iarray = NULL;
    char **sarray = NULL;
    list_t **l_array = NULL;

    for (int i = 0; i < list->nb_elements; i++) {
        printf("id = %d\tkey = %s", current->id, current->key);
        printf("\ttype = %d\tvalue = ", current->type);
        switch (current->type)
        {
        case 1:
            printf("\n");
            print_list((list_t *)current->value);
            printf("\n");
            break;
        case 2:
            printf("%f\n", *(double *)current->value);
            break;
        case 3:
            printf("%d\n", *(int *)current->value);
            break;
        case 4:
            printf("%s\n", (char *)current->value);
            break;
        case 10:
            l_array = (list_t **)current->value;
            printf("\n");
            for (int i = 0; i < current->len; i++) {
                printf("larray[%d] = \n", i);
                print_list(l_array[i]);
                printf("\n");
            }
            break;
        case 20:
            darray = (double *)current->value;
            printf("\n");
            for (int i = 0; i < current->len; i++)
                printf("darray[%d] = %f\n", i, darray[i]);
            break;
        case 30:
            iarray = (int *)current->value;
            printf("\n");
            for (int i = 0; i < current->len; i++)
                printf("iarray[%d] = %d\n", i, iarray[i]);
            break;
        case 40:
            sarray = (char **)current->value;
            printf("\n");
            for (int i = 0; i < current->len; i++)
                printf("sarray[%d] = %s\n", i, sarray[i]);
            break;
        default:
            break;
        }
        current = current->next;
    }
}

int main(int ac, char **av)
{
    char *buffer = NULL;
    list_t *list = NULL;

    if (ac < 2)
        return (84);
    buffer = get_buffer(av[1]);
    if (!buffer)
        return (84);
    if (stringify(&buffer))
        return (84);
    if (buffer) {
        list = get_data(&buffer[1]);
        print_list(list);
    }
    free(buffer);
}
