#include "philo.h"

int take_a_fork(t_philosofre *philo)
{
	philo->time_before_usleep = ft_gettimeofday() - philo->main->start_of_sim;
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->lift_fork);
	return (0);
}
void unlock_a_fork(t_philosofre *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->lift_fork);
}