# ifndef PHILO_H
# define PHILO_H

#include <stdio.h> 
#include <pthread.h>
#include "lib/libft/libft.h"

#define MAX_PHILOS 200

typedef struct s_main
{
    char **args;
	pthread_mutex_t	*forks;
    int philos_num;
    pthread_t *philos_ids;
    pthread_mutex_t philo_num_mutex;
}   t_main;

typedef struct s_philosofre
{
    int num;
    pthread_t philo_thread_id;
}   t_philosofre;

char **ft_strdup_matrix(char **str);
void    take_a_fork(pthread_mutex_t *forks, int i, int  num);
void    unlock_a_fork(pthread_mutex_t *forks, int i, int  num);

#endif