/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:28:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/06 11:09:48 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen_matrix(char **str)
{
    int i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

int check_____if____someone____is____dead(t_philosofre *philo)
{
    pthread_mutex_lock(philo->main->someone_else_dead_mutex);
    if (philo->someone_else_dead)
    {
        pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
        return (1);
    }
    pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
    return (0);
}

int safe_printf(t_philosofre *philo, char *str, char *color)
{
    if (check_____if____someone____is____dead(philo))
    {
        return (1);
    }
    pthread_mutex_lock(philo->main->printf_mutex);
    printf("%s%ld %d %s\033[0m\n", color, ft_gettimeofsim(philo), philo->num + 1, str);
    pthread_mutex_unlock(philo->main->printf_mutex);
    return (0);
}
char **ft_strdup_matrix(char **str)
{
    char **new_str;
    int i;

    i = 0;
    new_str = malloc((ft_strlen_matrix(str) + 1) * sizeof(char *));
    while (str[i])
    {
        new_str[i] = ft_strdup(str[i]);
        i++;
    }
    new_str[i] = NULL;
    return (new_str);
}