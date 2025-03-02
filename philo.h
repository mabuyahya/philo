# ifndef PHILO_H
# define PHILO_H

#include <stdio.h> 
#include <pthread.h>
#include "lib/libft/libft.h"

#define MAX_PHILOS 200

char **ft_strdup_matrix(char **str);
void    take_a_fork(pthread_mutex_t *forks, int i, int  num);
void    unlock_a_fork(pthread_mutex_t *forks, int i, int  num);

#endif