/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** opens the json file given as parameter in main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "json_parser.h"
#include "my.h"

static char **add_line(char *line, char **buffer)
{
    char **new_buffer = NULL;
    static int nb_lines = 1;
    int len = 0;

    nb_lines++;
    new_buffer = malloc(sizeof(char *) * nb_lines);
    if (!new_buffer)
        return (NULL);
    if (buffer) {
        for (; buffer[len]; len++)
            new_buffer[len] = buffer[len];
        new_buffer[len] = my_strdup(line);
        free(buffer);
    } else {
        new_buffer[0] = my_strdup(line);
    }
    new_buffer[nb_lines - 1] = NULL;
    return (new_buffer);
}

char **get_line_array(char *path)
{
    FILE *fd = fopen(path, "r");
    char **buffer = NULL;
    char *line = NULL;
    size_t size = 0;

    while (getline(&line, &size, fd) != (ssize_t) -1) {
        buffer = add_line(line, buffer);
        if (!buffer) {
            write(2, "Malloc error\n", 14);
            return (NULL);
        }
    }
    free(line);
    fclose(fd);
    return (buffer);
}
