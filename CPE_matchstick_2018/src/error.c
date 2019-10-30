/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** match stick error functions
*/

#include "../include/my.h"

int err_not_enough_matches(void)
{
    my_puterr("Error: not enough matches on this line\n");
    return (TRUE);
}

int err_positive_matches(void)
{
    my_puterr("Error: you have to remove at least one match\n");
    return (TRUE);
}

int err_positive_expected(int id)
{
    if (id == 1) {
        my_puterr("Error: invalid input (positive number expected)\n");
        my_putstr("Line: ");
    } else
        my_puterr("Error: invalid input (positive number expected)\n");
    return (TRUE);
}

int err_out_of_range(void)
{
    my_puterr("Error: this line is out of range\n");
    my_putstr("Line: ");
    return (TRUE);
}

int err_arguments(void)
{
    my_puterr("Error: Invalid arguments.\n");
    return (FAILURE);
}
