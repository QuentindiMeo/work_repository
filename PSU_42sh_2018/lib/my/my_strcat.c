/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    unsigned int i = 0;
    unsigned int j = 0;

    for (; dest[j]; j++);
    for (; src[i]; i++) {
        dest[j] = src[i];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
