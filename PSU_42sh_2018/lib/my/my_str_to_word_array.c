/*
** EPITECH PROJECT, 2018
** CPool_Day08_2018
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

static unsigned short isletter(char const c)
{
    if (c > 32 && c < 127)
        return (1);
    return (0);
}

static unsigned int count_str(char const *str)
{
    unsigned int i = 0;
    unsigned int count = 0;

    while (str[i]) {
        for (; str[i] && isletter(str[i]) == 0; i++);
        if (isletter(str[i]) > 0)
            count++;
        for (; str[i] && isletter(str[i]) > 0; i++);
    }
    return (count);
}

char ** my_str_to_word_array(char const *str)
{
    short i = 0;
    short g = 0;
    short a = 0;
    unsigned short size = count_str(str);
    int len;
    char **arr = malloc(sizeof(char *) * (size + 1));

    for (; a < size; a++) {
        for (; isletter(str[i]) == 0; i++);
        for (len = i; isletter(str[len]) != 0; len++);
        arr[a] = malloc(sizeof(char) * (len - i + 1));
        for (g = 0; isletter(str[i]) != 0; g++, i++) {
            arr[a][g] = str[i];
        }
        arr[a][g] = 0;
    }
    arr[a] = NULL;
    return (arr);
}
