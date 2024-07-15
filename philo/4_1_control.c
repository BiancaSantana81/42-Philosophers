/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_1_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:46:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/15 13:48:12 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_satisfied(void);
static bool	is_death(t_philo *philo,
				long current_time, long time_to_die);

bool	check_end_simulation(t_table *table)
{
	bool	end_simulation;

	pthread_mutex_lock(&table->end_simulation_mutex);
	end_simulation = table->end_simulation;
	pthread_mutex_unlock(&table->end_simulation_mutex);
	return (end_simulation);
}

void	*control(void *null)
{
	t_table	*table;

	(void)null;
	table = get_table();
	while (!check_end_simulation(table))
	{
		check_philosopher_death(table);
		if (check_end_simulation(table))
			break ;
		if (table->nbr_limits_meals > 0 && philo_satisfied())
		{
			pthread_mutex_lock(&table->end_simulation_mutex);
			table->end_simulation = true;
			pthread_mutex_unlock(&table->end_simulation_mutex);
		}
		usleep(10000);
	}
	return (NULL);
}

void	check_philosopher_death(t_table *table)
{
	long	current_time;
	int		i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		current_time = get_time();
		if (is_death(&(table->philo[i]),
				current_time, table->time_to_die))
		{
			pthread_mutex_lock(&table->end_simulation_mutex);
			table->end_simulation = true;
			pthread_mutex_unlock(&table->end_simulation_mutex);
			return ;
		}
	}
}

static bool	is_death(t_philo *philo,
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

static bool	philo_satisfied(void)
{
	t_table	*table;
	int		i;

	table = get_table();
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_lock(&table->philo[i].full_mutex);
		if (!table->philo[i].full)
		{
			pthread_mutex_unlock(&table->philo[i].full_mutex);
			return (false);
		}
		pthread_mutex_unlock(&table->philo[i].full_mutex);
		i++;
	}
	return (true);
}
