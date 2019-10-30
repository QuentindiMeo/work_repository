/*
** EPITECH PROJECT, 2018
** personal
** File description:
** my_str_isequal
*/

unsigned int my_strlen(char const *);

int my_str_isequal(char const *s1, char const *s2)
{
    int check = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    for (int i = 0; s1[i]; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}
