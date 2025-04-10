/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utilites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:46:23 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/08 13:51:08 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_main *main)
{
	int	i;

	i = 0;
	if_exist_free(main->forks);
	if_exist_free(main->time_of_last_meal_mutex);
	if_exist_free(main->waiting_mutex);
	if_exist_free(main->i_am_dead_mutex);
	if_exist_free(main->printf_mutex);
	if_exist_free(main->meals_mutex);
	if_exist_free(main->philos_ids);
	if_exist_free(main->monitors_ids);
	if_exist_free(main->philos);
	i = 0;
	while (main->args && main->args[i])
	{
		if_exist_free(main->args[i]);
		i++;
	}
	if_exist_free(main->args);
}

void	join_the_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philos_num)
	{
		pthread_join(main->philos_ids[i], NULL);
		i++;
	}
}

void	change_all_the_philos_iad_flag(t_main *main)
{
	int	i;

	i = 0;
	pthread_mutex_lock(main->i_am_dead_mutex);
	while (i < main->philos_num)
	{
		main->philos[i].i_am_dead = 1;
		i++;
	}
	pthread_mutex_unlock(main->i_am_dead_mutex);
}
