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
void *rotene(void *philos_id)
{
}
int ft_create_thread(char **argv)
{
	pthread_t	philos_id[ft_atoi(argv[0])];
	int	i;

	i = 0;
	while (i < ft_atoi(argv[0]))
	{
		pthread_create(&philo_id[i], NULL, );
		
	}

	
}

int    main(int argc, char **argv)
{
	if (argc == 4 || argc == 5)			
	{


	}
	else
	printf("the argv's should be 4 or 5");
}