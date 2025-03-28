/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:24:29 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/06 05:30:49by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_all_mutexs(pthread_mutex_t **forks, int num, t_main *main)
{
	int	i;

	i = 0;
	*forks = malloc(sizeof(pthread_mutex_t) * num);
	main->i_am_dead_mutex = malloc(sizeof(pthread_mutex_t));
	main->meals_flags_mutex = malloc(sizeof(pthread_mutex_t));
	main->waiting_mutex = malloc(sizeof(pthread_mutex_t));
	main->someone_else_dead_mutex = malloc(sizeof(pthread_mutex_t));
	main->printf_mutex = malloc(sizeof(pthread_mutex_t));

	while (i < num)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
	pthread_mutex_init(&main->philo_num_mutex, NULL);
	pthread_mutex_init(&(*main->i_am_dead_mutex), NULL);
	pthread_mutex_init(&(*main->waiting_mutex), NULL);
	pthread_mutex_init(&(*main->meals_flags_mutex), NULL);
	pthread_mutex_init(&(*main->printf_mutex), NULL);
	pthread_mutex_init(&(*main->someone_else_dead_mutex), NULL);
}

void	main_init(t_main *main, char **argv)
{
	int i;

	i = 0;
	main->args = ft_strdup_matrix(argv);
	main->i_am_dead = 0;
	main->philos_num = ft_atoi(main->args[1]);
	init_all_mutexs(&main->forks, main->philos_num, main);
	main->time_to_eat = ft_atoi(main->args[3]);
	main->time_to_sleep = ft_atoi(main->args[4]);
	main->time_to_die = ft_atoi(main->args[2]);
	main->philos_ids = malloc(sizeof(pthread_t) * main->philos_num);
	main->meals_flags = malloc(sizeof(int) * main->philos_num);
	while (i < main->philos_num)
	{
		main->meals_flags[i] = 0;
		i++;
	}
	main->monitors_ids = malloc(sizeof(pthread_t) * main->philos_num);
}

int	last_philo(t_main *main, int i)
{
	if (i == main->philos_num - 1)
		return (1);
	return (0);
}

void philos_init(t_philosofre **philos, t_main *main)
{
	int i;

	i = 0;

	*philos = malloc(sizeof(t_philosofre) * main->philos_num);
	while (i < main->philos_num)
	{
		(*philos)[i].time_of_last_meal = main->start_of_sim;
		(*philos)[i].num = i;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].someone_else_dead = 0;
		(*philos)[i].waiting_for_fork = 0;
		(*philos)[i].main = main;
		if (last_philo(main, i))
		{
			(*philos)[i].right_fork = &main->forks[0];
			(*philos)[i].lift_fork = &main->forks[i];
		}
		else
		{
			(*philos)[i].right_fork = &main->forks[i];
			(*philos)[i].lift_fork = &main->forks[i + 1];
		}
		i++;
	}
}