/*
** EPITECH PROJECT, 2019
** personal
** File description:
** my_cut_str
*/

#include <stdlib.h>

char *my_cut_str(char const *str, int const start, int const end)
{
    char *new = NULL;
    unsigned int i = start;
    unsigned int j = 0;

    if (end < start)
        return (NULL);
    new = malloc(sizeof(char) * (end - start + 2));
    if (!new)
        return (NULL);
    for (; str[i] && i != end; i++) {
        new[j] = str[i];
        j++;
    }
    if (str[i]) {
        new[j] = str[i];
        j++;
    }
    new[j] = 0;
    return (new);
}
