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

void    eating(t_philosofre *philo)
{
    take_a_fork(philo);
    printf("\033[1;31m%i   philo id %i is eating\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    philo->time_of_last_meal = ft_gettimeofday();
    usleep((philo->main->time_to_eat * 1000) - 1);
    check_if_dead(philo, philo->time_of_last_meal);
    unlock_a_fork(philo);
}
void sleeping(t_philosofre *philo)
{
    printf("\033[0;34m%i   philo id %i is sleeping\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    philo->time_before_usleep = ft_gettimeofday() - (philo->main->time_to_eat);
    usleep(philo->main->time_to_sleep * 1000);
    check_if_dead(philo, philo->time_before_usleep);
}

void thinking(t_philosofre *philo)
{
    printf("\033[0;35m%i   philo id %i is thinking\033[0m\n",
	ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
}