/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** my_strlen
*/

unsigned int my_strlen(char const *str)
{
    unsigned int i = 0;

    for (; str[i]; i++);
    return (i);
}
