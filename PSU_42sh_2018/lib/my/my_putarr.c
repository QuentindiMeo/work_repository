/*
** EPITECH PROJECT, 2018
** my_putarr
** File description:
** my put array
*/

unsigned short my_putchar(char const c);
unsigned short my_putstr(char const *str);

unsigned short my_putarr(char **arr, char separator)
{
    unsigned short id = 0;

    for (unsigned int i = 0; arr[i][0]; i++) {
        id = my_putstr(arr[i]);
        if (arr[i + 1][0])
            my_putchar(separator);
        if (id == 84)
            return (84);
    }
    return (0);
}
