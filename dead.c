/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:18:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/09 06:28:14 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_philosofre *philo)
{
    if (ft_gettimeofday() - (philo->time_of_last_meal) >= philo->main->time_to_die)
        return (1);
    return (0);
}

void    check_if_dead(t_philosofre *philo, char c)
{
		if (c == 'f')
		{
			if (is_dead)
			{
				printf("[%i] philo number %i is dead waiting for fork\n", i
				(ft_gettimeofday() - philo->main->start_of_sim) + (philo->main->time_to_die), philo->num + 1);
			}
			else
			{
				printf("\033[1;31m%i   philo id %i take a fork\033[0m\n",
				ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
			}
		}	
		else if (c == 'e')
		{
			if (is_dead)
			{
				printf("[%i] philo number %i is dead eating\n", i
				(ft_gettimeofday() - philo->main->start_of_sim) + (philo->main->time_to_die), philo->num + 1);
			}
			else
			{
				printf("\033[1;31m%i   philo id %i is eating\033[0m\n",
				ft_gettimeofday() - (philo->main->start_of_sim) - (philo->main->time_to_eat), philo->num + 1);
			}
		}
		else if (c == 's')
		{
			if (is_dead)
			{
				printf("[%i] philo number %i is dead sleeping\n", i
				(ft_gettimeofday() - philo->main->start_of_sim) + (philo->main->time_to_die), philo->num + 1);
			}
			else
			{
				printf("\033[1;31m%i   philo id %i is sleeping\033[0m\n",
				ft_gettimeofday() - (philo->main->start_of_sim) - (philo->main->time_to_sleep), philo->num + 1);
			}
		}
}