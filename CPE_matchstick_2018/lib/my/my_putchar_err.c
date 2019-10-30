/*
** EPITECH PROJECT, 2017
** my_putchar_err
** File description:
** putchar
*/

#include <unistd.h>

unsigned short my_putchar_err(char const c)
{
    if (write(2, &c, 1) == -1)
        return (84);
    return (0);
}
