/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:56:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 11:46:09 by bsantana         ###   ########.fr       */
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
# define WHITE "\033[1;37m"

/* PRINT MESSAGES */
# define THINK "[%ld] %d is thinking... 💡\n"
# define P_FORK_ONE  "[%ld] %d has taken the first fork.🍴\n"
# define P_FORK_TWO "[%ld] %d has taken the second fork.🍴\n"
# define D_FORK_ONE "[%ld] %d has put down the first fork.🍴\n"
# define D_FORK_TWO "[%ld] %d has put down the second fork.🍴\n"
# define DEATH  RED"💀 [%ld] %d has died! 💀"RST
# define SLEEP "[%ld] %d is sleeping... 💤💤"
# define EAT "[%ld] %d is eating... 😋"

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
	int		philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limits_mails;
	long	start_simulation;
	bool	end_simulation;
	struct	timeval start_time;
	t_mtx	table_mutex;
	t_philo	*philos;
	t_fork	*forks;
}	t_table;

/* PHILO STRUCT */
typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

/* ==== CHECK INPUT ==== */
void		prepare_dinner_table(int argc, char **input, t_table *table);
int			ft_isdigit(int c);
int			is_number(char *input);
long int	ft_atol(const char *nptr);

/* ==== INIT DATA ==== */
void		data_init(t_table *table);
void		init_philo(t_table *table);
void		assign_forks(t_philo *philo, t_fork *forks, int philo_position);

/* ==== DINNER ==== */
void		dinner_start(t_table *table);
void		*control(void *null);
void		*routine(void *arg);
void		lonely_dinner(void);

/* ==== ACTIONS ==== */
void	take_forks(t_philo *philo);
void    down_forks(t_philo *philo);

/* ==== UTILS ==== */
void		error_message(char *string, t_table *table);
void		*allocate_memory(int bytes);
void		free_everything(t_table *table);
void		set_table(t_table *new_table);
t_table		*get_table(void);

/* ==== TRASH ==== */
void		print_table(t_table *table);

#endif