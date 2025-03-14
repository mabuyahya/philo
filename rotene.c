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

void *rotene(void *philo)
{
    while (1)
    {
        if (take_a_fork(philo))
            return (NULL);
        check_if_dead(philo, 'f');
        check_if_dead(philo, 'e');
        if (eating(philo))
            return (NULL);
        check_if_dead(philo, 's');
        if (sleeping(philo))
            return (NULL);
        if (thinking(philo))
            return (NULL);
    }
    return (NULL);
}
int eating(t_philosofre *philo)
{
    pthread_mutex_lock(philo->main->dead_mutex);
    pthread_mutex_unlock(philo->main->dead_mutex);
    printf("\033[1;31m%li   philo id %i is eating\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    philo->time_of_last_meal = ft_gettimeofday();
    usleep((philo->main->time_to_eat * 999));
    unlock_a_fork(philo);
    return (0);
}
int sleeping(t_philosofre *philo)
{
    pthread_mutex_lock(philo->main->dead_mutex);
    pthread_mutex_unlock(philo->main->dead_mutex);
    printf("\033[1;33m%li   philo id %i is sleeping\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    usleep(philo->main->time_to_sleep * 999);
    return (0);
}

int thinking(t_philosofre *philo)
{
    pthread_mutex_lock(philo->main->dead_mutex);
    pthread_mutex_unlock(philo->main->dead_mutex);
    printf("\033[0;35m%li   philo id %i is thinking\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    return (0);
}