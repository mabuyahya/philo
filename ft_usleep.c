/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:47:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/18 06:16:05 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

extern pthread_mutex_t printf_mutex;
extern pthread_mutex_t philo_dead_mutex;

int ft_usleep(int time, t_philosofre *philo)
{
    long start_time;

    start_time = ft_gettimeofsim(philo);
    pthread_mutex_lock(&philo_dead_mutex);
    if (philo->dead)
    {
        pthread_mutex_unlock(&philo_dead_mutex);
        return (1);
    }
    pthread_mutex_unlock(&philo_dead_mutex);
    while (ft_gettimeofsim(philo) - start_time < time)
    {
        if (ft_gettimeofsim(philo) - philo->time_of_last_meal > philo->main->time_to_die)
        {
            pthread_mutex_lock(philo->main->dead_mutex);
            philo->main->dead = 1;
            pthread_mutex_lock(&printf_mutex);
                printf("[%li]    philo number %i died\n", ft_gettimeofsim(philo), philo->num + 1);
            pthread_mutex_unlock(&printf_mutex);
            pthread_mutex_unlock(philo->main->dead_mutex);
            return (1);
        }
        usleep(100);
    }
    return (0);
}