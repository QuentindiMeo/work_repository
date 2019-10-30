/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_arr_add
*/
#include <stdlib.h>

char **my_arr_add(char **old, char *new_line)
{
    int size;
    char **new;

    for (size = 0; old[size]; size++);
    new = malloc(sizeof(char *) * (size + 2));
    for (int i = 0; i != size; i++)
        new[i] = old[i];
    new[size] = new_line;
    new[size + 1] = NULL;
    return (new);
}