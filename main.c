/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:31:09 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/08 13:52:20 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_all_the_thread(t_main *main)
{
	int	i;

	i = 0;
	main->start_of_sim = ft_gettimeofday();
	if (philos_init(&main->philos, main))
		return (printf_return_free(main, "malloc error"));
	while (i < main->philos_num)
	{
		if (pthread_create(&main->philos_ids[i], NULL, rotene,
				&main->philos[i]) != 0)
			return (printf_return_free(main, "pthread_create error"));
		usleep(100);
		i++;
	}
	return (0);
}

int	check_if_any_philo_died(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philos_num)
	{
		pthread_mutex_lock(main->time_of_last_meal_mutex);
		if (ft_gettimeofsim(main->philos)
			- main->philos[i].time_of_last_meal > main->time_to_die)
		{
			pthread_mutex_unlock(main->time_of_last_meal_mutex);
			return (i);
		}
		pthread_mutex_unlock(main->time_of_last_meal_mutex);
		i++;
	}
	return (-1);
}

int	check_if_all_the_philo_eat(t_main *main)
{
	int	i;

	i = 0;
	if (main->number_of_meals != -1)
	{
		while (i < main->philos_num)
		{
			pthread_mutex_lock(main->meals_mutex);
			if (main->philos[i].meals_eaten < main->number_of_meals)
			{
				pthread_mutex_unlock(main->meals_mutex);
				return (0);
			}
			pthread_mutex_unlock(main->meals_mutex);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int	wait_all_the_thread(t_main *main)
{
	int	i;
	int	philo_id;

	i = 0;
	while (1)
	{
		philo_id = check_if_any_philo_died(main);
		if (philo_id != -1)
		{
			change_all_the_philos_iad_flag(main);
			break ;
		}
		if (check_if_all_the_philo_eat(main))
		{
			change_all_the_philos_iad_flag(main);
			return (-1);
		}
		usleep(100);
	}
	join_the_threads(main);
	printf("\033[47m\033[40m[%ld] philo number %d is dead\033[0m\n",
		ft_gettimeofsim(main->philos), philo_id + 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_main	main;
	int		i;

	i = 1;
	ft_memset(&main, 0, sizeof(t_main));
	if (argc == 5 || argc == 6)
	{
		if (check_if_valid_input(argv))
			return (1);
		if (argc == 6)
			main.number_of_meals = ft_atoi(argv[5]);
		else
			main.number_of_meals = -1;
		if (main_init(&main, argv))
			return (1);
		if (create_all_the_thread(&main))
			return (1);
		if (wait_all_the_thread(&main) == -1)
			join_the_threads(&main);
	}
	else
		printf("the argv's should be 4 or 5\n");
	cleanup(&main);
}
