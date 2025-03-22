#include "philo.h"

int take_a_fork(t_philosofre *philo)
{
	long time_now;


	pthread_mutex_lock(philo->right_fork);
	time_now = ft_gettimeofsim(philo);
	if (time_now - philo->time_of_last_meal > philo->main->time_to_die)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->main->i_am_dead_mutex);
		philo->main->i_am_dead = 1;
		pthread_mutex_unlock(philo->main->i_am_dead_mutex);
		return (1);
	}
	pthread_mutex_lock(philo->lift_fork);
	time_now = ft_gettimeofsim(philo);
	if (time_now - philo->time_of_last_meal > philo->main->time_to_die)
	{
		unlock_a_fork(philo);
		pthread_mutex_lock(philo->main->i_am_dead_mutex);
		philo->main->i_am_dead = 1;
		pthread_mutex_unlock(philo->main->i_am_dead_mutex);
		return (1);
	}
	pthread_mutex_lock(philo->main->someone_else_dead_mutex);
	if (philo->someone_else_dead)
	{
		pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
		unlock_a_fork(philo);
		return (1);
	}
	pthread_mutex_unlock(philo->main->someone_else_dead_mutex);
	pthread_mutex_lock(philo->main->printf_mutex);
	printf("\033[1;31m%li   philo id %i has taken a fork\033[0m\n",
		   ft_gettimeofsim(philo), philo->num + 1);
	pthread_mutex_unlock(philo->main->printf_mutex);
	return (0);
}
int unlock_a_fork(t_philosofre *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->lift_fork);
	return (0);
}