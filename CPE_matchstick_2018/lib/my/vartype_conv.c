/*
** EPITECH PROJECT, 2018
** vartype_converter
** File description:
** variables type converters
*/

#include <stdlib.h>

char *ctos(char const c)
{
    char *s = malloc(sizeof(char) * 2);

    s[0] = c;
    s[1] = '\0';
    return (s);
}

char stoc(char const *s)
{
    return (s[0]);
}

int ctoi(char const c)
{
    return (c - 48);
}

char itoc(int const i)
{
    return (i + 48);
}
