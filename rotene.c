/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotene.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:01:55 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/20 15:30:02 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *rotene(void *philo)
{
    while (1)
    {
        take_a_fork(philo);
        if (eating(philo))
            return (NULL);
        if (sleeping(philo))
            return (NULL);
        if (thinking(philo))
            return (NULL);
    }
    return (NULL);
}
int eating(t_philosofre *philo)
{
	pthread_mutex_lock(philo->main->someone_else_dead_mutex);
    if (philo->someone_else_dead)
    {
	pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
        return (1);
    }
	pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
    pthread_mutex_lock(philo->main->printf_mutex);
    printf("\033[1;31m%li   philo id %i is eating\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    pthread_mutex_unlock(philo->main->printf_mutex);
    philo->time_of_last_meal = ft_gettimeofsim(philo);
    if (ft_usleep(philo->main->time_to_eat, philo))
    {
        unlock_a_fork(philo);
        return (1);
    }
    unlock_a_fork(philo);
    return (0);
}
int sleeping(t_philosofre *philo)
{
	pthread_mutex_lock(philo->main->someone_else_dead_mutex);
    if (philo->someone_else_dead)
    {
	pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
        return (1);
    }
	pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
    pthread_mutex_lock(philo->main->printf_mutex);
    printf("\033[1;33m%li   philo id %i is sleeping\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    pthread_mutex_unlock(philo->main->printf_mutex);
    if (ft_usleep(philo->main->time_to_sleep, philo))
        return (1);
    return (0);
}

int thinking(t_philosofre *philo)
{
	pthread_mutex_lock(philo->main->someone_else_dead_mutex);
    if (philo->someone_else_dead)
    {
	pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
        return (1);
    }
	pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
    pthread_mutex_lock(philo->main->printf_mutex);
    printf("\033[0;35m%li   philo id %i is thinking\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    pthread_mutex_unlock(philo->main->printf_mutex);
    return (0);
}