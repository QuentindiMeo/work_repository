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
typedef unsigned short ushort;
typedef unsigned long ulong;

unsigned short my_putchar(char const c);
unsigned short my_putchar_err(char const c);
unsigned short my_putstr(char const *str);
unsigned short my_puterr(char const *str);
unsigned short my_putarr(char **arr, char);
unsigned int my_strlen(char const *str);
unsigned int my_compute_power_rec(int nb, int p);
int my_getnbr(char const *str);

int ctoi(char const c);
char itoc(int const i);
char *ctos(char const c);
char stoc(char const *s);


unsigned int size_nb(int const nb);
void display(int nb);
void split_nbr(int nbr);
unsigned short my_put_nbr(int nb);

#endif
