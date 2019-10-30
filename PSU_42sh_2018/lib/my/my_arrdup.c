/*
** EPITECH PROJECT, 2018
** my_arrdup
** File description:
** my array duplicator
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);

char **my_arrdup(char **arr, int size)
{
    char **dup;
    int line_size = 0;
    int j = 0;

    dup = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++)
        if (my_strlen(arr[i]) > line_size)
            line_size = my_strlen(arr[i]);
    for (int i = 0; i < size; i++)
        dup[i] = malloc(sizeof(char) * line_size);
    for (; j < size; j++)
        my_strcpy(dup[j], arr[j]);
    dup[j] = NULL;
    return (dup);
}
