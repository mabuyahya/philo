/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:31:09 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/08 13:02:57 by mabuyahy         ###   ########.fr       */
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
	if(philos_init(&main->philos, main))
		return (printf_return_free(main, "malloc error"));
	while (i < main->philos_num)
	{
		if(pthread_create(&main->philos_ids[i], NULL, rotene, &main->philos[i]) != 0)
			return (printf_return_free(main, "pthread_create error"));
		usleep(100);
		i++;
	}
	return (0);
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

int wait_all_the_thread(t_main *main)
{
	int	i;
	int philo_id;

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
	printf("\033[47m\033[40m[%ld] philo number %d is dead\033[0m\n", ft_gettimeofsim(main->philos), philo_id + 1);
	return (1);
}

int	valid_num(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
		{
			printf("posative only numbers in the input\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void if_exist_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void cleanup(t_main *main)
{
    int i;

	i  = 0;
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

void join_the_threads(t_main *main)
{
	int i;

	i = 0;
	while (i < main->philos_num)
	{
		pthread_join(main->philos_ids[i], NULL);
		i++;
	}
}

int check_if_valid_input(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (valid_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_main main;
	int	i;

	i = 1;
	ft_memset(&main, 0, sizeof(t_main));
	if (argc == 5 || argc == 6)
	{
		if(check_if_valid_input(argv))
			return (1);
		if (argc == 6)
			main.number_of_meals = ft_atoi(argv[5]);
		else
			main.number_of_meals = -1;
		if(main_init(&main, argv))
			return (1);
		if(create_all_the_thread(&main))
			return (1);
		if (wait_all_the_thread(&main) == -1)
			join_the_threads(&main);
	}
	else
		printf("the argv's should be 4 or 5\n");
	cleanup(&main);
}
