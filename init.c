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

int init_all_mutexs(pthread_mutex_t **forks, int num, t_main *main)
{
    int i;

    i = 0;
    *forks = malloc(sizeof(pthread_mutex_t) * num);
    if (!*forks)
        return (1);
    main->time_of_last_meal_mutex = malloc(sizeof(pthread_mutex_t));
    main->waiting_mutex = malloc(sizeof(pthread_mutex_t));
    main->i_am_dead_mutex = malloc(sizeof(pthread_mutex_t));
    main->printf_mutex = malloc(sizeof(pthread_mutex_t));
    main->meals_mutex = malloc(sizeof(pthread_mutex_t));
    if (!main->time_of_last_meal_mutex || !main->waiting_mutex || !main->i_am_dead_mutex || 
        !main->printf_mutex || !main->meals_mutex)
        return (1);
    while (i < num)
    {
        if (pthread_mutex_init(&(*forks)[i], NULL))
            return (1);
        i++;
    }
    if (pthread_mutex_init(&main->philo_num_mutex, NULL) || 
        pthread_mutex_init(&(*main->i_am_dead_mutex), NULL) ||
        pthread_mutex_init(&(*main->time_of_last_meal_mutex), NULL) ||
        pthread_mutex_init(&(*main->waiting_mutex), NULL) ||
        pthread_mutex_init(&(*main->printf_mutex), NULL) ||
        pthread_mutex_init(&(*main->meals_mutex), NULL))
        return (1);
    return (0);
}


int printf_return_free(t_main *main, char *str)
{
	printf("%s\n", str);
	cleanup(main);
	return (1);
}

int	main_init(t_main *main, char **argv)
{
	int i;

	i = 0;
	(void) argv;
	main->args = ft_strdup_matrix(argv);
	if (!main->args)
        return(printf_return_free(main, "malloc failed"));
	main->philo_died = 0;
	main->philos_num = ft_atoi(main->args[1]);
	if(init_all_mutexs(&main->forks, main->philos_num, main))
		return (printf_return_free(main, "malloc failed"));
	main->time_to_eat = ft_atoi(main->args[3]);
	main->time_to_sleep = ft_atoi(main->args[4]);
	main->time_to_die = ft_atoi(main->args[2]);
	if (main->time_to_eat == 0 || main->time_to_sleep == 0 || main->time_to_die == 0)
		return (printf_return_free(main, "the values can't be zero"));
	main->philos_ids = malloc(sizeof(pthread_t) * main->philos_num);
	main->monitors_ids = malloc(sizeof(pthread_t) * main->philos_num);
	if (!main->philos_ids || !main->monitors_ids)
		return (printf_return_free(main, "malloc failed"));
	return (0);
}

int	last_philo(t_main *main, int i)
{
	if (i == main->philos_num - 1)
		return (1);
	return (0);
}

int philos_init(t_philosofre **philos, t_main *main)
{
	int i;

	i = 0;

	*philos = malloc(sizeof(t_philosofre) * main->philos_num);
	if (!*philos)
		return (1);
	while (i < main->philos_num)
	{
		(*philos)[i].time_of_last_meal = main->start_of_sim;
		(*philos)[i].num = i;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].i_am_dead = 0;
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
	return (0);
}
