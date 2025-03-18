#ifndef philo_h
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include "lib/libft/libft.h"

#define MAX_PHILOS 200


typedef struct s_main t_main;

typedef struct s_philosofre
{
    int num;
    int dead;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *lift_fork;
    pthread_t philo_thread_id;
    t_main *main;
    long time_of_last_meal;
    long time_before_usleep;

} t_philosofre;

typedef struct s_main
{
    char **args;
    int philos_num;
    pthread_mutex_t *forks;
    pthread_mutex_t *dead_mutex;
    int dead;
    pthread_mutex_t philo_num_mutex;
    pthread_t *philos_ids;
    t_philosofre *philos;
    long start_of_sim;
    int time_to_eat;
    int time_to_sleep;
    int time_to_die;
} t_main;

void check_if_dead(t_philosofre *philos, char c);
void *rotene(void *philo);
int ft_usleep(int time, t_philosofre *philo);
int eating(t_philosofre *philo);
int sleeping(t_philosofre *philo);
int thinking(t_philosofre *philo);
char **ft_strdup_matrix(char **str);
void main_init(t_main *main, char **argv);
int take_a_fork(t_philosofre *philos);
void unlock_a_fork(t_philosofre *philos);
long ft_gettimeofday(void);
long ft_gettimeofsim(t_philosofre *philo);
void philos_init(t_philosofre **philos, t_main *main);
#endif