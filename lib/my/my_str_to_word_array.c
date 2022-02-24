/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** gets each word of a string with specifics delims
*/

#include <stdlib.h>
#include "my.h"

static int is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return (1);
    return (0);
}

static int count_words(char const *str, char const *delim)
{
    int nb_words = 0;
    int is_word = 0;

    for (int i = 0; str[i]; i++) {
        if (is_delim(str[i], delim))
            is_word = 0;
        else
            is_word++;
        nb_words += (is_word == 1) ? 1 : 0;
    }
    return (nb_words);
}

static char *set_word(char const *str, char const *delim, int in)
{
    char *word = NULL;
    int windex = 0;
    int len = 0;

    for (int i = in; str[i] && !is_delim(str[i], delim); i++, len++);
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        word = NULL;
    else
        for (int i = in; str[i] && !is_delim(str[i], delim); i++, windex++)
            word[windex] = str[i];
    word[windex] = '\0';
    return (word);
}

char **my_str_to_word_array(char const *str, char const *delim)
{
    int nb_words = count_words(str, delim);
    char **array = NULL;
    int is_word = 0;
    int index = 0;

    array = malloc(sizeof(char *) * (nb_words + 1));
    if (!array)
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if (is_delim(str[i], delim)) {
            is_word = 0;
        } else if (!is_word) {
            array[index++] = set_word(str, delim, i);
            is_word = 1;
        }
    }
    array[nb_words] = NULL;
    return (array);
}
