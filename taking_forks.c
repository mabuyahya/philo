#include "philo.h"

void    take_a_fork(t_philosofre *philo)
{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->lift_fork);
		philo->time_before_usleep = philo->time_of_last_meal;
		pthread_mutex_lock(philo->main->dead);
		check_if_dead(philo, philo->time_before_usleep);
		pthread_mutex_unlock(philo->main->dead);
		printf("\033[0;31m%i   philo id %i has taken a fork\033[0m\n",
			   ft_gettimeofday() - (philo->main->start_of_sim), philo->num + 1);
}
void    unlock_a_fork(t_philosofre *philo)
{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->lift_fork);
}