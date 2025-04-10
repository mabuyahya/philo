/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:26:30 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/04/10 17:03:27 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define MAX_PHILOS 200

typedef struct s_main	t_main;

typedef struct s_philosofre
{
	int					num;
	int					i_am_dead;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*lift_fork;
	pthread_t			philo_thread_id;
	t_main				*main;
	long				time_of_last_meal;
	long				time_before_usleep;
	int					waiting_for_fork;
	int					meals_eaten;
}						t_philosofre;

typedef struct s_main
{
	char				**args;
	int					philos_num;
	pthread_mutex_t		*forks;
	int					*meals_flags;
	pthread_mutex_t		*waiting_mutex;
	pthread_mutex_t		*meals_mutex;
	pthread_mutex_t		*i_am_dead_mutex;
	pthread_mutex_t		*printf_mutex;
	pthread_mutex_t		*time_of_last_meal_mutex;
	int					philo_died;
	pthread_mutex_t		philo_num_mutex;
	pthread_t			*philos_ids;
	pthread_t			*monitors_ids;
	t_philosofre		*philos;
	long				start_of_sim;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	int					number_of_meals;
}						t_main;

void					*rotene(void *philo);
long					ft_gettimeofsim(t_philosofre *philo);
long					ft_gettimeofday(void);
int						ft_atoi(const char *str);
void					*ft_memset(void *s, int c, size_t n);
int						valid_num(char *argv);
void					if_exist_free(void *ptr);
void					cleanup(t_main *main);
void					join_the_threads(t_main *main);
int						check_if_valid_input(char **argv, int argc);
void					change_all_the_philos_iad_flag(t_main *main);
int						ft_usleep(int time, t_philosofre *philo);
int						eating(t_philosofre *philo);
int						safe_printf(t_philosofre *philo, char *str,
							char *color);
int						sleeping(t_philosofre *philo);
int						check__if__i__am__dead(t_philosofre *philo);
int						thinking(t_philosofre *philo);
char					*ft_strdup(const char *src);
char					**ft_strdup_matrix(char **str);
int						main_init(t_main *main, char **argv);
int						take_a_fork(t_philosofre *philos);
void					cleanup(t_main *main);
void					join_the_threads(t_main *main);
int						unlock_a_fork(t_philosofre *philos);
long					ft_gettimeofday(void);
long					ft_gettimeofsim(t_philosofre *philo);
int						philos_init(t_philosofre **philos, t_main *main);
int						printf_return_free(t_main *main, char *str);
int						last_philo(t_main *main, int i);
#endif