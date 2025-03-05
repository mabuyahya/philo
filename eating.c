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
    usleep(philo->time_to_eat* 1000);
    unlock_a_fork(philo);
}
void sleeping(t_philosofre *philo)
{
    printf("\033[0;34m%i   philo id %i is sleeping\033[0m\n",
           ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
    usleep(philo->time_to_sleep * 1000);
}

void thinking(t_philosofre *philo)
{
    printf("\033[0;35m%i   philo id %i is thinking\033[0m\n",
	ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
}