/*
** EPITECH PROJECT, 2018
** CPool_Day03_2018
** File description:
** my_putchar
*/

#include <unistd.h>

unsigned short my_putchar(char const c)
{
    if (write(1, &c, 1) == -1)
        return (84);
    return (0);
}
