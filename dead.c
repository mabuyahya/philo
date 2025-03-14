/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:18:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/11 03:08:19 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_philosofre *philo, char c)
{
	if (c == 'f')
	{
		if (ft_gettimeofday() - (philo->time_of_last_meal) > philo->main->time_to_die)
			return (1);
	}
	else if (c == 'e')
	{
		// printf("c time %li\n", ft_gettimeofday());
		// printf("time of last meal %li\n", philo->time_of_last_meal);
		// printf("time to eat %i\n", philo->main->time_to_eat);
		// printf("time to die %i\n", philo->main->time_to_die);
		if ((philo->main->time_to_eat) > philo->main->time_to_die)
			return (1);
	}
	else if (c == 's')
	{
		if (ft_gettimeofday() - (philo->time_of_last_meal) + (philo->main->time_to_sleep) > philo->main->time_to_die)
			return (1);
	}
	return (0);
}

void check_if_dead(t_philosofre *philo, char c)
{
	pthread_mutex_lock(philo->main->dead_mutex);
	pthread_mutex_unlock(philo->main->dead_mutex);
	if (c == 'f')
	{
		if (is_dead(philo, 'f'))
		{
			pthread_mutex_lock(philo->main->dead_mutex);
			philo->main->dead = 1;
			printf("[%li] philo number %i is dead waiting for fork\n",
				   (philo->time_before_usleep) + (philo->main->time_to_die) - (philo->main->time_to_eat) - (philo->main->time_to_sleep), philo->num + 1);

			sleep(2);
		}
		else
		{
			printf("\033[1;31m%li   philo id %i take a fork\033[0m\n",
				   ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
		}
	}
	if (c == 'e')
	{
		if (is_dead(philo, 'e'))
		{
			printf("%li   philo id %i is eating\n",
				   ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
			usleep((philo->main->time_to_eat) * 999);
			pthread_mutex_lock(philo->main->dead_mutex);
			philo->main->dead = 1;
			printf("[%li] philo number %i is dead eating\n",
				   ft_gettimeofday() - (philo->main->start_of_sim) +
					   (philo->main->time_to_die) - (philo->main->time_to_eat),
				   philo->num + 1);
			sleep(2);
		}
	}
	if (c == 's')
	{
		if (is_dead(philo, 's'))
		{
			printf("%li   philo id %i is sleeping\n",
				   ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
			usleep((philo->main->time_to_sleep) * 999);
			pthread_mutex_lock(philo->main->dead_mutex);
			philo->main->dead = 1;
			printf("[%li] philo number %i is dead sleeping\n",
				   ft_gettimeofday() - (philo->main->start_of_sim) + (philo->main->time_to_die) - (philo->main->time_to_eat) - (philo->main->time_to_sleep), philo->num + 1);
			sleep(2);
		}
	}
}
