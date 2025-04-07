/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:47:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/06 14:27:36by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_usleep(int time, t_philosofre *philo)
{
	long start_time;

	start_time = ft_gettimeofsim(philo);
	while (ft_gettimeofsim(philo) - start_time < time)
	{
		if (check__if__i__am__dead(philo))
			return (1);
		if (ft_gettimeofsim(philo) - philo->time_of_last_meal > philo->main->time_to_die)
		{
			return (1);
		}
		usleep(1);
	}
	return (0);
}
