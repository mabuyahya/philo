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
    int i_am_dead;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *lift_fork;
    pthread_t philo_thread_id;
    t_main *main;
    long time_of_last_meal;
    long time_before_usleep;
    int waiting_for_fork;
    int meals_eaten;

} t_philosofre;

typedef struct s_main
{
    char **args;
    int philos_num;
    pthread_mutex_t *forks;
    int *meals_flags;
    pthread_mutex_t *waiting_mutex;
    pthread_mutex_t *meals_mutex;
    pthread_mutex_t *i_am_dead_mutex;
    pthread_mutex_t *printf_mutex;
    pthread_mutex_t *time_of_last_meal_mutex;
    int philo_died;
    pthread_mutex_t philo_num_mutex;
    pthread_t *philos_ids;
    pthread_t *monitors_ids;
    t_philosofre *philos;
    long start_of_sim;
    int time_to_eat;
    int time_to_sleep;
    int time_to_die;
    int number_of_meals;
} t_main;

// void check_if_dead(t_philosofre *philos, char c);
void *rotene(void *philo);
int ft_usleep(int time, t_philosofre *philo);
int eating(t_philosofre *philo);
int safe_printf(t_philosofre *philo, char *str, char *color);
int sleeping(t_philosofre *philo);
int check__if__i__am__dead(t_philosofre *philo);
int thinking(t_philosofre *philo);
char **ft_strdup_matrix(char **str);
int main_init(t_main *main, char **argv);
int take_a_fork(t_philosofre *philos);
void cleanup(t_main *main);
void join_the_threads(t_main *main);
int unlock_a_fork(t_philosofre *philos);
long ft_gettimeofday(void);
long ft_gettimeofsim(t_philosofre *philo);
int philos_init(t_philosofre **philos, t_main *main);
int printf_return_free(t_main *main, char *str);
void *monitor_philo(void *philoo); 
#endif