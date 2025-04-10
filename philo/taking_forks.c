/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:26:50 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/08 13:27:07 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_a_fork(t_philosofre *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->lift_fork);
	if (check__if__i__am__dead(philo))
	{
		unlock_a_fork(philo);
		return (1);
	}
	return (0);
}

int	unlock_a_fork(t_philosofre *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->lift_fork);
	return (0);
}
