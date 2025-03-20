#include "philo.h"


int take_a_fork(t_philosofre *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->lift_fork);
	pthread_mutex_lock(philo->main->printf_mutex);
    printf("\033[1;31m%li   philo id %i has taken a fork\033[0m\n",
           ft_gettimeofsim(philo), philo->num + 1);
	pthread_mutex_unlock(philo->main->printf_mutex);
	return (0);
}
void unlock_a_fork(t_philosofre *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->lift_fork);
}