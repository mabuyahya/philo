# ifndef PHILO_H
# define PHILO_H

#include <stdio.h> 
#include <pthread.h>
#include "lib/libft/libft.h"

#define MAX_PHILOS 200

typedef struct s_philosofre
{
    int num;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *lift_fork;
    pthread_t philo_thread_id;
}   t_philosofre;

typedef struct s_main
{
    char **args;
    int philos_num;
	pthread_mutex_t	*forks;
    pthread_mutex_t philo_num_mutex;
    pthread_t *philos_ids;
    t_philosofre *philos;
}   t_main;

char **ft_strdup_matrix(char **str);
void	main_init(t_main *main, char **argv);
void    take_a_fork(t_philosofre *philos);
void    unlock_a_fork(t_philosofre *philos);
void	philos_init(t_philosofre **philos, t_main *main, char **argv);

#endif