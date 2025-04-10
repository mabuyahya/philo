/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utilites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:42:47 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/08 18:30:33 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_gettimeofsim(t_philosofre *philo)
{
	long			time;
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	time = (c_time.tv_sec * 1000 + c_time.tv_usec / 1000);
	return (time - philo->main->start_of_sim);
}

long	ft_gettimeofday(void)
{
	long			time;
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	time = (c_time.tv_sec * 1000 + c_time.tv_usec / 1000);
	return (time);
}

int	check_if_valid_input(char **argv, int argc)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (valid_num(argv[i]))
			return (1);
		i++;
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 0)
		{
			printf("the values can't be zero\n");
			return (1);
		}
	}
	return (0);
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

void	if_exist_free(void *ptr)
{
	if (ptr)
		free(ptr);
}
