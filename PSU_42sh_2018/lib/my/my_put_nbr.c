/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put nbr
*/

#include <unistd.h>

unsigned int my_compute_power_rec(int nb, int p);

unsigned int size_nb(int const nb)
{
    int tmp = nb;
    unsigned int size = 0;

    if (tmp > 9)
        while (tmp > 9) {
            tmp = nb / my_compute_power_rec(10, size);
            size++;
        }
    else
        size = 1;
    return (size);
}

void display(int const nb)
{
    int ascii;

    ascii = 48 + nb;
    write(1, &ascii, 1);
}

void split_nbr(int nbr)
{
    int p = size_nb(nbr);
    int cursor = 0;
    int power = 0;
    int recup = 0;
    int splitted = 0;

    while (p != 0) {
        p--;
        cursor = nbr / my_compute_power_rec(10, p);
        power = cursor * my_compute_power_rec(10, p);
        power -= recup;
        recup += power;
        splitted = power / my_compute_power_rec(10, p);
        display(splitted);
    }
}

unsigned short my_put_nbr(int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb == 2147483648) {
        split_nbr(2147483648);
        return (0);
    }
    split_nbr(nb);
    return (0);
}
