#include "philo.h"

pthread_mutex_t test = PTHREAD_MUTEX_INITIALIZER;

void    take_a_fork(t_philosofre *philo)
{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->lift_fork);
		pthread_mutex_lock(&test);
		printf("\033[1m%i has taken a fork\033[0m\n", philo->num + 1);
		pthread_mutex_unlock(&test);
}
void    unlock_a_fork(t_philosofre *philo)
{
		pthread_mutex_unlock(philo->lift_fork);
		pthread_mutex_unlock(philo->right_fork);
}