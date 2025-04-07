/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:31:09 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/07 12:30:40 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long ft_gettimeofsim(t_philosofre *philo)
{
	long time;
	struct timeval c_time;

	gettimeofday(&c_time, NULL);
	time = (c_time.tv_sec * 1000 + c_time.tv_usec / 1000);
	return (time - philo->main->start_of_sim);
}

long ft_gettimeofday(void)
{
	long time;
	struct timeval c_time;

	gettimeofday(&c_time, NULL);
	time = (c_time.tv_sec * 1000 + c_time.tv_usec / 1000);
	return (time);
}

int create_all_the_thread(t_main *main)
{
	int i;

	i = 0;
	main->start_of_sim = ft_gettimeofday();
	philos_init(&main->philos, main);
	while (i < main->philos_num)
	{
		pthread_create(&main->philos_ids[i], NULL, rotene, &main->philos[i]);
		usleep(100);
		i++;
	}
	return (1);
}

int check_if_any_philo_died(t_main *main)
{
	int i;

	i = 0;
	while (i < main->philos_num)
	{
		pthread_mutex_lock(main->time_of_last_meal_mutex);
		if (ft_gettimeofsim(main->philos) - main->philos[i].time_of_last_meal > main->time_to_die)
		{
			pthread_mutex_unlock(main->time_of_last_meal_mutex);
			return (i);
		}
		pthread_mutex_unlock(main->time_of_last_meal_mutex);
		i++;
	}
	return (-1);
}

void change_all_the_philos_iad_flag(t_main *main)
{
	int i;

	i = 0;
	pthread_mutex_lock(main->i_am_dead_mutex);
	while (i < main->philos_num)
	{
		main->philos[i].i_am_dead = 1;
		i++;
	}
	pthread_mutex_unlock(main->i_am_dead_mutex);
}

int wait_all_the_thread(t_main *main)
{
	int	i;

	i = 0;
	int philo_id;
	while (1)
	{
		philo_id = check_if_any_philo_died(main);
		if (philo_id != -1)
		{
			change_all_the_philos_iad_flag(main);
			break ;
		}
		usleep(100);
	}
	while (i < main->philos_num)
	{
		pthread_join(main->philos_ids[i], NULL);
		i++;
	}
	printf("[%ld] philo number %d is dead\n", ft_gettimeofsim(main->philos), philo_id + 1);
	return (1);
}

int main(int argc, char **argv)
{
	t_main main;

	if (argc == 5 || argc == 6)
	{
		main_init(&main, argv);
		create_all_the_thread(&main);
		wait_all_the_thread(&main);
	}
	else
		printf("the argv's should be 4 or 5\n");
}