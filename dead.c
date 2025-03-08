/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:18:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/06 05:57:03 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_philosofre *philo)
{
    if (ft_gettimeofday() - (philo->time_of_last_meal) >= philo->main->time_to_die)
        return (1);
    return (0);
}

void    check_if_dead(t_philosofre *philo, int  sec)
{
    if (is_dead(philo))
    {
        printf("[%i] philo number %i is dead \n", (sec - philo->main->start_of_sim) + (philo->main->time_to_die), philo->num + 1);
        
    }
}