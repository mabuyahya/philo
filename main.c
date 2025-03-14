/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:31:09 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/03/03 23:22:39by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


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
	int	i;

	i = 0;
	while (i < main->philos_num)
	{
		pthread_create(&main->philos_ids[i], NULL, rotene, &main->philos[i]);
		usleep(100);
		i++;
	}
	return (1);
}

int	wait_all_the_thread(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philos_num)
	{
		pthread_detach(main->philos_ids[i]);
		i++;
	}
	while (!(main->dead))
		;
	return (1);
}


int    main(int argc, char **argv)
{
	t_main	main;
	

	if (argc == 5 || argc == 6)	
	{
		main_init(&main, argv);
		create_all_the_thread(&main);
		wait_all_the_thread(&main);
	}
	else
	printf("the argv's should be 4 or 5\n");
}