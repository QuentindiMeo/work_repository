/*
** EPITECH PROJECT, 2018
** my_arrdup
** File description:
** my array duplicator
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char **my_arrdup_enlarge(char **arr, int size, int enlarge)
{
    char **dup;
    int line_size = 0;
    int j = 0;

    dup = malloc(sizeof(char *) * (size + enlarge + 1));
    for (; j < size; j++)
        dup[j] = arr[j];
    dup[j] = NULL;
    return (dup);
}
