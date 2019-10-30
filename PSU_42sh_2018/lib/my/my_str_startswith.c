/*
** EPITECH PROJECT, 2018
** personal
** File description:
** my_str_startswith
*/

unsigned int my_strlen(char const *);

int my_str_startswith(char const *s1, char const *s2)
{
    int check = 0;
    int s_len = my_strlen(s2);

    if (my_strlen(s1) < my_strlen(s2))
        return (0);
    for (int i = 0; i < s_len; i++)
        if (s1[i] == s2[i])
            check++;
    if (check == s_len)
        return (1);
    return (0);
}
