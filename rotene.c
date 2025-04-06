/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotene.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:01:55 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/06 11:32:47 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *rotene(void *philo)
{
    while (1)
    {
        if (check_____if____someone____is____dead(philo))
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
void *monitor_philo(void *philoo)
{
	t_philosofre *philo;
    philo = (t_philosofre *)philoo;
	while (1)
	{
        if(check_____if____someone____is____dead(philo))
            return (NULL);
        if (ft_gettimeofsim(philo) - philo->time_of_last_meal > philo->main->time_to_die)
		{
			pthread_mutex_lock(philo->main->i_am_dead_mutex);
			philo->main->i_am_dead = 1;
			pthread_mutex_unlock(philo->main->i_am_dead_mutex);
			return (NULL);
        }
        usleep(100);
	}
	return (NULL);
}
int eating(t_philosofre *philo)
{
    if(take_a_fork(philo))
        return (1);
    if(safe_printf(philo, "has taken a fork", "\033[0;36m"))
    {
        unlock_a_fork(philo);
        return (1);
    }
    if(safe_printf(philo, "is eating", "\033[0;32m"))
    {
        unlock_a_fork(philo);
        return (1);
    }
    philo->time_of_last_meal = ft_gettimeofsim(philo);
    if (ft_usleep(philo->main->time_to_eat, philo))
    {
        unlock_a_fork(philo);
        return (1);
    }
    unlock_a_fork(philo);
    return (0);
}
int sleeping(t_philosofre *philo)
{
    if (check_____if____someone____is____dead(philo))
        return (1);
    safe_printf(philo, "is sleeping", "\033[0;34m"); 
    if (ft_usleep(philo->main->time_to_sleep, philo))
        return (1);
    return (0);
}

int thinking(t_philosofre *philo)
{
    if (check_____if____someone____is____dead(philo))
        return (1);
    safe_printf(philo, "is thinking", "\033[0;35m");
    return (0);
}