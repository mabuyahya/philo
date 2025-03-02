
#include "philo.h"

int ft_strlen_matrix(char **str)
{
    int i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

char **ft_strdup_matrix(char **str)
{
    char **new_str;
    int i;

    i = 0;
    new_str = malloc(ft_strlen_matrix(str) + 1);
    while (str[i])
    {
        new_str[i] = ft_strdup(str[i]);
        i++;
    }
    new_str[i] = NULL;
    return (new_str);
}