/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** match stick detectors 2
*/

#include "../include/my.h"
#include "../include/matchstick.h"

static int not_enough_matches(char *str, int played_line, int played_matches)
{
    int matches = 0;

    for (uint i = 1; str[i] != '*'; i++)
        if (str[i] == '|')
            matches++;
    if (played_matches > matches)
        return (TRUE);
    return (FALSE);
}

int played_matches_invalid(data *game, int lines, char *entry)
{
    uint ctr = 0;

    for (uint i = 0; entry[i + 1]; i++)
        if (!((entry[i] >= 48 && entry[i] <= 57) || (entry[i] == '-' && !i)))
            ctr++;
    if (game->played_matches < 1 && !ctr)
        return (err_positive_matches());
    if (ctr)
        return (err_positive_expected(2));
    if (game->played_matches > game->max_matches) {
        my_puterr("Error: you cannot remove more than ");
        my_put_nbr(game->max_matches);
        ctr = game->max_matches;
        my_puterr((ctr > 1) ? " matches per turn\n" : " match per turn\n");
        return (TRUE);
    }
    if (not_enough_matches(game->board[game->played_line],
                            game->played_line, game->played_matches))
        return (err_not_enough_matches());
    return (FALSE);
}

int line_is_out_of_range(int played_line, int lines, char *entry)
{
    uint ctr = 0;

    for (uint i = 0; entry[i + 1]; i++)
        if (!((entry[i] >= 48 && entry[i] <= 57) || (entry[i] == '-' && !i)))
            ctr++;
    if ((played_line > lines && !ctr) || (played_line < 1 && !ctr))
        return (err_out_of_range());
    if (ctr)
        return (err_positive_expected(1));
    return (FALSE);
}
