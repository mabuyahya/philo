#include "philo.h"

void    take_a_fork(t_philosofre *philo)
{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->lift_fork);
}
void    unlock_a_fork(t_philosofre *philo)
{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->lift_fork);
}