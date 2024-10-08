/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:56:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/15 14:02:12 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* LIBRARIES */
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

/* COLOR MESSAGES */
# define RST "\033[0m"
# define RED "\033[1;31m"

/* PRINT MESSAGES */
# define P_FORK_ONE  "[%ld] %d has taken the first fork.🍴\n"
# define P_FORK_TWO "[%ld] %d has taken the second fork.🍴\n"
# define EAT "[%ld] %d is eating. 🍔\n"
# define SLEEP "[%ld] %d is sleeping. 💤\n"
# define THINK "[%ld] %d is thinking.💡\n"
# define DEATH "[%ld] %d died! 💀\n"
# define DIE_ALONE "[%ld] %d died alone 😭\n"

typedef pthread_mutex_t	t_mtx;
typedef struct s_philo	t_philo;

/* FORK STRUCT */
typedef struct s_fork
{
	t_mtx	fork;
	int		id;
}	t_fork;

/* MAIN STRUCT */
typedef struct s_table
{
	int				philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limits_meals;
	long			start_time;
	bool			end_simulation;
	pthread_mutex_t	end_simulation_mutex;
	t_philo			*philo;
	t_fork			*fork;
	t_mtx			table_mutex;
	pthread_mutex_t	print;
}	t_table;

/* PHILO STRUCT */
typedef struct s_philo
{
	int				id;
	long			meals_counter;
	pthread_mutex_t	meals_counter_mutex;
	long			last_meal_time;
	pthread_mutex_t	last_meal_time_mutex;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	bool			full;
	pthread_mutex_t	full_mutex;
	t_table			*table;
}	t_philo;

/* ==== INPUT ==== */
void		prepare_dinner_table(int argc, char **input, t_table *table);
int			ft_isdigit(int c);
int			is_number(char *input);
long int	ft_atol(const char *nptr);

/* ==== DATA ==== */
void		data_init(t_table *table);
void		init_philo(t_table *table);
void		assign_forks(t_philo *philo, t_fork *forks, int philo_position);

/* ==== DINNER ==== */
void		dinner_start(t_table *table);

/* ==== CONTROL ==== */
bool		check_end_simulation(t_table *table);
void		*control(void *null);
void		check_philosopher_death(t_table *table);

/* ==== ROUTINE ==== */
void		*lonely_dinner(void);
void		*routine(void *arg);
bool		is_philo_full(t_philo *philo);

/* ==== TIME ==== */
long		get_time(void);
long		get_elapsed_time(long start_time);

/* ==== ACTIONS ==== */
void		down_forks(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_eating(t_philo *philo);
void		philo_thinking(t_philo *philo);

/* ==== CLEAN ==== */
void		free_everything(t_table *table);
void		destroy_mutexes(t_table *table);

/* ==== UTILS ==== */
void		error_message(char *string, t_table *table);
void		*allocate_memory(int bytes);
void		set_table(t_table *new_table);
t_table		*get_table(void);
void		print_message(t_philo *philo, const char *message);

#endif