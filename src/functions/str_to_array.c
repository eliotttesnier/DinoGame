/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** str_to_array
*/

#include "header.h"
#include <stdbool.h>

int is_ban(char letter, char *ban)
{
    for (int i = 0; ban[i] != '\0'; i++) {
        if (letter == ban[i])
            return (1);
    }
    if (letter == '\0')
        return (1);
    return (0);
}

int first_char(char *av, char *ban)
{
    int i = 0;

    for (i = 0; av[i] != '\0'; i++) {
        if (is_ban(av[i], ban) == 0)
            return i;
    }
    return (i);
}

static int nb_condition(char c, char *ban, bool quotes)
{
    if ((is_ban(c, ban) != 1 || quotes == true) && c != '\0')
        return (1);
    return (0);
}

int nb_letters(char *str, int ind, char *ban)
{
    bool quotes = false;
    int nb = 0;

    if (ind != 0)
        if (str[ind - 1] == '"')
            quotes = true;
    for (int i = ind; nb_condition(str[i], ban, quotes) == 1; i++) {
        if (str[i] == '"')
            quotes = !quotes;
        if (str[i] != '"')
            nb += 1;
    }
    return (nb);
}

int nb_words(char *arg, char *ban)
{
    bool quotes = false;
    int nb = 0;

    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == '"')
            quotes = !quotes;
        if (is_ban(arg[i], ban) == 0 && is_ban(arg[i + 1], ban) == 1
            && quotes == false)
            nb += 1;
    }
    return (nb);
}

static int last_condition(char c, char *ban)
{
    if ((is_ban(c, ban) == 1 || c == '"') && c != '\0')
        return (1);
    return (0);
}

char **str_to_array(char *av, char *ban)
{
    int words = nb_words(av, ban);
    char **arr = malloc(sizeof(char *) * (words + 1));
    int letters = 0;
    int ind = first_char(av, ban);

    arr[words] = NULL;
    for (int i = 0; i < words; i++) {
        letters = nb_letters(av, ind, ban);
        arr[i] = malloc(sizeof(char) * (letters + 1));
        for (int j = 0; j < letters && av[ind] != '\0'; j++) {
            arr[i][j] = (av[ind] == '"' ? arr[i][j] : av[ind]);
            j -= (av[ind] == '"' ? 1 : 0);
            ind += 1;
        }
        arr[i][letters] = '\0';
        for (ind = ind; last_condition(av[ind], ban) == 1; ind++);
    }
    return (words > 0 ? arr : NULL);
}
