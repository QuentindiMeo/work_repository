/*
** EPITECH PROJECT, 2018
** CPool_Day08_2018
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dup = malloc(sizeof(char) * my_strlen(src));

    return (my_strcpy(dup, src));
}
