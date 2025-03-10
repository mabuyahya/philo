/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:18:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/10 03:42:56y mabuyahy         ###   ########.fr       */
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
	// int	time;
	if (!(philo->main->dead))
	{
		if (c == 'f')
		{
			if (is_dead(philo))
			{
				printf("[%i] philo number %i is dead waiting for fork\n",
				(ft_gettimeofday() - philo->main->start_of_sim) + (philo->main->time_to_die), philo->num + 1);
				pthread_mutex_lock(philo->main->dead_mutex);
				if (!(philo->main->dead))
					philo->main->dead = 1;
				pthread_mutex_unlock(philo->main->dead_mutex);
			}
			else
			{
				printf("\033[1;31m%i   philo id %i take a fork\033[0m\n",
				ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
			}
		}	
		if (c == 'e')
		{
			
			if (is_dead(philo))
			{
				printf("[%i] philo number %i is dead eating\n",
					   ft_gettimeofday() - (philo->main->start_of_sim) - (philo->main->time_to_eat) + (philo->main->time_to_die), philo->num + 1);
				pthread_mutex_lock(philo->main->dead_mutex);
				if (!(philo->main->dead))
					philo->main->dead = 1;
				pthread_mutex_unlock(philo->main->dead_mutex);
			}
		}
		if (c == 's')
		{
			if (is_dead(philo))
			{
				printf("[%i] philo number %i is dead sleeping\n",
				 ft_gettimeofday() - (philo->main->start_of_sim) - (philo->main->time_to_sleep) + (philo->main->time_to_die) - (philo->main->time_to_eat), philo->num + 1);
				pthread_mutex_lock(philo->main->dead_mutex);
				if (!(philo->main->dead))
					philo->main->dead = 1;
				pthread_mutex_unlock(philo->main->dead_mutex);
			}
		}
	}
}
