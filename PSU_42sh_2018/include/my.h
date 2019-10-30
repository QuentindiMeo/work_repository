/*
** EPITECH PROJECT, 2018
** CPool_Day09_2018
** File description:
** my library headers
*/

#ifndef MY_H_
#define MY_H_

typedef enum {
    SUCCESS = 0,
    FAILURE = 84,
    TRUE = 1,
    FALSE = 0,
    YES = 1,
    NO = 0,
    ERROR = -1,
} return_values_t;

typedef unsigned int uint;
typedef unsigned char uchar;

unsigned short my_putchar(char const);
unsigned short my_putchar_err(char const);
unsigned short my_putstr(char const *);
unsigned short my_puterr(char const *);
unsigned int my_strlen(char const *);
unsigned int my_compute_power_rec(int, int);
int my_getnbr(char const *);
int my_str_isequal(char const *, char const *);
unsigned short my_put_nbr_err(int);
unsigned short my_put_nbr(int);
char **my_str_to_word_array(char const *);
char *my_strcpy(char *, char const *);
void my_charcat(char *, char const);
char *my_strcat(char *, char const *);
char *my_strdup(char const *);
unsigned short my_putarr(char **array, char separator);
char **my_arrdup(char **array, int array_size);
char **my_arrdup_enlarge(char **array, int array_size, int enlargement);
char **my_arr_add(char **array, char *string_to_add);
char **my_cut_word_array(char **array, int const start, int const end);
char *my_cut_str(char const *str, int const start, int const end);
int my_str_startswith(char const *s1, char const *s2);
int my_array_startswith(char *gtl, char **command);

char *my_itoa(int integer_to_convert);
int ctoi(char const);
char itoc(int const);
char *ctos(char const);
char stoc(char const *);

#endif
