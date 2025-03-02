/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:31:09 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/02/28 19:19:50 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t		test = PTHREAD_MUTEX_INITIALIZER;

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

void *rotene(void *ptr)
{
	static int	i;
	t_main *main;
	
	main = (t_main *) ptr;
	pthread_mutex_lock(&main->philo_num_mutex);
	i++;
	pthread_mutex_unlock(&main->philo_num_mutex);
	take_a_fork(main->forks, i, main->philos_num);
	unlock_a_fork(main->forks, i, main->philos_num);
	
	return (ptr);
}

int create_all_the_thread(pthread_t *philos_id, t_main *main) 
{
	int	i;

	i = 0;
	init_all_mutexs(&main->forks, main->philos_num, main);
	while (i < main->philos_num)
	{
		pthread_create(&philos_id[i], NULL,(void *) rotene, (void *) main);
		i++;
	}
	return (1);
}

int	wait_all_the_thread(pthread_t *philos_id, t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philos_num)
	{
		pthread_join(philos_id[i], NULL);
		i++;
	}
	return (1);
}

int    main(int argc, char **argv)
{
	t_main	main;

	main.args = ft_strdup_matrix(argv);
	main.philos_num = ft_atoi(main.args[1]);
	pthread_t	philos_id[main.philos_num];
	if (argc == 5 || argc == 6)			
	{
		create_all_the_thread(philos_id, &main);
		wait_all_the_thread(philos_id, &main);
	}
	else
	printf("the argv's should be 4 or 5");
}