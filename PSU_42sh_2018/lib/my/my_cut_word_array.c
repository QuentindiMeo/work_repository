/*
** EPITECH PROJECT, 2018
** personal
** File description:
** my_cut_array
*/

#include <stdlib.h>

char *my_strcpy(char *, char const *);

static unsigned int my_strlen(char const *str)
{
    unsigned int i = 0;

    for (; str[i]; i++);
    return (i);
}

static unsigned short isletter(char const c)
{
    if (c > 32 && c < 127)
        return (1);
    return (0);
}

static unsigned int max_size(char **array)
{
    unsigned int max = 0;

    for (uint i = 0; array[i] && array[i][0]; i++)
        if (max < my_strlen(array[i]))
            max = my_strlen(array[i]);
    return (max);
}

char **my_cut_word_array(char **array, int const start, int const end)
{
    unsigned short g = 0;
    unsigned short i = 0;
    unsigned char size = end - start + 2;
    unsigned short str_size = max_size(array);
    char **arr = malloc(sizeof(char *) * size);

    for (unsigned char a = start - 1; g < size - 1; g++) {
        arr[g] = malloc(sizeof(char) * (str_size + 1));
        my_strcpy(arr[g], array[a]);
        a++;
        arr[g][my_strlen(arr[g])] = '\0';
    }
    arr[g] = NULL;
    return (arr);
}
