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
    int time_before_usleep;

    time_before_usleep = ft_gettimeofday();
    philo->time_of_last_meal = ft_gettimeofday();
    usleep((philo->main->time_to_eat * 999));
    unlock_a_fork(philo);
}
void sleeping(t_philosofre *philo)
{
    usleep(philo->main->time_to_sleep * 999);
}

void thinking(t_philosofre *philo)
{
    printf("\033[0;35m%i   philo id %i is thinking\033[0m\n",
	ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
}