/*
** EPITECH PROJECT, 2018
** my_charcat
** File description:
** char concatenate
*/

unsigned int my_strlen(char const *str);

void my_charcat(char *str, char const c)
{
    unsigned int len = my_strlen(str);

    str[len] = c;
    str[len + 1] = '\0';
}
