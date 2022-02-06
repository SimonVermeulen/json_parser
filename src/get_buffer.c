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
    char **tmp_buffer = NULL;
    static int nb_lines = 1;
    int len = 0;

    nb_lines++;
    tmp_buffer = malloc(sizeof(char *) * nb_lines);
    if (!tmp_buffer)
        return (NULL);
    if (buffer) {
        for (; buffer[len]; len++) {
            printf("len == %d\tbuffer[%d] == %s\n", len, len, buffer[len]);
            tmp_buffer[len] = buffer[len];
        }
        tmp_buffer[len] = line;
        free(buffer);
    } else {
        tmp_buffer[0] = line;
    }
    tmp_buffer[nb_lines - 1] = NULL;
    buffer = tmp_buffer;
    return (buffer);
}

char **get_line_array(char *path)
{
    FILE *fd = fopen(path, "r");
    char *line = NULL;
    char **buffer = NULL;
    size_t size = 0;
    size_t llen = 0;

    while ((llen = getline(&line, &size, fd)) != (size_t) -1) {
        buffer = add_line(line, buffer);
        printf("after attribution:\n");
        for (int i = 0; buffer[i]; i++) {
            printf("buffer[%d] = %s\n", i, buffer[i]);
        }
    }
    return (buffer);
}
