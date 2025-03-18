/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:01:55 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/05 03:52:59by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t printf_mutex = PTHREAD_MUTEX_INITIALIZER;

void *rotene(void *philo)
{
    // while (1)
    // {
        take_a_fork(philo);
        eating(philo);
        unlock_a_fork(philo);
        sleeping(philo);
        thinking(philo);
    // }
    return (NULL);
}
int eating(t_philosofre *philo)
{
    pthread_mutex_lock(&printf_mutex);
    printf("\033[1;31m%li   philo id %i is eating\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    pthread_mutex_unlock(&printf_mutex);
    philo->time_of_last_meal = ft_gettimeofsim(philo);
    ft_usleep(philo->main->time_to_eat, philo);
    return (0);
}
int sleeping(t_philosofre *philo)
{
    pthread_mutex_lock(&printf_mutex);
    printf("\033[1;33m%li   philo id %i is sleeping\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    pthread_mutex_unlock(&printf_mutex);
    ft_usleep(philo->main->time_to_sleep, philo);
    return (0);
}

int thinking(t_philosofre *philo)
{
    pthread_mutex_lock(&printf_mutex);
    printf("\033[0;35m%li   philo id %i is thinking\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    pthread_mutex_unlock(&printf_mutex);
    return (0);
}