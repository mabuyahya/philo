/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotene.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:01:55 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/08 13:25:18 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*rotene(void *philo)
{
	t_philosofre	*philoo;

	philoo = (t_philosofre *)philo;
	if (philoo->main->philos_num == 1)
	{
		pthread_mutex_lock(philoo->main->time_of_last_meal_mutex);
		philoo->time_of_last_meal = 0;
		pthread_mutex_unlock(philoo->main->time_of_last_meal_mutex);
		safe_printf(philo, "has taken a fork", "\033[1;31m");
		ft_usleep(philoo->main->time_to_die, philo);
		return (NULL);
	}
	while (1)
	{
		if (check__if__i__am__dead(philo))
			return (NULL);
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
	}
	return (NULL);
}

int	eating(t_philosofre *philo)
{
	if (take_a_fork(philo))
		return (1);
	if (safe_printf(philo, "has taken a fork", "\033[1;31m"))
	{
		unlock_a_fork(philo);
		return (1);
	}
	if (safe_printf(philo, "is eating", "\033[1;33m"))
	{
		unlock_a_fork(philo);
		return (1);
	}
	pthread_mutex_lock(philo->main->time_of_last_meal_mutex);
	philo->time_of_last_meal = ft_gettimeofsim(philo);
	pthread_mutex_unlock(philo->main->time_of_last_meal_mutex);
	pthread_mutex_lock(philo->main->meals_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->main->meals_mutex);
	if (ft_usleep(philo->main->time_to_eat, philo))
	{
		unlock_a_fork(philo);
		return (1);
	}
	unlock_a_fork(philo);
	return (0);
}

int	sleeping(t_philosofre *philo)
{
	if (check__if__i__am__dead(philo))
		return (1);
	if (safe_printf(philo, "is sleeping", "\033[1;34m"))
		return (1);
	if (ft_usleep(philo->main->time_to_sleep, philo))
		return (1);
	return (0);
}

int	thinking(t_philosofre *philo)
{
	if (check__if__i__am__dead(philo))
		return (1);
	if (safe_printf(philo, "is thinking", "\033[1;35m"))
		return (1);
	return (0);
}
