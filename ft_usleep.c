/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:47:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/06 11:49:01 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_usleep(int time, t_philosofre *philo)
{
	long start_time;

	start_time = ft_gettimeofsim(philo);
	while (ft_gettimeofsim(philo) - start_time < time)
	{
		if(check_____if____someone____is____dead(philo))
			return (1);
	}
	return (0);
}