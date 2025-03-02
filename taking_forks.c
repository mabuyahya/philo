#include "philo.h"

void    take_a_fork(pthread_mutex_t *forks, int i, int  num)
{
    if (i == num - 1)
	{
		pthread_mutex_lock(&forks[i]);
		pthread_mutex_lock(&forks[0]);
		printf("\033[1m%i has taken a fork\033[0m\n", i);
	}
	else
	{
		pthread_mutex_lock(&forks[i]);
		pthread_mutex_lock(&forks[i + 1]);
		printf("\033[1m%i has taken a fork\033[0m\n", i);
	}
}
void    unlock_a_fork(pthread_mutex_t *forks, int i, int  num)
{
    if (i == num - 1)
	{
		pthread_mutex_unlock(&forks[i]);
		pthread_mutex_unlock(&forks[0]);
	}
	else
	{
		pthread_mutex_unlock(&forks[i]);
		pthread_mutex_unlock(&forks[i + 1]);
	}
}