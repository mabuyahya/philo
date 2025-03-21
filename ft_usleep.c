/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:47:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/21 14:19:19 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_usleep(int time, t_philosofre *philo)
{
    long start_time;

    start_time = ft_gettimeofsim(philo);
    while (ft_gettimeofsim(philo) - start_time < time)
    {
        pthread_mutex_lock(philo->main->someone_else_dead_mutex);
        if (philo->someone_else_dead)
        {
            pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
            return (1);
        }
        pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
        if (ft_gettimeofsim(philo) - philo->time_of_last_meal > philo->main->time_to_die)
        {
            pthread_mutex_lock(philo->main->i_am_dead_mutex);
            philo->main->i_am_dead = 1;
            pthread_mutex_unlock(philo->main->i_am_dead_mutex);
            pthread_mutex_lock(philo->main->printf_mutex);
            printf("[%li]    philo number %i died\n", ft_gettimeofsim(philo), philo->num + 1);
            pthread_mutex_unlock(philo->main->printf_mutex);
            return (1);
        }
        usleep(1);
    }
    return (0);
}