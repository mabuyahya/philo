/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotene.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:01:55 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/28 17:13:44 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *rotene(void *philo)
{
    while (1)
    {
        if (take_a_fork(philo))
            return (NULL);
        if (eating(philo))
            return (NULL);
        if (unlock_a_fork(philo))
            return (NULL);
        if (sleeping(philo))
            return (NULL);
        if (thinking(philo))
            return (NULL);
    }
    return (NULL);
}
void *monitor_philo(void *philoo)
{
	t_philosofre *philo;
    int waiting;
    philo = (t_philosofre *)philoo;
	while (1)
	{
		pthread_mutex_lock(philo->main->someone_else_dead_mutex);
		if (philo->someone_else_dead)
		{
			pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
        pthread_mutex_lock(philo->main->waiting_mutex);
        waiting = philo->waiting_for_fork;
        pthread_mutex_unlock(philo->main->waiting_mutex);
        if (waiting && ft_gettimeofsim(philo) - philo->time_of_last_meal > philo->main->time_to_die)
		{
			pthread_mutex_lock(philo->main->i_am_dead_mutex);
			philo->main->i_am_dead = 1;
			pthread_mutex_unlock(philo->main->i_am_dead_mutex);
			return (NULL);
		}
		usleep(1);
	}
	return (NULL);
}
int eating(t_philosofre *philo)
{
	pthread_mutex_lock(philo->main->someone_else_dead_mutex);
    if (philo->someone_else_dead)
    {
        pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
        unlock_a_fork(philo);
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
        usleep(0);
        unlock_a_fork(philo);
        return (1);
    }
    philo->meals_eaten++;
    if (philo->main->number_of_meals != -1 && philo->meals_eaten > philo->main->number_of_meals)
    {
        pthread_mutex_lock(philo->main->meals_flags_mutex);
        philo->main->meals_flags[philo->num] = 1;
        pthread_mutex_unlock(philo->main->meals_flags_mutex);
        unlock_a_fork(philo);
        return (1);
    }
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