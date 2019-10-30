/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** my_putstr
*/

unsigned short my_putchar(char const c);

unsigned short my_putstr(char const *str)
{
    unsigned short id;

    for (unsigned int i = 0; str[i]; i++) {
        id = my_putchar(str[i]);
        if (id == 84)
            return (84);
    }
    return (0);
}
