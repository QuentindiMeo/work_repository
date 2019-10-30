/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** match stick main
*/

#include "../include/my.h"
#include "../include/matchstick.h"
#include <stdio.h>

static int help(void)
{
    my_putstr("Usage:\n  ./matchstick [number of lines] "
                "[maximum matches to be taken per round]\n\n"
                "  The number of lines musts be as \"1 < n < 100\".\n"
                "  The number of maximum matches to be taken per round "
                "be as \"n > 0\".\n");
    return (SUCCESS);
}

static int args_aint_numerical(char *s1, char *s2)
{
    uint ctr = 0;

    for (uint i = 0; s1[i]; i++)
        if (!((s1[i] >= 48 && s1[i] <= 57) || (s1[i] == '-')))
            ctr++;
    for (uint i = 0; s2[i]; i++)
        if (!((s2[i] >= 48 && s2[i] <= 57) || (s2[i] == '-')))
            ctr++;
    if (ctr)
        return (TRUE);
    return (FALSE);
}

static int winning(int id)
{
    if (id == USER) {
        my_putstr("\nI lost... snif... but I'll get you next time!!\n");
        return (W_USER);
    } else {
        my_putstr("\nYou lost, too bad...\n");
        return (W_AI);
    }
}

static int matchstick(int lines, int max_matches)
{
    data *game = mallocator(lines);
    int winner;
    uint i = 0;

    fill_board(game, lines);
    fill_matches_array(game, lines, max_matches);
    for (; i <= lines; i++) {
        my_putstr(game->board[i]);
        my_putchar('\n');
    }
    my_putstr(game->board[i]);
    winner = game_loop(game, lines);
    freer(game, lines);
    if (winner == EOF)
        return (EOF);
    if (winner == USER)
        return (W_USER);
    return (W_AI);
}

int main(int ac, char **av)
{
    int winner;

    if (ac < 2)
        return (err_arguments());
    if ((av[1][0] == '-' && av[1][1] == '-' && av[1][2] == 'h' && !av[2] &&
        av[1][3] == 'e' && av[1][4] == 'l' && av[1][5] == 'p' && !av[1][6]) ||
        (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2] && !av[2]))
        return (help());
    if (ac != 3 || args_aint_numerical(av[1], av[2]))
        return (err_arguments());
    if ((my_getnbr(av[1]) < 2 || my_getnbr(av[1]) > 99) ||
        my_getnbr(av[2]) < 1)
        return (err_arguments());
    winner = matchstick(my_getnbr(av[1]), my_getnbr(av[2]));
    if (winner == USER)
        return (winning(USER));
    if (winner == AI)
        return (winning(AI));
    return (SUCCESS);
}
