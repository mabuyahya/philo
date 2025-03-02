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

void	init_all_mutexs(pthread_mutex_t **mutexs, int num, int	*flag)
{
	int	i;

	if (*flag)
		return;
	*flag = 1;
	i = 0;
	*mutexs = malloc(sizeof(pthread_mutex_t) * num);
	while (i < num)
	{
		pthread_mutex_init(&(*mutexs)[i], NULL);
		i++;
	}

}

void *rotene(void **args)
{
	static int	i;
	static int flag = 0;
	static pthread_mutex_t	*mutexs;

	
	pthread_mutex_lock(&test);
	init_all_mutexs(&mutexs, ft_atoi(args[1]), &flag);
	pthread_mutex_unlock(&test);
	take_a_fork(mutexs, i, ft_atoi(args[1]));
	unlock_a_fork(mutexs, i, ft_atoi(args[1]));
	
	return (args);
}

int create_all_the_thread(pthread_t *philos_id, char **args) 
{
	int	i;
	int	philos_num;

	philos_num = ft_atoi(args[1]);
	i = 0;
	while (i < philos_num)
	{
		pthread_create(&philos_id[i], NULL,(void *) rotene, (void *) args);
		i++;
	}
	return (1);
}

int	wait_all_the_thread(pthread_t *philos_id, char **args)
{
	int	i;
	int	philos_num;

	i = 0;
	philos_num = ft_atoi(args[1]);
	while (i < philos_num)
	{
		pthread_join(philos_id[i], NULL);
		i++;
	}
	return (1);
}

int    main(int argc, char **argv)
{
	char **args;

	args = ft_strdup_matrix(argv);
	pthread_t	philos_id[ft_atoi(args[1])];
	if (argc == 5 || argc == 6)			
	{
		create_all_the_thread(philos_id, args);
		wait_all_the_thread(philos_id, args);
	}
	else
	printf("the argv's should be 4 or 5");
}