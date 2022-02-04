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

static size_t get_size(char *path)
{
    FILE *fd = fopen(path, "r");
    char *line = NULL;
    size_t size = 0;
    size_t llen = 0;
    size_t len = 0;

    while ((llen = getline(&line, &size, fd)) != (size_t) -1)
        len += llen;
    return (len);
}

char *get_buffer(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buffer = NULL;
    size_t len = 0;

    if (fd < 0) {
        write(2, "Could not open the file\n", 25);
        return (NULL);
    }
    len = get_size(path);
    buffer = malloc(sizeof(char) * (len + 1));
    read(fd, buffer, len);
    return (buffer);
}
