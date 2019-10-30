/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my array starts with
*/

#include <stdlib.h>

unsigned int my_strlen(char const *str);
char **my_str_to_word_array(char const *str);
char *my_cut_str(char const *str, int const start, int const end);
int my_str_startswith(char const *s1, char const *s2);

int my_array_startswith(char *gtl, char **command)
{
    char **entry = my_str_to_word_array(gtl);
    char *new = command[0][0] == '!' ?
                my_cut_str(command[0], 1, my_strlen(command[0])) :
                my_cut_str(command[0], 0, my_strlen(command[0]));
    int ret_v = 0;

    if (my_str_startswith(entry[0], new))
        ret_v = 1;
    for (int i = 0; entry[i]; i++)
        free(entry[i]);
    free(entry);
    free(new);
    return (ret_v);
}
