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

// pthread_mutex_t test = PTHREAD_MUTEX_INITIALIZER;

void    eating(t_philosofre *philo)
{
    take_a_fork(philo);
    printf("\033[1;31m%i   philo id %i is eating\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    philo->time_of_last_meal = ft_gettimeofday();
    usleep((philo->main->time_to_eat * 999));
    pthread_mutex_lock(philo->main->dead);
    check_if_dead(philo, philo->time_of_last_meal);
    pthread_mutex_unlock(philo->main->dead);
    unlock_a_fork(philo);
}
void sleeping(t_philosofre *philo)
{
    printf("\033[0;34m%i   philo id %i is sleeping\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    philo->time_before_usleep = ft_gettimeofday() - (philo->main->time_to_eat);
    usleep(philo->main->time_to_sleep * 999);
    pthread_mutex_lock(philo->main->dead);
    check_if_dead(philo, philo->time_before_usleep);
    pthread_mutex_unlock(philo->main->dead);
}

void thinking(t_philosofre *philo)
{
    printf("\033[0;35m%i   philo id %i is thinking\033[0m\n",
	ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
}