/*
** EPITECH PROJECT, 2017
** my_puterr
** File description:
** oui
*/

unsigned short my_putchar_err(char const c);

unsigned short my_puterr(char const *str)
{
    unsigned short id;

    for (unsigned int i = 0; str[i]; i++) {
        id = my_putchar_err(str[i]);
        if (id == 84)
            return (84);
    }
    return (0);
}
