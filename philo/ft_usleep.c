/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:47:01 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/10 17:04:50 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(int time, t_philosofre *philo)
{
	long	start_time;

	start_time = ft_gettimeofsim(philo);
	while (ft_gettimeofsim(philo) - start_time < time)
	{
		if (check__if__i__am__dead(philo))
			return (1);
		if (ft_gettimeofsim(philo)
			- philo->time_of_last_meal > philo->main->time_to_die)
		{
			return (1);
		}
		usleep(1);
	}
	return (0);
}

int	last_philo(t_main *main, int i)
{
	if (i == main->philos_num - 1)
		return (1);
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(i + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
