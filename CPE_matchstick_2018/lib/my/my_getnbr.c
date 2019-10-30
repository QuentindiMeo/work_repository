/*
** EPITECH PROJECT, 2018
** CPool_Day06_2018
** File description:
** my_getnbr
*/

unsigned int my_compute_power_rec(int nb, int p);
int ctoi(char const c);

static unsigned short isanbr(char nbr)
{
    int value = 0;

    if (nbr >= '0' && nbr <= '9')
        value = 1;
    else if (nbr == '-' || nbr == '+')
        value = 2;
    else
        value = 0;
    return (value);
}

static int findnbr(char const *str)
{
    unsigned int i = 0;

    while (isanbr(str[i]) > 0) {
        if (isanbr(str[i]) == 1)
            return (i);
        i++;
    }
    return (0);
}

static unsigned int nbrlen(char const *str)
{
    unsigned int i = findnbr(str);
    unsigned int size = 0;

    while (isanbr(str[i]) == 1) {
        i++;
        size++;
    }
    return (size);
}

int my_getnbr(char const *str)
{
    int result = 0;
    int i = findnbr(str);
    char op;
    unsigned int integer = 0;
    unsigned int total = 0;

    if (i >= 0)
        op = str[i - 1];
    for (int p = nbrlen(str) - 1; isanbr(str[i]) == 1; p--) {
        integer = ctoi(str[i]);
        if (integer > 2 && p >= 9)
            return (0);
        integer *= my_compute_power_rec(10, p);
        total += integer;
        i++;
    }
    result = total;
    if (op == '-')
        result *= -1;
    return (result);
}
