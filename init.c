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

void	init_all_mutexs(pthread_mutex_t **mutexs, int num, t_main *main)
{
	int	i;

	
	i = 0;
	*mutexs = malloc(sizeof(pthread_mutex_t) * num);
	while (i < num)
	{
		pthread_mutex_init(&(*mutexs)[i], NULL);
		i++;
	}
	pthread_mutex_init(&main->philo_num_mutex, NULL);
}

void	main_init(t_main *main, char **argv)
{
	main->args = ft_strdup_matrix(argv);
	main->philos_num = ft_atoi(main->args[1]);
	init_all_mutexs(&main->forks, main->philos_num, main);
	main->time_to_eat = ft_atoi(main->args[3]);
	main->time_to_sleep = ft_atoi(main->args[4]);
	main->time_to_die = ft_atoi(main->args[2]);
	main->philos_ids = malloc(sizeof(pthread_t) * main->philos_num);
    philos_init(&main->philos, main, argv);
}

int	last_philo(t_main *main, int i)
{
	if (i == main->philos_num - 1)
		return (1);
	return (0);
}

void	philos_init(t_philosofre **philos, t_main *main, char **argv)
{
	int	i;
	(void) argv;

	i = 0;
	
	*philos = malloc(sizeof(t_philosofre) * main->philos_num);
	while (i < main->philos_num)
	{
		(*philos)[i].num = i;
		(*philos)[i].main = main;
		if (last_philo(main, i))
		{
			(*philos)[i].right_fork = &main->forks[i];
			(*philos)[i].lift_fork = &main->forks[0];
		}
		else
		{
			(*philos)[i].right_fork = &main->forks[i];
			(*philos)[i].lift_fork = &main->forks[i + 1];
		}
        i++;
	}
}