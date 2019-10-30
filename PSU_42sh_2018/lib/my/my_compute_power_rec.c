/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** my_compute_power_rec
*/

unsigned int my_compute_power_rec(int nb, int p)
{
    unsigned int result = 0;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    result = my_compute_power_rec(nb, (p - 1)) * nb;
    return (result);
}
