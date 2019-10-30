/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** int to str converter
*/

#include <stdlib.h>

void my_charcat(char *, char);

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 12);
    int modulo_pow = 1;

    str[0] = '\0';
    while (modulo_pow <= (nb / 10))
        modulo_pow *= 10;
    while (modulo_pow > 0) {
        my_charcat(str, nb / modulo_pow + '0');
        nb %= modulo_pow;
        modulo_pow /= 10;
    }
    return (str);
}
