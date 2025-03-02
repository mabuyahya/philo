# ifndef PHILO_H
# define PHILO_H

#include <stdio.h> 
#include <pthread.h>
#include "lib/libft/libft.h"

#define MAX_PHILOS 200

typedef struct s_main
{
    int id;
    char **args;
	pthread_mutex_t	*forks;
    int philos_num;
    pthread_mutex_t philo_num_mutex;
    int num;
}   t_main;


char **ft_strdup_matrix(char **str);
void    take_a_fork(pthread_mutex_t *forks, int i, int  num);
void    unlock_a_fork(pthread_mutex_t *forks, int i, int  num);

#endif