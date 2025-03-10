#include "philo.h"

int     take_a_fork(t_philosofre *philo)
{
    pthread_mutex_lock(philo->main->dead_mutex);
	if (philo->main->dead)
	{
    pthread_mutex_unlock(philo->main->dead_mutex);
		return (1);
	}
    pthread_mutex_unlock(philo->main->dead_mutex);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->lift_fork);
	return (0);
}
void unlock_a_fork(t_philosofre *philo)
{
	
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->lift_fork);
}