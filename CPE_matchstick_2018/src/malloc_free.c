/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** matchstick malloc free
*/

#include "../include/my.h"
#include "../include/matchstick.h"
#include <stdlib.h>

static data *alt_free(char **array, int i)
{
    for (i--; i > 0; i--)
        free(array[i]);
    free(array);
    return (NULL);
}

void freer(data *game, int lines)
{
    for (uint i = 0; i < lines + 2; i++)
        free(game->board[i]);
    free(game->board);
    free(game->matches);
    free(game);
}

data *mallocator(int lines)
{
    data *game = malloc(sizeof(data));
    uint height = lines + 2;
    uint length = 2 * lines + 1;

    if (!game)
        return (NULL);
    game->board = malloc(sizeof(char *) * height);
    if (!game->board)
        return (NULL);
    for (uint i = 0; i < height; i++) {
        game->board[i] = malloc(sizeof(char) * length);
        if (!game->board[i])
            return (alt_free(game->board, i));
    }
    game->matches = malloc(sizeof(int) * height - 2);
    return (game);
}
