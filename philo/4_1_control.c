/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.1.control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:46:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/11 15:39:22 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_satisfied(void);
static bool	check_philo_death(t_philo *philo,
				long current_time, long time_to_die);

void	*control(void *null)
{
	t_table	*table;

	(void)null;
	table = get_table();
	while (!table->end_simulation)
	{
		check_philosophers(table);
		if (table->end_simulation)
			break ;
		if (table->nbr_limits_meals > 0 && philo_satisfied())
			table->end_simulation = true;
		usleep(10000);
	}
	return (NULL);
}

void	check_philosophers(t_table *table)
{
	long	current_time;
	int		i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		current_time = get_time();
		if (check_philo_death(&(table->philo[i]),
				current_time, table->time_to_die))
		{
			table->end_simulation = true;
			return ;
		}
	}
}

static bool	philo_satisfied(void)
{
	t_table	*table;
	int		i;

	i = 0;
	table = get_table();
	while (i < table->philo_nbr)
	{
		if (table->philo[i].meals_counter < table->nbr_limits_meals)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_philo_death(t_philo *philo,
	long current_time, long time_to_die)
{
	long	time_since_last_meal;

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	time_since_last_meal = (current_time - philo->last_meal_time) * 1000;
	if (time_since_last_meal > time_to_die)
	{
		print_message(philo, DEATH);
		pthread_mutex_unlock(&philo->last_meal_time_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	return (false);
}
